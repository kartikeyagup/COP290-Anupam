#include <bits/stdc++.h>

using namespace std;


struct instruction
{
	string filename ;
	int action;
};


/* List of actions with codes:
	0 	->	no change
	1	->	server file to be deleted
	2	->	client file to be added in server
	3	->	client file to be updated
	4	->	server file to be updated
	5	->	send text from server to client
	6	->	send text from client to server
	*/
class DoAction
{
	private:
		//conatins filename with actions
		vector<instruction> actions;
	public:

		DoAction();
		void setAct(vector<instruction> acts);
		vector<instruction> getAct(); 
		//reads action and acts accordingly
		void Act();				
};

