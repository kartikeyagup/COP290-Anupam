#include <bits/stdc++.h>


using namespace std;

//SERVER PART :




Storage a;
a= new Storage();
Authentication b;
b = new Authentication();

void newuser()
{
	char* userdata = func();
	a.adduser(userdata);
	file2client()
	//send the client executable file.
}

void signin()
{
	//receive txt file with username and password.
	char* usandpass = func();
	a.isAuthenticated(usandpass);

	//send the file back to the client whether it is authenticated or not
}


void forgotpassword()
{
	//receive txt file with username and Answer .
	char* username =  func();
	a.sec(username);
	//send the security ques back to client.The file is secure.txt . If the file is empty , no such user exists.
}

void checksecans()
{
	//receive answer from Ronak.
	char* ans = func()
	a.verify(ans);
	//send the result back to ;the client whether the answer is correct or not.(verify.txt)
}

void  changepassword()
{
	//receive new password.
	a.changepass(newpass);
}


void deleteus()
{
	//
}

//add file to server(fts)
void addfts()
{
	//
}


//delete file from server.
void deleteffs()
{

}

//update file from server.
void updateffs()

