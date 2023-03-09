//******************************************************************
//Description: This program inputs and stores temperatures for consecutive days in an array, sorts the array in ascending order.
//Author: Jay Chong
//COMSC 165 Section 5096
//Date February 9th, 2023
//Status: Complete
//*******************************************************************
#include <iostream>
#include <iomanip>


using namespace std;
const int MAX_SIZE = 11;

// function declaration
void inputTemp(int temperatures[], int size);
void sortTemperatures(int temperatures[], int size);
double calculateAverage(int temperatures[], int size);

int main() {
  int size;
  cout << "Enter the number of temperatures: ";
  cin >> size;
  // simple function to check if temperature is within the given max limit
  if (size >= MAX_SIZE) {
    cout << "Size is too big, please enter a value below 11 " << endl;
    cout << "Enter the number of temperatures: ";
    cin >> size;
  }
  int temperatures[size];


  // call function to input temperatures
  inputTemp(temperatures, size);
  // call function to calculate the average and print out to two decimal places
  double average = calculateAverage(temperatures, size);
  cout << "The average temperature is: " << fixed << setprecision(2) << average << endl;
  // call function to sort temperatures
  sortTemperatures(temperatures, size);


  return 0;
}

// function for storing the inputted temperatures in an array
void inputTemp(int temperatures[], int size) {
  cout << "Enter the temperatures: " << endl;
  for (int i = 0; i < size; i++) {
    cin >> temperatures[i];
  }
}


// function to calculate the average
double calculateAverage(int temperatures[], int size) {
  double sum;
  for (int i = 0; i < size; i++) {
    // add the temperatures to sum
    sum += temperatures[i];
  }
  // divide the total sum by its size to get the average
  return sum / size;
}


// this is the bubble sort algorithm to sort the temperatures in ascending order
void sortTemperatures(int temperatures[], int size) {
  int temp;
  for (int i = 0; i < size; i++) {
    // the bubble sort works by comparing adjacent temperatures and swapping them if they are in the wrong order. Pretty inefficient! but it will do for this lab
    for (int j = i + 1; j < size; j++) {
      // if the temperature of index j is less than index i then…
      if (temperatures[j] < temperatures[i]) {
        // set index i = temp
        temp = temperatures[i];
        // set index j = i
        temperatures[i] = temperatures[j];
        // finally set temp equal to index j and continue
        temperatures[j] = temp;
      }
    }
  }
}