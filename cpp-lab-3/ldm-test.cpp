#include <iostream>

void sort(long long array[], const size_t size) {
	bool action = true;
	while (action) {
		action = false;
		for (int i = 0; i < size - 1; ++i) {
			if (array[i] > array[i + 1]) {
				array[i] ^= array[i + 1];
				array[i + 1] ^= array[i];
				array[i] ^= array[i + 1];
				action = true;
			}
		}
	}
}

long long getResult(long long array[], size_t size) {
	while (size > 1) {
		sort(array, size);
		size--;
		array[size - 1] -= array[size];
		array[size - 1] *= -1;
	}
	return array[0];
}

//int main()
//{
//	int n;
//	std::cin >> n;
//
//	long long arr[32]{};
//
//	for (int i = 0; i < n; ++i) {
//		std::cin >> arr[i];
//	}
//
//	std::cout << getResult(arr, n);
//	return 0;
//}
