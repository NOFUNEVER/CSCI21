/*
 * Name        : lab_4.cpp
 * Author      : Jason K Lamphere
 * Description : Use branching statements, looping statements and string and
 *               character functions to complete the functions
 */

#include "lab_4.h"

/*
 * Return a string comprised of a label, followed by a space, followed by a
 * separator character, followed by a space, followed by a floating-point value.
 * For example, label="Temperature", value=41.7, separator=':' will return
 * "Temperature : 41.7".
 * @uses stringstream.
 * @param string label - The label for the value
 * @param double value - The value associated with the label
 * @param char separator - The character that separates the label and the value
 * @return string - Comprised of a label, followed by a space, followed by a
 *                  separator character, followed by a space, followed by a
 *                  floating-point value
 */
 
 
 
string MakeString(string label, double value, char separator) {
  // CODE HERE
    stringstream ss;                                              // creates string stream object that can be used to collect input strings for use.
  ss << label << " " << separator << " " << value;
  return ss.str();                                                // makes a string out of what is currently stored in the stream and returns it
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Return the first character of a length 1 string. If the value is of
 * length 0 or of length > 1, return the null character ('\0').
 * @param string value - The expected single character
 * @return char - The first character of the string or null character ('\0')
 *                when value is length 0 or value is length > 1
 */
char StringToChar(string value) {
  // CODE HERE
  if (value.length() == 1)      //checks to make sure value is only 1 and returns if it confirms. else returns null.
    return value.at(0);
  else
    return '\0';
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an expected integer value (such as a string
 * captured from stdin) into an integer. If value is not valid as an integer,
 * return 0.
 * @uses stringstream
 * @param string value - The expected integer value
 * @return int - An integer representing the value, or 0 on failure
 */
int StringToInt(string value) {
  // THIS FUNCTION PROVIDED AS AN EXAMPLE AND IS ALREADY COMPLETE!
  int ivalue = 0;
  stringstream converter(value);           //creates string stream object named converter
  converter.exceptions(ios_base::failbit);    // creates and exception whenever the failbit is triggered.
 

  try {
    converter >> ivalue; // attempts to extract the integer from the stream. if failbit triggered it is caught andrecorded. else it returns the collected ivalue
  } catch (ios_base::failure f) {
  }

  return ivalue;
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an expected floating-point value (such as a
 * string captured from stdin) into a double. If value is not valid as a double
 * return 0.
 * @uses stringstream
 * @param string value - The expected floating-point value
 * @return double - A double representing the value, or 0 on failure
 */
double StringToDouble(string value) {
  // CODE HERE
  double ivalue = 0.0;
  stringstream converter(value);              //creates string stream object to store input.
  converter.exceptions(ios_base::failbit);    //creats and exception incase converter fails.
  try {
    converter >> ivalue;                      //attempts to extract double from stream
  } catch (ios_base::failure f) {             //catch records if a failbit triggers an exception and stores it preventing run time errors
  }

  return ivalue;
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an boolean value (such as a string captured from
 * stdin) into a bool. Return true if the first character is 'T'
 * (case-insensitive), false if the first character is 'F' (case-insensitive),
 * and false on anything else.
 * @param string value - The expected string to start with either 'T' or 'F'
 * @return bool - If the first character is 'T' (case-insensitive) return true.
 *                If the first character is 'F' (case-insensitive) return false.
 *                Return false on anything else.
 */
bool StringToBool(string value) {
  // CODE HERE
  
  
  bool bvalue = false;
   
   
       for(int i = 0; i < value.length(); i++) //walks through value
    {
        value[i] = tolower(value[i]); //puts all characters to lower case
    }
    
    
    stringstream converter(value);
    converter.exceptions(ios_base::failbit);

    try
    {
        converter >> std::boolalpha >> bvalue; // storing as alphanumeric instead of an integer
    }
    catch (ios_base::failure f)
    {
    }
    
    return bvalue;
  
  
}


