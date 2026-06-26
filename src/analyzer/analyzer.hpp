#ifndef CFLOW_ANALYZER_HPP
#define CFLOW_ANALYZER_HPP

#include <fstream>
#include <vector>
#include <filesystem>

namespace analyzer {
    class Analyzer {
    private:
        std::vector<std::filesystem::directory_entry> entries;
        std::ifstream file;

        void check_signature();

    public:
        explicit Analyzer(std::vector<std::filesystem::directory_entry> entries_vector);

        void analyze();
    };
}

#endif //CFLOW_ANALYZER_HPP
