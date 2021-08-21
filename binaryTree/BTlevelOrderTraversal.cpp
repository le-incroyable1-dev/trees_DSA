/*
Level order traversal

For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion and a single space will separate them.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. 
Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
*/

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


#include <queue>

void printLevelWise(BinaryTreeNode<int> *root) {
    
    if(root == NULL)
        return;
    
    queue<BinaryTreeNode<int> *> pendingNodes;
    BinaryTreeNode<int> * frontNode = new BinaryTreeNode<int>(0);
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    
    while(!pendingNodes.empty())
    {
        frontNode = pendingNodes.front();
        
        if(frontNode == NULL)
        {
            if(pendingNodes.size() == 1)
                break;
            
            pendingNodes.pop();
            pendingNodes.push(NULL);
            cout << endl;
            continue;
        }
        
        cout << frontNode -> data << " ";
        
        if(frontNode -> left != NULL)
            pendingNodes.push(frontNode -> left);
        
        if(frontNode -> right != NULL)
            pendingNodes.push(frontNode -> right);
        
		pendingNodes.pop();        
        
    }
    
}
