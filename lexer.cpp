#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isKeyword(string word)
{
    string keywords[] = {
        "int", "float", "char", "if", "else",
        "while", "for", "return"
    };

    for (string k : keywords)
    {
        if (word == k)
            return true;
    }

    return false;
}

int main()
{
    string input;

    cout << "Enter a line of code: ";
    getline(cin, input);

    for (int i = 0; i < input.length(); i++)
    {
        // Skip spaces
        if (isspace(input[i]))
            continue;

        // Identifier or Keyword
        if (isalpha(input[i]))
        {
            string word = "";

            while (i < input.length() &&
                   (isalnum(input[i]) || input[i] == '_'))
            {
                word += input[i];
                i++;
            }

            i--;

            if (isKeyword(word))
                cout << word << " -> Keyword" << endl;
            else
                cout << word << " -> Identifier" << endl;
        }

        // Number
        else if (isdigit(input[i]))
        {
            string number = "";

            while (i < input.length() && isdigit(input[i]))
            {
                number += input[i];
                i++;
            }

            i--;

            cout << number << " -> Number" << endl;
        }

        // Operator
        else if (input[i] == '+' || input[i] == '-' ||
                 input[i] == '*' || input[i] == '/' ||
                 input[i] == '=')
        {
            cout << input[i] << " -> Operator" << endl;
        }

        // Symbol
        else if (input[i] == ';' || input[i] == ',' ||
                 input[i] == '(' || input[i] == ')' ||
                 input[i] == '{' || input[i] == '}')
        {
            cout << input[i] << " -> Symbol" << endl;
        }

        // Unknown character
        else
        {
            cout << input[i] << " -> Unknown" << endl;
        }
    }

    return 0;
}