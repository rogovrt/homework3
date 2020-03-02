#include <tuple>
#include <iostream>

template <int i, typename Handler, typename... Args>
struct iterate {
	static void next(std::tuple <Args...>& t, Handler handler) { 
        	iterate <i - 1, Handler, Args...>::next(t, handler);
        	handler(i, std::get<i>(t));
        }
};
    
template <typename Handler, typename... Args>
struct iterate <0, Handler, Args...> {
	static void next(std::tuple <Args...>& t, Handler handler) {
		handler(0, std::get<0>(t));
        }
 };

template <typename Handler, typename... Args>
struct iterate <-1, Handler, Args...> {
        static void next(std::tuple <Args...>& t, Handler handler) {}
};

template <typename Handler, typename... Args>
void for_each(std::tuple <Args...>& t, Handler handler) {
	int const t_size = std::tuple_size <std::tuple <Args...>>::value;
    	iterate <t_size - 1, Handler, Args...>::next(t, handler);
}

struct handler
{
    template <typename T>
    void operator()(int index, T&& t) {
        std::cout << "tuple<"<< index << "> = " << t << std::endl;
    }
};


template<typename... Args>
void print(std::tuple <Args...>& t) {
	for_each(t, handler());
}


int main() {
    	auto t = std::make_tuple(1, 2.3, "hello");
	print(t);
	auto t1 = std::make_tuple();
	print(t1);
	return 0;
}

