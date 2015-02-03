// Aniket add proper random function and collision effect
//Ronak edited
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <bits/stdc++.h> 
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <vector>
#include <GL/glu.h>
#include <GL/glui.h>
#include <pthread.h>
#include <random>
#include <mutex>

using namespace std;

#include "Circle1.h"
#define zoom_ID  250
//#include "Vect.h"
double maxspeed=100;
pthread_mutex_t imutex; 
float zoom=1.0;

vector<Circle*> balls;
Rectangle* b=new Rectangle();
double asp,r,g,bl;
pair<double,double>* centre;
bool* keystates = new bool[256];
int whatallkeys=0,i;
int check=0;
double rotate_z=0;
int main_window;
GLUI_Rotation *rot;
GLUI_Panel *panel;
vector<int> forcolor;
vector< queue<Message> > database;
#define pause 500
#define add   200
int nabled=0;
vector<pair<Circle*,bool> > newballs;
vector<Vect* > forpause;
vector<pair<pthread_t*,int> > threads;

int last=0; 			// no of balls controlled by the last thread
int no_perthr;			//no controlled by each thread,but last





vector<Vect*> colvector;
vector<Vect*> finalvector;
Vect* colorvect;

void changetoratio(){
	for(int i=0;i<colvector.size();i++){
		double sum=colvector[i]->x+colvector[i]->y+colvector[i]->z;
		colorvect=new Vect(colvector[i]->x/256.0,colvector[i]->y/256.0,colvector[i]->z/256.0);
		finalvector.push_back(colorvect);
	}

}


void addcolors(){
	

	colorvect=new Vect(26, 188, 156);
	colvector.push_back(colorvect);
	colorvect=new Vect(46, 204, 113);

	colvector.push_back(colorvect);
	colorvect=new Vect(52, 152, 219);
	colvector.push_back(colorvect);
	colorvect=new Vect(155, 89, 182);
	colvector.push_back(colorvect);
	colorvect=new Vect(52, 73, 94);
	colvector.push_back(colorvect);
	colorvect=new Vect(192, 57, 43);
	colvector.push_back(colorvect);
	colorvect=new Vect(22, 160, 133);
	colvector.push_back(colorvect);
	colorvect=new Vect(39, 174, 96);
	colvector.push_back(colorvect);
	colorvect=new Vect(142, 68, 173);
	colvector.push_back(colorvect);
	colorvect=new Vect(44, 62, 80);
	colvector.push_back(colorvect);
	colorvect=new Vect(230, 126, 34);
	colvector.push_back(colorvect);
	colorvect=new Vect(231, 76, 60);
	colvector.push_back(colorvect);
	colorvect=new Vect(236, 240, 241);
	colvector.push_back(colorvect);
	colorvect=new Vect(149, 165, 166);
	colvector.push_back(colorvect);
	colorvect=new Vect(243, 156, 18);
	colvector.push_back(colorvect);
	colorvect=new Vect(211, 84, 0);
	colvector.push_back(colorvect);
	colorvect=new Vect(189, 195, 199);
	colvector.push_back(colorvect);
	colorvect=new Vect(127, 140, 141);
	colvector.push_back(colorvect);
	changetoratio();
}









float Cube_rotate[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };


float ver[8][3] = 
{
    {-700.0,-700.0,700.0},
    {-700.0,700.0,700.0},
    {700.0,700.0,700.0},
    {700.0,-700.0,700.0},
    {-700.0,-700.0,-700.0},
    {-700.0,700.0,-700.0},
    {700.0,700.0,-700.0},
    {700.0,-700.0,-700.0},
};

GLfloat color[8][3] = 
{
    {0.0,0.0,0.0},
    {1.0,0.0,0.0},
    {1.0,1.0,0.0},
    {0.0,1.0,0.0},
    {0.0,0.0,1.0},
    {1.0,0.0,1.0},
    {1.0,1.0,1.0},
    {0.0,1.0,1.0},
};


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

int ch =1;

