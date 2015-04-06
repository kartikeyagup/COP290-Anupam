#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <bits/stdc++.h>
struct Vertex{
	float x;
	float y;
	float z;
};

struct Texture{
	float x;
	float y;
};

struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};
typedef struct Image Image;

int ImageLoad(char*,Image);
void LoadGLTextures();

struct Face{
	Vertex vertex1,vertex2,vertex3;
	std::string colour;
	// Texture texture1, texture2, texture3; 
};

struct Colour{
	float x,y,z;
};

std::vector<Face> fileread(std::string);
std::unordered_map<std::string,Colour> filereadmtl(std::string);

void specialKeystranslate(unsigned char,int,int);
void specialKeysrotate(unsigned char,int,int);
// static void resize(int ,int);
void keySpecial(int,int,int);
void keySpecialUp(int,int,int);
void display(void);
void createscreen(int,char*);

void Rotatetank(/*double,double,double*/);
void Translatetank(double,double);

void translatebullet(double,double);
void translatemissile(double,double);
#endif