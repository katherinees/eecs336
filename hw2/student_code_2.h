///////////////////////////////////////////////////////////////////////////////
// You need to
//    1. Read Problem 2 in Homework Assignment #2.
//    2. Implement function GetStudentName.
//    3. Implement function FindMaxSchedule.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_2.h") and results ("solution_2.dat")
//       via Canvas.
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>

//you can include standard C++ libraries here


// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name
   your_name.assign("Katherine Steiner");
}


//you can use one of the following signatures

//int FindMaxSchedule (const std::vector<std::pair<int,int>>& intervals)
//or
//int FindMaxSchedule(std::vector<std::pair<int, int>> intervals)

int FindMaxSchedule (std::vector<std::pair<int,int>> intervals)
{
  std::vector<std::pair<int, int>> sortedIntervals;
  for (int i = 0; i < intervals.size(); i++) {
    sortedIntervals.push_back(std::make_pair(intervals[i].second, intervals[i].first));
  }
  std::sort(sortedIntervals.begin(), sortedIntervals.end());
  // sortedIntervals is a vector of elements (f(j), s(j))
  // sortedIntervals is sorted in increasing order of f(j)

  int result = 0;
  int beginTime = 0;
  // while sortedIntervals isn't empty
  while (sortedIntervals.size() != 0) {
    // get the next job
    std::pair<int, int> temp = sortedIntervals.front();
    sortedIntervals.erase(sortedIntervals.begin());
    // if this job starts at or later than the last job end time
    if (temp.second >= beginTime) {
      // then schedule it and increase new beginTime appropriately.
      result++;
      beginTime = temp.first;
    }
  }

   return result;
}
