﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using DiplomaHelp;
using GraphX.PCL.Common.Enums;
using GraphX.Controls;
using GraphX.Controls.Models;
using GraphX.PCL.Logic.Algorithms.EdgeRouting;
using GraphX.PCL.Logic.Algorithms.LayoutAlgorithms;
using Microsoft.Win32;
using QuickGraph;
using ShowcaseApp.WPF.FileSerialization;
using ShowcaseApp.WPF.Models;
using Rect = GraphX.Measure.Rect;

namespace ShowcaseApp.WPF.Pages
{
    /// <summary>
    /// Interaction logic for GeneralGraph.xaml
    /// </summary>
    public partial class GeneralGraph : UserControl
    {
        private GraphDataManager grManager;
        public GeneralGraph()
        {
            InitializeComponent();
            DataContext = this;

            grManager = new GraphDataManager("diploma\\filtData500k.csv");

            gg_findclientId.Text = "";
            var ggLogic = new LogicCoreExample();
            gg_Area.LogicCore = ggLogic;

            gg_sort.ItemsSource = Enum.GetValues(typeof(SortTypes)).Cast<SortTypes>();
            gg_sort.SelectedItem = SortTypes.MaxPath;

            gg_filter.ItemsSource = Enum.GetValues(typeof(FilterTypes)).Cast<FilterTypes>();
            gg_filter.SelectedItem = FilterTypes.All;

            gg_layalgo.SelectionChanged += gg_layalgo_SelectionChanged;
            gg_oralgo.SelectionChanged += gg_oralgo_SelectionChanged;
            gg_eralgo.SelectionChanged += gg_eralgo_SelectionChanged;

            gg_layalgo.ItemsSource = Enum.GetValues(typeof(LayoutAlgorithmTypeEnum)).Cast<LayoutAlgorithmTypeEnum>();
            gg_layalgo.SelectedItem = LayoutAlgorithmTypeEnum.LinLog;

            gg_oralgo.ItemsSource = Enum.GetValues(typeof(OverlapRemovalAlgorithmTypeEnum)).Cast<OverlapRemovalAlgorithmTypeEnum>();
            gg_oralgo.SelectedIndex = 0;

            gg_eralgo.ItemsSource = Enum.GetValues(typeof(EdgeRoutingAlgorithmTypeEnum)).Cast<EdgeRoutingAlgorithmTypeEnum>();
            gg_eralgo.SelectedItem = EdgeRoutingAlgorithmTypeEnum.SimpleER;

            gg_but_draw.Click += gg_but_randomgraph_Click;
            gg_async.Checked += gg_async_Checked;
            gg_async.Unchecked += gg_async_Checked;
            gg_Area.RelayoutFinished += gg_Area_RelayoutFinished;
            gg_Area.GenerateGraphFinished += gg_Area_GenerateGraphFinished;
            gg_Area.VertexLabelFactory = new DefaultVertexlabelFactory();
            gg_Area.SetEdgesDrag(true);

            ggLogic.DefaultEdgeRoutingAlgorithm = EdgeRoutingAlgorithmTypeEnum.SimpleER;
            ggLogic.EdgeCurvingEnabled = true;

            gg_Area.LogicCore.EnableParallelEdges = true;
            gg_Area.LogicCore.ParallelEdgeDistance = 30;

            gg_Area.ShowAllEdgesArrows();


            ZoomControl.SetViewFinderVisibility(gg_zoomctrl, Visibility.Visible);

            gg_zoomctrl.IsAnimationEnabled = true;
            gg_zoomctrl.ZoomStep = 2;

            gg_but_randomgraph_Click(null, null);

            //Loaded += GG_Loaded;
        }

        //void GG_Loaded(object sender, RoutedEventArgs e)
        //{
        //    GG_RegisterCommands();
        //}

        #region Commands

        #region GGRelayoutCommand

        private bool GGRelayoutCommandCanExecute(object sender)
        {
            return true;
        }

