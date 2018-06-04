#include "stdafx.h"
#include "RandomNumberGenerator.h"
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

namespace dynlib {

	RandomNumberGeneartor::RandomNumberGeneartor()
	{
	}



	RandomNumberGeneartor::~RandomNumberGeneartor()
	{
	}

	std::vector<int> RandomNumberGeneartor::fillVector(int &length)
	{
		srand(time(NULL));
		std::vector<int> vector;

		for (int i = 0; i < length; i++)
		{
			vector.push_back(rand() % 100 + 1);
		}
		return vector;
	}
}