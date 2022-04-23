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

int main(void)
{
	/*int arr2[2] = { 0, 1 };

	addOne(arr2);
	for (int i = 0; i < 2; i++)
	{
		std::cout << i << " = " << arr2[i] << std::endl;
	}*/

	float b = convertIntToFloat(1223423412);
	std::cout << "b = " << b << std::endl;

	system("pause");
}

