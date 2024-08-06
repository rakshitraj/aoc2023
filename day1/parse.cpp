#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;

int trebuchet(const std::string &line) {
    std::vector<int> nums = {};

    for (int i=0; i<line.length(); i++){
        std::string word = "";

        // for (auto el: nums){
        //     cout << el << " ";
        // }
        // cout << '\n';

        for (int j=i; j<=i+5 && j<line.length(); j++){
            
            char ch = line[j];

            if(word == "" && isdigit(ch)) {
                nums.push_back(int(ch) - 48);
                // i=j
                break;
            }
            else {
                word += ch;
                // cout << "word: " << word << '\n';
                if (word == "one"){
                    nums.push_back(1);
                    // i=j
                    break;
                }
                if (word == "two"){
                    nums.push_back(2);
                    // i=j
                    break;
                }
                if (word == "three"){
                    nums.push_back(3);
                    break;
                }
                if (word == "four"){
                    nums.push_back(4);
                    // i=j
                    break;
                }
                if (word == "five"){
                    nums.push_back(5);
                    // i=j
                    break;
                }
                if (word == "six"){
                    nums.push_back(6);
                    // i=j
                    break;
                }
                if (word == "seven"){
                    nums.push_back(7);
                    // i=j
                    break;
                }
                if (word == "eight"){
                    nums.push_back(8);
                    // i=j
                    break;
                }
                if (word == "nine"){
                    nums.push_back(9);
                    // i=j
                    break;
                }
                if (word == "zero"){
                    nums.push_back(0);
                    // i=j
                    break;
                }
            }
        }
    }

    // cout << "nums: [";
    // for (auto el: nums){
    //     cout << el << ", ";
    // }
    // cout << "]" << '\n';

    int number = nums[0]*10 + nums[nums.size() -1];
    return number;
}

int parser(const std::string &filepath) {
    std::ifstream inputFile(filepath);
    if (!inputFile) {
        std::cerr << "Unable to open file\n";
        return 1;
    }

    long long int sum = 0;

    std::string line;
    while (std::getline(inputFile, line)) {
        int result = trebuchet(line);
        std:cout << line << " " << result << '\n';
        sum += result;
        //std::cout << "Sum: " << sum << '\n';
    }

    std::cout << "Sum: " << sum << '\n';
    return 0;
}

int main() {
    return parser("input.txt");
}