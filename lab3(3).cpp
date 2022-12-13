#include <iostream>
#include <cstdlib>
 
const int ERR_EXIT = -1;
 
using namespace std;
 
 
class Matrix
{
public:
    float **mat;
    float rows;  // число строк
    float colls; // число столбцов
    size_t SIZE;
 
    Matrix();// конструктор без параметров
    Matrix(float _rows);// конструктор с одним параметром
    Matrix(float _rows, float _colls);// конструктор с двумя параметрами
    ~Matrix();// деструктор
 
    void printMatrix();// печать матрицы
    void printMatrixOne(); // Печать матрицы с одним параметром
    Matrix operator = (Matrix &A);// присвоение
    Matrix operator + (Matrix &A);//сложение
    Matrix operator - (Matrix &A);// вычитание
    Matrix operator * (float num);// умножение матрицы на число
    Matrix inMat();// ввод данных в матрицу
    Matrix poiskIJ();
};
 
// Конструктор без параметров
Matrix::Matrix()
{
    mat = NULL;
    rows = 0;
    colls = 0;
}
 
// Конструктор с одним параметром
Matrix::Matrix(float _rows )
{
    rows = colls = _rows;
    mat = new float* [_rows];
    for(int i = 0; i < _rows; i++)
    {
        mat[i] = new float[_rows];
    }
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _rows; j++)
            mat[i][j] = 1+rand()%9;
    }
}
 
// Конструктор с двумя параметрами
Matrix::Matrix(float _rows, float _colls)
{
    rows = _rows;
    colls = _colls;
    if (!(mat = new float* [_rows]))
    {
        cerr << "Невозможно разместить матрицу в памяти";
        exit(ERR_EXIT);
    }
    for (int i = 0; i < _rows; i++)
    {
        if (!(mat[i] = new float[_colls]))
        {
            cerr << "Невозможно разместить матрицу в памяти";
            exit (ERR_EXIT);
        }
    }
    for (int i = 0; i < _rows; i++) // заполняем массив случ. знач
            for (int j = 0; j < _colls; j++)
                mat[i][j] = 1+rand()%9;
}
 
// Присваивание /=/
 Matrix Matrix::operator = ( Matrix &A)
{
    int i,j;
    for (i = 0; i < colls; i++)
        delete (mat[i]);
        delete (mat);
    rows = A.rows;
    colls = A.colls;
 
    if (!(mat = new float*[rows]))
    {
        cerr << "Невозможно разместить матрицу в памяти";
        exit(ERR_EXIT);
    }
 
    for (i = 0; i < rows; i++)
    {
        if (!(mat[i] = new float [colls]))
        {
            cerr << "Невозможно разместить матрицу в памяти";
            exit(ERR_EXIT);
        }
    }
 
    for (j = 0; j < A.rows; j++)
    {
        for (i = 0; i < A.colls; i++)
        {
            mat[i][j] = A.mat[i][j];
        }
    }
 
    return *this;
}
 
// Деструктор
Matrix::~Matrix()
{
    for(int i = 0; i < rows; ++i)
    {
        delete  [] mat[i];
        mat[i] = NULL;
    }
    delete [] mat;
    mat = NULL;
}
 
 
// Вычитание /-/
Matrix Matrix::operator-(Matrix &A)
{
    int i,j;
    if (colls != A.colls || rows != A.rows )
    {
        cerr << "Матрица не совместима с операцией -";
        exit(ERR_EXIT);
    }
    Matrix C (rows, colls);
    for (j = 0; j < colls; j++)
    {
        for (i = 0; i < rows; i++)
        {
            C.mat[i][j] = mat[i][j] - A.mat[i][j];
        }
    }
    return C;
}
 
// Сложение /+/
Matrix Matrix::operator+(Matrix &A)
{
    int i,j;
    if (colls != A.colls || rows != A.rows )
    {
        cerr << "Матрица не совместима с операцией +";
        exit(ERR_EXIT);
    }
    Matrix C (rows, colls);
    for (j = 0; j < colls; j++)
    {
        for (i = 0; i < rows; i++)
        {
            C.mat[i][j] = A.mat[i][j] + mat[i][j];
        }
    }
    return C;
}
 
// Умножение на число
Matrix Matrix::operator*(float num)
{
    int i,j;
    for (j = 0; j < colls; j++)
        for (i = 0; i < rows; i++)
            mat[i][j] = num * mat[i][j];
    return *this;
}
 
// Ввод данных
Matrix Matrix::inMat()
{
    int i,j;
    cout << "Введите матрицу " << endl;
    cout << rows << 'X' << colls << ":" << endl;
 
    for (i = 0 ; i < rows; i++)
    {
        for (j = 0; j < colls; j++)
        {
            cin >> mat[i][j];
        }
    }
    return *this;
}

Matrix Matrix::poiskIJ()
{
    int i , j , a ,b;
    cout << "введіть a i b " << endl ;
    cin >> a >> b ;
    for (i = 0 ; i < rows; i++)
    {
        for (j = 0; j < colls; j++)
        {
          if ((a-1)<rows && (b-1)<colls)
            cout << mat[a-1][b-1]<<endl;
          else 
            cout << "net takogo " ;
        }
}
 return 0;
}
 
// Функция печати матрицы
void Matrix::printMatrix()
{
   for (int i = 0; i<rows; i++)
        {
            for (int j = 0; j<colls; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
}
 
// Функция печати матрицы с одним параметром
void Matrix::printMatrixOne()
{
   for (int i = 0; i<rows; i++)
        {
            cout << mat[i] << " ";
        }
            cout << endl;
}
int main()
{
    setlocale(0,"");
    int i;
 
    Matrix  F(4), A( 4, 4 ), B( 4, 4 ), G;
    //A.inMat();
    cout << "Матрица F" << endl;
    F.printMatrixOne();
    cout << "Матрица G" << endl;
    G.printMatrix();
    cout << "Матрица А" << endl;
    A.printMatrix();
    cout << "poiskomij element" << endl;
    A.poiskIJ();
    cout << "Матрица B" << endl;
    B.printMatrix();
    Matrix C = A + B ;
    cout << "matrix C" << endl ;
    C.printMatrix();
    Matrix C1 = A-B ;
    cout << "matrix C1" << endl ;
    C1.printMatrix();
    Matrix C2 = A *1.5 ;
    cout << "matrix C2" << endl ;
    C2.printMatrix() ;
    
    

    return 0;
}