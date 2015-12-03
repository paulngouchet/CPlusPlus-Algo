#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "pa2Functions.h"
using namespace std ;

extern const int ENTRIES;
void initialize()   // this function contains the header of the program 
{

  cout<<"EC327: Introduction to Software Engineering" << endl ;
  cout<<"Fall 2015" << endl ;
  cout<< "Programming Assignment 2" << endl ;
    cout<< "Value of Entries is: " << ENTRIES << endl ;
 
}
 
bool checkCode(char code )  // this function checks if the command code entered by the user is right 
{

  if ( code == 'F' || code =='f' || code == 'B' || code =='b' || code =='R' || code == 'r' || code =='L' || code == 'l' || code =='N' || code =='n' || code == 'I' || code =='i' || code == 'O' || code =='o' || code =='Q' || code == 'q' ) 
    {
      return true ;
    }

  return false ;

}
void writeDataToFile(const char* filename)  // it copies the files from the intermediate file "filesavior.txt " to filename entered by the user 
{

ofstream output ;
output.open (filename) ;

ifstream input ;
input.open("filesavior.txt") ;

char ch = input.get() ;
while (!input.eof())
{
  output.put(ch) ;
  ch = input.get() ;
}

input.close() ;
output.close() ;



}

void readDataFromFile(const char* filename)  // it reads the data from the file  and executed the data according to the program 
{
                                            // it has a copy od all the different possible cases as indicated by the program 
      ifstream input ;
      input.open(filename) ;

      char letter ;

      double myarray[3] = { 0 , 0 , 0} ;




      while ( !(input.eof()))
      {

      input>> letter ;

      if ( letter == 'F' || letter == 'f')
      input>> myarray[0] ;

    else if ( letter == 'B' || letter == 'b')
      input>> myarray[0]  ;


    else if ( letter == 'R' || letter == 'r')
      input>> myarray[0] >> myarray[1] >> myarray[2] ;

    else if ( letter == 'L' || letter == 'l')
      input>> myarray[0] >> myarray[1] >> myarray[2] ;

    else if ( letter == 'N' || letter == 'n')
      input>> myarray[0] >> myarray[1] >> myarray[2] ;

    else if ( letter == 'D' || letter == 'd')
      input>> myarray[0] >> myarray[1] ;


      if (checkCode(letter))
        {
        


      if ( letter == 'F' || letter == 'f')
        {
          
        cout<<"factorial("<<myarray[0]<<") "<<"= " << factorial((int)myarray[0])<<endl ;


      }


    else if ( letter == 'B' || letter =='b')
      {
    
        cout<<"fibonacci"<<myarray[0]<<") "<<" = " << fibonacci((int)myarray[0])<<endl ;


      }







    else  if ( letter == 'R' || letter == 'r')
      {
       

        if ( myarray[2] <= 0 || (myarray[0] > myarray[1]))
        {
    cout<<"No computation needed."<< endl ;

      }
        else
        {
          int i = 0 ;
          while (true)
          {
            if ( (myarray[0]+ (myarray[2]*i)) >= myarray[1])
            {

               
              cout<<fixed << setprecision(4) << "Square root of "<< myarray[1] << " = " << (findSqrtValue(myarray[1]))<< endl ;
              break ;

            }

            cout<<fixed << setprecision(4) << "Square root of "<< myarray[0] + (myarray[2]*i) << " = " << (findSqrtValue(myarray[0] + (myarray[2]*i)))<< endl ;
            i++ ;

            if ( i == ENTRIES)
              break;

          }
        }
     }

  







    else  if ( letter == 'L' || letter == 'l')
      {
        
        if ( myarray[2] <= 0 || (myarray[0] > myarray[1]))
        {
    cout<<"No computation needed."<< endl ;
      }
        else
        {
          int i = 0 ;
          while (true)
          {
            if ( (myarray[0]+ (myarray[2]*i)) >= myarray[1])
            {

              cout<<fixed << setprecision(4) << "Natural log of "<< myarray[1] << " = " << (naturalLog(myarray[1]))<< endl ;
              
              break ;
            }

            cout<<fixed << setprecision(4) << "Natural log of "<< myarray[0] + (myarray[2]*i) << " = " << (naturalLog(myarray[0] + (myarray[2]*i)))<< endl ;
            
            i++ ;

            if ( i == ENTRIES)
              break;

          }
        }
    }





else  if ( letter == 'N' || letter == 'n')
      {
       
        if ( myarray[2] <= 0 || myarray[0] > myarray[1])
        {
    cout<<"No computation needed."<< endl ;
      }
        else  
        {
          int i = 0 ;
          while (true)
          {
            if ( (myarray[0]+ (myarray[2]*i)) >= myarray[1])
            {

              cout<<fixed << setprecision(4) << "NyanCat value of "<< myarray[1] << " = " << (findNyanCatValue(myarray[1]))<< endl ;

              break ;
            }

            cout<<fixed << setprecision(4) << "Nyancat value of "<< myarray[0] + (myarray[2]*i) << " = " << (findNyanCatValue(myarray[0] + (myarray[2]*i)))<< endl ;
            i++ ;

            if ( i == ENTRIES )
              break;

          }
        }
    }



    else if ( letter == 'D' || letter == 'd')
    {


      int number = 0 ;

    int i = 0 ; 
      cout<< myarray[0] << " " ; ;

      while (true)
      {

        number = findNextOddValue ((int)myarray[0]) ;

        if ( ( (number + 1) == (int)myarray[1] ) || ((number + 2) == (int)myarray[1] ) )
        {
          cout << myarray[1] << endl ;
          break ;
        }

            cout << number << " ";
            cout << number << " ";

           myarray[0] = number ;

         i++ ;

         if ( i == ENTRIES)
          break ;
     }

 }


 }

    }


    }

double findNyanCatValue (double value )   // returns the nyancat value of a number 

{
  double result = (2*value ) + (( value * (pow(6 , value )))) ; // simple math 
  return result ;

				 } 

int factorial(int value )  // returns the factorial of a number 
    {
      int result = 1 ;
      int i = 1 ;

      while ( i <= value ) 
	{
	  result = result * i ;   // result = result * i  and increments i after each iteration until i = value entered as a paremeter 
	  i++;
	} 
      return result ;
    }

int fibonacci(int index )   // returns the fibonacci number at the index entered as a parameter 

{
  const int size = index + 1 ;
  int array[size] ;  // creates an array of size = index + 1
 array[0] = 0 ;      // initialize the first two values of the array with 0 and 1 . 
 array[1] = 1 ;

 for ( int i = 2 ; i< size ; i++ )
   array[i]=  array[i-1] + array[i-2]  ;  // store in the following array element the sum of the 2 preceding array elements 

 return array[index] ;  // returns the array[index] ;
}
 

double findSqrtValue(double value)  // returns the square root of a value
{
  return (sqrt(value)) ;

}


double naturalLog(double value)  // returns the natural log of a value 
 
{
  return (log(value)) ;

}



int findNextOddValue(int value)  // returns the odd number higher and closer to the value entered 

{

  int result = 0 ; 

  if ( (value % 2 ) == 0)  // check if the value is even or not  and assign result in function 
    result = value + 1 ; 
  else
    result = value + 2 ;

  return result ;

}











