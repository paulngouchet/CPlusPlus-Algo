#include <iostream>
using namespace std ;

void PrintRhombus(int n){
	static int e = n ;          // define some static variables in order for them for to be reinitialized each the function 
	static int d = n ;          // PrintRhombus is called 
	static int c = n ;          // e ,  d , c and b are integers that take the initial value of the number chosen by the user [1 , 9]
	static int b = n ;          // a = 1 
  	static int a = 1 ;          // savior is a static bool variable initialized with 1 ;
  	static bool savior = true ;
	
	if(n == 1) {              // Base case of the recursion
		for(int i = 1 ; i < e ; i++)
			cout << "  " ;
		
		cout<< "1 " << endl ;
	}
	else if(savior){        // when this if statement is entered it prints the top of the rhombus until line before the middle of the  Rhombus 
		if (c != 0){ // enters only if c different of zero ; 
			for(int i = 1 ; i < c ; i++ )    // This For loop is for the formatting of the rhombus with the exact number of spaces 
				cout << "  " ;                   // depending on the line at that time defines by c .
			c-- ;                              // decrements c .
		}
		
		for(int i = 1 ; i <= a ; i++) // prints the first part of the line 
			cout<< i << " " ;
		for(int i = a-1 ;i >= 1 ; i--) // prints the second part of line 
			cout<<i << " " ;
		
		cout << endl ;
		a++ ;                            // increments a .
		
		if(a == b)                    // when a is now equal to the number entered by the user , savior becomes false and it nevers enters the if statement again when the PrintRhombus is called
			savior = false ;
		PrintRhombus ( a ) ;             // calls printrhombus with the value of a ;
	}
	else if(n  > 1){              // This if statement only enters when the else if ( savior) is not entered , this if prints the bottom of the Rhombus from middle to the line before "1" ( the base case of the recursion )                                // it enters only if n ( number chosen by the user ) is greater than one 
		if ( n != d ){                 // This if statement is to print the spaces for the formatting of the Rhombus 
			
			for ( int i = d ; i > n ; i-- )
				cout << "  " ;
		}
		
		for(int i = 1 ; i <= n ; i++)   // prints the first part of the line 
			cout<< i << " " ;
		
		for(int i = n-1 ;i >= 1 ; i--)  // prints the second part of the line 
			cout<<i << " " ;
		
		cout << endl ;
		PrintRhombus(n -1) ;        // calls PrintRhombus with the value n -1 , decrementing until n - 1 = 1 and reach the base case and stop the recursion .
	} 


    }

int main(){     // main function 
	int number ;
	
	while(true){
		cout<< "Enter a number [1-9]: " ;     // asks the user to choose a number between [1-9] ;
		cin>>number ;
		
		if(number > 9 || number < 1){
			cout<< "Wrong input, please enter a single digit number between 1 and 9." << endl ; // if the number is not in the interval [1-9] , it prints an error message .
			cout<<endl ;
		}
		else{
			break ;
		}
	}
	
	PrintRhombus(number) ;     // calls PrintRhombus in order to print the Rhombus with the number chosen by the user . 
}
