// Given an array of integers A and an integer B.
//
// Find the total number of subarrays having bitwise XOR of all
// elements equals to B.

// Input 1:
//
//  A = [4, 2, 2, 6, 4]
//  B = 6
// Input 2:
//
//  A = [5, 6, 7, 8, 9]
//  B = 5
//
// Example Output
// Output 1:
//
//  4
// Output 2:
//
//  2

// O(n) time complexity.
#include <bits/stdc++.h>
using namespace std;

long long subarrayXor(int arr[], int n, int m)
{
	long long ans = 0;
	int* xorArr = new int[n];

	unordered_map<int, int> mp;
	xorArr[0] = arr[0];
	for (int i = 1; i < n; i++)
		xorArr[i] = xorArr[i - 1] ^ arr[i];


	for (int i = 0; i < n; i++) {
		int tmp = m ^ xorArr[i];
		ans = ans + ((long long)mp[tmp]);
		if (xorArr[i] == m)
			ans++;
		mp[xorArr[i]]++;
	}

	return ans;
}
