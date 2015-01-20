#ifndef AFA
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <bits/stdc++.h> 
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <vector>
#include <GL/glu.h>
#include <pthread.h>
#include <random>
#include <mutex>
#include <GL/glui.h>
//#include "color.h"
#include "Vect.h"

using namespace std;

//#include "Rectangle1.h"
#include "Circle11.h"

#define add   200
//#define play  300
#define Delete 250
#define pause 500
#define idx 301
#define idy 302
#define show 100
#define box1 101
int nabled=0;
float xspee=0;
float yspee=0;
int   main_window;
double maxspeed=100;
pthread_mutex_t imutex; //= PTHREAD_MUTEX_INITIALIZER;
vector<Circle*> balls;
vector<pair<Circle*,bool> > newballs;
vector<pair<double,double> > forpause;
vector<int> forcolor;
Rectangle* b=new Rectangle();
double asp;
vector<bool> reflect;
vector<pthread_t*> threads;
pair<double,double>* centre;
double r;
double g;
double bl;
//keys k(balls);
bool* keystates = new bool[256];
int whatallkeys=0;
int i;
int xwindow, ywindow, wid, heig ;
GLUI_EditText *xyz;
GLUI_EditText *ysp;




vector<Vect*> colvector;
vector<Vect*> finalvector;
Vect* color;

void changetoratio(){
	for(int i=0;i<colvector.size();i++){
		double sum=colvector[i]->x+colvector[i]->y+colvector[i]->z;
		color=new Vect(colvector[i]->x/255.0,colvector[i]->y/255.0,colvector[i]->z/255.0);
		finalvector.push_back(color);
	}

}


void addcolors(){
	

	color=new Vect(0, 1, 1);
	colvector.push_back(color);
	color=new Vect(124, 252, 0);
	colvector.push_back(color);
	color=new Vect(205,92,92);
	colvector.push_back(color);
	color=new Vect(178,34,34);
	colvector.push_back(color);
	color=new Vect(255,69,0);
	colvector.push_back(color);
	color=new Vect(134,43,226);
	colvector.push_back(color);
	color=new Vect(0,0,139);
	colvector.push_back(color);
	color=new Vect(78,238,148);
	colvector.push_back(color);
	color=new Vect(205,41,144);
	colvector.push_back(color);
	color=new Vect(205,0,0);
	colvector.push_back(color);
	color=new Vect(255,215,0);
	colvector.push_back(color);
	color=new Vect(102,205,0);
	colvector.push_back(color);
	color=new Vect(131,11,255);
	colvector.push_back(color);
	color=new Vect(208,32,144);
	colvector.push_back(color);
	color=new Vect(255,215,0);
	colvector.push_back(color);
	color=new Vect(123,104,238);
	colvector.push_back(color);
	color=new Vect(189, 195, 199);
	colvector.push_back(color);
	color=new Vect(127, 140, 141);
	colvector.push_back(color);
	changetoratio();
}



float ver[8][3] = 
{
    {-1.0*(1280.0/720.0),0.0,1.0},
    {-700.0,700.0,700.0},
    {700.0,700.0,700.0},
    {-1.0*(1280.0/720.0),-1.0,1.0},
    {1.0*(1280.0/720.0),0.0,1.0},
    {-700.0,700.0,-700.0},
    {700.0,700.0,-700.0},
    {1.0*(1280.0/720.0),-1.0,1.0},
};



double transp=0.5;
void quad(int a,int b,int c,int d,double r,double g,double bl,double transp)
{
    glBegin(GL_QUADS);
    glColor4f(r,g,bl,transp);    
	//glColor3fv(color[a]);
    glVertex3fv(ver[a]);

    //glColor3fv(color[b]);
    glVertex3fv(ver[b]);

    //glColor3fv(color[c]);
    glVertex3fv(ver[c]);

    //glColor3fv(color[d]);
    glVertex3fv(ver[d]);
    glEnd();
}



void colorcube()
{
    //quad(0,3,2,1,1,1,1,1);
    //quad(2,3,7,6,0,1,0,1);
    quad(3,7,4,0,0,1.91,2.55,transp);
    //quad(1,2,6,5,1,0,0,0.5);
    //quad(4,5,6,7,0,0,1,0.5);
    //quad(0,1,5,4,0,1,0,0.5);
}










