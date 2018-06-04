#include "stdafx.h"
#include "RadixSort.h"


RadixSort::RadixSort()
{
}


RadixSort::~RadixSort()
{
}

dynlib::Queue RadixSort::sort(dynlib::Queue queue)
{
	int x;
	dynlib::Queue *t[10];

	for (int i = 0; i <= 9; i++)
	{
		t[i] = new dynlib::Queue;
	}

	bool loop = 1;
	int digit = 1;
	int x_mod;
	int x_div;

	while (loop) {
		loop = 0;
		while (!queue.isEmpty()) {
			x = queue.deque();
			x_div = x / digit;
			x_mod = x_div % 10;
			t[x_mod]->enque(x);
			if (x_div / 10)
			{
				loop = 1;
			}
		}
		for (int i = 0; i <= 9; i++)
		{
				while (!t[i]->isEmpty())
				{
					queue.enque(t[i]->deque());
				}
		}
		digit *= 10;
	}

	return queue;
}
