#pragma once
#include "tree_depth.hpp"

std::pair<int, std::vector<int>> calculate_with_cutoff(int n, std::vector<std::pair<int, int>> edges, double seconds) {
  std::vector<int> vert;
  for (auto [u, v] : edges) {
    vert.push_back(u);
    vert.push_back(v);
  }
  std::sort(begin(vert), end(vert));
  vert.erase(std::unique(begin(vert), end(vert)), end(vert));
  assert(size(vert) == n);
  for (auto& [u, v] : edges) {
    u = std::lower_bound(begin(vert), end(vert), u) - begin(vert) + 1;
    v = std::lower_bound(begin(vert), end(vert), v) - begin(vert) + 1;
  }
  std::sort(begin(edges), end(edges));
  edges.erase(std::unique(begin(edges), end(edges)), end(edges));
  BasicOneBasedGraph graph(n);
  for (auto [u, v] : edges) {
    graph.addEdge(u, v);
  }

  unsigned int seed = std::random_device()();
  Environment env(seed, seconds);
  env.found_cut = false;
  MainAlgo algo(graph, env);
  algo.main = true;
  algo.run();
  
  std::pair<int, std::vector<int>> res;
  res.first = algo.bestResult.depth;
  for (int v : algo.bestResult.ordering) {
    res.second.push_back(vert[v - 1]);
  }

  return res;
}

std::pair<int, std::vector<int>> calculate_until_stall(int n, std::vector<std::pair<int, int>> edges) {
  std::vector<int> vert;
  for (auto [u, v] : edges) {
    vert.push_back(u);
    vert.push_back(v);
  }
  std::sort(begin(vert), end(vert));
  vert.erase(std::unique(begin(vert), end(vert)), end(vert));
  assert(size(vert) == n);
  for (auto& [u, v] : edges) {
    u = std::lower_bound(begin(vert), end(vert), u) - begin(vert) + 1;
    v = std::lower_bound(begin(vert), end(vert), v) - begin(vert) + 1;
  }
  std::sort(begin(edges), end(edges));
  edges.erase(std::unique(begin(edges), end(edges)), end(edges));
  BasicOneBasedGraph graph(n);
  for (auto [u, v] : edges) {
    graph.addEdge(u, v);
  }

  unsigned int seed = std::random_device()();
  Environment env(seed, 1e9);
  env.found_cut = false;
  MainAlgo algo(graph, env);
  algo.main = true;
  algo.stop = true;
  algo.run();
  
  std::pair<int, std::vector<int>> res;
  res.first = algo.bestResult.depth;
  for (int v : algo.bestResult.ordering) {
    res.second.push_back(vert[v - 1]);
  }

  return res;
}