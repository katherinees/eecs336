///////////////////////////////////////////////////////////////////////////////
// You need to
//    1. Read Problem 2 in homework assignment #6.
//    2. Implement function GetStudentName.
//    3. Implement function FindMonotonePrediction.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_5.h") and results ("solution_5.dat")
//       via Canvas.
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>

//you can include standard C++ libraries here
#include <queue>

// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name
   your_name.assign("Katherine Steiner");
}

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
