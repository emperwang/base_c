#include <iostream>


// ���鴫ֵ  -- ok
//void addOne(int arr[2])
//{
//	arr[0] += 1;
//	arr[1] += 1;
//}

// ��������	-- ok
//void addOne(int (&arr)[2])
//{
//	arr[0] += 1;
//	arr[1] += 1;
//}

// ָ��
void addOne(int* arr)
{
	arr[0] += 1;
	arr[1] += 1;
}


int main(void)
{
	int arr2[2] = { 0, 1 };

	addOne(arr2);
	for (int i = 0; i < 2; i++)
	{
		std::cout << i << " = " << arr2[i] << std::endl;
	}

	system("pause");
}

