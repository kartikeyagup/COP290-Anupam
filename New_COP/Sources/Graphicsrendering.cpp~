#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include "Graphicsrendering.h"
#include <unistd.h>//create faces from triangle
#include "Graphicsrendering.h"
#include "Creatingobjects.h"
#include "Tank.h"



//storing vertex and faces in two vectors
std::vector<Face> bullet;
std::vector<Face> missile;
std::vector<Face> wall;
std::vector<Face> tank;
std::vector<Face> eagle;
std::unordered_map<std::string,Colour> tankcolour;
std::string keypressed;             //which key is pressed by the user to move the tank
Tank mytank;
double rotate_x = 90;
double rotate_y = 0;
double rotate_z = 0;
// double translate_x =0;
// double translate_y = 0;
// double translate_z =0;
// Board board;
/* ascii code for the escape key */
#define ESCAPE 27

/* The number of our GLUT window */
int window; 

/* floats for x rotation, y rotation, z rotation */
float xrot, yrot, zrot;

/* storage for one texture  */
unsigned int texture[1];

/* Image type - contains height, width, and data */


// quick and dirty bitmap loader...for 24 bit bitmaps with 1 plane only.  
// See http://www.dcs.ed.ac.uk/~mxr/gfx/2d/BMP.txt for more info.
int ImageLoad(char *filename, Image *image) {
    FILE *file;
    unsigned long size;                 // size of the image in bytes.
    unsigned long i;                    // standard counter.
    unsigned short int planes;          // number of planes in image (must be 1) 
    unsigned short int bpp;             // number of bits per pixel (must be 24)
    char temp;                          // temporary color storage for bgr-rgb conversion.

    // make sure the file is there.
    if ((file = fopen(filename, "rb"))==NULL)
    {
    printf("File Not Found : %s\n",filename);
    return 0;
    }
    
    // seek through the bmp header, up to the width/height:
    fseek(file, 18, SEEK_CUR);

    // read the width
    if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
    printf("Error reading width from %s.\n", filename);
    return 0;
    }
    printf("Width of %s: %lu\n", filename, image->sizeX);
    
    // read the height 
    if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
    printf("Error reading height from %s.\n", filename);
    return 0;
    }
    printf("Height of %s: %lu\n", filename, image->sizeY);
    
    // calculate the size (assuming 24 bits or 3 bytes per pixel).
    size = image->sizeX * image->sizeY * 3;

    // read the planes
    if ((fread(&planes, 2, 1, file)) != 1) {
    printf("Error reading planes from %s.\n", filename);
    return 0;
    }
    if (planes != 1) {
    printf("Planes from %s is not 1: %u\n", filename, planes);
    return 0;
    }

    // read the bpp
    if ((i = fread(&bpp, 2, 1, file)) != 1) {
    printf("Error reading bpp from %s.\n", filename);
    return 0;
    }
    if (bpp != 24) {
    printf("Bpp from %s is not 24: %u\n", filename, bpp);
    return 0;
    }
    
    // seek past the rest of the bitmap header.
    fseek(file, 24, SEEK_CUR);

    // read the data. 
    image->data = (char *) malloc(size);
    if (image->data == NULL) {
    printf("Error allocating memory for color-corrected image data");
    return 0;   
    }

    if ((i = fread(image->data, size, 1, file)) != 1) {
    printf("Error reading image data from %s.\n", filename);
    return 0;
    }

    for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
    temp = image->data[i];
    image->data[i] = image->data[i+2];
    image->data[i+2] = temp;
    }
    
    // we're done.
    return 1;
}
    
// Load Bitmaps And Convert To Textures
void LoadGLTextures() { 
    // Load Texture
    Image *image1;
    
    // allocate space for texture
    image1 = (Image *) malloc(sizeof(Image));
    if (image1 == NULL) {
    printf("Error allocating space for image");
    exit(0);
    }

    if (!ImageLoad("/home/anupam/COP290-Anupam/New_COP/images/texturetank.bmp", image1)) {
    exit(1);
    }        

    // Create Texture   
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);   // 2d texture (x and y size)

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture

    // 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image, 
    // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
};

