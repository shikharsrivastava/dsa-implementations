#include<bits/stdc++.h>

using namespace std;


void quickSort(vector<int>& arr, int s, int e)
{
	// Base condition
	if(s <=e )
		return;
	
	// finding the position of
	// partition element (the element
	// which is at its correct position)
	// This function will find and put 
	// the partition element at is correct
	// place
	int p = partition(arr, s, e);

	// the element at p is already
	// at it's correct position
	// so recursively sorting the
	// left and right parts of the array
	quickSort(arr, s, p-1);
	quickSort(arr, p+1, e)

}
