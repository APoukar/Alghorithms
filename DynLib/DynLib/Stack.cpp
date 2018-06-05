#include "stdafx.h"
#include "Stack.h"
#include <iostream>
#include "RandomNumberGenerator.h"
#include <list>
#include <string>

namespace dynlib {

	void Stack::printStack()
	{
		std::list<int> myList;
		for (int const &number : m_array)
		{
			myList.push_front(number);
		}
		for (int const &num : myList)
		{
			std::cout << num << ", ";
		}
	}

	Stack::Stack() 
	{
	}
	Stack::Stack(int length)
	{
		RandomNumberGeneartor rng;
		m_array = rng.fillVector(length);
	}


	Stack::~Stack()
	{
	}

	void Stack::print(const std::string line)
	{
		std::cout << '\n';
		if (!line.empty())
		{
			std::cout << line << '\n';
		}		
		printStack();
		std::cout << '\n';
	}

	int Stack::size() const
	{
		return m_array.size();
	}

	void Stack::push(int number)
	{
		m_array.push_back(number);
	}

	int Stack::pop()
	{
		if (isEmpty()) {
			throw std::runtime_error("Stack is empty");
			return 0;
		}
		int lastElement = m_array.back();
		m_array.pop_back();
		return  lastElement;
	}

	bool Stack::isEmpty() const
	{
		return m_array.empty();
	}
	int Stack::show() const
	{
		return m_array.back();
	}
}