GLdouble ox=0.0,oy=0.0,oz=0.0;
void mouseClicks(int button,int state,int x,int y) {
  GLint viewport[4];
  GLdouble modelview[16],projection[16];
  GLfloat wx=x,wy,wz;

  if(state!=GLUT_DOWN)
    return;
  if(button==GLUT_RIGHT_BUTTON)
    exit(0);
  glGetIntegerv(GL_VIEWPORT,viewport);
  y=viewport[3]-y;
  wy=y;
  glGetDoublev(GL_MODELVIEW_MATRIX,modelview);
  glGetDoublev(GL_PROJECTION_MATRIX,projection);
  glReadPixels(x,y,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,&wz);
  gluUnProject(wx,wy,wz,modelview,projection,viewport,&ox,&oy,&oz);
  std::cout<<ox<<"x\n";
  std::cout<<oy<<"y\n";
  std::cout<<oz<<"z\n";
  glutPostRedisplay();
}



bool* keySpecialstates = new bool[256];
bool* keyStates = new bool [256];
void keySpecial(int key, int x, int y){
    keySpecialstates[key] = true;
}

void keySpecialUp(int key,int x,int y){
    keySpecialstates[key] = false;
}

//file reading
std::vector<Face> fileread(std::string path){
	std::vector<Face> read;
	std::vector<Vertex> vertexread;
	std::vector<std::string> colourread;
	FILE *file = fopen(path.c_str(), "r");
	
    std::cout << "Starting\n";
	if( file == NULL ){
    	printf("Impossible to open the file !\n");
    	return read;
	}
	while( 1 ){
 		std::cout << "In while\n";
    	char lineHeader[128];
    	// read the first word of the line
    	int res = fscanf(file, "%s", &lineHeader);

    	if (res == EOF)
    	    break; // EOF = End Of File. Quit the loop.
    	else{
    		std::cout << "In else\n";
    		while( 1 ){
    			std::cout << "In while again\n";
 				char lineHeader[128];
    			// read the first word of the line
    			int res = fscanf(file, "%s", &lineHeader);
    			if (res == EOF){
    				std::cout << "EOF found\n";
    			    break; // EOF = End Of File. Quit the loop.
    			}
    			else{
    				if ( strcmp( lineHeader, "v" ) == 0 ){
    					std::cout << "vertex case\n";
   						Vertex vertex;
    					fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
    					vertexread.push_back(vertex);
    				}
    				else if ( strcmp( lineHeader, "vt" ) == 0 ){
    					// Texture texture;
    					// fscanf(file, "%f %f\n", &texture.x, &texture.y );
    					// textureread.push_back(texture);
    				}
    				else if ( strcmp( lineHeader, "f" ) == 0 ){
    					Face face;
    					std::cout << "face case\n";
    					 int v1,v2,v3 ,x,y,z,a,b,c;
    					int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &v1,&x,&a,&v2,&y,&b,&v3,&z,&c );
    					if (matches != 9){
    					    printf("File can't be read by our simple parser : ( Try exporting with other options\n");
    					    return read;
    					}
    					face.vertex1 = vertexread[v1-1];
    					face.vertex2 = vertexread[v2-1];
    					face.vertex3 = vertexread[v3-1];
    					// face.texture1 = textureread[x-1];
    					// face.texture2 = textureread[y-1];
    					// face.texture3 = textureread[z-1];
    					face.colour = colourread[colourread.size()-1];
    					read.push_back(face);
    				}
    				else if( strcmp(lineHeader,"usemtl") == 0){
    					std::cout<<"In usemtl\n";
    					char Col[128];		//to store the colour name
    					fscanf(file, "%s\n", &Col);
    					std::cout<<Col<<"Printing colour\n";
    					
    					colourread.push_back(Col);

    				}
    			}	
			}
			return read;
		}
	}
}

