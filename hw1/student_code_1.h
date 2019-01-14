///////////////////////////////////////////////////////////////////////////////
// You need to
//    1. Read Problem 2 in homework assignmnet #1.
//    2. Implement function GetStudentName.
//    3. Implement function CountNUOccurrences.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code and results via Canvas.
///////////////////////////////////////////////////////////////////////////////

//you can include standard C++ libraries here

//required libraries
#include <string>

// This function should return your name.
// The name should match your name in Canvas
void GetStudentName(std::string& your_name)
{
   //replace Firstname and Lastname below with you first name and last name
   your_name.assign("Katherine Steiner");
}

//This is the function you need to implement.
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
