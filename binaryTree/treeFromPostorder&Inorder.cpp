/***********************************************************
	Following is the Binary Tree Node class structure

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

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    
    if(inLength == 0)
        return NULL;
    else if(inLength == 1)
    {
        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[postLength-1]);
        return root;
    }
    else
    {
        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[postLength-1]);
        
        int i = 0;
        
        while(inorder[i] != postorder[postLength-1])
        {
            i++;
        }
        
        
        int left_size = i;
        int right_size = inLength - i - 1;
        
        
        BinaryTreeNode<int>* leftRoot = buildTree(postorder, left_size, inorder, left_size);
        BinaryTreeNode<int> *rightRoot = buildTree(&postorder[left_size], right_size, &inorder[left_size + 1], right_size);
        
        root -> right = rightRoot;
        root -> left = leftRoot;
        
        return root;
    }
}
