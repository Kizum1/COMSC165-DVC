//******************************************************************
//Description: Takes the average of X amount of grades and their respective percents and displays
// a final grade based on what the average was
//Author: Jay Chong
//COMSC 165 Section 5096
//Date February 1st, 2023
//Status: Complete
//*******************************************************************

#include <iostream>

using namespace std;

// a declaration of the function
void calculateAverage(float, int, float & );

int main() {
  // to store the grades inputted
  int inGrades;
  //store each 
  float grade, average, sumGrade;

  cout << "Enter the number of grades " << endl;
  cin >> inGrades;

  // a simple for loop that totals all the grades inputted
  for (int i = 0; i < inGrades; i++) {
    cout << "Enter a grade " << endl;
    cin >> grade;

    sumGrade = sumGrade + grade;
  }
  // call the function to calculate average
  calculateAverage(sumGrade, inGrades, average);
  cout << "The grade is ";
  // using if-else statements we can determine what the grade is
  if (average >= 90) {
    cout << "A";
  } else if (average >= 80) {
    cout << "B";
  } else if (average >= 70) {
    cout << "C";
  } else if (average >= 60) {
    cout << "D";
  } else {
    cout << "F" << endl;
  }
}

// function to calculate the average of the grades entered by the user
void calculateAverage(float sumGrade, int inGrade, float & average) {
  average = sumGrade / inGrade;
}