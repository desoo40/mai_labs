using System;
using System.Drawing;


namespace CpCG
{
    public class BezierCurve
    {
        private int NumberOfDrawPoints;

        private MyPoint[] dataPoints;

        public BezierCurve(MyPoint[] points, int NumberOfDrawPoints)
        {
            this.NumberOfDrawPoints = NumberOfDrawPoints;
            dataPoints = points;
            Invalidate();
        }

        public MyPoint[] DrawingPoints { get; private set; }

        public MyPoint[] DataPoints //4 штуки
        {
            get { return dataPoints; }
            set
            {
                dataPoints = value;
                Invalidate();
            }
        }

        public MyPoint this[int i]
        {
            get { return dataPoints[i]; }
            set
            {
                dataPoints[i] = value;
                Invalidate();
            }
        }

        static public BezierCurve operator *(Matrix m, BezierCurve b)
        {
            MyPoint[] dataPoints1 = new MyPoint[4];

            for (int i = 0; i < 4; i++)
                dataPoints1[i] = m * b.DataPoints[i];
            
            return new BezierCurve(dataPoints1, b.NumberOfDrawPoints);
        }

        public void Invalidate()
        {
            DrawingPoints = new MyPoint[NumberOfDrawPoints + 1];
            double dt = 1f / NumberOfDrawPoints;
            double t = 0f;
            for (int i = 0; i <= NumberOfDrawPoints; i++)
            {
                DrawingPoints[i] = B(t);
                t += dt;
            }
        }

        private MyPoint B(double t)
        {
            double c0 = (1 - t) * (1 - t) * (1 - t);
            double c1 = (1 - t) * (1 - t) * 3 * t;
            double c2 = (1 - t) * t * 3 * t;
            double c3 = t * t * t;
            double x = c0 * dataPoints[0].x + c1 * dataPoints[1].x + c2 * dataPoints[2].x + c3 * dataPoints[3].x;
            double y = c0 * dataPoints[0].y + c1 * dataPoints[1].y + c2 * dataPoints[2].y + c3 * dataPoints[3].y;
            double z = c0 * dataPoints[0].z + c1 * dataPoints[1].z + c2 * dataPoints[2].z + c3 * dataPoints[3].z;
            return new MyPoint(x, y, z, 1);
        }

        public void Draw(Matrix preobr, Graphics g)
        {
            Pen pen = new Pen(Color.Aqua, 2f);
            BezierCurve b;
            b = preobr * this;

            for (int i = 0; i < DrawingPoints.Length - 1; i++)
            {
                g.DrawLine(pen, (int)b.DrawingPoints[i].x, (int)b.DrawingPoints[i].y, (int)b.DrawingPoints[i + 1].x, (int)b.DrawingPoints[i + 1].y);
            }
        }

        public void DrawMarkers(Matrix preobr, Graphics g)
        {
            BezierCurve b;
            b = preobr * this;

            for (int i = 0; i < 4; i++)
            {
                RectangleF rectangle = new RectangleF((int)b.dataPoints[i].x - 5, (int)b.dataPoints[i].y - 5, (float)10, (float)10);
                g.FillEllipse(Brushes.Black, rectangle);
            }
        }
    }
}