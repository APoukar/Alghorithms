#include "stdafx.h"
#include "BreadthFirstSearch.h"
#include <iostream>
#include "Queue.h"


BreadthFirstSearch::BreadthFirstSearch()
{
}


BreadthFirstSearch::~BreadthFirstSearch()
{
}

void BreadthFirstSearch::search(const std::vector<std::vector<int>>& graph, const int & vertexes, const int & entrance, const int & exit)
{
	int dst;

	std::vector<int> distances(vertexes, -1);

	bool path = false;

	int v = entrance;

	dynlib::Queue queue;

	queue.enque(v);

	distances[v] = 0;

	while (!queue.isEmpty()) {
		v = queue.deque();

		std::cout << "Processing vertex: " << v << '\n';

		dst = distances[v] + 1;

		for (int j = 0; j <= vertexes - 1; j++) {
			if (graph[v][j] && distances[j] == -1) {
				queue.enque(j);

				distances[j] = dst;

				if (j == exit) {
					path = true;
					break;
				}
			}
		}
		if (path)
		{
			break;
		}
	}

	while (!queue.isEmpty())
	{
		queue.deque();
	}

	if (path) {
		v = exit;
		queue.enque(v);

		while (v != entrance)
		{
			dst = distances[v] - 1;

			for (int i = 0; i <= vertexes - 1; i++) {
				if (graph[v][i] && distances[i] == dst) {
					queue.enque(i);
					v = i;
					break;
				}
			}
		}

		queue.print("Way out of the maze (from exit to entrance):");
	}
	else
	{
		std::cout << "There is no way from this maze";
	}
}
