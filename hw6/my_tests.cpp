#include <string>
#include <vector>
//you can include standard C++ libraries here
#include <queue>
#include <array>

int ComputeCost (std::vector<int> y, int x[]) {
  int cost = 0;
  for (int k = 0; k < y.size(); k++) {
    cost += (y[k]-x[k])*(y[k]-x[k]);
  }
  return cost;
}

int FindMonotonePrediction (const std::vector<int>& y, int M)
{
  int s = y.size();
  int x[s];

  for (int k = 0; k < y.size(); k++) {
    x[k] = 0;
  }

  int best = M*M*y.size();

  for (int m = 0; m <= M; m++) {
    int keep[s];
    for (int k = 0; k < s; k++) {
      keep[k] = x[k];
    }
    int so_far = M*M*y.size();
    int save = 0;
    for (int i = y.size(); i >= 0; i--) {
      x[i] = m;
      int maybe = ComputeCost(y, x);
      if (maybe < so_far) {
        so_far = maybe;
        save = i;
      }
    }

    for (int j = 0; j < save; j ++) {
      x[j] = keep[j];
    }

    int attempt = ComputeCost(y, x);
    best = std::min(best, attempt);
  }
  return best;
}

int main() {
  std::vector<int> y;
  y.push_back(0);
  y.push_back(2);
  y.push_back(0);
  y.push_back(0);
  y.push_back(6);
  y.push_back(0);
  y.push_back(1);
  y.push_back(4);
  y.push_back(5);
  y.push_back(8);

  //
  // int test [5] = {0};
  // for (int k = 0; k < 5; k++) {
  //   std::cout << test[k] << " ";
  // }
  std::cout << FindMonotonePrediction(y, 10);
}
