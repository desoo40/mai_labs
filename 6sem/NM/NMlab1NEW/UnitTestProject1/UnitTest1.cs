using System;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using NMlab1;

namespace UnitTestProject1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void CalcNorm_1_1_4returned4_24()
        {
            //arrange
            List<double> b = new List<double>()
            { 1, 1, 4 };

            double expected = 4.24;

            //act
            var res = QRAlgorythm.CalcNorm(b);

            //assert

            Assert.AreEqual(expected, res, 0.01);
        }

        [TestMethod]
        public void CalcV_1_1_4returned5d24_1_4()
        {
            //arrange
            List<double> b = new List<double>()
                { 1, 1, 4 };

            List<double> expected = new List<double>()
            {5.24, 1, 4};

            //act
            var res = QRAlgorythm.CalcV(b, 0);

            //assert

            Assert.AreEqual(expected[0], res[0], 0.01);
            Assert.AreEqual(expected[1], res[1], 0.01);
            Assert.AreEqual(expected[2], res[2], 0.01);

        }

        [TestMethod]
        public void CalcV_m3d77_m0d29_m2d17returned0_m2d48_m2d17()
        {
            //arrange
            List<double> b = new List<double>()
                { -3.77, -0.29, -2.17 };

            List<double> expected = new List<double>()
                {0, -2.48, -2.17};

            //act
            var res = QRAlgorythm.CalcV(b, 1);

            //assert

            Assert.AreEqual(expected[0], res[0], 0.01);
            Assert.AreEqual(expected[1], res[1], 0.01);
            Assert.AreEqual(expected[2], res[2], 0.01);

        }
        [TestMethod]
        public void FindEps6()
        {
            //arrange
            List<double> b = new List<double>()
                { 6.34, 0.034, 0.023};

            double expected = 0.01;

            //act
            var res = QRAlgorythm.FindEps(b);

            //assert

            Assert.IsTrue(res > expected);
        }
        [TestMethod]
        public void FindEps7()
        {
            //arrange
            List<double> b = new List<double>()
                { 6.34, -0.0014, 0.0006};

            double expected = 0.01;

            //act
            var res = QRAlgorythm.FindEps(b);

            //assert

            Assert.IsTrue(res < expected);
        }
    }
}
