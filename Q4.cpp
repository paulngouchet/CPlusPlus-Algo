#include <iostream>
using namespace std ;


int* ReverseMultiply ( int* list , int size )    // function ReverseMultiply that take a pointer ( array ) as a parameter and the size of the array 
{                                                // double the size + 1  
  int* myArray = new int[2*size+1] ;             // pointer of an array of size 2*size+1 in the heap 
  for ( int i = 0 ; i<size ; i++ )               // copy all the data of the array passed in the function in the first part of myarray 
      myArray[i] = list[i] ;

  int a = size-1 ;
 
  for ( int i = size ; i < ( 2*size) ; i++ )     // copy the data of the array passed in the function in reverse order in the second part of myarray excluding the last components of myarray (myarray[2*size])
    {
      myArray[i] = list [a] ;
    a--;
    }

  myArray[2*size] = 1 ;
  for ( int i = 0 ; i<2*size  ; i++ )
    {
      myArray[2*size]*= myArray[i] ;    // stored the sum of the data of my array in myarray[2*size] .
    }

  return myArray ;                    // return the pointer to the array 
}


int main ( ) 
{
  int size ;
  cout<< "Enter the number of entries: " ;     // ask the user the number of entries 
  cin>>size ;

  if ( size <= 0)                             // if the user enters a number <=0 it prints an error . 
    {
      cout<< "Invalid size entered." << endl ;
    return 0 ;
    }

  int* newArray = new int[size] ;           // pointer to an array in the heap ;

  for ( int i=0 ; i<size ; i++ )            // fills the differents entries in the array 
    {
      cout << "Entry " << i << " is: " ;
    cin>>newArray[i] ;
    }
  cout << "*****" << endl ;                 // prints line of asterix to separate the output . 

  int* finalArray = ReverseMultiply(newArray , size ) ; // the new pointer points to the same thing as the pointer retured by the function ReverseMultiply()

  cout<<"Original array is: " ;                 // prints the original data stored in the array ( entries )
  for ( int i=0 ; i<size ; i++ )
    cout<< newArray[i] << " " ;

  cout << "and the address of the zero element is: " << &newArray[0] << endl ; // address of the zero element 

  cout <<"Final array is: " ;                     // prints the data stored in the final array 
  for ( int i=0 ; i < (2*size+1 ) ; i++ )
    cout<< finalArray[i] << " " ;
  cout<< "and the address of the zero element is: " << &finalArray[0] << endl ; // prints the address of the zero element .


}
