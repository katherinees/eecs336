#include <string>
#include <vector>
#include <set>
#include <map>

int ProblemA (std::vector<int> X)
{
  std::set<int> P;
  std::set<int>::iterator it;
  int k = 1;
  for (int i = 0; i < X.size(); i++) {
    it = P.find(X[i]);

    if (it == P.end()) {
      P.insert(X[i]);
    } else {
      k++;
      P.clear();
      P.insert(X[i]);
    }
  }

   return k;
}

int ProblemB (std::vector<int> X)
{
  int answer = 0;
  std::map<int, int> dup;
  for (int x : X) {
    dup[x]++;
    if (dup[x] > answer) {
      answer = dup[x];
    }
  }

  // std::map<int,int>::iterator it;
  // it = dup.upper_bound(dup.begin());


  for (auto p : dup) {
    std::cout << p.first << ' ' << p.second << std::endl;
  }

   // ... your code ...
   return answer;
   // return it->second; /* your answer */
}

int main() {
  std::vector<int> x;
  x.push_back(1);
  x.push_back(2);
  x.push_back(1);
  x.push_back(1);
  int answer = ProblemB(x);
  std::cout << answer;
  std::map<int,int> k;


}
