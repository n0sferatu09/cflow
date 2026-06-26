#include <iostream>
#include <stdexcept>

#include "../call_graph/graph.hpp"
#include "../checker/checker.hpp"
#include "analyzer.hpp"

namespace analyzer {
    Analyzer::Analyzer(std::vector<std::filesystem::directory_entry> entries_vector)
                       : entries(std::move(entries_vector)) {}

    void Analyzer::analyze() {
        for (const auto& entry : entries) {
            file.open(entry.path());
            if (!file) {
                throw std::runtime_error("Failed to open file!");
            }
            check_signature();
            file.close();
        }
    }

    void Analyzer::check_signature() {
        std::string data;
        while (file >> data) {
            if (!KeywordChecker::is_keyword(data) &&
                data.back() == ')' && data[data.length() - 2] == '(') {
                std::cout << data << std::endl;
            }
        }
    }


}