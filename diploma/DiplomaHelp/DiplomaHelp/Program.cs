using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DiplomaHelp
{
    class Program
    {
        static HashSet<string> isVisited = new HashSet<string>();

        static void Main(string[] args)
        {
            var str = File.ReadAllLines("data.csv").ToList();
            var trList = new List<Transaction>();

            var clientsIdList = new List<string>();
            var clientsGraph = new Dictionary<Client, List<Client>>();

            var merchantsDict = new Dictionary<string, int>();
            var clientsDict = new Dictionary<string, TypeOfTrans>();

            var sumPayment = 0;
            var sumDebit = 0;
            var sumCashIn = 0;
            var sumCashOut = 0;
            var sumTransfer = 0;

            var sumFraud = 0;
            var sumFlaggedFraud = 0;

            var fraudPayments = 0;
            var fraudDebits = 0;
            var fraudCashIn = 0;
            var fraudCashOut = 0;
            var fraudTransfer = 0;

            var sumM = 0;

            var kek = new Dictionary<string, int>();
            str.RemoveAt(0);

            Console.WriteLine("Загрузка данных:");
            var strCount = str.Count;
            //var strCount = 1000001;

            var strFr = new List<string>();

            for (int i = 0; i < strCount; i++)
            {
                var el = str[i];

                trList.Add(new Transaction(el));

                var s = "";

                var lst = new List<string>();

                lst.Add(trList[i].NameDest);
                lst.Add(trList[i].NameOrig);

                lst.Sort();

                s = lst[0] + lst[1];

                if (kek.ContainsKey(s))
                    kek[s]++;
                else
                    kek[s] = 1;


                continue;
                //if (trList[i].isFraud)
                //{
                //    strFr.Add(el);
                //    continue;
                //}


                #region counters

                if (trList[i].type == "CASH_IN")
                    ++sumCashIn;

                if (trList[i].type == "CASH_IN" && trList[i].isFraud)
                    ++fraudCashIn;

                if (trList[i].type == "CASH_OUT")
                    ++sumCashOut;

                if (trList[i].type == "CASH_OUT" && trList[i].isFraud)
                    ++fraudCashOut;

                if (trList[i].type == "DEBIT")
                    ++sumDebit;

                if (trList[i].type == "DEBIT" && trList[i].isFraud)
                    ++fraudDebits;

                if (trList[i].type == "PAYMENT")
                    ++sumPayment;

                if (trList[i].type == "PAYMENT" && trList[i].isFraud)
                    ++fraudPayments;

                if (trList[i].type == "TRANSFER")
                    ++sumTransfer;

                if (trList[i].type == "TRANSFER" && trList[i].isFraud)
                    ++fraudTransfer;

                if (trList[i].isFraud)
                    ++sumFraud;

                if (trList[i].isFlaggedFraud)
                    ++sumFlaggedFraud;

                #endregion


                var sender = trList[i].NameOrig;
                var receiver = trList[i].NameDest;

                if (receiver.Contains("M"))
                {
                    ++sumM;

                    if (merchantsDict.ContainsKey(receiver))
                        merchantsDict[receiver]++;
                    else
                        merchantsDict.Add(receiver, 0);

                    continue;
                }

                clientsIdList.Add(sender);
                clientsIdList.Add(receiver);

                ProgressWriting(i, strCount);
            }

            var slis = new List<string>();

            foreach (var el in kek)
            {
                var s = el.Key + " " + el.Value;
                slis.Add(s);
            }

            File.WriteAllLines("pairs.txt", slis);
            //return;
            clientsIdList = clientsIdList.Distinct().ToList();

            //clientsIdList.Sort();

            File.WriteAllLines("Clients.txt", clientsIdList);

            Console.WriteLine();
            Console.WriteLine("Creating client-objects base:");

            var clientStringClassDict = new Dictionary<string, Client>();

            for (int i = 0; i < clientsIdList.Count; i++)
            {
                var el = clientsIdList[i];
                var tmpClient = new Client(el);

                clientsGraph.Add(tmpClient, new List<Client>());

                clientStringClassDict[el] = tmpClient;

                ProgressWriting(i, clientsIdList.Count);
            }

            Console.WriteLine();
            Console.WriteLine("Fill graph:");

            for (var i = 0; i < strCount; i++)
            {
                var tr = trList[i];

                if (tr.NameDest.Contains("M"))
                    continue;
                    
                var sender = clientStringClassDict[tr.NameOrig];
                var receiver = clientStringClassDict[tr.NameDest];

                sender.AddToSender(tr);
                receiver.AddToReceiver(tr);

                clientsGraph[sender].Add(receiver);
                clientsGraph[receiver].Add(sender);

                ProgressWriting(i, strCount);
            }


            foreach (var pair in clientsGraph)
            {
                pair.Key.MaxPath = DFS(pair.Key, pair.Value, clientsGraph, pair.Key.MaxPath);
            }

            var tmp = clientsGraph.Keys.ToList();

            tmp = tmp.OrderBy(c => -c.MaxPath).ToList();

            var tmpstr = new List<string>();

            foreach (var el in tmp)
            {
                tmpstr.Add(el.ToString());
            }

            File.WriteAllLines("path.txt", tmpstr);

            Console.WriteLine();
            //HistBuilder(clientsDict);

            Console.WriteLine();

            Console.WriteLine($"Transactions:     {str.Count}");
            Console.WriteLine($"Uniq clients:     {clientsDict.Count}");
            Console.WriteLine();
            Console.WriteLine($"CASH-IN:          {sumCashIn}");
            Console.WriteLine($"CASH-OUT:         {sumCashOut}");
            Console.WriteLine($"DEBIT:            {sumDebit}");
            Console.WriteLine($"PAYMENT:          {sumPayment}");
            Console.WriteLine($"TRANSFER:         {sumTransfer}");
            Console.WriteLine();
            Console.WriteLine($"Merchants exist:  {sumM}");
            Console.WriteLine($"Uniq merchants :  {merchantsDict.Count}");
            Console.WriteLine();
            Console.WriteLine($"Fraud:            {sumFraud}");
            Console.WriteLine($"Fraud cash-in:    {fraudCashIn}");
            Console.WriteLine($"Fraud cash-out:   {fraudCashOut}");
            Console.WriteLine($"Fraud debit:      {fraudDebits}");
            Console.WriteLine($"Fraud transfer:   {fraudTransfer}");
            Console.WriteLine($"Fraud payments:   {fraudPayments}");
            Console.WriteLine();
            Console.WriteLine($"Flagged Fraud:    {sumFlaggedFraud}");



            //CalcSendReceive(clientsDict);

            //Console.WriteLine("\n" + sumFraud);
            Console.ReadLine();

        }

        private static int DFS(Client client, List<Client> connectClients, Dictionary<Client, List<Client>> clientsGraph, int path)
        {
            var currId = client.Id;

            if (isVisited.Contains(currId))
                return path;

            if (connectClients == null || connectClients.Count == 0)
                return path + 1;

            isVisited.Add(currId);
            ++path;

            var lenghtList = new List<int>();

            foreach (var cl in connectClients)
            {
                cl.MaxPath = DFS(cl, clientsGraph[cl], clientsGraph, cl.MaxPath);
                lenghtList.Add(cl.MaxPath);
            }

            return path + lenghtList.Max();
        }

        private static void CalcSendReceive(Dictionary<string, TypeOfTrans> clientsDict)
        {
            var sendPath = "send.txt";
            var recievePath = "rec.txt";

            var recieveDict = from pair in clientsDict
                orderby pair.Value.receiv descending
                select pair;

            var recieveStrList = new List<string>();

            var sendDict = from pair in clientsDict
                orderby pair.Value.send descending
                select pair;

            var sendStrList = new List<string>();

            Console.WriteLine("Создание файла получателей:");
            var i = 0;
            var recCnt = recieveDict.Count();

            foreach (var pair in recieveDict)
            {
                recieveStrList.Add(pair.Key + "\t SEND: " + pair.Value.send + "\t RECIVE: " + pair.Value.receiv);
                ProgressWriting(++i, recCnt);
            }

            File.WriteAllLines(recievePath, recieveStrList);

            Console.WriteLine();

            Console.WriteLine("Создание файла отправителей:");
            i = 0;
            var sendCnt = sendDict.Count();

            foreach (var pair in sendDict)
            {
                sendStrList.Add(pair.Key + "\t SEND: " + pair.Value.send + "\t RECIVE: " + pair.Value.receiv);
                ProgressWriting(++i, sendCnt);
            }

            File.WriteAllLines(sendPath, sendStrList);

            Console.WriteLine();
        }

        private static void HistBuilder(Dictionary<string, TypeOfTrans> clientsDict)
        {
            var sendHis = new int[clientsDict.Max(c => c.Value.send) + 1];
            var recHis = new int[clientsDict.Max(c => c.Value.receiv) + 1];
            var transHis = new int[clientsDict.Max(c => c.Value.receiv + c.Value.send) + 1];

            var i = 0;

            Console.WriteLine();
            Console.WriteLine("Prepairing data for histograms...");

            foreach (var typeOfTranse in clientsDict)
            {
                sendHis[typeOfTranse.Value.send] += 1;
                recHis[typeOfTranse.Value.receiv] += 1;
                transHis[typeOfTranse.Value.receiv + typeOfTranse.Value.send] += 1;

                ProgressWriting(i, clientsDict.Count);
            }

            var sendHisPath = "sendHis.txt";
            var sendHisList = new List<string>();

            var recHisPath = "recHis.txt";
            var recHisList = new List<string>();

            var transHisPath = "transHis.txt";
            var transHisList = new List<string>();

            Console.WriteLine("");
            Console.WriteLine("Creating send histogram:");

            for (i = 0; i < sendHis.Length; i++)
            {
                sendHisList.Add($"{i}   {sendHis[i]}");
                ProgressWriting(i, sendHis.Length);
            }

            File.WriteAllLines(sendHisPath, sendHisList);

            Console.WriteLine("");
            Console.WriteLine("Creating receive histogram:");

            for (i = 0; i < recHis.Length; i++)
            {
                recHisList.Add($"{i}   {recHis[i]}");
                ProgressWriting(i, recHis.Length);
            }

            File.WriteAllLines(recHisPath, recHisList);

            Console.WriteLine("");
            Console.WriteLine("Creating transations histogram:");

            for (i = 0; i < transHis.Length; i++)
            {
                transHisList.Add($"{i}   {transHis[i]}");
                ProgressWriting(i, transHis.Length);
            }

            File.WriteAllLines(transHisPath, transHisList);
        }

        private static void ProgressWriting(int i, int full)
        {
            i++;
            var sym = "";

            var pred = i - 1;

            double predPer = (double) pred / full * 100.0;
            double percent = (double) i    / full * 100.0;

            if ((int) percent % 4 == 0)
                sym = "|";

            if ((int)percent % 4 == 1)
                sym = "/";

            if ((int)percent % 4 == 2)
                sym = "-";

            if ((int)percent % 4 == 3)
                sym = "\\";

            if ((int) predPer < (int) percent)
                Console.Write("\r{0:0}%     {1}", percent, sym);
        }

        private static void CheckFile(string p)
        {
           if (File.Exists(p))
                File.Delete(p);
        }
    }
}
