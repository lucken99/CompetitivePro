/*
Given an array arr[] of positive integers and a number K, the task is to find the minimum and maximum values of Bitwise operation on elements of subarray of size K.
Examples:

Input: arr[]={2, 5, 3, 6, 11, 13}, k = 3 
Output: 
Maximum AND = 2 
Minimum AND = 0 
Maximum OR = 15 
Minimum OR = 7 
Explanation: 
Maximum AND is generated by subarray 3, 6 and 11, 3 & 6 & 11 = 2 
Minimum AND is generated by subarray 2, 3 and 5, 2 & 3 & 5 = 0 
Maximum OR is generated by subarray 2, 6 and 13, 2 | 6 | 13 = 15 
Minimum OR is generated by subarray 2, 3 and 5, 2 | 3 | 5 = 7

Input: arr[]={5, 9, 7, 19}, k = 2 
Output: 
Maximum AND = 3 
Minimum AND = 1 
Maximum OR = 23 
Minimum OR = 13

Using Sliding Window Technique:

- Traverse the prefix array of size K and for each array, element goes through it’s each bit and 
increases bit array (by maintaining an integer array bit of size 32) by 1 if it is set.
- Convert this bit array to a decimal number lets say ans, and move the sliding window to the next index.
- For newly added element for the next subarray of size K, 
Iterate through each bit of the newly added element and increase bit array by 1 if it is set.
- For removing the first element from the previous window, decrease bit array by 1 if it is set.
- Update ans with a minimum or maximum of the new decimal number generated by bit array.

Source: GFG
*/

// Time Complexity: O(n * B) where n is the size of the array and B is the integer array bit of size 32. 
// Auxiliary Space: O(n)

// Maximum Bitwise OR subarray
#include <iostream> 
using namespace std; 
 
int build_num(int bit[]) 
{ 
    int ans = 0; 
  
    for (int i = 0; i < 32; i++) 
        if (bit[i]) 
            ans += (1 << i); 
  
    return ans; 
} 
 
int maximumOR(int arr[], int n, int k) 
{
    int bit[32] = { 0 }; 
   
    for (int i = 0; i < k; i++)
    { 
        for (int j = 0; j < 32; j++)
        { 
            if (arr[i] & (1 << j)) 
                bit[j]++; 
        } 
    } 
 
    int max_or = build_num(bit); 
  
    for (int i = k; i < n; i++)
    { 
        for (int j = 0; j < 32; j++)
        { 
            if (arr[i - k] & (1 << j)) 
                bit[j]--; 
        } 
 
        for (int j = 0; j < 32; j++)
        { 
            if (arr[i] & (1 << j)) 
                bit[j]++; 
        } 

        max_or = max(build_num(bit), max_or); 
    } 
 
    return max_or; 
} 
 
int main() 
{ 
    int arr[] = { 2, 5, 3, 6, 11, 13 }; 

    int k = 3; 
    int n = sizeof arr / sizeof arr[0]; 

    cout << maximumOR(arr, n, k); 
  
    return 0; 
} 
