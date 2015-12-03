#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std ;







int DataToFile ( const char  *filename ,int N ,int M)  // this functions stores a N random datas oscillating from 0 to M inclusive in a file passed as a parameter 

{
 

  int myArray[N] ;  // creates an array of N size 

  srand(time(0));
  for ( int i=0 ; i < N ; i++ )
    {
      myArray[i] = rand() % (M+1) ;  // stores in the array random numbers between [0-M]
    }
  ofstream output(filename) ;

  if ( output.is_open()) // if the file is open it goes in the if statement , copies the data and returns 1 otherwise returns 0
    {

  for ( int i=0 ; i<N ; i++ )
    output << myArray[i] << endl ;  // copies the data in the array to the file 

  output.close() ;
    
  return 1 ;

    }
  else 
    return 0;

}


 

int DataFromFile( const char *filename , int myArray[] , int &size ) // reads the data from a file and stored them in array passed as a parameter ( by reference ) and also assigns it sizes 
{

  ifstream input(filename) ;

  if ( input.fail() )
    {
      return 0;
    }

  int* newArray = new int[1000];  // creates a pointers to an array of the maximum size 1000 

  int size1 ;
  for ( int i=0 ; i < 1000 ; i++ )
    {
    input >> newArray[i]; // reads the data and puts in the array 
    if ( input.eof() ) // if there is no more data , it gets in the if statement and assign to size1 , i ( value it has at the last interation corresponding to the size of the array )
      {
      size1 = i ;
      break;
      }
    }

  input.close() ;


 for ( int i=0 ; i<size1 ; i++ ) // copies all the data read in the array passed as an argument 
   myArray[i] = newArray[i] ;

 size = size1 ; // assign size1 to size 
  return 1 ;


}




