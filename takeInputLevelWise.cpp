/*
Take input level wise
in a tree
*/

treeNode<int>* takeInputlevelWise()
{
	int rootData;

	cout << "\nEnter root data : ";
	cin >> rootData;

	treeNode<int>* rootNode = new treeNode<int>(rootData);

	queue<treeNode<int>*> pendingNodes;

	pendingNodes.push(rootNode);

	while (!pendingNodes.empty())
	{
		treeNode<int>* nextNode = pendingNodes.front();
		pendingNodes.pop();

		cout << "\nEnter number of children of " << nextNode->data << " : ";
		int numChild;
		cin >> numChild;

		for (int i = 0; i < numChild; i++)
		{
			int childData;
			cout << "\nEnter the data of " << i << "th child : ";
			cin >> childData;

			treeNode<int>* newChild = new treeNode<int>(childData);

			pendingNodes.push(newChild);
			nextNode->children.push_back(newChild);
		}
	}

	return rootNode;

}
