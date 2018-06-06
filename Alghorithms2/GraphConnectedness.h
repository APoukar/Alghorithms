#pragma once
#include <vector>


class GraphConnectedness
{
public:
	GraphConnectedness();
	~GraphConnectedness();

	void isConnected(const std::vector<std::vector<int>> &graph);
};

