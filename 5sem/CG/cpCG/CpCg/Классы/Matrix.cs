using System;


namespace CpCG
{
    public class Matrix
{
    public Matrix()
    {
       m = new Double[4,4];
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                m[i,j] = 0;
    }
        
    // операции над векторами и матрицами:
    
    // умножение матриц
    static public Matrix operator *(Matrix left, Matrix right) 
    {
        Matrix res = new Matrix();
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                for(int k = 0; k < 4; ++k)
                    res.m[i,j] += left.m[i,k] * right.m[k,j];
        return res;
    }
    // умножение вектора на матрицу
    static public MyPoint operator *(Matrix left, MyPoint p)
    {
        double[] t = {0, 0, 0, 0};
        double[] tp = {p.x, p.y, p.z, p.w};
        
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                t[i] += left.m[i,j] * tp[j];
        
        return new MyPoint(t[0], t[1], t[2], t[3]);
    }
    // присваивание
    static public Matrix operator ==(Matrix left, Matrix right)
    {
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                left.m[i,j] = right.m[i,j];
        
        return left;
    }

    static public Matrix operator !=(Matrix left, Matrix right)
    {
        return left;
    }

    public double[,] m;
};

//матрица масштабирования
class ScalingMatrix: Matrix
{
    public ScalingMatrix(double a, double b, double c)
    {
        m[0,0] = a;
        m[1,1] = b; 
        m[2,2] = c; 
        m[3,3] = 1;
    }
}

//матрица поворота
class RotationMatrix: Matrix
{
        public RotationMatrix(char axis, double a)
        {
            switch(axis)
            {
                case 'X':
                    m[1,1] = m[2,2] = Math.Cos(a);
                    m[1,2] = -1 *(m[2,1] = Math.Sin(a));
                    m[0,0] = 1;
                    break;
                case 'Y':
                    m[0,0] = m[2,2] = Math.Cos(a);
                    m[2,0] = -1 *(m[0,2] = Math.Sin(a));
                    m[1,1] = 1;
                    break;
                case 'Z':
                    m[0,0] = m[1,1] = Math.Cos(a);
                    m[1,0] = -1 *(m[0,1] = Math.Sin(a));
                    m[2,2] = 1;
                    break;
            }
            m[3,3] = 1;
        }
}

//матрица сдвига
class ShiftMatrix: Matrix
{
    public ShiftMatrix(double a, double b, double c)
    {
        m[0,3] = a;
        m[1,3] = b;
        m[2,3] = c;
        for(int i = 0; i < 4; ++i)
            m[i,i] = 1;
    }
}

}
