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

    void delete_all_children(void);
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
void Node<T>::delete_all_children(void)
{
    if(left)
    {
        left->delete_all_children();
        delete left;
    }
    if(right)
    {
        right->delete_all_children();
        delete right;
    }
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

    void balance(void);
    void add_list_to_node(Node<T> * n,vector<Node<T> *> v);
    
    vector<Node<T> *> get_sorted_list(void);
    void add_node_to_list(Node<T> * n, vector<Node<T> *> &list);
	
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
	// int depth=get_depth(head);
        int depth=0;
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
	print_node(n->right,depth+1);
	print_node(n->left,depth+1);
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
void BinarySearchTree<T>::balance(void)
{
    vector<Node<T> *> v=get_sorted_list();

    Node<T> * prev_head=head;
    head=new Node<T>;
    
    add_list_to_node(head,v);

    prev_head->delete_all_children();
    delete prev_head;
}

template<class T>
void BinarySearchTree<T>::add_list_to_node(Node<T> * n,vector<Node<T> *> v)
{
    n->left=0;
    n->right=0;
        
    int size=v.size();

    if(size==1)
    {
        Node<T> * mid_node = v[0];
        n->data=mid_node->data; 
    }
    else if(size>0)
    {
        int mid=size/2;
        // cout << " -- size: " << size << " -- mid: " << mid << endl;
        
        Node<T> * mid_node = v[mid];
        n->data=mid_node->data;
        vector<Node<T> *> left_v(&v[0], &v[mid]);
        vector<Node<T> *> right_v(&v[mid+1], &v[size]);

        if(left_v.size())
        {
            n->left = new Node<T>;
            add_list_to_node(n->left,left_v);
        }
        if(right_v.size())
        {
            n->right = new Node<T>;
            add_list_to_node(n->right,right_v);
        }
    }
}

template<class T>
vector<Node<T> *> BinarySearchTree<T>::get_sorted_list(void)
{
    vector<Node<T> *> v;
    add_node_to_list(head,v);
    return v;
}

template<class T>
void BinarySearchTree<T>::add_node_to_list(Node<T> * n, vector<Node<T> *> &list)
{
    if(n)
    {
	add_node_to_list(n->left,list);
	list.push_back(n);
	add_node_to_list(n->right,list);
    }
    
    
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
	b.add(14);
	b.add(15);
	b.add(16);
	b.add(20);
	b.add(30);
	b.add(4);
	
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


	cout << " BEFORE balancing ... " << endl;
	b.print();
        
	cout << " balancing ... " << endl;
	b.balance();
        
	cout << " AFTER balancing ... " << endl;
	b.print();

	
	return 0;

}