void colorcube()
{
    quad(0,3,2,1,255.0/255.0,160.0/255.0,122.0/255.0,1);
    quad(2,3,7,6,187.0/255.0,1,1,1);
    quad(0,4,7,3,0,0,0,0.5);
    quad(1,2,6,5,1,0,0,0.5);
    quad(4,5,6,7,0,1,1,0.5);
    quad(0,1,5,4,0,0.5,0.5,0.5);
}

double rotate_y = 0; 
double rotate_x = 0;
void specialKeys( int key, int x, int y ) 
{	cout<<"key"<<rotate_y<<" "<<rotate_x<<"  "<<rotate_z<<endl;
    if (key == GLUT_KEY_RIGHT){
        rotate_y += 2; ch=1;}
    else if (key == GLUT_KEY_LEFT){
        rotate_y += -2; ch=1;}
    else if (key == GLUT_KEY_UP){
        rotate_x += 2; ch=1;}
    else if (key == GLUT_KEY_DOWN){
        rotate_x += -2; ch=1;}
    else if (key == GLUT_KEY_PAGE_UP){
        rotate_z += 2; ch =1;}
    else if (key == GLUT_KEY_PAGE_DOWN)
    {
    rotate_z += -2; ch =1;
    }
	cout<<"key2"<<rotate_y<<" "<<rotate_x<<"  "<<rotate_z<<endl;
  } 

void keyPressed(unsigned char a,int x,int y){
	keystates[int(a)]=1;
	if(int(a) >=48 && int(a) <= 57){
		whatallkeys=10*whatallkeys+int(a)-48;
	}
}

void keyup(unsigned char a,int x,int y){
	keystates[int(a)]=0;
}

void keyOperations(void){
	if(keystates[int('a')]){
		i=whatallkeys;}
	if(keystates[int('x')]){
		cout<<i<<endl;
		balls[i]->speed->x=whatallkeys;
	}
	if(keystates[int('y')]){
		balls[i]->speed->y=whatallkeys;
	}
	if(keystates[int('z')]){
		balls[i]->speed->z=whatallkeys;
	}
	whatallkeys=0;
	
    	/*if (keystates[int('m')]){
        rotate_x += 0.002; ch=1;}
    	if (keystates[int('b')]){
        rotate_x -= 0.002; ch=1;}
	//cout<<ch<<" ch"<<endl;*/
	
}


 void control_cb(int control){

 	if (control==zoom_ID){
 		zoom=zoom+0.1;
 	}
  }


int addrandom(double radius)
{	int h=0;
	double w = glutGet(GLUT_WINDOW_WIDTH);
	double ht = glutGet(GLUT_WINDOW_HEIGHT);
	int max=pix*piy*piz;
	len = ortho_x/pix;
	width = ortho_y / piy;
	hei = ortho_z / piz;

	double min1 = min(len,width);
	min1 = min(min1,hei);
	raw[balls.size()]=(double)radius/(double)min1;
	radius= radius/(double)min1;
	int counti=0;
	int cre=0;
while(h==0)
{	cre = random()%max;
	double d =1000000000.0;
	//cout<<cre<<" cre"<<endl;
		int cond = cre%(pix*piy);
		if(cond==0) cond = pix*piy;
		int y_2 = cond/pix + 1;
		if(cond%pix==0)y_2 = cond/pix;
		int x_2 = cond%pix;  if(x_2==0) x_2 = pix;
		int z_2 = cre/(pix*piy) + 1; if(cre%(pix*piy)==0) z_2 = cre/(pix*piy) ;
		if( x_2 >= radius + 1 && x_2 + radius <= pix && y_2 >= radius + 1 && y_2 + radius <= piy && z_2 >= raius +1 && z_2 + radius <= piz )
		{ for(int i=0;i<balls.size();i++)
		 {		int x_1= int(double (balls[i]->position->x+700) /double (min1) + 1) ;
				int y_1 = int( (double)(balls[i]->position->y+700) / double(width) + 1);
				int z_1  = int( (double)(balls[i]->position->z + 700 )/double (hei) + 1);
				d = min(d,sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2)+(z_1-z_2)*(z_1-z_2))-raw[i]);
			
			
	    	}
		 if(d>=radius)
				{	pos_cl.push_back(cre);h++;}
		}
		//cout<<"chotu"<<endl;
		counti++;
		if(counti>10000)
			{	break;}
}
	if(h==1)
	{	int cond = cre%(pix*piy);
		if(cond==0) cond = pix*piy;
		int y_2 = cond/pix + 1;
		if(cond%pix==0)y_2 = cond/pix;
		int x_2 = cond%pix;  if(x_2==0) x_2 = pix;
		int z_2 = cre/(pix*piy) + 1; if(cre%(pix*piy)==0) z_2 = cre/(pix*piy) ;
		p.push_back((co_or(double(x_2-1)*len-700.0,double(y_2-1)*width-700.0,double(z_2-1)*hei-700.0)));
		}
	return h;
}




