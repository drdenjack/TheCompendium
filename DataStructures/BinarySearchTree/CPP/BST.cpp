#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<class T>
class Node
{
public:
    Node();
    Node(int v);
    Node(const Node &n);
    // ~Node();

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

// template<class T>
// Node<T>::~Node()
// {
// }


// --------------------------------------------------------------------------
template<class T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    void print();
    void print_node(Node<T> *, int);
    void add_node(Node<T> * n);
    void add(T x);
    
    T remove(Node<T> * n);

    // non BST searching
    Node<T> * breadthFirstSearch(T);
    Node<T> * depthFirstSearch(T);
    Node<T> * searchNode(Node<T> *, T);

    // BST searching
    Node<T> * find(T);

    // void balance(void);
    
private:
    Node<T> * head;
    void swap(Node<T> *, Node<T> *);
    int get_depth(Node<T> *);
    queue<Node<T> *> get_bfs_queue();
};

template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
    head=0;
}

template<class T>
void BinarySearchTree<T>::print(void)
{
    cout << "Printing ..." << endl;

    cout << "Depth: " << get_depth(head) << endl;
    if(!head)
	cout << "Tree is empty!" << endl;
    else
    {
	int depth=get_depth(head);
	print_node(head,depth);

	
	queue<Node<T> *> q = get_bfs_queue();
	while(!q.empty())
	{
	    Node<T> * tmp = q.front();
	    cout << tmp->data << " ";
	    q.pop();
	}
	cout << endl;

    }
}

template<class T>
void BinarySearchTree<T>::print_node(Node<T> * n,int depth)
{
    if(n)
    {
	for(int i=0;i<depth;i++)
	    cout << "  ";
	cout << n->data << endl;
	print_node(n->left,depth-1);
	print_node(n->right,depth-1);
    }
}

template<class T>
void BinarySearchTree<T>::add_node(Node<T> * n)
{
    if(!head)
	head=n;
    else
    {
	Node<T> * tmp=head;
	while(tmp)
	{
	    if(n->data < tmp->data)
	    {
		if(tmp->left)
		    tmp=tmp->left;
		else
		{
		    tmp->left=n;
		    return;
		}
	    }
	    else
	    {
		if(tmp->right)
		    tmp=tmp->right;
		else
		{
		    tmp->right=n;
		    return;
		}
	    }
	    
	}

    }
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
    return 0;
}

template<class T>
void BinarySearchTree<T>::swap(Node<T> * n1, Node<T> * n2)
{
    T tmp=n1->data;
    n1->data=n2->data;
    n2->data=tmp;
}

template<class T>
int BinarySearchTree<T>::get_depth(Node<T> * n)
{
    if(!n)
	return 0;
    else
    {
	int ld = get_depth(n->left);
	int rd = get_depth(n->right);
	int ret=1;
	if(ld>rd)
	    ret+=ld;
	else
	    ret+=rd;
	return ret;
	
    }
}

template<class T>
Node<T> * BinarySearchTree<T>::breadthFirstSearch(T val)
{
    // for regular trees / graphs, not BSTs

    cout << "Beginning BFS ..." << endl;

    if(!head)
	return NULL;
    else
    {
	queue<Node<T> *> tmp_q;
	tmp_q.push(head);
	while(!tmp_q.empty())
	{
	    Node<T> * tmp = tmp_q.front();
	    tmp_q.pop();

	    cout << "bfs - searching: " << tmp->data << endl;
	    
	    if(tmp->data == val)
		return tmp;
	
	    if(tmp->left)
		tmp_q.push(tmp->left);
	    if(tmp->right)
		tmp_q.push(tmp->right);
	}
	return NULL;
    }
}

template<class T>
Node<T> * BinarySearchTree<T>::depthFirstSearch(T val)
{
    // for regular trees / graphs, not BSTs

    cout << "Beginning DFS ..." << endl;
    return searchNode(head,val);
}

template<class T>
Node<T> * BinarySearchTree<T>::searchNode(Node<T> * n, T val)
{
    if(!n)
	return NULL;

    if(n)
	cout << "dfs - searching: " << n->data << endl;

    if(n->data==val)
	return n;

    Node<T> * left_val=searchNode(n->left,val);
    if(left_val)
	return left_val;
    else
	return searchNode(n->right,val);
}
    

template<class T>
Node<T> * BinarySearchTree<T>::find(T val)
{
    cout << "Beginning Binary Search ..." << endl;
    if(!head)
	return NULL;

    Node<T> * tmp = head;
    while(tmp)
    {
	cout << "Binary Search - searching: " << tmp->data << endl;
	if(tmp->data==val)
	    return tmp;
	if(val>tmp->data)
	    tmp=tmp->right;
	else
	    tmp=tmp->left;
	
    }
    return NULL;
}
    

template<class T>
queue<Node<T> *> BinarySearchTree<T>::get_bfs_queue()
{
    queue<Node<T> *> ret;

    if(!head)
	return ret;
    else
    {
	queue<Node<T> *> tmp_q;
	tmp_q.push(head);

	while(!tmp_q.empty())
	{
	    Node<T> * tmp = tmp_q.front();
	    tmp_q.pop();
	    if(tmp->left)
		tmp_q.push(tmp->left);
	    if(tmp->right)
		tmp_q.push(tmp->right);
	    ret.push(tmp);
	}
    }
    return ret;
}

int main() {
	cout << "Binary Search Tree" << endl;

	BinarySearchTree<int> b;
	b.add(11);
	Node<int> * n2 = new Node<int>(9);
	b.add_node(n2);

	b.add(13);
	b.add(1);
	b.add(7);
	b.add(3);
	b.add(12);
	
	b.print();

	// cout << "removing, n2..." << endl;

	// b.remove(n2);
	
	// b.print();

	int val = -30;

	Node<int> * found;
	found = b.depthFirstSearch(val);
	if(!found)
	    cout << "not found" << endl;
	else
	    cout << "found: " << found->data << endl;

	found = b.breadthFirstSearch(val);
	if(!found)
	    cout << "not found" << endl;
	else
	    cout << "found: " << found->data << endl;
	
	found = b.find(val);
	if(!found)
	    cout << "not found" << endl;
	else
	    cout << "found: " << found->data << endl;
	
	return 0;
}
