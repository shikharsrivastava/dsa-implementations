#include <bits/stdc++.h>
using namespace std;

/* Note - A tree is nothing but an acyclic graph. The following implementation of graphs is
		  exactly how trees are implemented using STL as well, there is no difference in the 
		  method of constructing them


		//////////////////////////////////////////////////
		//												//
		//	vector representation of a simple graph 	//
		//												//
		//////////////////////////////////////////////////
	
	
	vector<vector<int> > graph(20);

	We have created a graph with 20 nodes. It is a vector of vectors (better version of a 2D array)
	We can visualize this gragh as a 2D array where the each row (i) contains a vector 
	which is the adjecency list of for the node with id (i). Initially it will look like this
	
	v
	e
	c
	t
	o
	r
	|
	v

	0 -> empty vector
	1 -> empty vector
	2 -> empty vector
	.
	.
	19 -> empty vector


	Now suppose we want to add a bidirectional edge between node 4 and 5.
	We can do it as -

	graph[4].push_back(5)
	graph[5].push_back(4)


	Now our graph will look like


	v
	e
	c
	t
	o
	r
	|
	v

	0 -> empty vector
	1 -> empty vector
	2 -> empty vector
	3 -> empty vector
	4 -> [5]
	5 -> [4]
	6 -> empty vector
	.
	.
	19 -> empty vector

	As you can see, we are simple using the 2D array representation of adjecency
	list using vectors. Using vectors make it dynamic, memory efficient, lets us use 
	predefined function and passing it arround in functions without thinking about pointers

	*/


/*	Below is the code to build user defined graph after taking various inputs from the user */

int main()
{
	// Number of nodes in the graph
	int n;

	// Taking maximum number of nodes as input from user
	cin >> n;

	// Creating an empty graph of n+1 nodes (0 to n) with no edges
	vector<vector<int>> g(n+1); 

	// Number of edges in the graph
	int e;	

	// Taking the number of edges as input from the user
	cin >> e;


	// Lopping to take all (e) edges as input from user
	for(int i=0; i<e; i++)
	{
		// Taking the information of edge as
		// input from the user in the format
		// of two space separated integers a and b
		// meaning there is an edge between node id a and
		// node id b
		cin >> a >> b;

		// Adding the edge to our graph
		g[a].push_back(b);

		// If the edges are bidirectional
		// we should also add a reverse edge, otherwise
		// this step is not required
		g[b].push_back(a);
	}

	// Finally our graph is constructed an we can do any operation we want on it

}




/*


		//////////////////////////////////////////////////////////
		//														//
		//	vector representation of a simple weighted graph 	//
		//														//
		//////////////////////////////////////////////////////////
	
	
	vector<vector<pair<int, int> > > graph(20);

	We have created a graph with 20 nodes. It is a vector of vectors of pairs
	We can visualize this gragh as a 2D array where the each row (i) contains a vector of pairs 
	which is the adjecency list of for the node with id (i) and 
	it contains two entries (neighbourId, weight).
	Initially it will look like this - 
	
	v
	e
	c
	t
	o
	r
	|
	v

	0 -> empty vector of pairs
	1 -> empty vector of pairs
	2 -> empty vector of pairs
	.
	.
	19 -> empty vector of pairs


	Now suppose we want to add a bidirectional edge between 
	node 4 and 5 with weight 20
	We can do it as -

	graph[4].push_back(make_pair(5, 20))
	graph[5].push_back(make_pair(4, 20))

	Note:- The make_pair is a template function which makes a pair object
		   from the entries you pass in it.

		   Example -
		   pair<int, int> myPair = make_pair(1, 2)

		   We can access the elements using :-

		   myPair.first  -> reference to the first element in the pair
		   myPair.second -> reference to the second elemnt in the pair


	Now our graph will look like


	v
	e
	c
	t
	o
	r
	|
	v

	0 -> empty vector
	1 -> empty vector
	2 -> empty vector
	3 -> empty vector
	4 -> [(5, 20)]
	5 -> [(4, 20)]
	6 -> empty vector
	.
	.
	19 -> empty vector


	Now if we further add a bidirectional edge between node 1 and 4 with weight 40
	we can do it like this

	graph[1].push_back(make_pair(4, 40))
	graph[4].push_back(make_pair(1, 40))


	Now our graph will look like

	v
	e
	c
	t
	o
	r
	|
	v

	0 -> empty vector
	1 -> [(4, 40)]
	2 -> empty vector
	3 -> empty vector
	4 -> [(5, 20), (1, 40)]
	5 -> [(4, 20)]
	6 -> empty vector
	.
	.
	19 -> empty vector



	As you can see, we are simple using the 2D array representation of adjecency
	list using vector of pairs. Using vectors make it dynamic, memory efficient, lets us use 
	predefined function and passing it arround in functions without thinking about pointers

	*/


