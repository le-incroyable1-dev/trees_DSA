/*
We will try to find the diameter of a binary tree by a slighty
better approach. Here we return the diameter as well as the height together 
in order to avoid the height calculation being repeated.

also refer : https://www.geeksforgeeks.org/diameter-of-a-binary-tree/

*/

#include<iostream>
#include<algorithm>

using namespace std;

pair<int, int> heightDiameter(BinaryTreeNode<int>* root)
{
  if(root == NULL) 
  {
    pair<int, int> p;
    p.first = 0;
    p.second = 0;
    return p;
  }
  else
  {
    pair<int, int> leftHD = heightDiameter(root->left);
    pair<int, int> rightHD = heightDiameter(root->right);
    
    int lh = leftHD.first;
    int ld = leftHD.second;
    
    int rh = rightHD.first;
    int rd = rightHD.second;
    
    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    
    return p;
  }
  
}
