/*
Given an array arr[] consisting of N integers and queries Q[][] of the form {L, R} where 0 ≤ L < R ≤ N – 1, the task for each query is to calculate the following equation :

KL | KL + 1 |…| KR – 1 
where Ki = (arr[i] ^ arr[i+1]) | (arr[i] ~ arr[i+1]), 
“~” represents binary XNOR, 
“^” represents binary XOR , 
“|” represents binary OR 

Use Segment Tree or Sparse Table.

- Taking OR of both of these operations, all the bits up to the largest of the max(MSB(arri), MSB(arri+1)) will be set.
- Therefore, find the largest number, using Segment Tree, in between the given indices and set all of its bits to 1, 
to obtain the required answer.
- Print the answer.

Source: GFG
*/

// Time Complexity: O(N*log(sizeof(Q)) 
// Auxiliary Space: O(N)

#include <bits/stdc++.h>
using namespace std;

int getMid(int s, int e)
{
	return s + (e - s) / 2;
}

int MaxUtil(int* st, int ss, int se, int l,
			int r, int node)
{
	if (l <= ss && r >= se)
		return st[node];

	if (se < l || ss > r)
		return -1;

	int mid = getMid(ss, se);

	return max(MaxUtil(st, ss, mid, l, r,
					2 * node + 1),
			MaxUtil(st, mid + 1, se, l,
					r, 2 * node + 2));
}


int getMax(int* st, int n, int l, int r)
{
	if (l < 0 || r > n - 1 || l > r)
	{
		printf("-1");
		return -1;
	}

	return MaxUtil(st, 0, n - 1, l, r, 0);
}

int constructSTUtil(int arr[], int ss, int se,
					int* st, int si)
{
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	int mid = getMid(ss, se);

	st[si] = max(constructSTUtil(arr, ss, mid, st,
								si * 2 + 1),
				constructSTUtil(arr, mid + 1, se,
								st, si * 2 + 2));

	return st[si];
}

int* constructST(int arr[], int n)
{
	int x = (int)(ceil(log2(n)));

	int max_size = 2 * (int)pow(2, x) - 1;

	int* st = new int[max_size];

	constructSTUtil(arr, 0, n - 1, st, 0);

	return st;
}

int main()
{
	int arr[] = { 5, 2, 3, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int* st = constructST(arr, n);

	vector<vector<int> > Q = { { 1, 3 }, { 0, 2 } };
	for (int i = 0; i < Q.size(); i++) {

		int max = getMax(st, n, Q[i][0], Q[i][1]);
		int ok = 0;
		for (int i = 30; i >= 0; i--) {
			if ((max & (1 << i)) != 0)
				ok = 1;

			if (!ok)
				continue;

			max |= (1 << i);
		}

		cout << max << " ";
	}

	return 0;
}
