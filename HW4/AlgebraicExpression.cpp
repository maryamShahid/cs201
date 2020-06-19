#include "AlgebraicExpression.h"

using namespace std;

bool AlgebraicExpression::isOperator(char character) {
    return (!isalpha(character) && !isdigit(character));
}

bool AlgebraicExpression::isOperand(char c) {
    return isdigit(c);
}

int AlgebraicExpression::getOperatorPriority(char operatorSymbol)
{
    if(operatorSymbol == '-' || operatorSymbol == '+')
        return 1;
    else if(operatorSymbol == '*' || operatorSymbol == '/')
        return 2;
    else if(operatorSymbol == '^')
        return 3;
    return 0;
}

string AlgebraicExpression::infix2Postfix(string infixExp) {
    infixExp = '(' + infixExp + ')';
    int length = infixExp.size();

    Stack<char> st;

    string postfixExp;
    for (int i = 0; i < length; i++) {
        if(isalpha(infixExp[i]) || isdigit(infixExp[i]))
            postfixExp += infixExp[i];
        else if(infixExp[i] == '(')
            st.push('(');
        else if(infixExp[i] == ')')
        {
            while(st.getTop() != '(') {
                postfixExp += st.getTop();
                st.pop();
            }
            st.pop();
        }
        else {
            if(isOperator(st.getTop())) {
                while (getOperatorPriority(infixExp[i]) <= getOperatorPriority(st.getTop())) {
                    postfixExp += st.getTop();
                    st.pop();
                }
                st.push(infixExp[i]);
            }
        }
    }
    return postfixExp;
}

string AlgebraicExpression::infix2prefix(string exp) {
    int length = exp.size();
    reverse(exp.begin(), exp.end());

    for (int i = 0; i < length; i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
            i++;
        }
        else if (exp[i] == ')') {
            exp[i] = '(';
            i++;
        }
    }
    string prefix = infix2Postfix(exp);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

double AlgebraicExpression::evaluatePrefix(string exp) {

    Stack<double> resultStack;

    for (int i = exp.size() - 1; i >= 0; i--) {
        if (isOperand(exp[i]))
            resultStack.push(exp[i] - '0');
        else {
            double operatorOne = resultStack.getTop();
            resultStack.pop();
            double operatorTwo = resultStack.getTop();
            resultStack.pop();

            if (exp[i] == '+')
                resultStack.push(operatorOne + operatorTwo);
            else if (exp[i] == '-')
                resultStack.push(operatorOne - operatorTwo);
            else if (exp[i] == '*')
                resultStack.push(operatorOne * operatorTwo);
            else if (exp[i] == '/')
                resultStack.push(operatorOne / operatorTwo);
        }
    }
    return resultStack.getTop();
}