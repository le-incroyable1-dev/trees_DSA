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


void depthHelper(TreeNode<int> *root, int depth)
{
    root -> data = depth;
    depth++;
    
    for(int i = 0; i < root->children.size(); i++)
    {
      //root -> children.at(i) -> data = depth;
        depthHelper(root->children.at(i), depth);
    }
}


void replaceWithDepthValue(TreeNode<int>* root) {
    // Write your code here
    
    int depth = 0;
    
    if(root == NULL)
        return;
    else
    {
        depthHelper(root, depth);
    }
    
}
