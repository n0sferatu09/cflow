#ifndef CFLOW_CHECKER_HPP
#define CFLOW_CHECKER_HPP

#include <array>
#include <string_view>
#include <algorithm>

namespace analyzer {
    class Struct_Checker {
    private:
        static constexpr std::array<std::string_view, 3> STRUCT_TYPES {
            "enum", "struct", "union"
        };

        static constexpr const std::array<std::string_view, 3>& get_struct_types() {
            return STRUCT_TYPES;
        }
    public:
        static bool is_struct_type(std::string_view word) {
            const auto& struct_types = get_struct_types();
            return std::binary_search(struct_types.begin(), struct_types.end(), word);
        }
    };
}

#endif //CFLOW_CHECKER_HPP
