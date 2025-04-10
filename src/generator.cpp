#include "generator.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include "utils.h"

Generator::Generator(const std::string &manualTitle, const std::string &outputDir,
                     const std::string &author,
                     const std::string &cssTemplatePath, const std::string &jsTemplatePath)
    : manualTitle(manualTitle), outputDir(outputDir), author(author),
      cssTemplatePath(cssTemplatePath), jsTemplatePath(jsTemplatePath) {
}

void Generator::addPage(const std::string &id, const std::string &title, const std::string &content) {
    Page page;
    page.id = id;
    page.title = title.empty() ? id : title;
    page.content = content;
    pages.push_back(page);
}

void Generator::generate() {
    // sort pages alphabetically by title
    std::sort(pages.begin(), pages.end(),
              [](const Page &a, const Page &b) { return a.title < b.title; });

    // create necessary directories and files
    fs::create_directories(fs::path(outputDir) / "css");
    fs::create_directories(fs::path(outputDir) / "js");

    createStylesheet();
    createScripts();
    createIndexPage();
    createContentPages();
}

void Generator::createStylesheet() const {
    std::string cssOutput = (fs::path(outputDir) / "css" / "style.css").string();

    // Read from template file
    std::ifstream templateFile(cssTemplatePath);
    if (!templateFile) {
        std::cerr << "Warning: Could not open CSS template file: " << cssTemplatePath << std::endl;
        return;
    }

    // Copy to output file
    std::ofstream outputFile(cssOutput);
    outputFile << templateFile.rdbuf();

    templateFile.close();
    outputFile.close();
}

void Generator::createScripts() const {
    std::string jsOutput = (fs::path(outputDir) / "js" / "script.js").string();

    // Read from template file
    std::ifstream templateFile(jsTemplatePath);
    if (!templateFile) {
        std::cerr << "Warning: Could not open JS template file: " << jsTemplatePath << std::endl;
        return;
    }

    // Copy to output file
    std::ofstream outputFile(jsOutput);
    outputFile << templateFile.rdbuf();

    templateFile.close();
    outputFile.close();
}

void Generator::createIndexPage() {
    std::ofstream indexFile((fs::path(outputDir) / "index.html").string());

    indexFile << "<!DOCTYPE html>\n"
            << "<html lang=\"en\">\n"
            << "<head>\n"
            << "    <meta charset=\"UTF-8\">\n"
            << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
            << "    <title>" << manualTitle << "</title>\n"
            << "    <link rel=\"stylesheet\" href=\"css/style.css\">\n"
            << "</head>\n"
            << "<body>\n"
            << "    <nav class=\"sidebar\">\n"
            << "        <div class=\"sidebar-header\">\n"
            << "            <h1>" << manualTitle << "</h1>\n"
            << "        </div>\n"
            << "        <ul class=\"nav-list\">\n";

    // add index page link (always active on index page)
    indexFile << "            <li class=\"nav-item\">\n"
            << "                <a class=\"nav-link active\" href=\"index.html\">Home</a>\n"
            << "            </li>\n";

    // add links to all pages
    for (const auto &page: pages) {
        indexFile << "            <li class=\"nav-item\">\n"
                << R"(                <a class="nav-link" href=")" << page.id << ".html\">" << page.title << "</a>\n"
                << "            </li>\n";
    }

    indexFile << "        </ul>\n"
            << "    </nav>\n"
            << "    <main class=\"content\">\n"
            << "        <h1>" << manualTitle << "</h1>\n";

    if (!author.empty()) {
        indexFile << "        <p class=\"author\">By " << author << "</p>\n";
    }

    indexFile << "        <div id=\"toc\"></div>\n"
            << "        <p>Welcome to the " << manualTitle <<
            ". This manual provides comprehensive documentation generated from markdown files.</p>\n"
            << "        <h2>Contents</h2>\n"
            << "        <ul>\n";

    for (const auto &page: pages) {
        indexFile << "            <li><a href=\"" << page.id << ".html\">" << page.title << "</a></li>\n";
    }

    indexFile << "        </ul>\n"
            << "    </main>\n"
            << "    <script src=\"js/script.js\"></script>\n"
            << "</body>\n"
            << "</html>\n";

    indexFile.close();
}

void Generator::createContentPages() {
    for (const auto &page: pages) {
        std::ofstream pageFile((fs::path(outputDir) / (page.id + ".html")).string());

        pageFile << "<!DOCTYPE html>\n"
                << "<html lang=\"en\">\n"
                << "<head>\n"
                << "    <meta charset=\"UTF-8\">\n"
                << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
                << "    <title>" << page.title << " - " << manualTitle << "</title>\n"
                << "    <link rel=\"stylesheet\" href=\"css/style.css\">\n"
                << "</head>\n"
                << "<body>\n"
                << "    <nav class=\"sidebar\">\n"
                << "        <div class=\"sidebar-header\">\n"
                << "            <h1>" << manualTitle << "</h1>\n"
                << "        </div>\n"
                << "        <ul class=\"nav-list\">\n";

        // add index page link
        pageFile << "            <li class=\"nav-item\">\n"
                << "                <a class=\"nav-link\" href=\"index.html\">Home</a>\n"
                << "            </li>\n";

        // add links to all pages with current page marked active
        for (const auto &p: pages) {
            pageFile << "            <li class=\"nav-item\">\n"
                    << "                <a class=\"nav-link" << (p.id == page.id ? " active" : "") << "\" href=\""
                    << p.id << ".html\">" << p.title << "</a>\n"
                    << "            </li>\n";
        }

        pageFile << "        </ul>\n"
                << "    </nav>\n"
                << "    <main class=\"content\">\n"
                << "        <h1>" << page.title << "</h1>\n"
                << "        <div id=\"toc\"></div>\n"
                << page.content << "\n"
                << "    </main>\n"
                << "    <script src=\"js/script.js\"></script>\n"
                << "</body>\n"
                << "</html>\n";

        pageFile.close();
    }
}
