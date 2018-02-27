using System;
using System.Drawing;


namespace К.Г.__Лаб._7___Герасименко._8о_303Б
{
    public class BezierCurve
    {
        private int N = 40;

        private PointF[] dataPoints;

        public BezierCurve(PointF[] points)
        {
            dataPoints = points;
            Invalidate();
        }

        public PointF[] DrawingPoints { get; private set; }

        public PointF[] DataPoints //4 штуки
        {
            get { return dataPoints; }
            set
            {
                dataPoints = value;
                Invalidate();
            }
        }

        public PointF this[int i]
        {
            get { return dataPoints[i]; }
            set
            {
                dataPoints[i] = value;
                Invalidate();
            }
        }

        public void Invalidate()
        {
            DrawingPoints = new PointF[N + 1];
            float dt = 1f / N;
            float t = 0f;
            for (int i = 0; i <= N; i++)
            {
                DrawingPoints[i] = B(t);
                t += dt;
            }
        }

        private PointF B(float t)
        {
            float c0 = (1 - t) * (1 - t) * (1 - t);
            float c1 = (1 - t) * (1 - t) * 3 * t;
            float c2 = (1 - t) * t * 3 * t;
            float c3 = t * t * t;
            float x = c0 * dataPoints[0].X + c1 * dataPoints[1].X + c2 * dataPoints[2].X + c3 * dataPoints[3].X;
            float y = c0 * dataPoints[0].Y + c1 * dataPoints[1].Y + c2 * dataPoints[2].Y + c3 * dataPoints[3].Y;
            return new PointF(x, y);
        }

        public void Draw(Graphics g)
        {
            Pen pen = new Pen(System.Drawing.SystemColors.Highlight, 2f);
            g.DrawLines(pen, DrawingPoints);
        }
    }
}