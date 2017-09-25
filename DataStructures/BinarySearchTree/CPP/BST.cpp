#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Node
{
public:
    Node();
    Node(int v);
    Node(const Node &n);
    ~Node();

    void set_data(int d);
    int get_data();

private:
    int data;
    Node* left;
    Node* right;
    
};

template<class T>
Node<T>::Node()
{
    data = -1;
    left = NULL;
    right = NULL;
}

template<class T>
Node<T>::Node(int v)
{
    data = v;
    left = NULL;
    right = NULL;
}

template<class T>
Node<T>::Node(const Node &n)
{
    data = n.data;
    if(n.left)
	left = n.left;
    if(n.right)
	right = n.right;
}

template<class T>
Node<T>::~Node()
{
    if(left)
	delete left;
    if(right)
	delete right;
}

template<class T>
void Node<T>::set_data(int d)
{
    data=d;
}

template<class T>
int Node<T>::get_data(void)
{
    return data;
}

template<class T>
class BinarySearchTree
{
public:
    void print_tree();
    void add_node(Node<T> * n);
    void add(T x);
    
    T remove(Node<T> * n);

    // void balance(void);
    
private:
    vector<Node<T> *> nodes;
};

template<class T>
void BinarySearchTree<T>::print_tree(void)
{
    cout << "Printing ..." << endl;
    size_t size=nodes.size();
    if(size>0)
    {
        for(int i=0;i<static_cast<int>(size);i++)
        {
            cout << nodes[i]->get_data();
            if(i<static_cast<int>(size)-1)
                cout << ", ";
        }
        cout << endl;
    }
}

template<class T>
void BinarySearchTree<T>::add_node(Node<T> * n)
{
    nodes.push_back(n);
}

template<class T>
void BinarySearchTree<T>::add(T x)
{
    Node<T> * n = new Node<T>(x);
    add_node(n);
}

template<class T>
T BinarySearchTree<T>::remove(Node<T> * n)
{
    size_t size=nodes.size();
    if(size>0)
    {
        for(int i=0;i<static_cast<int>(size);i++)
        {
	    if(nodes[i] == n)
	    {
		nodes.erase(nodes.begin()+i);
		return 1;
	    }
        }
    }
	return 0;
}

int main() {
	cout << "Binary Search Tree" << endl;

	BinarySearchTree<int> b;
	b.add(11);
	Node<int> * n2 = new Node<int>(9);
	b.add_node(n2);

	b.print_tree();

	cout << "removing, n2..." << endl;

	b.remove(n2);
	
	b.print_tree();

	return 0;
}
