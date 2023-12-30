#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int index = 0)
{
    if (index == size) {
        return;
    }

    a[index] = Low + rand() % (High - Low + 1);
    Create(a, size, Low, High, index + 1);
}

void Print(int* a, const int size, int index = 0)
{
    if (index == size) {
        cout << endl;
        return;
    }

    cout << setw(5) << a[index];
    Print(a, size, index + 1);
}

int Pos(int* a, int n, int index = 0)
{
    if (index == n) {
        return 0;
    }

    return (a[index] > 0) + Pos(a, n, index + 1);
}

int Sum(int* a, const int size, int index = 0, bool foundZero = false)
{
    if (index == size) {
        return 0;
    }

    if (a[index] == 0) {
        foundZero = true;
    }

    if (foundZero && a[index] > 0) {
        return a[index] + Sum(a, size, index + 1, foundZero);
    }

    return Sum(a, size, index + 1, foundZero);
}

void Sort(int* a, const int size, int i = 0, int j = 0)
{
    if (i == size - 1) {
        return;
    }

    if (j < size - i - 1) {
        if ((abs(a[j]) > 1 && abs(a[j + 1]) <= 1) ||
            (abs(a[j]) > abs(a[j + 1]) && abs(a[j + 1]) <= 1) ||
            (abs(a[j]) == abs(a[j + 1]) && a[j] > a[j + 1]))
        {
            int tmp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = tmp;
        }

        Sort(a, size, i, j + 1);
    }
    else {
        Sort(a, size, i + 1, 0);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int n;

    cout << "n = "; cin >> n;

    int* a = new int[n];
    int Low = -5;
    int High = 5;

    Create(a, n, Low, High);
    Print(a, n);

    cout << "Sum = " << Sum(a, n) << endl;

    Sort(a, n);
    Print(a, n);
    cout << "k+= " << Pos(a, n) << endl;

    delete[] a;
    a = nullptr;
    return 0;
}
