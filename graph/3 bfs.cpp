#include <bits/stdc++.h>

/* This section explains the bfs algorithms on any graph. The method is exactly the same for
   trees as well.
*/

	/////////////////////////////////////
	//								   //
	// 	BFS in an unweighted graph 	   //
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
// in bfs function. It's just a different way of implementation.
// In most cases I prefer this method until the problem dictates otherwise
// Assuming the maximum number of nodes in graph is 10^5 (problem dependent)
bool visited[10e5 + 1];


/* bfs function
   params:
   g - The graph on which we wish to apply bfs
   startingNode - The node id from where you want bfs to start (defaults to 1)
*/

// We are passing the reference of the node to
// prevent copying of the entire graph on each
// function call
void bfs(vector<Node>& g, startingNode = 1)
{


	// Creating a bfs queue using STL queue class
	queue<int> q;

	// pushing the stating node id in the queue
	q.push(startingNode);

	// Starting the BFS loop
	// looping till there is more than 1
	// element in the queue
	while(!q.empty())
	{
		// It gives the first element in the queue
		currNode = q.front();

		// Removing the first element from queue
		q.pop();

		// If we have already visited the node
		// we will not process it again and move
		// to the next element in the queue
		if(visited[currNode] == true)
			continue;

		// Mark this node as visited
		visited[currNode] = true;

		/* Do whatever you want to do when you
		   first reach any node here (dependent on the problem)
		   ....
		   ....
		   ....
		   ....
		*/

		// Looping through all the neighbours 
		for(int i=0; i<graph[currNode].adj.size(); i++)
		{
			// Getting the id of neighbouring nodes
			neighbourNode = graph[currNode].adj[i];

			// Checking if the neighbouring node is already
			// visited. We won't add it to the bfs queue if
			// its already visited
			if(visited[neighbourNode] == true)
				continue;

			// Adding the node to the bfs queue
			q.push(neighbourNode);
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

	// This will start the bfs from node id 1
	bfs(graph);

	/*
		If we want to start the bfs from some
		other node (say 5)-
	*/

	bfs(graph, 5);
}


	/////////////////////////////////////
	//								   //
	// 	BFS in a weighted graph 	   //
	//								   //
	/////////////////////////////////////



// The strucutre of the node depending
// on the tyoe of problem
struct Node
{
	// Adjecency list for this node
	vector<pair<int, int> > adj;

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
// in bfs function. It's just a different way of implementation.
// In most cases I prefer this method until the problem dictates otherwise
// Assuming the maximum number of nodes in graph is 10^5 (problem dependent)
bool visited[10e5 + 1];


/* bfs function
   params:
   g - The graph on which we wish to apply bfs
   startingNode - The node id from where you want bfs to start (defaults to 1)
*/

// We are passing the reference of the node to
// prevent copying of the entire graph on each
// function call
void bfs(vector<Node>& g, startingNode = 1)
{


	// Creating a bfs queue using STL queue class
	// it is a queue of pair to contian the
	// nieghbouring node id and the weight associated
	// with this edge, the cumulative weight in till this
	// node in the path, etc (problem dependent)
	queue<pair<int, int> > q;

	// pushing the starting node id in the queue
	// Since no edge brought us to this node, we
	// can push any dummy value here (0)
	q.push(make_pair(startingNode, 0));

	// Starting the BFS loop
	// looping till there is more than 1
	// element in the queue
	while(!q.empty())
	{
		// It gives the first element in the queue
		// we extract the node id of the current node
		// and the weight of the edge that brought 
		//us to this node
		currNode = q.front().first;
		weight = q.front().second;

		// Removing the first element from queue
		q.pop();

		// If we have already visited the node
		// we will not process it again and move
		// to the next element in the queue
		if(visited[currNode] == true)
			continue;

		// Mark this node as visited
		visited[currNode] = true;

		/* Do whatever you want to do when you
		   first reach any node here (dependent on the problem)
		   ....
		   ....
		   ....
		   ....
		*/

		// Looping through all the neighbours 
		for(int i=0; i<graph[currNode].adj.size(); i++)
		{
			// Getting the id of neighbouring node and
			// the weight of the edge
			neighbourNode = graph[currNode].adj[i].first;
			neighbourWeight = graph[currNode].adj[i].second;

			// Checking if the neighbouring node is already
			// visited. We won't add it to the bfs queue if
			// its already visited
			if(visited[neighbourNode] == true)
				continue;

			// Adding the information for the neighbouring node to the bfs queue
			q.push(make_pair(neighbourNode, neighbourWeight));
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

	// This will start the bfs from node id 1
	bfs(graph);

	/*
		If we want to start the bfs from some
		other node (say 5)-
	*/

	bfs(graph, 5);
}


