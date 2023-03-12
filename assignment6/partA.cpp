/ Pig Latin
#include <iostream>
#include <string>
using namespace std;
// Prototypes
string leftTrim(string);
string popWord(string &);
string toPigLatin(string);
int main()
{
// Declare 3 strings
// To hold the user's input
// To hold the translated string
// to hold a word
// Get a sentence from the user.
// Translate each word and create a new string.
while (str.size() > 0)
{
// Get the next word from the string by caaling popWord.
// Translate the word to Pig Latin by calling toPigLatin function.
// Add the word and a space to the pig string.
}
// Display the translat
return 0;
}
// The leftTrim function accepts a string
// argument and returns that same argument
// with any leading spaces removed.
//
string leftTrim(string str)
{
}
// The popWord function accepts a string argument,
// passed by reference. It removes the first word
// from the string and then returns that word.
string popWord(string &sentence)
{
// Trim any spaces from the beginning of the string.
// Locate the first space, or the end of the string.
// Copy the substring from the beginning of sentence
// up to index, and store the copy in word.
// Remove the word from sentence.
// Return the extracted word.
}
// The toPigLatin function accepts a string
// containing a word. It returns that word
// translated to Pig Latin.
string toPigLatin(string word)
{
// Get the first letter of the word.
// Append the letter to the end of the word.
// Append "ay" to the word.
// Delete the first letter.
// Return the word.