#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>

Parser::Parser(const std::string &filePath) : filePath(filePath) {
    readFile();
}

void Parser::readFile() {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    content = buffer.str();
    file.close();
}

std::vector<std::string> Parser::splitLines() const {
    std::vector<std::string> lines;
    std::istringstream stream(content);
    std::string line;

    while (std::getline(stream, line)) {
        lines.push_back(line);
    }

    return lines;
}

MarkdownElement Parser::parseHeading(const std::string &line) {
    MarkdownElement element;
    element.type = MarkdownElement::HEADING;

    // count leading # to determine heading level
    size_t level = 0;
    while (level < line.size() && line[level] == '#') {
        level++;
    }

    // skip whitespace after the # characters
    size_t contentStart = level;
    while (contentStart < line.size() && std::isspace(line[contentStart])) {
        contentStart++;
    }

    element.level = level;
    element.content = parseInlineMarkdown(line.substr(contentStart));

    return element;
}

MarkdownElement Parser::parseParagraph(const std::string &content) {
    MarkdownElement element;
    element.type = MarkdownElement::PARAGRAPH;
    element.content = parseInlineMarkdown(content);
    return element;
}

MarkdownElement Parser::parseCodeBlock(const std::vector<std::string> &lines, size_t &index) {
    MarkdownElement element;
    element.type = MarkdownElement::CODE_BLOCK;

    // check if it's a fenced code block with language
    const std::string& firstLine = lines[index];
    const std::regex languageRegex("^```(\\w*)");
    std::smatch matches;

    if (std::regex_search(firstLine, matches, languageRegex) && matches.size() > 1) {
        element.attributes["language"] = matches[1];
    }

    index++; // skip the opening fence

    std::stringstream codeContent;
    while (index < lines.size()) {
        if (lines[index] == "```") {
            index++; // skip the closing fence
            break;
        }

        codeContent << lines[index] << '\n';
        index++;
    }

    element.content = codeContent.str();

    return element;
}

MarkdownElement Parser::parseList(const std::vector<std::string> &lines, size_t &index) {
    MarkdownElement element;
    element.type = MarkdownElement::LIST;

    // determine if it's an ordered or unordered list
    const bool isOrdered = std::regex_match(lines[index], std::regex(R"(^\d+\.\s.*)"));
    element.attributes["ordered"] = isOrdered ? "true" : "false";

    while (index < lines.size()) {
        const std::string& line = lines[index];

        // check if the line is a list item
        const bool isListItem = std::regex_match(line, std::regex(R"(^[\*\-\+]\s.*)")) ||
                          std::regex_match(line, std::regex(R"(^\d+\.\s.*)"));

        if (!isListItem) {
            break;
        }

        // extract list item content (remove marker and leading space)
        size_t contentStart = line.find_first_of("*-+1234567890") + 1;
        while (contentStart < line.size() && std::isspace(line[contentStart])) {
            contentStart++;
        }

        MarkdownElement listItem;
        listItem.type = MarkdownElement::LIST_ITEM;
        listItem.content = parseInlineMarkdown(line.substr(contentStart));

        element.children.push_back(listItem);
        index++;
    }

    return element;
}

std::string Parser::parseInlineMarkdown(const std::string &text) {
    std::string result = text;

    // handle bold text
    const std::regex boldRegex(R"(\*\*(.*?)\*\*|__(.*?)__)");
    result = std::regex_replace(result, boldRegex, "<strong>$1$2</strong>");

    // handle italic text
    const std::regex italicRegex("\\*(.*?)\\*|_(.*?)_");
    result = std::regex_replace(result, italicRegex, "<em>$1$2</em>");

    // handle inline code
    const std::regex codeRegex("`(.*?)`");
    result = std::regex_replace(result, codeRegex, "<code>$1</code>");

    // handle links
    const std::regex linkRegex(R"(\[(.*?)\]\((.*?)\))");
    result = std::regex_replace(result, linkRegex, "<a href=\"$2\">$1</a>");

    // handle images
    const std::regex imageRegex(R"(!\[(.*?)\]\((.*?)\))");
    result = std::regex_replace(result, imageRegex, R"(<img src="$2" alt="$1">)");

    return result;
}

MarkdownDocument Parser::parse() const {
    MarkdownDocument document;
    const std::vector<std::string> lines = splitLines();

    bool hasParagraphContent = false;
    std::string currentParagraph;

    for (size_t i = 0; i < lines.size(); i++) {
        const std::string& line = lines[i];

        // skip empty lines
        if (line.empty()) {
            if (hasParagraphContent) {
                document.elements.push_back(parseParagraph(currentParagraph));
                currentParagraph.clear();
                hasParagraphContent = false;
            }
            continue;
        }

        // check for heading
        if (line[0] == '#') {
            if (hasParagraphContent) {
                document.elements.push_back(parseParagraph(currentParagraph));
                currentParagraph.clear();
                hasParagraphContent = false;
            }

            MarkdownElement heading = parseHeading(line);
            document.elements.push_back(heading);

            // use the first heading as the document title
            if (heading.level == 1 && document.title.empty()) {
                document.title = heading.content;
            }

            continue;
        }

        // check for code block
        if (line == "```" || line.substr(0, 3) == "```") {
            if (hasParagraphContent) {
                document.elements.push_back(parseParagraph(currentParagraph));
                currentParagraph.clear();
                hasParagraphContent = false;
            }

            document.elements.push_back(parseCodeBlock(lines, i));
            i--; // index is already advanced in parseCodeBlock
            continue;
        }

        // check for list
        if ((line[0] == '*' || line[0] == '-' || line[0] == '+') && line.size() > 1 && std::isspace(line[1])) {
            if (hasParagraphContent) {
                document.elements.push_back(parseParagraph(currentParagraph));
                currentParagraph.clear();
                hasParagraphContent = false;
            }

            document.elements.push_back(parseList(lines, i));
            i--; // index is already advanced in parseList
            continue;
        }

        // check for ordered list
        if (std::regex_match(line, std::regex(R"(^\d+\.\s.*)"))) {
            if (hasParagraphContent) {
                document.elements.push_back(parseParagraph(currentParagraph));
                currentParagraph.clear();
                hasParagraphContent = false;
            }

            document.elements.push_back(parseList(lines, i));
            i--; // index is already advanced in parseList
            continue;
        }

        // check for horizontal rule
        if (line == "---" || line == "***" || line == "___") {
            if (hasParagraphContent) {
                document.elements.push_back(parseParagraph(currentParagraph));
                currentParagraph.clear();
                hasParagraphContent = false;
            }

            MarkdownElement hr;
            hr.type = MarkdownElement::HORIZONTAL_RULE;
            document.elements.push_back(hr);
            continue;
        }

        // if we get here, it's part of a paragraph
        if (hasParagraphContent) {
            currentParagraph += " " + line;
        }
        else {
            currentParagraph = line;
            hasParagraphContent = true;
        }
    }

    // add the last paragraph if there is one
    if (hasParagraphContent) {
        document.elements.push_back(parseParagraph(currentParagraph));
    }

    return document;
}
