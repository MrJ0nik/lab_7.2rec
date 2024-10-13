#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, int i, int j, const int k, const int n, const int Low, const int High);
void Print(int** a, int i, int j, const int k, const int n);
void SwapMinMaxInRows(int** a, int i, int j, const int k, const int n, int maxIdx, int minIdx);

int main() {
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int k, n;

    cout << "k = ";
    cin >> k;
    cout << "n = ";
    cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, 0, 0, k, n, Low, High);
    cout << "Matrix before swapping:" << endl;
    Print(a, 0, 0, k, n);

    SwapMinMaxInRows(a, 0, 0, k, n, 0, 0);

    cout << "Matrix after swapping:" << endl;
    Print(a, 0, 0, k, n);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, int i, int j, const int k, const int n, const int Low, const int High) {
    if (i == k) return;
    if (j < n) {
        a[i][j] = Low + rand() % (High - Low + 1);
        Create(a, i, j + 1, k, n, Low, High);
    }
    else {
        Create(a, i + 1, 0, k, n, Low, High);
    }
}

void Print(int** a, int i, int j, const int k, const int n) {
    if (i == k) return;
    if (j < n) {
        cout << setw(4) << a[i][j];
        Print(a, i, j + 1, k, n);
    }
    else {
        cout << endl;
        Print(a, i + 1, 0, k, n);
    }
}

void SwapMinMaxInRows(int** a, int i, int j, const int k, const int n, int maxIdx, int minIdx) {
    if (i == k) return;
    if (j < n) {
        if (a[i][j] > a[i][maxIdx]) maxIdx = j;
        if (a[i][j] < a[i][minIdx]) minIdx = j;
        SwapMinMaxInRows(a, i, j + 1, k, n, maxIdx, minIdx);
    }
    else {
        int temp = a[i][maxIdx];
        a[i][maxIdx] = a[i][minIdx];
        a[i][minIdx] = temp;
        SwapMinMaxInRows(a, i + 1, 0, k, n, 0, 0);
    }
}
