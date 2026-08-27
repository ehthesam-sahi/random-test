#include <iostream>
#include <string>
using namespace std;

class Parser {
    string input;
    int pos = 0;

public:
    Parser(string str) {
        input = str;
    }

    void parse() {
        expression();

        if (pos == input.length()) {
            cout << "Parsing Successful!" << endl;
        } else {
            cout << "Parsing Error!" << endl;
        }
    }

    void expression() {
        term();

        while (pos < input.length() && input[pos] == '+') {
            pos++;
            term();
        }
    }

    void term() {
        factor();

        while (pos < input.length() && input[pos] == '*') {
            pos++;
            factor();
        }
    }

    void factor() {
        if (pos < input.length() && isdigit(input[pos])) {
            cout << "Found number: " << input[pos] << endl;
            pos++;
        } else {
            cout << "Invalid factor!" << endl;
        }
    }
};

int main() {
    string input = "3+5*2";

    Parser parser(input);
    parser.parse();

    return 0;
}