void badd(void){
	double w = glutGet(GLUT_WINDOW_WIDTH);
	double h = glutGet(GLUT_WINDOW_HEIGHT);
	int i=balls.size();
	Vect* spee = new Vect(0,0,0); Vect* pos = new Vect(0,0,0);
	double rad = 0.05,xs=0,ys=0,x=0,y=0;
	int chi= addrandom(rad);
	act[i]=rad;	
	spee->x=0;spee->y=0;spee->z=0;
	if(chi==1)
	{	 pos->x=p[i].x-700; pos->y=p[i].y-700;pos->z=p[i].z-700;
	}
	Circle* newball = new Circle(rad,pos,spee);
	balls.push_back(newball);
	int a=random()%(colvector.size());
	forcolor.push_back(a);
	reflect.push_back(0);
	if (threads[threads.size()-1].second < no_perthr){
		threads[threads.size()-1].second +=1;
	}
	else{
		pthread_t* thr = new pthread_t;
		pair<pthread_t*,int> a = make_pair(thr,1);
		threads.push_back(a);		
	}
	
}

void control1_cb(int control){
   // if (nabled==1){
    //		forpause.resize(0);
//    		if(ch==0){
// 	   		for(int i=0;i<balls.size();i++){
// 	   				Vect *a = new Vect(balls[i]->speed->x,balls[i]->speed->y,balls[i]->speed->z);
// 					forpause.push_back(a);
// 	   				balls[i]->speed->x=0;
// 	   				balls[i]->speed->y=0; 
// 	   				balls[i]->speed->z=0;
// 	   		}
// 	   		ch ++;
// 	   	}

//    		if (control==add){
//    			badd();
//    			control=0;
//    		}
// 	}

// 	else{ 		
//    		if( control!= add){
//    		for(int i=0;i<balls.size();i++){
//    				balls[i]->speed->x=forpause[i]->x;
//    				balls[i]->speed->y=forpause[i]->y;
//    				balls[i]->speed->z=forpause[i]->z;
//    			}
//    			ch = 0;	
//    			cou=0;
//    		}


// 	}
 }


double min(double a , double b)
{	return a>b ? a:b;}

class co_or
{	public:
	int x,y,z;
	co_or(int aa , int bb , int cc)
	{	x=aa;y=bb;z=cc;}
};
vector<double> real;
vector<co_or> p;
double len,width,hei;
double ortho_x=2*700 ;double ortho_y=2*700 ;double ortho_z =2*700 ;
int pix=700;int piy=700;int piz=700;
vector<double> raw;
vector<int> pos;
vector<int> reali;

