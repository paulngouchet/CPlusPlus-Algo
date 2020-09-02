#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std ;
#include "statistics.h"
#include "q3func.h"

int main(){
  int size ; 
  int array[1000];
  int N  ;
  int M  ;
  int check =  DataFromFile("numbers.txt" , array , size) ; // calls DataFromFile function and stores the value returned in the varibale check
  
  if(check == 0) { // if check == 0 , it prints an error message .
    cout << "Sorry , file doesn't exist" << endl ;
    return  0 ;
  }
  
  if (size == 0) { // enters this if statement if size == 0 
    cout << "Array size is: " << size << endl ;  // prints none at the end of each declaration 
    cout << "Mean is: " << "None"<<endl ;
    cout<< "StdDev is: " << "None" << endl ;
    cout<< "Array values forward are: " << "None" << endl ;
    cout<< "Array values reverse are: " << "None" << endl ;
    cout<< "The largest array value is: " << "None" <<endl ;
    cout<< "The smallest array value is: " << "None" <<endl ;
    
    return 0 ;
  }
  
  int finalArray[size] ;
  
  for(int i=0 ;i < size ; i++ )
    finalArray[i] = array[i] ;
  
 cout << "Array size is: " << size << endl ; // prints the array size 
 cout << fixed << setprecision(2) << "Mean is: " << getMean(finalArray ,size)<<endl ; // prints the mean 
 cout<< fixed << setprecision(2) << "StdDev is: " << getStdDev(finalArray , size ) << endl ; // prints the standard deviation 
 cout<< "Array values forward are: " ; // prints the array elements forward using a for loop 
  
 for(int i = 0 ; i < size ; i++ ){
   cout<< finalArray[i] ;  
   if (i == size -1 )
     cout<<" " ;
   else 
     cout<< ", " ;
 }
  
 cout<<endl ;
 cout<< "Array values reverse are: " ;   // prints the array elements in a reverse order using the for loop 
 
  for ( int i = size -1 ; i >=0 ; i-- ){
    cout << finalArray[i] ; 
    if(i == 0)
      cout << " " ;
    else 
      cout << ", " ;
  }
  
  cout << endl ;
  int* min = min_element (finalArray , finalArray + size ); // use algorithm functions 
  int* max = max_element ( finalArray ,finalArray + size );
  cout<< "The largest array value is: " << *max << endl ;  // prints the smallest element of the array
  cout<< "The smallest array value is: " << *min << endl ; // prints the largest elemetn of the arry 
  return 0 ;
}
