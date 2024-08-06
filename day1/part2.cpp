#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <map>

using namespace std;

// Declare and initialize the map in the global scope
std::map<std::string, int> digits{
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"0", 0}, {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}
};

int getSum(const std::string& str) {
    int firstDigit = -1, lastDigit = -1;

    cout << str << endl;

    std::string key;
    
    key = "";
    for (int i = 0; i < str.length(); ++i) {
        
        if (isdigit(str[i])) {
            firstDigit = digits[std::string(1, str[i])];
            cout << str[i] <<" "<< digits[std::string(1, str[i])] << endl;
            break;
        }
        else{
            key += str[i];
            auto it = digits.find(key);
            if (it != digits.end()) {
                cout<<key<<" "<<digits[key]<<endl;
                firstDigit = digits[key];
                break;
            }
        }
    }

    key = "";
    for (int i=(str.length() - 1); i>-1; --i) {
        
        if (isdigit(str[i])) {
            lastDigit = digits[std::string(1, str[i])];
            cout << str[i] << " "<<digits[std::string(1, str[i])]<< endl;
            break;
        }
        else {
            key = str[i] + key;
            auto it = digits.find(key);
            if (it != digits.end()) {
                cout<<key<<" "<<digits[key]<<endl;
                lastDigit = digits[key];
                break;
            }

        }
    }

    if (firstDigit != -1 && lastDigit != -1) {
        std::cout<< firstDigit<<lastDigit<<endl;
        return firstDigit*10 + lastDigit;
    } else {
        return 0; // Return 0 if no digits are found
    }
}

int driver() {
    std::ifstream inputFile("test.txt"); // Open the file for reading
    if (!inputFile) {
        std::cerr << "Unable to open file";
        return 1; // Exit with error code
    }

    int sum = 0;
    std::string line;
    while (std::getline(inputFile, line)) {
        sum += getSum(line);
    }

    inputFile.close(); // Close the file

    return sum;
}

int main() {
    int result = driver();
    std::cout << result << std::endl;
    return 0;
}
