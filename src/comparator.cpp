#include "comparator.hpp"

template <typename T> bool Comparator<T>::leq(T lhs, T rhs)
{
	compare_count++;
	return (lhs <= rhs);
}
template <typename T> bool Comparator<T>::gre(T lhs, T rhs)
{
	compare_count++;
	return (lhs > rhs);
}
template <typename T> int Comparator<T>::getCount()
{
	return compare_count;
}

template class Comparator<int>;