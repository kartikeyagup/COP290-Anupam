void addelement(string filepath, Nodeserver node)
{
	Nodeserver start = node;
	for(int i=0;i<vect.size();i++)
	{
		for(int j=0;j<start.children.size();j++)
		{
			//a child already exists
			if(start.chidren[j].name == vect[i])
			{
				start = vect[i].children[j];
				goto g;
			}
		}
		//adding a new node
		Nodeserver topush;
		topush.name = vect[i];
		topush.height = start.height + 1; 
		topush.path = filepath;
		topush.parent = start; 
		start.children.push_back(topush);
		start = start.children[start.size()-1];
		//if the child does not exist , add a child to the parent and reach here.
 		g: ;
	}
}

vector<Nodeserver*> elematheight(int h)
{
	vector<Nodeserver*> vect ; 
	queue<Nodeserver*> q;
	q.push(root);
	//while the popped element has height <= h .
	while(q.front()->height <= h)
	{
		Nodeserver* elem = q.front();
		q.pop();
		for(int i=0;i<elem->children.size();i++)
		{
			q.push(elem->children[i]);
		}
		//adding only elements with height h;
		if(elem->height==h)
		{
			vect.push_back(elem);
		}
	}
	return vect;
}
