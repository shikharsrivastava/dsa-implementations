#include <bits/stdc++.h>
using namespace std;


class SegmentTree
{
	int          size;
	vector<int>  tree;

	public:

	SegmentTree(int n): size(n), tree(n)
	{
	}

	void build(vector<int> arr, int l, int r, int id = 1)
	{
		if(l > r)
			return;
		else if(l == r)
			tree[id] = arr[l];
		else
		{
			int mid = l + (r-l) / 2;
			build(arr, l, mid, id*2);
			build(arr, mid+1, r, id*2+1);

			tree[id] = tree[id*2] + tree[id*2+1];
		}

	}

	void pointUpdate(int newVal, int p, int l, int r, int id = 1)
	{
		if(l == r)
		{
			tree[id] += newVal;
			return;
		}
		
		int mid = l + (r-l)/2;

		if(p <= mid)
			pointUpdate(newVal, p, l, mid, id*2);
		else
			pointUpdate(newVal, p, mid+1, r, id*2+1);

		tree[id] = tree[id*2] + tree[id*2+1];
	}

	int query(int L, int R, int l, int r, int id = 1)
	{
		if(l > R || r < L)
			return 0;
		else if(l >= L && r <= R)
			return tree[id];
		else
		{
			int mid = l + (r-l)/2;
			
			leftAns = query(L, R, l, mid, id*2);
			rightAns = query(L, R, mid + 1, r, id*2+1);

			ans = leftAns + rightAns;
			return ans;
		}
	}

};


struct Node
{
	int val;
	int lazy;
	bool lazySet;
}

class SegmentTree
{
	int          size;
	vector<Node>  tree;
	public:

	SegmentTree(int n): size(n), tree(n)
	{
		for(int i=0; i<n; i++)
		{
			tree[i].val = 0;
			tree[i].lazy = 0;
			tree[i].lazySet = false;
		}
	}

	void build(vector<int> arr, int l, int r, int id = 1)
	{
		if(l == r)
			tree[id].val = arr[l];
		else
		{
			int mid = l + (r-l) / 2;
			build(arr, l, mid, id*2);
			build(arr, mid+1, r, id*2+1);

			tree[id].val = tree[id*2].val + tree[id*2+1].val;
		}

	}

	void rangeUpdate(int newVal,int L, int R, int l, int r, int id = 1)
	{
		if(tree[id].lazySet == true)
		{
			tree[id].val += (r - l + 1) * tree[id].lazy;
			
			if(id*2 < size)
			{
				tree[id*2].lazySet = true;
				tree[id*2].lazy += tree[id].lazy;
			}
			if(id*2+1 < size)
			{
				tree[id*2+1].lazySet = true;
				tree[id*2+1].lazy += tree[id].lazy;
			}

			tree[id].lazySet = false;
			tree[id].lazy = 0;
		}

		if(l > R || r < L)
			return ;
		else if(l >= L && r <= R)
		{	
			tree[id].lazySet = true;
			tree[id].lazy += newVal;
			return;
		}
		else
		{
			int mid = l + (r-l)/2;
			
			rangeUpdate(newVal, L, R, l, mid, id*2);
			rangeUpdate(newVal, L, R, mid + 1, r, id*2+1);

			return
		}


	}

	int query(int L, int R, int l, int r, int id = 1)
	{
		if(tree[id].lazySet == true)
		{
			tree[id].val += (r - l + 1) * tree[id].lazy;
			
			if(id*2 < size)
			{
				tree[id*2].lazySet = true;
				tree[id*2].lazy += tree[id].lazy;
			}
			if(id*2+1 < size)
			{
				tree[id*2+1].lazySet = true;
				tree[id*2+1].lazy += tree[id].lazy;
			}

			tree[id].lazySet = false;
			tree[id].lazy = 0;
		}

		if(l > R || r < L)
			return 0;
		else if(l >= L && r <= R)
			return tree[id].val;
		else
		{
			int mid = l + (r-l)/2;
			
			leftAns = query(L, R, l, mid, id*2);
			rightAns = query(L, R, mid + 1, r, id*2+1);

			ans = leftAns + rightAns;
			return ans;
		}
	}

};



