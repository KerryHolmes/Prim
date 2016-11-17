/*------------------------------------
|
| This file runs a test to show the
| Datastrucure and design in action
|
------------------------------------*/
#include "graph.hpp"
#include "prim.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));
    //Create a network of 8 computers
    // (8 vertices)
    Graph test(8);
    for(int i = 0; i < test.numVerticies(); ++i)
    {
        for(int j = 0; j < test.numVerticies(); ++j)
        {
            if(i == j)
	    {}
            else
            {
               int weight = (std::rand() % 10) + 10;
               test.addEdge(i, j, weight);
            }
        }
    }
    
    //Show all edges
    for(int i = 0; i < test.numVerticies(); ++i)
    {
        for(int j = 0; j < test.numVerticies(); ++j)
        {
           std::cout << "edge " << i << ", " << j << " weight " << test.getWeight(i,j) << std::endl;
        }
    }
    
    int sum = 0;
    //sun all edges
    for(int i = 0; i < test.numVerticies(); ++i)
    {
        for(int j = 0; j < test.numVerticies(); ++j)
        {
            if(i == j);
            else
              sum+=test.getWeight(i,j);

        }
    }
    std::cout << "sum " << sum << std::endl;
    
    //Create an empty distance array of proper size
    int dist[test.numVerticies()];
    std::cout << "made distance" << std::endl;

    //Create an empty MST array of proper size
    int mst[test.numVerticies()] = {};
    std::cout << "made mst" << std::endl;

    //pick a starting vertex
    int vertex = 7;
    std::cout << "made start, starting prim" << std::endl;

    //Find the MST
    Prim(test, dist, mst, vertex);
    
    sum = 0;
    //This displays the mst. The left vertex is the parent of the right, and -1 indicates the start
    //vertex, which has no parent
    for(int i  = 0; i < test.numVerticies(); ++i)
    {
      std::cout << mst[i] << "<--->" << i << " weight "<< dist[i] << std::endl;
      sum+=dist[i];
    }
    std::cout << "new sum " << sum << std::endl;
    return 0;
}
