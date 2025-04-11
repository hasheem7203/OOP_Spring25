#include <iostream>
using namespace std;

class MatrixHandler; 
class Matrix {
private:
    int a, b, c, d;

public:
    Matrix(int valA = 0, int valB = 0, int valC = 0, int valD = 0) {
        a = valA;
        b = valB;
        c = valC;
        d = valD;
    }

    Matrix operator+(const Matrix& other) const {
        return Matrix(
            a + other.a,
            b + other.b,
            c + other.c,
            d + other.d
        );
    }

    Matrix operator-(const Matrix& other) const {
        return Matrix(
            a - other.a,
            b - other.b,
            c - other.c,
            d - other.d
        );
    }

    Matrix operator*(const Matrix& other) const {
        return Matrix(
            (a * other.a + b * other.c),
            (a * other.b + b * other.d),
            (c * other.a + d * other.c),
            (c * other.b + d * other.d)
        );
    }

    friend int calculateDeterminant(const Matrix& m);

    friend class MatrixHandler;

    friend ostream& operator<<(ostream& os, const Matrix& m) {
        os << "[ " << m.a << "  " << m.b << " ]\n";
        os << "[ " << m.c << "  " << m.d << " ]";
        return os;
    }
};

int calculateDeterminant(const Matrix& m) {
    return m.a * m.d - m.b * m.c;
}

class MatrixHandler {
public:
    static void changeValue(Matrix& m, int row, int col, int value) {
        if (row == 0 && col == 0) m.a = value;
        else if (row == 0 && col == 1) m.b = value;
        else if (row == 1 && col == 0) m.c = value;
        else if (row == 1 && col == 1) m.d = value;
        else cout << "Invalid matrix coordinates!\n";
    }
};

int main() {
    Matrix mat1(2, 3, 4, 5);
    Matrix mat2(6, 7, 8, 9);

    cout << "Matrix 1:\n" << mat1 << "\n";
    cout << "\nMatrix 2:\n" << mat2 << "\n";

    Matrix sumResult = mat1 + mat2;
    cout << "\nSum of matrices:\n" << sumResult << "\n";

    Matrix diffResult = mat1 - mat2;
    cout << "\nDifference of matrices:\n" << diffResult << "\n";

    Matrix productResult = mat1 * mat2;
    cout << "\nProduct of matrices:\n" << productResult << "\n";

    int det = calculateDeterminant(mat1);
    cout << "\nDeterminant of Matrix 1: " << det << "\n";

    MatrixHandler::changeValue(mat1, 0, 1, 99);
    cout << "\nMatrix 1 after modification at (0,1):\n" << mat1 << "\n";

    return 0;
}
