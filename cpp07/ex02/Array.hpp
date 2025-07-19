
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
private:
	T* m_array;
	size_t m_size;

public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(const Array& other);
	Array& operator=(const Array& other);

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	const T& getArray(unsigned int index) const;

	size_t size() const;
};

template <typename T>
Array<T>::Array() : m_array(NULL), m_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : m_array(new T[n]), m_size(n) {}

template <typename T>
Array<T>::~Array() {
	delete[] m_array;
}

template <typename T>
Array<T>::Array(const Array& other) : m_array(new T[other.m_size]), m_size(other.m_size) {
	for (size_t i = 0; i < m_size; i++)
		m_array[i] = other.m_array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this == &other)
		return *this;
	delete[] m_array;
	m_size = other.m_size;
	m_array = new T[m_size];
	for (size_t i = 0; i < m_size; i++)
		m_array[i] = other.m_array[i];
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= m_size)
		throw std::out_of_range("Index out of range");
	return m_array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= m_size)
		throw std::out_of_range("Index out of range");
	return m_array[index];
}

template <typename T>
const T& Array<T>::getArray(unsigned int index) const {
	if (index >= m_size)
		throw std::out_of_range("Index out of range");
	return m_array[index];
}

template <typename T>
size_t Array<T>::size() const {
	return m_size;
}
#endif

