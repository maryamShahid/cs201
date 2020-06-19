#include <iostream>
#include <bits/stdc++.h>
#include "Stack.h"

using namespace std;

class AlgebraicExpression {
public:
    // It converts an infix expression exp to its equivalent prefix form.
    string infix2prefix( const string exp );
    // It evaluates a prefix expression.
    double evaluatePrefix( const string exp );

    bool isOperand(char character);
    static bool isOperator(char character);
    int getOperatorPriority(char operatorSymbol);
    string infix2Postfix(string infixExpression);
};
