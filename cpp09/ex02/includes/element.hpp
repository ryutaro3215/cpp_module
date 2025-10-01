#ifndef ELEMENT_HPP
# define ELEMENT_HPP
#include <cstddef>

typedef struct {
	//最初のソートしたい数列におけるindex
	size_t index;
	//pairにしたときのpairのindex。再帰が進むことによって変化する.
	int pair_id;
	int value;
} element;

#endif
