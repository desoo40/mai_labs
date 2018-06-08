using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Drawing.Drawing2D;

namespace Ч.М.Лаб._4._2_Герасименко_Н.А._8о_303
{
    public partial class ResultForm : Form
    {
        double[,] XotT;
        double[,] RRpogrotT;
        double[,] XotTtochn;

        public ResultForm(double[,] XotT, double[,] RRpogrotT)
        {
            InitializeComponent();
            this.XotT = XotT;
            this.RRpogrotT = RRpogrotT;
            InitTochn();
        }

        private void InitTochn()
        {
            XotTtochn = new double[XotT.GetLength(0), XotT.GetLength(1)];
            for (int i = 0; i < XotTtochn.GetLength(0); i++)
            {
                XotTtochn[i, 0] = Math.Exp(-XotT[i, 1]) / XotT[i, 1];
                XotTtochn[i, 1] = XotT[i, 1];
            }
            double tochnPogr = 0;
            for (int i = 1; i < XotTtochn.GetLength(0)-1; i++)
            {
                if (Math.Abs(XotT[i, 0] - XotTtochn[i, 0]) > tochnPogr) tochnPogr = Math.Abs(XotT[i, 0] - XotTtochn[i, 0]);
            }
            textBoxTochnPogr.Text = Convert.ToString(tochnPogr).Substring(0, 10);
        }

        private void pictureBoxXotT_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawLine(new Pen(Color.Gray), new Point(0, pictureBoxXotT.Size.Height / 2), new Point(pictureBoxXotT.Size.Width, pictureBoxXotT.Size.Height / 2));
            e.Graphics.DrawLine(new Pen(Color.Gray), new Point(pictureBoxXotT.Size.Width / 2, 0), new Point(pictureBoxXotT.Size.Width / 2, pictureBoxXotT.Size.Height));

            //double coefK = pictureBoxXotT.Size.Width / (Convert.ToDouble(textBox14.Text));
            //double h = (Convert.ToDouble(textBox14.Text)) / (Convert.ToDouble(textBox13.Text));

            if (XotT != null)
            {
                int minPointNum = 0;
                int maxPointNum = 0;
                for (int i = 0; i < XotT.GetLength(0); i++)
                {
                    if (XotT[minPointNum, 0] > XotT[i, 0]) minPointNum = i;
                    if (XotT[maxPointNum, 0] < XotT[i, 0]) maxPointNum = i;
                }

                //PointF maxYpoint = new PointF();
                //PointF maxXpoint = new PointF((float)XotT[XotT.GetLength(0), 1], (float)XotT[XotT.GetLength(0), 0]);

                List<Point> screenItems = new List<Point>();
                List<Point> screenItems2 = new List<Point>();

                double globalWidth = 0;
                double globalHight = 0;
                for (int i = 0; i < XotT.GetLength(0); i++)
                {
                    if (Math.Abs(XotT[i, 0]) > globalHight) { globalHight = Math.Abs(XotT[i, 0]); /*maxYpoint.X = (float)XotT[i, 1]; maxYpoint.Y = (float)XotT[i, 0];*/ };
                    if (Math.Abs(XotT[i, 1]) > globalWidth) { globalWidth = Math.Abs(XotT[i, 1]); };
                }

                double Kwidth = pictureBoxXotT.Size.Width / (2 * globalWidth);
                double Khight = pictureBoxXotT.Size.Height / (2 * globalHight);
                double K = Math.Min(Kwidth, Khight);
                // }

                for (int i = 0; i < XotT.GetLength(0); i++)
                {
                    screenItems.Add(new Point((int)((Kwidth / 1.5 * XotT[i, 1]) + pictureBoxXotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * XotT[i, 0]) + pictureBoxXotT.Size.Height / 2)));
                }
                for (int i = 0; i < XotT.GetLength(0); i++)
                {
                    screenItems2.Add(new Point((int)((Kwidth / 1.5 * XotTtochn[i, 1]) + pictureBoxXotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * XotTtochn[i, 0]) + pictureBoxXotT.Size.Height / 2)));
                }

