We have made a screensaver in which balls move on the screen both in 2-D and 3-D. We have made several classes which are as follows:
1) Rectangle.cpp - In this file, we have created the board on which the balls move. We have used its parameters in the circle.cpp file to handle the reflection
                   of the balls with the walls of the board.

2) Circle.cpp- In this file, we have created the balls with various parameters like radius, components of speed in x and y direction and coordinates of the centre of the ball 
	       and handled their movement, collision between the balls and reflection between balls and walls of the board.
	       In case of 3D design, we have used vector calculus to create the balls and the board and handle the parameters and function specified above.

3) Vect.cpp - In this file, we have made a class for vector calculus which have used in Circle and Rectangle.cpp in case of 3D design to make the calculation in various functions like move, collision and reflection functions easier.

4) Test.cpp- We have created a class called test to verify our program, and then used it to do multiple unit testing. We have done the overall testing by closely observing the screensaver during the runtime.

5) Graphics (openGL) - In this file, we have added the graphics in our program. We have added various features to make our screen saver presentable. They are as follows:
		1) Lighting and Materials- We have added lights so that the balls have a 3D effect even in 2D case. We have used material which makes the ball shiny due to which
		                           the screen saver looks more intriguing.
		2) GUI Buttons- We have added GUI Buttons to provide user with various functions like play and pause the screen saver,adding, deleting a ball, showing the speed of the ball and and also setting new
				speed of the ball. For this we have used openGL library called glui.
				Also in 3D case, we have added Rotation button to rotate the box and scroll bar to zoom in and zoom out of the box.
		3) Added Water in 2D case- We have added water to add the effect of buoyancy and also added gravity which can be both switched on and off at the same time with the help of glui checkbox.
		4) Collision effect- We have also added particle effect during the collision between the balls i.e. we have flashed small spheres whenever the two balls collide.
		5) Transparency in 3D box- We have made 4 walls of the 3D box transparent to increase the overall fell of the screen saver.

Usage of POSIX-Threads- We have used pthreads to control the  movement, collision between the balls and reflection between balls and walls of the board.
			For inter thread communication, we have first used barrier method in which we have kept the parameters of balls global. Then we have used one to one communication between the threads and passed 
			messages between them using message queues. The message includes the attributes of the ball which is sending the message to the other balls and has similar messages from other balls in its mailbox.
			For inter thread synchronization, we have used mutex locking mechanism which helps us to synchronize the action between the threads.
			These threads help us in parallel processing of the functions like collision, move and reflection.
		\\Reason behind using one to one communicaiton


					##############################        HOW TO USE         ##############################








		