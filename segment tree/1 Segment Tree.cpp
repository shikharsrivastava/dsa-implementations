/* This is my implementation of Segment Trees that I find easy to use when solving
   problems. 

 */

#include <bits/stdc++.h>
using namespace std;


         //////////////////////////////////////////////
         //                                          //
         // Simple Implementaion of Segment Tree     //
         //                                          //
         //////////////////////////////////////////////

/* This is a simple Segment Tree that is built on an array of integers (arr) 
   that can be used to query range sum in the array. It can be used to get the
   sum of integers from index L to R in the array (arr). Each node in the tree
   stores the sum of integers in the array in the range that this node represents.

   The implementation of the Node, build, query and update functions are highly dependent
   on the question, but the strcture of the code is mostly same. The aim of this implementation
   is to give you an idea of the implementaion of these recursive functions which will mostly
   be same for any problem, the work that these functions do (how to merge two nodes of the tree, 
   what values should be stored in a node, etc) depends on the problem to be solved. Below is an
   implementation of a Segment tree where each node stores just an integer value (The sum of the
   range that this node represents) and merging two ranges (Nodes) is done by adding the values
   of sum of individual ranges(left and right) because sum([L..R]) = sum([L..mid]) + sum([mid+1..arr])
 */


// Class to encapsulate the segment tree structure

class SegmentTree
{
	// The size of the array that will hold the segment tree
	int          size;
	// The array that will hold the segment tree
	vector<int>  tree;

	public:

	// Constructor to initialize the values of size
	SegmentTree(int n): size(n), tree(n, 0)
	{
		// Initializers list initialises the size = n
		// and initalizes tree as a vector of size n
		// where every entry is initialised with 0
	}


	// Recursive function to build the segment Tree
	// Param -
	// arr - The array on which the segment tree has to
	//       be built
	// l   - The leftmost index of the current range
	// r   - The rightmost index of the current range
	// id  - The index of the current node in the segment tree
	void build(vector<int> arr, int l, int r, int id = 1)
	{
		// If we have reached the leaf node
		if(l == r)
			tree[id] = arr[l];

		// I we haven't reached the leaf node yet
		else
		{
			// finding the mid of the current range
			int mid = l + (r-l) / 2;

			// building the left subtree of the current node
			build(arr, l, mid, id*2);

			// building the right subtree of the current node
			build(arr, mid+1, r, id*2+1);

			// Once both the left and right subtrees
			// are fully built. We can build the subtree
			// rooted at the current node by filling the
			// required information in the current node


			// It is completely dependent of the problem
			// how two child nodes are merged to get the
			// value of a parent node.

			// Since we are building a segment tree that
			// stores the sum of integers in the array (arr)
			// in the range that this node represents, we can
			// merge the two child nodes by 
			// simply adding the values of child nodes to get the
			// value of parent Node because
			// sum([l..mid]) + sum([mid+1..r]) = sum([l..r])


			tree[id] = tree[id*2] + tree[id*2+1];

		}
	}

	// The type of update that we want to do on the segment tree
	// is also completely problem dependent. The implementation 
	// will differ problem to problem but the structure of the
	// recursive function is mostly the same. Below is the implementation
	// of a point update function which adds a new value to the existing
	// value in the array(arr) and updates the segment tree accordingly
	// to reflect the changes


	// Recursive function to add a new value to the
	// value at a a point p and update the segment
	// tree accordingly
	// Param -
	// newVal - The new value to be added at a point
	// p      - The index where this new value has to be
	//          added
	// l      - The leftmost index of the current range
	// r      - The rightmost index of the current range
	// id     - The index of the current node in the segment tree

	void pointUpdate(int newVal, int p, int l, int r, int id = 1)
	{
		// If we have reached the leaf node
		if(l == r)
		{
			tree[id] += newVal;
			return;
		}

		// I we haven't reached the leaf node yet
		int mid = l + (r-l)/2;

		// Checking if the point to be updated
		// is in the left subtree or right subtree
		// and calling the recursive update function
		// accordingly
		if(p <= mid)
			pointUpdate(newVal, p, l, mid, id*2);
		else
			pointUpdate(newVal, p, mid+1, r, id*2+1);

		// Once we have reached this point, it means that
		// the segment tree is updated properly in the left and
		// right subtree of the current Node. We now have to 
		// update the changes upwards towards the root so that
		// the segment tree reflects the updated sum of all the ranges


		// It is completely dependent of the problem
		// how two child nodes are merged to get the
		// value of a parent node.

		// Since we are building a segment tree that
		// stores the sum of integers in the array (arr)
		// in the range that this node represents, we can
		// merge the two child nodes by 
		// simply adding the values of child nodes to get the
		// value of parent Node because
		// sum([l..mid]) + sum([mid+1..r]) = sum([l..r])
		tree[id] = tree[id*2] + tree[id*2+1];
	}

