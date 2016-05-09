 /*
 * Name        : Assignment 1
 * Author      : Jason K Lamphere
 * Description : Counts , Encrypts, Averages, Decrypts, and Sorts max min values for strings
 * Sources     : http://www.tenouk.com/cpluscodesnippet/cplusasciicharintergerrep.html, http://www.rowanwatson.com/c-caesar-cipher/
 */

#include "assignment_1.h"

// Write Function Definitions Here (What goes below main)

int CountWords( const string &my_string){
     int count = 0;                                     //creates counter
     for (int i = 0; i <my_string.length();i++){        //loops through string char by char
       if (my_string.at(i) == ' '){                     // if it finds a space add a count
       count++;
       }
     }
     if (my_string.length()> 0 ){                    //if the string has any lenght we can always assume one word more than there are spaces. 
            count++;
     }
    return count;
}

bool CheckAlphabetic(const string &my_string) {
    if(my_string == ""){   //empty string passes isalpha so we have to check specifically for emtpy cases.
        return false;
    }
    for (unsigned int i = 0; i < my_string.length(); i++) { //rotates through string from space 0 to last space
     if (isalpha(my_string.at(i)) == false ) {            //if it finds an non alphabetic char it ends returning false
       return false;
     }
    }                                              //if it rotates through with out finding a non alphabet character it returns true
  return true;
}

bool EncryptString(string &my_string, int shift_num) {
    if (CheckAlphabetic(my_string)== true){              // we don't want our encryption to proceed if its not alphabetic so we use our previous function
      for (unsigned int i = 0; i < my_string.length(); i++){
        if(isupper(my_string[i])){ 
        my_string[i] -=65;                              // we are going to modulo by 26 the size of the alphabet to find our end position from a to z. in order for it to work we have to convert our range from 65-90 to 0-25
        my_string[i] = (my_string[i]+shift_num)%26;
          if(my_string[i]<0){                              // if your shift results in a negative value you add 26 to compensate to find the numerical position
          my_string[i]+=26;
          } 
        my_string[i] +=65;                              // 0-25 don't actually corrispond to alphabet values so we have to reverse our first step by adding 65
        }
        if(islower(my_string[i])){                           // if we have a lower case value we have to compensate by a larger value of 97 to get our range of 0-25
        my_string[i] -=97;
        my_string[i] = (my_string[i]+shift_num)%26;
          if(my_string[i]<0){
          my_string[i]+=26;
          }
        my_string[i] +=97;
        }
      }return true;
    }else return false;
}

bool DecryptString(string &my_string, int shift_num) {                  //same as our encrypt with the shift value subtracted we can save space my simply running our encrypt function with a negetive shift. 

  EncryptString(my_string, -shift_num);

}

double ComputeAverage(double d_array[], unsigned int array_size) {
    double average = 0;
    for (unsigned int i = 0; i < array_size; i++) {
        average += d_array[i];                          //adds up all positions in array
    }
   double x = average/array_size;                        //divides by array size to find avg
    return x;
}

double FindMinValue(double d_array[], unsigned int array_size) {
    double minimum = d_array[0];
    for (unsigned int i = 1; i < array_size; i++) {               //goes through array, every time it finds a smaller value than the one stored in minimum it replaces it
        if (d_array[i] < minimum)
            minimum = d_array[i];
    }
    return minimum;
}

double FindMaxValue(double d_array[], unsigned int array_size) {    // same as find min but larger values
    double maximum = d_array[0];
    for (unsigned int i = 1; i < array_size; i++) {
        if (d_array[i] > maximum)
            maximum = d_array[i];
    }
    return maximum;
}
