#include "includes.hpp"

template<typename T>
class Comparator 
{
private:
	static int compare_count;

public:
	bool leq(T lhs, T rhs);
	bool gre(T lhs, T rhs);
	int getCount();
};

template<typename T> int Comparator<T>::compare_count = 0;
