#pragma once
#ifndef CUSTOMVECTOR_H
#define CUSTOMVECTOR_H

#include <utility>

template<typename T>
class CustomVector
{
public:
	CustomVector();
	CustomVector(int size);
	CustomVector(const CustomVector<T>& rhs);
	~CustomVector();

	CustomVector& operator=(CustomVector<T> rhs);
	T& operator [](int i);

	void resize(int NewSize);
	int size() {return mSize;}

private:
	T* mData;
	int mSize;
};

template<typename T>
CustomVector<T>::CustomVector() : mData(nullptr), mSize(0)
{

}

template<typename T>
CustomVector<T>::CustomVector(int size) : mSize(size)
{
	if (size < 0)
	{
		std::cout << "Cannot be < 0.\n";
		return;
	}
	else
	{
		this ->mData = (size > 0) ? new T[size] : nullptr;
	}
}

template<typename T>
CustomVector<T>::CustomVector(const CustomVector<T>& rhs) : mSize(rhs.mSize), mData((rhs.mSize > 0) ? new T[rhs.mSize] : nullptr)
{
	// Assign new memory chunk to copied data
	for (int i = 0; i < rhs.mSize; ++i)
	{
		this->mData[i] = rhs.mData[i];
	}
}

template<typename T>
CustomVector<T>::~CustomVector()
{
	delete[] mData;

	mData = nullptr;
}

template<typename T>
CustomVector<T>& CustomVector<T>::operator=(CustomVector<T> rhs)
{
	std::swap(*this, rhs);

	return *this;
}

template<typename T>
T& CustomVector<T>::operator[](int i)
{
	return mData[i];
}

template<typename T>
void CustomVector<T>::resize(int newSize)
{
	if (newSize < 0) return;

	if (newSize == mSize) return;

	T* new_data = new T[newSize];

	int elemets_to_copy = (newSize > mSize) ? newSize : mSize;

	for (int i = 0; i < elemets_to_copy; ++i)
	{
		new_data[i] = mData[i];
	}

	delete[] mData;

	mData = new_data;
	mSize = newSize;
}


#endif // !CUSTOMVECTOR_H

