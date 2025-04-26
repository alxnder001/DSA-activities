#include <iostream>
using namespace std;

char stack[20];
int top = -1;
string stackOutput = "";

void push(char value) {
    stack[++top] = value;
    stackOutput += value;
}

char pop() {
    char value = stack[top--];
    stackOutput = "";
    for (int i = 0; i <= top; i++) {
        stackOutput += stack[i];
    }
    return value;
}

char peek() {
    return stack[top];
}

int checkLevel(char op) {
    if (op == '+' || op == '-') return 2;
    else if (op == '*' || op == '/') return 1;
    else return 3;
}

void convertToPostfix(string input) {
    string output = "";

    cout << "| Input | Stack  | Output |" << endl;
    cout << "|-------------------------|" << endl;

    for (int i = 0; i < input.length(); i++) {
        char current = input[i];

        if (isdigit(input[i])) {
            output += input[i];
        } else {
            if (top == -1) {
                push(input[i]);
            } else {
                if (input[i] == '(' || peek() == '(') {
                    push(input[i]);
                } else if (input[i] == ')') {
                    while (peek() != '(') {
                        output += pop();
                    }
                    pop();
                } else {
                    while (top != -1 && checkLevel(peek()) <= checkLevel(input[i])) {
                        output += pop();
                    }
                    push(input[i]);
                }
            }
        }

        cout << "|   " << input[i] << "   | "
             << stackOutput;

        for (int j = stackOutput.length(); j < 6; j++) cout << " ";

        cout << "|  " << output;

        for (int j = output.length(); j < 6; j++) cout << " ";

        cout << "|" << endl;
        cout << "|-------------------------|" << endl;
    }

    while (top != -1) {
        output += pop();

        cout << "|     " << " | "
             << stackOutput;

        for (int j = stackOutput.length(); j < 6; j++) cout << " ";

        cout << "|  " << output;

        for (int j = output.length(); j < 6; j++) cout << " ";

        cout << "|" << endl;
        cout << "|-------------------------|" << endl;
    }

    cout << "Final Postfix Expression: " << output << endl << endl;
}

int main() {
    string inputs [] = {
        "(2+3)-5*4/5",
        "(5+5)*(8-2)",
        "5+5+3*4-7",
        "(5+6)*2+1",
        "(5+6)*(2+1)"
    };

    for (int i = 0; i < 5; i++) {
        cout << "Test Case " << i+1 << ": " << inputs[i] << endl;
        top = -1;
        stackOutput = "";
        convertToPostfix(inputs[i]);
    }

    return 0;
}
