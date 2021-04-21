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

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/

#include <algorithm>
#include <climits>

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    
    if(root == NULL)
    {
        pair<int, int> p;
        
        p.first = INT_MAX;
        p.second = INT_MIN;
        
        return p;
    }
    else
    {
        pair<int, int> leftP = getMinAndMax(root -> left);
        pair<int, int> rightP = getMinAndMax(root -> right);
        
        int maxp = max(max(leftP.second, rightP.second), root->data);
        int minp = min(min(leftP.first, rightP.first), root->data);
        
        pair<int, int> p;
        p.first = minp;
        p.second = maxp;
        
        return p;   
    }
    
}
