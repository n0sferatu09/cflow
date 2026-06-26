#ifndef CFLOW_GRAPH_HPP
#define CFLOW_GRAPH_HPP

#include <string>
#include <vector>

namespace analyzer {
    class FunctionNode {
    private:
        std::string name;
        bool is_implementation = false;
        std::vector<FunctionNode*> neighbors;
    public:
        FunctionNode(std::string& func_name, bool is_impl);
    };
}

#endif //CFLOW_GRAPH_HPP