/*	Below is the code to build user defined graph after taking various inputs from the user */

int main()
{
	// Number of nodes in the graph
	int n;

	// Taking maximum number of nodes as input from user
	cin >> n;

	// Creating an empty graph of n+1 nodes (0 to n) with no edges
	vector<vector<pair<int, int> > > g(n+1); 

	// Number of edges in the graph
	int e;	

	// Taking the number of edges as input from the user
	cin >> e;


	// Lopping to take all (e) edges as input from user
	for(int i=0; i<e; i++)
	{
		// Taking the information of edge as
		// input from the user in the format
		// of three space separated integers a, b and c
		// meaning there is an edge between node a and
		// node b with weight c
		cin >> a >> b >> c;

		// Adding the edge to our graph
		g[a].push_back(make_pair(b,c));

		// If the edges are bidirectional
		// we should also add a reverse edge, otherwise
		// this step is not required
		g[b].push_back(make_pair(a, c));
	}

	// Finally our graph is constructed an we can do any operation we want on it

}



		//////////////////////////////////////////////////////////
		//														//
		//	vector representation of a complex weighted graph 	//
		//														//
		//////////////////////////////////////////////////////////


/*	Depending on the problem a 
	node in graph may be an abstract
	datatype which contains multiple
	entries.

*/

/* Node of a graph */

struct Node
{
	// A vector to contain the adjecency list of a node
	// It is a vector of pairs which will contain the node ids 
	// of its neighbours and the weights
	vector<pair<int, int> > adj;
	

	//More entries depending
	//on the problem
	
	int a;
	int b;
	.
	.
	.
	int z;

};

// Creating an empty graph of 20 nodes where
// each noe is of type Node
// Note :- it is not a vector of vectors because
//		   the Node data type already contains a vector
//		   to serve as adjececncy list

vector<Node> g(20)

/*
	Initially our graph looks like
	
	v
	e
	c
	t
	o
	r
	|
	v

	0 | x = 0, y = 0, adj = empty vector|
	1 | x = 0, y = 0, adj = empty vector|
	2 | x = 0, y = 0, adj = empty vector|
	.
	.
	19| x = 0, y = 0, adj = empty vector|

	Now suppose we want to add a bidirectional edge between node 4 and 5
	with weight 20
	We can do it as -

	graph[4].adj.push_back(make_pair(5, 20))
	graph[5].adj.push_back(make_pair(4, 20))


	Now our graph will look like

	0 | x = 0, y = 0, adj = empty vector|
	1 | x = 0, y = 0, adj = empty vector|
	2 | x = 0, y = 0, adj = empty vector|
	3 | x = 0, y = 0, adj = empty vector|
	4 | x = 0, y = 0, adj -> [(5, 20)]|
	5 | x = 0, y = 0, adj -> [(4, 20)]|
	.
	.
	19| x = 0, y = 0, adj = empty vector|


*/

/*	Below is the code to build user defined graph after taking various inputs from the user */

int main()
{
	// Number of nodes in the graph
	int n;

	// Taking maximum number of nodes as input from user
	cin >> n;

	// Creating an empty graph of n+1 nodes (0 to n) with no edges
	vector<Node> g(n+1); 

	// Number of edges in the graph
	int e;	

	// Taking the number of edges as input from the user
	cin >> e;


	// Lopping to take all (e) edges as input from user
	for(int i=0; i<e; i++)
	{
		// Taking the information of edge as
		// input from the user in the format
		// of three space separated integers a, b and c
		// meaning there is an edge between node a and
		// node b with weight c
		cin >> a >> b >> c;

		// Adding the edge to our graph
		g[a].adj.push_back(make_pair(b, c));

		// If the edges are bidirectional
		// we should also add a reverse edge, otherwise
		// this step is not required
		g[b].adj.push_back(make_pair(a, c));
	}

	// Finally our graph is constructed an we can do any operation we want on it

}