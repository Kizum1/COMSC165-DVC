//******************************************************************
//Description: This program will wap two floating point numbers stored
// in "first" and "second" using a function "swap" with formal parameters "number1" and "number2."
//Author: Jay Chong
//COMSC 165 Section 5096
//Date February 1st, 2023
//Status: Complete
//*******************************************************************

#include <iostream>

using namespace std;

//declare a function called swap_function which will accept two parameters of V of any type!
void swap_function(double &firstValue, double &secondValue);

int main() {
  // declared these two variables as double because the assignment asked for the inclusion floating point numbers
  double firstValue, secondValue;

  //these 4 lines serve to get the input from the user about firstValue and secondValue
  cout << "Enter the first number\nThen hit enter\n";
  cin >> firstValue;
  cout << "Enter the second number\nThen hit enter\n";
  cin >> secondValue;

  //call the swap function with the two arguments given
  swap_function(firstValue, secondValue);

  //display results
  cout << "You input the numbers as " << secondValue << " and " << firstValue << endl;
  cout << "After swapping, the first number has the value of " << firstValue << endl;
  cout << "which was the value of the second number" << endl;
  cout << "The second number has the value of " << secondValue << endl;
  cout << "which was the value of the first number" << endl;

  return 0;
}
//the implementation of the swap_function that I declared at the top of the code
void swap_function(double &firstValue, double &secondValue) {
    double tmp = firstValue;
    firstValue = secondValue;
    secondValue = tmp;
}