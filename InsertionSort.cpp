#include<iostream>
using namespace std;
int main() {
	int a = {4, 1, 2, 9, 8, 5, 7, 6, 3};
	cout << "Array Before Sort: ";
	for (int j = 0; j < 9; j++)
	{
		cout << a[j] << " ";
	}
	cout << "\n";
	int key;
	for (int i = 2; i < 9; i++)
	{
		key = a[i];
		j = i - 1;
		while (j > 0 && a[i] < key)
		{
			a[j + 1] = a[j];
			j = j - 1;
			a[j + 1] = key;
		}
	}

	cout << "Array After Insertion Sort: ";
	for (int j = 0; j < 9; j++)
	{
		cout << a[j] << " ";
	}

	return 0;
}