# Question 4

Implement the function:

    void oddsKeepEvensFlip(int arr[], int arrSize)

This function gets an array of integers arr and its logical size arrSize.

When called, it should reorder (in-place) the elements of arr so that:

1. All the odd numbers come before all the even numbers
2. The odd numbers will keep their original relative order
3. The even numbers will be placed in a reversed order (relative to their original order).

For example, if arr = `[5, 2, 11, 7, 6, 4]`, after calling `oddsKeepEvensFlip(arr, 6)`, 
`arr` will be: `[5, 11, 7, 4, 6, 2]`

## Implementation requirements

1. Your function should run in linear time. That is, if there are `n` items in `arr`, calling
   `oddsKeepEvensFlip(arr, n)` will run in θ(n).
2. Write a `main()` program that tests this function..