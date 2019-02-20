using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DiplomaHelp
{
    class Client
    {
        public string Id;
        public List<Transaction> Sender; // транзакция, в которой отправитель
        public List<Transaction> Receiver; //транзакция, в которой получатель
        public bool IsFraud = false;
        public int MaxPath;
        public Client(string str)
        {
            Id = str;
            MaxPath = 0;
            Sender = new List<Transaction>();
            Receiver = new List<Transaction>();
        }

        public void AddToSender(Transaction tr)
        {
            Sender.Add(tr);
        }

        public void AddToReceiver(Transaction tr)
        {
            Receiver.Add(tr);
        }

        public override string ToString()
        {
            return Id + $" - s:{Sender.Count}; r:{Receiver.Count}; m:{MaxPath}";
        }
    }
}
