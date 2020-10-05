/*
Given a string str, the task is to find the number of distinct substrings that are placed consecutively in the given string.

Using Dynamic Programming. 
Follow the steps below to solve the problem:

- If the length of the string does not exceed 1, then it is not possible to find any such consecutively placed similar substrings. So return 0 as the count.
- Otherwise, initialize a memoization table dp[] of dimensions (N+1 * N+1) which is initialized to 0.
- Initialize an unordered_set to store the distinct substrings placed consecutively.
- Iterate from the end of the string.
- While traversing the string if any repeating character is found, then dp[i][j] will be determined considering the previously computed dp value i.e., count of identical substrings up to dp[i+1][j+1] characters and including the current character.
- If the character is not similar then, dp[i][j] will be filled with 0.
- Similar substrings are consecutively placed together without any other characters and they will be the same for at most (j – i) characters. Hence, for valid substrings, dp[i][j] value must be greater than (j – i). Store those substrings in unordered_set which appears the maximum number of times consecutively.
- Finally, return the size of the unordered_set as the count of distinct substrings placed consecutively.

Source: GFG
*/

// Time Complexity: O(N) 
// Auxiliary Space: O(N)

 
#include <bits/stdc++.h> 
using namespace std; 

int distinctSimilarSubstrings(string str) 
{ 
    int n = str.size(); 

    if (n <= 1)
        return 0; 
 
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0)); 

    unordered_set<string> substrings; 

    for (int j = n - 1; j >= 0; j--)
    { 
        for (int i = j - 1; i >= 0; i--)
        { 
 
            if (str[i] == str[j])
            {  
                dp[i][j] = dp[i + 1][j + 1] + 1; 
            } 
 
            else
            { 
  
                dp[i][j] = 0; 
            } 
   
            if (dp[i][j] >= j - i)
            { 
  
                substrings.insert( 
                    str.substr(i, j - i)); 
            } 
        } 
    } 

    return substrings.size(); 
} 
 
int main() 
{ 
    string str = "strforstrstring"; 
  
    cout << distinctSimilarSubstrings(str); 
    return 0; 
}