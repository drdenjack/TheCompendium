#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Node
{
public:
    Node();
    Node(T val);
    Node(const Node &n);
    ~Node();

    void set_data(T d);
    T get_data();

private:
    T data;
    Node * next;
    
};

template<class T>
Node<T>::Node()
{
    data = -1;
}

template<class T>
Node<T>::Node(T v)
{
    data = v;
}

template<class T>
Node<T>::~Node()
{
    if(next)
	delete next;
}

template<class T>
Node<T>::Node(const Node &n)
{
    data = n.data;
}

template<class T>
void Node<T>::set_data(T d)
{
    data=d;
}

template<class T>
T Node<T>::get_data(void)
{
    return data;
}

// --------------------------------------------------------------
template<class T>
class LinkedList
{
public:
    void print();
    void add_node(Node<T> * n);
    void add(T x);
    
    int remove(Node<T> * n);

    // void balance(void);
    
private:
    vector<Node<T> *> nodes;
};

template<class T>
void LinkedList<T>::print(void)
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
void LinkedList<T>::add_node(Node<T> * n)
{
    nodes.push_back(n);
}

template<class T>
void LinkedList<T>::add(T x)
{
    Node<T> * n = new Node<T>(x);
    add_node(n);
}

template<class T>
int LinkedList<T>::remove(Node<T> * n)
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
	cout << "Linked List" << endl;

	LinkedList<double> l;
	l.add(11);
	Node<double> * n2 = new Node<double>(9);
	l.add_node(n2);

	l.print();

	cout << "removing, n2..." << endl;

	l.remove(n2);
	
	l.print();

	return 0;
}
