# Question 3

Write four versions of a function `getPosNums` that gets an array of integers 
`arr`, and its logical size. When called it creates a new array containing
only the positive numbers from arr.

For example, if `arr = [3, -1, -3, 0, 6, 4]`, the functions should create an array
containing the following 3 elements: `[3, 6, 4]`,

The four versions you should implement differ in the way the output is returned.
The prototypes of the functions are:

1. `int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)` returns the 
   base address of the array (containing the positive numbers), and updates
   the output parameter outPosArrSize with the array’s logical size.
2. `void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)`
   updates the output parameter `outPosArr` with the base address of the array
   (containing the positive numbers), and the output parameter `outPosArrSize` 
   with the array' logical size.
3. `int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr)` returns 
   the base address of the array (containing the positive numbers), and uses
   the pointer `outPosArrSizePtr` to update the array’s logical size.
4. `void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)`
   uses the pointer outPosArrPtr to update the base address of the array 
   (containing the positive numbers), and the pointer `outPosArrSizePtr` to update 
   the array’s logical size.

Note: You should also write a main program that calls and tests all these functions.
