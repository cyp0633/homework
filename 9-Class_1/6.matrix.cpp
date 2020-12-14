//矩阵计算
#include <iostream>
#include <cstdlib>
using namespace std;
class matrix
{
private:
    int rows, cols; //row是行，col是列
    int **p;

public:
    matrix();
    matrix(int &M, int &N);
    matrix(matrix &A, int &&m, int &n);
    ~matrix();

    matrix multi(int x); //  数乘
    int det();           //  计算行列式
    void out();          //输出矩阵
    void input();

    matrix operator+(matrix &another); //重载加法运算实现矩阵相加
    matrix operator*(matrix &another); //重载乘法运算实现矩阵相乘
};

matrix::matrix(int &M, int &N)
{
    rows = M, cols = N;
    p = new int *[rows];
    for (int i = 0; i < M; i++)
    {
        p[i] = new int[cols];
    }
}

matrix::matrix(matrix &A, int &&m, int &n) //从矩阵A中删除第m行第n列后得到新的矩阵
{
    p = new int *[A.rows - 1];
    int i, j;
    for (int i = 0; i < A.rows - 1; i++)
    {
        p[i] = new int[A.cols - 1];
    }
    for (i = 0; i <m; i++) //左上
    {
        for (j = 0; j < n ; j++)
        {
            p[i][j] = A.p[i][j];
        }
    }
    for (i = m; i < A.rows-1; i++) //左下
    {
        for (j = 0; j < n; j++)
        {
            p[i][j] = A.p[i + 1][j];
        }
    }
    for (i = 0; i < m ; i++) //右上
    {
        for (j = n; j < A.cols-1; j++)
        {
            p[i][j] = A.p[i][j + 1];
        }
    }
    for (i = m; i < A.rows-1; i++) //右下
    {
        for (j = n; j < A.cols-1; j++)
        {
            p[i][j] = A.p[i + 1][j + 1];
        }
    }
}

matrix::~matrix()
{
    for (int i = 0; i < rows; i++)
        delete[] p[i];

    delete[] p;
}

matrix matrix::multi(int x) //  数乘
{
    matrix tmp(rows, cols);
    int i, j, m, n;
    for (i = 0; i < this->rows; i++)
    {
        for (j = 0; j < this->cols; j++)
        {
            tmp.p[i][j] = this->p[i][j] * x;
        }
    }
    return tmp;
}

void matrix::out() //输出矩阵
{
    int i, j;
    for (i = 0; i < this->rows; i++)
    {
        for (j = 0; j < this->cols; j++)
        {
            cout << this->p[i][j] << ' ';
        }
        cout << '\n';
    }
    /*  逐行输出，数据间用空格分隔  */
}

void matrix::input()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> p[i][j];
}

matrix matrix::operator+(matrix &another) //重载加法运算实现矩阵相加
{
    matrix tmp(rows, cols);
    /*  矩阵对应位置元素相加  */
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            tmp.p[i][j] = this->p[i][j] + another.p[i][j];
        }
    }
    return tmp;
}

matrix matrix::operator*(matrix &another) //重载乘法运算实现矩阵相乘
{
    matrix tmp(rows, another.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < another.cols; j++)
        {
            /*  计算A矩阵的第i行与B矩阵的第j列元素对应相乘后之和，作为新矩阵的第i行第j列元素的值  */
            int sum = 0;
            for (int m = 0; m < this->cols; m++)
            {
                sum += this->p[i][m] * another.p[m][j];
            }
            tmp.p[i][j] = sum;
        }
    }
    return tmp;
}

int matrix::det()
{
    if (rows == 1)
        return p[0][0];
    else
    {
        int result = 0, flag;
        for (int i = 0; i < cols; i++)
        {
            flag = (i % 2) ? -1 : 1;
            matrix tmp(*this, 0, i);
            result = result + flag * p[0][i] * tmp.det(); //  使用代数余子式求行列式的值,  递归
        }
        return result;
    }
}
int main()
{
    int M, N;

    //  A矩阵的行和列
    cin >> M >> N;

    matrix mA(M, N); //生成A矩阵

    //  输入矩阵值

    mA.input();

    //  输入数乘值

    int x;
    cin >> x;

    matrix mm1 = mA.multi(x);

    mm1.out();

    //B矩阵的行和列
    int K, L;
    cin >> K >> L;

    matrix mB(K, L); //生成B矩阵
    mB.input();

    /*  求矩阵A和矩阵B的和  */

    if (M == K && N == L)
    {
        matrix mm2 = mA + mB;
        mm2.out();
    }

    /*  求矩阵A和矩阵B的乘积矩阵  */
    if (N == K)
    {
        matrix mm3 = mA * mB;
        mm3.out();
    }

    /*  矩阵A的行列式的值  */
    if (M == N)
        cout << mA.det() << endl;

    if (K == L)
        cout << mB.det() << endl;

    return 0;
}