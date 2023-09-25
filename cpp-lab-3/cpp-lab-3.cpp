#include <iostream>

long long min(long long a, long long b) {
	return a < b ? a : b;
}

int getResult(const long long array[], const size_t index, size_t n, long long sum1, long long sum2) {
	if (index == n) {
		return abs(sum1 - sum2);
	}

	return min(
		getResult(array, index + 1, n, sum1 + array[index], sum2),
		getResult(array, index + 1, n, sum1, sum2 + array[index])
	);
}

int getResult(const long long array[], const size_t n) {
	return getResult(array, 0, n, 0, 0);
}

int main()
{
	int n;
	std::cin >> n;

	long long arr[32] {};

	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}

	std::cout << getResult(arr, n);
	return 0;
}
