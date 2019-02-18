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
  std::vector<int> n;
  for (int k = 0; k < north.size(); k++) {
    n.push_back(north[k]);
  }
  std::vector<int> w;
  for (int i = 0; i < west.size(); i++) {
    w.push_back(west[i]);
  }
  std::vector<int> subs;
  std::vector<int> last;
  if (n[0] > w[0]) {
    subs.push_back(n[0]);
    last.push_back(0);
  } else {
    subs.push_back(w[0]);
    last.push_back(1);
  }
  if (n.size() == 1) {
    return subs.back();
  }
  if (n[0]+n[1] > w[0]+w[1]) {
    subs.push_back(n[0]+n[1]);
    last.push_back(0);
  } else {
    subs.push_back(w[0]+w[1]);
    last.push_back(1);
  }
  if (n.size() == 2) {
    return subs.back();
  }
  int alln = n[0]+n[1]+n[2];
  int allw = w[0]+w[1]+w[2];
  int nw = n[0]+w[2];
  int wn = w[0]+n[2];
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
  if (n.size() == 3) {
    return subs.back();
  }
  n.push_back(0);
  w.push_back(0);
  for (int i = 3; i < n.size()-1; i++) {
    int swap;
    int swapPrep = last[i-2];
    if (swapPrep == 0) {
      swap = subs[i-2]+w[i]+w[i+1];
      swapPrep = 1;
    } else {
      swap = subs[i-2]+n[i]+n[i+1];
      swapPrep = 0;
    }
    int keep;
    int keepPrep = last[i-1];
    if (keepPrep == 0) {
      keep = subs[i-1]+n[i]+n[i+1];
      keepPrep = 0;
    } else {
      keep = subs[i-1]+w[i]+w[i+1];
      keepPrep = 1;
    }
    int undo;
    int undoPrep = last[i-3];
    if (undoPrep == 0) {
      undo = subs[i-3]+n[i-2]+n[i-1]+n[i]+n[i+1];
      undoPrep = 0;
    } else {
      undo = subs[i-3]+w[i-2]+w[i-1]+w[i]+w[i+1];
      undoPrep = 1;
    }
    std::cout << "i = " << i << "\nswap = " << swap << "\nkeep = " << keep << "\nundo = " << undo << "\n";
    if (swap > keep and swap > undo) {
      if (swapPrep == 0) {
        subs.push_back(swap - n[i+1]);
      } else {
        subs.push_back(swap - w[i+1]);
      }
      last.push_back(swapPrep);
    } else if (keep > swap and keep > undo) {
      if (keepPrep == 0) {
        subs.push_back(keep - n[i+1]);
      } else {
        subs.push_back(keep - w[i+1]);
      }
      last.push_back(keepPrep);
    } else {
      if (undoPrep == 0) {
        subs.push_back(undo - n[i+1]);
      } else {
        subs.push_back(undo - w[i+1]);
      }
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
