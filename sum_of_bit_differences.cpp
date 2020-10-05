/*
Given a number N, the task is to calculate the total number of corresponding different bit in the binary representation for every consecutive number from 0 to N.

Examples:

Input: N = 5
Output: 8
Explanation:
Binary Representation of numbers are:
0 -> 000,
1 -> 001,
2 -> 010,
3 -> 011,
4 -> 100,
5 -> 101
Between 1 and 0 -> 1 bit is different
Between 2 and 1 -> 2 bits are different
Between 3 and 2 -> 1 bit is different
Between 4 and 3 -> 3 bits are different
Between 5 and 4 -> 1 bit is different
Total = 1 + 2 + 1 + 3 + 1 = 8

Input: N = 11
Output: 19

Steps:

Using Recursion

Number:     0 1 2 3 4  5  6  7
Difference: 1 2 1 3 1  2  1  4
Sum:        1 3 4 7 8 10 11 15

We can observe that for N = [1, 2, 3, 4, …..], the sum of different bits in consecutive elements forms the sequence [1, 3, 4, 7, 8, ……]. 
Hence, Nth term of this series will be our required answer, which can be calculated as:

a(n) = a(n / 2) + n; with base case as a(1) = 1

Source: GFG
*/

// Time Complexity: O(log2N)
// Auxiliary Space: O(1)

#include <bits/stdc++.h> 
using namespace std; 

int totalCountDifference(int n) 
{ 
    if (n == 1) 
        return 1; 
 
    return n + totalCountDifference(n / 2); 
} 
   
int main() 
{ 
    int N = 5; 
    cout << totalCountDifference(N); 

    return 0; 
} 