void randm(int n,double r, double len, double weight)
{		
	int k1= int((len/(r*3)));
	int k2 = int(((weight)/(r*3)));		
	int max_range=k1*k2;
	vector<int> pos;
	int ch=0;
	int num=0;
	int j=0;
	for(int i=0;i<max_range&&j<n;i++)
	{	int rn = max_range-i;
		int rm = n- j ;
		if(rand()%rn<rm)
		{	pos.push_back(i+1);
		}
	}
	
	centre = new pair<double,double>[n];
	for(int i=0;i<n;i++)
	{	int nu=pos[i];
		int ylane= nu%k2;
		if(ylane==0)ylane=k2; // along the length side 
		int xlane = nu/k2;
		double xcen =  xlane*3*r + 1.5*double(r);
		double ycen = (ylane-1)*3*r+ 1.5*r;
		centre[i]=make_pair(xcen,ycen);
	}
}



static void resize(int width, int height)
{	
	GLUI_Master.get_viewport_area (& xwindow, & ywindow, & wid, & heig); 
	glViewport (xwindow, ywindow, wid, heig); 
	//cout<<wid<<" "<<heig<<endl;
	//exit(0);
    const float ar = (float) wid / (float) heig; 
   	
    //glViewport(0, 0, width, height);
    //GLUI_Master.auto_set_viewport();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glOrtho(-1*ar,1*ar,-1,1,-1,1); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    glutPostRedisplay();

} 
 
double raw[1000];
double act[1000];

vector<pair<double,double>> loc;

double min(double a , double b)
{	return a>b ? b:a;
}

vector<int> pos_cl;		

int random(int n)
{	double w = glutGet(GLUT_WINDOW_WIDTH);
	double ht = glutGet(GLUT_WINDOW_HEIGHT);
	int pixel_l = w, pixel_w = ht;
	int  max= pixel_l*pixel_w;
	double ortho_x  = 1.0*((w-163)/ht)*2.0;
	double ortho_y = 1.0*2.0;
	int chi=1;
	int last=0;
	int cre=0;
	double len = ortho_x/pixel_l; // along the length
	double width = ortho_y/pixel_w; // along the width
	double min1 = min(len,width);
	for(int i=0;i<n;i++)
	{	raw[i]=double (act[i])/(double)min1;
	}
	int counter=0;

	while(chi!=n+1)
	{	double d;
	
		cre=(rand()*rand())%max;
		;
		d=100000000.0;     // int max rough value
		
		int y_dis2 = cre%pixel_l;
		if(y_dis2==0)y_dis2 = pixel_l;
		
		int x_dis2 = cre/pixel_l + 1;
		if( x_dis2 >= raw[chi-1] + 1 && x_dis2 + raw[chi-1] <= pixel_w && y_dis2 >= raw[chi-1] + 1 && y_dis2 + raw[chi-1] <= pixel_l ) /// doesnot exceed the boundary condition
		{	
			for(int i=0;i<pos_cl.size();i++)
			{	int x_dis1= pos_cl[i]/pixel_l+1;
				int y_dis1 = pos_cl[i]%pixel_l;	
				if(y_dis1==0)y_dis1=pixel_l;
				d = min(d,sqrt((x_dis1-x_dis2)*(x_dis1-x_dis2)+(y_dis1-y_dis2)*(y_dis1-y_dis2))-raw[i]);	//minimum distance 
			}
			
			if(d>=raw[chi-1])
			{	pos_cl.push_back(cre);chi++;
			}

	
		}
				counter++;
			if(counter>1000)
			{break;	}
	}
	for(int i=0;i<pos_cl.size();i++)
	{	int num = pos_cl[i]; 
		int y1 = pos_cl[i]%pixel_l;
		if(y1==0)y1=pixel_l;
		int x1 = pos_cl[i]/pixel_l + 1;
		loc.push_back(make_pair(double(y1-1)*len,double(x1-1)*width));
	}
	return chi;
}


