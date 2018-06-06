#include "stdafx.h"
#include "GraphConnectedness.h"
#include "Stack.h"
#include <iostream>


GraphConnectedness::GraphConnectedness()
{
}


GraphConnectedness::~GraphConnectedness()
{
}

void GraphConnectedness::isConnected(const std::vector<std::vector<int>> &graph)
{
	const int n = graph.size();

	std::vector<bool> visited(n, false);

	dynlib::Stack stack;

	stack.push(0);

	visited[0] = true;

	int v;

	while (!stack.isEmpty())
	{
		v = stack.pop();
		std::cout << "Processing vertex: " << v << '\n';

		for (int i = 0; i < n; i++)
		{
			if (graph[v][i] && !visited[i]) {
				stack.push(i);
				visited[i] = true;
			}
		}
	}

	bool all = true;

	for (int i = 0; i < n; i++)
	{
		if (!visited[i]) {
			all = false;
		}

	}

	if (all) std::cout << "The graph is connected\n";
	else std::cout << "The graph is not connected\n";
}
