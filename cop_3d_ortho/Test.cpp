#ifndef Test
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "Test.h"

Test:: Test(){
	pass=true;
}

bool Test::verify(bool a, string s){
	if(a==false){
		pass=false;
		cout<<pass<<"  "<< s<<endl;
		exit(0);
	}
	else{
		return pass;
	}
}

#endif