        private void GgRelayoutCommandExecute(object sender)
        {
            if (gg_Area.LogicCore.AsyncAlgorithmCompute)
                gg_loader.Visibility = Visibility.Visible;
            gg_Area.RelayoutGraph(true);
        }
        #endregion

        #region SaveStateCommand
        private static readonly RoutedCommand SaveStateCommand = new RoutedCommand();
        private void SaveStateCommandCanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = gg_Area.LogicCore.Graph != null && gg_Area.VertexList.Count > 0;
        }

        private void SaveStateCommandExecute(object sender, ExecutedRoutedEventArgs e)
        {
            if (gg_Area.StateStorage.ContainsState("exampleState"))
                gg_Area.StateStorage.RemoveState("exampleState");
            gg_Area.StateStorage.SaveState("exampleState", "My example state");
        }
        #endregion

        #region LoadStateCommand
        private static readonly RoutedCommand LoadStateCommand = new RoutedCommand();
        private void LoadStateCommandCanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = gg_Area.StateStorage.ContainsState("exampleState");
        }

        private void LoadStateCommandExecute(object sender, ExecutedRoutedEventArgs e)
        {
            if (gg_Area.StateStorage.ContainsState("exampleState"))
                gg_Area.StateStorage.LoadState("exampleState");
        }
        #endregion

        #region SaveLayoutCommand
        private static readonly RoutedCommand SaveLayoutCommand = new RoutedCommand();
        private void SaveLayoutCommandCanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = gg_Area.LogicCore.Graph != null && gg_Area.VertexList.Count > 0;
        }

        private void SaveLayoutCommandExecute(object sender, ExecutedRoutedEventArgs e)
        {
            var dlg = new SaveFileDialog { Filter = "All files|*.*", Title = "Select layout file name", FileName = "laytest.xml" };
            if (dlg.ShowDialog() == true)
            {
				FileServiceProviderWpf.SerializeDataToFile(dlg.FileName, gg_Area.ExtractSerializationData());
            }
        }
        #endregion

        #region LoadLayoutCommand

        private static readonly RoutedCommand LoadLayoutCommand = new RoutedCommand();
        private static void LoadLayoutCommandCanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void LoadLayoutCommandExecute(object sender, ExecutedRoutedEventArgs e)
        {
            var dlg = new OpenFileDialog { Filter = "All files|*.*", Title = "Select layout file", FileName = "laytest.xml" };
            if (dlg.ShowDialog() != true) return;
            try
            {
				gg_Area.RebuildFromSerializationData(FileServiceProviderWpf.DeserializeDataFromFile(dlg.FileName));
                gg_Area.SetVerticesDrag(true, true);
                gg_Area.UpdateAllEdges();
                gg_zoomctrl.ZoomToFill();
            }
            catch (Exception ex)
            {
                MessageBox.Show(string.Format("Failed to load layout file:\n {0}", ex));
            }
        }
        #endregion

        //void GG_RegisterCommands()
        //{
        //    CommandBindings.Add(new CommandBinding(SaveStateCommand, SaveStateCommandExecute, SaveStateCommandCanExecute));
        //    gg_saveState.Command = SaveStateCommand;
        //    CommandBindings.Add(new CommandBinding(LoadStateCommand, LoadStateCommandExecute, LoadStateCommandCanExecute));
        //    gg_loadState.Command = LoadStateCommand;

        //    CommandBindings.Add(new CommandBinding(SaveLayoutCommand, SaveLayoutCommandExecute, SaveLayoutCommandCanExecute));
        //    gg_saveLayout.Command = SaveLayoutCommand;
        //    CommandBindings.Add(new CommandBinding(LoadLayoutCommand, LoadLayoutCommandExecute, LoadLayoutCommandCanExecute));
        //    gg_loadLayout.Command = LoadLayoutCommand;

        //    gg_but_relayout.Command = new SimpleCommand(GGRelayoutCommandCanExecute, GgRelayoutCommandExecute);
        //}

        #endregion

        void gg_async_Checked(object sender, RoutedEventArgs e)
        {
            gg_Area.LogicCore.AsyncAlgorithmCompute = gg_async.IsChecked != null;
        }


        private void gg_layalgo_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var late = (LayoutAlgorithmTypeEnum)gg_layalgo.SelectedItem;
            gg_Area.LogicCore.DefaultLayoutAlgorithm = late;
            if (late == LayoutAlgorithmTypeEnum.EfficientSugiyama)
            {
                var prms = gg_Area.LogicCore.AlgorithmFactory.CreateLayoutParameters(LayoutAlgorithmTypeEnum.EfficientSugiyama) as EfficientSugiyamaLayoutParameters;
                prms.EdgeRouting = SugiyamaEdgeRoutings.Orthogonal;
                prms.LayerDistance = prms.VertexDistance = 100;
                gg_Area.LogicCore.EdgeCurvingEnabled = false;
                gg_Area.LogicCore.DefaultLayoutAlgorithmParams = prms;
                gg_eralgo.SelectedItem = EdgeRoutingAlgorithmTypeEnum.None;
            }
            else
            {
                gg_Area.LogicCore.EdgeCurvingEnabled = true;
            }
            if (late == LayoutAlgorithmTypeEnum.BoundedFR)
                gg_Area.LogicCore.DefaultLayoutAlgorithmParams
                    = gg_Area.LogicCore.AlgorithmFactory.CreateLayoutParameters(LayoutAlgorithmTypeEnum.BoundedFR);
            if (late == LayoutAlgorithmTypeEnum.FR)
                gg_Area.LogicCore.DefaultLayoutAlgorithmParams
                    = gg_Area.LogicCore.AlgorithmFactory.CreateLayoutParameters(LayoutAlgorithmTypeEnum.FR);
        }

        private void gg_useExternalLayAlgo_Checked(object sender, RoutedEventArgs e)
        {
            if (gg_useExternalLayAlgo.IsChecked == true)
            {
                var graph = gg_Area.LogicCore.Graph ?? ShowcaseHelper.GenerateDataGraph(30); // изменил руками, раньше из гуи бралось
                gg_Area.LogicCore.Graph = graph;
                AssignExternalLayoutAlgorithm(graph);
            }
            else gg_Area.LogicCore.ExternalLayoutAlgorithm = null;
        }

        private void AssignExternalLayoutAlgorithm(BidirectionalGraph<DataVertex, DataEdge> graph)
        {
            gg_Area.LogicCore.ExternalLayoutAlgorithm = gg_Area.LogicCore.AlgorithmFactory.CreateLayoutAlgorithm(LayoutAlgorithmTypeEnum.ISOM, graph);
        }

        private void gg_oralgo_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var core = gg_Area.LogicCore;
            core.DefaultOverlapRemovalAlgorithm = (OverlapRemovalAlgorithmTypeEnum)gg_oralgo.SelectedItem;
            if (core.DefaultOverlapRemovalAlgorithm == OverlapRemovalAlgorithmTypeEnum.FSA || core.DefaultOverlapRemovalAlgorithm == OverlapRemovalAlgorithmTypeEnum.OneWayFSA)
            {
                core.DefaultOverlapRemovalAlgorithmParams.HorizontalGap = 30;
                core.DefaultOverlapRemovalAlgorithmParams.VerticalGap = 30;
            }
        }

        private void gg_useExternalORAlgo_Checked(object sender, RoutedEventArgs e)
        {
            gg_Area.LogicCore.ExternalOverlapRemovalAlgorithm = gg_useExternalORAlgo.IsChecked == true ? gg_Area.LogicCore.AlgorithmFactory.CreateOverlapRemovalAlgorithm(OverlapRemovalAlgorithmTypeEnum.FSA, null) : null;
        }

        private void gg_eralgo_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            gg_Area.LogicCore.DefaultEdgeRoutingAlgorithm = (EdgeRoutingAlgorithmTypeEnum)gg_eralgo.SelectedItem;
            if ((EdgeRoutingAlgorithmTypeEnum) gg_eralgo.SelectedItem == EdgeRoutingAlgorithmTypeEnum.Bundling)
            {
                BundleEdgeRoutingParameters prm = new BundleEdgeRoutingParameters();
                gg_Area.LogicCore.DefaultEdgeRoutingAlgorithmParams = prm;
                prm.Iterations = 200;
                prm.SpringConstant = 5;
                prm.Threshold = .1f;
                gg_Area.LogicCore.EdgeCurvingEnabled = true;
            }else 
                gg_Area.LogicCore.EdgeCurvingEnabled = false;
        }

        private void gg_useExternalERAlgo_Checked(object sender, RoutedEventArgs e)
        {
            if (gg_useExternalERAlgo.IsChecked == true)
            {
                var graph = gg_Area.LogicCore.Graph ?? ShowcaseHelper.GenerateDataGraph(30); // изменил руками, бралось из гуи
                gg_Area.LogicCore.Graph = graph;
                gg_Area.GetLogicCore<LogicCoreExample>().ExternalEdgeRoutingAlgorithm = gg_Area.LogicCore.AlgorithmFactory.CreateEdgeRoutingAlgorithm(EdgeRoutingAlgorithmTypeEnum.SimpleER, new Rect(gg_Area.DesiredSize.ToGraphX()), graph, null, null);
            }
            else gg_Area.GetLogicCore<LogicCoreExample>().ExternalEdgeRoutingAlgorithm = null;
        }

        void gg_Area_RelayoutFinished(object sender, EventArgs e)
        {
            if (gg_Area.LogicCore.AsyncAlgorithmCompute)
                gg_loader.Visibility = Visibility.Collapsed;
            gg_zoomctrl.ZoomToFill();
            gg_zoomctrl.Mode = ZoomControlModes.Custom;
        }

        /// <summary>
        /// Use this event in case we have chosen async computation
        /// </summary>
        void gg_Area_GenerateGraphFinished(object sender, EventArgs e)
        {
            if(!gg_Area.EdgesList.Any())
                gg_Area.GenerateAllEdges();
            if (gg_Area.LogicCore.AsyncAlgorithmCompute)
                gg_loader.Visibility = Visibility.Collapsed;

            gg_zoomctrl.ZoomToFill();
            gg_zoomctrl.Mode = ZoomControlModes.Custom;
        }

        private void gg_but_randomgraph_Click(object sendr, RoutedEventArgs e)
        {
            gg_Area.ClearLayout();
            //var mult = 25;
            //GraphExample graph;
            //switch (gg_Area.LogicCore.DefaultLayoutAlgorithm)
            //{
            //    case LayoutAlgorithmTypeEnum.LinLog:
            //        mult = 45;
            //        graph = ShowcaseHelper.GenerateDataGraph(Convert.ToInt32(gg_vertexCount.Text), true, mult);
            //        break;
            //    case LayoutAlgorithmTypeEnum.EfficientSugiyama:
            //    case LayoutAlgorithmTypeEnum.Sugiyama:
            //        graph = ShowcaseHelper.GenerateDataGraph(Convert.ToInt32(gg_vertexCount.Text), true, mult);
            //        //graph = ShowcaseHelper.GenerateSugiDataGraph();
            //        break;
            //    default:
            //        graph = ShowcaseHelper.GenerateDataGraph(Convert.ToInt32(gg_vertexCount.Text), true, mult);
            //        break;
            //}
            ////add self loop
            //graph.AddEdge(new DataEdge(graph.Vertices.First(), graph.Vertices.First()));

            //Lets make new data graph instance
            var graph = new GraphExample();
            //Now we need to create edges and vertices to fill data graph
            //This edges and vertices will represent graph structure and connections
            //Lets make some vertices

            var findingClient = gg_findclientId.Text;

            if (grManager.IsFilterChanged)
            {
                grManager.FilterByCriteria((FilterTypes)gg_filter.SelectedIndex);
                grManager.IsFilterChanged = false;
            }

            if (grManager.IsSortingChanged)
            {
                grManager.SortByCriteria((SortTypes) gg_sort.SelectedIndex);
                grManager.IsSortingChanged = false;
            }

            var rootCl = grManager.CurrWorkingList[grManager.CurrentRootClientInd];

            gg_clientDescription.Text = $"ID: {rootCl.Id}, Receives: {rootCl.Receiver.Count}, Sends: {rootCl.Sender.Count}, MaxPath: {rootCl.MaxPath}";

            if (findingClient != "")
            {
                findingClient = findingClient.ToUpper();

                if (grManager.ClientsIdList.Contains(findingClient))
                    rootCl = grManager.ClientStringClassDict[findingClient];
                else
                    MessageBox.Show("No such client");
            }


            //foreach (var el in tmp)
            //{
            //    if (el.IsFraud)
            //    {
            //        rootCl = el;
            //        break;
            //    }
            //}

            var rootClList = grManager.ClientsGraph[rootCl];

            var rootVert = new DataVertex(rootCl.Id) { ImageId = rootCl.IsFraud ? 4 : 1};
            graph.AddVertex(rootVert);


            //var tmpVert = new DataVertex(rootClList[0].Id);
            //graph.AddVertex(tmpVert);

            //var tmpEdge = new DataEdge(rootVert, tmpVert) { Text = "Tuda\n" +
            //                                                       "dfgdfg\n" +
            //                                                       "dfgdfgd\n" +
            //                                                       "dfgdfgdf\n" +
            //                                                       "gdfgd\n" };
            //var tmpEdge3 = new DataEdge(rootVert, tmpVert) { Text = "Tuda" };
            //var tmpEdge4 = new DataEdge(rootVert, tmpVert) { Text = "Tuda" };
            //var tmpEdge2 = new DataEdge(tmpVert, rootVert) { Text = "Suda" };

            //graph.AddEdge(tmpEdge);
            //graph.AddEdge(tmpEdge2);
            //graph.AddEdge(tmpEdge3);
            //graph.AddEdge(tmpEdge4);

            grManager.IsVisited.Clear();

            graph = BFSGraphCreating(rootCl, rootVert, rootClList, grManager.ClientsGraph, graph, 0, 3);

            //Now lets make some edges that will connect our vertices
            //get the indexed list of graph vertices we have already added

            //Then create two edges optionaly defining Text property to show who are connected

            //assign graph again as we need to update Graph param inside and i have no independent examples
            if (gg_Area.LogicCore.ExternalLayoutAlgorithm != null)
                AssignExternalLayoutAlgorithm(graph);

            if (gg_Area.LogicCore.AsyncAlgorithmCompute)
                gg_loader.Visibility = Visibility.Visible;

            //supplied graph will be automaticaly be assigned to GraphArea::LogicCore.Graph property
            gg_Area.GenerateGraph(graph);

            gg_Area.ShowAllEdgesLabels(true);

            gg_currIdText.Text = "Curr Id in list " + grManager.CurrentRootClientInd;

            foreach (var item in gg_Area.VertexList)
                HighlightBehaviour.SetIsHighlightEnabled(item.Value, true);
            foreach (var item in gg_Area.EdgesList)
                HighlightBehaviour.SetIsHighlightEnabled(item.Value, true);
        }

        private GraphExample BFSGraphCreating(Client client, DataVertex clVert, List<Client> clientList, Dictionary<Client, List<Client>> clientsGraph, GraphExample dataGraph, int currDist, int limit)
        {
            var currId = client.Id;

            if (currDist == limit)
                return dataGraph;

            if (grManager.IsVisited.Contains(currId))
                return dataGraph;

            if (clientList == null || clientList.Count == 0)
                return dataGraph;

            grManager.IsVisited.Add(currId);

            foreach (var cl in clientList)
            {
                if (grManager.IsVisited.Contains(cl.Id)) //отсутствовало это условие, поэтому строился граф a1->a2->a1
                    continue;

                var clConnVert = new DataVertex(cl.Id) { ImageId = cl.IsFraud ? 2 : 0};
                if (cl.Id.Contains("M"))
                {
                    clConnVert.ImageId = 3;
                }
                dataGraph.AddVertex(clConnVert);

                // ВАЖНО!!! Поминть здесь о возможности нескольких транзакций между двумя клиентами. Переписать под файндол 

                //var ss = client.Sender.Find(tr => tr.NameDest == cl.Id);
                var rr = client.Receiver.Find(tr => tr.NameOrig == cl.Id);


                var ind = 0;

                var clEdge = new DataEdge(clVert, clConnVert);

                if (rr != null)
                {
                    clEdge.Source = clConnVert;
                    clEdge.Target = clVert;
                    ind = grManager.StringTrDict[cl.Id + currId];

                }
                else
                {
                    ind = grManager.StringTrDict[currId + cl.Id];
                }

                clEdge.Transaction = grManager.TransactionsList[ind];
                clEdge.Text = ind.ToString();

                dataGraph.AddEdge(clEdge);

                dataGraph = BFSGraphCreating(cl, clConnVert, clientsGraph[cl], clientsGraph, dataGraph, ++currDist, limit);
            }

            return dataGraph;
        }

        private void gg_nextbtn_Click(object sender, RoutedEventArgs e)
        {
            grManager.CurrentRootClientInd++;

            if (grManager.CurrentRootClientInd == grManager.CurrWorkingList.Count)
                grManager.CurrentRootClientInd = 0;

            gg_but_randomgraph_Click(null, null);
        }

        private void gg_prevbtn_Click(object sender, RoutedEventArgs e)
        {
            grManager.CurrentRootClientInd--;

            if (grManager.CurrentRootClientInd == -1)
                grManager.CurrentRootClientInd = grManager.CurrWorkingList.Count - 1;

            gg_but_randomgraph_Click(null, null);
        }

        private void gg_sort_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            grManager.IsSortingChanged = true;
            grManager.CurrentRootClientInd = 0;
        }

        private void gg_filter_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            grManager.IsFilterChanged = true;
            grManager.CurrentRootClientInd = 0;
        }

        private void gg_findTransBut_Click(object sender, RoutedEventArgs e)
        {
            var ind = 0;

            try
            {
                ind = Convert.ToInt32(gg_findTrans.Text);
            }
            catch (Exception exception)
            {
                Console.WriteLine(exception);
            }
           

            if (ind >= grManager.TransactionsList.Count || ind < 0)
            {
                gg_transDescription.Text = "No such transaction";
                return;
            }

            var tr = grManager.TransactionsList[ind];

            gg_transDescription.Text = "";
            gg_transDescription.Text += $"Index: {ind}, ";
            gg_transDescription.Text += $"Is Fraud: {tr.isFraud}, ";
            gg_transDescription.Text += $"Step: {tr.step}, ";
            gg_transDescription.Text += $"Type: {tr.type}, ";
            gg_transDescription.Text += $"Amount: {tr.amount},\n";
            gg_transDescription.Text += $"Sender: {tr.NameOrig}, ";
            gg_transDescription.Text += $"OBS: {tr.oldbalanceOrg}, ";
            gg_transDescription.Text += $"NBS: {tr.newbalanceOrg},\n";
            gg_transDescription.Text += $"Receiver: {tr.NameDest}, ";
            gg_transDescription.Text += $"OBR: {tr.oldbalanceDest}, ";
            gg_transDescription.Text += $"NBR: {tr.newbalanceDest}.";
        }

      
    }
}
