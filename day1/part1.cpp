#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

int getSum(const char* str) {
    int firstDigit = 0, lastDigit = 0;
    for (int i=0; i<strlen(str); i++) {
        if(isdigit(str[i])) {
            firstDigit = str[i] - '0';
            break;
        }
    }

    for (int i=(strlen(str) - 1); i>-1; i--) {
        if(isdigit(str[i])) {
            lastDigit = str[i] - '0';
            break;
        }
    }

    //cout << str << " " << firstDigit << lastDigit << endl;

    return firstDigit*10 + lastDigit;
}

int driver() {
    std::ifstream inputFile("input.txt"); // Open the file for reading
    if (!inputFile) {
        std::cerr << "Unable to open file";
        return 1; // Exit with error code
    }

    int sum = 0;
    std::string line;
    while (std::getline(inputFile, line)) {
        // std::cout << line << std::endl; // Print each line to the console
        sum += getSum(line.c_str());
    }

    inputFile.close(); // Close the file

    return sum;
}

int main(){
    std::cout << driver() << std::endl;
    return 0;
}