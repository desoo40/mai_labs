using System;
using System.Drawing;
using System.Windows.Forms;

namespace К.Г.__Лаб._7___Герасименко._8о_303Б
{
    public class Marker
    {
        public Marker(int x, int y)
        {
            rectangle = new RectangleF(x - Radius / 2f, y - Radius / 2f, Radius, Radius);
        }

        public Action<PointF> OnDrag { get; set; }

        public Action<PointF> OnMouseDown { get; set; }

        public PointF Location
        {
            get { return new PointF(rectangle.X + Radius / 2f, rectangle.Y + Radius / 2f); }
        }

        public void Draw(Graphics g)
        {
            g.FillEllipse(Brushes.Black, rectangle);
        }

        public void MouseDown(MouseEventArgs e)
        {
            if (rectangle.Contains(e.Location))
            {
                drag = true;
                if (OnMouseDown != null)
                {
                    OnMouseDown(e.Location);
                }
            }
        }

        public void MouseUp()
        {
            drag = false;
        }

        public void MouseMove(MouseEventArgs e)
        {
            if (drag)
            {
                rectangle.X = e.X - Radius / 2f;
                rectangle.Y = e.Y - Radius / 2f;
                if (OnDrag != null)
                {
                    OnDrag(e.Location);
                }
            }
        }

        private int Radius = 10;
        private bool drag;
        private RectangleF rectangle;
    }
}