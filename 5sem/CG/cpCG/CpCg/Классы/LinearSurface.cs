using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace CpCG
{
    public class LinearSurface
    {
        public LinearSurface(BezierCurve b1, BezierCurve b2)
        {
            this.b1 = b1;
            this.b2 = b2;
        }

        public void Draw(Matrix preobr, Graphics g, int dataPointCount, bool withMarkers)
        {

            BezierCurve tempb1, tempb2;
            tempb1 = preobr * b1;
            tempb2 = preobr * b2;

            Pen pen = new Pen(Color.Green, 2f);
            Pen pen1 = new Pen(Color.Red, 3f);
            for (int i = 0; i < tempb1.DrawingPoints.Length; i++)
            {
                if (i == 0 || i == tempb1.DrawingPoints.Length - 1) g.DrawLine(pen1, (int)tempb1.DrawingPoints[i].x, (int)tempb1.DrawingPoints[i].y, (int)tempb2.DrawingPoints[i].x, (int)tempb2.DrawingPoints[i].y);
                else g.DrawLine(pen, (int)tempb1.DrawingPoints[i].x, (int)tempb1.DrawingPoints[i].y, (int)tempb2.DrawingPoints[i].x, (int)tempb2.DrawingPoints[i].y);
            }

            b1.Draw(preobr, g);
            b2.Draw(preobr, g);

            if (withMarkers)
            {
                b1.DrawMarkers(preobr, g);
                b2.DrawMarkers(preobr, g);

                Pen pen2 = new Pen(Color.Blue, 1f);
                for (int i = 0; i < 8; i++)
                {
                    if (i < 3) g.DrawLine(pen2, (int)tempb1.DataPoints[i].x, (int)tempb1.DataPoints[i].y, (int)tempb1.DataPoints[i + 1].x, (int)tempb1.DataPoints[i + 1].y);
                    if (i > 4) g.DrawLine(pen2, (int)tempb2.DataPoints[i - 5].x, (int)tempb2.DataPoints[i - 5].y, (int)tempb2.DataPoints[i - 5 + 1].x, (int)tempb2.DataPoints[i - 5 + 1].y);
                }

                if (dataPointCount != 8)
                {
                    RectangleF rectangle;
                    if (dataPointCount < 4)
                    {
                        rectangle = new RectangleF((int)tempb1.DataPoints[dataPointCount].x - 5, (int)tempb1.DataPoints[dataPointCount].y - 5, (float)10, (float)10);
                    }
                    else
                    {
                        rectangle = new RectangleF((int)tempb2.DataPoints[dataPointCount - 4].x - 5, (int)tempb2.DataPoints[dataPointCount - 4].y - 5, (float)10, (float)10);
                    }
                    g.FillEllipse(Brushes.Red, rectangle);
                }
            }
        }

        BezierCurve b1; 
        BezierCurve b2;
    }
}
