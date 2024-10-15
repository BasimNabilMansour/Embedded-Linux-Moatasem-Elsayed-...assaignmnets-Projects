#include <iostream>
#include <regex>
#include <string>

int main() {
    // Example branch name to validate
    std::string branchName = "feature/TN-123/branchname";

    // Regex pattern for validating the branch name
    std::regex pattern("^feature/TN-[0-9]{3}/[a-zA-Z0-9_-]+$");

    // Check if the branch name matches the pattern
    if (std::regex_match(branchName, pattern)) {
        std::cout << "Valid branch name" << std::endl;
    } else {
        std::cout << "Invalid branch name" << std::endl;
    }

    return 0;
}