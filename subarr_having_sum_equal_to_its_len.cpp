/*
Given an array arr[] of size N, the task is to find the number of subarrays having the sum of its elements 
equal to the number of elements in it.

If all the elements of the array are decremented by 1, then all the subarrays of array arr[] with a sum equal to its number of elements are same as finding the number of subarrays with sum 0 in the new array
(formed by decrementing all the elements of arr[ ] by 1).

Steps:
- Decrement all the array elements by 1.
- Initialize a prefix array with prefix[0] = arr[0].
- Traverse the given array arr[] from left to right, starting from index 1 and update a prefix sum array as pref[i] = pref[i-1] + arr[i].
- Initialize the answer to 0.
- Iterate the prefix array pref[] from left to right and increment the answer by the value of the current element in the map.
- Increment the value of the current element in the map.
- Print the value of answer after the above steps.

Source: GFG
*/

// Time Complexity: O(N * Log(N))
// Auxiliary Space: O(N)

#include <bits/stdc++.h>
using namespace std;
 
// Function that counts the subarrays
int countOfSubarray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        arr[i]--;

    int pref[N];
    pref[0] = arr[0];
 
    for (int i = 1; i < N; i++)
        pref[i] = pref[i - 1] + arr[i];
 
    map<int, int> mp;
    int ans = 0;
 
    mp[0]++;
 
    for (int i = 0; i < N; i++) 
    {
        ans += mp[pref[i]];
        mp[pref[i]]++;
    }
 
    return ans;
}
 

int main()
{
    // Given array arr[]
    int arr[] = { 1, 1, 0 };
    int N = sizeof arr / sizeof arr[0];

    cout << countOfSubarray(arr, N);

    return 0;
}
