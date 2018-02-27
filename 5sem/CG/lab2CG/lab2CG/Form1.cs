using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace lab2CG
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            surfaces = new List<List<Triangle>>();
            calcPyramid();

            mx = 0;
            my = 0;
            cx = 0;
            cy = 0;
            cur = 0;

            scale = 50;
            mashtabK = 0;

            isMouseDown = false;
        }

        public void calcPyramid()
        {
            double radius = double.Parse(textBoxOfPirRadius.Text);
            double hight = double.Parse(textBoxOfPirHight.Text);

            List<Triangle> pyramid = new List<Triangle>();
            double katet = radius / Math.Sqrt(2);

            MyPoint A = new MyPoint(0, 0, -hight);
            MyPoint B = new MyPoint(radius, 0, -hight);
            MyPoint C = new MyPoint(0, radius, -hight);
            MyPoint D = new MyPoint(0, 0, 0);
            MyPoint E = new MyPoint(0, -radius, -hight);
            MyPoint F = new MyPoint(-radius, 0, -hight);
            MyPoint M = new MyPoint(katet, katet, -hight);
            MyPoint N = new MyPoint(-katet, katet, -hight);
            MyPoint K = new MyPoint(-katet, -katet, -hight);
            MyPoint H = new MyPoint(katet, -katet, -hight);

            Triangle a = new Triangle(B, M, A);
            Triangle b = new Triangle(M, C, A);
            Triangle c = new Triangle(C, N, A);
            Triangle d = new Triangle(N, F, A);
            Triangle e = new Triangle(F, K, A);
            Triangle f = new Triangle(A, K, E);
            Triangle g = new Triangle(A, E, H);
            Triangle h = new Triangle(A, H, B);
            Triangle j = new Triangle(D, M, B);
            Triangle k = new Triangle(D, C, M);
            Triangle l1 = new Triangle(D, N, C);
            Triangle m = new Triangle(D, F, N);
            Triangle n = new Triangle(D, K, F);
            Triangle l = new Triangle(D, E, K);
            Triangle o = new Triangle(D, H, E);
            Triangle p = new Triangle(D, B, H);

            pyramid.Add(a);
            pyramid.Add(b);
            pyramid.Add(c);
            pyramid.Add(d);
            pyramid.Add(e);
            pyramid.Add(f);
            pyramid.Add(g);
            pyramid.Add(h);
            pyramid.Add(j);
            pyramid.Add(k);
            pyramid.Add(l);
            pyramid.Add(m);
            pyramid.Add(n);
            pyramid.Add(l1);
            pyramid.Add(o);
            pyramid.Add(p);

            surfaces.Add(pyramid);

        }

        List<List<Triangle>> surfaces;

        // текущие координаты курсора и координаты его предыдущего положения

        int mx, my, cx, cy;

        // индекс текущей поверхности и масштаб

        int cur;
        float scale;
        double mashtabK;

        bool isMouseDown;

        private void mashtabMinusButton_Click(object sender, EventArgs e)
        {
            mashtabK -= 5;

            Refresh();
        }

        private void mashtabPlusButton_Click(object sender, EventArgs e)
        {
            mashtabK += 5;

            Refresh();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Pen pen = new Pen(Color.Black, 1.0f);
            double zoomLevel = (scale + mashtabK) / 1000;
            double coeff = Math.Max(e.ClipRectangle.Width, e.ClipRectangle.Height) * zoomLevel;

            
            Matrix m1 = new Matrix();
            m1.m[0, 0] = Math.Sqrt(3);
            m1.m[0, 1] = 0;
            m1.m[0, 2] = -Math.Sqrt(3);
            m1.m[1, 0] = 1;
            m1.m[1, 1] = 2;
            m1.m[1, 2] = 1;
            m1.m[2, 0] = Math.Sqrt(2);
            m1.m[2, 1] = -Math.Sqrt(2);
            m1.m[2, 2] = Math.Sqrt(2);
            m1.m[3, 3] = 1;
            m1 = m1 * (1 / Math.Sqrt(6));

            Matrix m2 = new Matrix();
            m2.m[0, 0] = 1;
            m2.m[0, 1] = 0;
            m2.m[0, 2] = 0;
            m2.m[1, 0] = 0;
            m2.m[1, 1] = 1;
            m2.m[1, 2] = 0;
            m2.m[2, 0] = 0;
            m2.m[2, 1] = 0;
            m2.m[2, 2] = 0;
            m2.m[3, 3] = 1;

            ShiftMatrix sh = new ShiftMatrix(e.ClipRectangle.Width /2, e.ClipRectangle.Height/2, 0);
            ScalingMatrix sc = new ScalingMatrix(coeff, coeff, coeff);
            RotationMatrix rtx = new RotationMatrix('X', my * Math.PI / 180.0);
            RotationMatrix rty = new RotationMatrix('Y', -mx * Math.PI / 180.0);
            Matrix tr = new Matrix();
            if (izometrCheckBox.Checked) { tr = sc * m1 * m2 * rtx * rty; tr = (sh * 2) * tr; }
            else tr = sh * sc * rtx * rty;

            for (int i = 0; i < surfaces[cur].Count; ++i)
            {
                Triangle t = tr * surfaces[cur][i];
                t.Draw(pen, e.Graphics, invLinCheckBox.Checked);
            }
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (isMouseDown)
            {
                int deltaX = e.X - cx;
                int deltaY = e.Y - cy;
                mx += deltaX;
                my += deltaY;
                cx = e.X;
                cy = e.Y;

                Refresh();
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            isMouseDown = true;
            cx = e.X;
            cy = e.Y;
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            isMouseDown = false;
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            Refresh();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void invLinCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            Refresh();
        }

        private void buttonOfApply1_Click(object sender, EventArgs e)
        {
            surfaces.Clear();
            calcPyramid();

            Refresh();
        }

        private void izometrCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            surfaces.Clear();
            calcPyramid();

            Refresh();
        }
    }
}
