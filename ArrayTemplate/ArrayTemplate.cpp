#include <iostream>
#include "CustomVector.h"

int main()
{
	CustomVector<int> vectorExm(10);
	vectorExm[3] = 5;

	std::cout << vectorExm[3];
	return 0;
}