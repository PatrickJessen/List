#include "Vector.h"
#include <iostream>

struct Test
{
	int x;
	int y;
	Test(int x, int y)
		:x(x), y(y) {}

	Test() {}
};

int main()
{
	Vector<Test>* myVector = new Vector<Test>();
	myVector->Add(Test{ 10, 20 });
	myVector->Add(Test{ 20, 40 });
	myVector->Add(Test{ 30, 60 });

	myVector->RemoveAt(1);

	for (int i = 0; i < myVector->Size(); i++)
		std::cout << myVector->At(i).x << " , " << myVector->At(i).y << std::endl;
	std::cout << myVector->Size() << "\n";
	std::cin.get();
	return 0;
}