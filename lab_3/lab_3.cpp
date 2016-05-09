/*
 * Name        : lab_3.cpp
 * Author      : Jason K Lamphere
 * Description : Using branching statements, looping statements and string and
 *               character functions complete the functions
 */

#include "lab_3.h"

/*
 * Tell the story of Goldilocks. For example, if item is "bed" and number is 1,
 * the story will say "This bed is too soft". "item" parameter will be passed
 * in as all lowercase characters
 * Cases:
 * -item: "porridge", number: 1, return "This porridge is too hot"
 * -item: "porridge", number: 2, return "This porridge is too cold"
 * -item: "porridge", number: 3, return "This porridge is just right"
 * -item: "chair", number: 1, return "This chair is too big"
 * -item: "chair", number: 2, return "This chair is too small"
 * -item: "chair", number: 3, return "This chair is just right"
 * -item: "bed", number: 1, return "This bed is too hard"
 * -item: "bed", number: 2, return "This bed is too soft"
 * -item: "bed", number: 3, return "This bed is just right"
 * @param string item - Represents the item in the story ("porridge", "chair",
 *                      and "bed" are the only legal values -- will default to
 *                      "bed" on invalid argument)
 * @param int number - which item (1, 2, and 3 are the only legal values -- will
 *                     default to 3 on invalid argument)
 * @return string - The output string specified in the documentation above
 */
 
 
/*
string Goldilocks(string item, int number) {
  // CODE HERE
  if(item == "porridge"){
  switch(number){
    case 1: 
	  
	  return "This porridge is too hot";
	  break;
	case 2:
	  return "This porridge is too cold";
	  break;
	default:
	  return "This porridge is just right";
  }
  }else if(item == "chair"){
  switch(number){
    case 1: 
	  return "This chair is too big";
	  break;
	case 2:
	  return "This chair is too small";
	  break;
	default:
	  return "This chair is just right";
  }
  }else{
  switch(number){
    case 1: 
	  return "This bed is too hard";
	  break;
	case 2:
	  return "This bed is too soft";
	  break;
	default:
	  return "This bed is just right";
  }
  }
}

*/
string Goldilocks(string item, int number)      // Please note I have another version of this function commented out directly above if this one does not work
{												// 
  
   string out = "";
  if(item == "porridge")
  {
  	switch(number)
  	{
    	case 1: 
    	{
     		out = "this porridge is too hot" ;
    		break;
		 }
		case 2:
		{
			
			 out = "This porridge is too cold";
			 break;
		}
		case 3:
		{
			out = "This porridge is just right";
	  	
			
		}
	
  	}
  	
  }
  else if(item == "chair")
  {
  	switch(number)
  	{
    	case 1: 
    	{
     		out = "This chair is too big";
    		break;
		 }
		case 2:
		{
			out = "This chair is too small";
			break;
		}
		case 3:
		{
			out = "This chair is just right";
	  		break;
			
		}
	
  	}
  
  }
  else if(item == "bed")
  {
  	switch(number)
  	{
    	case 1: 
    	{
     		out = "This bed is too hard!" ;
    		break;
		 }
		case 2:
		{
			out = "This bed is too soft!";
		
			 break;
		}
		case 3:
		{
			out = "This bed is just right!";
	  		
			
		}
	
  	}
  	
  }
  cout << out << endl;
  return out;
} 
  
 
  
  
  
  
 
	int main()      //for testing
	{ 
		string item_choice;
		int item_number;
		char p1, p2;
		cout <<" porridge, chair, or bed? "<< endl;
		cin >> item_choice;
		cout << item_choice << " number 1, 2, or 3?"<< endl;
		cin >> item_number;
		
	Goldilocks(item_choice, item_number);
	cout <<"Player One Choose"<<endl;
	cin >> p1;
	cout <<"Player Two Choose"<< endl;
	cin >> p2;
	RockScissorPaper(p1,p2);
	
	return 0;
	}



/*
 * Compute the outcome of a round of a rock-scissor-paper game. Lowercase or
 * uppercase values for player_one and player_two arguments are acceptable.
 * Possible inputs: 'R' rock, 'S' scissor, 'P' paper
 * Conditions
 * -rocks beats scissors
 * -scissors beats paper
 * -paper beats rock
 * @param char player_one - Represents player one's "play" ('R', 'S', or 'P')
 * @param char player_two - Represents player two's "play" ('R', 'S', or 'P')
 * @return int - 1 if player one wins, 2 if player two wins, 3 on a draw,
 *               0 if invalud inputs
 */
int RockScissorPaper(char player_one, char player_two) // takes in user selection of rock paper scissors for two players and determines the winner. 
{
  // YOU MUST USE A SWITCH IN THIS FUNCTION
  // CODE HERE
  player_one = toupper(player_one);
  player_two = toupper(player_two);
  switch(player_one){
    case 'R':
    {
	  if(player_two == 'S')
	  {	cout << "result" << 1;
	    return 1;
	  }
	  else if(player_two == 'P')
	  {	cout << 2 << endl;
	    return 2;
	  }  
	  else
	  {	cout <<3 << endl;
	    return 3;
	break;
	  }
    }
	case 'S':
	{
	  if(player_two == 'P')
	  {	cout << 1 << endl;
	    return 1;}
	  else if(player_two == 'R')
	  {	cout <<  2 << endl;
	    return 2;}
	  else
	  {cout << 3 << endl;
	    return 3;
	break;
	  	
	  }
		
	}
	case 'P':
	{
	  if(player_two == 'R')
	  {	cout << 1 << endl;
	    return 1;}
	  else if(player_two == 'S')
	  {	cout << 2 << endl; 
	    return 2;}
	  else
	 { cout << 3 << endl;
	    return 3;
	break;}}
  }
  return 0;
}

/*
 * Return the input string with all characters converted to lowercase.
 * @param string input - The string that will be converted to all lowercase
 * @return string - a string containing the converted input string
 */
string ToLower(string input) {   //using the tolower and toupper functiosn which change single characters i have it loop through the string positions one at a time applying the case choosen. 
  // CODE HERE
  for(unsigned int i = 0; i <input.length(); i++)
  input.at(i) = tolower(input.at(i));
  cout << input << endl;
  return input;
}

/*
 * Return the input string with all characters converted to uppercase.
 * @param string input - The string that will be converted to all uppercase
 * @return string - a string containing the converted input string
 */
string ToUpper(string input) {
  // CODE HERE
  for(unsigned int i = 0; i <input.length(); i++)
  input.at(i) = toupper(input.at(i));
  cout << input << endl;
  return input;
}
