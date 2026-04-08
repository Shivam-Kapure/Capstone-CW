#include <iostream>
#include <vector>

using namespace std;

void dnfSort(vector<int>& arr) {
	int low = 0;
	int mid = 0;
	int high = static_cast<int>(arr.size()) - 1;

	while (mid <= high) {
		if (arr[mid] == 0) {
			swap(arr[low], arr[mid]);
			low++;
			mid++;
		} else if (arr[mid] == 1) {
			mid++;
		} else if (arr[mid] == 2) {
			swap(arr[mid], arr[high]);
			high--;
		} else {
			cout << "Invalid input detected. Array should contain only 0, 1, and 2.\n";
			return;
		}
	}
}

int main() {
	int n;
	cout << "Enter number of elements: ";
	cin >> n;

	vector<int> arr(n);
	cout << "Enter " << n << " elements (only 0, 1, 2): ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dnfSort(arr);

	cout << "Sorted array: ";
	for (int num : arr) {
		cout << num << " ";
	}
	cout << '\n';

	return 0;
}
