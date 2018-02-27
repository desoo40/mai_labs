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
    class Triangle
    {
        public Triangle(MyPoint a, MyPoint b, MyPoint c)
        {
            this.a = a;
            this.b = b;
            this.c = c;
            Connect();
        }

        public void Connect()
        {
            a.triangleList.Add(this);
            b.triangleList.Add(this);
            c.triangleList.Add(this);
        }

        public MyPoint n()
        {
            return (b - a) ^ (c - a);
        }

        static public Triangle operator *(Matrix m, Triangle t)
        {
            return new Triangle(m * t.a, m * t.b, m * t.c);
        }

        public void draw(Pen pen, Graphics g, bool illuminate, MyPoint svet, double[,] iNofLight, double[,] kMat)
        {
            if (!illuminate)
            {
                if (n().z > 0)
                {
                    g.DrawLine(pen, (int)a.x, (int)a.y, (int)b.x, (int)b.y);
                    g.DrawLine(pen, (int)b.x, (int)b.y, (int)c.x, (int)c.y);
                    g.DrawLine(pen, (int)c.x, (int)c.y, (int)a.x, (int)a.y);
                }
            }

            double[] tempId = { iNofLight[0, 0], iNofLight[0, 1], iNofLight[0, 2] };
            double[] tempIa = { iNofLight[1, 0], iNofLight[1, 1], iNofLight[1, 2] };
            double[] tempIs = { iNofLight[2, 0], iNofLight[2, 1], iNofLight[2, 2] };

            Color color = new Color();

            if (a.n().z > 0 && b.n().z > 0 && c.n().z > 0)
            {
                int R = (a.Color(svet, tempId, tempIa, tempIs, kMat).R + b.Color(svet, tempId, tempIa, tempIs, kMat).R + c.Color(svet, tempId, tempIa, tempIs, kMat).R) / 3;
                int G = (a.Color(svet, tempId, tempIa, tempIs, kMat).G + b.Color(svet, tempId, tempIa, tempIs, kMat).G + c.Color(svet, tempId, tempIa, tempIs, kMat).G) / 3;
                int B = (a.Color(svet, tempId, tempIa, tempIs, kMat).B + b.Color(svet, tempId, tempIa, tempIs, kMat).B + c.Color(svet, tempId, tempIa, tempIs, kMat).B) / 3;
                color = Color.FromArgb(((int)(((byte)(R)))),
                                       ((int)(((byte)(G)))),
                                       ((int)(((byte)(B)))));
            }

            if (illuminate)
            {
                Pen penOfa;
                Pen penOfb;
                Pen penOfc;

                if (a.n().z > 0) { penOfa = new Pen(a.Color(svet, tempId, tempIa, tempIs, kMat), 1.0f); g.DrawRectangle(penOfa, (int)a.x, (int)a.y, 1, 1); }
                if (b.n().z > 0) { penOfb = new Pen(b.Color(svet, tempId, tempIa, tempIs, kMat), 1.0f); g.DrawRectangle(penOfb, (int)b.x, (int)b.y, 1, 1); }
                if (c.n().z > 0) { penOfc = new Pen(c.Color(svet, tempId, tempIa, tempIs, kMat), 1.0f); g.DrawRectangle(penOfc, (int)c.x, (int)c.y, 1, 1); }
                if (a.n().z > 0 && b.n().z > 0 && c.n().z > 0)
                {
                    Point[] trigon = { new Point((int)a.x, (int)a.y), new Point((int)b.x, (int)b.y), new Point((int)c.x, (int)c.y) };
                    g.FillPolygon(new SolidBrush(color), trigon);
                }
            }
        }

        public MyPoint a, b, c;
    }
}



