//******************************************************************
//Description: Pig Latin. 
//Author: Jay Chong
//COMSC 165 Section 5096
//Date March 12th, 2023
//Status: Complete
//*******************************************************************

#include <iostream>
#include <string>
#include <cstring>

using namespace std;
const int SIZE = 80;

void append(char[]);
void find(char[]);
void insert(char[]);
void replace(char[]);
void deleteChar(char[]);
int search (char sourceString [], char targetString []);

int main() {
    char option;
    char buffer[SIZE];

    string menu = "s-search, i-insert, d-delete, r-replace, a-append, e-exit";

    cout << "Enter a string you would like to edit " << endl;
    cin.getline(buffer, SIZE);

    cout << menu << endl;
    cin >> option;
    cin.ignore();

    while(option != 'o') {
        switch (option) {
            case 's':
                find(buffer);
                break;
            case 'i':
                insert(buffer);
                break;
            case 'a':
                append(buffer);
                break;
            case 'd':
                deleteChar(buffer);
                break;
            case 'r':
                replace(buffer);
                break;
            default: cout << "Invalid" << endl;
        }
        cout << menu << endl;
        cin >> option;
        cin.ignore();
    }
    return 0;
}

void append(char buffer[]) {
    char toappend[SIZE];
    char empty[SIZE] = " ";

    cout << "Enter the string to be appended" << endl;
    cin.getline(toappend, SIZE);

    strcat(buffer, empty);
    strcat(buffer, toappend);

    cout << "The new string is " << buffer << endl;
}

void find(char buffer[]) {
    char tosearch[SIZE];
    int found;
    cout << "Enter the substring to be searched" << endl;
    cin.getline(tosearch, SIZE);
    found = search(buffer, tosearch);
    if (found == -1)
        cout << "The substring was not found" << endl;
    else
        cout << "The substring was found at position " << found << endl;
        cout << endl;
    cout << "The new string is " << buffer << endl;
}

void insert(char buffer[]) {
    char toinsert[SIZE];
    char empty[SIZE] = " ";
    int position;
    char temp[SIZE];
    cout << "Enter the string to be inserted" << endl;
    cin.getline(toinsert, SIZE);
    cout << "Enter the position to insert the string" << endl;
    cin >> position;
    cin.ignore();

    strcpy(temp, &buffer[position]);
    buffer[position] = '\0';
    strcat(buffer, empty);
    strcat(buffer, toinsert);
    strcat(buffer, temp);
    cout << "The new string is " << buffer << endl;
}

void deleteChar(char buffer[]) {
    char todelete[SIZE];
    int position;
    char empty[SIZE] = " ";
    char temp[SIZE];
    cout << "Enter the position to delete the string" << endl;
    cin.getline(todelete, SIZE);
    position = search(buffer, todelete);

    if (position == -1) 
        cout << "The substring does not exist" << endl;
    else {
        strcpy(temp, &buffer[position + strlen(todelete)]);
        buffer[position] = '\0';
        strcat(buffer, temp);
        cout << "The updated string is " << buffer << endl;
    }
}

void replace(char buffer[]) {
    char toreplace[SIZE];
    char newsubstring[SIZE];
    char temp[SIZE];
    int found;
    char empty[SIZE] = " ";
    cout << "Enter the substring to be replaced" << endl;
    cin.getline(toreplace, SIZE);
    cout << "Enter the new substring" << endl;
    cin.getline(newsubstring, SIZE);
    found = search(buffer, toreplace);
    if (found == -1)
    cout << "The string you want to replace does not exist" << endl;
    else {
        strcpy(temp, &buffer[found + strlen(toreplace)]);
        buffer[found] = '\0';
        strcat(buffer, empty);
        strcat(buffer, newsubstring);
        strcat(buffer, temp);
        cout << "The updated string is " << buffer << endl;
    }
}

int search (char sourceString [], char targetString []) {
    int sourceLength, targetLength, index, returnValue;
    sourceLength = strlen(sourceString);
    targetLength = strlen(targetString);
    index = -1;
    for (int i = 0; i < (sourceLength - (targetLength - 1)); i++) {
        returnValue = strncmp (&sourceString [i], targetString, targetLength);

        if (returnValue == 0) {
            index = i;
            break;
        }
    }
    return index;
}