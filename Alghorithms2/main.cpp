// Alghorithms2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <list>
#include "RadixSort.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "GraphConnectedness.h"

int main()
{

	/********************
	*	Stack example
	********************/

	dynlib::Stack stack;

	for (int i = 1; i < 10; i += 2)
	{
		stack.push(i);
	}

	stack.print("Your stack included numbers: ");

	/*******************
	*	Queue example
	*******************/

	dynlib::Queue queue;

	for (int i = 0; i < 10; i += 3)
	{
		queue.enque(i);
	}

	queue.print("Your queue included numbers: ");

	/*******************
	 *	Radix sort
	 ******************/

	dynlib::Queue queueRadix(10);

	RadixSort radix;
	queueRadix = radix.sort(queueRadix);
	queueRadix.print("Sorted by Radix Sort:");

	/***********************
	*	Depth First Search
	***********************/

	std::vector<std::vector<int>> graph =
	{ { 0, 1, 1, 0, 0, },
	{ 1,0,0,1,1 },
	{ 1,0,0,0,0 },
	{ 0,1,0,0,0 },
	{ 0,1,0,0,0 } };

	DepthFirstSearch dfs;
	dfs.search(graph, graph.size(), 0, 4);

	/*************************
	*	Breadth First Search
	*************************/

	BreadthFirstSearch bfs;
	bfs.search(graph, graph.size(), 0, 4);

	/*****************************
	*	Connectedness of a graph
	*****************************/
	// An undirected paht G is connected if there is a path in G between every pair of vertices in V(G).

	GraphConnectedness gc;
	gc.isConnected(graph);
	

	return 0;
}

