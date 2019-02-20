using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Windows;
using DiplomaHelp;
using GraphX.PCL.Common.Enums;
using GraphX.PCL.Logic.Algorithms.LayoutAlgorithms;
using GraphX.Controls;
using SimpleGraph.Models;

/* Some notes about the main objects and types in this example:
 * 
 * GraphAreaExample - our custom layout panel derived from the base GraphArea class with custom data types. Presented as object named: Area.
 * GraphExample - our custom data graph derived from BidirectionalGraph class using custom data types.
 * GXLogicCoreExample - our custom logic core that contains all logic settings and algorithms
 * DataVertex - our custom vertex data type.
 * DataEdge - our custom edge data type.
 * Zoombox - zoom control object that handles all zooming and interaction stuff. Presented as object named: zoomctrl.
 * 
 * VertexControl - visual vertex object that is responsible for vertex drawing. Can be found in Area.VertexList collection.
 * EdgeControl - visual edge object that is responsible for edge drawing. Can be found in Area.EdgesList collection.
 */

namespace SimpleGraph
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window, IDisposable
    {
        static HashSet<string> isVisited = new HashSet<string>();

        public MainWindow()
        {
            InitializeComponent();

            //Customize Zoombox a bit
            //Set minimap (overview) window to be visible by default
            ZoomControl.SetViewFinderVisibility(zoomctrl, Visibility.Visible);
            //Set Fill zooming strategy so whole graph will be always visible
            zoomctrl.ZoomToFill();

            //Lets setup GraphArea settings
            GraphAreaExample_Setup();

            gg_but_randomgraph.Click += gg_but_randomgraph_Click;
            gg_but_relayout.Click += gg_but_relayout_Click;

            Loaded += MainWindow_Loaded;
        }

        void MainWindow_Loaded(object sender, RoutedEventArgs e)
        {
            //lets create graph
            //Note that you can't create it in class constructor as there will be problems with visuals
            gg_but_randomgraph_Click(null, null);
        }

        void gg_but_relayout_Click(object sender, RoutedEventArgs e)
        {
            //This method initiates graph relayout process which involves consequnet call to all selected algorithms.
            //It behaves like GenerateGraph() method except that it doesn't create any visual object. Only update existing ones
            //using current Area.Graph data graph.
            Area.RelayoutGraph();
            zoomctrl.ZoomToFill();
        }

        void gg_but_randomgraph_Click(object sender, RoutedEventArgs e)
        {
            //Lets generate configured graph using pre-created data graph assigned to LogicCore object.
            //Optionaly we set first method param to True (True by default) so this method will automatically generate edges
            //  If you want to increase performance in cases where edges don't need to be drawn at first you can set it to False.
            //  You can also handle edge generation by calling manually Area.GenerateAllEdges() method.
            //Optionaly we set second param to True (True by default) so this method will automaticaly checks and assigns missing unique data ids
            //for edges and vertices in _dataGraph.
            //Note! Area.Graph property will be replaced by supplied _dataGraph object (if any).
            Area.GenerateGraph(true, true);

            /* 
             * After graph generation is finished you can apply some additional settings for newly created visual vertex and edge controls
             * (VertexControl and EdgeControl classes).
             * 
             */

            //This method sets the dash style for edges. It is applied to all edges in Area.EdgesList. You can also set dash property for
            //each edge individually using EdgeControl.DashStyle property.
            //For ex.: Area.EdgesList[0].DashStyle = GraphX.EdgeDashStyle.Dash;
            Area.SetEdgesDashStyle(EdgeDashStyle.Solid);
            //This method sets edges arrows visibility. It is also applied to all edges in Area.EdgesList. You can also set property for
            //each edge individually using property, for ex: Area.EdgesList[0].ShowArrows = true;
            Area.ShowAllEdgesArrows(true);

            //This method sets edges labels visibility. It is also applied to all edges in Area.EdgesList. You can also set property for
            //each edge individually using property, for ex: Area.EdgesList[0].ShowLabel = true;
            Area.ShowAllEdgesLabels(false);

            zoomctrl.ZoomToFill(); 
        }

        private GraphExample GraphExample_Setup()
        {
            //Lets make new data graph instance
            var dataGraph = new GraphExample();
            //Now we need to create edges and vertices to fill data graph
            //This edges and vertices will represent graph structure and connections
            //Lets make some vertices

            var str = File.ReadAllLines("diploma\\data.csv").ToList();
            var trList = new List<Transaction>();

            var clientsIdList = new List<string>();
            var clientsGraph = new Dictionary<Client, List<Client>>();

            var merchantsDict = new Dictionary<string, int>();
            var clientsDict = new Dictionary<string, TypeOfTrans>();

            str.RemoveAt(0);
            var strCount = str.Count;
            //var strCount = 10000;

            for (int i = 0; i < strCount; i++)
            {
                var el = str[i];

                trList.Add(new Transaction(el));

                var sender = trList[i].NameOrig;
                var receiver = trList[i].NameDest;

                if (receiver.Contains("M"))
                {
                    if (merchantsDict.ContainsKey(receiver))
                        merchantsDict[receiver]++;
                    else
                        merchantsDict.Add(receiver, 0);

                    continue;
                }

                clientsIdList.Add(sender);
                clientsIdList.Add(receiver);
            }

            clientsIdList = clientsIdList.Distinct().ToList();

            var clientStringClassDict = new Dictionary<string, Client>();

            foreach (var el in clientsIdList)
            {
                var tmpClient = new Client(el);

                clientsGraph.Add(tmpClient, new List<Client>());

                clientStringClassDict[el] = tmpClient;
            }

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

            var rootCl = tmp[0];
            var rootClList = clientsGraph[rootCl];

            var rootVert = new DataVertex(rootCl.Id);
            dataGraph.AddVertex(rootVert);

            isVisited.Clear();
            dataGraph = BFSGraphCreating(rootCl, rootVert, rootClList, clientsGraph, dataGraph, 0, 1000);

            

            //foreach (var client in tmplist)
            //{
            //    var clientConnVert = new DataVertex(client.Id);
            //    dataGraph.AddVertex(clientConnVert);

            //    var dataEdge = new DataEdge(clienVert, clientConnVert);
            //    dataGraph.AddEdge(dataEdge);
            //}


            //for (int i = 0; i < strCount; i++)
            //{
            //    var dataVertex1 = new DataVertex(trList[i].NameOrig);
            //    var dataVertex2 = new DataVertex(trList[i].NameDest);

            //    dataGraph.AddVertex(dataVertex1);
            //    dataGraph.AddVertex(dataVertex2);

            //    var dataEdge = new DataEdge(dataVertex1, dataVertex2);
            //    dataGraph.AddEdge(dataEdge);
            //}

            //Now lets make some edges that will connect our vertices
            //get the indexed list of graph vertices we have already added
            
            //Then create two edges optionaly defining Text property to show who are connected
            

            return dataGraph;
        }

        private GraphExample BFSGraphCreating(Client client, DataVertex clVert, List<Client> clientList, Dictionary<Client, List<Client>> clientsGraph, GraphExample dataGraph, int currDist, int limit)
        {
            var currId = client.Id;

            if (currDist == limit)
                return dataGraph;

            if (isVisited.Contains(currId))
                return dataGraph;

            if (clientList == null || clientList.Count == 0)
                return dataGraph;

            isVisited.Add(currId);

            foreach (var cl in clientList)
            {
                if(isVisited.Contains(cl.Id)) //отсутствовало это условие, поэтому строился граф a1->a2->a1
                    continue;

                var clConnVert = new DataVertex(cl.Id);
                dataGraph.AddVertex(clConnVert);
            
                var clEdge = new DataEdge(clVert, clConnVert);
                dataGraph.AddEdge(clEdge);

                dataGraph = BFSGraphCreating(cl, clConnVert, clientsGraph[cl], clientsGraph, dataGraph, ++currDist, limit);
            }

            return dataGraph;
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

        private void GraphAreaExample_Setup()
        {
            //Lets create logic core and filled data graph with edges and vertices
            var logicCore = new GXLogicCoreExample() { Graph = GraphExample_Setup() };
            //This property sets layout algorithm that will be used to calculate vertices positions
            //Different algorithms uses different values and some of them uses edge Weight property.
            logicCore.DefaultLayoutAlgorithm = LayoutAlgorithmTypeEnum.LinLog;
            //Now we can set parameters for selected algorithm using AlgorithmFactory property. This property provides methods for
            //creating all available algorithms and algo parameters.
            logicCore.DefaultLayoutAlgorithmParams = logicCore.AlgorithmFactory.CreateLayoutParameters(LayoutAlgorithmTypeEnum.KK);
            //Unfortunately to change algo parameters you need to specify params type which is different for every algorithm.
            ((KKLayoutParameters)logicCore.DefaultLayoutAlgorithmParams).MaxIterations = 100;

            //This property sets vertex overlap removal algorithm.
            //Such algorithms help to arrange vertices in the layout so no one overlaps each other.
            logicCore.DefaultOverlapRemovalAlgorithm = OverlapRemovalAlgorithmTypeEnum.FSA;
            //Default parameters are created automaticaly when new default algorithm is set and previous params were NULL
            logicCore.DefaultOverlapRemovalAlgorithmParams.HorizontalGap = 50;
            logicCore.DefaultOverlapRemovalAlgorithmParams.VerticalGap = 50;

            //This property sets edge routing algorithm that is used to build route paths according to algorithm logic.
            //For ex., SimpleER algorithm will try to set edge paths around vertices so no edge will intersect any vertex.
            //Bundling algorithm will try to tie different edges that follows same direction to a single channel making complex graphs more appealing.
            logicCore.DefaultEdgeRoutingAlgorithm = EdgeRoutingAlgorithmTypeEnum.Bundling;

            //This property sets async algorithms computation so methods like: Area.RelayoutGraph() and Area.GenerateGraph()
            //will run async with the UI thread. Completion of the specified methods can be catched by corresponding events:
            //Area.RelayoutFinished and Area.GenerateGraphFinished.
            logicCore.AsyncAlgorithmCompute = false;

            //Finally assign logic core to GraphArea object
            Area.LogicCore = logicCore;
        }

        public void Dispose()
        {
            //If you plan dynamicaly create and destroy GraphArea it is wise to use Dispose() method
            //that ensures that all potential memory-holding objects will be released.
            Area.Dispose();
        }
    }
}
