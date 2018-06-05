#pragma once
#include <vector>

class DepthFirstSearch
{
public:
	DepthFirstSearch();
	~DepthFirstSearch();
	
	void search(const std::vector<std::vector<int>> &graph, const int &vertexes, const int &entrance, const int &exit);
};

