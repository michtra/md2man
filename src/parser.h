#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <unordered_map>

// represents a structural element in markdown
struct MarkdownElement {
    enum Type {
        HEADING,
        PARAGRAPH,
        CODE_BLOCK,
        LIST,
        LIST_ITEM,
        LINK,
        IMAGE,
        HORIZONTAL_RULE,
        TEXT
    };

    Type type;
    std::string content;
    int level; // heading level (1-6)
    std::unordered_map<std::string, std::string> attributes;
    std::vector<MarkdownElement> children;
};

// represents a complete markdown document
struct MarkdownDocument {
    std::string title;
    std::vector<MarkdownElement> elements;
};

class Parser {
public:
    explicit Parser(const std::string& filePath);
    [[nodiscard]] MarkdownDocument parse() const;

private:
    std::string filePath;
    std::string content;

    void readFile();

    [[nodiscard]] std::vector<std::string> splitLines() const;

    static MarkdownElement parseHeading(const std::string& line);
    static MarkdownElement parseParagraph(const std::string& content);
    static MarkdownElement parseCodeBlock(const std::vector<std::string>& lines, size_t& index);

    static MarkdownElement parseList(const std::vector<std::string>& lines, size_t& index);
    static std::string parseInlineMarkdown(const std::string& text);
};

#endif