void random(int n)
{	int max=pix*piy*piz;
	//cout<<max<<endl;
	int number=0;
	int counter=0;
//	cout<<1<<"kk"<<max<<endl;
	len = ortho_x/pix;
	width = ortho_y / piy;
	hei = ortho_z / piz;
	int min1 = min(len,width);
	min1 = min(min1,hei);
	cout<<min1<<endl;
	for(int i=0;i<reali.size();i++)
	{	raw.push_back( reali[i]/(double)min1 ); }

	while(number!=n)
	{	long long cre; cre = (rand()*rand()*rand())%max;
		cre = (cre + max)%max;
		double d = 100000000.0;
		int cons  = cre%(pix*piy);if(cons==0)cons=piy*pix;
		int y1 = cons/pix + 1 ;if(cons%pix==0)y1 = cons/pix; int x1 = cons%pix ; if(x1==0) x1 = pix;
		int z1 =  cre/(pix*piy) + 1;if(cre%(pix*piy)==0)z1 = cre/(pix*piy);
		if(x1>=raw[number-1]+1&&x1+raw[number-1]<=pix&&y1>=raw[number-1]+1&&y1+raw[number-1]<=piy&&z1>=raw[number-1]+1&&z1+raw[number-1]<=piz)
		{	for(int i=0;i<pos.size();i++)
			{	int create =  pos[i]%(pix*piy);
				if(create==0) create = pix*piy;
				int y2 = create/pix+1; int x2 = create%pix; if(x2==0) x2 = pix; int z2 = pos[i]/(pix*piy) +1 ;
				double left  = sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2) )- raw[i];
				d = min(d,left);
			}
			if(d>=raw[number-1])
			{	counter=0;
			pos.push_back(cre);number++;}
		}

		counter++;
		if(counter>100000)
		{	break;}
	}

	for(int i=0;i<pos.size();i++)
	{	int cre = pos[i];	
		int cons  = cre%(pix*piy);if(cons==0)cons=piy*pix;
		int y1 = cons/pix + 1 ; int x1 = cons%pix ; if(x1==0) x1 = pix;;
		int z1 =  cre/(pix*piy) + 1;
		p.push_back(co_or((x1-1)*len-700.0,(y1-1)*width-700.0,(z1-1)*hei-700.0));
	}
}



static void resize(int width, int height)
{
    const float ar = (float) width / (float) height; 
    glViewport(0, 0, width, height);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
	glOrtho(-w,w,-h,h,-10000,10000);     
	glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glutSwapBuffers();
} 
 
 
vector<Vect*> diffpoint;
vector<Vect*> actual;
void* update(void* arg)
{	
	long counter;
	pthread_mutex_lock(&imutex);
	counter = (long)arg;
	cout<<"pooooo"<<endl;
	if( counter < threads.size()-1){
		for(int i=counter*no_perthr;i < counter*no_perthr + no_perthr;i++){
			Message mes1;
			mes1.position = balls[i]->position ; mes1.speed = balls[i]->speed; mes1.radius = balls[i]->radius;
			cout<<"weeee"<<endl;
			while(database[i].empty()== false)
			{
					
					Message m = database[i].front();
					
					database[i].pop();
					if(balls[i]->Collision(m)==1)
					{	Vect* pointofcollision = balls[i]->pointcollision(m);	
						diffpoint.push_back(pointofcollision);			
					}
			}
			for(int j=0;j<database.size();j++)
			{
				if(j!=i) database[j].push(mes1);
				//cout<<"here hello  "<<
			}
		}

		for(int i=counter*no_perthr;i<counter*no_perthr + no_perthr;i++){
			balls[i]->Reflection(*b);	
		}
		for(int i=counter*no_perthr;i<counter*no_perthr + no_perthr;i++){
			balls[i]->Move();
		}

	}
	else{
		cout<<"reeeee"<<endl;
		for(int i=counter*no_perthr;i<balls.size();i++){
			Message mes1;
			mes1.position = balls[i]->position ; mes1.speed = balls[i]->speed; mes1.radius = balls[i]->radius;

			while(database[i].empty()== false)
			{
					
					Message m = database[i].front();
					
					database[i].pop();
					if(balls[i]->Collision(m)==1)
					{	Vect* pointofcollision = balls[i]->pointcollision(m);	
						diffpoint.push_back(pointofcollision);			
					}
			}
			for(int j=0;j<database.size();j++)
			{
				if(j!=i) database[j].push(mes1);
			}
		}
		for(int i=counter*no_perthr;i<balls.size();i++){
			balls[i]->Reflection(*b);
		}
		for(int i=counter*no_perthr;i<balls.size();i++){
			balls[i]->Move();
		}
	}
	pthread_mutex_unlock(&imutex);
}



