#include <iostream>


// 数组传值  -- ok
//void addOne(int arr[2])
//{
//	arr[0] += 1;
//	arr[1] += 1;
//}

// 数组引用	-- ok
//void addOne(int (&arr)[2])
//{
//	arr[0] += 1;
//	arr[1] += 1;
//}

// 指针
void addOne(int* arr)
{
	arr[0] += 1;
	arr[1] += 1;
}

float convertIntToFloat(int a)
{
	float b = a;

	while ( b >= 1.0)
	{
		b /= 10;
	}
	return b;
}

void test2(int a)
{
	static int t1 = 5;
	std::cout << "t1 = " << t1 << std::endl;

	t1 = t1 + a;
	std::cout << "2 t1 = " << t1 << std::endl;
}

int main(void)
{
	/*int arr2[2] = { 0, 1 };

	addOne(arr2);
	for (int i = 0; i < 2; i++)
	{
		std::cout << i << " = " << arr2[i] << std::endl;
	}*/

	/*float b = convertIntToFloat(1223423412);
	std::cout << "b = " << b << std::endl;*/

	test2(0);
	test2(1);
	test2(2);
	system("pause");
}

