//************************************************************************
//Description: A program to input number of tellers and their sick days for the last 3 years and output the total tellers and total sick days.
//Author: Jay Chong
//COMSC 165 Section 5096
//Date January 31, 2023
//Status: Complete
//************************************************************************
#include <iostream>
using namespace std;

int main()
{
	// two variables needed to keep track of the number of tellers and the total sick days
	int numofTeller, sickDays = 0;

	cout << "How many tellers worked at Nation’s Bank during each of the last"
	" three years ?\n";
	cin >> numofTeller;
	// this for loop is required to increment the tellers number up to how many were inputted
	for (int countTeller = 1; countTeller <= numofTeller; countTeller++)
	{
		// this for loop is required to increment the years up to 3 as stated in the assignment
		for (int yearCount = 1; yearCount <= 3; yearCount++)
		{
			//this sickdayCount will be used to keep track of the user input of how many sick days for each teller and their year
			int sickdayCount = 0;
			cout << "How many days was teller " << countTeller <<
				" out sick during year " << yearCount << " ?\n";
			cin >> sickdayCount;
			// once an a value is given, keep adding it to sickDays until the loop terminates
			sickDays += sickdayCount;
		}
	}

	// display all results
	cout << "\nThe " << numofTeller << " tellers were out sick for a total of " <<
		sickDays << " days during the last 3 years.\n";

	return 0;
}