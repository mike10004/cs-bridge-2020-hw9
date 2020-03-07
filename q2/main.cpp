// mac937@nyu.edu
// hw9 question 2

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
 * Analyzes a line of text. Counts the instances of each letter.
 * @param line a line of text
 * @param letterCounts array of length ALPHA_SIZE
 */
void analyzeLine(const string& line, int letterCounts[]) {
    for (char ch : line) {
        accumulate(letterCounts, ch);
    }
}

/**
 * Determines whether two arrays are equal.
 * @param array1 the first array
 * @param array1Size first array size
 * @param array2  the second array
 * @param array2Size  second array size
 * @return true if and only if they contain the same values at the same positions
 */
bool isArraysEqual(const int *array1, int array1Size, const int *array2, const int array2Size) {
    if (array1Size != array2Size) {
        return false;
    }
    for (int i = 0; i < array1Size; i++) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int letterCounts1[ALPHA_SIZE] = {0};
    int letterCounts2[ALPHA_SIZE] = {0};
    char phrase1[MAX_LINE_LEN] = "";
    char phrase2[MAX_LINE_LEN] = "";
    cout << "Please enter two phrases:" << endl;
    cin.getline(phrase1, MAX_LINE_LEN);
    cin.getline(phrase2, MAX_LINE_LEN);
    string phrase1String(phrase1);
    string phrase2String(phrase2);
    analyzeLine(phrase1, letterCounts1);
    analyzeLine(phrase2, letterCounts2);
    bool anagrams = isArraysEqual(letterCounts1, ALPHA_SIZE, letterCounts2, ALPHA_SIZE);
    cout << "Those are";
    if (!anagrams) {
        cout << " not";
    }
    cout << " anagrams." << endl;
    return 0;
}
