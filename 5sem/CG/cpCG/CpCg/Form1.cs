using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Drawing2D;
using System.Threading;

namespace CpCG
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            dataPointCount = 0;
            withMarkers = checkBoxOfMerkersEnabled.Checked;
            panelOfApproximation.Enabled = checkBoxOfMerkersEnabled.Checked;
            panelOfDataPoints.Enabled = checkBoxOfMerkersEnabled.Checked;

            dataPoints1 = new MyPoint[4];
            MyPoint point11 = new MyPoint(0, 0, 0, 1);
            MyPoint point12 = new MyPoint(1, -1, 0, 1);
            MyPoint point13 = new MyPoint(2, 0, 0, 1);
            MyPoint point14 = new MyPoint(3, -1, 0, 1);

            dataPoints1[0] = point11;
            dataPoints1[1] = point12;
            dataPoints1[2] = point13;
            dataPoints1[3] = point14;

            dataPoints2 = new MyPoint[4];
            MyPoint point21 = new MyPoint(0, 0, 1, 1);
            MyPoint point22 = new MyPoint(1, -1, 1, 1);
            MyPoint point23 = new MyPoint(2, 0, 1, 1);
            MyPoint point24 = new MyPoint(3, -1, 1, 1);

            dataPoints2[0] = point21;
            dataPoints2[1] = point22;
            dataPoints2[2] = point23;
            dataPoints2[3] = point24;

            calcCurves();

            mx = 0;
            my = 0;
            cx = 0;
            cy = 0;

            scale = 100;
            mashtabK = 0;

            isMouseDown = false;
        }

        private void calcCurves()
        {
            bezierCurve1 = new BezierCurve(dataPoints1, int.Parse(textBoxOfNumberOfDrawPoints.Text));
            bezierCurve2 = new BezierCurve(dataPoints2, int.Parse(textBoxOfNumberOfDrawPoints.Text));
            linearSurface = new LinearSurface(bezierCurve1, bezierCurve2);
        }

        private void mashtabMinusButton_Click(object sender, EventArgs e)
        {
            mashtabK -= 10;

            Refresh();
        }

        private void mashtabPlusButton_Click(object sender, EventArgs e)
        {
            mashtabK += 10;

            Refresh();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.SmoothingMode = SmoothingMode.HighQuality;
            double zoomLevel = (scale + mashtabK) / 1000;
            double coeff = Math.Max(e.ClipRectangle.Width, e.ClipRectangle.Height) * zoomLevel;

            ShiftMatrix sh = new ShiftMatrix(e.ClipRectangle.Width / 2, e.ClipRectangle.Height / 2, 0);
            ScalingMatrix sc = new ScalingMatrix(coeff, coeff, coeff);
            RotationMatrix rtx = new RotationMatrix('X', my * Math.PI / 180.0);
            RotationMatrix rty = new RotationMatrix('Y', -mx * Math.PI / 180.0);
            Matrix preobr = sh * rtx * rty * sc;

            linearSurface.Draw(preobr, e.Graphics, dataPointCount, withMarkers);
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

        private void buttonOfApply1_Click(object sender, EventArgs e)
        {
            calcCurves();
            Refresh();
        }

        private void buttonRight_Click(object sender, EventArgs e)
        {
            if (dataPointCount < 4) dataPoints1[dataPointCount].x += 1;
            else dataPoints2[dataPointCount - 4].x += 1;
            calcCurves();

            Refresh();
        }

        private void buttonLeft_Click(object sender, EventArgs e)
        {
            if (dataPointCount < 4) dataPoints1[dataPointCount].x -= 1;
            else dataPoints2[dataPointCount - 4].x -= 1;
            calcCurves();

            Refresh();
        }

        private void buttonUp_Click(object sender, EventArgs e)
        {
            if (dataPointCount < 4) dataPoints1[dataPointCount].y -= 1;
            else dataPoints2[dataPointCount - 4].y -= 1;
            calcCurves();

            Refresh();
        }

        private void buttonDown_Click(object sender, EventArgs e)
        {
            if (dataPointCount < 4) dataPoints1[dataPointCount].y += 1;
            else dataPoints2[dataPointCount - 4].y += 1;
            calcCurves();

            Refresh();
        }
        private void buttonNaNas_Click(object sender, EventArgs e)
        {
            if (dataPointCount < 4) dataPoints1[dataPointCount].z += 1;
            else dataPoints2[dataPointCount - 4].z += 1;
            calcCurves();

            Refresh();
        }

        private void buttonOtNas_Click(object sender, EventArgs e)
        {
            if (dataPointCount < 4) dataPoints1[dataPointCount].z -= 1;
            else dataPoints2[dataPointCount - 4].z -= 1;
            calcCurves();

            Refresh();
        }

        // текущие координаты курсора и координаты его предыдущего положения

        int mx, my, cx, cy;

        // масштаб

        float scale;
        double mashtabK;

        MyPoint[] dataPoints1;
        MyPoint[] dataPoints2;
        int dataPointCount;

        bool isMouseDown;

        BezierCurve bezierCurve1;
        BezierCurve bezierCurve2;
        LinearSurface linearSurface;
        bool withMarkers;

        private void buttonOfDataPointCounter_Click(object sender, EventArgs e)
        {
            if (dataPointCount < 8)
            {
                dataPointCount++;
                if (dataPointCount == 8)
                {
                    buttonDown.Enabled = false;
                    buttonUp.Enabled = false;
                    buttonRight.Enabled = false;
                    buttonLeft.Enabled = false;
                    buttonNaNas.Enabled = false;
                    buttonOtNas.Enabled = false;
                }
            }
            else
            {
                dataPointCount = 0;
                buttonDown.Enabled = true;
                buttonUp.Enabled = true;
                buttonRight.Enabled = true;
                buttonLeft.Enabled = true;
                buttonNaNas.Enabled = true;
                buttonOtNas.Enabled = true;
            }

            Refresh();
        }

        private void checkBoxOfMerkersEnabled_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBoxOfMerkersEnabled.Checked) checkBoxOfMerkersEnabled.BackColor = Color.GreenYellow;
            else checkBoxOfMerkersEnabled.BackColor = System.Drawing.SystemColors.ButtonHighlight;

            panelOfApproximation.Enabled = checkBoxOfMerkersEnabled.Checked;
            panelOfDataPoints.Enabled = checkBoxOfMerkersEnabled.Checked;
            withMarkers = checkBoxOfMerkersEnabled.Checked;
            Refresh();
        }
    }
}
