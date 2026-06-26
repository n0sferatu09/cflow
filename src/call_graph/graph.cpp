#include "graph.hpp"

namespace analyzer {
    FunctionNode::FunctionNode(std::string& func_name, bool is_impl)
    : name(std::move(func_name)), is_implementation(is_impl) {}
}
