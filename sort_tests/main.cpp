#include <iostream>
#include <algorithm>
#include <chrono>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include "timer.hpp"

/*вывод программы
std::sort for std::array =
7 milliseconds
std::sort for std::vector =
15 milliseconds
std::sort for std::deque =
26 milliseconds
operation sort for std::list =
55 milliseconds
operation sort for std::forward_list =
28 milliseconds
итог: array - самый быстрый
*/

int main() {
	{	
		std::array <int, 100001> a;
		for (int i = 0; i < 100001; ++i) 
			a[i] = 100000 - i;	
		Timer t;
		std::sort(a.begin(), a.end());
		t.stop();
		std::cout << "std::sort for std::array = " << std::endl;
	}

	{
		std::vector <int> v;
		for (int i = 0; i < 100001; ++i)
			v.push_back(100000 - i);
		Timer t;
		std::sort(v.begin(), v.end());
		t.stop();
		std::cout << "std::sort for std::vector = " << std::endl;
	}

	{
		std::deque <int> d;
		for (int i = 0; i < 100001; ++i)
        		d.push_back(100000 - i);
		Timer t;
		std::sort(d.begin(), d.end());
		t.stop();
		std::cout << "std::sort for std::deque = " << std::endl;
	}

	{
		std::list <int> l;
		for (int i = 0; i < 100001; ++i)
			l.push_back(100000 - i);
		Timer t;
		l.sort();
		t.stop();
		std::cout << "operation sort for std::list = " << std::endl;
	}
	{
		std::forward_list <int> fl;
                for (int i = 0; i < 100001; ++i)
                        fl.push_front(i);
		Timer t;
		fl.sort();
                t.stop();
		std::cout << "operation sort for std::forward_list = " << std::endl;
	}
	return 0;
}

