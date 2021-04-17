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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
    if(root1 == NULL && root2 == NULL)
        return true;
    
    if(root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL)
        return false;
    
    if(root1 -> children.size() != root2 -> children.size())
        return false;
    
    for(int i = 0; i < root1->children.size(); i++)
    {
        TreeNode<int> *child1 = root1->children.at(i);
        TreeNode<int> *child2= root2->children.at(i);
        
        if(!areIdentical(child1, child2))
            return false;
    }
    
    return true;
}