	// The type of query that we want to do on the segment tree
	// is also completely problem dependent. The implementation 
	// and the return value of the function
	// will differ problem to problem but the structure of the
	// recursive function is mostly the same. Below is the implementation
	// of a range query function which get the sum of integers in the range
	// L to R of the array on which the Segment Tree is built.


	// Recursive function to query the segment tree
	// from range L to R
	// Param -
	// L  - The leftmost index of the query range
	// R  - The rightmost index of the query range
	// l  - The leftmost index of the current range
	// r  - The rightmost index of the current range
	// id - The index of the current node in the segment tree
	// 
	// Return -
	// An integer value which is the sum of integers
	// in the query range L to R

	int query(int L, int R, int l, int r, int id = 1)
	{
		// If the current range doen't overlap
		// with the range we want to query [L..R]
		if(l > R || r < L)
			return 0;
		// If the current range lies completely
		// inside the range we want to query [L..R]
		else if(l >= L && r <= R)
			return tree[id];
		// If only some part of the
		// current range overlaps with the
		// query range [L..R]
		else
		{
			int mid = l + (r-l)/2;
			
			// Getting the correct answer for
			// our query range [L..R] which lies
			// in the left[l..mid] and right[mid+1..r]
			// of our current range[l..r] by querying
			// the left and right subtree of the current node
			leftAns = query(L, R, l, mid, id*2);
			rightAns = query(L, R, mid + 1, r, id*2+1);

			// It is completely dependent of the problem
			// how two child nodes are merged to get the
			// value of a parent node.

			// Since we are building a segment tree that
			// stores the sum of integers in the array (arr)
			// in the range that this node represents, we can
			// merge the two child nodes by 
			// simply adding the values returen by querying
			// the child nodes to get the value of ans which lies
			// in the current range [l..r]
			// sum([l..mid]) + sum([mid+1..r]) = sum([l..r])
			ans = leftAns + rightAns;
			return ans;
		}
	}

};


         ///////////////////////////////////////////////////////////////
         //                                                           //
         //   Implementaion of Segment Tree with lazy propogation     //
         //                                                           //
         ///////////////////////////////////////////////////////////////


/* This is a Segment Tree that is built on an array of integers (arr) 
   that can be used to query range sum in the array. It can be used to get the
   sum of integers from index L to R in the array (arr). Each node in the tree is of
   type Node defined below. It stores the sum of integers in the array in the range
   that this node represents in the field val. The value that hasn't been added to this
   node yet in lazy and the boolean value lazySet to indicate weather we have to still update
   the node by adding the lazy value.

   The implementation of the Node, build, query and update functions are highly dependent
   on the question, but the strcture of the code is mostly same. The aim of this implementation
   is to give you an idea of the implementaion of these recursive functions which will mostly
   be same for any problem, the work that these functions do (how to merge two nodes of the tree, 
   what values should be stored in a node, etc) depends on the problem to be solved. Below is an
   implementation of a Segment tree where each node stores just an integer value (The sum of the
   range that this node represents) and merging two ranges (Nodes) is done by adding the values
   of sum of individual ranges(left and right) because sum([L..R]) = sum([L..mid]) + sum([mid+1..arr])
 */

struct Node
{
	// The value of sum for the range
	// that this node represents
	int val;
	// The value lazy for this node
	// This is the value that has to 
	// be added in the range represented
	// by this node before moving down the tree
	// or answering queries
	int lazy;
	// A falg varibale to idicate weather
	// the value in lazy needs to be added
	// to the node or not 
	bool lazySet;
}

class SegmentTree
{
	// The size of the array that will hold the segment tree
	int          size;
	// The array that will hold the segment tree
	vector<Node>  tree;
	public:

	// Constructor to initialize the values of size
	SegmentTree(int n): size(n), tree(n)
	{
		// Since the tree is not a vector of
		// any primitive datatype and we haven't
		// made any constructor for struct Node, we
		// are initialising the values in this way instead
		// of initialisers list
		for(int i=0; i<n; i++)
		{
			// Initially everything is set to 0
			tree[i].val = 0;
			tree[i].lazy = 0;
			tree[i].lazySet = false;
		}
	}

