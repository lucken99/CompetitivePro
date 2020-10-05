/*
Given a number N and for any number K for a series formed as K, K + 1, K + 2, K + 3, K + 4, ……., K + N. 
The task is to find the number of unique sums that can be obtained by adding two or more integers from the series of N + 1 integers.

Examples:

Input: N = 3 
Output: 10 
Explanation: 
The possible unique combinations are: 
(K) + (K + 1) = 2*K + 1 
(K) + (K + 2) = 2*K + 2 
(K) + (K + 3) = 2*K + 3 
(K + 1) + (K + 3) = 2*K + 4 
(K + 2) + (K + 3) = 2*K + 5 
(K) + (K + 1) + (K + 2) = 3*K + 3 
(K) + (K + 1) + (K + 3) = 3*K + 4 
(K) + (K + 2) + (K + 3) = 3*K + 5 
(K + 1) + (K + 2) + (K + 3) = 3*K + 6 
(K) + (K + 1) + (K + 2) + (K + 3) = 4*K + 6 
So in total, there are 10 unique ways. 

Input: N = 4 
Output: 20 
Explanation: 
The possible unique combinations are 20 in number.

Steps:

- Initialize two arrays array fsum[] and rsum[] each of size N + 1 to 0.
- For each element of both the arrays fsum[] and rsum[], update fsum[i] with ar[i] + fsum[i – 1] and rsum[i] with ar[i] + fsum[i + 1].
- Initialize a variable ans to 1 that stores the count of different possible sums of the given series.
- For each possible subset size X, where (2 ≤ X ≤ (N + 1)), add the value 1 + rsum[n + 1 – k] + fsum[k] to ans.
- The value of ans is the required answer hence return it. 
 
*/

// Time Complexity: O(N) 
// Auxiliary Space: O(N)

#include <bits/stdc++.h> 
using namespace std; 

int count_unique_sum(int n) 
{ 
  
    int i, ar[n + 1], fsum[n + 1]; 
    int rsum[n + 1], ans = 1; 

    memset(fsum, 0, sizeof fsum); 

    memset(rsum, 0, sizeof rsum); 
  
    for (i = 0; i <= n; i++) { 
        ar[i] = i; 
    } 
 
    fsum[0] = ar[0]; 

    rsum[n] = ar[n]; 
 
    for (i = 1; i <= n; i++) { 
        fsum[i] = ar[i] + fsum[i - 1]; 
    }

    for (i = n - 1; i >= 0; i--)
    { 
        rsum[i] = ar[i] + rsum[i + 1]; 
    } 

    for (int k = 2; k <= n; k++)
    {  
        ans += 1 + rsum[n + 1 - k] 
               - fsum[k - 1]; 
    } 

    return ans; 
} 
 
int main() 
{
    int N = 4; 

    cout << count_unique_sum(N);

    return 0; 
}