#include <iostream>
#include <optional>
#include <vector>
#include <algorithm>

std::ostream& operator<<(std::ostream& os, std::vector<std::pair<char, int>> v) {
    for (std::pair<char, int> item : v) {
        os << item.first << " : " << item.second << std::endl;
    }
    return os;
}

class FirstNRepeatingStream {
public:
    FirstNRepeatingStream(int N) : CurrentN(N) {}

    std::optional<char> next(char c) {
        bool found = false;
        for (std::pair<char, int>& CharPair : CharMap) {
            if (CharPair.first == c && !found) {
                (CharPair.second)++;
                found = true;
                break;
            }
        }
        if (!found) {
            CharMap.push_back({c, 1});
        }
        for (std::pair CharPair : CharMap) {
            if (CharPair.second <= CurrentN) {
                return CharPair.first;
            }
        }
        return std::nullopt;
    }

private:
    const int CurrentN;
    std::vector<std::pair<char, int>> CharMap;
};

int main() {
    while (true) {
        std::string command;
        std::cout << "Enter N or \"end\": ";
        std::cin >> command;
        if (command == "end") {
            break;
        }

        int N = stoi(command);
        FirstNRepeatingStream f(N);
        while (true) {
            std::string command;
            std::cout << "Enter char or \"end\": ";
            std::cin >> command;
            if (command == "end") {
                break;
            }

            char c = command[0];
            std::cout << "result: " << *(f.next(c)) << std::endl;


        }
    }

    return 0;
}
