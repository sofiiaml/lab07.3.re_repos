#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n,const int Low, const int High, int nIndex) {
	if (nIndex == n)
		return;
	for (int i = 0; i < n; i++) {
		a[nIndex][i] = Low + rand() % (High - Low + 1);
	}
	Create(a, n, Low, High, nIndex + 1);
}
void Print(int** a, const int n, int nIndex) {
	if (nIndex == n)
		return;
	for (int j = 0; j < n; j++)
		cout << setw(4) << a[nIndex][j];
	cout << endl;
	Print(a, n,nIndex + 1);
}
void Sort(int** a, int n, int k) {
	if( k < n){
		int max = INT_MIN;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (k == 0 && a[i][j] > max) {
					max = a[i][j];
				}
				if (k > 0 && a[i][j] > max && a[i][j] < a[k - 1][k - 1]) {
					max = a[i][j];
				}
			}
		}
		a[k][k] = max;
		Sort(a, n, k + 1);
	}
}
int findFirstRowWithoutPositive(int**a,int n, int i) {
	if (i == n) {
		return -1; 
	}
	bool hasPositive = false;
	for (int j = 0; j < n; j++) {
		if (a[i][j] > 0) {
			hasPositive = true;
			break;
		}
	}
	if (!hasPositive) {
		return i + 1; 
	}
	return findFirstRowWithoutPositive(a,n, i + 1);
}
int main() {
	srand((unsigned)time(NULL));
	int Low = -15;
	int High = 5;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High,0);
	cout << "Array:"; cout << endl;
	Print(a, n,0);
	cout << "I=" << findFirstRowWithoutPositive(a, n, 0); cout << endl;
	findFirstRowWithoutPositive(a, n,0);
	Sort(a, n,0);
	cout << "Changed Array:"; cout << endl;
	Print(a, n,0);
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
	return 0;
}