std::unordered_map<std::string,Colour> filereadmtl(std::string path){
    std::unordered_map<std::string,Colour> read;
    std::vector<std::string> colourread;
    FILE *file = fopen(path.c_str(), "r");
    
    std::cout << "Starting\n";
    if( file == NULL ){
        printf("Impossible to open the file !\n");
        return read;
    }
    while( 1 ){
        std::cout << "In while\n";
        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", &lineHeader);

        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.
        else{
            std::cout << "In else\n";
            while( 1 ){
                std::cout << "In while again\n";
                char lineHeader[128];
                // read the first word of the line
                int res = fscanf(file, "%s", &lineHeader);
                if (res == EOF){
                    std::cout << "EOF found\n";
                    break; // EOF = End Of File. Quit the loop.
                }
                else{
                    if ( strcmp( lineHeader, "Kd" ) == 0 ){
                        std::cout << "vertex case\n";
                        Colour colour1;
                        fscanf(file, "%f %f %f\n", &colour1.x, &colour1.y, &colour1.z );
                        read[colourread[colourread.size()-1]] = colour1;
                    }
                    else if ( strcmp( lineHeader, "vt" ) == 0 ){
                        // Texture texture;
                        // fscanf(file, "%f %f\n", &texture.x, &texture.y );
                        // textureread.push_back(texture);
                    }
                    else if ( strcmp( lineHeader, "f" ) == 0 ){
                        // Face face;
                        // std::cout << "face case\n";
                        //  int v1,v2,v3 ,x,y,z,a,b,c;
                        // int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &v1,&x,&a,&v2,&y,&b,&v3,&z,&c );
                        // if (matches != 9){
                        //     printf("File can't be read by our simple parser : ( Try exporting with other options\n");
                        //     return read;
                        // }
                        // face.vertex1 = vertexread[v1-1];
                        // face.vertex2 = vertexread[v2-1];
                        // face.vertex3 = vertexread[v3-1];
                        // // face.texture1 = textureread[x-1];
                        // // face.texture2 = textureread[y-1];
                        // // face.texture3 = textureread[z-1];
                        // face.colour = colourread[colourread.size()-1];
                        // read.push_back(face);
                    }
                    else if( strcmp(lineHeader,"newmtl") == 0){
                        std::cout<<"In usemtl\n";
                        char Col[128];      //to store the colour name
                        fscanf(file, "%s\n", &Col);
                        std::cout<<Col<<"Printing colour\n";
                        
                        colourread.push_back(Col);

                    }
                }   
            }
            return read;
        }
    }    
}




void specialKeysrotate( unsigned char key, int x, int y ) 								//using special keys to rotate the balls
{	
	if (key == 100){
        rotate_y += 3;
    }
    else if (key == 97){
        rotate_y += -3;
    }
    else if (key == 119){
        rotate_x += 3;
    }
    else if (key == 115){
        rotate_x += -3;
    }
    else if (key == 120){
        rotate_z += 3;
    }
    else if (key == 122)
    {
    	rotate_z += -3;
    }
    glutPostRedisplay();
    // std::cout<<"Rotate Variables"<<"\n";
    // std::cout<<rotate_x<<"\n";
    // std::cout<<rotate_y<<"\n";
    // std::cout<<rotate_z<<"\n";
 }

void specialKeystranslate( int key, int x, int y ) 								//using special keys to rotate the balls
{	
	if (key == GLUT_KEY_RIGHT){
        keypressed = "right";
    }
    else if (key == GLUT_KEY_LEFT){
        keypressed = "left";
    }
    else if (key == GLUT_KEY_UP){
        keypressed = "up";
    }
    else if (key == GLUT_KEY_DOWN){
        keypressed = "down";
    }   	
    glutPostRedisplay();
 }


static void resize(int width, int height){
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

//rotate the whole frame
void Rotatetank(/*double rotate_x, double rotate_y , double rotate_z*/){
	glRotatef( rotate_x,1,0,0);
    glRotatef( rotate_y,0,1,0);
	glRotatef( rotate_z,0,0,1);
}

void Translatetank(double translate_x, double translate_y){
	glTranslatef(translate_x,translate_y,0);
}

void translatebullet(double translate_x,double translate_y){
    glTranslatef(translate_x,translate_y,0);
}

void translatemissile(double translate_x,double translate_y){
    glTranslatef(translate_x,translate_y,0);
}


//render object onto the screen
void display(void){	
	int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );

   
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, w, h);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
	glOrtho(-w,w,-h,h,-10000,10000);     
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();






	double width = glutGet(GLUT_WINDOW_WIDTH); //Width in pixels of the current window.
    double height = glutGet(GLUT_WINDOW_HEIGHT);
	double ar = width/height;

	// glColor3d(0,0,1);
	// glPushMatrix();
	// glTranslated(10,10,10);
	// glutSolidSphere(50,50,50);
	// glPopMatrix();
	
	// createbullet(bullet);
	// createmissile(missile);
	// createwall(wall);
	// createeagle(eagle);
    
	createtank(tank,mytank);
	// glTranslated(0,0,0);	

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
  
}

