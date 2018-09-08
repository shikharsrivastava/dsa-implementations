#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, int s, int e)
{
	if(s >= e) return;

	int m = (s + e)/2;

	vector<int> temp(e-s+1);
	int counter, i, j;
	counter = 0, i = s, j = m+1;

	// Merging the parts [s..m] and [m+1..e]
	// in temp
	while(i <= m && j <= e)
	{
		if(arr[i] <= arr[j])
			temp[counter++] = arr[i++];
		else
			temp[counter++] = arr[j++];
	}
	
	// Adding the remaining elements
	// Note:- Only one of the below
	// will execute as true, it will
	// be the part of either [s..m] or [m+1..e]
	// which didn't finish merging because the
	// other part finished
	while(i <= m)
		temp[counter++] = arr[i++];
	while(j <= e)
		temp[counter++] = arr[j++];

	// Putting the merged data from
	// temp in the original array
	
	i = 0;
	while(s <= e)
		arr[s++] = temp[i++];
	return;
}

void mergeSort(vector<int>& arr, int s, int e)
{
	// Base condition
	if(s <= e)
		return;

	int m = (s + e) / 2;

	// Sorting both halves
	// [s..m] and [m+1..e]
	// recursively
	mergeSort(arr, s, m);
	mergeSort(arr, m+1, e);

	// Merging the parts
	// sorted above
	merge(arr, s, e);
	
	return;
}

int main()
{
	return 0;
}

