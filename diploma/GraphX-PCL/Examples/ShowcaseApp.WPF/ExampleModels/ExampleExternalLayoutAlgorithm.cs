﻿using System.Collections.Generic;
using System.Threading;
using GraphX.Measure;
using GraphX.PCL.Common.Interfaces;
using GraphX.PCL.Logic.Algorithms.LayoutAlgorithms;
using QuickGraph;

/*
 External layout algorithm implementation example
 
 Also shows how to use internal algorithms inside the external one.
 
 */
namespace ShowcaseApp.WPF
{
    public class ExampleExternalLayoutAlgorithm: IExternalLayout<DataVertex, DataEdge>
    {
        public bool SupportsObjectFreeze
        {
            get { return true; }
        }

        public void ResetGraph(IEnumerable<DataVertex> vertices, IEnumerable<DataEdge> edges)
        {
            _graph = default(IMutableBidirectionalGraph<DataVertex, DataEdge>);
            _graph.AddVertexRange(vertices);
            _graph.AddEdgeRange(edges);
        }

        private IMutableBidirectionalGraph<DataVertex, DataEdge> _graph;
        public ExampleExternalLayoutAlgorithm(IMutableBidirectionalGraph<DataVertex, DataEdge> graph)
        {
            _graph = graph;
        }

        public void Compute(CancellationToken cancellationToken)
        {
            var pars = new EfficientSugiyamaLayoutParameters { LayerDistance = 200 };
            var algo = new EfficientSugiyamaLayoutAlgorithm<DataVertex, DataEdge, IMutableBidirectionalGraph<DataVertex, DataEdge>>(_graph, pars, _vertexPositions, VertexSizes);
            algo.Compute(cancellationToken);

            // now you can use = algo.VertexPositions for custom manipulations

            //set this algo calculation results 
            _vertexPositions = algo.VertexPositions;
        }

        IDictionary<DataVertex, Point> _vertexPositions = new Dictionary<DataVertex, Point>();
        public IDictionary<DataVertex, Point> VertexPositions
        {
            get { return _vertexPositions;  }
        }

        public IDictionary<DataVertex, Size> VertexSizes { get; set; }

        public bool NeedVertexSizes
        {
            get { return true; }
        }
    }
}
