/*----------------------------------------------------------
| These functions implement Prim's algorithm as perscribed
| in the textbook chapter on graph traversals. The code is
| modified to function with the modified version of the
| implemented Graph class
----------------------------------------------------------*/
#include "prim.hpp"

int leastWeight(Graph problem, int Distance[] )
{
   int vertex = 0;
   
   for(int i = 0; i < problem.numVerticies(); ++i)
   {
     if(!problem.isVisited(i))
       {
         vertex = i;

         break;
       }
   }

   for(int i = 0; i < problem.numVerticies(); ++i)
   {
     if((!problem.isVisited(i)) && (Distance[i] <  Distance[vertex]))
       {
         vertex = i;
 
       }
   }
  
   return vertex;
}

void Prim( Graph& problem, int Distance[], int MST[], int start)
{
   //At the beiginning every distance is set to be infinite, which has been 
   //represented as max which because it is an illegal value for distance
   for(int i = 0; i < problem.numVerticies(); ++i)
   {
      Distance[i] = max;
   }
   //The starting vertex has no distance to itself
   Distance[start] = 0;
	 MST[start] = -1;

    for(int i=0; i < problem.numVerticies(); ++i)
    {
        int v = leastWeight(problem, Distance); //Find the next node

        problem.Visit(v, true);
       
       //If the node cannot be reached the tree cannot be connected, terminate
        if(Distance[v] == max)
        {
	         std::cout << "failed " << i;
            return;
        }
       //Update the distances
	
        for(int j = 0, w = problem.neighbor(v); j < problem.numVerticies(); w = problem.neighbor(v, j), ++j )
        {
            if(Distance[w] > problem.getWeight(v,w) && !problem.isVisited(w))
            {
                Distance[w] = problem.getWeight(v, w);
                MST[w] = v;
            }
        }
	  }
}
