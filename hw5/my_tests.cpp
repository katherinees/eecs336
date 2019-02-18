#include <string>
#include <vector>
// #include "student_code_5.h"

// north: [62, 99, 60,  1,109, 77,  1,  1,116]
// west: [ 95,  1,  1, 72,106,  1,  1, 60,  1]
//          1,  0,  0,  1,  1,  1,  1,  1,
//         95,161,221,233,339,340,341,401,
//         95,
//
// N = 62
// W = 95 <
//
// NN = 161 <
// WW = 96
//
// NNN = 221 <
// WWW = 97
// NLW = 63
// WLN = 155
//
// N = 222
// W = 233 <
// L = 221
//
// N = 331
// W = 339
// L = 330
//
// N =
//
//
// swap = 327
// keep = 339
// undo = 331
//
// swap = 310
// keep = 340
// undo = 340
//
// swap = 340
// keep = 341
// undo = 341
//
// swap = 341
// keep = 401
// undo = 401
//
// swap = 457
// keep = 402
// undo = 402

// north: [ 1,  1,  1,105,  1,107,104,107, 93, 92,113]
// west: [109,  1,111, 84, 79,105,  1,105,  1, 96,  1]
//        109,110,221,305,384,
//          1,  1,  1,  1,  x,  0,  0,  0,  0,  0,  0
//                      3,  4   5,  6   7   8   9   a
int FindMaxProfitTest (const std::vector<int>& north, const std::vector<int>& west)
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

int main() {
  std::vector<int> n;
  n.push_back(1);
  n.push_back(1);
  n.push_back(1);
  n.push_back(105);
  n.push_back(1);
  n.push_back(107);
  n.push_back(104);
  n.push_back(107);
  n.push_back(93);
  n.push_back(92);
  n.push_back(113);

  std::vector<int> w;
  w.push_back(109);
  w.push_back(1);
  w.push_back(111);
  w.push_back(84);
  w.push_back(79);
  w.push_back(105);
  w.push_back(1);
  w.push_back(105);
  w.push_back(1);
  w.push_back(96);
  w.push_back(1);




  std::cout << "FUCKKK" << FindMaxProfitTest(n,w);
}
