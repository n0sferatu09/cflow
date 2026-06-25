#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <cstddef>

void open(const std::string& path, std::vector<std::filesystem::directory_entry>& entries_vector) {
    try {
        if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
            for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
                entries_vector.push_back(entry);
            }
        } else {
            std::cout << "Directory not found or not a directory" << std::endl;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cout << "File system error: " << e.what() << std::endl;
    }
}

void entries_validate(std::vector<std::filesystem::directory_entry>& entries_vector) {
    std::size_t length = entries_vector.size();
    for (std::size_t i = 0; i < length; ++i) {
        std::string entry = entries_vector[i].path().string();
        if (entry.back() != 'c' || entry.back() != 'h') {

        }

        if (entry.length() >= 2) {
            if (entry[entry.length()] - 2) {

            }
        }
    }
}

int main(int argc, char** argv) {
    std::string path;

    if (argc == 1) {
        path = ".";
    } else if (argc == 2) {
        path = argv[1];
    } else {
        std::cout << "Usage: cflow <dirname>" << std::endl;
        return 1;
    }

    std::vector<std::filesystem::directory_entry> entries;
    open(path, entries);

    entries_validate(entries);

    return 0;
}