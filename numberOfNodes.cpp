int numNodes(treeNode<int>* root)
{
	int ans = 1;

	for (int i = 0; i < root->children.size(); i++)
	{
		ans += numNodes(root->children.at(i));
	}

	return ans;
}
