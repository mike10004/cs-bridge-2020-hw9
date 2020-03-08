// mac937@nyu.edu
// hw9 question 1

#include <iostream>
#include <string>

using namespace std;

const char ALPHA_MIN = 'a';
const char ALPHA_MAX = 'z';
const int ALPHA_SIZE = ALPHA_MAX - ALPHA_MIN + 1;
const int UPPER_TO_LOWER_OFFSET = 'a' - 'A';
const int MAX_LINE_LEN = 1024;
const char DELIM = '\t';

/**
 * Returns the lower case variant of a letter, if it is an upper case
 * US English letter.
 * @param ch a letter
 * @return lower case version of the given upper-case letter; returns argument
 * unchanged if it's not an upper-case letter
 */
char toLowerCase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return (char) (ch + UPPER_TO_LOWER_OFFSET);
    } else {
        return ch;
    }
}

/**
 * Checks whether a character is a letter in the US English alphabet.
 * @param ch a character
 * @return true if and only if the character is a letter in the US English alphabet
 */
bool isAlpha(char ch) {
    ch = toLowerCase(ch);
    return ch >= ALPHA_MIN && ch <= ALPHA_MAX;
}

/**
 * Increments a letter count. Does nothing if the argument character
 * is not a letter.
 * @param letterCounts array of counts, where index 0 represents 'a' and index 25 represents 'z'
 * @param letter the letter to increment the count of
 */
void accumulate(int letterCounts[], char letter) {
    if (isAlpha(letter)) {
        letter = toLowerCase(letter);
        int index = letter - 'a';
        letterCounts[index]++;
    }
}

/**
 * Analyzes a line of text. Counts the instances of each letter and returns
 * the number of words.
 * @param line a line of text
 * @param letterCounts array of length ALPHA_SIZE
 * @return  number of words
 */
int analyzeLine(const string& line, int letterCounts[]) {
    bool inWord = false;
    int numWords = 0;
    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];
        accumulate(letterCounts, ch);
        if (!inWord && isAlpha(ch)) {
            inWord = true;
            numWords++;
        } else if (inWord && !isAlpha(ch)) {
            inWord = false;
        }
    }
    return numWords;
}

/**
 * Prints a line analysis.
 * @param letterCounts letter counts array (length ALPHA_SIZE)
 * @param numWords number of words
 */
void printAnalysis(int letterCounts[], int numWords) {
    cout << numWords << DELIM << "words" << endl;
    for (int i = 0; i < ALPHA_SIZE; i++) {
        if (letterCounts[i] > 0) {
            char letter = (char) ('a' + i);
            cout << letterCounts[i] << DELIM << letter << endl;
        }
    }
}

/**
 * Prompts for text and reports word and letter counts.
 * Performs two O(n) operations, where n is string length: copying
 * input to a string object and calling analyzeLine to perform 
 * text analysis.
 * @return zero on normal operation
 */
int main() {
    char inputLine[MAX_LINE_LEN] = "";
    int letterCounts[ALPHA_SIZE] = {0};  // initialize all to zero
    cout << "Please enter a line of text:" << endl;
    cin.getline(inputLine, MAX_LINE_LEN);
    string lineStr(inputLine);
    int numWords = analyzeLine(inputLine, letterCounts);
    printAnalysis(letterCounts, numWords);
    return 0;
}
