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
	
if (!(num / 10)) return (num);
    return (num % 10 + binToDec(num / 10) * 2); 
	
	
}


int main()
{
	
	int choice = 0;
	int value = 0;
	bool play = 1;
	
	
cout<< "Welcome to base conversion Tool!" << endl;

while(play){
cout<< "Please make a Choice!" << endl;
cout<< "1: Decimal To Binary"<<endl;
cout<< "2: Binary To Decimal"<<endl;

cin >> choice;
while(choice < 1 | choice> 2){
	
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
