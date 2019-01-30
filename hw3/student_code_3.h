///////////////////////////////////////////////////////////////////////////////
// You need to
//    1. Read Problem 2 in homework assignment #3.
//    2. Implement function GetStudentName.
//    3. Implement function FindMaxSchedule.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_3.h") and results ("solution_3.dat")
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


//your goal is to implement the following function

double FindBestAssignment (std::vector<double> a,std::vector<double> b,
                           std::vector<double> r)

{
    double max_revenue = 0;
    std::vector<double> L;
    for (int i = 0; i < b.size(); i++) {
      L.push_back(b[i]*r[i]);
    }
    
    std::sort(L.begin(), L.end());
    std::reverse(L.begin(), L.end());
    std::sort(a.begin(), a.end());
    std::reverse(a.begin(), a.end());
    for (int j = 0; j < a.size(); j++) {
      max_revenue += a[j]*L[j];
    }

    return max_revenue;
}
