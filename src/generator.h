#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

struct Page {
    std::string id;
    std::string title;
    std::string content;
};

class Generator {
  public:
    Generator(const std::string& manualTitle, const std::string& outputDir, 
              const std::string& author,
              const std::string& cssTemplatePath = "templates/style.css",
              const std::string& jsTemplatePath = "templates/script.js");
    void addPage(const std::string& id, const std::string& title, const std::string& content);
    void generate();

    void createStylesheet() const;
    void createScripts() const;

private:
    std::string manualTitle;
    std::string outputDir;
    std::string author;
    std::string cssTemplatePath;
    std::string jsTemplatePath;
    std::vector<Page> pages;
    
    void createIndexPage();
    void createContentPages();
    std::string generateNavigation(const std::string& currentPageId);
};

#endif
