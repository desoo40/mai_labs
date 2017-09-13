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
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Pen penblue = new Pen(Color.Blue, 1);
            var pi = Math.PI;

            var t = -pi/4;
            var dt = pi/360;

            t += dt;

            var a = 100.0;
            var r = (a * Math.Cos(2 * t)) / Math.Cos(t);

            var x_ = (float)(drawBox.Width / 2.0);
            var y_ = (float)(drawBox.Height / 2.0);

            Graphics g = drawBox.CreateGraphics();

            var x0 = r * Math.Sin(t);
            var y0 = r * Math.Cos(t);

            var x1 = r * Math.Sin(t);
            var y1 = r * Math.Cos(t);

            for (int i = 0; i < 180; i++)
            {
                t += dt;

                g.DrawLine(penblue, x_ + (float)x0, y_ + (float)y0, x_ + (float)x1, y_ + (float)y1);

                x0 = x1;
                y0 = y1;

                x1 = r * Math.Sin(t);
                y1 = r * Math.Cos(t);

                r = (a * Math.Cos(2 * t)) / Math.Cos(t);
            }
        }
    }
}
