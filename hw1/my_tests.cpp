// copy of relevant student_code_1 :
#include <string>

int CountNUOccurrences(const std::string& message)
{
   int occurences = 0;
   int partition = 0;
   while ((partition = message.find("NU", partition)) != std::string::npos) {
     partition += 2;
     occurences += 1;
   }
   return occurences;
}

int main() {
  // Test 1: I understand strings
  std::string t1 = "I understand strings";
  std::cout << t1 << std::endl;

  // Test 2
  std::string t2 = "NU go wildcats";
  std::cout << "expect 1: " << CountNUOccurrences(t2) << std::endl;

  // Test 3
  std::string t3 = "N U go wildcats";
  std::cout << "expect 0: " << CountNUOccurrences(t3) << std::endl;

  // Test 4
  std::string t4 = "nu go wildcats";
  std::cout << "expect 0: " << CountNUOccurrences(t4) << std::endl;

  // Test 5
  std::string t5 = "NUNU";
  std::cout << "expect 2: " << CountNUOccurrences(t5) << std::endl;

  // Test 6
  std::string t6 = "Sit NU adipiscing officia in, in. Adipiscing eu quis voluptate enim reprehenderit incididunt elit in irure ut occaecat eiusmod. Labore NU NU sed. Eu culpa NU id ullamco. Labore nonproident. Nonproident.";
  std::cout << "expect 4: " << CountNUOccurrences(t6) << std::endl;

  // Test 7
  std::string t7 =  "Reprehenderit aliquaut, NU sed. Amet NU, aliquaut quis duis, NU ullamco, deserunt eu. Dolore dolor, pariatur in ad irure eu in, est NU duis elit NU. Labore labore. Amet NU minim quis nulla dolore, NU excepteur.";
  std::cout << "expect 7: " << CountNUOccurrences(t7) << std::endl;

}
