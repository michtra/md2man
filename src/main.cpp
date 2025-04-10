#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "parser.h"
#include "converter.h"
#include "generator.h"

namespace fs = std::filesystem;

void printUsage(const char *programName) {
    std::cout << "Usage: " << programName << " <input_dir> <output_dir> [title] [author]" << std::endl;
    std::cout << "  input_dir: Directory containing markdown files" << std::endl;
    std::cout << "  output_dir: Directory where the HTML manual will be generated" << std::endl;
    std::cout << "  title: (Optional) Title of the manual (default: \"Reference Manual\")" << std::endl;
    std::cout << "  author: (Optional) Author name (default: none)" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printUsage(argv[0]);
        return 1;
    }

    std::string inputDir = argv[1];
    std::string outputDir = argv[2];
    std::string title = argc > 3 ? argv[3] : "Reference Manual";
    std::string author = argc > 4 ? argv[4] : "";

    // Check if input directory exists
    if (!fs::exists(inputDir) || !fs::is_directory(inputDir)) {
        std::cerr << "Error: Input directory does not exist or is not a directory." << std::endl;
        return 1;
    }

    // Create output directory if it doesn't exist
    if (!fs::exists(outputDir)) {
        if (!fs::create_directories(outputDir)) {
            std::cerr << "Error: Could not create output directory." << std::endl;
            return 1;
        }
    }

    // Collect markdown files
    std::vector<std::string> mdFiles;
    for (const auto &entry: fs::directory_iterator(inputDir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".md") {
            mdFiles.push_back(entry.path().string());
        }
    }

    if (mdFiles.empty()) {
        std::cerr << "Error: No markdown files found in the input directory." << std::endl;
        return 1;
    }

    try {
        Generator generator(title, outputDir, author);

        for (const auto &mdFile: mdFiles) {
            // Parse markdown file
            Parser parser(mdFile);
            auto mdContent = parser.parse();

            // Convert markdown to HTML
            Converter converter;
            auto htmlContent = converter.convert(mdContent);

            // Add page to the generator
            fs::path filePath(mdFile);
            std::string pageName = filePath.stem().string();
            generator.addPage(pageName, mdContent.title.empty() ? pageName : mdContent.title, htmlContent);
        }

        // Generate the manual
        generator.generate();

        std::cout << "Manual generated successfully in: " << outputDir << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
