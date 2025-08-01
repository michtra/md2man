#include "converter.h"
#include <sstream>
#include <algorithm>
#include "utils.h"

Converter::Converter() {
}

std::string Converter::convert(const MarkdownDocument &document) {
    std::stringstream html;

    for (const auto &element: document.elements) {
        html << convertElement(element);
    }

    return html.str();
}

std::string Converter::convertElement(const MarkdownElement &element) {
    switch (element.type) {
        case MarkdownElement::HEADING:
            return convertHeading(element);
        case MarkdownElement::PARAGRAPH:
            return convertParagraph(element);
        case MarkdownElement::CODE_BLOCK:
            return convertCodeBlock(element);
        case MarkdownElement::LIST:
            return convertList(element);
        case MarkdownElement::HORIZONTAL_RULE:
            return convertHorizontalRule();
        default:
            return "";
    }
}

std::string Converter::convertHeading(const MarkdownElement &element) {
    std::stringstream html;

    // create an ID from the heading content for navigation
    const std::string id = utils::slugify(element.content);

    html << "<h" << element.level << " id=\"" << id << "\">"
            << element.content
            << "</h" << element.level << ">\n";

    return html.str();
}

std::string Converter::convertParagraph(const MarkdownElement &element) {
    return "<p>" + element.content + "</p>\n";
}

std::string Converter::convertCodeBlock(const MarkdownElement &element) {
    std::stringstream html;

    const auto it = element.attributes.find("language");
    const std::string language = (it != element.attributes.end()) ? it->second : "";

    html << "<pre><code";
    if (!language.empty()) {
        html << " class=\"language-" << language << "\"";
    }
    html << ">" << element.content << "</code></pre>\n";

    return html.str();
}

std::string Converter::convertList(const MarkdownElement &element) {
    std::stringstream html;

    // convert lists to unordered lists with dashes
    html << "<ul>" << "\n";

    for (const auto &item: element.children) {
        html << "  <li>" << item.content << "</li>\n";
    }

    html << "</ul>" << "\n";

    return html.str();
}

std::string Converter::convertHorizontalRule() {
    return "<hr>\n";
}
