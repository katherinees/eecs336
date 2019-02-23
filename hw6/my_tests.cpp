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
  // std::cout << "\nFUCK\n";
  int best = M*M*y.size();
  int start_index = 0;
  for (int m = 0; m <= M; m ++) {
    std::cout << "\ngoing forwards with start " << start_index << " and m " << m << "\n";

    for (int i = start_index; i < y.size(); i++) {
      if (i != 0) {
        if (y[i] < y[i-1]) {
          x[i] = std::min(m, x[i-1]);
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

    m++;
    if (m>M) { break; }
    int save = 0;
    int b = y.size();
    int keep[b];
    for (int k = 0; k < y.size(); k++) {
      keep[k] = x[k];
    }

    int so_far = M*M*y.size();
    for (int j = y.size(); j >= 0; j--) {
      x[j] = m;
      int maybe = ComputeCost(y, x);
      if (maybe < so_far) {
        so_far = maybe;
        save = j;
      }
    }

    std::cout << "\nSAVE IS " << save << "\n";

    for (int l = 0; l < save; l++) {
      x[l] = keep[l];
    }

    for (int j = 0; j < y.size(); j++) {
      std::cout << x[j] << " ";
    }
    attempt = ComputeCost(y, x);
    std::cout << "-- " << attempt << "\nFUCK\n";
    best = std::min(best, attempt);

    start_index = save;
  }

  start_index = 0;
  for (int m = 1; m <= M; m ++) {
    std::cout << "\ngoing forwards with start " << start_index << " and m " << m << "\n";

    for (int i = start_index; i < y.size(); i++) {
      if (i != 0) {
        if (y[i] < y[i-1]) {
          x[i] = std::min(m, x[i-1]);
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

    m++;
    if (m>M) { break; }
    int save = 0;
    int b = y.size();
    int keep[b];
    for (int k = 0; k < y.size(); k++) {
      keep[k] = x[k];
    }

    int so_far = M*M*y.size();
    for (int j = y.size(); j >= 0; j--) {
      x[j] = m;
      int maybe = ComputeCost(y, x);
      if (maybe < so_far) {
        so_far = maybe;
        save = j;
      }
    }

    std::cout << "\nSAVE IS " << save << "\n";

    for (int l = 0; l < save; l++) {
      x[l] = keep[l];
    }

    for (int j = 0; j < y.size(); j++) {
      std::cout << x[j] << " ";
    }
    attempt = ComputeCost(y, x);
    std::cout << "-- " << attempt << "\nFUCK\n";
    best = std::min(best, attempt);

    start_index = save;
  }
  // for (int j = 0; j < y.size(); j++) {
  //   std::cout << x[j] << ' ';
  // }
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