	// Recursive function to build the segment Tree
	// Param -
	// arr - The array on which the segment tree has to
	//       be built
	// l   - The leftmost index of the current range
	// r   - The rightmost index of the current range
	// id  - The index of the current node in the segment tree
	void build(vector<int> arr, int l, int r, int id = 1)
	{
		// If we have reached the leaf node
		if(l == r)
			tree[id].val = arr[l];
		// I we haven't reached the leaf node yet
		else
		{
			// finding the mid of the current range
			int mid = l + (r-l) / 2;

			// building the left subtree of the current node
			build(arr, l, mid, id*2);

			// building the right subtree of the current node
			build(arr, mid+1, r, id*2+1);

			// Once both the left and right subtrees
			// are fully built. We can build the subtree
			// rooted at the current node by filling the
			// required information in the current node


			// It is completely dependent of the problem
			// how two child nodes are merged to get the
			// value of a parent node.

			// Since we are building a segment tree that
			// stores the sum of integers in the array (arr)
			// in the range that this node represents, we can
			// merge the two child nodes by 
			// simply adding the values of child nodes to get the
			// value of parent Node because
			// sum([l..mid]) + sum([mid+1..r]) = sum([l..r])

			// Note - Since this is a structure, we cannot add it
			// directly without operator overloading. We will instead
			// add the val attribute from each node to make up the
			// val attribute in the parent node
			tree[id].val = tree[id*2].val + tree[id*2+1].val;
		}

	}

	// The type of update that we want to do on the segment tree
	// is also completely problem dependent. The implementation 
	// will differ problem to problem but the structure of the
	// recursive function is mostly the same. Below is the implementation
	// of a range update function which adds a new value to all the elements
	// in the range L to R in array(arr) and updates the segment tree accordingly
	// to reflect the changes. It updates it using Lazy propogation to achive
	// O(logN) update.


	// Recursive function to add a new value to all
	// values in range L to R and update the segment
	// tree accordingly
	// Param -
	// newVal - The new value to be added at a point
	// L      - The leftmost index of the query range
	// R      - The rightmost index of the query range
	// l      - The leftmost index of the current range
	// r      - The rightmost index of the current range
	// id     - The index of the current node in the segment tree
	void rangeUpdate(int newVal,int L, int R, int l, int r, int id = 1)
	{
		// This section updates the val
		// attribute of the node if the lazySet attribute is
		// true. If the lazySet attribute is true, it means
		// that some other update operation was made on this node
		// previously or any of its ancestor was updated which
		// passed down the lazy value to this node.

		// Before moving forward with any operation, we first
		// have to perform this operation so that the segment
		// Tree is consistent and has the correct information.


		// After updating the node representing th current range[l..r], we
		// pass the lazy value to its children which represent the ranges
		// [l..mid] and [mid+1..r] respectively.

		// Once we have done all this work we set the lazy value for the 
		// current node as 0 and lazySet flagas false so that we don't 
		// perform this operation on this node again unless it is set again
		if(tree[id].lazySet == true)
		{
			// We need to add the same value to range 
			// represented by this node [l..r] so the total
			// sum of this range will increse by 
			// (number of elements in the range * nlazyValue) 
			tree[id].val += (r - l + 1) * tree[id].lazy;
			
			// Once we have updated the current range, we
			// will pass the lazy value to its child nodes.
			// rather than going all the way to the leaves and
			// updating everything in the path, we just set
			// the lazy value of the nodes which will be evaluated
			// when someone queries those nodes of we go through
			// that path in the tree. In this way we can achive
			// range update in (logN)

			// Setting lazy for left subtree
			if(id*2 < size)
			{
				tree[id*2].lazySet = true;
				tree[id*2].lazy += tree[id].lazy;
			}

			// Setting lazy for the right subtree
			if(id*2+1 < size)
			{
				tree[id*2+1].lazySet = true;
				tree[id*2+1].lazy += tree[id].lazy;
			}

			// Seting the lazySet flag for this
			// node as false because this node
			// has already been updated to the latest 
			// values and has passed the lazy values to the 
			// children
			tree[id].lazySet = false;
			tree[id].lazy = 0;
		}
		// If our current range
		// doesn't overlap with the
		// range we want to update
		if(l > R || r < L)
			return ;

		// If the current range lies completely
		// in the range we want to update
		else if(l >= L && r <= R)
		{	
			// We just update the lazy value of the
			// node isntead of making the entre addition
			// to every node all the way to the leaves. This is
			// the use of lazy to make updates faster. 
			// Whenever someone will query this node, the lazy value
			// will be updated like above so that the node has the updated
			// values

			// Setting the lazySet flag for
			// this node to true
			tree[id].lazySet = true;
			// Adding the lazy value to any already
			// existing lazy value
			tree[id].lazy += newVal;
			return;
		}
		// If only some part of the
		// current range overlaps with the
		// query range [L..R]
		else
		{
			int mid = l + (r-l)/2;
			
			// Updating the part of current range which lies
			// in our query range [L..R]. We update the left
			// [l..mid] and right[mid+1..r] subtree 
			// of our current range[l..r] by calling the range update
			// function on the left and right subtree of the current node
			// To see more clearly how this works you can check
			// https://codeextractor.wordpress.com/2016/07/11/playing-with-ranges-segment-tree/

			rangeUpdate(newVal, L, R, l, mid, id*2);
			rangeUpdate(newVal, L, R, mid + 1, r, id*2+1);

			// Once the subtrees are update, we update the current node
			// to reflect the changes. This step is important to propogate
			// the changes made at any node upwards in the tree so that all the
			// nodes that overlap with the update range [L..R] are updated.
			tree[id].val = tree[id*2].val + tree[id*2+1].val;
			return
		}


	}

