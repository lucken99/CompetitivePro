/*
Given two numbers L and R, the task is to find two distinct minimum positive
integers X and Y such that whose LCM lies in the range [L, R]. If there doesn’t
exist any value of X and Y then print “-1”.

Examples:

Input: L = 3, R = 8 
Output: x = 3, y=6
Explanation:
LCM of 3 and 6 is 6 which is in range 3, 8

Input: L = 88, R = 90
Output: -1
Explanation:
Minimum possible x and y are 88 and 176 respectively, but 176 is greater than 90.

Steps:
- For the minimum value of X choose L as the minimum value as this is the minimum value in the given range.
- Now for the value of Y choose 2*L as this is the minimum value of Y whose LCM is L.
- Now if the above two values of X and Y lie in the range [L, R], then this is required pair of integers with minimum possible values of X and Y.
- Otherwise, print “-1” as there doesn’t exist any other pair.

Source: GFG
*/

// Time Complexity: O(1)
// Auxiliary Space: O(1)

#include <bits/stdc++.h> 
using namespace std; 
   
void answer(int L, int R) 
{ 
    if (2 * L <= R) 
        cout << L << ", "
             << 2 * L << "\n"; 
    else
        cout << -1; 
} 
  
int main() 
{ 
    int L = 3, R = 8; 
    answer(L, R);

    return 0; 
}

