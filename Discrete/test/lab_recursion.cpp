/*
 * Name        : lab_recursion.cpp
 * Author      : YOUR NAME
 * Description : Recursive Functions
 */

#include "lab_recursion.h"

// CODE FUNCTION DEFINITIONS HERE

/*
 * UPDATE!!!! to match the requirements
 * Convert a decimal number to binary
 * @param number to be converted.
 * @return a stringstream.
 */
int decToBin(int num)
{
	if (num > 1) //note this makes the base case num = 0
	{
		decToBin(num/2); //recursive call
	}

	cout<<(num%2); //outputs in correct order
}




int binToDec(int num){
	
if (!(num / 10))
return (num);
return (num % 10 + binToDec(num / 10) * 2); 

}



double schoolCost(int year, double cost, double interest){
    if(year>1995){
      
    
    cost = (cost*interest);
    year--  ; 
    interest = interest + (.0313/5); //interest rate climbs from 1.0786 
  schoolCost(year, cost);            //during 1985-1990 to 1.10998 during 1990-1995
   									// so every 5 years our interest rate climbs .0313 and every year .0313/5
  }else   
  return cost;
}
    




int main()
{
	
	int choice = 0;
	int value = 0;
	bool play = 1;
	double start;
	
	
cout<< "Welcome to base conversion Tool!" << endl;

while(play){
cout<< "Please make a Choice!" << endl;
cout<< "1: Decimal To Binary"<<endl;
cout<< "2: Binary To Decimal"<<endl;
cout<< "3: School Cost Prediction"<<endl;

cin >> choice;
while(choice < 1 | choice> 3){
	
	cout << "please make a selection"<<endl;
	cin >> choice;
}

if(choice == 1){
	
cout<<" Input Decimal Value You would like to convert"	<<endl;
cin >> value;
decToBin(value);
cout<<endl;

}
if(choice == 2){
	
cout<<" Input Binary Value you would like to convert"	<<endl;
cin >> value;
cout<<binToDec(value)<<endl;

}
if(choice == 3){
	
cout<<" Input Year to Predict"	<<endl;
cin >> value;
cout<<"if it cost $12300 per year of school in 1995 " << endl;

cout<<"we predict it will cost " <<schoolCost(value)<< " in the year "<< value <<endl;

}



cout<< "Would you Like to Play Again!" << endl;
cout<< "1: Yes"<<endl;
cout<< "0: No"<<endl;
cin >> play;
while(play < 0 | play> 1){
	
	cout << "please make a selection"<<endl;
	cin >> play;
}

	
	
	
}
	
return 0;	
}
