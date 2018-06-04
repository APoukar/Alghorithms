#pragma once
#include <vector>

namespace dynlib {

	class RandomNumberGeneartor
	{
	public:
		RandomNumberGeneartor();
		~RandomNumberGeneartor();
		std::vector<int> fillVector(int &length);
	};
}