void createscreen(int argc,char* argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(1200,600);
	int main_window=glutCreateWindow("Yo Team Creation");
	double width = glutGet(GLUT_WINDOW_WIDTH); //Width in pixels of the current window.
	double height = glutGet(GLUT_WINDOW_HEIGHT);
	double asp = width/height;
}

 
// const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
// const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; 
// const GLfloat light_position2[] = { 2.0f, -5.0f , 5.0f , 0.0f };
// const GLfloat light_position3[] = { -2.0f, -5.0f , 5.0f , 0.0f };
// const GLfloat light_position4[] = { -2.0f, 5.0f , 5.0f , 0.0f };
// const GLfloat light_position5[] = { 2.0f, 5.0f, -5.0f, 0.0f }; 
// const GLfloat light_position6[] = { 2.0f, -5.0f , -5.0f , 0.0f };
// const GLfloat light_position7[] = { -2.0f, -5.0f , -5.0f , 0.0f };
// const GLfloat light_position8[] = { -2.0f, 5.0f , -5.0f , 0.0f }; 
// const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
// const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
// const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
// const GLfloat high_shininess[] = { 100.0f };




//int main
int main(int argc,char* argv[]){
	createscreen(argc,argv);
	

	// Vect* w= new Vect(0,0,0);
	// Vect* col = new Vect(1,1,1);
	// Vect* dim = new Vect(1400,1400,1400);
	// b->Setp(w);
	// b->Setd(dim);
	// b->Setc(col);


	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
	glutReshapeFunc(resize);
    // glutSpecialFunc(keySpecial);
    glutMouseFunc(mouseClicks);
    //glutSpecialFuncUp(keySpecialUp);
	// glutKeyboardFunc(keyPressed);
 //    glutKeyboardUpFunc(keyUp);
    glDepthFunc(GL_LESS); 
    LoadGLTextures();              // Load The Texture(s) 
    bullet = fileread("../trial/bullet.obj");
    missile = fileread("../trial/missile.obj");
    wall = fileread("../trial/wall.obj");
    eagle = fileread("../trial/monkey.obj");
    tank = fileread("../trial/tank.obj");

    tankcolour = filereadmtl("../trial/tank.mtl");
    glEnable(GL_TEXTURE_2D);            // Enable Texture Mapping
                                    
        // glEnable(GL_BLEND);
        // glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);           // enabling the transparency factor  //
        // glEnable(GL_LIGHT0);                                          // effects of lighting //
        // glEnable(GL_NORMALIZE);


        // glEnable(GL_COLOR_MATERIAL);
        // glEnable(GL_LIGHTING); 
     
        // glLightfv(GL_LIGHT2, GL_AMBIENT,  light_ambient);
        // glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
        // glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        // glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
        // glLightfv(GL_LIGHT0, GL_POSITION, light_position2); 
        // glLightfv(GL_LIGHT0, GL_POSITION, light_position3); 
        // glLightfv(GL_LIGHT0, GL_POSITION, light_position4); 
        // glLightfv(GL_LIGHT0, GL_POSITION, light_position5); 
        // glLightfv(GL_LIGHT0, GL_POSITION, light_position6); 
        // glLightfv(GL_LIGHT0, GL_POSITION, light_position7); 
        // glLightfv(GL_LIGHT0, GL_POSITION, light_position8);
        // glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        // glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        // glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        // glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutKeyboardFunc(specialKeysrotate);
    glutSpecialFunc(specialKeystranslate);
	glutDisplayFunc(display);
	glClearColor(1,0,0,1);
	glutMainLoop(); 
	return EXIT_SUCCESS;	
}
