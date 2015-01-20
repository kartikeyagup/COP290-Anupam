#ifndef TestRecCir
#include <bits/stdc++.h>
//#include "Rectangle1.h"
#include "Circle1.h"
#include "Test.h"
#include "TestRecCir.h"
#endif
using namespace std;

Rectangle* bo=new Rectangle();


Maintest:: Maintest(){
}


bool Maintest:: Runalltest(){
	Testlength();
	Testwidth();
	Testheight();
	Testrcolor();
	Testgcolor();
	Testbcolor();
	Testxcord();
	Testycord();
	Testzcord();
	Testrad();
	Testxspeed();
	Testyspeed();
	Testzspeed();
	Testxccord();
	Testyccord();
	Testzccord(); 
	Testzcord();
	TestMove();
	//TestCollision();
	cout<<"All passed"<<endl;
}



bool Maintest:: Testlength(){
	Test a;
	bool t1=a.verify((bo->dimension)->x==1000.0,"length is 1000.0");
	return t1;
	// bool t2= a.verify(b.width==4000.0,"width is 4000.0");
	// bool t3=

}


bool Maintest:: Testwidth(){
	Test a;
	bool t1=a.verify((bo->dimension)->y==4000.0,"width is 4000.0");
	return t1;
}

bool Maintest:: Testheight(){
	Test a;
	bool t1=a.verify((bo->dimension)->z==2000.0,"height is 2000.0");
	return t1;
}

bool Maintest:: Testrcolor(){
	Test a;
	bool t1=a.verify((bo->colour)->x==1.0,"Red is 1.0");
	return t1;
}

bool Maintest:: Testgcolor(){
	Test a;
	bool t1=a.verify((bo->colour)->y==1.0,"Green is 1.0");
	return t1;
}

bool Maintest:: Testbcolor(){
	Test a;
	bool t1=a.verify((bo->colour)->z==0.0,"Blue is 0.0");
	return t1;
}

bool Maintest:: Testxcord(){
	Test a;
	bool t1= a.verify((bo->position)->x==5.0,"x-cord is 10.0");
	return t1;
}

bool Maintest:: Testycord(){
	Test a;
	bool t1= a.verify((bo->position)->y==10.0,"y-cord is 10.0");
	return t1;
}

bool Maintest:: Testzcord(){
	Test a;
	bool t1= a.verify((bo->position)->z==10.0,"z-cord is 10.0");
	return t1;
}

Vect* poscircle=new Vect(2.0,-1.0,2.0);
Vect* spee=new Vect(-2.0,1.0,-3.0);

Circle c1(2.0,poscircle,spee);
// Circle c2(2.0,-4.0,2.0,4.0,-2.0);

bool Maintest:: Testrad(){
	Test a;
	bool t1=a.verify(c1.radius==2.0,"Radius is 2.0");
	return t1;
}

bool Maintest:: Testxspeed(){
	Test a;
	bool t1=a.verify((c1.speed)->x==-2.0,"x-speed is -2.0");
	return t1;
}

bool Maintest:: Testyspeed(){
	Test a;
	bool t1=a.verify((c1.speed)->y==1.0,"y-speed is 1.0");
	return t1;
}

bool Maintest:: Testzspeed(){
	Test a;
	bool t1=a.verify((c1.speed)->z==-3.0,"z-speed is -3.0");
	return t1;
}

bool Maintest:: Testxccord(){
	Test a;
	bool t1=a.verify((c1.position)->x==2.0,"x-cord is 2.0");
	return t1;
}

bool Maintest:: Testyccord(){
	//cout<<"ajlkfja"<<endl;
	Test a;
	bool t1=a.verify((c1.position)->y==-1.0,"y-cord is -1.0");
	return t1;
}

bool Maintest:: Testzccord(){
	Test a;
	bool t1=a.verify((c1.position)->z==2.0,"z-cord is 2.0");
	return t1;
}


bool Maintest:: TestMove(){
	Test a;
	c1.Move();
	// cout<<(c1.position)->x<<endl;
	// cout<<(c1.position)->y<<endl;
	// cout<<(c1.position)->z<<endl;
	// exit(0);
	bool t1=a.verify((c1.position)->x==1.998,"Final x-cord is 1.998");
	bool t2=a.verify((c1.position)->y==-0.999,"Final y-cord is -0.999");
	bool t3=a.verify((c1.position)->z==1.997,"Final z-cord is 1.997");
	return (t1 && t2 && t3);
}

// Circle c3(2.0,2.0.0.0,-2.0,0.0);
// Circle c4(2.0,-2.0.0.0,2.0,0.0);
// bool Maintest:: TestCollision(){
// 	Test a;
// 	double dist = sqrt((c1.xcord- c2.xcord)*(c1.xcord - c2.xcord) + (c1.ycord - c2.ycord)*(c1.ycord-c2.ycord));
// 	while(dist*(0.2) < c1.radius + c2.radius){
// 		c1.Move();
// 		c2.Move();
	
// 	}
// 		c1.Collision(c2);
// 	cout<<c1.xspeed<<"ronak"<<endl;
// 	bool t1=a.verify((c1.xspeed==-4.0 )&& (c2.xspeed==2.0) ,"x-speed is not matched");
// 	bool t2=a.verify((c1.yspeed==2.0) && (c2.yspeed==-1.0),"y-speed is not matched");
// 	return (t1 && t2);
// }

// bool Maintest::TestReflection(){
// 	Test a;
// 	bool t = (c1.xcord <= bo->vertices[0].first + radius);				//left line of rectangle
// 	bool z = (c1.xcord + radius >= bo->vertices[1].first );				//right line
// 	bool c = (c1.ycord <= bo->vertices[0].second + radius ); 			//bottom line 
// 	bool d = (c1.ycord +radius >= bo->vertices[2].second);				//up lne
// 	while(t || z || c ||d){
// 		c1.Move();
// 	}
// 	if(t)
// 		{
// 			 c1.xspeed = abs(c1.xspeed) ;
// 			 bool t1=a.verify((c1.xspeed==))
// 		}
// 	else if(z) xspeed = -abs(xspeed);
// 	else if(c)
// 	{
// 		  yspeed = abs(yspeed) ;
// 	}
// 	else if(d) yspeed = -abs(yspeed);

// }

int main(){
	Vect *dimensio = new Vect(1000.0,4000.0,2000.0);
	Vect *colou = new Vect(1.0,1.0,0.0);
	Vect *positio= new Vect(5.0,10.0,10.0);
	bo->Rectang(dimensio,colou,positio);
	Maintest a;
	a.Runalltest();
	return 0;
}


// bool Maintest:: TestCollision(){
// 	Test a;
// 	c3.Collsion(c4);
// 	bool t1=a.verify(c3.xspeed==2.0,"Speed is 2.0");
// 	bool t2=a.verify(c4.xpeed==-2.0,"Speed is -2.0");
// 	return (t1 && t2);
// }

// bool Maintest:: TestReflection(){
// 	Test a;

// }