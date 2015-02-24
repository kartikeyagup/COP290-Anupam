#include <bits/stdc++.h>

using namespace std;

DoAction::DoAction()
{
	actions = new vector<instruction>;
}

void DoAction::setAct(vector<instruction> acts)
{
	actions = acts;
}

vector<instruction> DoAction::getAct()
{
	return actions;
}



void DoAction::Act()
{
	for(int i=0;i<actions.size();i++)
	{
		switch(files[i].action)

			case 1:
			{
				//TODO : Deletion of file from server.
			}
			case 2:
			{
				//TODO : Addition of file in client.
			} 
			case 3:
			{
				//TODO : WRITE CODE TO UPDATE THE CLIENT SIDE FILE BY SENDING
			}
			default:
			{
				TODO :
				deletefile(files[i].filename , us);
				addfile(files[i].filename, us);
			}
		}	
}