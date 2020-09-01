#include <iostream>
#include <iomanip>
#include <fstream>
#include "pa2Functions.h"
using namespace std ;

extern const int ENTRIES = 10 ;
int main (){
	initialize() ; // Iniatilize the program with the header 
	
	while(true){ 
		char code ; 
		cout<< "Please enter command code: "  ;  // Asks the user to enter a command code 
     		cin>> code ; 								// save it in the variable code 
		
		if( checkCode(code )){    // check the command code entered by the user is right , enter the if statement if yes , if not prints an error message 
			if ( code == 'Q' || code == 'q')			// check if code == q or Q , terminates the program if true , continue the program if not .
				return 0 ;
			else if ( code == 'I' || code == 'i'){	// if  code == i or I it reads data from file by calling a function readDataFromFile which parameter is the name of the file entered by the user .
				string filename ;
      				cout<< "Please enter command parameters: " ;
      				cin>> filename ;
				readDataFromFile ( filename.c_str()) ;
			}
			else if ( code == 'O' || code =='o'){ // if code == 'O' or 'o' it copy first the successive output of the program in an intermediate file "filesavior.txt" 										// then copies all the contents of that file in the file named by the user by calling the function WriteDataToFile when the user enter Q or q to terminates program .
				string filename1 ;
				cout<< "Please enter command parameters: " ;
				cin>> filename1 ;
				ofstream output ;
				output.open("filesavior.txt") ;
				
				while(true){    // all the lines in this if statement are just a copy of the different possible cases of the program except that " output "is used  each time after "cout" to copy the outputs 					// in the intermeadiate file " filesavior.txt" as described in the top .
					// all the functionality of the program is explained later at the end of this if statement .
					char code1 ;
					cout << "Please enter command code: " ; 
					cin>> code1 ;
					output<< "Please enter command code: " << code1 << endl ;
					
					if (checkCode(code1)){
						if ( code1 == 'Q' || code1 == 'q'){
							writeDataToFile ( filename1.c_str()) ;
							return 0 ;
						}
						else if ( code1 == 'F' || code1 == 'f'){
							int input1 ;
	      						cout<<"Please enter command parameters: " ;
	     						cin>>input1 ;
	     						cout<<"factorial("<<input1<<") "<<"= " << factorial(input1)<<endl ;
	     	 					output<< "Please enter command parameters: " << input1 << endl ;
	      						output<<"factorial("<<input1<<") "<<" = " << factorial(input1)<<endl ;
						}
						else if (code1 == 'I' || code1 == 'i'){
							string filename ;
	    						cout<< "Please enter command parameters: " ;
	    						output<< "Please enter command parameters: " ;
	    						cin>> filename ;
	    						output<< filename  << endl ; 
							ifstream input ;
      							input.open(filename) ;
							char letter ;
      							double myarray[3] = { 0 , 0 , 0} ;
							
							while ( !(input.eof())){
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
								
								if (checkCode(letter)){
									if ( letter == 'F' || letter == 'f'){
										cout<<"factorial("<<myarray[0]<<") "<<"= " << factorial((int)myarray[0])<<endl ;
        									output<<"factorial("<<myarray[0]<<") "<<"= " << factorial((int)myarray[0])<<endl ;
									}
									else if ( letter == 'B' || letter =='b'){
										cout<<"fibonacci"<<myarray[0]<<") "<<" = " << fibonacci((int)myarray[0])<<endl ;
										output<<"fibonacci"<<myarray[0]<<") "<<" = " << fibonacci((int)myarray[0])<<endl ;
									}
									else  if ( letter == 'R' || letter == 'r'){
										if ( myarray[2] <= 0 || (myarray[0] > myarray[1])){
											cout<<"No computation needed."<< endl ;
											output<<"No computation needed."<< endl ;
										}
										else{
											int i = 0 ;
											
											while (true){
												if ( (myarray[0]+ (myarray[2]*i)) >= myarray[1]){   
													cout<<fixed << setprecision(4) << "Square root of "<< myarray[1] << " = " << (findSqrtValue(myarray[1]))<< endl ;
              												output<<fixed << setprecision(4) << "Square root of "<< myarray[1] << " = " << (findSqrtValue(myarray[1]))<< endl ;
              												break ;
												}
												cout<<fixed << setprecision(4) << "Square root of "<< myarray[0] + (myarray[2]*i) << " = " << (findSqrtValue(myarray[0] + (myarray[2]*i)))<< endl ;
            											output<<fixed << setprecision(4) << "Square root of "<< myarray[0] + (myarray[2]*i) << " = " << (findSqrtValue(myarray[0] + (myarray[2]*i)))<< endl ;
            											i++ ;
												if ( i == ENTRIES)
													break;
											}
										}
									}
									else  if ( letter == 'L' || letter == 'l'){
										if ( myarray[2] <= 0 || (myarray[0] > myarray[1])){
											cout<<"No computation needed."<< endl ;
    											output<<"No computation needed."<< endl ;
										}
										else{
											int i = 0 ;
											while (true){
												if ( (myarray[0]+ (myarray[2]*i)) >= myarray[1]){
													cout<<fixed << setprecision(4) << "Natural log of "<< myarray[1] << " = " << (naturalLog(myarray[1]))<< endl ;
              												output<<fixed << setprecision(4) << "Natural log of "<< myarray[1] << " = " << (naturalLog(myarray[1]))<< endl ;
													break ;
												}
												cout<<fixed << setprecision(4) << "Natural log of "<< myarray[0] + (myarray[2]*i) << " = " << (naturalLog(myarray[0] + (myarray[2]*i)))<< endl ;
            											output<<fixed << setprecision(4) << "Natural log of "<< myarray[0] + (myarray[2]*i) << " = " << (naturalLog(myarray[0] + (myarray[2]*i)))<< endl ;
												i++ ;
												
												if ( i == ENTRIES)
													break;
											}
										}
									}
									else  if ( letter == 'N' || letter == 'n'){
										if ( myarray[2] <= 0 || myarray[0] > myarray[1]){
											cout<<"No computation needed."<< endl ;
											output<<"No computation needed."<< endl ;
										}
										else{
											int i = 0 ;
											while (true){
												if ( (myarray[0]+ (myarray[2]*i)) >= myarray[1]){
													cout<<fixed << setprecision(4) << "NyanCat value of "<< myarray[1] << " = " << (findNyanCatValue(myarray[1]))<< endl ;
              												output<<fixed << setprecision(4) << "NyanCat value of "<< myarray[1] << " = " << (findNyanCatValue(myarray[1]))<< endl ;
													break ;
												}
												
												cout<<fixed << setprecision(4) << "Nyancat value of "<< myarray[0] + (myarray[2]*i) << " = " << (findNyanCatValue(myarray[0] + (myarray[2]*i)))<< endl ;
												output<<fixed << setprecision(4) << "Nyancat value of "<< myarray[0] + (myarray[2]*i) << " = " << (findNyanCatValue(myarray[0] + (myarray[2]*i)))<< endl ;
												i++ ;
												
												if ( i == ENTRIES )
													break;
											}
										}
									}
									else if ( letter == 'D' || letter == 'd'){
										int number = 0 ;
										int i = 0 ; 
      										cout<< myarray[0] << " " ; ;
      										output<< myarray[0] << " " ; ;
										while (true){
											number = findNextOddValue ((int)myarray[0]) ;
											
											if ( ( (number + 1) == (int)myarray[1] ) || ((number + 2) == (int)myarray[1] ) ){
												cout << myarray[1] << endl ;
												output << myarray[1] << endl ;
          											break ;
											}
											
											cout << number << " ";
											output << number << " ";
											myarray[0] = number ;
											i++ ;
											
											if ( i == ENTRIES)
												break ;
										}
									}
								}
							}
						}
						
						else if ( code1 == 'B' || code1 =='b'){
							int input2 ;
	      						cout<<"Please enter command parameters: " ;
	      						cin>>input2 ;
	      						cout<<"fibonacci"<<input2<<") "<<" = " << fibonacci(input2)<<endl ;
		  					output<< "Please enter command parameters: " << input2 << endl ;
		 					output<<"fibonacci("<<input2<<") "<<" = " << fibonacci(input2)<<endl ;
						}
						
						else  if ( code1 == 'R' || code1 == 'r'){
							double input3[3];
							cout<< "Please enter command parameters: ";
							output<< "Please enter command parameters: ";
							
							for(int i = 0 ; i<3 ; i++ ){
								cin>> input3[i] ;
								output << input3[i] << " " ;
							}
							
							output<< endl ;
							
							if (input3[2] <= 0 || (input3[0] > input3[1])){
								cout<<"No computation needed."<< endl ;
								output<<"No computation needed."<< endl ;
							}
							else{
								int i = 0 ;
								
								while (true){
									if ( (input3[0]+ (input3[2]*i)) >= input3[1]){ 
										cout<<fixed << setprecision(4) << "Square root of "<< input3[1] << " = " << (findSqrtValue(input3[1]))<< endl ;
	      									output<<fixed << setprecision(4) << "Square root of "<< input3[1] << " = " << (findSqrtValue(input3[1]))<< endl ;
	      									break ;
									}
									
									cout<<fixed << setprecision(4) << "Square root of "<< input3[0] + (input3[2]*i) << " = " << (findSqrtValue(input3[0] + (input3[2]*i)))<< endl ;
	      								output<<fixed << setprecision(4) << "Square root of "<< input3[0] + (input3[2]*i) << " = " << (findSqrtValue(input3[0] + (input3[2]*i)))<< endl ;
	      								i++ ;
									
									if ( i == ENTRIES)
										break;
								}
							}
						}
						
						else  if ( code1 == 'L' || code1 == 'l'){
							double input4[3];
							cout<< "Please enter command parameters: " ;
	      						output<< "Please enter command parameters: " ;
	      						int i = 0 ;
							
							while(i<3){
								cin>> input4[i] ;
		  						output<< input4[i] << " " ;
		  						i++ ;
							}
							
							output << endl ;
							if ( input4[2] <= 0 || (input4[0] > input4[1])){
								cout<<"No computation needed."<< endl ;
								output<<"No computation needed."<< endl ;
							}
							else{
								int i = 0 ;
								
								while (true){
									if ( (input4[0]+ (input4[2]*i)) >= input4[1]){
										cout<<fixed << setprecision(4) << "Natural log of "<< input4[1] << " = " << (naturalLog(input4[1]))<< endl ;
										output<<fixed << setprecision(4) << "Natural log of "<< input4[1] << " = " << (naturalLog(input4[1]))<< endl ;
										break ;
									}
									
									cout<<fixed << setprecision(4) << "Natural log of "<< input4[0] + (input4[2]*i) << " = " << (naturalLog(input4[0] + (input4[2]*i)))<< endl ;
	      								output<<fixed << setprecision(4) << "Natural log of "<< input4[0] + (input4[2]*i) << " = " << (naturalLog(input4[0] + (input4[2]*i)))<< endl ;
	      								i++ ;
									
									if ( i == ENTRIES)
										break;
								}
							}
						}
						
						else  if ( code1 == 'N' || code1 == 'n'){
							double input5[3];
	      						cout<< "Please enter command parameters: " ;
	      						output<< "Please enter command parameters: " ;
	     				 		int i = 0 ;
							
							while ( i <3 ){
								cin>> input5[i] ;
		  						output<< input5[i] << " ";
		  						i++ ;
							}
							
							output<<endl ;
							
							if (input5[2] <= 0 || (input5[0] > input5[1])){
								cout<<"No computation needed."<< endl ;
								output<<"No computation needed."<< endl ;
							}
							else {
								int i = 0 ;
								
								while (true){
									if ( (input5[0]+ (input5[2]*i)) >= input5[1]){
										cout<<fixed << setprecision(4) << "NyanCat value of "<< input5[1] << " = " << (findNyanCatValue(input5[1]))<< endl ;
	      									output<<fixed << setprecision(4) << "NyanCat value of "<< input5[1] << " = " << (findNyanCatValue(input5[1]))<< endl ;
	      									break ;
									}
									
									cout<<fixed << setprecision(4) << "Nyancat value of "<< input5[0] + (input5[2]*i) << " = " << (findNyanCatValue(input5[0] + (input5[2]*i)))<< endl ;
	      								output<<fixed << setprecision(4) << "Nyancat value of "<< input5[0] + (input5[2]*i) << " = " << (findNyanCatValue(input5[0] + (input5[2]*i)))<< endl ;
	      								i++ ;
									
									if ( i == ENTRIES )
										break;
								}
							}
						}



	  else if ( code1 == 'D' || code1 == 'd')
	  {
	  	int odd[2] ;
	  	cout<< "Please enter command parameters: " ;
	  	output<< "Please enter command parameters: " ;
		int a = 0;
	  	while( a<2)
	  	{
	  		cin>> odd[a] ;
	  		output<< odd[a] << " " ;
	  		a++ ;

	  	}

	  	output << endl ;

	  	int number = 0 ;

		int i = 0 ; 
	  	cout<< odd[0] << " " ;
	  	output<< odd[0] << " " ;

	  	while (true)
	  	{

	  		number = findNextOddValue (odd[0]) ;

	  		if ( ( (number + 1) == odd[1] ) || ((number + 2) == odd[1] ) )
	  		{
	  			cout << odd[1] << endl ;
	  			output << odd[1] << endl ;
	  			break ;
	  		}

            cout << number << " ";
            cout << number << " ";

           odd[0] = number ;

         i++ ;

         if ( i == ENTRIES)
         	break ;
     }

 }


 }



else 
cout << "Invalid command code " << endl ;

}

}

// end of the if statement corresponding to the code "o" ot " O "
 






	  else if ( code == 'F' || code == 'f')  // if code == F or f  , it asks the user to enter a command parameter ( an integer) stored in input1 and calls the function  
	    {									// the function factioral with that input .
	      int input1 ;
	      cout<<"Please enter command parameters: " ;
	      cin>>input1 ;
	      cout<<"factorial("<< input1 <<") "<<" = " << factorial(input1)<<endl ;
	    }

	  else if ( code == 'B' || code == 'b')  // if code == B or b , it asks the user to enter a command parameter ( an integer) stored in input2 and calls the function  
	    {									// the function fibonacci with that input .
	      int input2 ;							
	      cout<<"Please enter command parameters: " ;
	      cin>>input2 ;
	      cout<<"fibonacci("<<input2<<") "<<" = " << fibonacci(input2)<<endl ;
	    }







	  else  if ( code == 'R' || code == 'r') // code == R or r  , it promts the user to enter the parameters , which are 3 doubles stored in input3[3] array 
	    {									// it prints square root of the first number  to the square root of the final by delta incrementation and only stops for two reasons ( explained in the next part)
	      double input3[3];
	      cout<< "Please enter command parameters: ";
		for( int i = 0 ; i<3 ; i++ )
		  cin>> input3[i] ;   // stores the values in the array 
	      if ( input3[2] <= 0 || (input3[0] > input3[1]))  // if input3[2] ( delta ) <= 0 and input3[0] ( first ) > input3[0] (last)  then it prints no computation needed .
		cout<<"No computation needed."<< endl ;
	      else 
	      {
	      	int i = 0 ;
	      	while (true)    // infintie loop  that breaks only if a delta increment >= final or number of iteration of the calculation has exceeded 10 
	      	{
	      		if ( (input3[0]+ (input3[2]*i)) >= input3[1])
	      		{

	      			cout<<fixed << setprecision(4) << "Square root of "<< input3[1] << " = " << (findSqrtValue(input3[1]))<< endl ; // prints the square root of the final number and breaks the loop
	      			break ;
	      		}

	      		cout<<fixed << setprecision(4) << "Square root of "<< input3[0] + (input3[2]*i) << " = " << (findSqrtValue(input3[0] + (input3[2]*i)))<< endl ;
	      		// prints the square root of the first number at the first iterattion and  then the square root of the first by delta increments at successive iteration of the loop 
	      		i++ ;  

	      		if ( i == ENTRIES)   // breaks the loop if i == 10 ;
	      			break;

	      	}
	      }
	  }



	  else  if ( code == 'L' || code == 'l') // code == L or l  , it promts the user to enter the parameters , which are 3 doubles stored in input4[3] array 
	    {      								// it prints natural log of the first number  to the natural log of the final by delta incrementation and only stops for two reasons ( explained in the next part)
	      double input4[3];
	      cout<< "Please enter command parameters: " ;
		for( int i = 0 ; i<3 ; i++ )
		  cin>> input4[i] ;				 // stores the values in the array 
	      if ( input4[2] <= 0 || (input4[0] > input4[1]))  // if input4[2] ( delta ) <= 0 and input4[0] ( first ) > input4[1] (last)  then it prints no computation needed .
		cout<<"No computation needed."<< endl ;
	      else
	      {
	      	int i = 0 ;
	      	while (true)  // infintie loop  that breaks only if a delta increment >= final or number of iteration of the calculation has exceeded 10 
	      	{
	      		if ( (input4[0]+ (input4[2]*i)) >= input4[1])
	      		{

	      			cout<<fixed << setprecision(4) << "Natural log of "<< input4[1] << " = " << (naturalLog(input4[1]))<< endl ; // prints the natural log of the final number and breaks the loop
	      			break ;
	      		}

	      		cout<<fixed << setprecision(4) << "Natural log of "<< input4[0] + (input4[2]*i) << " = " << (naturalLog(input4[0] + (input4[2]*i)))<< endl ;
	      		i++ ; // prints the natural log of the first number at the first iterattion and  then the natural log of the first by delta increments at successive iteration of the loop 

	      		if ( i == ENTRIES)  // breaks the loop if i == 10 ;
	      			break;

	      	}
	      }
	  }


else  if ( code == 'N' || code == 'n')  // code == N or n  , it promts the user to enter the parameters , which are 3 doubles stored in input5[3] array 
	    {								// it prints nyancat value of the first number  to the nyancat value of the final by delta incrementation and only stops for two reasons ( explained in the next part)
	      double input5[3];
	      cout<< "Please enter command parameters: " ;
		for( int i = 0 ; i<3 ; i++ )
		  cin>> input5[i] ;			// stores the values in the array
	      if ( input5[2] <= 0 || (input5[0] > input5[1])) // if input5[2] ( delta ) <= 0 and input5[0] ( first ) > input5[1] (last)  then it prints no computation needed .
		cout<<"No computation needed."<< endl ;
	      else if (true)
	      {
	      	int i = 0 ;
	      	while (true)  // infintie loop  that breaks only if a delta increment >= final or number of iteration of the calculation has exceeded 10 
	      	{
	      		if ( (input5[0]+ (input5[2]*i)) >= input5[1])
	      		{

	      			cout<<fixed << setprecision(4) << "NyanCat value of "<< input5[1] << " = " << (findNyanCatValue(input5[1]))<< endl ; // prints the nyancat value of the final number and breaks the loop
	      			break ;
	      		}

	      		cout<<fixed << setprecision(4) << "Nyancat value of "<< input5[0] + (input5[2]*i) << " = " << (findNyanCatValue(input5[0] + (input5[2]*i)))<< endl ;
	      		i++ ;  // prints the nyancat value of the first number at the first iterattion and  then the nyancat value of the first by delta increments at successive iteration of the loop 

	      		if ( i == ENTRIES ) // breaks the loop if i == 10 ;
	      			break;

	      	}
	      }
	  }



	  else if ( code == 'D' || code == 'd')    // if code == D OR d , it promts the user to enter the parameters  ( two integers )
	  {											// this statement prints the first integer and the odd integers following until it reached the second integer ( final ) , it stops for two reason ( explained in the next part )
	  	int odd[2] ;
	  	cout<< "Please enter command parameters: " ;
	  	for ( int i = 0 ; i < 2 ; i++ )
	  		cin>> odd[i] ;   // those two integers are stored in the array odd[2]

	  	int number = 0 ;

		int i = 0 ; 
	  	cout<< odd[0] << " " ;

	  	while (true)
	  	{

	  		number = findNextOddValue (odd[0]) ;

	  		if ( ( (number + 1) == odd[1] ) || ((number + 2) == odd[1] ) ) // when the program feels like it is close to last number , it prints the last number and breaks .
	  		{
	  			cout << odd[1] << endl ;
	  			break ;
	  		}

            cout << number << " ";

           odd[0] = number ;

         i++ ;

         if ( i == ENTRIES)  // break if the has been more than 10 interations of the loop . 
         	break ;
     }

 }



	 
	} 
	
      else 
	{
	  cout << "Invalid command code" << endl ;  // prints an error message because the command code is invalid . 
	}

}


	return 0 ;

}






