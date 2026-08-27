#include <iostream>
#include <map>
#include <string>
using namespace std;

class SemanticAnalyzer {
private:
    map<string, string> symbolTable;

public:
    // Declare a variable
    void declareVariable(string name, string type) {
        if (symbolTable.find(name) != symbolTable.end()) {
            cout << "Semantic Error: Variable '" << name
                 << "' already declared.\n";
            return;
        }

        symbolTable[name] = type;
        cout << "Declared: " << name << " (" << type << ")\n";
    }

    // Check whether variable exists
    bool isDeclared(string name) {
        return symbolTable.find(name) != symbolTable.end();
    }

    // Get variable type
    string getType(string name) {
        if (isDeclared(name))
            return symbolTable[name];

        return "undefined";
    }

    // Check assignment
    void checkAssignment(string name, string valueType) {
        if (!isDeclared(name)) {
            cout << "Semantic Error: Variable