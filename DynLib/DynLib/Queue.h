#pragma once
#include <vector>

namespace dynlib {

	class Queue
	{

		std::vector<int> m_array;
		void printQueue();

	public:
		Queue();
		Queue(int length);
		~Queue();
		void print(const std::string line);
		int size() const;
		void enque(int number);
		int deque();
		bool isEmpty() const;
		int getMax();
		int show() const;
	};
}


