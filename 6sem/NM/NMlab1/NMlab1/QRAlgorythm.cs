using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    static class QRAlgorythm
    {
        static Matrix A;
        static double eps;

        public static void QR(Matrix m, double e)
        {
            A = m;
            eps = e;

        }

        private static Matrix HouseholderMtxFinder(Matrix M)
        {
            Matrix res = new Matrix(A.rows, A.columns);



            return null;
        }
        
    }
}
