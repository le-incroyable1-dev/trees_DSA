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

int getHeight(TreeNode<int>* root) {
    // Write your code here
    
    if(root -> children.size() == 0)
    {
        return 1;
    }
    else if(root -> children.size() == 1)
    {
        int smallOutput = 1 + getHeight(root->children.at(0));
        return smallOutput;
    }
    else
    {
        int maxH = 0;
        
        for(int i = 0; i < root->children.size(); i++)
        {
            int curH = getHeight(root->children.at(i));
            
            if(curH > maxH)
            {
                maxH = curH;
            }
        }
        
        int smallOutput = 1 + maxH;
    	return smallOutput;
    }
}
