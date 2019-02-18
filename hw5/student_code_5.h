///////////////////////////////////////////////////////////////////////////////
// You need to
//    1. Read Problem 2 in homework assignment #5.
//    2. Implement function GetStudentName.
//    3. Implement function FindMaxProfit.
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

// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name
   your_name.assign("Katherine Steiner");
}


//you can use one of the following signatures

//int FindMaxProfit (const std::vector<int>& north, const std::vector<int>& west)
//or
//int FindMaxProfit (std::vector<int> north, std::vector<int> west)

int FindMaxProfit (const std::vector<int>& north, const std::vector<int>& west)
{
  std::vector<int> PN;
  std::vector<int> PW;
  std::vector<int> PL;
  PN.push_back(north[0]);
  PW.push_back(west[0]);
  PL.push_back(0);
  if (north.size() > 1) {
    for (int i = 0; i < north.size()-1; i++) {
      PN.push_back(north[i+1] + std::max(PN[i], PL[i]));
      PW.push_back(west[i+1] + std::max(PW[i], PL[i]));
      PL.push_back(std::max(PN[i], PW[i]));
    }
  }

  return std::max(PN.back(), PW.back());
 }
