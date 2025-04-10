#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include "parser.h"

class Converter {
public:
    Converter();
    static std::string convert(const MarkdownDocument& document);

private:
    static std::string convertElement(const MarkdownElement& element);

    static std::string convertHeading(const MarkdownElement& element);

    static std::string convertParagraph(const MarkdownElement& element);

    static std::string convertCodeBlock(const MarkdownElement& element);

    static std::string convertList(const MarkdownElement& element);
    static std::string convertHorizontalRule();
};

#endif
