//******************************************************************
//Description: Modified the program so the pins are vectors not arrays
//Author: Jay Chong
//COMSC 165 Section 5096
//Date February 9th, 2023
//Status: Complete
//*******************************************************************
#include <vector>


#include <iostream>


using namespace std;


bool testPIN(const vector < int > & custPIN,
  const vector < int > & databasePIN) {
  if (custPIN.size() != databasePIN.size())
    return false;
  for (int index = 0; index < custPIN.size(); index++) {
    if (custPIN[index] != databasePIN[index])
      return false;
  }
  return true;
}


int main() {
// we just need to use the newly imported vector directive and then use vector<int> to change from array to vector
vector<int> pin1 = {2, 4, 1, 8, 7, 9, 0};
vector<int> pin2 = {2, 4, 6, 8, 7, 9, 0};
vector<int> pin3 = {1, 2, 3, 4, 5, 6, 7};
  if (testPIN(pin1, pin2))
    cout << "ERROR: pin1 and pin2 report to be the same.\n";
  else
    cout << "SUCCESS: pin1 and pin2 are different.\n";
  if (testPIN(pin1, pin3))
    cout << "ERROR: pin1 and pin3 report to be the same.\n";
  else
    cout << "SUCCESS: pin1 and pin3 are different.\n";
  if (testPIN(pin1, pin1))
    cout << "SUCCESS: pin1 and pin1 report to be the same.\n";
  else
    cout << "ERROR: pin1 and pin1 report to be different.\n";
  return 0;
}
