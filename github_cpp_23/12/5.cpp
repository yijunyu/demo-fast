

#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <cstdint>
#include <limits>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>

using namespace std;

class WeightedUndirectedGraph{
private:
    
    uint32_t nVertex;

    
    uint32_t nEdges;

    
    vector<vector<double>> adjacencyMatrix;

public:
    WeightedUndirectedGraph();

    
    WeightedUndirectedGraph(uint32_t nVertex, vector<vector<int>> orderedPairs);

    
    WeightedUndirectedGraph(const WeightedUndirectedGraph& orig);

    
    virtual ~WeightedUndirectedGraph();

    
    vector<vector<double>> createMinimumSpanningTree();

    
    bool isOnMinimumSpanningTree(uint32_t lineToCheck, uint32_t columnToCheck, vector<vector<double>> minimumSpanningTree);

    
    double costOfMinimumSpanningTree();

    
    double findSmallestEdge(vector<double> vertex, vector<bool> minimumSpanningTreeSet);
};

WeightedUndirectedGraph::WeightedUndirectedGraph(){
    nVertex = 0;
    nEdges = 0;
}

WeightedUndirectedGraph::WeightedUndirectedGraph(uint32_t nVertex, vector<vector<int>> orderedPairs){
    adjacencyMatrix.resize(nVertex);
    this->nVertex = nVertex;
    nEdges = 0;
    for(uint32_t i = 0; i < nVertex; i++)
        adjacencyMatrix[i].resize(nVertex);

    for(uint32_t i = 0; i < nVertex; i++){
        for(uint32_t j = 0; j < nVertex; j++){
            if(i != j)
                adjacencyMatrix[i][j] = sqrt(
                    pow((orderedPairs[i][0] - orderedPairs[j][0]), 2) +
                    pow((orderedPairs[i][1] - orderedPairs[j][1]), 2)
                );
            else
                adjacencyMatrix[i][j] = 0;
            nEdges++;
        }
    }
}

WeightedUndirectedGraph::WeightedUndirectedGraph(const WeightedUndirectedGraph& orig){
}

WeightedUndirectedGraph::~WeightedUndirectedGraph(){
}

vector<vector<double>> WeightedUndirectedGraph::createMinimumSpanningTree(){
    vector<vector<double>> auxAdjacencyMatrix(nVertex), minimumSpanningTree(nVertex);
    vector<bool> visitedVertex(nVertex);
    double smallestEdge = numeric_limits<double>::max();
    uint32_t auxNEdges = nEdges, auxI = 0, auxJ = 0;

    for(uint32_t i = 0; i < nVertex; i++){
        auxAdjacencyMatrix[i].resize(nVertex);
        minimumSpanningTree[i].resize(nVertex);
        visitedVertex[i] = false;
    }

    copy(adjacencyMatrix.begin(), adjacencyMatrix.end(), auxAdjacencyMatrix.begin());

    while(auxNEdges > 0){
        for(uint32_t i = 0; i < nVertex; i++){
            for(uint32_t j = 0; j < nVertex; j++){
                if(auxAdjacencyMatrix[i][j] <= smallestEdge && auxAdjacencyMatrix[i][j] > 0){
                    smallestEdge = auxAdjacencyMatrix[i][j];
                    auxI = i;
                    auxJ = j;
                }
            }
        }
        if(!isOnMinimumSpanningTree(auxI, auxJ, minimumSpanningTree)){
            minimumSpanningTree[auxI][auxJ] = smallestEdge;
            minimumSpanningTree[auxJ][auxI] = smallestEdge;
        }
        auxAdjacencyMatrix[auxI][auxJ] = 0;
        auxAdjacencyMatrix[auxJ][auxI] = 0;

        smallestEdge = numeric_limits<double>::max();
        auxNEdges--;
    }

    return minimumSpanningTree;
}

bool WeightedUndirectedGraph::isOnMinimumSpanningTree(uint32_t lineToCheck, uint32_t columnToCheck, vector<vector<double>> minimumSpanningTree){
    bool lineOnTreeFlag = false, columnOnTreeFlag = false;
    for(uint32_t i = 0; i < nVertex && !lineOnTreeFlag; i++)
        if(minimumSpanningTree[lineToCheck][i] > 0)
            if(i != columnToCheck)
                lineOnTreeFlag = true;


    for(uint32_t i = 0; i < nVertex && !columnOnTreeFlag; i++)
        if(minimumSpanningTree[columnToCheck][i] > 0)
            if(i != lineToCheck)
                columnOnTreeFlag = true;

    return lineOnTreeFlag & columnOnTreeFlag;
}

double WeightedUndirectedGraph::costOfMinimumSpanningTree(){
    vector<double> parent(nVertex);
    vector<double> vertex(nVertex);
    vector<bool> minimumSpanningTreeSet(nVertex);

    for (uint32_t i = 0; i < nVertex; i++){
       vertex[i] = numeric_limits<double>::max();
       minimumSpanningTreeSet[i] = false;
    }

    vertex[0] = 0;
    parent[0] = -1;

    for (uint32_t i = 0; i < nVertex-1; i++){
       double smallestEdge = findSmallestEdge(vertex, minimumSpanningTreeSet);
       minimumSpanningTreeSet[smallestEdge] = true;

       for (uint32_t j = 0; j < nVertex; j++)
         if (adjacencyMatrix[smallestEdge][j] && minimumSpanningTreeSet[j] == false && adjacencyMatrix[smallestEdge][j] <  vertex[j]){
            parent[j]  = smallestEdge;
            vertex[j] = adjacencyMatrix[smallestEdge][j];
        }
    }

    double cost = 0;
    for (uint32_t i = 1; i < nVertex; i++)
       cost += adjacencyMatrix[i][parent[i]];
    return cost;
    
}

double WeightedUndirectedGraph::findSmallestEdge(vector<double> vertex, vector<bool> minimumSpanningTreeSet){
   double smallestEdge = numeric_limits<double>::max(), smallestEdgeIndex;

   for (uint32_t i = 0; i < nVertex; i++)
     if (minimumSpanningTreeSet[i] == false && vertex[i] < smallestEdge){
         smallestEdge = vertex[i];
         smallestEdgeIndex = i;
     }
   return smallestEdgeIndex;
}

int main(){
    uint32_t nVertex;
    bool failFlag = false;
    vector<vector<int>> pairs;
    WeightedUndirectedGraph graph;
    cin >> nVertex;
    if(cin){
        while(!cin.eof()){
            pairs.resize(nVertex);
            for(uint32_t i = 0; i < nVertex; i++)
                pairs[i].resize(nVertex);
            for (uint32_t i = 0; i < nVertex; i++){
                cin >> pairs[i][0];
                if(!cin){
                    failFlag = true;
                    break;
                }
                cin >> pairs[i][1];
                if(!cin){
                    failFlag = true;
                    break;
                }
            }
            if(failFlag)
                break;
            graph = WeightedUndirectedGraph(nVertex, pairs);
            cout << fixed << setprecision(2) << graph.costOfMinimumSpanningTree() << endl;
            for(uint32_t i = 0; i < nVertex; i++)
                pairs[i].clear();
            pairs.clear();
            cin >> nVertex;
            if(!cin)
                break;
        }
    }
    return 0;
}
