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
    // ~Node();

    T data;
    Node * next;
    
};

template<class T>
Node<T>::Node()
{
    data = -1;
    next=NULL;
}

template<class T>
Node<T>::Node(T v)
{
    data = v;
    next=NULL;
}

// template<class T>
// Node<T>::~Node()
// {
//     // if(next)
//     // 	delete next;
// }

template<class T>
Node<T>::Node(const Node &n)
{
    data = n.data;
    next=n.next;
}

// --------------------------------------------------------------
template<class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    
    void print();
    void add_node(Node<T> * n);
    void add(T x);
    
    int remove(Node<T> * n);
    int remove_at_index(int i);

    Node<T>* find_node(Node<T> * n);
    Node<T>* find_node_by_index(int i);
    
    // void balance(void);
    
private:
    Node<T> * head;
};

template<class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* n=head;
    if(n)
    {
    	while(n)
    	{
    	    Node<T>* prev=n;
    	    n=n->next;
    	    delete prev;
    	}
    }
}

template<class T>
void LinkedList<T>::print(void)
 {
    cout << "Printing ..." << endl;
    if(!head)
	cout << "List is empty!" << endl;
    else
    {
	Node<T> * tmp=head;
	while(tmp)
	{
	    cout << tmp->data;
	    
	    tmp=tmp->next;
	    
	    if(tmp)
	    	cout << " -> ";
	    else
	    	cout << endl;
	}
    }
}

template<class T>
void LinkedList<T>::add_node(Node<T> * n)
{
    cout << "adding: " << n->data << endl;
    
    if(!head)
    {
	head=n;
	// cout << "adding head" << endl;
    }
    else
    {
	// cout << "adding non-null" << endl;
	Node<T> * tmp=head;
	while(tmp->next)
	{
	    tmp=tmp->next;
	}
	tmp->next=n;
    }
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
    cout << "Removing " << n->data << endl;

    if(!head)
	return 0;
    else if(head==n)
    {
	Node<T>* tmp=head;
	if(head->next)
	    head=head->next;
	else
	    head=NULL;
	delete tmp;
	return 1;
    }
    else
    {
	cout << "removing other " << endl;
	Node<T>* tmp=head;
	while(tmp->next)
	{
	    if(tmp->next==n)
	    {
		Node<T>* found=tmp->next;
		if(found->next)
		    tmp->next=found->next;
		else
		    tmp->next=NULL;
		delete found;
		return 1;
	    }
	    tmp=tmp->next;
	}
    }

    return 0;
}

template<class T>
int LinkedList<T>::remove_at_index(int i)
{
    Node<T> * n = find_node_by_index(i);
    if(n)
	return remove(n);
    
    return 0;
}

template<class T>
Node<T>* LinkedList<T>::find_node(Node<T> * n)
{
    if(head)
    {	
	Node<T>* tmp=head;
	while(tmp)
	{
	    if(tmp==n)
		return tmp;
	    else if(tmp->next) 
		tmp=tmp->next;
	}
    }
    return NULL;
}

template<class T>
Node<T>* LinkedList<T>::find_node_by_index(int i)
{
    if(head)
    {	
	int idx=0;
	Node<T>* tmp=head;
	while(tmp)
	{
	    if(idx==i)
	    {
		cout << " found index: " << i << " -- tmp->data: " << tmp->data << endl;
		return tmp;
	    }

	    tmp=tmp->next;
	    idx++;
	}
    }
    cout << "node does not exist at index = " << i << endl;
    return NULL;
}

int main() {
	cout << "Linked List" << endl;

	LinkedList<double> l;
	l.print();
	l.add(11);
	l.add(13);
	Node<double> * n2 = new Node<double>(9);
	l.add_node(n2);
	l.add(-14);
	l.print();

	cout << "removing, n2..." << endl;
	l.remove(n2);
	l.print();

	cout << "getting first node (index = 0)" << endl;
	Node<double> * n = l.find_node_by_index(0);
	cout << "returned val: " << n->data << endl;
	l.remove(n);
	l.print();

	
	cout << "removing node at index = 1" << endl;	
	l.remove_at_index(1);
	l.print();

	cout << "removing node at index = 0" << endl;	
	l.remove_at_index(0);
	l.print();

	
	cout << "removing node at index = 0" << endl;	
	l.remove_at_index(0);
	l.print();

	
	return 0;
}
