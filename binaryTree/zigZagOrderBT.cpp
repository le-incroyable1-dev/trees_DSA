
/*

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

#include <stack>
#include <queue>
#include <iostream>
using namespace std;
*/


//TEST CODE -----
//NOT VERIFIED -----


#include <stack>

void zigZagOrder(BinaryTreeNode <int>* root)
{
    if (root == NULL)
        return;
    else
    {
        int curLvl = 0;
        
        BinaryTreeNode<int>* frontNode;

        queue<BinaryTreeNode<int>*> pendingNodes;
        stack<BinaryTreeNode<int>*> oppositePrint;

        pendingNodes.push(root);
        pendingNodes.push(NULL);

        while (!pendingNodes.empty())
        {
            frontNode = pendingNodes.front();
            pendingNodes.pop();
            

            if (frontNode == NULL)
            {
                if (curLvl % 2 == 0)
                {
                    while (!oppositePrint.size() == 0)
                    {
                        cout << oppositePrint.top() -> data << " ";
                        oppositePrint.pop();
                    }
                }

                pendingNodes.push(NULL);
                curLvl++;

                cout << endl;
            }
            else {
            
                if (frontNode->left)
                {
                    pendingNodes.push(frontNode->left);
                    if (curLvl % 2 == 0)
                    {
                        oppositePrint.push(frontNode->left);
                    }

                }

                if (frontNode->right)
                {
                    pendingNodes.push(frontNode->right);
                    if (curLvl % 2 == 0)
                    {
                        oppositePrint.push(frontNode->right);
                    }
                }

                if (curLvl % 2 == 0)
                {
                    cout << frontNode->data << " ";
                }

            }

        }
    }
}
