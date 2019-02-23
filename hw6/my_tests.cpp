#include <string>
#include <vector>
//you can include standard C++ libraries here
#include <queue>

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
  // std::cout << "\nFUCK\n";
  int best = M*M*y.size();
  for (int m = 0; m <= M; m ++) {
    for (int i = 0; i < y.size(); i++) {
      if (i != 0) {
        if (y[i] < y[i-1]) {
          x[i] = m;
        } else {
          x[i] = std::min(m, y[i]);
          x[i] = std::max(x[i], x[i-1]);
        }
      } else {
        x[i] = std::min(m, y[i]);
      }
    }
    for (int j = 0; j < y.size(); j++) {
      std::cout << x[j] << " ";
    }
    int attempt = ComputeCost(y, x);
    std::cout << "-- " << attempt << "\nFUCK\n";
    best = std::min(best, attempt);
  }
  // for (int j = 0; j < y.size(); j++) {
  //   std::cout << x[j] << ' ';
  // }
  return best;
}

int main() {
  std::vector<int> y;
  y.push_back(0);
  y.push_back(0);
  y.push_back(4);
  y.push_back(0);
  y.push_back(0);
  y.push_back(2);
  y.push_back(2);
  y.push_back(7);
  y.push_back(6);
  y.push_back(0);

  //
  // int test [5] = {0};
  // for (int k = 0; k < 5; k++) {
  //   std::cout << test[k] << " ";
  // }
  std::cout << FindMonotonePrediction(y, 10);
}
