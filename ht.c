int treeHeight(node *root)
{
    // Base Case
    if (root == NULL)
        return 0;
 
    // Create an empty queue for level order tarversal
    queue<node *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
    int height = 0;
 
    while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = q.size();
        if (nodeCount == 0)
            return height;
 
        height++;
 
        // Dequeue all nodes of current level and Enqueue all
        // nodes of next level
        while (nodeCount > 0)
        {
            node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
    }
}
