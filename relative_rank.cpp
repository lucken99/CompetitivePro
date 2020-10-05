/*
Given an array A[] of N integers, the task is to find the relative rank for each element in the given array.

The relative rank for each element in the array is the count of elements which is greater than the current element in the 
Longest Increasing Subsequence from the current element.

Examples:

Input: A[] = {8, 16, 5, 6, 9}, N = 5
Output: {1, 0, 2, 1, 0}
Explanation:
For i = 0, required sequence is {8, 16} Relative Rank = 1.
For i = 1, Since all elements after 16 are smaller than 16, Relative Rank = 0.
For i = 2, required sequence is {5, 6, 9} Relative Rank = 2
For i = 3, required sequence is {6, 9} Relative Rank = 1
For i = 4, required sequence is {9} Relative Rank = 0

Steps:

- Use a Stack and store the elements which in non-decreasing order from the right till each element(say A[i]) 
- then the rank for each A[i] is the (size of stack – 1) till that element.

Source: GFG
*/

// Time Complexity: O(N)
// Auxiliary Space: O(1)

#include <bits/stdc++.h> 
using namespace std; 
  
void findRank(int A[], int N) 
{ 
   int rank[N] = {}; 
 
    stack<int> s; 
 
    s.push(A[N - 1]); 
  
    for (int i = N - 2; i >= 0; i--)
    {  
        if (A[i] < s.top())
        { 
            s.push(A[i]); 
            rank[i] = s.size() - 1; 
        } 
        else
        {
            while (!s.empty() && A[i] >= s.top())
            { 
                s.pop(); 
            } 
            s.push(A[i]); 
  
            rank[i] = s.size() - 1; 
        } 
    } 
  
    for (int i = 0; i < N; i++)
    { 
        cout << rank[i] << " "; 
    } 
} 
   
int main() 
{  
    int A[] = { 1, 2, 3, 5, 4 }; 
  
    int N = sizeof(A) / sizeof(A[0]); 
   
    findRank(A, N);

    return 0; 
} 