                Pen pointPen = new Pen(Color.Blue, 1.0f);
                pointPen.DashStyle = DashStyle.Dash;
                //e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * XotT[minPointNum, 1]) + pictureBoxXotT.Size.Width / 2),
                //                               (int)((-1) * (Khight / 1.5 * XotT[minPointNum, 0]) + pictureBoxXotT.Size.Height / 2))), (new Point((int)(pictureBoxXotT.Size.Width / 2),
                //                               (int)((-1) * (Khight / 1.5 * XotT[minPointNum, 0]) + pictureBoxXotT.Size.Height / 2))));
                //e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * XotT[minPointNum, 1]) + pictureBoxXotT.Size.Width / 2),
                //                               (int)((-1) * (Khight / 1.5 * XotT[minPointNum, 0]) + pictureBoxXotT.Size.Height / 2))), (new Point((int)((Kwidth / 1.5 * XotT[minPointNum, 1]) + pictureBoxXotT.Size.Width / 2),
                //                               pictureBoxXotT.Size.Height / 2)));

                string drawStringMinX = Convert.ToString(XotT[minPointNum, 1]);
                string drawStringMinY = Convert.ToString(XotT[minPointNum, 0]);

                if (!drawStringMinX.Contains(",")) drawStringMinX += ",";
                do
                {
                    drawStringMinX += "0";
                } while (drawStringMinX.Length < 6);
                if (!drawStringMinY.Contains(",")) drawStringMinY += ",";
                do
                {
                    drawStringMinY += "0";
                } while (drawStringMinY.Length < 6);
                drawStringMinX = drawStringMinX.Substring(0, 4);
                drawStringMinY = drawStringMinY.Substring(0, 5);

                System.Drawing.Font drawFont = new System.Drawing.Font("Arial", 8);
                System.Drawing.SolidBrush drawBrush = new System.Drawing.SolidBrush(System.Drawing.Color.Black);

                //e.Graphics.DrawString(drawStringMinY, drawFont, drawBrush, new Point((int)(pictureBoxXotT.Size.Width / 2 - 33),
                //                               (int)((-1) * (Khight / 1.5 * XotT[minPointNum, 0]) + pictureBoxXotT.Size.Height / 2 - 7)));
                //e.Graphics.DrawString(drawStringMinX, drawFont, drawBrush, new Point((int)((Kwidth / 1.5 * XotT[minPointNum, 1]) + pictureBoxXotT.Size.Width / 2 - 14),
                //                               pictureBoxXotT.Size.Height / 2 - 14));

                pointPen.DashStyle = DashStyle.Dash;
                //e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * XotT[minPointNum, 1]) + pictureBoxXotT.Size.Width / 2),
                //                               (int)((-1) * (Khight / 1.5 * XotT[minPointNum, 0]) + pictureBoxXotT.Size.Height / 2))), (new Point((int)(pictureBoxXotT.Size.Width / 2),
                //                               (int)((-1) * (Khight / 1.5 * XotT[minPointNum, 0]) + pictureBoxXotT.Size.Height / 2))));
                //e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * XotT[minPointNum, 1]) + pictureBoxXotT.Size.Width / 2),
                //                               (int)((-1) * (Khight / 1.5 * XotT[minPointNum, 0]) + pictureBoxXotT.Size.Height / 2))), (new Point((int)((Kwidth / 1.5 * XotT[minPointNum, 1]) + pictureBoxXotT.Size.Width / 2),
                //                               pictureBoxXotT.Size.Height / 2)));

                string drawStringNachX = Convert.ToString(XotT[0, 1]);
                string drawStringNachY = Convert.ToString(XotT[0, 0]);

                if (!drawStringNachX.Contains(",")) drawStringNachX += ",";
                do
                {
                    drawStringNachX += "0";
                } while (drawStringNachX.Length < 6);
                if (!drawStringNachY.Contains(",")) drawStringNachY += ",";
                do
                {
                    drawStringNachY += "0";
                } while (drawStringNachY.Length < 6);
                drawStringNachX = drawStringNachX.Substring(0, 4);
                drawStringNachY = drawStringNachY.Substring(0, 5);

