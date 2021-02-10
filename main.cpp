#include "graph.hpp"

#include <iostream>

// 打印输出路径
void print_path(int i, const std::vector<int > & parent) {
    if(parent[i] == -1) {
        std::cout << i << ", ";
        return;
    }
    print_path(parent[i], parent);
    std::cout << i << ", ";
}

int main(int, char**) {
    Graph graph;
    graph.addAdj(0, 1);
    graph.addAdj(0, 3);
    graph.addAdj(2, 3);
    graph.addAdj(1, 4);
    graph.addAdj(1, 7);
    graph.addAdj(4, 5);
    graph.addAdj(4, 7);
    graph.addAdj(5, 6);
    graph.addAdj(5, 7);
    graph.addAdj(6, 7);

    std::vector<bool> visited(graph.getN(), false); 
    std::vector<int> d(graph.getN(), 0);
    std::vector<int> parent(graph.getN(), -1);
    std::priority_queue<int> queue;

    visited[0] = true;
    queue.push(0);
    while(!queue.empty()) {
        int curNode = queue.top();
        queue.pop();
        for(Node * adjNode = graph.adj[curNode]->getNxt(); 
            adjNode != nullptr; 
            adjNode = adjNode->getNxt()) {
            
            if(!(visited[adjNode->getNum()])) {
                visited[adjNode->getNum()] = true;
                d[adjNode->getNum()] = d[curNode] + 1;
                parent[adjNode->getNum()] = curNode;
                queue.push(adjNode->getNum());
            }

        }
    }
    print_path(4, parent);

    return 0;
}

