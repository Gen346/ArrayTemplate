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

	CustomVector& operator=(const CustomVector<T>& rhs);
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
CustomVector<T>& CustomVector<T>::operator=(const CustomVector<T>& rhs)
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
	if (newSize >= mSize)
	{
		T* = new CustomVector{newSize};
	}
}


#endif // !CUSTOMVECTOR_H

