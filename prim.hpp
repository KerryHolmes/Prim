/*--------------------------------------------------------
| These functions implement Prim's algorithm as perscribed
| in the textbook chapter on graph traversals. The code is
| modified to function with the modified version of the
| implemented Graph class
-------------------------------------------------------*/

#ifndef PRIM_HPP
#define PRIM_HPP

#include "graph.hpp"
#include <iostream>

//The algorithm itslef as a function
void Prim( Graph& problem, int Distance[], int MST[], int start);

//This function takes in a grpah and a distance array and then returns
//an unvisited edge with the lowest known weight
int leastWeight(Graph problem, int Distance[]);

#endif
