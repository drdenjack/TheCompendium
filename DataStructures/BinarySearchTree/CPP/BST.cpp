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
    void print_node(Node<T> *, int, int);

    int add(T x);
    int remove(T val);

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

        // print super basic tree (pre-order with indenting)
        int height=0;
        print_node(head,height,-1);
        cout << endl;
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
void BinarySearchTree<T>::print_node(Node<T> * n, int depth, int right)
{
    if(n)
    {
        print_node(n->right,depth+1,1);
        
        for(int i=0;i<depth;i++)
            cout << "  ";
        if(right==1)
        {
            cout << "/";
        }
        else if(right==0)
        {
            cout << "\\";
        }
        
        cout << n->data << endl;
        print_node(n->left,depth+1,0);

    }

/*
PRINTING EXAMPLE

    /30
      \20
  /15
    \14
      \13
12
    /11
      \9
  \7
      /4
    \3
      \1


*/
}

template<class T>
int BinarySearchTree<T>::add(T x)
{
    if(!head)
	head=new Node<T>(x);
    else
    {
	Node<T> * tmp=head;
	while(tmp)
	{
            if(x==head->data)
                return 0;
            
	    if(x < tmp->data)
	    {
		if(tmp->left)
		    tmp=tmp->left;
		else
		{
		    tmp->left=new Node<T>(x);
		    return 1;
		}
	    }
	    else
	    {
		if(tmp->right)
		    tmp=tmp->right;
		else
		{
		    tmp->right=new Node<T>(x);
		    return 1;
		}
	    }
	    
	}

    }
    return 0;
}

template<class T>
int BinarySearchTree<T>::remove(T val)
{
    if(!head)
        return 0;
    
    Node<T> * tmp=head;
    Node<T> * prev;
    while(tmp)
    {
        if(val==tmp->data)
        {
            cout << "val= " << val << " is found. removing it now ..." << endl;
            // do_remove();
            if(!tmp->left && !tmp->right)
            {
                cout << val << " has no children" << endl;
                // node to remove has no children
                if(tmp==prev->left)
                    prev->left=0;
                else
                    prev->right=0;
            
                delete tmp;
            }
            else if(tmp->left && tmp->right)
            {
                cout << val << " has 2 children" << endl;
                // node has 2 children

                // find smallest element in right sub-tree
                // swap val with tmp
                // remove leaf

                Node<T> * smallest_prev=tmp;
                Node<T> * smallest=smallest_prev->right;
                
                while(smallest->left)
                {
                    smallest_prev=smallest;
                    smallest=smallest->left;
                }
                cout << "smallest val: " << smallest->data << endl;
                
                tmp->data=smallest->data;

                if(smallest==smallest_prev->left)
                {
                    cout << "smallest_prev->left" << endl;
                    smallest_prev->left=0;
                }
                else
                {
                    cout << "smallest_prev->right" << endl;
                    smallest_prev->right=0;
                }
                delete smallest; 
                            
            }
            else
            {
                cout << val << " has 1 child" << endl;

                // node has 1 child
                if(tmp==prev->left)
                {
                    if(tmp->left)
                        prev->left=tmp->left;
                    else
                        prev->left=tmp->right;
                }
                else
                {
                    if(tmp->left)
                        prev->right=tmp->left;
                    else
                        prev->right=tmp->right;
                }
                delete tmp;
            }
            
            return 1;
        }
        else if(val>tmp->data)
        {
            prev=tmp;
            tmp=tmp->right;
        }
        else
        {
            prev=tmp;
            tmp=tmp->left;
        }
            
    }
    
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
	b.add(9);
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


        b.remove(16);
        
	cout << " AFTER removing ... " << endl;
	b.print();


	return 0;

}
