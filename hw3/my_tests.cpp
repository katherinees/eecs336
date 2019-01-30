#include <string>
#include <vector>

double FindBestAssignment (std::vector<double> a,std::vector<double> b,
                           std::vector<double> r)

{
    double max_revenue = 0;
    std::vector<double> L;
    for (int i = 0; i < b.size(); i++) {
      L.push_back(b[i]*r[i]);
    }
    std::sort(L.begin(), L.end());
    std::reverse(L.begin(), L.end());
    for (int k = 0; k < L.size(); k++) {
      std::cout << L[k] << ' ';
    }
    std::cout << '\n';
    std::sort(a.begin(), a.end());
    std::reverse(a.begin(), a.end());
    for (int k = 0; k < a.size(); k++) {
      std::cout << a[k] << ' ';
    }
    std::cout << '\n';
    for (int j = 0; j < a.size(); j++) {
      max_revenue += a[j]*L[j];
    }
    //you code goes here

    return max_revenue;
}

int main() {
  std::vector<double> a;
  a.push_back(0.35);
  std::vector<double> b;
  b.push_back(0.86);
  b.push_back(0.03);
  std::vector<double> r;
  r.push_back(2.55);
  r.push_back(2.78);
  std::cout << FindBestAssignment(a, b, r);
}
