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

char toLowerCase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return (char) (ch + UPPER_TO_LOWER_OFFSET);
    } else {
        return ch;
    }
}

bool isAlpha(char ch) {
    ch = toLowerCase(ch);
    return ch >= ALPHA_MIN && ch <= ALPHA_MAX;
}

void accumulate(int letterCounts[], char letter) {
    if (isAlpha(letter)) {
        letter = toLowerCase(letter);
        int index = letter - 'a';
        letterCounts[index]++;
    }
}

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

void printAnalysis(int letterCounts[], int numWords) {
    cout << numWords << DELIM << "words" << endl;
    for (int i = 0; i < ALPHA_SIZE; i++) {
        if (letterCounts[i] > 0) {
            char letter = (char) ('a' + i);
            cout << letterCounts[i] << DELIM << letter << endl;
        }
    }
}

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
