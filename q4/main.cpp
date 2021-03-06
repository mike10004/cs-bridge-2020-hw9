// mac937@nyu.edu
// hw9 question 4

#include <iostream>
#include <cassert>

using namespace std;

/**
 * Determines whether a number is even.
 * @param number the number
 * @return true if even, false if odd
 */
bool isEven(int number) {
    return number % 2 == 0;
}

/**
 * Counts the even numbers in an array of integers.
 * @param arr the array
 * @param arrSize the array size
 * @return count of evens in the array
 */
int countEvens(const int arr[], int arrSize) {
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (isEven(arr[i])) {
            count++;
        }
    }
    return count;
}

/**
 * Rearranges elements of an array such that all odd values
 * are at positions before all even values. The original ordering
 * of the odd values is preserved, and the ordering of the
 * even values is reversed. The array is traversed once to count
 * the even numbers and again to push all odds to the front and 
 * collect the evens into a buffer. The evens buffer is then 
 * copied into the end of the array. Time complexity is O(n).
 * @param arr array
 * @param arrSize array size
 */
void oddsKeepEvensFlip(int arr[], int arrSize) {
    int numEvens = countEvens(arr, arrSize);
    int oddsVisited = 0, evensVisited = 0;
    int* evens = new int[numEvens];
    for (int i = 0; i < arrSize; i++) {
        if (isEven(arr[i])) {
            evens[numEvens - 1 - evensVisited] = arr[i];
            evensVisited++;
        } else {
            arr[oddsVisited] = arr[i];
            oddsVisited++;
        }
    }
    for (int i = 0; i < numEvens; i++) {
        arr[oddsVisited + i] = evens[i];
    }
    delete[] evens;
}

/**
 * Determines whether two arrays are equal.
 * @param array1 the first array
 * @param array1Size first array size
 * @param array2  the second array
 * @param array2Size  second array size
 * @return true if and only if they contain the same values at the same positions
 */
bool isArraysEqual(const int array1[], int array1Size, const int array2[], const int array2Size) {
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

/**
 * Prints an array.
 * @param arr  array
 * @param arrSize array length
 */
const char* printArray(const int arr[], int arrSize, const char* returnValue){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout.flush();
    return returnValue;
}

/**
 * Tests the oddsKeepEvensFlip function.
 * @param input input array
 * @param inputLength input array length
 * @param expected expected output array
 */
void testOddsKeepEvensFlip(const int input[], int inputLength, const int expected[]) {
    int* actual = new int[inputLength];
    for (int i = 0; i < inputLength; i++) {
        actual[i] = input[i];
    }
    oddsKeepEvensFlip(actual, inputLength);
    bool equal = isArraysEqual(actual, inputLength, expected, inputLength);
    if (!equal) {
        cout << "original: " << printArray(input, inputLength, "\n");
        cout << "expected: " << printArray(expected, inputLength, "\n");
        cout << "  actual: " << printArray(actual, inputLength, "\n");
        cout << endl;
    }
    delete[] actual;
    assert(equal);
}

/**
 * Tests the oddsKeepEvensFlip function with a variety of test cases.
 * @return zero on normal operation; nonzero on assertion failure
 */
int main() {
    int empty[] = {};
    int oneEven[] = {4};
    int oneOdd[] = {123};
    int twoBefore1[] = {2, -1};
    int twoAfter1[] =  {-1, 2};
    int twoBefore2[] = {-1, 2};
    int twoAfter2[] =  {-1, 2};
    int threeBefore1[] = {2, 3, 4};
    int threeAfter1[] =  {3, 4, 2};
    int threeBefore2[] = {2, 3, 5};
    int threeAfter2[] =  {3, 5, 2};
    int threeBefore3[] = {3, 4, 6};
    int threeAfter3[] =  {3, 6, 4};
    int threeBefore4[] = {4, 6, 3};
    int threeAfter4[] =  {3, 6, 4};
    int sixBefore1[] = {5, 2, 11, 7, 6, 4};
    int sixAfter1[] =  {5, 11, 7, 4, 6, 2};
    int tenBefore1[] = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9};
    int tenAfter1[] =  { 1,  3,  5,  7,  9,  8,  6,  4,  2,  0};
    int tenBefore2[] = { 0,  2,  4,  6,  8, 10, 12, 14, 16, 18};
    int tenAfter2[] =  {18, 16, 14, 12, 10,  8,  6,  4,  2,  0};
    int tenBefore3[] = {19, 17, 15, 13, 11,  9,  7,  5,  3,  1};
    int tenAfter3[] =  {19, 17, 15, 13, 11,  9,  7,  5,  3,  1};
    int tenBefore4[] = {19, 17, 15,  2,  4,  9,  7,  5,  3,  1};
    int tenAfter4[] =  {19, 17, 15,  9,  7,  5,  3,  1,  4,  2};
    int tenBefore5[] = { 0,  2,  4,  6,  8, 10, 12, 14, 16, 17};
    int tenAfter5[] =  {17, 16, 14, 12, 10,  8,  6,  4,  2,  0};
    testOddsKeepEvensFlip(empty, 0, empty);
    testOddsKeepEvensFlip(oneEven, 1, oneEven);
    testOddsKeepEvensFlip(oneOdd, 1, oneOdd);
    testOddsKeepEvensFlip(twoBefore1, 2, twoAfter1);
    testOddsKeepEvensFlip(twoAfter1, 2, twoAfter1);
    testOddsKeepEvensFlip(twoBefore2, 2, twoAfter2);
    testOddsKeepEvensFlip(threeBefore1, 3, threeAfter1);
    testOddsKeepEvensFlip(threeBefore2, 3, threeAfter2);
    testOddsKeepEvensFlip(threeBefore3, 3, threeAfter3);
    testOddsKeepEvensFlip(threeBefore4, 3, threeAfter4);
    testOddsKeepEvensFlip(threeAfter2, 3, threeAfter2);
    testOddsKeepEvensFlip(sixBefore1, 6, sixAfter1);
    testOddsKeepEvensFlip(tenBefore1, 10, tenAfter1);
    testOddsKeepEvensFlip(tenBefore2, 10, tenAfter2);
    testOddsKeepEvensFlip(tenBefore3, 10, tenAfter3);
    testOddsKeepEvensFlip(tenBefore4, 10, tenAfter4);
    testOddsKeepEvensFlip(tenBefore5, 10, tenAfter5);
    return 0;
}

