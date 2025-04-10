#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <algorithm>
#include <cctype>
#include <regex>

namespace utils {

// convert string to lowercase
inline std::string toLowercase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

// generate a slug (URL-friendly string) from text
inline std::string slugify(const std::string& text) {
    // remove HTML tags
    std::string result = std::regex_replace(text, std::regex("<[^>]*>"), "");
    
    // convert to lowercase
    result = toLowercase(result);
    
    // replace spaces with hyphens
    std::replace(result.begin(), result.end(), ' ', '-');
    
    // remove any non-alphanumeric characters except hyphens
    result.erase(std::remove_if(result.begin(), result.end(), 
                                [](unsigned char c) { 
                                    return !(std::isalnum(c) || c == '-'); 
                                }), 
                 result.end());
    
    // replace multiple hyphens with a single hyphen
    result = std::regex_replace(result, std::regex("--+"), "-");
    
    // remove leading and trailing hyphens
    if (!result.empty() && result.front() == '-') {
        result.erase(0, 1);
    }
    if (!result.empty() && result.back() == '-') {
        result.pop_back();
    }
    
    return result;
}

} // namespace utils

#endif
