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

#include <climits>

int height(BinaryTreeNode<int>* root) {
    // Write our code here
    if(root == NULL)
        return 0;
    else
    {
        int maxH = INT_MIN;
        bool flag = false;
        
        if(root -> left != NULL)
        {
            int lH = height(root -> left);
            if(lH > maxH)
                maxH = lH;
            
            flag = true;
        }
        
        if(root -> right != NULL)
        {
            int rH = height(root -> right);
            if(rH > maxH)
                maxH = rH;
            
            flag = true;
        }
        
        if(flag)
            return 1 + maxH;
        else
            return 1;
    }
}