	// The type of query that we want to do on the segment tree
	// is also completely problem dependent. The implementation 
	// and the return value of the function
	// will differ problem to problem but the structure of the
	// recursive function is mostly the same. Below is the implementation
	// of a range query function which get the sum of integers in the range
	// L to R of the array on which the Segment Tree is built. It follows the
	// lazy procedure and first updates any node it reaches and propogates the
	// lazy value to its children before processing the node. In this way we always
	// get the correct value for a node when we begin processing it.


	// Recursive function to query the segment tree
	// from range L to R
	// Param -
	// L  - The leftmost index of the query range
	// R  - The rightmost index of the query range
	// l  - The leftmost index of the current range
	// r  - The rightmost index of the current range
	// id - The index of the current node in the segment tree
	// 
	// Return -
	// An integer value which is the sum of integers
	// in the query range L to R

	int query(int L, int R, int l, int r, int id = 1)
	{
		// This section updates the val
		// attribute of the node if the lazySet attribute is
		// true. If the lazySet attribute is true, it means
		// that some other update operation was made on this node
		// previously or any of its ancestor was updated which
		// passed down the lazy value to this node.

		// Before moving forward with any operation, we first
		// have to perform this operation so that the segment
		// Tree is consistent and has the correct information.


		// After updating the node representing th current range[l..r], we
		// pass the lazy value to its children which represent the ranges
		// [l..mid] and [mid+1..r] respectively.

		// Once we have done all this work we set the lazy value for the 
		// current node as 0 and lazySet flagas false so that we don't 
		// perform this operation on this node again unless it is set again
		if(tree[id].lazySet == true)
		{
			// We need to add the same value to range 
			// represented by this node [l..r] so the total
			// sum of this range will increse by 
			// (number of elements in the range * nlazyValue) 
			tree[id].val += (r - l + 1) * tree[id].lazy;
			
			// Once we have updated the current range, we
			// will pass the lazy value to its child nodes.
			// rather than going all the way to the leaves and
			// updating everything in the path, we just set
			// the lazy value of the nodes which will be evaluated
			// when someone queries those nodes of we go through
			// that path in the tree. In this way we can achive
			// range update in (logN)

			// Setting lazy for left subtree
			if(id*2 < size)
			{
				tree[id*2].lazySet = true;
				tree[id*2].lazy += tree[id].lazy;
			}

			// Setting lazy for the right subtree
			if(id*2+1 < size)
			{
				tree[id*2+1].lazySet = true;
				tree[id*2+1].lazy += tree[id].lazy;
			}

			// Seting the lazySet flag for this
			// node as false because this node
			// has already been updated to the latest 
			// values and has passed the lazy values to the 
			// children
			tree[id].lazySet = false;
			tree[id].lazy = 0;
		}
		
		// If the current range doen't overlap
		// with the range we want to query [L..R]

		if(l > R || r < L)
			return 0;
		// If the current range lies completely
		// inside the range we want to query [L..R]
		else if(l >= L && r <= R)
			return tree[id].val;

		// If only some part of the
		// current range overlaps with the
		// query range [L..R]
		else
		{
			int mid = l + (r-l)/2;
			

			// Getting the correct answer for
			// our query range [L..R] which lies
			// in the left[l..mid] and right[mid+1..r]
			// of our current range[l..r] by querying
			// the left and right subtree of the current node

			leftAns = query(L, R, l, mid, id*2);
			rightAns = query(L, R, mid + 1, r, id*2+1);

			// Since we are building a segment tree that
			// stores the sum of integers in the array (arr)
			// in the range that this node represents, we can
			// merge the two child nodes by 
			// simply adding the values returen by querying
			// the child nodes to get the value of ans which lies
			// in the current range [l..r]
			// sum([l..mid]) + sum([mid+1..r]) = sum([l..r])

			ans = leftAns + rightAns;
			return ans;
		}
	}

};



