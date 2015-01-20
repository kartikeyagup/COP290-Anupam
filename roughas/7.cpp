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

using namespace std;

#include "Circle1.h"
//#include "Vect.h"
double maxspeed=100;
pthread_mutex_t imutex; 


vector<Circle*> balls;
Rectangle* b=new Rectangle();
double asp,r,g,bl;
pthread_t* threads;
pair<double,double>* centre;
bool* keystates = new bool[256];
int whatallkeys=0,i;
int check=0;
double rotate_z=0;


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
    //quad(0,3,2,1,1,1,1,1);
    //quad(2,3,7,6,0,1,0,1);
    quad(0,4,7,3,0,0,0,0.5);
    //quad(1,2,6,5,1,0,0,0.5);
    quad(4,5,6,7,44, 62, 80,0.5);
    quad(0,1,5,4,,0.5);
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







void randm(int n,double r, double len, double weight)
{		
	int k1= int((len/(r*3)));
	int k2 = int(((weight)/(r*3)));		
	int max_range=k1*k2;
	vector<int> pos;
	int ch=0;
	int num=0;
	int j=0;
	cout<<k1<<" "<<k2<<endl;
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
    const float ar = (float) width / (float) height; 
   
    glViewport(0, 0, width, height);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
    //glViewport(0,0,w,h);
    //gluPerspective( 5.0f, w / h, -1000.0f, 1.0f );
	glOrtho(-w,w,-h,h,-10000,10000);     
	/*gluLookAt
        ( 
        -700,0,-700, 
        0,0,0,
        0, 0,1 
        );
*/
   //glFrustum(-w,w,-h,h,-4000,4000);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    //glLoadIdentity();
   

    


    glutSwapBuffers();
} 
 

void* update(void* arg)
{	long counter;
	counter = (long)arg;
	pthread_mutex_lock(&imutex);
	for(int j= counter+1;j<balls.size();j++)
	{

			balls[counter]->Collision(*balls[j]);
	}
	balls[counter]->Reflection(*b);
	balls[counter]->Move(/*sqrt(pow(balls[counter]->xspeed,2)+pow(balls[counter]->yspeed,2))*/);
	pthread_mutex_unlock(&imutex);
}


void display(void)
{

	    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
	 glViewport(0, 0, w, h);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    //glViewport(0,0,w,h);
    //gluPerspective( 5.0f, w / h, -1000.0f, 1.0f );
	glOrtho(-w,w,-h,h,-10000,10000);     
	/*gluLookAt
        ( 
        -700,0,-700, 
        0,0,0,
        0, 0,1 
        );
*/
   //glFrustum(-w,w,-h,h,-4000,4000);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glRotatef( rotate_x,1,0,0);
    glRotatef( rotate_y,0,1,0);
	glRotatef( rotate_z,0,0,1);
	keyOperations();
	double width = glutGet(GLUT_WINDOW_WIDTH); //Width in pixels of the current window.
    	double height = glutGet(GLUT_WINDOW_HEIGHT);
	double ar = width/height;
	//b->dimension->x = 2*ar;
	//b->dimension->y = 2;
	cout<<balls.size()<<endl;
	for(int i=0;i<balls.size();i++)
	{
		cout<<balls[i]->position->x <<" x" <<balls[i]->position->y <<" y"<<balls[i]->position->z <<" z"<<endl;  
	}
 	pthread_t threads[balls.size()];
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for(int i=0;i<balls.size();i++)
	{	/*if (check<balls.size());
		{
			r= random()%100/100.0; g=random()%100/100.0; bl=random()%100/100.0;
			cout<<check<<endl;
			check++;
		}*/
		if (i%2==0)
		glColor3d(1,1,0);
		else glColor3d(1,0,0);
		glPushMatrix();
			glTranslated(balls[i]->position->x,balls[i]->position->y,balls[i]->position->z);
			glutSolidSphere(balls[i]->radius,50,50);
		glPopMatrix();
	}	
	pthread_mutex_init(&imutex,NULL);
	int rc;		
	for(int i=0;i<balls.size();i++)
	{
		
		rc = pthread_create(&threads[i],NULL,update,(void*)i);
		if(rc)
		{
			cout<<"Unable to create thread"<<endl;
			exit(1);
		}
	}
	for(int i=0;i<balls.size();i++) pthread_join(threads[i],NULL);
	
	//cout<<ch<<endl;
    colorcube();
    glutSwapBuffers();
    glutPostRedisplay();
} 

 
const GLfloat light_ambient[]  = { 10.0f, 10.0f, 10.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 700.0f, 700.0f, 700.0f, 0.0f }; 
 

