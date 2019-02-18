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
  std::vector<int> PN;
  std::vector<int> PW;
  std::vector<int> PL;
  PN.push_back(north[0]);
  PW.push_back(west[0]);
  PL.push_back(0);
  if (north.size() > 1) {
    for (int i = 0; i < north.size()-1; i++) {
      // std::cout << north[i+1] + std::max(PN[i], PL[i]) << "\n";
      PN.push_back(north[i+1] + std::max(PN[i], PL[i]));
      PW.push_back(west[i+1] + std::max(PW[i], PL[i]));
      PL.push_back(std::max(PN[i], PW[i]));
    }
  }

  return std::max(PN.back(), PW.back());
}

int main() {
  std::vector<int> n;
  n.push_back(1);
  n.push_back(95);
  n.push_back(70);
  std::vector<int> w;
  w.push_back(1);
  w.push_back(94);
  w.push_back(102);
  // std::vector<int> n;
  // n.push_back(1);
  // n.push_back(1);
  // n.push_back(1);
  // n.push_back(105);
  // n.push_back(1);
  // n.push_back(107);
  // n.push_back(104);
  // n.push_back(107);
  // n.push_back(93);
  // n.push_back(92);
  // n.push_back(113);
  //
  // std::vector<int> w;
  // w.push_back(109);
  // w.push_back(1);
  // w.push_back(111);
  // w.push_back(84);
  // w.push_back(79);
  // w.push_back(105);
  // w.push_back(1);
  // w.push_back(105);
  // w.push_back(1);
  // w.push_back(96);
  // w.push_back(1);


  std::cout << "FUCKKK\n" << FindMaxProfitTest(n,w);
}
