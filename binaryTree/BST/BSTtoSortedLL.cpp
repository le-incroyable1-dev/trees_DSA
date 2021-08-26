/*

Code: BST to Sorted LL

Given a BST, convert it into a sorted linked list. You have to return the head of LL.

Input format:
The first and only line of input contains data of the nodes of the tree in level order form. 
The data of the nodes of the tree is separated by space. If any node does not have left or right child, 
take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, 
it will not be a part of the data of any node.   

Output Format:
The first and only line of output prints the elements of sorted linked list.

Constraints:
Time Limit: 1 second

*/

/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    
    if(root == NULL)
        return NULL;
    
    Node<int> * leftLL = constructLinkedList(root -> left);
    Node<int> * rightLL = constructLinkedList(root -> right);
    
    if(leftLL != NULL && rightLL != NULL)
    {
        Node<int> *leftTail = leftLL;
    
    	while(leftTail -> next != NULL)
        	leftTail = leftTail -> next;
    
    	Node<int> * rootNode = new Node<int> (root -> data);
    
    	leftTail -> next = rootNode;
    
    	rootNode -> next = rightLL;
    
    	return leftLL;
    }
    else if(leftLL == NULL && rightLL != NULL)
    {
        Node<int> * rootNode = new Node<int> (root -> data);
    
    	rootNode -> next = rightLL;
    
    	return rootNode;
    }
    else if(leftLL != NULL && rightLL == NULL)
    {
        Node<int> *leftTail = leftLL;
    
    	while(leftTail -> next != NULL)
        	leftTail = leftTail -> next;
    
    	Node<int> * rootNode = new Node<int> (root -> data);
    
    	leftTail -> next = rootNode;
    
    	rootNode -> next = NULL;
    
    	return leftLL;
    }
    else
    {
        Node<int> * rootNode = new Node<int> (root -> data);
        rootNode -> next = NULL;
        
        return rootNode;
    }
    
}
