#include <iostream>
#include <cmath>
using namespace std ;



float  getMean ( int myArray[] , int size ) // calculate the mean of the data in the array 
{
  int result = 0 ;

  for ( int i=0 ; i < size ; i++ )
    result +=  myArray[i] ;   //  the value of result of is updated to result + myarray[i] at ecah iteration 

  float answer = (float)result ; //  cast the value of result to float and stores it in the variable answer 

   answer  = answer  / size ; 

  return answer ; // return answer which is the mean .

}



float getStdDev (int myArray[] , int size )  // calculates the standard deviation of the data in the array 
{

  float mean = getMean ( myArray , size ) ; // assign the mean of the data in the array to the variable mean by calling getMean 
 
  float intermediate ;

  for ( int i=0 ; i < size ; i++ )  // for loop to calculates the first step of the standard deviation , sum of (Xi-mean)^2
    {
    float a =  (((float)myArray[i]) - mean ) ;
    intermediate += (a*a) ;
    }

  intermediate = (intermediate / size) ;  // DIVIDE THE value obtained in the fist step by the size of the array 

  intermediate = sqrt ( intermediate ) ;   // find the square root of the actual value stored in intermediate 

  return intermediate ; // returns intermediate 

}



 


