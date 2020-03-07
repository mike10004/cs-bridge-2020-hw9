// mac937@nyu.edu
// hw9 question 3

#include <iostream>
#include <cassert>

using namespace std;

/**
 * Counts the number of positive integers in an array of integers.
 * @param array array
 * @param arraySize array size
 * @return number of positive integers in the array
 */
int countPositives(const int array[], int arraySize) {
    int posCount = 0;
    for (int i = 0; i < arraySize; i++) {
        if (array[i] > 0) {
            posCount++;
        }
    }
    return posCount;
}

/**
 * Copies each positively-valued element of a source array into a
 * destination array.
 * @param src source array
 * @param srcLen length of source array
 * @param dst destination array; must be allocated large enough to hold all positives
 * @return number of positives, in case you didn't already know
 */
int copyPositives(const int src[], int srcLen, int dst[]) {
    int posCount = 0;
    for (int i = 0; i < srcLen; i++) {
        if (src[i] > 0) {
            dst[posCount] = src[i];
            posCount++;
        }
    }
    return posCount;
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

/**
 * Creates a new array containing only the positive numbers from the given array.
 * @param arr input array
 * @param arrSize input array size
 * @param outPosArrSize value updated with output array's logical size
 * @return base address of the output array (containing the positive numbers)
 */
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    outPosArrSize = countPositives(arr, arrSize);
    int* positives = new int[outPosArrSize];
    copyPositives(arr, arrSize, positives);
    return positives;
}

/**
 * Tests the function getPosNums1.
 */
void testGetPosNums1(int input[], int inputSize, int expected[], int expectedSize) {
    int actualSize = 0;
    int *actual = getPosNums1(input, inputSize, actualSize);
    assert(actual != nullptr);
    assert(expectedSize == actualSize);
    assert(isArraysEqual(expected, expectedSize, actual, actualSize));    
    delete actual;
}

/**
 * Creates a new array containing only the positive numbers from the given array.
 * Updates the output parameter `outPosArr` with the base address of the array 
 * (containing the positive numbers), and the output parameter `outPosArrSize` 
 * with the array's logical size.
 * @param arr input array
 * @param arrSize input array size
 * @param outPosArr output: array of positive numbers
 * @param outPosArrSize output: array's logical size 
 */
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    outPosArrSize = countPositives(arr, arrSize);
    outPosArr = new int[outPosArrSize];
    copyPositives(arr, arrSize, outPosArr);    
}

/**
 * Tests the function getPosNums2.
 */
void testGetPosNums2(int input[], int inputSize, int expected[], int expectedSize) {
    int actualSize = 0;
    int *actual = nullptr;
    getPosNums2(input, inputSize, actual, actualSize);
    assert(actual != nullptr);
    assert(expectedSize == actualSize);
    assert(isArraysEqual(expected, expectedSize, actual, actualSize));
    delete actual;
}

/**
 * Creates a new array containing only the positive numbers from the given array.
 * Returns the base address of the array (containing the positive numbers), and uses 
 * the pointer `outPosArrSizePtr` to update the array's logical size
 * @param arr input array
 * @param arrSize input array size 
 * @param outPosArrSizePtr pointer to location updated with output array size
 * @return output array base address
 */
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr) {
    int numPositives = countPositives(arr, arrSize);
    *outPosArrSizePtr = numPositives;
    int* positives = new int[numPositives];
    copyPositives(arr, arrSize, positives);
    return positives;
}

/**
 * Tests the function getPosNums3.
 */
void testGetPosNums3(int input[], int inputSize, int expected[], int expectedSize) {
    int actualSize = 0;
    int *actual = getPosNums3(input, inputSize, &actualSize);
    assert(actual != nullptr);
    assert(expectedSize == actualSize);
    assert(isArraysEqual(expected, expectedSize, actual, actualSize));
    delete actual;
}


/**
 * Creates a new array containing only the positive numbers from the given array.
 * Uses the pointer outPosArrPtr to update the base address of the array 
 * (containing the positive numbers), and the pointer `outPosArrSizePtr` to update the array’s logical size.
 * @param arr input array
 * @param arrSize input array size
 * @param outPosArrPtr pointer to pointer to location that will be assigned address of output array
 * @param outPosArrSizePtr pointer to location that will be assigned output array size
 */
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    int numPositives = countPositives(arr, arrSize);
    *outPosArrSizePtr = numPositives;
    int* positives = new int[numPositives];
    copyPositives(arr, arrSize, positives);
    *outPosArrPtr = positives;
}

/**
 * Tests the function getPosNums4.
 */
void testGetPosNums4(int input[], int inputSize, int expected[], int expectedSize) {
    int actualSize = 0;
    int *actual = nullptr;
    getPosNums4(input, inputSize, &actual, &actualSize);
    assert(actual != nullptr);
    assert(expectedSize == actualSize);
    assert(isArraysEqual(expected, expectedSize, actual, actualSize));
    delete actual;
}


int main() {
    int emptyArray[] = {};
    int onePositiveArray[] = {4};
    int oneNegativeArray[] = {-3};
    int manyNumbers[] = {-269,  -18,  609,  283, 
                           40,  288,  485,  309, 
                          551, -491, -552, -845, 
                           69,  905, -673,    0};
    int manyNumbersLength = 16;
    int manyPositives[] = {
            609, 283,  40, 288, 
            485, 309, 551,  69, 
            905
    };
    int manyPositivesLength = 9;
    
    testGetPosNums1(emptyArray, 0, emptyArray, 0);
    testGetPosNums2(emptyArray, 0, emptyArray, 0);
    testGetPosNums3(emptyArray, 0, emptyArray, 0);
    testGetPosNums4(emptyArray, 0, emptyArray, 0);
    
    testGetPosNums1(onePositiveArray, 1, onePositiveArray, 1);
    testGetPosNums2(onePositiveArray, 1, onePositiveArray, 1);
    testGetPosNums3(onePositiveArray, 1, onePositiveArray, 1);
    testGetPosNums4(onePositiveArray, 1, onePositiveArray, 1);
    
    testGetPosNums1(oneNegativeArray, 1, emptyArray, 0);
    testGetPosNums2(oneNegativeArray, 1, emptyArray, 0);
    testGetPosNums3(oneNegativeArray, 1, emptyArray, 0);
    testGetPosNums4(oneNegativeArray, 1, emptyArray, 0);
    
    testGetPosNums1(manyNumbers, manyNumbersLength, manyPositives, manyPositivesLength);
    testGetPosNums2(manyNumbers, manyNumbersLength, manyPositives, manyPositivesLength);
    testGetPosNums3(manyNumbers, manyNumbersLength, manyPositives, manyPositivesLength);
    testGetPosNums4(manyNumbers, manyNumbersLength, manyPositives, manyPositivesLength);
    
    return 0;
}
