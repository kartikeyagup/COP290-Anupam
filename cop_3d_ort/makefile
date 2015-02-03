execute:Circle1.cpp Rectangle.cpp Vect.cpp 7.cpp
	g++ -std=c++11 Circle1.cpp Rectangle.cpp Vect.cpp 7.cpp -lpthread -lGL -lGLU -lglut -lglui
	./a.out $(num_thread)
	rm a.out

test: Test.cpp TestRecCir.cpp Circle1.cpp Rectangle.cpp Vect.cpp
	g++ -std=c++11 Test.cpp TestRecCir.cpp Circle1.cpp Rectangle.cpp Vect.cpp

clear:
	rm -rf *o execute
