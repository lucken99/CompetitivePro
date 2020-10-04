/*
Given an array arr[] of N positive integers and an integer K.
The task is to create a set of prime numbers such that 
the sum of all the powers of prime numbers in the prime factorization of all the array elements is divisible by K.

Steps:

- Create the smallest prime factorization array spf[] up to the maximum number in the array. This step is used to precalculate the prime factors of a number.
- Traverse the given array arr[] and for each element find the sum of all the count of factors stored in spf[] array.
- For each sum of the power of a prime number in the above steps stored it frequency in a Map.
- Traverse the map if, for any number, frequency is divisible by K then store that number.
- Finally, print all the numbers stored in the above step.
*/

// Time Complexity: O(M*log(M)), where M is the maximum element of the array. 
// Auxiliary Space: O(M) 

#include <iostream>  
#include <unordered_map>  
#include <vector>  
using namespace std;  
   
int spf[10001];  
  
void spf_array(int spf[])  
{   
    spf[1] = 1;  
  
    for (int i = 2; i < 1000; i++)   
        spf[i] = i;  
  
    for (int i = 4; i < 1000; i += 2)  
        spf[i] = 2;  
  
    for (int i = 3; i * i < 1000; i++)
    {    
        if (spf[i] == i)
        {   
            for (int j = i * i;  
                j < 1000; j += i)  
  
                if (spf[j] == j)  
                    spf[j] = i;  
        }  
    }  
}  
    
void frequent_prime(int arr[], int N,  
                    int K)  
{   
    spf_array(spf);  
  
    unordered_map<int, int> Hmap;  
  
    vector<int> result;

    int i = 0, c = 0;  
    
    for (i = 0; i < N; i++)
    {  
        int x = arr[i];  
        while (x != 1) {  
  
            Hmap[spf[x]]  
                = Hmap[spf[x]] + 1;  
            x = x / spf[x];  
        }  
    }  
   
    Hmap.erase(1);  
  
    for (auto x : Hmap)
    {    
        int primeNum = x.first, frequency = x.second;  
  
        if (frequency % K == 0) 
            result.push_back(primeNum);   
    }  
   
    if (result.size() > 0) 
    {  
        for (auto& it : result) 
        {  
            cout << it << ' ';  
        }  
    }  
    else  
        cout << "{}";   
}  
    
int main()  
{   
    int arr[] = { 1, 4, 6 };  
    
    int K = 1, N = sizeof(arr) / sizeof(arr[0]);  
   
    frequent_prime(arr, N, K);

    return 0;  
} 

