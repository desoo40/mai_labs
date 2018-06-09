using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab4
{
class Matrix
{
    public Matrix(int razm, char E)
    {
       this.razm = razm;
        if (E.Equals('0'))
       {
           matrix = new double[razm, razm];
           for (int i = 0; i < razm; ++i)
               for (int j = 0; j < razm; ++j)
                   matrix[i, j] = 0;
       }
        if (E.Equals('E'))
       {
           matrix = new double[razm, razm];
           for (int i = 0; i < razm; ++i)
               for (int j = 0; j < razm; ++j)
                   matrix[i, j] = 0;

           for (int i = 0; i < razm; ++i)
                   matrix[i, i] = 1;
       }
    }

    public Matrix(double[,] matrix)
    {
        razm = (int)Math.Sqrt(matrix.Length);
        this.matrix = matrix;
    }
        

    // операции над матрицами:
    
    // умножение матриц
    static public Matrix operator *(Matrix left, Matrix right) 
    {
        int razm = left.razm;
        Matrix res = new Matrix(razm, '0');
        for (int i = 0; i < razm; ++i)
            for (int j = 0; j < razm; ++j)
                for (int k = 0; k < razm; ++k)
                    res.matrix[i,j] += left.matrix[i,k] * right.matrix[k,j];
        return res;
    }
    // сложение матриц
    static public Matrix operator +(Matrix left, Matrix right)
    {
        int razm = left.razm;
        Matrix res = new Matrix(razm, '0');
        for (int i = 0; i < razm; ++i)
            for (int j = 0; j < razm; ++j)
                    res.matrix[i, j] = left.matrix[i, j] + right.matrix[i, j];
        return res;
    }
    // вычитание матриц
    static public Matrix operator -(Matrix left, Matrix right)
    {
        int razm = left.razm;
        Matrix res = new Matrix(razm, '0');
        for (int i = 0; i < razm; ++i)
            for (int j = 0; j < razm; ++j)
                res.matrix[i, j] = left.matrix[i, j] - right.matrix[i, j];
        return res;
    }
    // присваивание
    static public Matrix operator ==(Matrix left, Matrix right)
    {
        int razm = left.razm;

        for (int i = 0; i < razm; ++i)
            for (int j = 0; j < razm; ++j)
                left.matrix[i,j] = right.matrix[i,j];
        
        return left;
    }

    static public Matrix operator !=(Matrix left, Matrix right)
    {
        return left;
    }
    //определитель
    static public double operator !(Matrix matrix)
    {
        int razm = matrix.razm;
        double res = 0;

        if (razm == 2) { res = matrix.matrix[0,0] * matrix.matrix[1,1] - matrix.matrix[0,1] * matrix.matrix[1,0]; }
        else
        {
            for (int i = 0; i < razm; i++)
            {
                int[] strStlb = new int[2];
                strStlb[0] = 0;
                strStlb[1] = i;

                res = res + Math.Pow((-1), i) * matrix.matrix[0, i] * !(matrix & strStlb);
            }
        }

        return res;
    }
    //матрица минора
    static public Matrix operator &(Matrix matrix, int[] strStlb)
    {
        int razm = matrix.razm;
        Matrix res = new Matrix(razm - 1, '0');

        for (int i = 0; i < razm; ++i)
            for (int j = 0; j < razm; ++j)
            {
                if (i == strStlb[0] || j == strStlb[1]) continue;

                if (i < strStlb[0] && j < strStlb[1]) { res.matrix[i, j] = matrix.matrix[i, j]; }
                if (i > strStlb[0] && j < strStlb[1]) { res.matrix[i - 1, j] = matrix.matrix[i, j]; }
                if (i < strStlb[0] && j > strStlb[1]) { res.matrix[i, j - 1] = matrix.matrix[i, j]; }
                if (i > strStlb[0] && j > strStlb[1]) { res.matrix[i - 1, j - 1] = matrix.matrix[i, j]; }
            }

        return res;
    }
    //транспонирование
    static public Matrix operator ~(Matrix matrix)
    {
        int razm = matrix.razm;
        Matrix res = new Matrix(razm, '0');

        for (int i = 0; i < razm; ++i)
            for (int j = 0; j < razm; ++j)
            {
                res.matrix[i, j] = matrix.matrix[j, i];
            }

        return res;
    }
    //Обратная матрица
    static public Matrix operator --(Matrix matrix)
    {
        int razm = matrix.razm;
        Matrix res = new Matrix(razm, '0');

        for (int i = 0; i < razm; ++i)
            for (int j = 0; j < razm; ++j)
            {
                int[] strStlb = new int[2];
                strStlb[0] = i;
                strStlb[1] = j;

                res.matrix[i, j] = (1 / !matrix) * Math.Pow((-1), i + j) * !(matrix & strStlb);
            }

        res = ~res;
        return res;
    }

    // умножение вектора на матрицу слева
    static public Vector operator *(Matrix matrix, Vector vector)
    {
        int razm = matrix.razm;
        double[] res = new double[razm];

        for (int i = 0; i < razm; ++i)
            for (int j = 0; j < razm; ++j)
                res[i] += matrix.matrix[i, j] * vector.vector[j];

        return new Vector(res);
    }

    public double Norma()
    {
        double res = 0;
        for (int j = 0; j < razm; ++j)
        {
            double temp = 0;
            for (int i = 0; i < razm; ++i)
            {
                temp = temp + Math.Abs(matrix[i, j]);
                if (temp > res) res = temp;
            }
        }
        return res;
    }

    public void StrPlusStrUmnCh(int str1, int str2, double chislo)
    {
        for (int i = 0; i < razm; i++)
        {
            matrix[str1,i] = matrix[str1,i] + chislo * matrix[str2,i];
        }
    }

    public void StrSwap(int str1, int str2)
    {
        double[] temp = new double[razm];
        for (int i = 0; i < razm; i++)
        {
            temp[i] = matrix[str1, i];
        }

        for (int i = 0; i < razm; i++)
        {
            matrix[str1, i] = matrix[str2, i];
            matrix[str2, i] = temp[i];
        }
    }

    public double t()
    {
        double res = 0;
        for (int i = 0; i < razm; i++)
        {
            for (int j = i + 1; j < razm; j++)
            {
                res = res + matrix[i, j] * matrix[i, j];
            }
        }

        return Math.Sqrt(res);
    }

    public int MetodVrash(double tochnost, Vector[] sobstvVec, double[] sobstvZn, int kolvoIter, double[,] temp)
    {
        kolvoIter++;
        int vedStr = 0;
        int vedStlb = 1;
        for (int i = 0; i < razm; i++)
        {
            for (int j = i+1; j < razm; j++)
            {
                if (Math.Abs(matrix[i, j]) > Math.Abs(matrix[vedStr, vedStlb])) { vedStr = i; vedStlb = j; }
            }
        }
        double phi;
        if (Math.Abs(matrix[vedStr, vedStr] - matrix[vedStlb, vedStlb]) < tochnost)
        {
            phi = Math.PI / 4;
        }
        else
        {
            phi = Math.Atan(2 * matrix[vedStr, vedStlb] / (matrix[vedStr, vedStr] - matrix[vedStlb, vedStlb]));
            phi = phi / 2;
        }
        Matrix U = new Matrix(razm, 'E');
        U.matrix[vedStr, vedStlb] = -Math.Sin(phi);
        U.matrix[vedStlb, vedStr] = Math.Sin(phi);
        U.matrix[vedStr, vedStr] = Math.Cos(phi);
        U.matrix[vedStlb, vedStlb] = Math.Cos(phi);

        Matrix Temp = new Matrix(temp);
        Temp = Temp * U;
        temp = Temp.matrix;
        Matrix transU = ~U;
        Matrix A = transU * this;
        A = A * U;
        double At = A.t();
        if (A.t() < tochnost)
        {
            for (int j = 0; j < razm; j++)
            {
                for (int i = 0; i < razm; i++)
                {
                    sobstvVec[j].vector[i] = Temp.matrix[i, j];
                    if (i == j) sobstvZn[j] = A.matrix[j, i];
                }
            }
        }
        else
        {
            kolvoIter = A.MetodVrash(tochnost, sobstvVec, sobstvZn, kolvoIter, temp);
        }

        return kolvoIter;
    }

    public double[,] matrix;
    public int razm;
};
}