                e.Graphics.DrawString(drawStringNachY, drawFont, drawBrush, new Point((int)(pictureBoxXotT.Size.Width / 2 - 33),
                                               (int)((-1) * (Khight / 1.5 * XotT[0, 0]) + pictureBoxXotT.Size.Height / 2 - 7)));
                e.Graphics.DrawString(drawStringNachX, drawFont, drawBrush, new Point((int)((Kwidth / 1.5 * XotT[0, 1]) + pictureBoxXotT.Size.Width / 2 - 14),
                                               pictureBoxXotT.Size.Height / 2 - 14));

                pointPen.DashStyle = DashStyle.Dash;
                e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * XotT[0, 1]) + pictureBoxXotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * XotT[0, 0]) + pictureBoxXotT.Size.Height / 2))), (new Point((int)(pictureBoxXotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * XotT[0, 0]) + pictureBoxXotT.Size.Height / 2))));
                e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * XotT[0, 1]) + pictureBoxXotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * XotT[0, 0]) + pictureBoxXotT.Size.Height / 2))), (new Point((int)((Kwidth / 1.5 * XotT[0, 1]) + pictureBoxXotT.Size.Width / 2),
                                               pictureBoxXotT.Size.Height / 2)));

                string drawStringKonX = Convert.ToString(XotT[XotT.GetLength(0)-1, 1]);
                string drawStringKonY = Convert.ToString(XotT[XotT.GetLength(0)-1, 0]);

                if (!drawStringKonX.Contains(",")) drawStringKonX += ",";
                do
                {
                    drawStringKonX += "0";
                } while (drawStringKonX.Length < 6);
                if (!drawStringKonY.Contains(",")) drawStringKonY += ",";
                do
                {
                    drawStringKonY += "0";
                } while (drawStringKonY.Length < 6);
                drawStringKonX = drawStringKonX.Substring(0, 4);
                drawStringKonY = drawStringKonY.Substring(0, 5);

                e.Graphics.DrawString(drawStringKonY, drawFont, drawBrush, new Point((int)(pictureBoxXotT.Size.Width / 2 - 33),
                                               (int)((-1) * (Khight / 1.5 * XotT[XotT.GetLength(0)-1, 0]) + pictureBoxXotT.Size.Height / 2 - 7)));
                e.Graphics.DrawString(drawStringKonX, drawFont, drawBrush, new Point((int)((Kwidth / 1.5 * XotT[XotT.GetLength(0)-1, 1]) + pictureBoxXotT.Size.Width / 2 - 14),
                                               pictureBoxXotT.Size.Height / 2 - 14));


                pointPen.DashStyle = DashStyle.Dash;
                e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * XotT[XotT.GetLength(0)-1, 1]) + pictureBoxXotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * XotT[XotT.GetLength(0)-1, 0]) + pictureBoxXotT.Size.Height / 2))), (new Point((int)(pictureBoxXotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * XotT[XotT.GetLength(0)-1, 0]) + pictureBoxXotT.Size.Height / 2))));
                e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * XotT[XotT.GetLength(0)-1, 1]) + pictureBoxXotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * XotT[XotT.GetLength(0)-1, 0]) + pictureBoxXotT.Size.Height / 2))), (new Point((int)((Kwidth / 1.5 * XotT[XotT.GetLength(0)-1, 1]) + pictureBoxXotT.Size.Width / 2),
                                               pictureBoxXotT.Size.Height / 2)));

                List<Point> pointFup = new List<Point>();
                for (int i = 0; i < screenItems.Count; i++)
                {
                    if (screenItems[i].Y > 0) { pointFup.Add(screenItems[i]); }
                }
                for (int i = 0; i < pointFup.Count - 1; i++)
                {
                    e.Graphics.DrawLine(new Pen(Color.Red, 2.0f), pointFup[i].X, pointFup[i].Y,
                                    pointFup[i + 1].X, pointFup[i + 1].Y);
                }

                //построение точек с отрицательными координатами Y
                List<Point> pointFdown = new List<Point>();
                for (int i = 1; i < screenItems.Count; i++)
                {
                    if (screenItems[i].Y < 0) { pointFdown.Add(screenItems[i]); }
                }
                for (int i = 0; i < pointFdown.Count - 1; i++)
                {
                    e.Graphics.DrawLine(new Pen(Color.Red, 2.0f), pointFdown[i].X, pointFdown[i].Y,
                                    pointFdown[i + 1].X, pointFdown[i + 1].Y);
                }

                List<Point> pointFup2 = new List<Point>();
                for (int i = 0; i < screenItems2.Count; i++)
                {
                    if (screenItems2[i].Y > 0) { pointFup2.Add(screenItems2[i]); }
                }
                for (int i = 0; i < pointFup2.Count - 1; i++)
                {
                    e.Graphics.DrawLine(new Pen(Color.Blue, 1.0f), pointFup2[i].X, pointFup2[i].Y,
                                    pointFup2[i + 1].X, pointFup2[i + 1].Y);
                }

                //построение точек с отрицательными координатами Y
                List<Point> pointFdown2 = new List<Point>();
                for (int i = 1; i < screenItems.Count; i++)
                {
                    if (screenItems2[i].Y < 0) { pointFdown2.Add(screenItems2[i]); }
                }
                for (int i = 0; i < pointFdown2.Count - 1; i++)
                {
                    e.Graphics.DrawLine(new Pen(Color.Blue, 1.0f), pointFdown2[i].X, pointFdown2[i].Y,
                                    pointFdown2[i + 1].X, pointFdown2[i + 1].Y);
                }
            }

        }

        private void pictureBoxRRpogrotT_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawLine(new Pen(Color.Gray), new Point(0, pictureBoxRRpogrotT.Size.Height / 2), new Point(pictureBoxRRpogrotT.Size.Width, pictureBoxRRpogrotT.Size.Height / 2));
            e.Graphics.DrawLine(new Pen(Color.Gray), new Point(pictureBoxRRpogrotT.Size.Width / 2, 0), new Point(pictureBoxRRpogrotT.Size.Width / 2, pictureBoxRRpogrotT.Size.Height));

            //double coefK = pictureBoxRRpogrotT.Size.Width / (Convert.ToDouble(textBox14.Text));
            //double h = (Convert.ToDouble(textBox14.Text)) / (Convert.ToDouble(textBox13.Text));

            if (RRpogrotT != null)
            {
                int minPointNum = 0;
                int maxPointNum = 0;
                for (int i = 0; i < RRpogrotT.GetLength(0); i++)
                {
                    if (RRpogrotT[minPointNum, 0] > RRpogrotT[i, 0]) minPointNum = i;
                    if (RRpogrotT[maxPointNum, 0] < RRpogrotT[i, 0]) maxPointNum = i;
                }

                //PointF maxYpoint = new PointF();
                //PointF maxXpoint = new PointF((float)RRpogrotT[RRpogrotT.GetLength(0), 1], (float)RRpogrotT[RRpogrotT.GetLength(0), 0]);

                List<Point> screenItems = new List<Point>();

                double globalWidth = 0;
                double globalHight = 0;
                for (int i = 0; i < RRpogrotT.GetLength(0); i++)
                {
                    if (Math.Abs(RRpogrotT[i, 0]) > globalHight) { globalHight = Math.Abs(RRpogrotT[i, 0]); /*maxYpoint.X = (float)RRpogrotT[i, 1]; maxYpoint.Y = (float)RRpogrotT[i, 0];*/ };
                    if (Math.Abs(RRpogrotT[i, 1]) > globalWidth) { globalWidth = Math.Abs(RRpogrotT[i, 1]); };
                }

                double Kwidth = pictureBoxRRpogrotT.Size.Width / (2 * globalWidth);
                double Khight = pictureBoxRRpogrotT.Size.Height / (2 * globalHight);
                double K = Math.Min(Kwidth, Khight);
                // }

                for (int i = 0; i < RRpogrotT.GetLength(0); i++)
                {
                    screenItems.Add(new Point((int)((Kwidth / 1.5 * RRpogrotT[i, 1]) + pictureBoxRRpogrotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * RRpogrotT[i, 0]) + pictureBoxRRpogrotT.Size.Height / 2)));
                }

                Pen pointPen = new Pen(Color.Blue, 1.0f);
                pointPen.DashStyle = DashStyle.Dash;
                e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * RRpogrotT[minPointNum, 1]) + pictureBoxRRpogrotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * RRpogrotT[minPointNum, 0]) + pictureBoxRRpogrotT.Size.Height / 2))), (new Point((int)(pictureBoxRRpogrotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * RRpogrotT[minPointNum, 0]) + pictureBoxRRpogrotT.Size.Height / 2))));
                e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * RRpogrotT[minPointNum, 1]) + pictureBoxRRpogrotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * RRpogrotT[minPointNum, 0]) + pictureBoxRRpogrotT.Size.Height / 2))), (new Point((int)((Kwidth / 1.5 * RRpogrotT[minPointNum, 1]) + pictureBoxRRpogrotT.Size.Width / 2),
                                               pictureBoxRRpogrotT.Size.Height / 2)));

                string drawStringMinX = Convert.ToString(RRpogrotT[minPointNum, 1]);
                string drawStringMinY = Convert.ToString(RRpogrotT[minPointNum, 0]);

                if (!drawStringMinX.Contains(",")) drawStringMinX += ",";
                do
                {
                    drawStringMinX += "0";
                } while (drawStringMinX.Length < 6);
                if (!drawStringMinY.Contains(",")) drawStringMinY += ",";
                do
                {
                    drawStringMinY += "0";
                } while (drawStringMinY.Length < 6);
                drawStringMinX = drawStringMinX.Substring(0, 4);
                drawStringMinY = drawStringMinY.Substring(0, 5);

                System.Drawing.Font drawFont = new System.Drawing.Font("Arial", 8);
                System.Drawing.SolidBrush drawBrush = new System.Drawing.SolidBrush(System.Drawing.Color.Black);

                e.Graphics.DrawString(drawStringMinY, drawFont, drawBrush, new Point((int)(pictureBoxRRpogrotT.Size.Width / 2 - 33),
                                               (int)((-1) * (Khight / 1.5 * RRpogrotT[minPointNum, 0]) + pictureBoxRRpogrotT.Size.Height / 2 - 7)));
                e.Graphics.DrawString(drawStringMinX, drawFont, drawBrush, new Point((int)((Kwidth / 1.5 * RRpogrotT[minPointNum, 1]) + pictureBoxRRpogrotT.Size.Width / 2 - 14),
                                               pictureBoxRRpogrotT.Size.Height / 2 - 14));

                string drawStringNachX = Convert.ToString(RRpogrotT[0, 1]);
                string drawStringNachY = Convert.ToString(RRpogrotT[0, 0]);

                if (!drawStringNachX.Contains(",")) drawStringNachX += ",";
                do
                {
                    drawStringNachX += "0";
                } while (drawStringNachX.Length < 6);
                if (!drawStringNachY.Contains(",")) drawStringNachY += ",";
                do
                {
                    drawStringNachY += "0";
                } while (drawStringNachY.Length < 6);
                drawStringNachX = drawStringNachX.Substring(0, 4);
                drawStringNachY = drawStringNachY.Substring(0, 5);

                e.Graphics.DrawString(drawStringNachY, drawFont, drawBrush, new Point((int)(pictureBoxRRpogrotT.Size.Width / 2 - 33),
                                               (int)((-1) * (Khight / 1.5 * RRpogrotT[0, 0]) + pictureBoxRRpogrotT.Size.Height / 2 - 7)));
                e.Graphics.DrawString(drawStringNachX, drawFont, drawBrush, new Point((int)((Kwidth / 1.5 * RRpogrotT[0, 1]) + pictureBoxRRpogrotT.Size.Width / 2 - 14),
                                               pictureBoxRRpogrotT.Size.Height / 2 - 14));

                pointPen.DashStyle = DashStyle.Dash;
                e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * RRpogrotT[0, 1]) + pictureBoxRRpogrotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * RRpogrotT[0, 0]) + pictureBoxRRpogrotT.Size.Height / 2))), (new Point((int)(pictureBoxRRpogrotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * RRpogrotT[0, 0]) + pictureBoxRRpogrotT.Size.Height / 2))));
                e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * RRpogrotT[0, 1]) + pictureBoxRRpogrotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * RRpogrotT[0, 0]) + pictureBoxRRpogrotT.Size.Height / 2))), (new Point((int)((Kwidth / 1.5 * RRpogrotT[0, 1]) + pictureBoxRRpogrotT.Size.Width / 2),
                                               pictureBoxRRpogrotT.Size.Height / 2)));

                string drawStringKonX = Convert.ToString(RRpogrotT[RRpogrotT.GetLength(0) - 1, 1]);
                string drawStringKonY = Convert.ToString(RRpogrotT[RRpogrotT.GetLength(0) - 1, 0]);

                if (!drawStringKonX.Contains(",")) drawStringKonX += ",";
                do
                {
                    drawStringKonX += "0";
                } while (drawStringKonX.Length < 6);
                if (!drawStringKonY.Contains(",")) drawStringKonY += ",";
                do
                {
                    drawStringKonY += "0";
                } while (drawStringKonY.Length < 6);
                drawStringKonX = drawStringKonX.Substring(0, 4);
                drawStringKonY = drawStringKonY.Substring(0, 5);

                e.Graphics.DrawString(drawStringKonY, drawFont, drawBrush, new Point((int)(pictureBoxRRpogrotT.Size.Width / 2 - 33),
                                               (int)((-1) * (Khight / 1.5 * RRpogrotT[RRpogrotT.GetLength(0) - 1, 0]) + pictureBoxRRpogrotT.Size.Height / 2 - 7)));
                e.Graphics.DrawString(drawStringKonX, drawFont, drawBrush, new Point((int)((Kwidth / 1.5 * RRpogrotT[RRpogrotT.GetLength(0) - 1, 1]) + pictureBoxRRpogrotT.Size.Width / 2 - 14),
                                               pictureBoxRRpogrotT.Size.Height / 2 - 14));

                pointPen.DashStyle = DashStyle.Dash;
                e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * RRpogrotT[RRpogrotT.GetLength(0) - 1, 1]) + pictureBoxRRpogrotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * RRpogrotT[RRpogrotT.GetLength(0) - 1, 0]) + pictureBoxRRpogrotT.Size.Height / 2))), (new Point((int)(pictureBoxRRpogrotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * RRpogrotT[RRpogrotT.GetLength(0) - 1, 0]) + pictureBoxRRpogrotT.Size.Height / 2))));
                e.Graphics.DrawLine(pointPen, (new Point((int)((Kwidth / 1.5 * RRpogrotT[RRpogrotT.GetLength(0) - 1, 1]) + pictureBoxRRpogrotT.Size.Width / 2),
                                               (int)((-1) * (Khight / 1.5 * RRpogrotT[RRpogrotT.GetLength(0) - 1, 0]) + pictureBoxRRpogrotT.Size.Height / 2))), (new Point((int)((Kwidth / 1.5 * RRpogrotT[RRpogrotT.GetLength(0) - 1, 1]) + pictureBoxRRpogrotT.Size.Width / 2),
                                               pictureBoxRRpogrotT.Size.Height / 2)));

                List<Point> pointFup = new List<Point>();
                for (int i = 0; i < screenItems.Count; i++)
                {
                    if (screenItems[i].Y > 0) { pointFup.Add(screenItems[i]); }
                }
                for (int i = 0; i < pointFup.Count - 1; i++)
                {
                    e.Graphics.DrawLine(new Pen(Color.Red, 1.0f), pointFup[i].X, pointFup[i].Y,
                                    pointFup[i + 1].X, pointFup[i + 1].Y);
                }

                //построение точек с отрицательными координатами Y
                List<Point> pointFdown = new List<Point>();
                for (int i = 1; i < screenItems.Count; i++)
                {
                    if (screenItems[i].Y < 0) { pointFdown.Add(screenItems[i]); }
                }
                for (int i = 0; i < pointFdown.Count - 1; i++)
                {
                    e.Graphics.DrawLine(new Pen(Color.Red, 1.0f), pointFdown[i].X, pointFdown[i].Y,
                                    pointFdown[i + 1].X, pointFdown[i + 1].Y);
                }
            }
        }
    }
}
