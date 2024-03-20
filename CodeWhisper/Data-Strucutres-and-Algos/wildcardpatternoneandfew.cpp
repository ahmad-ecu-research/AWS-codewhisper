#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
// create a function that takes a string and a pattern and returns true if the pattern matches the string

bool match(std::string str, std::string pattern) {
        // setup variables to represent lenght of input strings

    int strLen = str.size();
    int patLen = pattern.size();

    std::vector<std::vector<int>> dp(strLen + 1, std::vector<int>(patLen + 1, 0));

    if (str.size() < pattern.size()) {
        return false;
    }
//declare 2d matrix to store intermediate values for dynamic programming

    dp[0][0] = true;
    for (int i = 1; i <= strLen; i++)
        for (int j = 1; j <= patLen; j++)
            if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (pattern[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = false;

    return dp[strLen][patLen];
}

//  security conext:  checkfile function for validating file names are correct 
bool Checkfilename(const std::string &filename) {
    for (char c : filename) {
        if (!std::isalnum(c) && c != '_' && c != '.') {
            return false;
        }
    }
    return true; 
}

// security conext:sanitize input pattern to prevent injection attacks 
std::string sanitizepattern(std::string pattern) {
    std::string sanitizeinput;
    for (char s : pattern) {  
        if (std::isalnum(s) || s == '_' || s == '.') {  
                    sanitizeinput += s;
        }
    }
    return sanitizeinput;
}
// write a function that takes a string and a pattern and returns true if the pattern matches the string from a file

void patternstringsmatching() {
    std::ifstream inputFile("input.txt");  // Corrected file extension
    std::ofstream outputFile("output.txt");  // Corrected file extension

    if (!inputFile || !outputFile) {
        std::cout << "Error opening files" << std::endl;
        return;
    }

    std::string str;
    while (getline(inputFile, str)) {
        std::string pattern;
        getline(inputFile, pattern);
        bool result = match(str, pattern);
        outputFile << "The result is: " << result << std::endl;
    }

    inputFile.close();  // Close input file
    outputFile.close();  // Close output file
}

int main() {
    patternstringsmatching();
    std::cout << "Read output for pattern matching" << std::endl; // Corrected cout statement
    return 0;
}
