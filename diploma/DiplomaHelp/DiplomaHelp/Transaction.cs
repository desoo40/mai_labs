using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DiplomaHelp
{
    class Transaction
    {
        public int step;
        public string type;
        public double amount;
        public string NameOrig { get; set; }
        public Client Sender { get; set; }
        public double oldbalanceOrg;

        public double newbalanceOrg;
        public string NameDest { get; set; }
        public Client Receiver { get; set; }
        public double oldbalanceDest;
        public double newbalanceDest;
        public bool isFraud;
        public bool isFlaggedFraud;

        public Transaction(string s)
        {
            var sarr = s.Split(',');

            step = Convert.ToInt32(sarr[0]);
            type = sarr[1];
            sarr[2] = sarr[2].Replace('.', ',');
            amount = Convert.ToDouble(sarr[2]);
            NameOrig = sarr[3];
            sarr[4] = sarr[4].Replace('.', ',');
            oldbalanceOrg = Convert.ToDouble(sarr[4]);
            sarr[5] = sarr[5].Replace('.', ',');
            newbalanceOrg = Convert.ToDouble(sarr[5]);
            NameDest = sarr[6];

            sarr[7] = sarr[7].Replace('.', ',');
            oldbalanceDest = Convert.ToDouble(sarr[7]);

            sarr[8] = sarr[8].Replace('.', ',');
            newbalanceDest = Convert.ToDouble(sarr[8]);

            isFraud = sarr[9] == "1";
            isFlaggedFraud = sarr[10] == "1";
        }
    }
}
