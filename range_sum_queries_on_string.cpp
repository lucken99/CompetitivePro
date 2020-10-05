/*
Given a string S with lowercase alphabets only and Q queries where each query contains a pair {L, R}. For each query {L, R}, there exists a substring S[L, R], the task is to find the value of the product of the frequency of each character in substring with their position in alphabetical order. 
Note: Consider 1-based indexing.
Examples: 
 

Input: S = “abcd”, Q = { {2, 4}, {1, 3} } 
Output: 9 6 
Explanation: 
For 1st query, 
substring is S[2, 4] = “bcd”. Therefore the frequency of b, c, d are 1, 1, 1 in range 2 to 4. 
value = 2*(1) + 3*(1) + 4*(1) = 9.
For 2nd query, 
substring is S[1, 3] = “abc”. Therefore the frequency of a, b, c are 1, 1, 1 in range 1 to 3. 
value = 1*(1) + 2*(1) + 3*(1) = 6.

Input: S = “geeksforgeeks”, Q = { {3, 3}, {2, 6}, {1, 13} } 
Output: 5 46 133

Steps:
Using Prefix Sum of the whole string by which we can perform each query in constant time. 
 
- Create an array arr[] of length equals to the length of the string.
- Traverse the given string and for each corresponding index i in the string, assign arr[i] the value of current character – ‘a’.
- Find the prefix sum of the array arr[]. This prefix sum array will given sum of occurrence of all characters till each index i.
- Now for each query(say {L, R}) the value of arr[R – 1] – arr[L – 2] will give the value of the given expression.

Source: GFG 
*/

// Time Complexity: O(N), where N is the length of the given string. 
// Auxiliary Space: O(1)


#include <bits/stdc++.h> 
using namespace std; 
 
void Range_sum_query(string S, 
                     vector<pair<int, int> > Query) 
{ 
    int N = S.length();  
    int A[N]; 
  
    A[0] = S[0] - 'a' + 1; 
 
    for (int i = 1; i < N; i++)
    { 
        A[i] = S[i] - 'a' + 1; 
        A[i] = A[i] + A[i - 1]; 
    }

    for (int i = 0; i < Query.size(); i++)
    { 
        if (Query[i].first == 1)
        { 
            cout << A[(Query[i].second) - 1] 
                 << endl; 
        } 
  
        else
        {
            cout << A[(Query[i].second) - 1] 
                        - A[(Query[i].first) - 2] 
                 << endl; 
        } 
    } 
} 
  
int main() 
{
    string S = "abcd"; 
  
    vector<pair<int, int> > Query; 
 
    Query.push_back(make_pair(2, 4)); 
    Query.push_back(make_pair(1, 3)); 

    Range_sum_query(S, Query);
     
    return 0; 
} 

