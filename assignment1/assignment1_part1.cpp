//******************************************************************
//Description: This program tallies votes on beverages until terminated, after which the result of the votes are printed
//Author: Jay Chong
//COMSC 165 Section 5096
//Date January 24, 2023
//Status: Complete
//*******************************************************************

#include <iostream>

using namespace std;

int main() {
  // individual variables are needed for each beverage 
  int coffeeTally = 0, teaTally = 0, cokeTally = 0, ojTally = 0;

  // these variables are needed to compare the user input to corresponding drink and to count the person #
  int tally, personNum;

// this for loop carries 3 statements that are required to keep the program looping until terminated
  for (personNum = 1; tally != -1; personNum++) {

    // display text, and grab the input and set it to to the variable tally
    cout << "Please input the favorite beverage of person #" << personNum << ": Choose 1, 2, 3, or 4 from the above menu or -1 to exit the program" << endl;
    cin >> tally;

    // these if statement serve to increment each tally based on what the input was
    if (tally == 1) {
      coffeeTally++;

    } else if (tally == 2) {
      teaTally++;

    } else if (tally == 3) {
      cokeTally++;

    } else if (tally == 4) {
      ojTally++;

    // if the input was -1 then exit the loop and display results
    } else if (tally == -1) {
      break;
      
    // if any other choice was inputted then display Invalid Choice and continue the loop
    } else {
      cout << "Invalid Choices" << endl;
      continue;
    }

  }

// display all results at the end. 
  cout << "The total number of people surveyed is " << personNum << ". The results are as follows:" << endl;
  cout << "Beverage Number of Votes" << endl;
  cout << "********************************" << endl;
  cout << "Coffee: " << coffeeTally << endl;
  cout << "Tea: " << teaTally << endl;
  cout << "Coke: " << cokeTally << endl;
  cout << "Orange Juice: " << ojTally << endl;

  return 0;
}