all : Game

Game: Vector.o Tank.o PowerUps.o Bullet.o Walls.o Board.o TestTank.o  
	g++ -o Game Vector.o Tank.o PowerUps.o Bullet.o Walls.o Board.o TestTank.o

Vector.o : Vector.cpp 
	g++ -c Vector.cpp

Tank.o : Tank.cpp
	g++ -c -std=c++11 Tank.cpp

Bullet.o :  Bullet.cpp
	g++ -c Bullet.cpp

Walls.o :  Walls.cpp
	g++  -c Walls.cpp

Board.o : Board.cpp
	g++ -c Board.cpp

PowerUps.o : PowerUps.cpp
	g++ -c PowerUps.cpp

TestTank.o : TestTank.cpp
	g++ -c TestTank.cpp
