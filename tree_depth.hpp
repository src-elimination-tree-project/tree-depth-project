#pragma once
#include "src/mainAlgo.h"

/** 
 * Accepts number of vertices, vector of edges and time cutoff in seconds. 
 * Returns tree depth of a graph and it's elimination ordering.
 * Calculates the best tree depth in given time or until any sensible result.
*/
std::pair<int, std::vector<int>> calculate_with_cutoff(int n, std::vector<std::pair<int, int>> edges, double seconds);

/**
 * Accepts number of vertices, vector of edges.
 * Returns tree depth of a graph and it's elimination ordering.
 * Calculates the best tree depth until the process stall and new updates unlikely.
*/
std::pair<int, std::vector<int>> calculate_until_stall(int n, std::vector<std::pair<int, int>> edges);