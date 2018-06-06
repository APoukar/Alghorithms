#pragma once
#include <vector>


class BreadthFirstSearch
{
public:
	BreadthFirstSearch();
	~BreadthFirstSearch();

	void search(const std::vector<std::vector<int>> &graph, const int &vertexes, const int &entrance, const int &exit);
};

