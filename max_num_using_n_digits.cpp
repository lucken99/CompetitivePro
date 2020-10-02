/*
Given a positive integer N, the task is to find the minimum N-digit number 
such that performing the following operations on it in the following order results
into the largest N-digit number:
1. Convert the number to its Binary Coded Decimal form.
2. Concatenate all the resulting nibbles to form a binary number.
3. Remove the least significant N bits from the number.
4. Convert this obtained binary number to its decimal form.

Source: GFG
*/

// Time Complexity: O(N) 
// Auxiliary Space: O(1)

#include <bits/stdc++.h> 
using namespace std; 

void maximizedNdigit(int n) 
{ 
	int count0s, count9s;  
	if (n % 4 == 0)
	{ 
		count0s = n / 4; 
		count9s = n - n / 4; 
	} 
 
	else
	{ 
		count0s = n / 4 + 1; 
		count9s = n - count0s; 
		count0s--; 
	} 

	while (count9s--) 
		cout << '9'; 

	if (n % 4 != 0) 
		cout << '8'; 

	while (count0s--) 
		cout << '0';

	cout << endl; 
} 

int main() 
{ 
	//Min Digits
	int n = 5; 
	maximizedNdigit(n);

	return 0; 
} 
