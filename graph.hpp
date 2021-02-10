#include <queue>
#include <vector>

class Node {
private:
    int num;
    double w;
    Node * nxt;

public:
    Node() {
        num = 0;
        w = 0.0;
        nxt = NULL;
    }
    Node(int num_, double w_):num(num_), w(w_) {}
    Node(int num_, double w_, Node * nxt_):
        num(num_), w(w_), nxt(nxt_) {}
    
    // 各种值的get，set方法
    void setNum(int num) {this->num = num;}
    void setW(double w) {this->w = w;}
    void setNxt(Node * nxt) {this->nxt = nxt;}
    int getNum() {return this->num;}
    double getW() {return this->w;}
    Node * getNxt() {return this->nxt;}
};

class Graph {
private:
    int n;
public:
    /*邻接链表，带有哑节点*/
    std::vector<Node *> adj;

public:
    Graph(int n):adj(n, nullptr) {
        this->n = n;
        for(int i = 0; i < n; i++){
            adj[i] = new Node(-1, 1.0);
        }    
    }
    Graph():n(8), adj(8, nullptr) {
        for(int i = 0; i < n; i++){
            adj[i] = new Node(-1, 1.0);
        }    
    }
    /*
    有始有终，释放资源
    */
    ~Graph() {
        for(int i = 0; i < n; i++) {
            Node * cur = adj[i];
            Node * nxt = cur->getNxt();
            while(nxt != nullptr) {
                delete cur;
                cur = nxt->getNxt();
                nxt = cur->getNxt();
            }
        }
    }

    int getN() const {return n;}
    /*
        不加检查地添加一条边
    */
    void addAdj(int n0, int n1, double w = 1.0) {
        if(n0 < n && n1 < n) {
            Node * node0 = new Node(n0, w);
            Node * node1 = new Node(n1, w);
            
            // 在邻接链表中添加一条边
            node0->setNxt(adj[n1]->getNxt());
            adj[n1]->setNxt(node0);
            node1->setNxt(adj[n0]->getNxt());
            adj[n0]->setNxt(node1);
        }
    }
        
};