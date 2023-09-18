#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        exit(1);
    }
}

// Function to evaluate an expression
double evaluate(char *expression) {
    int i = 0;
    int len = strlen(expression);
    
    // Create two stacks for operands and operators
    double operandStack[len];
    char operatorStack[len];
    int operandTop = -1;
    int operatorTop = -1;
    
    while (i < len) {
        // Skip whitespace characters
        if (isspace(expression[i])) {
            i++;
            continue;
        }
        
        // If the current character is a digit or a decimal point, parse the operand
        if (isdigit(expression[i]) || (expression[i] == '.')) {
            operandTop++;
            operandStack[operandTop] = strtod(&expression[i], NULL);
            while (isdigit(expression[i]) || (expression[i] == '.')) {
                i++;
            }
        } else if (expression[i] == '(') {
            // Push opening parenthesis onto the operator stack
            operatorTop++;
            operatorStack[operatorTop] = '(';
            i++;
        } else if (expression[i] == ')') {
            // Evaluate expressions within parentheses
            while ((operatorTop >= 0) && (operatorStack[operatorTop] != '(')) {
                double b = operandStack[operandTop--];
                double a = operandStack[operandTop--];
                char op = operatorStack[operatorTop--];
                
                switch (op) {
                    case '+':
                        operandStack[++operandTop] = add(a, b);
                        break;
                    case '-':
                        operandStack[++operandTop] = subtract(a, b);
                        break;
                    case '*':
                        operandStack[++operandTop] = multiply(a, b);
                        break;
                    case '/':
                        operandStack[++operandTop] = divide(a, b);
                        break;
                }
            }
            if ((operatorTop >= 0) && (operatorStack[operatorTop] == '(')) {
                operatorTop--;  // Pop the opening parenthesis
            } else {
                printf("Error: Unbalanced parentheses\n");
                exit(1);
            }
            i++;
        } else if ((expression[i] == '+') || (expression[i] == '-') || (expression[i] == '*') || (expression[i] == '/')) {
            // Push operators onto the operator stack
            while ((operatorTop >= 0) &&
                   (operatorStack[operatorTop] != '(') &&
                   (((expression[i] == '+') || (expression[i] == '-')) &&
                    ((operatorStack[operatorTop] == '*') || (operatorStack[operatorTop] == '/')))) {
                double b = operandStack[operandTop--];
                double a = operandStack[operandTop--];
                char op = operatorStack[operatorTop--];
                
                switch (op) {
                    case '+':
                        operandStack[++operandTop] = add(a, b);
                        break;
                    case '-':
                        operandStack[++operandTop] = subtract(a, b);
                        break;
                    case '*':
                        operandStack[++operandTop] = multiply(a, b);
                        break;
                    case '/':
                        operandStack[++operandTop] = divide(a, b);
                        break;
                }
            }
            operatorTop++;
            operatorStack[operatorTop] = expression[i];
            i++;
        } else {
            printf("Error: Invalid character in expression\n");
            exit(1);
        }
    }
    
    // Evaluate any remaining operators
    while (operatorTop >= 0) {
        double b = operandStack[operandTop--];
        double a = operandStack[operandTop--];
        char op = operatorStack[operatorTop--];
        
        switch (op) {
            case '+':
                operandStack[++operandTop] = add(a, b);
                break;
            case '-':
                operandStack[++operandTop] = subtract(a, b);
                break;
            case '*':
                operandStack[++operandTop] = multiply(a, b);
                break;
            case '/':
                operandStack[++operandTop] = divide(a, b);
                break;
        }
    }
    
    // The result is left on the operand stack
    return operandStack[0];
}

int main() {
    char expression[100];
    
    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);
    
    // Remove trailing newline character from fgets
    expression[strlen(expression) - 1] = '\0';
    
    double result = evaluate(expression);
    
    printf("Result: %lf\n", result);
    
    return 0;
}
