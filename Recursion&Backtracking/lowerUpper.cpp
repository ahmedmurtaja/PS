#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
int lower_bound(T arr[], int n, T target) {
	int left = 0, right = n - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] >= target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	return left;
}

template <typename T>
int upper_bound(T arr[], int n, T target) {
	int left = 0, right = n - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	return left;
}

int main() {
	int arr[] = {1, 2, 2, 3, 3, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 3;

	int lowerIndex = lower_bound(arr, n, target);
	int upperIndex = upper_bound(arr, n, target);

	cout << "Lower bound index: " << lowerIndex << endl;
	cout << "Upper bound index: " << upperIndex << endl;
	cout << "Frequency of " << target << " is: " << upperIndex - lowerIndex << endl;

	return 0;
}