void display(void)
{	//cout<<1<<endl;

	    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	 glViewport(0, 0, w, h);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    //glViewport(0,0,w,h);
    //gluPerspective( 5.0f, w / h, -1000.0f, 1.0f );
	glOrtho(-w,w,-h,h,-10000,10000);     
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glRotatef( rotate_x,1,0,0);
    glRotatef( rotate_y,0,1,0);
	glRotatef( rotate_z,0,0,1);
	glScalef(zoom,zoom,zoom);


	const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
	const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
	const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat high_shininess[] = { 100.0f }; 


	const GLfloat light_ambient[]  = { 10.0f, 10.0f, 10.0f, 1.0f };
	const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_position[] = { 700.0f, 700.0f, 700.0f, 0.0f }; 

	const GLfloat light_ambient1[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
	const GLfloat light_diffuse1[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_specular1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_position1[] = { -700.0f, -700.0f, -700.0f, 0.0f }; 



    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    //glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); 

	glMultMatrixf( Cube_rotate );
	keyOperations();

	double width = glutGet(GLUT_WINDOW_WIDTH); //Width in pixels of the current window.
    double height = glutGet(GLUT_WINDOW_HEIGHT);
	double ar = width/height;
	//b->dimension->x = 2*ar;
	//b->dimension->y = 2;

	// for(int i=0;i<balls.size();i++)
	// {
	// 	cout<<balls[i]->position->x <<" x" <<balls[i]->position->y <<" y"<<balls[i]->position->z <<" z"<<endl;  
	// }
 	
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for(int i=0;i<balls.size();i++)
	{	/*if (check<balls.size());
		{
			r= random()%100/100.0; g=random()%100/100.0; bl=random()%100/100.0;
			cout<<check<<endl;
			check++;
		}*/
		// if (i%2==0)
		// glColor3d(238.0/255.0,213.0/255.0, 210.0/255.0);
		// else glColor3d(1,0,0);
		glColor3d(finalvector[forcolor[i]]->x,finalvector[forcolor[i]]->y,finalvector[forcolor[i]]->z);
	//	glColor3d(finalvector[4]->x,finalvector[4]->y,finalvector[4]->z);	
		glPushMatrix();
		glTranslated(balls[i]->position->x,balls[i]->position->y,balls[i]->position->z);
		glutSolidSphere(balls[i]->radius,50,50);
		glPopMatrix();
	}	
	
	int rc;	
	for(int i=0;i<threads.size();i++)
	{
		rc = pthread_create((threads.at(i)).first,NULL,update,(void*)i);
		if(rc)
		{
			cout<<"Unable to create thread"<<endl;
			exit(1);
		}
	}
	for(int i=0;i<threads.size();i++){
		cout<<i<<"joining threads"<<endl;
		 pthread_join(*(threads.at(i)).first,NULL);
	}
	// pthread_t threads[balls.size()];
	// pthread_mutex_init(&imutex,NULL);
	// int rc;		
	// for(int i=0;i<balls.size();i++)
	// {
		
	// 	rc = pthread_create(&threads[i],NULL,update,(void*)i);
	// 	if(rc)
	// 	{
	// 		cout<<"Unable to create thread"<<endl;
	// 		exit(1);
	// 	}
	// }
	// for(int i=0;i<balls.size();i++) pthread_join(threads[i],NULL);

	//cout<<"end"<<endl;
	int cat=0;
while(cat<=12)
	{		for(int  j=0;j< diffpoint.size();j++)
			{	glColor3d(0,0,0);
				glPushMatrix();
				glTranslated(diffpoint[j]->x,diffpoint[j]->y,diffpoint[j]->z);
				glutSolidSphere(50,50,50);
		//	glclear();
				glPopMatrix();
			
		//	glPopMatrix();
//			
			}
			cout<<diffpoint.size()<<" yo"<<endl;
			cat++;
			glutPostRedisplay();
		//	goto g1;
	}
	diffpoint.resize(0);//
	
	//cout<<ch<<endl;
    colorcube();
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
} 

/* Program entry point */
 
int main(int argc, char *argv[])
{
    if(argc == 2)
    {
	    int n;
	    
	    n= atoi(argv[1]);
	    int m=n;
		no_perthr=n/m;					
		last=n%m;
	    cout<<"Enter no of balls"<<endl;
	    //threads = new pthread_t[n];
	    glutInit(&argc, argv);
	    glutInitWindowSize(1853,1027);
	    main_window=glutCreateWindow("Yo Team Creation");
	    double width = glutGet(GLUT_WINDOW_WIDTH); //Width in pixels of the current window.
	    double height = glutGet(GLUT_WINDOW_HEIGHT);
	    asp = width/height;
	    Vect* w= new Vect(0,0,0);
	    Vect* col = new Vect(1,1,1);
	    Vect* dim = new Vect(1400,1400,1400);
	    b->Rectang(dim,col,w);
	    
	    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
	    
	     for(int i=0;i<n;i++)
			{	reali.push_back(100);}
	 
	
	    centre= new pair<double,double>[n];
	  	random(n);
	    for(int i=0;i<n;i++)
	    {
		
		
		double x=p[i].x/*-5+2*i*/,y=p[i].y/*-5+2*i*/,z=p[i].z,rad=100/*random()%2/10.0+0.1*/,xs=/*-30*//*rand()%30 - 28*/6000.0,ys=/*-30*//*rand()%30 - 28*/6000.0,zs =0;;
		Vect* a1= new Vect(x,y,z);
		Vect* b1= new Vect(xs,ys,zs);

		Circle* a=new Circle(rad,a1,b1);
		cout<<x<<" "<<y<<endl;
		balls.push_back(a);
		queue<Message> q;
		database.push_back(q);

	    }
	    addcolors();
	    for(int i=0;i<balls.size();i++){
			int a=random()%(colvector.size());
			cout<<a<<endl;
			forcolor.push_back(a);
		}

	    for(int i=0;i<m;i++) 
	    {
	    	if(i<m-1){
	    		pthread_t* thr = new pthread_t;
	    		pair<pthread_t*,int> a = make_pair(thr,no_perthr);
	    		threads.push_back(a);
	    	}
	    	else{
	    		pthread_t* thr=new pthread_t;
	    		pair<pthread_t*,int> a = make_pair(thr,last);
	    		threads.push_back(a);
	    	}
	    
	    }

	   
	    GLUI_Master.set_glutReshapeFunc(resize);
	    glutKeyboardFunc(keyPressed);
	    glutSpecialFunc(specialKeys);
	    glutKeyboardUpFunc(keyup);

	    glutDisplayFunc(display);
	    GLUI *glui = GLUI_Master.create_glui_subwindow( main_window, 
              GLUI_SUBWINDOW_RIGHT );
  		 glui->set_main_gfx_window( main_window );
  	 	GLUI_Rotation *rot= new GLUI_Rotation(glui, "Objects", Cube_rotate );
  		rot->set_spin( 1.0 );

  		GLUI_Scrollbar *sb;
  		sb = new GLUI_Scrollbar( glui, "zoom",GLUI_SCROLL_VERTICAL,
                           &zoom,zoom_ID,control_cb);
  		sb->set_float_limits( 1.0, 3.0 );
		new GLUI_Checkbox( glui, "Pause", &nabled,2,control1_cb);
  		new GLUI_Button( glui, "add ball", add, control1_cb );

		glui->sync_live();
		GLUI_Master.sync_live_all();	
	    glEnable(GL_DEPTH_TEST);
	    glClearColor(b->colour->x,b->colour->y,b->colour->z,1);
	    //3D effects start here
	    glEnable(GL_BLEND);
	    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	    glutMainLoop(); 
	 
	    return EXIT_SUCCESS;
	}
	else if(argc==3){
		int m;
		m=atoi(argv[2]);
		int n = atoi(argv[1]);
		no_perthr=n/m;					
		last=n%m;
	    //threads = new pthread_t[n];
	    glutInit(&argc, argv);
	    glutInitWindowSize(1853,1027);
	    main_window=glutCreateWindow("Yo Team Creation");
	    double width = glutGet(GLUT_WINDOW_WIDTH); //Width in pixels of the current window.
	    double height = glutGet(GLUT_WINDOW_HEIGHT);
	    asp = width/height;
	    Vect* w= new Vect(0,0,0);
	    Vect* col = new Vect(1,1,1);
	    Vect* dim = new Vect(1400,1400,1400);
	    b->Rectang(dim,col,w);
	    
	    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
	    
	     for(int i=0;i<n;i++)
			{	reali.push_back(100);}
	 
	
	    centre= new pair<double,double>[n];
	  	random(n);
	    for(int i=0;i<n;i++)
	    {
		
		
		double x=p[i].x/*-5+2*i*/,y=p[i].y/*-5+2*i*/,z=p[i].z,rad=100/*random()%2/10.0+0.1*/,xs=/*-30*//*rand()%30 - 28*/6000.0,ys=/*-30*//*rand()%30 - 28*/6000.0,zs =0;;
		Vect* a1= new Vect(x,y,z);
		Vect* b1= new Vect(xs,ys,zs);

		Circle* a=new Circle(rad,a1,b1);
		cout<<x<<" "<<y<<endl;
		balls.push_back(a);
		queue<Message> q;
		database.push_back(q);

	    }
	    addcolors();
	    for(int i=0;i<balls.size();i++){
			int a=random()%(colvector.size());
			cout<<a<<endl;
			forcolor.push_back(a);
		}

	    for(int i=0;i<m;i++) 
	    {
	    	if(i<m-1){
	    		pthread_t* thr = new pthread_t;
	    		pair<pthread_t*,int> a = make_pair(thr,no_perthr);
	    		threads.push_back(a);
	    	}
	    	else{
	    		pthread_t* thr=new pthread_t;
	    		pair<pthread_t*,int> a = make_pair(thr,last);
	    		threads.push_back(a);
	    	}
	    
	    }

	   
	    GLUI_Master.set_glutReshapeFunc(resize);
	    glutKeyboardFunc(keyPressed);
	    glutSpecialFunc(specialKeys);
	    glutKeyboardUpFunc(keyup);

	    glutDisplayFunc(display);
	    GLUI *glui = GLUI_Master.create_glui_subwindow( main_window, 
              GLUI_SUBWINDOW_RIGHT );
  		 glui->set_main_gfx_window( main_window );
  	 	GLUI_Rotation *rot= new GLUI_Rotation(glui, "Objects", Cube_rotate );
  		rot->set_spin( 1.0 );

  		GLUI_Scrollbar *sb;
  		sb = new GLUI_Scrollbar( glui, "zoom",GLUI_SCROLL_VERTICAL,
                           &zoom,zoom_ID,control_cb);
  		sb->set_float_limits( 1.0, 3.0 );
		new GLUI_Checkbox( glui, "Pause", &nabled,2,control1_cb);
  		new GLUI_Button( glui, "add ball", add, control1_cb );

		glui->sync_live();
		GLUI_Master.sync_live_all();	
	    glEnable(GL_DEPTH_TEST);
	    glClearColor(b->colour->x,b->colour->y,b->colour->z,1);
	    //3D effects start here
	    glEnable(GL_BLEND);
	    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	    glutMainLoop(); 
	 
	    return EXIT_SUCCESS;

	}
}
