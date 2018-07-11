#include <bits/stdc++.h>

/* This section explains the dfs algorithms on any graph. The method is exactly the same for
   trees as well.
*/

	/////////////////////////////////////
	//								   //
	// 	DFS in an unweighted graph 	   //
	//								   //
	/////////////////////////////////////

// The strucutre of the node depending
// on the tyoe of problem
struct Node
{
	// Adjecency list for this node
	vector<int> adj;

	// Entries that this node must have
	// (depending on the problem)
	int a;
	int b;
	.
	.
	.
	int z;

};
// Creating a global visted array so that it
// can be shared between functions. We can also create
// it locally in the main function and pass a reference to it
// in dfs function. It's just a different way of implementation.
// In most cases I prefer this method until the problem dictates otherwise
// Assuming the maximum number of nodes in graph is 10^5 (problem dependent)
bool visited[10e5 + 1];


/* dfs function
   params:
   g - The graph on which we wish to apply dfs
   currNode - The id of the current Node (defaults to 0)
*/

// We are passing the reference of the node to
// prevent copying of the entire graph on each
// function call
void dfs(vector<Node>& g, int currNode = 0)
{

	// Mark this node as visited
	visited[currNode] = true;
	/* Do whatever you want to do when you
	   first reach any node here (dependent on the problem)
	   ....
	   ....
	   ....
	   ....
	 */

	// Move to the neighbouring node
	for(int i=0; i<g[currNode].adj.size(); i++)
	{
		// Getting the ith neighbour of the currNode
		neighbourNode = g[currNode].adj[i];

		// Visit the neighbour only if it hasn't ben visited yet
		if(visited[neighbourNode] == false)
			dfs(g, neighbourNode);
	}

	/* Do whatever you want to do when you
	   exit any node here (dependent on the problem)
	   ....
	   ....
	   ....
	   ....
	 */

}

int main()
{
	/*

	Code for constructing the graph after taking 
	input from the users (dependent on the problem)
	
	vector<Node> graph(sizeOfGraph+1)
	....
	....
	....
	....
	
	*/

	// Clearing the visited array first.
	// Marking all nodes as not visited
	for(int i=0; i<sizeOfGraph + 1; i++)
		visited[i] = false;

	// This will start the dfs from node id 1
	dfs(graph);

	/*
		If we want to start the dfs from some
		other node (say 5)-
	*/

	dfs(graph, 5);
}


	/////////////////////////////////////
	//								   //
	// 	DFS in a weighted graph 	   //
	//								   //
	/////////////////////////////////////

// The strucutre of the node depending
// on the tyoe of problem
struct Node
{
	// Adjecency list for this node
	vector<pair<int, int>> adj;

	// Entries that this node must have
	// (depending on the problem)
	int a;
	int b;
	.
	.
	.
	int z;

};
// Creating a global visted array so that it
// can be shared between functions. We can also create
// it locally in the main function and pass a reference to it
// in dfs function. It's just a different way of implementation.
// In most cases I prefer this method until the problem dictates otherwise
// Assuming the maximum number of nodes in graph is 10^5 (problem dependent)
bool visited[10e5 + 1];


/* dfs function
   params:
   g - The graph on which we wish to apply dfs
   currNode - The id of the current Node (defaults to 0)
*/

// We are passing the reference of the node to
// prevent copying of the entire graph on each
// function call
void dfs(vector<Node>& g, int currNode = 0)
{

	// Mark this node as visited
	visited[currNode] = true;
	/* Do whatever you want to do when you
	   first reach any node here (dependent on the problem)
	   ....
	   ....
	   ....
	   ....
	 */

	// Move to the neighbouring node
	for(int i=0; i<g[currNode].adj.size(); i++)
	{
		// Getting the ith neighbour of the currNode
		// and the weight of the edge
		neighbourNode = g[currNode].adj[i].first;
		weight = g[currNode].adj[i].first.second;

		// Visit the neighbour only if it hasn't ben visited yet
		if(visited[neighbourNode] == false)
			dfs(g, neighbourNode);
	}

	/* Do whatever you want to do when you
	   exit any node here (dependent on the problem)
	   ....
	   ....
	   ....
	   ....
	 */

}

int main()
{
	/*

	Code for constructing the graph after taking 
	input from the users (dependent on the problem)
	
	vector<Node> graph(sizeOfGraph+1)
	....
	....
	....
	....
	
	*/

	// Clearing the visited array first.
	// Marking all nodes as not visited
	for(int i=0; i<sizeOfGraph + 1; i++)
		visited[i] = false;

	// This will start the dfs from node id 1
	dfs(graph);

	/*
		If we want to start the dfs from some
		other node (say 5)-
	*/

	dfs(graph, 5);
}
