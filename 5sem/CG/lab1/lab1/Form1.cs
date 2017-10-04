using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab1
{
    public partial class Form1 : Form
    {
        int MAX = 1000000;
        float scale = 1;
        Point zero;
        double pi = Math.PI;

        private Point CalcCentr()
        {
            return new Point(drawBox.Width / 2, drawBox.Height / 2);
        }

        public Form1()
        {
            InitializeComponent();
            zero = CalcCentr();

            drawBox.MouseWheel += DrawBox_MouseWheel;
        }

        
        private void button1_Click(object sender, EventArgs e)
        {
            scale = 1;
            drawBox.Invalidate();

        }

        private double myFunc(double a, double t)
        {
            return a * Math.Cos( t) / Math.Cos(t) > MAX ? MAX : a * Math.Cos(2 * t) / Math.Cos(t);
        }

        private void drawBox_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            g.ScaleTransform(scale,scale);

            g.TranslateTransform(zero.X, zero.Y);
            DrawCoordinates(g, Pens.Red);
            DrawCurve(g);
           


        }

        private void DrawCurve(Graphics g)
        {
            Pen linePen = new Pen(Color.Blue, 100);

            var aBorder = -pi;
            var bBorder = pi;
            var paramA = 100.0;

            var step = (bBorder - aBorder)/1000;

            for (double i = aBorder; i < bBorder; i += step)
            {
                var r = myFunc(paramA, i);
                PointF begin = ToDecart(r, i);
                PointF end = ToDecart(r, i + step);

               g.DrawLine(linePen, begin, end);
            }

            
        }

        private PointF ToDecart(double r, double d)
        {
           return new PointF((float)(r * Math.Cos(d)), (float)(r * Math.Sin(d)));
        }

        private void DrawCoordinates(Graphics g, Pen p)
        {
            g.DrawLine(p, new Point(-MAX, 0), new Point(MAX, 0));
            g.DrawLine(p, new Point(0, -MAX), new Point(0, MAX));

            for (int i = -1000; i < 1000; i += 10)
            {
                g.DrawLine(p, new Point(i, -2), new Point(i, 2));

                if (i % 100 == 0) g.DrawString((i / 10).ToString(), DefaultFont, Brushes.Green, new Point(i, 10));

                g.DrawLine(p, new Point(-2, i), new Point(2, i));


            }

        }


        private void DrawBox_MouseWheel(object sender, MouseEventArgs e)
        {
            if ( e.Delta > 0)
                scale *= 1.1f;
            else
            {
                scale *= 0.9f;
            }

            drawBox.Invalidate();
        }

        private void drawBox_SizeChanged(object sender, EventArgs e)
        {
            zero = CalcCentr();
        }
    }
}
