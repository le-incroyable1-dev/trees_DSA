/**********************************************************
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

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root == NULL)
        return;
    else
    {
        if(root->left == NULL && root->right == NULL)
            return;
        else if(root->left == NULL && root->right != NULL)
        {
            root -> left = root -> right;
            root -> right = NULL;
            
            mirrorBinaryTree(root->left);
        }
        else if(root->left != NULL && root->right == NULL)
        {
            root -> right = root -> left;
            root -> left = NULL;
            
            mirrorBinaryTree(root->right);
        }
        else
        {
            BinaryTreeNode<int>* rightNode = root -> right;
            BinaryTreeNode<int>* leftNode = root -> left;
            
            root -> right = leftNode;
            root -> left = rightNode;
            
            mirrorBinaryTree(root -> right);
            mirrorBinaryTree(root -> left);
        }
    }
}
