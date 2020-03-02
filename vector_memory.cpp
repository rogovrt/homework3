#include <iostream>
#include <vector>

template <typename T>
void memoryInfo(const std::vector <T> &v) {
	std::cout << "capacity = "<< v.capacity() << std::endl;
        std::cout << "size = " << v.size() << std::endl;
	std::cout << "-------------" << std::endl;
}

template <typename T>
void memoryCheck(const std::vector <T> &v) {
	if (v.capacity() != v.size()) {
		memoryInfo(v);
	}
}

int main() {
	{
		std::vector <int> v;
		memoryInfo(v);
		for (int i = 0; i < 10; ++i) {
			v.push_back(i);
			memoryCheck(v);
		}
		//вывод: при нехватке памяти емкость вектора увеличивается в 2 раза от текущей. причем сначала емкость и размер равны 0, при добавлении первого эелемента и емкость и размер = 1, а далее идет последоательное увеличение емкости в 2 раза при нехватке памяти, т.е. 2, 4, 8 и т.д.
	}

	{
		std::vector <int> v;
		v.reserve(5);
		memoryInfo(v);
		for (int i = 0; i < 20; ++i) {
			v.push_back(i);
			memoryCheck(v);
		}
		//вывод: при нехватке памяти емкость также увеличивается в 2 раза от текущей, т.е. сначала выделяется 5 элементов, затем 10, 20 и т.д.
	}

	{
		std::vector <int> v;
		std:: cout << "max_size = " << v.max_size() << std::endl;
		//int n = v.max_size() / 10000000000 + 1;
		//int n = 922337204;
		//int n = 922337200;
		//int n = 1000000000;
		//int n = 500000000;
		int n = 900000000;
		v.reserve(n);
		memoryInfo(v);
		v.insert(v.end(), n, 0);
		memoryInfo(v);
		v.push_back(2);
		memoryInfo(v);
		//вывод: проанализировав для различных значений начального количества элементов, могу сделать вывод, что если у системы есть возможность увеличить capacity в два раза, то она увеличивает, иначе программа падает с std::bad_alloc
	}
	return 0;
}
