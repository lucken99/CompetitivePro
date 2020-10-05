/*
Given an integer array arr[] of size N, the task is to construct an array consisting of N+1 strings of length N such that arr[i] 
is equal to the Longest Common Prefix of ith String and (i+1)th String.

Examples:

Input: arr[] = {1, 2, 3}
Output: {“abb”, “aab”, “aaa”, “aaa”}
Explanation:
Strings “abb” and “aab” have a single character “a” as Longest Common Prefix.
Strings “aab” and “aaa” have “aa” as Longest Common Prefix.
Strings “aaa” and “aaa” have “aa” as Longest Common Prefix.

Input : arr[]={2, 0, 3}
Output: {“bab”, “baa”, “aaa”, “aaa”}
Explanation:
Strings “bab” and “baa” have “ba” as Longest Common Prefix.
Strings “baa” and “aaa” have no common prefix.
Strings “aaa” and “aaa” have “aaa” as Longest Common Prefix.

Steps:

- The idea is to observe that if ith string is known then (i-1)th string can be formed from ith string 
by changing N – arr[i-1] characters from ith string.
- Start constructing strings from right to left and generate the N + 1 strings.

Source: GFG
*/

// Time Complexity: O(N)
// Auxiliary Space: O(N)

#include <bits/stdc++.h> 
using namespace std; 

vector<string> solve(int n, int arr[]) 
{ 
    string s = string(n, 'a'); 
    vector<string> ans; 
    ans.push_back(s); 

    for (int i = n - 1; i >= 0; i--)
    { 
        char ch = s[arr[i]]; 
 
        if (ch == 'b') 
            ch = 'a';  
        else
            ch = 'b';

        s[arr[i]] = ch;

        ans.push_back(s); 
    } 
 
    return ans; 
} 
 
int main() 
{   
    int arr[] = { 2, 0, 3 }; 
    int n = sizeof arr / sizeof arr[0]; 
    vector<string> ans = solve(n, arr); 
 
    for (int i = ans.size() - 1; i >= 0; i--)
    { 
        cout << ans[i] << endl; 
    } 
  
    return 0; 
} 