const GLfloat light_ambient1[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse1[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position1[] = { -700.0f, -700.0f, -700.0f, 0.0f }; 


const GLfloat light_ambient2[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse2[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position2[] = { 700.0f, 700.0f, -700.0f, 0.0f }; 

const GLfloat light_ambient3[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse3[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular3[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position3[] = { 700.0f, -700.0f, -700.0f, 0.0f }; 

const GLfloat light_ambient4[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse4[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular4[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position4[] = { 700.0f, -700.0f, 700.0f, 0.0f }; 

const GLfloat light_ambient5[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse5[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular5[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position5[] = { -700.0f, 700.0f, 700.0f, 0.0f }; 

// const GLfloat light_ambient6[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
// const GLfloat light_diffuse6[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_specular6[] = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_position6[] = { 700.0f, 700.0f, 700.0f, 0.0f }; 
 

// const GLfloat light_ambient7[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
// const GLfloat light_diffuse7[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_specular7[] = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_position7[] = { -700.0f, -700.0f, -700.0f, 0.0f }; 


// const GLfloat light_ambient2[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
// const GLfloat light_diffuse2[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_specular2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_position2[] = { 700.0f, 700.0f, -700.0f, 0.0f }; 

// const GLfloat light_ambient3[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
// const GLfloat light_diffuse3[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_specular3[] = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_position3[] = { 700.0f, -700.0f, -700.0f, 0.0f }; 

// const GLfloat light_ambient4[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
// const GLfloat light_diffuse4[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_specular4[] = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_position4[] = { 700.0f, -700.0f, 700.0f, 0.0f }; 

// const GLfloat light_ambient5[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
// const GLfloat light_diffuse5[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_specular5[] = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_position5[] = { -700.0f, 700.0f, 700.0f, 0.0f }; 


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
	    threads = new pthread_t[n];
	    glutInit(&argc, argv);
	    //double l=1853,w=1027,x=0,y=0,rcolour=1,gcolor=0,bcolor=0;
	    cout<<"Enter rectangle parameters"<<endl;
	    glutInitWindowSize(1853,1027);
	    glutCreateWindow("Yo Team Creation");
	    double width = glutGet(GLUT_WINDOW_WIDTH); //Width in pixels of the current window.
	    double height = glutGet(GLUT_WINDOW_HEIGHT);
	    asp = width/height;
	    Vect* w= new Vect(0,0,0);
	    Vect* col = new Vect(1,1,1);
	    Vect* dim = new Vect(1400,1400,1400);
	    b->Rectang(dim,col,w);
	    //glutInitWindowPosition(b->position->x,b->position->y);
	    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
	    
	     
	 
	
	    centre= new pair<double,double>[n];
		cout<<"1"<<endl;
	   randm(n,100,1400,1400);
	    cout<<"a"<<endl;
	    for(int i=0;i<n;i++)
	    {
		//srand(100);
		
		cout<<r<<" r "<<g<<" g "<<bl<<" bl "<<endl;
		double x=centre[i].first-700/*-5+2*i*/,y=centre[i].second-700/*-5+2*i*/,rad=100/*random()%2/10.0+0.1*/,xs=/*-30*//*rand()%30 - 28*/6000.0,ys=/*-30*//*rand()%30 - 28*/6000.0,zs =0;;
		Vect* a1= new Vect(x,y,100*i);
		Vect* b1= new Vect(xs,ys,zs);
		cout<<"Enter circle parameters"<<endl;
		//cin>>rad>>xs>>ys>>x>>y;;
		Circle* a=new Circle(rad,a1,b1);
		cout<<x<<" "<<y<<endl;
		balls.push_back(a);

	    }
	   // r= rand()%100/100.0; g = rand()%100/100.0; bl= rand()%100/100.0;
	    glutReshapeFunc(resize);
	    glutKeyboardFunc(keyPressed);
	    glutSpecialFunc(specialKeys);
	    glutKeyboardUpFunc(keyup);
	    
	    //cout<<"abcd"<<endl;
	    glutDisplayFunc(display);
	   // glutIdleFunc(display);	
	    glEnable(GL_DEPTH_TEST);
	    glClearColor(b->colour->x,b->colour->y,b->colour->z,1);
	    //3D effects start here
	    /*glEnable(GL_BLEND);
	    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);*/
	    //glEnable(GL_CULL_FACE);
	    //glCullFace(GL_BACK);
	 
	    
	    //glDepthFunc(GL_LESS); 
	 
	    glEnable(GL_LIGHT0);
	    glEnable(GL_NORMALIZE);
	    glEnable(GL_COLOR_MATERIAL);
	    glEnable(GL_LIGHTING); 
	 	// for (int i=0;i<12;i++){
	 	// 	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient[i]);
	  //  		glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse[i]);
	  //   	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular[i]);
	  //   	glLightfv(GL_LIGHT0, GL_POSITION, light_position[i]); 
	 	// }
	    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 

	    glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient1);
	    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse1);
	    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
	    glLightfv(GL_LIGHT1, GL_POSITION, light_position1); 

	     glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient2);
	    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse2);
	    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular2);
	    glLightfv(GL_LIGHT1, GL_POSITION, light_position2); 

	     glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient3);
	    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse3);
	    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular3);
	    glLightfv(GL_LIGHT1, GL_POSITION, light_position3); 

	     glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient4);
	    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse4);
	    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular4);
	    glLightfv(GL_LIGHT1, GL_POSITION, light_position4); 

	     glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient5);
	    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse5);
	    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular5);
	    glLightfv(GL_LIGHT1, GL_POSITION, light_position5); 
	 

	 	// glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	  //   glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	  //   glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	  //   glLightfv(GL_LIGHT0, GL_POSITION, light_position); 

	  //   glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient1);
	  //   glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse1);
	  //   glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
	  //   glLightfv(GL_LIGHT1, GL_POSITION, light_position1); 

	  //    glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient2);
	  //   glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse2);
	  //   glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular2);
	  //   glLightfv(GL_LIGHT1, GL_POSITION, light_position2); 

	  //    glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient3);
	  //   glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse3);
	  //   glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular3);
	  //   glLightfv(GL_LIGHT1, GL_POSITION, light_position3); 

	  //    glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient4);
	  //   glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse4);
	  //   glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular4);
	  //   glLightfv(GL_LIGHT1, GL_POSITION, light_position4); 

	    //  glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient5);
	    // glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse5);
	    // glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular5);
	    // glLightfv(GL_LIGHT1, GL_POSITION, light_position5); 
	    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
	    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
	    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
	    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	    glutMainLoop(); 
	 
	    return EXIT_SUCCESS;
	}
}
#endif