using System;
using System.Collections.Generic;
using System.IO;
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
        public string nameOrig;
        public double oldbalanceOrg;
        public double newbalanceOrg;
        public string nameDest;
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
            nameOrig = sarr[3];
            sarr[4] = sarr[4].Replace('.', ',');
            oldbalanceOrg = Convert.ToDouble(sarr[4]);
            sarr[5] = sarr[5].Replace('.', ',');
            newbalanceOrg = Convert.ToDouble(sarr[5]);
            nameDest = sarr[6];

            sarr[7] = sarr[7].Replace('.', ',');
            oldbalanceDest = Convert.ToDouble(sarr[7]);

            sarr[8] = sarr[8].Replace('.', ',');
            newbalanceDest = Convert.ToDouble(sarr[8]);

            isFraud = sarr[9] == "1" ? true : false;
            isFlaggedFraud = sarr[10] == "1" ? true : false;
        }
    }

    class TypeOfTrans
    {
        public int send = 0;
        public int reciv = 0;

        public TypeOfTrans (int a, int b)
        {
            send = a;
            reciv = b;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var str = File.ReadAllLines("data.csv").ToList();
            var trList = new List<Transaction>();
            var i = 0;
            var sumFraud = 0;

            var clientsDict = new Dictionary<string, TypeOfTrans>();

            str.RemoveAt(0);
            foreach (var el in str)
            {
                trList.Add(new Transaction(el));

                var sender = trList[i].nameOrig;
                var reciever = trList[i].nameDest;

                if (i % 10000 == 0)
                    Console.Write("\r{0}", i);

                if (reciever.Contains("M"))
                {
                    ++i;
                    continue;
                }

                if (clientsDict.ContainsKey(sender))
                    clientsDict[sender].send++;
                else
                    clientsDict.Add(sender, new TypeOfTrans(1, 0));


                if (clientsDict.ContainsKey(reciever))
                    clientsDict[reciever].reciv++;
                else
                    clientsDict.Add(reciever, new TypeOfTrans(0, 1));

                ++i;
            }
            Console.WriteLine(clientsDict.Count);
            i = 0;
            //foreach(var el in clientsDict)
            //{
            //    if (i % 10000 == 0)
            //        Console.Write("\r{0}", i);

            //    File.AppendAllText("clients.txt", el.Key + "\t SEND: " + el.Value.send + "\t RECIVE: " + el.Value.reciv + "\n");
            //    //Console.WriteLine(el.Key + "\t SEND: " + el.Value.send + "\t RECIVE: " + el.Value.reciv);
            //    ++i;
            //}

            //Console.WriteLine("\n" + sumFraud);

        }
    }
}
