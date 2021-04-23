// Very very epic function


// Function to do level order
// traversal line by line
void levelOrder(node *root)
{
    if (root == NULL) return;
  
    // Create an empty queue for
    // level order tarversal
    queue<node *> q;
      
    // to store front element of 
    // queue.
    node *curr;
  
    // Enqueue Root and NULL node.
    q.push(root);
    q.push(NULL);
  
    while (q.size() > 1)
    {
        curr = q.front();
        q.pop();
          
        // condition to check 
        // occurrence of next 
        // level.
        if (curr == NULL)
        {
           q.push(NULL);
           cout << "\n";
        }
          
        else {
              
            // pushing left child of 
            // current node.
            if(curr->left)
            q.push(curr->left);
              
            // pushing right child of
            // current node.
            if(curr->right)
            q.push(curr->right);
              
            cout << curr->data << " ";
        }
    }
}
