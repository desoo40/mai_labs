using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows;

namespace DiplomaHelp
{
    class GraphDataManager
    {
        public HashSet<string> IsVisited = new HashSet<string>();

        public List<string> StringsFile = new List<string>();
        public List<Transaction> TransactionsList = new List<Transaction>();

        public List<string> ClientsIdList = new List<string>();
        public Dictionary<string, Client> ClientStringClassDict = new Dictionary<string, Client>();

        public Dictionary<Client, List<Client>> ClientsGraph = new Dictionary<Client, List<Client>>();

        public Dictionary<string, int> MerchantsDict = new Dictionary<string, int>();
        public List<Client> CurrWorkingList = new List<Client>();
        public int CurrentRootClientInd = 0;
        public bool IsSortingChanged = false;
        public bool IsFilterChanged = false;

        public GraphDataManager(string diplomaDataCsv)
        {
            StringsFile = File.ReadAllLines(diplomaDataCsv).ToList();

            StringsFile.RemoveAt(0); // удаляется строка с описанием столбцов

            //var strCount = StringsFile.Count;
            var strCount = 10000;

            for (int i = 0; i < strCount; i++)
            {
                var el = StringsFile[i];

                TransactionsList.Add(new Transaction(el));

                var sender = TransactionsList[i].NameOrig;
                var receiver = TransactionsList[i].NameDest;

                if (receiver.Contains("M"))
                {
                    if (MerchantsDict.ContainsKey(receiver))
                        MerchantsDict[receiver]++;
                    else
                        MerchantsDict.Add(receiver, 0);

                    continue;
                }

                ClientsIdList.Add(sender);
                ClientsIdList.Add(receiver);
            }

            ClientsIdList = ClientsIdList.Distinct().ToList();

            foreach (var el in ClientsIdList)
            {
                var tmpClient = new Client(el);

                ClientsGraph.Add(tmpClient, new List<Client>());

                ClientStringClassDict[el] = tmpClient;
            }

            for (var i = 0; i < strCount; i++)
            {
                var tr = TransactionsList[i];

                if (tr.NameDest.Contains("M"))
                    continue;

                var sender = ClientStringClassDict[tr.NameOrig];
                var receiver = ClientStringClassDict[tr.NameDest];

                if (tr.isFraud)
                {
                    sender.IsFraud = true;
                    receiver.IsFraud = true;
                }

                sender.AddToSender(tr);
                receiver.AddToReceiver(tr);

                ClientsGraph[sender].Add(receiver);
                ClientsGraph[receiver].Add(sender);
            }

            foreach (var pair in ClientsGraph)
            {
                pair.Key.MaxPath = DFS(pair.Key, pair.Value, ClientsGraph, pair.Key.MaxPath);
            }

            FilterByCriteria(FilterTypes.All);
            SortByCriteria(SortTypes.MaxPath);

            MessageBox.Show("Data downloading completed");
        }

        public void SortByCriteria(SortTypes criteria)
        {
            if (criteria == SortTypes.MaxPath)
                CurrWorkingList = CurrWorkingList.OrderBy(c => -c.MaxPath).ToList();

            if (criteria == SortTypes.Receives)
                CurrWorkingList = CurrWorkingList.OrderBy(c => -c.Receiver.Count).ToList();

            if (criteria == SortTypes.Sends)
                CurrWorkingList = CurrWorkingList.OrderBy(c => -c.Sender.Count).ToList();


            var tmpstr = new List<string>();

            foreach (var el in CurrWorkingList)
            {
                tmpstr.Add(el.ToString());
            }

            File.WriteAllLines("path.txt", tmpstr);
        }

        public void FilterByCriteria(FilterTypes criteria)
        {
            if (criteria == FilterTypes.All)
                CurrWorkingList = ClientsGraph.Keys.ToList();

            if (criteria == FilterTypes.Frauds)
                CurrWorkingList = CurrWorkingList.FindAll(el => el.IsFraud);
        }

        private int DFS(Client client, List<Client> connectClients, Dictionary<Client, List<Client>> clientsGraph, int path)
        {
            var currId = client.Id;

            if (IsVisited.Contains(currId))
                return path;

            if (connectClients == null || connectClients.Count == 0)
                return path + 1;

            IsVisited.Add(currId);
            ++path;

            var lenghtList = new List<int>();

            foreach (var cl in connectClients)
            {
                cl.MaxPath = DFS(cl, clientsGraph[cl], clientsGraph, cl.MaxPath);
                lenghtList.Add(cl.MaxPath);
            }

            return path + lenghtList.Max();
        }
    }
}
