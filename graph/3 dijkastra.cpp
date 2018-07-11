#include <bits/stdc++.h>

/* This section explains the dijkastras algorithms on any graph. The method is exactly the same for
   trees as well.
*/

	//////////////////////////////////////
	//								   	//
	// 	Dijkastra in an weighted graph 	//
	//								    //
	//////////////////////////////////////



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
// in dijkastra function. It's just a different way of implementation.
// In most cases I prefer this method until the problem dictates otherwise
// Assuming the maximum number of nodes in graph is 10^5 (problem dependent)
bool visited[10e5 + 1];


/* dijkastra function
   params:
   g - The graph on which we wish to apply dijkastra
   startingNode - The node id from where you want the shortest path (defaults to 1)

   return value:
   returns a vetcor<int> where the ith index has the value of 
   shortest path from startingNode to node i  
*/

// We are passing the reference of the node to
// prevent copying of the entire graph on each
// function call
vector<int> dijkastra(vector<Node>& g, startingNode = 1)
{


	// Creating a dijkastra prioriy queue using STL
	// priority_queue class. It is a queue of pair to 
	// contian the cumulative weight of the path from 
	// startingNode to the node in the second entry in
	// the pair
	priority_queue<pair<int, int> > q;

	/* priority queue always keeps the LARGEST
	   element in the front of the queue. In case
	   of pairs, comparision is done from first to second

	   Example -
	   (4, 1) > (3, 20)
	   (4, 20) > (4, 18)
	 */

	// The number of nodes in the graph
	int n = g.size();

	// Creating a vector to store the shortest
	// path. The size of vector is equal to the
	// size of the graph and all values are initialised
	// with -10^5 (infinite)
	vector<int> distance(n, 10e5);

	// pushing the shortest path from the starting
	// node and the starting node in the queue
	q.push(make_pair(-0, startingNode));

	/*
		Note:- We are pushing the distance value as negative (-)
			   because priority queue puts the largest element in
			   front of the queue, but we want the smallest element
			   We can pass an additional comparator when defining 
			   the queue, but this trick is relatively simple because

			   20 > 5 but -20 < -5

			   Also we are passing the negative distance value as the first
			   value of the pair because we want the priority queue to be
			   sorted by distance, not the node id. So the positioning here
			   is important.
	*/


	// Starting the Dijkastra loop
	// looping till there is more than 1
	// element in the queue
	while(!q.empty())
	{
		
		// Getting the distance till the current
		// node and the current node
		distanceTillCurrNode = -q.top().first;
		currNode = q.top().second;

		/* Note - Since we introduced a negative sign earlier
				  we have to put a negative signe again to get 
				  the correct result.

				  Also priority queue has method name top() instead
				  of front() like normal queue
		*/

		// Removing the top element from queue
		q.pop();


		// If we have already visited the node
		// we will not process it again and move
		// to the next element in the queue
		if(visited[currNode] == true)
			continue;

		// Mark this node as visited
		visited[currNode] = true;

		// Since this is the first time we have visited the
		// node, according to dijkastras algorithm the value of
		// distanceTillCurrNode should be the shortest path from 
		//startNode to the currNode

		// But we don't need the fllowing line because
		// before reaching this node we already have updated
		// the distance in line 168 when we were at the 
		// predecessor of this node in the shortest path

		// distance[currNode] = distanceTillCurrNode; //



		// Looping through all the neighbours 
		for(int i=0; i<graph[currNode].adj.size(); i++)
		{
			// Getting the id of neighbouring node and
			// the weight of the edge
			neighbourNode = graph[currNode].adj[i].second;
			weight = graph[currNode].adj[i].first;

			// Checking if the neighbouring node is already
			// visited. We won't add it to the dijkastras queue if
			// its already visited
			if(visited[neighbourNode] == true)
				continue;

			// Applying dijkastras algorithm

			if (distanceTillCurrNode + weight < distance[neighbourNode])
			{
				// Updating the distance with newDistance
				newDistance = distanceTillCurrNode + weight;
				distance[neighbourNode] = newDistance;
					
				// Pushing the new distance in the
				// priority queue with negative (-) sign
				q.push(make_pair(-newDistance, neighbourNode));
			}
		} // Dijkastras algorithm finished

		return distance;
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

	// This will apply dijkastra from node id 1
	vector<int> shortestDistance = dijkastra(graph);

	/*
		If we want to apply dijkastra from some
		other node (say 5)-
	*/

	vector<int> shortestDistance = dijkastra(graph, 5);
}


