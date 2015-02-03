/* rename example */
#include <stdio.h>

int main ()
{
  int result;
  char oldname[] ="/home/btech/cs1130212/COP290-Anupam/Assignment2/abc.txt";
  char newname[] ="/home/btech/cs1130212/Desktop/a.txt";
  result= rename( oldname , newname );
  if ( result == 0 )
    puts ( "File successfully renamed" );
  else
    perror( "Error renaming file" );
  return 0;
}