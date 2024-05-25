#include <iostream>
#include <vector>
#include "tree_depth.hpp"

using namespace std;

int main() {
  string trash;
  cin >> trash >> trash;
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges;
  while (m--) {
    int u, v;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }
  cout << calculate_with_cutoff(n, edges, 10).first << endl;
}