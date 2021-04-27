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


BinaryTreeNode<int> *tree(int *input, int start, int end){
    if(start > end){    //base case
        return NULL;
    }
    int mid = (start + end) / 2;    //mid of array
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);    //assign mid as root
    root -> left = tree(input, start, mid - 1);    // call to left
    root -> right = tree(input, mid + 1, end);    // call to right
    return root;
}


BinaryTreeNode<int>* constructTree(int *input, int n) {
    int start = 0;    //start of array
    int end = n - 1;    //end of array
    return tree(input, start, end);
}
