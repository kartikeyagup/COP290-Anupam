#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include "Graphicsrendering.h"
#include <unistd.h>//create faces from triangle
#include "Graphicsrendering.h"
#include "Creatingobjects.h"
#include "Tank.h"
// #include "texturemapping.h"


extern std::unordered_map<std::string,Colour> tankcolour;

void createface(Face newface){
	glBegin(GL_POLYGON);		 // Drawing Using Triangles
	// glColor4f(newface.te,transp);
	Vertex newvertex1,newvertex2,newvertex3; 
	newvertex1.x = newface.vertex1.x;
	newvertex1.y = newface.vertex1.y;
	newvertex1.z = newface.vertex1.z;
	// std::cout<<newvertex1.z<<"\n";
	// exit(0);

	newvertex2.x = newface.vertex2.x;
	newvertex2.y = newface.vertex2.y;
	newvertex2.z = newface.vertex2.z;


	newvertex3.x = newface.vertex3.x;
	newvertex3.y = newface.vertex3.y;
	newvertex3.z = newface.vertex3.z;
	 //glTexCoord2f(0.0f, 0.0f);	// Bottom Left Of The Texture and Quad
    glVertex3f( newvertex1.x, newvertex1.y, newvertex1.z);              // Top
	 //glTexCoord2f(1.0f, 0.0f); 	// Bottom Right Of The Texture and Quad
    glVertex3f( newvertex2.x, newvertex2.y, newvertex2.z);              // Bottom Left
    //glTexCoord2f(1.0f, 1.0f); 	// Top Right Of The Texture and Quad
    glVertex3f( newvertex3.x, newvertex3.y, newvertex3.z);              // Bottom Right
	glEnd();                            // Finished Drawing The Triangle	
}



//create object from faces

//create bullet
// void createbullet(std::vector<Face> fac1, Bullet bullet){
// 	glPushMatrix();
// 	glColor3f(0,0,1);
// 	translatebullet(bullet.getPosition().x,bullet.getPosition().y);
// 	for(int i=0;i<fac1.size();i++){
// 		createface(fac1[i]);
// 	}
// 	glPopMatrix();
// }

// //create missile
// void createmissile(std::vector<Face> fac1,Missile attr_missile){
// 	glPushMatrix();
// 	glColor3f(0,0,1);
// 	translatemissile(attr_missile.getPosition().x,attr_missile.getPosition().y);
// 	for(int i=0;i<fac1.size();i++){
// 		createface(fac1[i]);
// 	}
// 	glPopMatrix();

// }

// void createboard(std::vector<>)

//create tank

void createtank(std::vector<Face> fac1,Tank attr_tank){
	glPushMatrix();
	Rotatetank();
	Translatetank(attr_tank.getCentre().getX(),attr_tank.getCentre().getY());
	// Vector dim;
	// dim.setX();
	// dim.setY();
	// dim.setZ();
	// attr_tank.setDimensions(dim);
	// Translatetank(attr_tank.getCentre().getX(),attr_tank.getCentre().getY());

	for(int i=0;i<fac1.size();i++){
        Colour a= tankcolour[fac1[i].colour];
		glColor3f(a.x,a.y,a.z);
		createface(fac1[i]);
	}
	glPopMatrix();
}

//create wall
// void createwall(std::vector<Face> fac1){
// 	glPushMatrix();
// 	glColor3f(0,0,1);
// 	for(int i=0;i<fac1.size();i++){
// 		createface(fac1[i]);
// 	}
// 	glPopMatrix();
// }

// //create eagle
// void createeagle(std::vector<Face> fac1){
// 	glPushMatrix();
// 	glColor3f(0,0,1);
// 	for(int i=0;i<fac1.size();i++){
// 		createface(fac1[i]);
// 	}
// 	glPopMatrix();
// }

float ver[8][3] = 														//sets the coordinates of the vertex of the box
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

void quad(int a,int b,int c,int d,double r,double g,double bl,double transp)      //function to build the quadrilateral
{
    glBegin(GL_QUADS);
    glColor4f(r,g,bl,transp);    
    glVertex3fv(ver[a]);
    glVertex3fv(ver[b]);
    glVertex3fv(ver[c]);
    glVertex3fv(ver[d]);
    glEnd();
}

// void createboard(std::vector<std::pair<std::vector<int>,std::vector<double> > > config)										
// {
// 	for(int i=0;i<config.size();i++){
// 		quad((config[i].first)[0],(config[i].first)[1],(config[i].first)[2],(config.first)[3],(config[i].second)[0],(config[i].second)[1],(config[i].second)[2])
// 	}
//     // quad(0,3,2,1,255.0/255.0,160.0/255.0,122.0/255.0,1);
//     // quad(2,3,7,6,187.0/255.0,1,1,1);
//     // quad(0,4,7,3,0,0,0,0.5);
//     // quad(1,2,6,5,1,0,0,0.5);
//     // quad(4,5,6,7,0,1,1,0.5);
//     // quad(0,1,5,4,0,0.5,0.5,0.5);
// }

// std::vector<std::pair<std::vector<int>,std::std::vector<double> > > getboardproperties(){
// 	std::vector<int> postion;
// 	std::vector<double> colour;
// 	std::vector<std::pair<std::vector<int>,std::vector<double> > > returnfinal;
// 	std::pair<std::vector<int>,std::vector<double> > pairfinal;
// 	position.push_back(0);
// 	position.push_back(3);
// 	position.push_back(2);
// 	position.push_back(1);

	

// }