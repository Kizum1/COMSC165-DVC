//******************************************************************
//Description: takes two parameters of miles and hours and calculates the mph.
//Author: Jay Chong
//COMSC 165 Section 5096
//Date February 1st, 2023
//Status: Complete
//*******************************************************************

#include <iostream>

#include <iomanip>

using namespace std;

// this is a declaration of the function to calculate the speed later
// mph has to be passed as a reference so that value is updated later when called
void calculatormph(double miles, double hours, double &mph);

int main() {
  double miles, hours, calculatedSpeed; // Variables to store miles, hours and speed

  // prompt the user to input miles traveled
  cout << "Please input the miles traveled\n";
  cin >> miles;

  // prompt the user to input hours traveled
  cout << "Please input the hours traveled\n";
  cin >> hours;

  // call on the function to calculate
  calculatormph(miles, hours, calculatedSpeed);

  // display the calculated speed to 2 decimal places by using setprecision() and the preprocessor directive iomanip
  cout << "Your speed is " << fixed << setprecision(2) << calculatedSpeed << " miles per hour\n";

  return 0;
}

// definition of the function to calculate the speed that was declared earlier
void calculatormph(double miles, double hours, double &mph) {
  mph = miles / hours;
}