/***********************************************************
//	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

BinaryTreeNode<int>* buildTree(int *preOrder, int preLength, int *inOrder, int inLength) {
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preOrder[0]);
    
    if(preLength == 1)     
        return root;
    if(preLength == 0)    
        return NULL;
    
    int i = 0;
    
    while(inOrder[i] != preOrder[0]){
        i++;
    }
    
    int left_size = i;
    int right_size = inLength - i - 1;
    
    BinaryTreeNode<int> *leftSubtree = buildTree(preOrder + 1, left_size, inOrder, left_size);
    BinaryTreeNode<int> *rightSubtree = buildTree(preOrder + 1 + left_size, right_size, inOrder + 1 + left_size, right_size);
    
    root -> left = leftSubtree;
    root-> right = rightSubtree;
    
    return root;
}
