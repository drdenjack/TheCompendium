#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    Node(Node &n);

    void set_data(int d);
    int get_data();
    
private:
    int data;
    Node* left;
    Node* right;
    
};

Node::Node(Node &n)
{

}

void Node::set_data(int d)
{

}

int Node::get_data(void)
{

}

class BinarySearchTree
{
public:
    void print_tree();
    void add_node(Node n);
private:
    vector<Node> nodes;
};

void BinarySearchTree::print_tree(void)
{
    int size=nodes.size();
    if(size>0)
    {
        for(int i=0;i<size;i++)
        {
            cout << nodes[i];
            if(i<size-1)
                cout << ", ";
        }
        cout << endl;
    }
}

void BinarySearchTree::add_node(Node n)
{
    nodes.push_back(n);
}

int main() {
	cout << "Binary Search Tree" << endl;


	return 0;
}