int addrandom(double radius)
{	int h=0;
	double w = glutGet(GLUT_WINDOW_WIDTH);
	double ht = glutGet(GLUT_WINDOW_HEIGHT);
	int pixel_l = w, pixel_w = ht;
	int max=pixel_l*pixel_w;
	double ortho_x  = 1.0*((w-163)/ht)*2.0;
	double ortho_y = 1.0*2.0;
	double len = ortho_x/pixel_l; // along the length
	double width = ortho_y/pixel_w; // along the width
	double min1 = min(len,width);
	raw[balls.size()]=(double)radius/(double)min1;
	radius= radius/(double)min1;
	int counti=0;
	int cre=0;
while(h==0)
{	cre = random()%max;
	double d =1000000000.0;
	//cout<<cre<<" cre"<<endl;
	int y_dis2 = cre%pixel_l;
		if(y_dis2==0) y_dis2 = pixel_l;
		int x_dis2 = cre/pixel_l + 1;
		if( x_dis2 >= radius + 1 && x_dis2 + radius <= pixel_w && y_dis2 >= radius + 1 && y_dis2 + radius <= pixel_l )
		{ for(int i=0;i<balls.size();i++)
		 {		int x_dis1= int(double (balls[i]->xcord+((w-163)/ht)) /double (min1) + 1) ;
				int y_dis1 = int( (double)(balls[i]->ycord+1.0) / double(width) + 1);
				d = min(d,sqrt((x_dis1-y_dis2)*(x_dis1-y_dis2)+(y_dis1-x_dis2)*(y_dis1-x_dis2))-raw[i]);
			
			
	    	}
		 if(d>=radius)
				{	pos_cl.push_back(cre);h++;}
		}
		cout<<"chotu"<<endl;
		counti++;
		if(counti>10000)
			{	break;}
	}
	if(h==1)
	{	int y3 = cre%pixel_l;
		if(y3==0)y3 = pixel_l;
		int x3 = cre/pixel_l + 1;
		loc.push_back((make_pair(double(y3-1)*len,double(x3-1)*width)));
		}
		return h;
	}
pair<int,int> a;
int deleteball(int x , int y)
{
	double w = glutGet(GLUT_WINDOW_WIDTH);
	double h = glutGet(GLUT_WINDOW_HEIGHT);	
	int x_pix=x;
	int y_pix=y;
	int pos=-1;
	double x1 = (2*((w-163)/h) * (double)x_pix )/(w-163);
	double y1 = (2.0* (double)y_pix )/ h;
	cout<<y_pix<<" mmm"<<(2.0* (double)y_pix )<<endl;
	x1  = x1 - ((w-163)/h); y1 = -y1 + (1.0);
	cout<<x1<< " yoyo"<<y1<<endl;
	for(int i=0;i<balls.size();i++)
	{	double x_ball=  balls[i]->xcord; double y_ball = balls[i]->ycord;
		double d= sqrt(pow(x_ball-x1,2)+pow((y_ball-y1),2)) - act[i];
		if(d<0)
		{	pos=i;break;}
	 }
	 return pos;
	}

int ball_number=0;
void ball_delete(){
	if(ball_number!=-1)
	{	balls.erase(balls.begin()+ball_number);
		forcolor.erase(forcolor.begin()+ball_number);
		newballs[ball_number].second=1;
		threads.erase(threads.begin()+ball_number);
	}
}

int cou;


 void myGlutMouse(int button, int button_state, int x, int y ) //return ball _number on which mouse is clicked
{	
	
	a=make_pair(x,y);
	cout<<x<<" "<<y<<endl;
	ball_number= deleteball(a.first,a.second);
	cout<<ball_number<<endl;
	glutPostRedisplay();
}

void showspeed(int ball_number){
	if(newballs[ball_number].second==0){
		xspee=forpause[ball_number].first;
		yspee=forpause[ball_number].second;
	}
}
	
vector<double> stop_acc;
void setnewxspeed(int ball_number){
	forpause[ball_number].first=xspee;
}

void setnewyspeed(int ball_number){
	forpause[ball_number].second=yspee;
}



