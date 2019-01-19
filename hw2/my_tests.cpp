#include <string>
#include <vector>

int FindMaxSchedule (std::vector<std::pair<int,int>> intervals)
{
  for (int i = 0; i < intervals.size(); i++) {
    std::cout << intervals[i].first << " " << intervals[i].second << "\n";
  }
  std::vector<std::pair<int, int>> sortedIntervals;
  for (int i = 0; i < intervals.size(); i++) {
    sortedIntervals.push_back(std::make_pair(intervals[i].second, intervals[i].first));
  }
  std::sort(sortedIntervals.begin(), sortedIntervals.end());
  for (int i = 0; i < sortedIntervals.size(); i++) {
    std::cout << sortedIntervals[i].second << " " << sortedIntervals[i].first << "\n";
  }

  int result = 0;
  // int beginTime = 0;
  // while (sortedIntervals.size() != 0) {
  //   std::pair<int, int> temp = sortedIntervals.front();
  //   sortedIntervals.erase(sortedIntervals.begin());
  //   if (temp.second > beginTime) {
  //     result++;
  //     beginTime = temp.first;
  //   }
  // }

   return result;
}

int main() {
  // left: [91946,94572,14561,40233,59634,56492,12902,71846,98695,1586]
  // right: [108008,103097,27702,55709,75994,65559,19072,80626,103143,7287]
  std::vector<std::pair<int, int>> test2;

  test2.push_back(std::make_pair(44279, 61806));
  test2.push_back(std::make_pair(29414, 42160));
  test2.push_back(std::make_pair(614, 12194));
  test2.push_back(std::make_pair(23565, 48140));
  test2.push_back(std::make_pair(45652, 47212));

  std::cout << FindMaxSchedule(test2);

  // std::vector<std::pair<int, int>> test;
  // for (int i = 0; i < test2.size(); i++) {
  //   test.push_back(std::make_pair(test2[i].second, test2[i].first));
  // }
  //
  //
  //
  // for (int i = 0; i < test.size(); i++) {
  //   std::cout << test[i].second << " " << test[i].first << "\n";
  // }
  //
  //
  //
  // std::sort(test.begin(), test.end());
  //
  // for (int i = 0; i < test.size(); i++) {
  //   std::cout << test[i].second << " " << test[i].first << "\n";
  // }
  //
  // int result = 0;
  // int beginTime = 0;
  // while (test.size() != 0) {
  //   std::pair<int,int> temp = test.front();
  //   test.erase(test.begin());
  //   std::cout << "currently considering "<< temp.second << " " << temp.first << "\n";
  //   if (temp.second > beginTime) {
  //     std::cout << "we can schedule this";
  //     result++;
  //     beginTime = temp.first;
  //   }
  // }
  // std::cout << "\nAHH " << result;


}
