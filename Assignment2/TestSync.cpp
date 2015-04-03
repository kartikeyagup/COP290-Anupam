#include <bits/stdc++.h>
#include "Sync.h"

using namespace std;

int main()
{
	Sync* a = new Sync();
	vector<filechars> file,file1 ;
	filechars b;
	b.filename = "/anupam/1.cpp";
	b.filemodtime = 13;
	filechars c;
	c.filename = "/anupam/2.cpp";
	c.filemodtime = 14;
	filechars d;
	d.filename = "/anupam/3.cpp";
	d.filemodtime = 15;
	file.push_back(b);
	file.push_back(c);
	file.push_back(d);
	a->setf(file);
	filechars e;
	e.filename = "/anupam/1.cpp";
	e.filemodtime = 10;
	filechars f;
	f.filename = "/anupam/2.cpp";
	f.filemodtime = 15;
	filechars g;
	g.filename = "/anupam/3.cpp";
	g.filemodtime = 13;
	file1.push_back(e);
	file1.push_back(f);
	file1.push_back(g);
	a->seto(file1);
	//a->getaction();
}