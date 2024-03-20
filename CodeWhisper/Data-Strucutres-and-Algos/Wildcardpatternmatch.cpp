#include <iostream>
#include <fstream>
#include <vector>
#include <string>


// create a function that takes a string and a pattern and returns true if the pattern matches the string
bool match(std::string str, std::string pattern) {
    // setup variables to represent lenght of input strings
    int strLen = str.size();
    int patLen = pattern.size();

//declare 2d matrix to store intermediate values for dynamic programming
    std::vector<std::vector<int>> dp(strLen + 1, std::vector<int>(patLen + 1, 0));

    if (str.size() < pattern.size()) {
        return false;
    }


// initialze 2 dimensional dynamic programming matrix
TwoD[0][0]=ture;
for (int i=1;i<=strLen;i++)
    for (int j=1;j<=patLen;j++)
      if (str[i-1]==pattern[j-1] || pattern[j-1]=='?')
                    TwoD[i][j]=TwoD[i-1][j-1];
            else if (pattern[j-1]=='*')
                2d[i][j]=TwoD[i-1][j]||cd[i][j-1];
                else
                    TwoD[i][j]=false;
                    return TwoD[strLen][patLen];
                
}
// write a function that takes a string and a pattern and returns true if the pattern matches the string from a file
void patternstringsmatching ()
{
//take input from input file
ifstream inputFile ("input.text")
ofstream outputFile ("output.text")
if (inputFile.is_open())
    {
        string str;
        while (getline(inputFile, str))
        {
            string pattern;
            getline(inputFile, pattern);
            bool result = match(str, pattern);
            outputFile << "The result is: " << result << endl;
        }
        // do exception handling if files are not opened
        if (!inpuptFile || !outputFile)
        {
            cout << "Error opening files" << endl;
            return;
        }
}

                    int main() {
                        // calling function patternstringsmatching
                        patternstringsmatching();
                        couut<<" Read output for pattern matching";

                        }
                       



