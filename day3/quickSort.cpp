#include <iostream>
#include <vector>

using namespace std;

int partitionWithPivot(vector<int>& arr, int low, int high, int pivotType) {
	int pivotIndex;

	switch (pivotType) {
		case 1:
			pivotIndex = low;
			break;
		case 2:
			pivotIndex = high;
			break;
		case 3:
			pivotIndex = low + (high - low) / 2;
			break;
		default:
			pivotIndex = high;
			break;
	}

	swap(arr[pivotIndex], arr[high]);
	int pivot = arr[high];

	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, int pivotType) {
	if (low < high) {
		int pivotPos = partitionWithPivot(arr, low, high, pivotType);
		quickSort(arr, low, pivotPos - 1, pivotType);
		quickSort(arr, pivotPos + 1, high, pivotType);
	}
}

int main() {
	int n;
	cout << "Enter number of elements: ";
	cin >> n;

	vector<int> arr(n);
	cout << "Enter " << n << " elements: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int choice;
	cout << "Choose pivot type:\n";
	cout << "1. First element\n";
	cout << "2. Last element\n";
	cout << "3. Middle element\n";
	cout << "Enter your choice (1/2/3): ";
	cin >> choice;

	if (choice < 1 || choice > 3) {
		cout << "Invalid choice. Using last element as pivot by default.\n";
		choice = 2;
	}

	quickSort(arr, 0, n - 1, choice);

	cout << "Sorted array: ";
	for (int num : arr) {
		cout << num << " ";
	}
	cout << '\n';

	return 0;
}
