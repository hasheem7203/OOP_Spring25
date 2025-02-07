#include <iostream>
using namespace std;

int **allocate(int row, int col) {
    int **ptr = new int *[row];
    for (int i = 0; i < row; i++) {
        ptr[i] = new int[col];
    }
    return ptr;
}

void deallocate(int **ptr, int row) {
    for (int i = 0; i < row; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
}

void input(int **ptr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "(" << i + 1 << "," << j + 1 << ") : ";
            cin >> ptr[i][j];
        }
    }
}

void display(int **ptr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << ptr[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
}

void multiplication(int **ptr1, int **ptr2, int **ptr3, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            ptr3[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                ptr3[i][j] += ptr1[i][k] * ptr2[k][j];
            }
        }
    }
}

int main() {
    int r1, r2, c1, c2;
    cout << "Enter Rows Of Matrix 1: ";
    cin >> r1;
    cout << "Enter Columns Of Matrix 1: ";
    cin >> c1;
    cout << "Enter Rows Of Matrix 2: ";
    cin >> r2;
    cout << "Enter Columns Of Matrix 2: ";
    cin >> c2;

    if (c1 != r2) {
        cout << "Cannot Perform Matrix Multiplication \n";
        return 0;
    }

    int **ptr1 = allocate(r1, c1);
    int **ptr2 = allocate(r2, c2);
    int **ptr3 = allocate(r1, c2);

    cout << "Enter values for Matrix 1:\n";
    input(ptr1, r1, c1);
    cout << "Enter values for Matrix 2:\n";
    input(ptr2, r2, c2);

    multiplication(ptr1, ptr2, ptr3, r1, c1, c2);

    cout << "Resultant Matrix:\n";
    display(ptr3, r1, c2);

    deallocate(ptr1, r1);
    deallocate(ptr2, r2);
    deallocate(ptr3, r1);

    return 0;
}