vector<pair<double,double> >different;
vector<int> start_1;
void* update(void* arg)
{	long counter;
	counter = (long)arg;
	pthread_mutex_lock(&imutex);
	for(int j= counter+1;j<balls.size();j++)
	{		pair<double,double> point1;
			point1 = balls[counter]->Collision(*balls[j]/*(ch[counter][j],collide[counter],collide[j]*/);
			if(point1.first!=0&&point1.second!=0)
			{	different.push_back(point1);
				start_1.push_back(counter);
				start_1.push_back(j);
				//start_1.push_back(counter);start_1.push_back(j);
			}
	}

	pthread_mutex_unlock(&imutex);
	balls[counter]->Reflection(*b,reflect.at(counter));
	
	balls[counter]->Move();
	//pthread_mutex_unlock(&imutex);
}




void badd(void){
	double w = glutGet(GLUT_WINDOW_WIDTH);
	double h = glutGet(GLUT_WINDOW_HEIGHT);
	int i=balls.size();
	pthread_t* thr = new pthread_t;
	threads.push_back(thr);	
	double rad = 0.05,xs=0,ys=0,x=0,y=0;
	int chi= addrandom(rad);
	act[i]=rad;
	cout<<chi<<"uuuuuu"<<endl;

	if(chi==1)
	{	 x=loc[i].first-((w-163)/h); y=loc[i].second-1.0;
	}
	Circle* newball = new Circle(rad,xs,ys,x,y);
	pair<Circle*,bool> ain=make_pair(newball,0);
	newballs.push_back(ain);
	newball->acc_y=0;
//	newball->pau=1;
	balls.push_back(newball);
	cout<<"hul"<<balls[balls.size()-1]->xspeed<<" "<<balls[balls.size()-1]->yspeed<<" "<<balls[balls.size()-1]->acc_y<<endl;
	int a=random()%(colvector.size());
	forcolor.push_back(a);
	reflect.push_back(0);
}

int ch=0;
int ronak=0;
int water=0;
 void control_cb(int control){
  	cout<<nabled<<endl;
  //	exit(0);

  if (nabled==1){
   		if(water==1){
			
				transp=0;
		
					}
		else{
				transp=0.5;
	
			}
   		forpause.resize(0);
   		stop_acc.resize(0);
   		if(ch==0){
	   			for(int i=0;i<balls.size();i++){
	   				pair<double,double> a = make_pair(balls[i]->xspeed,balls[i]->yspeed);
	   				forpause.push_back(a);
	   				balls[i]->xspeed=0;
	   				balls[i]->yspeed=0; 
	   			}
	   			for(int i=0;i<balls.size();i++)
	   			{	balls[i]->pau=1;
	   				stop_acc.push_back(balls[i]->acc_y);balls[i]->acc_y=0;	}
	   			ch ++;
	   			}

   		if (control==add){
   			badd();
   			control=0;
   			if (balls.size()==1)
   			{
   				ronak=1;
   			}
     	}

   		 
   		if(control==Delete){
   			if(balls.size()==1){
   				ronak=0;
   			}
  			ball_delete();
     		 control = 0;
    	 }
    	 if(control==idx){
    	 	setnewxspeed(ball_number);
    	 }
    	 if(control==idy){
    	 	setnewyspeed(ball_number);
    	 }
    	 if (control==show){
    	 	cout<<xspee<<"  "<<yspee<<endl;
    	 	 showspeed(ball_number); 
    	 	 xyz->set_float_val(xspee);
    	 	 ysp->set_float_val(yspee);
    	 	 cout<<xspee<<"  "<<yspee<<endl;
    	 }
   	}
   	else if(nabled==0){ 
	   	if(water==1){
			transp=0;
			for(int i=0;i<balls.size();i++){
				balls[i]->pau=1;
			}
			
		//	for(int i=0;i<balls.size();i++)
	   	//	{	
	   	//		stop_acc.push_back(balls[i]->acc_y);	}
		}
		else{

			transp=0.5;
			for(int i=0;i<balls.size();i++){
				balls[i]->pau=0;
			}
			
		}
		
			
  //  		cout<<water<<endl;
   		if( control!= add && control!= Delete && control!= idx &&control!=idy && control != show ){
   		cout<<ronak<<"fafafafafa"<<endl;
   		if(ch==1){
   		for(int i=0;i<balls.size();i++){
   				
   				balls[i]->xspeed=forpause[i].first;
   				balls[i]->yspeed=forpause[i].second;
   				
   				balls[i]->acc_y=stop_acc[i];
   				//balls[i]->pau=0;
   			}
   		}
   			ronak=0;
   			ch = 0;	
   			cou=0;
   		
}

	}
  }





