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
  int start_index = 0;
  for (int m = 1; m <= M; m ++) {
    for (int i = start_index; i < y.size(); i++) {
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
    // for (int j = 0; j < y.size(); j++) {
    //   std::cout << x[j] << " ";
    // }
    int attempt = ComputeCost(y, x);
    // std::cout << "-- " << attempt << "\nFUCK\n";
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

    // std::cout << "\nSAVE IS " << save << "\n";

    for (int l = 0; l < save; l++) {
      x[l] = keep[l];
    }

    // for (int j = 0; j < y.size(); j++) {
    //   std::cout << x[j] << " ";
    // }
    attempt = ComputeCost(y, x);
    // std::cout << "-- " << attempt << "\nFUCK\n";
    best = std::min(best, attempt);

    start_index = save;
  }
  // for (int j = 0; j < y.size(); j++) {
  //   std::cout << x[j] << ' ';
  // }
  return best;
}
