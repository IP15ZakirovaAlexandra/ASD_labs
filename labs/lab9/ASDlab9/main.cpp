#include <iostream>
#include <iomanip>

using namespace std;

double **Create(size_t n, size_t m) {
    auto Matrix = new double *[n];
    for (size_t i = 0; i < n; ++i) {
        Matrix[i] = new double[m];
    }
    return Matrix;
}

void Delete(double **Matrix, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] Matrix[i];
    }
    delete[] Matrix;
}

void SnakeCols(double **Matrix, int n, int m) {
    int i, j;
    double k = 0.5;
    for (j = 0; j < m; j++) {
        for (i = 0; i < n; i++) {
            Matrix[i][j] = (j % 2 ? (j + 1) * n - i - 0.5 : k);
            k++;
        }
    }
}

void Print(double **Matrix, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        cout << "\n";
        for (j = 0; j < m; j++) {
            cout << setw(4) << Matrix[i][j] << "  ";
        }
    }
    cout << "\n" << endl;
}

void MaxWithIndex(double **Matrix, int n, int m) {
    for (int j = 0; j < m; j++) {
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (Matrix[max][j] < Matrix[i][j]) {
                max = i;
            }
        }
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if (Matrix[a][b] == Matrix[max][j]) {
                    cout << "Max value in " << b + 1 << " column is " << Matrix[max][j] << " in [" << a + 1 << "]["
                         << b + 1 << "] position\n";
                    Matrix[a][0] = Matrix[max][j];
                }
            }
        }
    }
}


int main() {
    int n, m;
    cout << "Set the dimension of the matrix A(n x m)\n";
    cout << "n: ";
    cin >> n;
    cout << endl << "m: ";
    cin >> m;
    double **Matrix = Create(n, m);
    SnakeCols(Matrix, n, m);
    Print(Matrix, n, m);
    MaxWithIndex(Matrix, n, m);
    Print(Matrix, n, m);
    Delete(Matrix, n);
    return 0;
}