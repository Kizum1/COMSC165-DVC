//******************************************************************
//Description: This program prompts the user for a number of elements up to 50 and then will search for the number
// that was inputted by using a binary search.
//Author: Jay Chong
//COMSC 165 Section 5096
//Date February 20th, 2023
//Status: Complete
//*******************************************************************
#include <iostream>
#include <iomanip>


using namespace std;
// declare a max array size for later
const int MAX_SIZE = 50;

// declaring function prototypes along with their necessary values needed
void searchNumber(int elements[], int size, int searchNum);
void sortnumber(int elements[], int size);
double meanCalculator(int elements[], int size);

int main() {
  // declare both a size and searchNum
  int size;
  int searchNum;
  // input the desire amount of elements into the variable size
  cout << "Input the number of elements: ";
  cin >> size;
  // if that amount is bigger than the max, then reprompt
  if (size >= MAX_SIZE) {
    cout << "Size is too big, please enter a value below 50 " << endl;
    cout << "Input the number of elements: ";
    cin >> size;
  }
  // declare an array with the inputted size
  int elements[size];
  // this for loop serves to put each number into the element array
  for (int i = 0; i < size; i++) {
    cout << "Enter a number " << i + 1 << endl;
    cin >> elements[i];
  }
  // this will print out the original array before being sorted
  cout << "Original array: ";
  for (int i = 0; i < size; i++) {
    cout << elements[i] << " ";
  }
  cout << endl;
  // we call the sortnumber function in between so that the next for loop will print a sorted array
  sortnumber(elements, size);
  // prompt for a number to look for inside the array and assign in to searchNum
  cout << "What number do you want to look for? " << endl;
  cin >> searchNum;
  // print the sorted array after the sortnumber function has ran
  cout << "Sorted array: ";
  for (int i = 0; i < size; i++) {
    cout << elements[i] << " ";
  }
  cout << endl;
  // call the searchNumber function
  searchNumber(elements, size, searchNum);
  // call the meanCalculator function
  meanCalculator(elements, size);
  return 0;
}
// this is the bubble sort algorithm to sort the temperatures in ascending order
// the bubble sort works by comparing adjacent temperatures and swapping them if they are in the wrong order.
void sortnumber(int elements[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      // if the temperature of index j is less than index i then…
      if (elements[i] > elements[j]) {
        // set index i = temp
        int temp = elements[i];
        // set index j = i
        elements[i] = elements[j];
        // finally set temp equal to index j and continue
        elements[j] = temp;
      }
    }
  }
}

// this is the binery search algorithm which searches for the number in a sorted array
void searchNumber(int elements[], int size, int searchNum) {
  int l = 0; // first pointer for the first element
  int r = size - 1; // pointer for the last element
  int m; // a variable to store the middle index

  // while l is less than or equal to r
  while (l <= r) {
    // calculate m
    m = (l + r) / 2;
    // if the element[m] matches the inputted searchNum then display results
    if (elements[m] == searchNum) {
      cout << "The size of the array was " << size << endl;
      // we use m here instead of m+1 because in an array the index starts at 0 not 1.
      cout << "Your number " << searchNum << " was found at position " << m << " in the sorted array." << endl;
      return;
      // if it is less than move the firsst pointer up by 1
    } else if (elements[m] < searchNum) {
      l = m + 1;
      // otherwise move it down by 1 and repeat the while loop
    } else {
      r = m - 1;
    }
  }
  // if nothing is found then print this error message
  cout << "The number " << searchNum << " was not found in the array." << endl;
}

// function to calculate the average
double meanCalculator(int elements[], int size) {
  int total = 0;
  for (int i = 0; i < size; i++) {
    // add the temperatures to sum
    total += elements[i];
  }
  // divide the total sum by its size to get the average
  double mean = (double)total / size;
  // display the result with 2 decimal places.
  cout << "The mean of the data set is " << fixed << setprecision(2) << mean << endl;
  return mean;
}