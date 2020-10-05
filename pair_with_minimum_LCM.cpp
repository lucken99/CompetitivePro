/*
Given a number N, the task is to find two numbers a and b such that a + b = N and LCM(a, b) is minimum.

Examples:

Input: N = 15
Output: a = 5, b = 10
Explanation:
The pair 5, 10 has a sum of 15 and their LCM is 10 which is the minimum possible.

Input: N = 4
Output: a = 2, b = 2
Explanation: 
The pair 2, 2 has a sum of 4 and their LCM is 2 which is the minimum possible

Approach:

- If N is a Prime Number then the answer is 1 and N – 1 because in any other cases either a + b > N or LCM( a, b) is > N – 1. 
This is because if N is prime then it implies that N is odd. So a and b, any one of them must be odd and other even. 
Therefore, LCM(a, b) must be greater than N ( if not 1 and N – 1) as 2 will always be a factor.
- If N is not a prime number then choose a, b such that their GCD is maximum, because of the formula LCM(a, b) = a*b / GCD (a, b). 
So, in order to minimize LCM(a, b) we must maximize GCD(a, b).
- If x is a divisor of N, then by simple mathematics a and b can be represented as N / x and N / x*( x – 1) respectively. 
Now as a = N / x and b = N / x * (x – 1), so their GCD comes out as N / x. To maximize this GCD, take the smallest possible x or smallest possible divisor of N.

Source: GFG
*/

// Time Complexity: O(sqrt(N))
// Auxiliary Space: O(1)


#include <bits/stdc++.h> 
using namespace std; 
 
bool prime(int n) 
{ 
    if (n == 1) 
        return false; 
    for (int i = 2; i * i <= n; i++)
    { 
        if (n % i == 0) 
            return false; 
    } 
 
    return true; 
} 
 
void minDivisior(int n) 
{ 
    if (prime(n))
    { 
        cout << 1 << " " << n - 1; 
    } 

    else
    { 
        for (int i = 2; i * i <= n; i++)
        { 
            if (n % i == 0)
            { 
                cout << n / i << " "
                     << n / i * (i - 1); 
                break; 
            } 
        } 
    } 
} 
  
int main() 
{ 
    int N = 4; 

    minDivisior(N); 

    return 0; 
}

