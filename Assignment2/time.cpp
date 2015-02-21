	
#include <sys/stat.h>
#include <bits/stdc++.h>	
#include <unistd.h>
	
#include <time.h>
	

int main()
{

	
	struct tm* clock;				// create a time structure
		
	struct stat attrib;			// create a file attribute structure
	        
	stat("Authentication.cpp", &attrib);		// get the attributes of afile.txt
		
	clock = gmtime(&(attrib.st_mtime));
	std::cout << clock->tm_year <<"\n";
	std::cout << clock->tm_mon <<"\n";
	std::cout << clock->tm_mday <<"\n";
	std::cout << clock->tm_hour <<"\n";
	std::cout << clock->tm_min <<"\n";
	std::cout << clock->tm_sec <<"\n";
}	