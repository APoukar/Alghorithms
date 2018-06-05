#pragma once
#include <vector>

namespace dynlib {
	class Stack
	{
	private:
		std::vector<int> m_array;
		void printStack();
	public:
		Stack();
		Stack(int length);
		~Stack();
		void print(const std::string line);
		int size() const;
		void push(int number);
		int pop();
		bool isEmpty() const;
		int show() const;
	};
}

