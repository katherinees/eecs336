///////////////////////////////////////////////////////////////////////////////
// You need to
//    1. Read Problem 1 in homework assignment #4.
//    2. Implement function GetStudentName.
//    3. Implement functions ProblemA and ProblemB.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_4.h") and results ("solution_4.dat")
//       via Canvas.
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>
#include <set>
#include <map>

//you can include standard C++ libraries here


// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name
   your_name.assign("Katherine Steiner");
}

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

  return answer;
}
