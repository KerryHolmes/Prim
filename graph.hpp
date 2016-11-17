/* -------------------------------------------------------------------------------------------------------------------------------
|   This is my version of the implementation of an adjacency matrix found in the textbook
|   -Kerry Holmes  kjh80@zips.uakron.edu
--------------------------------------------------------------------------------------------------------------------------------*/
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <limits>
const int max = std::numeric_limits<int>::max();

class Graph{
    
    //private members
    
    //this is the adjacency matrix itself
    std::vector<std::vector<int>> matrix;
    //This vector has one slot for each node, and stores a 0 if it is unvisited, and a 1 if it was visited
    std::vector<bool> visited;
    ///These are counts for aspects of the graph
    int nEdges;
    int totalWeight;
    
    public:
    //constructor makes a new adjancency matrix with size*size elements all initialized to max 
    //max is being used as a constant for infinity 
    Graph(int size)
       : matrix(std::vector<std::vector<int>>(size, std::vector<int>(size, max))), visited(std::vector<bool>(size, false)), nEdges(0), totalWeight(0)
      {}
    
    //this destructor is trivial because I do not perform any allocations using new
    //Dynamic allocations are done through vector which memory manages itself
    ~Graph()
    {
    }
    
    //Checks if this an edge
    bool edgePresent(int edge1, int edge2)
    {
        return matrix[edge1][edge2] != max;
    }
    
    //Add a weighted edge to the graph
    void addEdge( int edge1, int edge2, int weight)
    {
        //You can't add an edge to itself
        //&You can't put in a weight outside of the graphs initial size
        if( edge1 > matrix.size() || edge2 > matrix.size() || edge1 == edge2)
        { 
            std::cout << "That edge cannot be added";
            return;
        }
        
        //Checks that the edge weight is valid
        if( weight < 0)
        {
            std::cout<<"edge weights must be positive";
            return;
        }
        
        //Check that this edge weight isn't set
        if( matrix[edge1][edge2] == matrix[edge2][edge1] && matrix[edge2][edge1] == max)
        {
           ++nEdges;
        }
    
        matrix[edge1][edge2] = weight;
        matrix[edge2][edge1] = weight;
        
    }
    
    //returns the number of verticies in the graph
   int numVerticies()
   {
       return matrix.size();
   }
   
   //returns the number of edges on the graph
   int numEdges()
   {
       return nEdges;
   }
    
   //return the first edge from the current vertex to another one
   int neighbor(int vertex){
       for(int index = 0; index < numVerticies(); ++index)
       {
           if( matrix[vertex][(index % numVerticies())] != max && edgePresent(vertex,(index % numVerticies())))
           {
               return (index % numVerticies());
           }
       }
           return max;
   }
   
    //Overload of neighbor
    //return the first edge from the current vertex to another one
    //that is not the index provided. If there isnt one it will return max
   int neighbor(int vertex, int current){
       for(int index = 0 + current; index < numVerticies(); ++index)
       {
           if( matrix[vertex][(index % numVerticies())] != max && edgePresent(vertex,(index % numVerticies())))
           {
               return (index % numVerticies());
           }
       }
       return max;
	
   }
    
   //Changes the wieght of an existing edge
   void setEdge(int edge1, int edge2, int weight)
   {
       //Checks that the edge weight is valid
        if( weight < 0)
        {
            std::cout<<"edge weights must be positive";
            return;
        }
        
       if(matrix[edge1][edge2] == max)
       {
           addEdge(edge1, edge2, weight);
           return;
       }
       
       matrix[edge1][edge2] = weight;
       matrix[edge2][edge1] = weight;
   }
   
   //removes an edge from the table
   void deleteEdge(int edge1, int edge2) 
   { 
   if (matrix[edge1][edge2] == 0 || !edgePresent(edge1, edge2)) 
    {
        std::cout << "Edge does not exist";
        return;
    }
    
    matrix[edge1][edge2] = max;
    matrix[edge2][edge1] = max;
    
   }
   
   //returns the weight of the edge
   //Because the graph is undirected it only needs to be checked one way
   int getWeight(int edge1, int edge2)
   {
       return matrix[edge1][edge2];
   }
   
   //Checks to see if a vertex has been hit
   bool isVisited(int vertex)
   {
       return visited[vertex];
   }
   
   //visit the vertex in the graph
   void Visit(int vertex, bool visit)
   {
       visited[vertex] = visit;
   }

};
#endif