void display(void)
{
	double width = glutGet(GLUT_WINDOW_WIDTH); //Width in pixels of the current window.
    double height = glutGet(GLUT_WINDOW_HEIGHT);
	double ar = (width-163)/height;
	b->vertices[0].first = -1*ar;
	b->vertices[1].first= 1*ar;
	b->vertices[2].first = 1*ar;
	b->vertices[3].first = -1*ar;
 	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for(int i=0;i<balls.size();i++)
	{	//glColor3d(0.0702,0.508,0.42);
		//cout<<"ronak"<<endl;
		glColor3d(finalvector[forcolor[i]]->x,finalvector[forcolor[i]]->y,finalvector[forcolor[i]]->z);
		
		glPushMatrix();
		glTranslated(balls[i]->xcord,balls[i]->ycord,-1);
		glutSolidSphere(balls[i]->radius,50,50);
		glPopMatrix();
	}	
	int rc;	
	
	for(int i=0;i<balls.size();i++)
	{
		rc = pthread_create(threads.at(i),NULL,update,(void*)i);
		if(rc)
		{
			cout<<"Unable to create thread"<<endl;
			exit(1);
		}
	}
	for(int i=0;i<balls.size();i++) pthread_join(*threads.at(i),NULL);
    	//	cout<<1<<endl;
    		int counter1=0;
  //   		int yet=0;
		// while(yet<10&&different.size()!=0)
		// 	{	for(int j=0;j<different.size();j++)
		// 	{ 	glColor3d(0,0,0);
 	// 			glPushMatrix();
 	// 			glTranslated(different[j].first,different[j].second,0);
 	// 			glutSolidSphere(0.04,30,10);
 				
 	// 	//	glclear();
		// 	glPopMatrix();
		// 	// 	for(int k=0;k<2;k++)
		// 	// 	{	int l; if(k==0) l=2*j;if(k==1)l=2*j+1;
		// 	// 		glColor3d(0,1,0);
		// 	// 		glPushMatrix();
		// 	// 		glTranslated(balls[start_1[l]]->xcord,balls[start_1[l]]->ycord,0);
		// 	// 	glutSolidSphere(balls[start_1[l]]->radius,50,50);
		// 	// 	glPopMatrix();
				
		// 	// }
		// 	colorcube();
		// 	glutSwapBuffers();
 				
 	// 		glutPostRedisplay();
		// 	}yet++;
			
	 
	 different.resize(0);
 	colorcube();
 	glutSwapBuffers();
	 glutPostRedisplay();
} 
 
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; 
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 
 
/* Program entry point */
 
