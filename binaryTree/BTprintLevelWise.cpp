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

void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL)
        return;
    else
    {
        queue<BinaryTreeNode<int>*> pendingNodes;
        pendingNodes.push(root);
        
        while(!pendingNodes.empty())
        {
            BinaryTreeNode<int>* frontNode = pendingNodes.front();
            pendingNodes.pop();
            
            cout << frontNode -> data << ":" ;
            
            cout << "L:";
            if(frontNode -> left == NULL)
                cout << -1;
            else
            {
                cout << frontNode -> left -> data;
                pendingNodes.push(frontNode -> left);
            }
            
            cout << ",";
            
            cout << "R:";
            if(frontNode -> right == NULL)
                cout << -1;
            else
            {
                cout <<frontNode -> right -> data;
                pendingNodes.push(frontNode -> right);
            }
            
            cout << endl;
            
            
            
        }
    }
}
