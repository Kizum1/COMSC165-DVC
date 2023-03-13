//******************************************************************
//Description: This is a program that performs a pig latin translation which reverse the first letter of each word and add "ay" to the end of the word.
//Author: Jay Chong
//COMSC 165 Section 5096
//Date March 12th, 2023
//Status: Complete
//*******************************************************************
#include <iostream>

#include <string>

using namespace std;

// Prototypes
string leftTrim(string);
string popWord(string & );
string toPigLatin(string);

int main() {
  // Declare 3 strings
  string string1, string2, string3;

  // To hold the user's input
  cout << "Enter three strings: ";
  cin >> string1 >> string2 >> string3;

  // To hold the translated string
  string translated = string1 + " " + string2 + " " + string3;

  // Translate each word and create a new string.
  string pig = "";
  while (translated.size() > 0) {
    // Get the next word from the string by calling popWord.
    string word = popWord(translated);

    // Translate the word to Pig Latin by calling toPigLatin function.
    string pig_word = toPigLatin(word);

    // Add the word and a space to the pig string.
    pig += pig_word + " ";
  }

  // Display the translation
  cout << "Original string: " << string1 << " " << string2 << " " << string3 << endl;
  cout << "Pig Latin: " << pig << endl;

  return 0;
}

// The leftTrim function accepts a string
// argument and returns that same argument
// with any leading spaces removed.
string leftTrim(string str) {
  while (str.size() > 0 && isspace(str[0])) {
    str.erase(0, 1);
  }
  return str;
}

// The popWord function accepts a string argument,
// passed by reference. It removes the first word
// from the string and then returns that word.
string popWord(string & sentence) {
  // Trim any spaces from the beginning of the string.
  sentence = leftTrim(sentence);

  // Locate the first space, or the end of the string.
  size_t space_pos = sentence.find_first_of(" ");

  // Copy the substring from the beginning of sentence
  // up to index, and store the copy in word.
  string word = sentence.substr(0, space_pos);

  // Remove the word from sentence.
  sentence.erase(0, space_pos);

  // Return the extracted word.
  return word;
}

// The toPigLatin function accepts a string
// containing a word. It returns that word
// translated to Pig Latin.
string toPigLatin(string word) {
  // Get the first letter of the word.
  char first_letter = word[0];

  // Append the letter to the end of the word.
  word += first_letter;

  // Append "ay" to the word.
  word += "ay";

  // Delete the first letter.
  word.erase(0, 1);

  // Return the word.
  return word;
}