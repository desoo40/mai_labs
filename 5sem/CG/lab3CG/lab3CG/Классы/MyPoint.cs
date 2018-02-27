using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab3CG
{
    class MyPoint
{
    public MyPoint(double x = 0, double y = 0, double z = 0, double w = 1) 
    {
        this.x = x; 
        this.y = y; 
        this.z = z;
        this.w = w;

        triangleList = new List<Triangle>();
    }
    public MyPoint(MyPoint rhs)
    {
        this.x = rhs.x; 
        this.y = rhs.y; 
        this.z = rhs.z;
        this.w = rhs.w;
    }

    public MyPoint n()
    {
        MyPoint temp = new MyPoint();
        for (int i = 0; i < triangleList.Count; i++)
        {
            temp = (temp + triangleList[i].n()) * 0.5;
        }

        return temp;
    }

    // операции над векторами:

    // вычитание
    static public MyPoint operator -(MyPoint left, MyPoint right)
    {
        return new MyPoint(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
    }
    //линейные операции
    static public MyPoint operator +(MyPoint left, MyPoint right)
    {
        return new MyPoint(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
    }

    static public MyPoint operator *(MyPoint left, double lyambda)
    {
        return new MyPoint(left.x * lyambda, left.y * lyambda, left.z * lyambda, left.w * lyambda);
    }
    // присваивание
    static public MyPoint operator ==(MyPoint thisPoint, MyPoint rhs)
    {
        thisPoint.x = rhs.x;
        thisPoint.y = rhs.y;
        thisPoint.z = rhs.z;
        thisPoint.w = rhs.w;
        return thisPoint;
    }
    
    static public MyPoint operator !=(MyPoint thisPoint, MyPoint rhs)
    {
        return thisPoint;
    }
	// скалярное произведение
    static public double operator *(MyPoint left, MyPoint right)
    {
	    return left.x * right.x + left.y * right.y + left.z * right.z;
    }
    // векторное произведение
    static public MyPoint operator ^(MyPoint left, MyPoint right)
    {
	    MyPoint res = new MyPoint();
        res.x = left.y * right.z - left.z * right.y;
        res.y = left.z * right.x - left.x * right.z;
        res.z = left.x * right.y - left.y * right.x;
        res.w = 0;

        return res;
    }

    public double Modul()
    {
        return Math.Sqrt(x*x + y*y + z*z);
    }

    public Color Color(MyPoint svet, double[] iD, double[] iA, double[] iS, double[,] kMat)
    {
        double[] kD = { kMat[0, 0], kMat[0, 1], kMat[0, 2] };
        double[] kA = { kMat[1, 0], kMat[1, 1], kMat[1, 2] };
        double[] kS = { kMat[2, 0], kMat[2, 1], kMat[2, 2] };

        double[] absIntens = new double[3];
        int[] intens = new int[3];
        MyPoint globalSvet = svet;
        globalSvet.y = - svet.y;

        for(int i=0; i < 3; i++)
        {
            double[] fatt = new double[3];
            fatt[i] = 1 / (kD[i] * 0.005*(this - svet).Modul());
            double temp = (this - svet).Modul();

            double cosLN = (this.n() * (this - svet)) / (this.n().Modul() * (this - svet).Modul());
            MyPoint H = ((this - svet) + new MyPoint(0, 0, 1, 1)) * ( 1 / ((this - svet) + new MyPoint(0, 0, 1, 1)).Modul() );
            double cosHN = (this.n() * H) / (this.n().Modul() * H.Modul());

            if (cosHN < 0) cosHN = 0;
            if (cosLN < 0) cosLN = 0;

            absIntens[i] = fatt[i] * (iA[i]*kA[i] + kD[i]*iD[i]*cosLN + kS[i]*iS[i]*cosHN);
            
            if (absIntens[i] > 1) absIntens[i] = 1;

            intens[i] = Math.Abs((int)(255 * absIntens[i]));
        }

        if ((this.n() * (this - svet)) >= 0)
            return System.Drawing.Color.FromArgb(((int)(((byte)(intens[0])))), 
                                                 ((int)(((byte)(intens[1])))), 
                                                 ((int)(((byte)(intens[2])))));
        else return System.Drawing.Color.FromArgb(0, 0, 0);
    }

    public double x, y, z, w;
    public List<Triangle> triangleList;
};
}