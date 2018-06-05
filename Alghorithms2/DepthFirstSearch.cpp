#include "stdafx.h"
#include "DepthFirstSearch.h"
#include <iostream>
#include "stack.h"



DepthFirstSearch::DepthFirstSearch()
{
}


DepthFirstSearch::~DepthFirstSearch()
{
}

void DepthFirstSearch::search(const std::vector<std::vector<int>> &graph, const int &vertexes, const int &entrance, const int &exit)
{
	dynlib::Stack stackMaze;

	bool path = false;

	std::vector<bool> visited(vertexes, false);

	int v = entrance;

	stackMaze.push(v);

	visited[v] = true;

	while (v != exit && !stackMaze.isEmpty()) {
		std::cout << "Processing vertex: " << v << '\n';
		if (graph[v][exit]) {
			stackMaze.push(exit);
			v = exit;
			visited[v] = true;
		}
		else
		{
			path = false;
			for (int j = 0; j <= vertexes - 1; j++) {
				if (graph[v][j] && !visited[j]) {
					path = true;
					stackMaze.push(j);
					v = j;
					visited[v] = true;
					break;
				}
			}
			if (!path) {
				v = stackMaze.pop();
				if (!stackMaze.isEmpty()) {
					v = stackMaze.show();
				}
				else
				{
					break;
				}
			}
		}
	}

	if (!stackMaze.isEmpty()) {
		stackMaze.print("Way out of the maze");
	}
	else
	{
		std::cout << "There is no way from this maze";
	}
}
