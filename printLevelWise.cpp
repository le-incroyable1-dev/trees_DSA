/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

void printLevelWise(TreeNode<int>* root) {
	// Write your code here
	queue<TreeNode<int>*>  pendingNodes;

	pendingNodes.push(root);

	while (!pendingNodes.empty())
	{
		TreeNode<int>* curNode = pendingNodes.front();

		cout << curNode->data << ":";
		pendingNodes.pop();

		for (int i = 0; i < curNode->children.size(); i++)
		{
			cout << curNode->children.at(i)->data;
			if (i < curNode->children.size() - 1)
				cout << ",";
			pendingNodes.push(curNode->children.at(i));
		}

		cout << endl;
	}

}
