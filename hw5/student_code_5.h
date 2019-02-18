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
  std::vector<int> subs;
  std::vector<int> last;
  if (north[0] > west[0]) {
    subs.push_back(north[0]);
    last.push_back(0);
  } else {
    subs.push_back(west[0]);
    last.push_back(1);
  }
  if (north.size() == 1) {
    return subs.back();
  }
  if (north[0]+north[1] > west[0]+west[1]) {
    subs.push_back(north[0]+north[1]);
    last.push_back(0);
  } else {
    subs.push_back(west[0]+west[1]);
    last.push_back(1);
  }
  if (north.size() == 2) {
    return subs.back();
  }
  int alln = north[0]+north[1]+north[2];
  int allw = west[0]+west[1]+west[2];
  int nw = north[0]+west[2];
  int wn = west[0]+north[2];
  if (alln > allw and alln > nw and alln > wn) {
    subs.push_back(alln);
    last.push_back(0);
  }
  if (allw > alln and allw > nw and allw > wn) {
    subs.push_back(allw);
    last.push_back(1);
  }
  if (nw > alln and nw > allw and nw > wn) {
    subs.push_back(nw);
    last.push_back(1);
  }
  if (wn > alln and wn > allw and wn > nw) {
    subs.push_back(wn);
    last.push_back(0);
  }
  if (north.size() == 3) {
    return subs.back();
  }
  // int b3 = std::max(north[0]+north[1]+north[2], west[0]+west[1]+west[2]);
  // b3 = std::max(b3, north[0]+west[2]);
  // b3 = std::max(b3, west[0]+north[2]);
  // if (north.size() == 3) {
  //   return b3;
  // }
  // subs.push_back(b3);
  for (int i = 3; i < north.size(); i++) {
    int swap;
    int swapPrep = last[i-2];
    if (swapPrep == 0) {
      swap = subs[i-2]+west[i];
      swapPrep = 1;
    } else {
      swap = subs[i-2]+north[i];
      swapPrep = 0;
    }
    int keep;
    int keepPrep = last[i-1];
    if (keepPrep == 0) {
      keep = subs[i-1]+north[i];
      keepPrep = 0;
    } else {
      keep = subs[i-1]+west[i];
      keepPrep = 1;
    }
    int undo;
    int undoPrep = last[i-3];
    if (undoPrep == 0) {
      undo = subs[i-3]+north[i-2]+north[i-1]+north[i];
      undoPrep = 0;
    } else {
      undo = subs[i-3]+west[i-2]+west[i-1]+west[i];
      undoPrep = 1;
    }
    std::cout << "i = " << i << "\nswap = " << swap << "\nkeep = " << keep << "\nundo = " << undo << "\n";
    if (swap > keep and swap > undo) {
      subs.push_back(swap);
      last.push_back(swapPrep);
    } else if (keep > swap and keep > undo) {
      subs.push_back(keep);
      last.push_back(keepPrep);
    } else {
      subs.push_back(undo);
      last.push_back(undoPrep);
    }
  }
  for (int k = 0; k < subs.size(); k++) {
    std::cout << subs[k] << ' ';
  }
  std::cout << "\n";
  for (int k = 0; k < last.size(); k++) {
    std::cout << last[k] << ' ';
  }
  std::cout << "\n";

   //your code

   return subs.back();
}
