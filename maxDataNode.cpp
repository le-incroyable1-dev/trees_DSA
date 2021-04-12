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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    int max = -99999999999;
    queue<TreeNode<int>*> pendingNodes;
    TreeNode<int>* maxNode = new TreeNode<int>(max);
    
    pendingNodes.push(root);
    
    while(!pendingNodes.empty())
    {
        TreeNode<int>* curNode = pendingNodes.front();
        
        if(curNode -> data > max)
        {
            max = curNode -> data;
            maxNode = curNode;
        }
        
        pendingNodes.pop();
        
        for(int i = 0; i < curNode -> children.size(); i++)
            pendingNodes.push(curNode -> children.at(i));
        
    }
    
    return maxNode;
}
