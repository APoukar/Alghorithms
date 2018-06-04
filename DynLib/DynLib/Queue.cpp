#include "stdafx.h"
#include "Queue.h"
#include <iostream>
#include "RandomNumberGenerator.h"
#include <list>
#include <string>

namespace dynlib {

#pragma region Ctor

	Queue::Queue()
	{
	}
	Queue::Queue(int length)
	{
		RandomNumberGeneartor rd;
		m_array = rd.fillVector(length);
	}

	Queue::~Queue()
	{
	}

#pragma endregion Ctor

#pragma region Private

	void Queue::printQueue()
	{
		std::list<int> list;

		for (int &num : m_array) {
			list.push_front(num);
		}
		for (int &num : list) {
			std::cout << num << ", ";
		}
	}

#pragma endregion Private

#pragma region Public

	void Queue::print(const std::string line)
	{
		std::cout << '\n';
		if (!line.empty())
		{
			std::cout << line << '\n';
		}
		printQueue();
		std::cout << '\n';
	}

	int Queue::size() const
	{
		return m_array.size();
	}

	void Queue::enque(int number)
	{
		m_array.insert(m_array.begin(), number);
	}

	int Queue::deque()
	{
		if (isEmpty()) {
			throw std::runtime_error("Queue is empty");
		}
		else {
			int lastElement = m_array.back();
			m_array.pop_back();
			return  lastElement;
		}
	}

	bool Queue::isEmpty() const
	{
		return m_array.empty();
	}
	int Queue::getMax()
	{
		int max = 0;
		for (int i = 0; i < size(); i++) {
			int number = deque();
			if (number > max)
			{
				max = number;
			}
			enque(number);
		}
		return max;
	}
	int Queue::show() const
	{
		if (isEmpty()) {
			throw std::runtime_error("Queue is empty");
		}
		else {
			return m_array.back();
		}
	}

#pragma endregion Public
}