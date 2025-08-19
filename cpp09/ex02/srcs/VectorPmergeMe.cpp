#include "PmergeMe.hpp"
#include "VectorPmergeMe.hpp"
#include <algorithm>
#include <map>

vectorPmergeMe::vectorPmergeMe() {};

vectorPmergeMe::~vectorPmergeMe() {};

vectorPmergeMe::vectorPmergeMe(const std::list<element>& arg_list) {
	for (std::list<element>::const_iterator it = arg_list.begin(); it != arg_list.end(); it++)
		_vector.push_back(*it);
}

vectorPmergeMe::vectorPmergeMe(const vectorPmergeMe& other) {
	for (std::vector<element>::const_iterator it = other._vector.begin(); it != other._vector.end(); it++)
		this->_vector.push_back(*it);
}

vectorPmergeMe &vectorPmergeMe::operator=(const vectorPmergeMe& other) {
	if (this == &other)
		return *this;
	for (std::vector<element>::const_iterator it = other._vector.begin(); it != other._vector.end(); it++)
		this->_vector.push_back(*it);
	return *this;
}

std::vector<element> vectorPmergeMe::getVector() {
	return _vector;
}

void vectorPmergeMe::pmergeMe_sort() {
	//Starting Algorithm
	setStartTime();
	sorting(_vector);
	setEndTime();
}

void vectorPmergeMe::sorting(std::vector<element>& original) {
	if (original.size() <= 1)
		return ;
	std::vector<element> large, small;
	divIntoLargeAndSmall(original, large, small);
	sorting(large);
	groupJacobsthal(small, large);
	inserting(original, large, small);
}

void vectorPmergeMe::divIntoLargeAndSmall(std::vector<element>& original, std::vector<element>& large, std::vector<element>& small) {
	int pair_num = 0;
	for (size_t i = 0; i + 1 < original.size(); i += 2) {
		original[i].pair_id = pair_num;
		original[i + 1].pair_id = pair_num;
		int left = original[i].value;
		int right = original[i + 1].value;
		if (left < right) {
			small.push_back(original[i]);
			large.push_back(original[i + 1]);
		} else {
			small.push_back(original[i + 1]);
			large.push_back(original[i]);
		}
		pair_num++;
	}
	if (original.size() % 2 == 1) {
		element tail = original.back();
		tail.pair_id = -1;
		large.push_back(tail);
	}
}

void vectorPmergeMe::groupJacobsthal(std::vector<element>& small, std::vector<element>& large) { 
}

void vectorPmergeMe::inserting(std::vector<element>& original, std::vector<element>& large, std::vector<element>& small) {
	// large vector is already sorted. So, large vector copy to original, and insert small element into original.
	// Update original to large
	original = large;
	original.reserve(large.size() + small.size());

	//Insert first small el into large top
	//Search same pair_id small number
	int first_largeEl_id = original.begin()->pair_id;
	for (std::vector<element>::iterator it = small.begin(); it != small.end(); it++) {
		if (it->pair_id == first_largeEl_id) {
			original.insert(original.begin(), *it);
			small.erase(it);
			break ;
		}
	}

	//Binary search
	for (std::vector<element>::iterator sit = small.begin(); sit != small.end(); sit++) {
		int upper_largeEl_id = sit->pair_id;
	// Get upper large element
		std::vector<element>::iterator upperIt = original.begin();
		for(; upperIt != original.end(); ++upperIt)
			if (upperIt->pair_id == upper_largeEl_id)
				break;

		//get Pos
		std::vector<element>::iterator pos = std::lower_bound(original.begin(), upperIt, *sit, &vectorPmergeMe::compValue);

		//Insert element
		original.insert(pos, *sit);
	}
}

bool vectorPmergeMe::compValue(const element& a, const element& b) {
	return a.value < b.value;
}



