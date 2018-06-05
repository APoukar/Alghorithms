#pragma once
#include "Queue.h"
class RadixSort
{
public:
	RadixSort();
	~RadixSort();
	dynlib::Queue sort(dynlib::Queue &queue);
};

