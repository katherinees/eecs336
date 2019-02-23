////////////////////////////////////////////////////////////////////////////
// DO NOT EDIT THIS FILE
//

#include <string>
#include <vector>
#include "test_framework.h"
#include "student_code_6.h"

const char* inputFilename = "problem_set_6.in";
const char* outputFilename = "solution_6.dat";

const char* strNotice = "##################################\n"
                        "# Do not edit this file!\n"
                        "##################################\n";

constexpr int problem_set_id = 6;

struct ProblemN6 : public TestFramework::BasicProblem
{
   std::vector<int> y;
   int M;
};

int main(int argc, char *argv[])
{
   using namespace TestFramework;
   
   static_assert (GetTestFrameworkVersion () == 5, "TestFramework version 5 is required. Please, update test_framework.h.");
   ExitIfConditionFails((argc == 1) || (argc == 2), "This program takes at most one parameter.");

   std::cout << std::endl << "Problem set #" << problem_set_id << ". ";

   ProblemSetHeader header;
   RecordAdapter<ProblemSetHeader> psAdapter(header); 
   AddDefaultProblemSetColumns(psAdapter);

   std::vector<ProblemN6> problems;
   TableAdapter<ProblemN6> prAdapter(problems);
   AddDefaultProblemColumns (prAdapter);
 
   AddColumn<ProblemN6>(prAdapter, "y", &ProblemN6::y);
   AddColumn<ProblemN6>(prAdapter, "M", &ProblemN6::M, 0);
        
   BasicYamlParser parser(dynamic_cast<ITable*>(&psAdapter), dynamic_cast<ITable*>(&prAdapter));
   parser.ParseFile(inputFilename, true);

   GetStudentName(header.student_name);

   PreprocessProblemSet(problem_set_id, problems, header);

   bool isDebugMode = (argc == 2);

   if (!isDebugMode)
   {
      for (int i = 0; i < header.problem_count; i++)
      {
         ProblemN6& theProblem = problems[i];
         theProblem.student_answer = FindMonotonePrediction (theProblem.y, theProblem.M);
      }

      ProcessResults(problems, header);

      TableAdapter<ProblemN6> prOutAdapter(problems);
      AddDefaultProblemColumnsForOutput(prOutAdapter);

      WriteTableToFile(outputFilename, &prOutAdapter, &psAdapter, false, strNotice);
      std::cout << "Don't forget to submit your source code and file '" << outputFilename << "' via Canvas.";
      std::cout << std::endl << std::endl;
   }
   else
   {
      int problemToSolve = atoi(argv[1]);

      ExitIfConditionFails(problemToSolve != 0,
         "Invalid parameter. Please, specify the number of the problem you want to solve. The number of the first problem is 1.");

      std::cout << "Solving problem #" << problemToSolve << "." << std::endl;

      ExitIfConditionFails(problemToSolve <= header.problem_count, "The problem you specified does not exist.");
      ProblemN6& theProblem = problems[problemToSolve - 1];
      theProblem.student_answer = FindMonotonePrediction (theProblem.y, theProblem.M);

      if (problemToSolve <= header.test_problems)
      {      
            std::cout << "Correct answer: " << theProblem.correct_answer << "." << std::endl;
      }

      std::cout << "Your answer: " << theProblem.student_answer << "." << std::endl;
      std::cout << std::endl;
   }

   return 0;
}

