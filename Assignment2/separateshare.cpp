void sharefile
{
	//get shared files list for users 1 and 2.
	vector<sharedfiles> us2shared = getshared(us2 , Directory);
	vector<sharedfiles> us1shared = getshared(us1 , Directory);
	vector<filenames> us1files = getfiles()
	//search if file is already present in shared files of us2.
	for(int i=0;i<us2shared.size();i++)
	{
		//if file exists , push the username us1 to the shared file list.
		if(us2shared[i].clientname == file)
		{
			us2shared[i].commusers.push_back(us1);
			for(int i=0;i<u1shared.size();i++)
			{
				if(us1shared[i].clientname==file)
				{

					us1shared[i].commonusers.push_back(us2);
					goto g ;
				}
				for(int j=0;j<us1files[i].size();j++)
				{
					if(us1files[j].clientname = +file)
					{
						//TODO : add the files into the shared folder of us1.
						us1files.erase(us1files.begin() + j);
					}
				}
			}
		}
	}
}