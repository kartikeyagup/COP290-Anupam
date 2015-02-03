#include <boost/filesystem.hpp> 
#include <iostream> 

int main() 
{ 
  boost::filesystem::path p("/home/btech/cs1130212/COP290-Anupam/Assignment2"); 

  //std::wcout << p.native() << std::endl; 

  std::cout << p.string() << std::endl; 
  //std::wcout << p.wstring() << std::endl; 

  std::cout << p.generic_string() << std::endl; 
 // std::wcout << p.generic_wstring() << std::endl; 
} 