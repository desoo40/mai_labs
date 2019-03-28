using System.ComponentModel;
using GraphX;
using System;
using DiplomaHelp;
using GraphX.Measure;
using GraphX.PCL.Common.Models;
using ShowcaseApp.WPF.FileSerialization;
using YAXLib;

namespace ShowcaseApp.WPF
{
    [Serializable]
    public class DataEdge : EdgeBase<DataVertex>, INotifyPropertyChanged
    {
        [YAXCustomSerializer(typeof(YAXPointArraySerializer))]
        public override Point[] RoutingPoints { get; set; }

        public DataEdge(DataVertex source, DataVertex target, double weight = 1)
			: base(source, target, weight)
		{
		}

        public DataEdge()
            : base(null, null, 1)
        {
        }

        /// <summary>
        /// Node main description (header)
        /// </summary>
        private string _text;
        public string Text { get { return _text; } set { _text = value; OnPropertyChanged("Text"); } }
        public string ToolTipText {get; set; }
        public Transaction Transaction { get; set; }

        public override string ToString()
        {
            return Text;
        }

        public event PropertyChangedEventHandler PropertyChanged;

        public void OnPropertyChanged(string name)
        {
            if (PropertyChanged != null)
                PropertyChanged.Invoke(this, new PropertyChangedEventArgs(name));
        }
    }
}
