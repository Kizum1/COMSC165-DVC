//******************************************************************
//Description: This program is used to gather statistical data on the number of movies
// that college students see in one month. It utilizes pointers and dynamic memory allocation
//Author: Jay Chong
//COMSC 165 Section 5096
//Date February 27th, 2023
//Status: Complete
//*******************************************************************

#include <iostream>

using namespace std;

// declaring function prototypes
double median(int * , int);
int mode(int * , int);
int * makeArray(int);
void getMovieData(int * , int);
void selectionSort(int[], int);
double average(int * , int);

int main() {
  // declaring one pointer, and two variables
  int * movieData, num, mod;

  // getting the number of students and assigning it to num
  cout << "How many students were surveyed? ";
  cin >> num;

  // creating an array with dynamically allocated memory
  movieData = makeArray(num);

  // get the movie data and store into an array
  getMovieData(movieData, num);

  // sort the array in ascending order using a selection sort algorithm
  selectionSort(movieData, num);

  // display the results
  cout << "The average number of movies seen is ";
  cout << average(movieData, num) << endl;
  cout << "The median of the number of movies seen is ";
  cout << median(movieData, num) << endl;
  cout << "The mode of the number of movies seen is: ";
  mod = mode(movieData, num);

  // calculating the mod of the number of movies seen
  if (mod == -1)
    cout << "The set has no mode. \n";
  else
    cout << "The mode is " << mod << endl;
  // free the allocated memory
  delete[] movieData;
  movieData = 0;
}
// this function will dynamically allocate memory for the array of a size
int * makeArray(int size) {
  int * ptr;

  ptr = new int[size];

  return ptr;
}

// get the movie data from the user, and store into an array
void getMovieData(int arr[], int num) {
  cout << "Enter the number of movies each student saw. \n";

  for (int count = 0; count < num; count++) {
    cout << "Student " << (count + 1) << ": ";
    cin >> arr[count];
  }
}

// this uses the selection sort algorithm to sort the array
void selectionSort(int values[], int size) {
  int startScan, minIndex, minValue;

  for (startScan = 0; startScan < (size - 1); startScan++) {
    minIndex = startScan;
    minValue = values[startScan];
    for (int index = startScan + 1; index < size; index++) {
      if (values[index] < minValue) {
        minValue = values[index];
        minIndex = index;
      }
    }
    values[minIndex] = values[startScan];
    values[startScan] = minValue;
  }
}

// function to calculate the median of an array of integers
double median(int * arr, int num) {
  double med;

  // if the array size is even then the median is the average of the middle values
  if (num % 2 == 0) {
    int mid1 = num / 2;
    int mid2 = (num / 2) - 1;
    med = (( * (arr + mid1) + * (arr + mid2)) / 2.0);
  }
  // if the size is odd, then the median is the very middle value
  else
    med = * (arr + (num / 2));
  return med;
}

int mode(int * arr, int num) {
  int * freq, highest, elem, count;
  // allocate an array of integers 
  freq = makeArray(num);
  // initialize all elements in the array to zero
  for (count = 0; count < num; count++)
    freq[count] = 0;
  // this for loop will determine the frequency of each element by comparison
  for (int count1 = 0; count1 < num; count1++) {
    for (int count2 = 0; count2 < num; count2++) {
      if ( * (arr + count2) == * (arr + count1))
        ( * (freq + count1)) ++;
    }
  }
  // determine the highest frequency in the array
  highest = * freq;
  elem = 0;

  for (count = 1; count < num; count++) {
    if ( * (freq + count) > highest) {
      highest = * (freq + count);
      elem = count;
    }
  }

  // if the input array occurs once then there is no mode
  if (highest == 1)
    return -1;
  else
    return * (arr + elem);
}

double average(int arr[], int num) {
  int total = 0;
  double ave;

  // calculate the sum of all the elements in the input array
  for (int count = 0; count < num; count++) {
    total += arr[count];
  }
  // calculate the average of the elements
  ave = total / static_cast < double > (num);

  return ave;
}