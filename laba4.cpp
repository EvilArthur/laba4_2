#include <iostream>

using namespace std;
template<typename type, int n, int m>
class Matrix {
private:
    type matrix[n][m] = {0};
public:
    Matrix() = default;
    Matrix(const Matrix<type, n, m>& mtrx) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = mtrx.matrix[i][j];
            }
        }
    }

    Matrix<type, n, m>& operator = (const Matrix<type, n, m>& mtrx) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = mtrx.matrix[i][j];
            }
        }
        return *this;
    }

    Matrix<type, n, m> operator + (const Matrix<type, n, m>& mtrx) {
        Matrix<type, n, m> mtrxResult;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mtrxResult.matrix[i][j] = matrix[i][j] + mtrx.matrix[i][j];
            }
        }
        return mtrxResult;
    }

    Matrix<type, n, m>& operator +=(const Matrix<type, n, m>& mrtx) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] += mrtx.matrix[i][j];
            }
        }
        return *this;
    }

    Matrix<type, n, m> operator * (const Matrix<type, n, m>& mrtx) {
        Matrix<type, n, m> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    result.matrix[i][j] += matrix[i][k] * mrtx.matrix[k][j];
                }
            }
        }
        return result;
    }

    Matrix<type, n, m> operator *= (const Matrix<type, n, m>& mrtx) {
        Matrix<type, n, m> temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    temp.matrix[i][j] += (matrix[i][k] * mrtx.matrix[k][j]);
                }
            }
        }
        *this = temp;

        return *this;
    }

    Matrix<type, n, m>& operator++() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j]++;
            }
        }
        return *this;
    }

    type& operator()(int i, int j) {
        return matrix[i][j];
    }

    double det() {
        if (n == m) {
            switch (n) {
            case 1:
                return matrix[0][0];
            case 2:
                return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
            case 3:
                return (matrix[0][0] * matrix[1][1] * matrix[2][2]) +
                    (matrix[0][1] * matrix[1][2] * matrix[2][0]) +
                    (matrix[0][2] * matrix[1][0] * matrix[2][1]) -
                    (matrix[0][2] * matrix[1][1] * matrix[2][0]) -
                    (matrix[0][0] * matrix[1][2] * matrix[2][1]) -
                    (matrix[0][1] * matrix[1][0] * matrix[2][2]);
            }
        }
        else {
            abort();
        }
    }

    friend ostream& operator<<(ostream& os, const Matrix<type, n, m>& mtrx) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                os << mtrx.matrix[i][j] << ' ';
            }
            os << '\n';
        }
        return os;
    }

    friend istream& operator>>(istream& is, Matrix<type, n, m>& mtrx) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                is >> mtrx.matrix[i][j];
            }
        }
        return is;
    }
};





int main() {
    Matrix<int, 3, 3> m1;
    cin >> m1;
    cout << m1;

    Matrix<int, 3, 3> m2;
    cin >> m2;
    cout << m2;

    Matrix<int, 3, 3> m3;
    m3 = m1 + m2;
    cout << m3 << endl;

    m3 = m1 * m2;
    cout << m3 << endl;

    cout << m2.det() << endl;

}