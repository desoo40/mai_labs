using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ч.М.Лаб._4._2_Герасименко_Н.А._8о_303
{
    public partial class Form1 : Form
    {
        BVP bvp;

        public Form1()
        {
            InitializeComponent();
        }

        private void buttonMS_Click(object sender, EventArgs e)
        {
            double t0 = 1;
            double tk = 2;
            double stepOfRg4 = Convert.ToDouble(textBoxRg4step.Text);
            bvp = new BVP(t0, tk, stepOfRg4);
            int nnode = (int)((tk - t0) / stepOfRg4);
            double[,] tempXout = new double[nnode, 3];
            double[,] tempRRpogr = new double[nnode/2, 2];

            bvp.calcMS(tempXout, tempRRpogr);

            double[,] XotT = new double[nnode+1, 2];
            for (int i = 0; i < nnode; i++)
            {
                XotT[i, 0] = tempXout[i, 0];
                XotT[i, 1] = tempXout[i, 2];
            }
            XotT[nnode, 0] = 1 / (2 * Math.E * Math.E);
            XotT[nnode, 1] = 2;

            double[,] RRpogrotT = new double[nnode/2, 2];
            for (int i = 0; i < nnode/2; i++)
            {
                RRpogrotT[i, 0] = tempRRpogr[i, 0];
                RRpogrotT[i, 1] = tempRRpogr[i, 1];
            }
            ResultForm resForm = new ResultForm(XotT, RRpogrotT);
            resForm.ShowDialog();
        }

        private void buttonKR_Click(object sender, EventArgs e)
        {
            double t0 = 1;
            double tk = 2;
            double stepOfRg4 = Convert.ToDouble(textBoxRg4step.Text);
            bvp = new BVP(t0, tk, stepOfRg4);
            int nnode = (int)((tk - t0) / stepOfRg4);
            double[,] tempXout = new double[nnode+1, 3];
            double[,] tempRRpogr = new double[nnode / 2 + 1, 3];

            bvp.calcKR(tempXout, tempRRpogr);

            double[,] XotT = new double[nnode+1, 2];
            for (int i = 0; i < nnode+1; i++)
            {
                XotT[i, 0] = tempXout[i, 0];
                XotT[i, 1] = tempXout[i, 2];
            }
            double[,] RRpogrotT = new double[nnode / 2 + 1, 2];
            for (int i = 0; i < nnode / 2 + 1; i++)
            {
                RRpogrotT[i, 0] = tempRRpogr[i, 0];
                RRpogrotT[i, 1] = tempRRpogr[i, 2];
            }
            ResultForm resForm = new ResultForm(XotT, RRpogrotT);
            resForm.ShowDialog();
        }
    }
}