int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		int n;
		n= atoi(argv[1]);
		cout<<"Enter no of balls"<<endl;
		for(int i=0;i<n;i++) reflect.push_back(0);
				for(int i=0;i<n;i++)
			{	act[i]=(double)(rand()%100+40)/1000.0; }
	     glutInit(&argc, argv);
	    double x=0;
	    double y=0;
	    double rcolor=1;
	    double gcolor=1;
	    double bcolor=1;
	    cout<<"Enter rectangle parameters"<<endl;
	    glutInitWindowSize(1280,720);
	     main_window=glutCreateWindow("Yo Team Creation"); 
	    //glutFullScreen();
	    glutInitWindowPosition(b->xcord,b->ycord);
	    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
	    double w = glutGet(GLUT_WINDOW_WIDTH); //Width in pixels of the current window.
	    double h = glutGet(GLUT_WINDOW_HEIGHT);
	    b->Rectang(2*((w-163)/h),2,rcolor, gcolor, bcolor,x, y);	   
	 	GLUI_Master.set_glutMouseFunc( myGlutMouse );
		int a;
		a = random(n);
		a--;
	
	addcolors();
	n=a;
	for(int i=0;i<n;i++){
		double x=loc[i].first-((w-163)/h)/*-5+2*i*/,y=loc[i].second-1.0/*-5+2*i*/,rad=act[i],/*random()%2/10.0+0.1*/xs=/*-30*/rand()%10 - 8,ys=/*-30*/rand()%10 - 8;
		//cin>>rad>>xs>>ys>>x>>y;;
		Circle* a=new Circle(rad,xs,ys,x,y);
		balls.push_back(a);
	    }
	    /*Circle* a = new Circle(1,0,0,0,0);
	    balls.push_back(a);
	    Circle* f = new Circle(1,50,0,-5,0);
	    balls.push_back(f);
	    Circle* c = new Circle(1,-50,0,5,0);
	    balls.push_back(c);
	    Circle* d = new Circle(1,0,50,0,-5);
	    balls.push_back(d);
	    Circle* e = new Circle(1,0,-50,0,5);
	    balls.push_back(e);*/
	    // cout<<balls[0]->xcord<<endl;
	    // cout<<balls[0]->ycord<<endl;
	    // cout<<balls[0]->xspeed<<" "<<balls[0]->yspeed<<endl; 
	    for (int i=0;i<balls.size();i++){
	    	pair<Circle*,bool> a=make_pair(balls[i],0);
	    	
	    	newballs.push_back(a);
	    }
	   	for(int i=0;i<balls.size();i++){
		
		int a=random()%(colvector.size());
		forcolor.push_back(a);
	}
	   //threads= new pthread_t[balls.size()];

	    for(int i=0;i<n;i++) 
	    {
	    	pthread_t* thr = new pthread_t;
	    	threads.push_back(thr);
	    }
		glClearColor(b->rcolour,b->gcolour,b->bcolour,1);
	    glutDisplayFunc(display);
	    GLUI_Master.set_glutReshapeFunc( resize );	
	  	glEnable(GL_DEPTH_TEST);
	    GLUI *glui = GLUI_Master.create_glui_subwindow( main_window, 
	              GLUI_SUBWINDOW_RIGHT );
	   	glui->set_main_gfx_window( main_window );
	   	new GLUI_Checkbox( glui, "Pause", &nabled,2,control_cb);   
	   	new GLUI_Button( glui, "add ball", add, control_cb );
	   	new GLUI_Button( glui, "Delete Ball", Delete, control_cb );
	  
	  //new GLUI_Button( glui, "Play", play, control_cb );
	  	new GLUI_Button( glui, "Quit", 0,(GLUI_Update_CB)exit );
	   	new GLUI_Button( glui, "Show speed", show, control_cb );
	  	GLUI_Spinner *x_spinner = 
	    new GLUI_Spinner( glui, "x-speed",GLUI_SPINNER_FLOAT, 
	                      &xspee,idx,control_cb);
	  	x_spinner->set_float_limits( 0.0, 50.0 );

	   	GLUI_Spinner *y_spinner = 
	    new GLUI_Spinner( glui, "y-speed:", GLUI_SPINNER_FLOAT,
	                      &yspee,idy,control_cb);
	  	y_spinner->set_float_limits( 0.0, 50.0 );

	  	xyz=new GLUI_EditText( glui, "ball's xspeed", &xspee, 2,control_cb );
	 	ysp=new GLUI_EditText( glui, "ball's yspeed", &yspee, 2,control_cb );
	 	new GLUI_Checkbox( glui, "Delete water", &water,2,control_cb);
	  	glui->sync_live();
	  	GLUI_Master.sync_live_all();
	    glEnable(GL_CULL_FACE);
	    glCullFace(GL_BACK);
	 
	    glDepthFunc(GL_LESS); 
	 
	    glEnable(GL_BLEND);
	    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	    glEnable(GL_LIGHT0);
	    glEnable(GL_NORMALIZE);
	    glEnable(GL_COLOR_MATERIAL);
	    glEnable(GL_LIGHTING); 
	 
	    glLightfv(GL_LIGHT2, GL_AMBIENT,  light_ambient);
	    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
	 
	    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
	    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
	    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
	    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	 
	    glutMainLoop(); 
	 
	    return EXIT_SUCCESS;
	}
}
#endif
