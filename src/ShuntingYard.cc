#include <ShuntingYard.hh>
#include <iostream>
#include <stack>
#include <string>
#include <token.hh>
using namespace std;

// Function that receives a stack of tokens to be parsed to a stack of tokens in
// postfix notation
stack<Token> ShuntingYard::parse(stack<Token> tokenizedExpression) {
  int expressionSize = tokenizedExpression.size();
  for (int i = 0; i < expressionSize; i++) {
    switch (tokenizedExpression.top().type()) {
    // If the token is a number push to the postfixStack
    case TokenType::TOKEN_TYPE_NUMBER:
      tokenStack.push(tokenizedExpression.top());
      break;
    // If the token is an operator, if its precedence is equal or lower than
    // the operator on the operatorStack and its read from left to right
    // move the top operator to the postfix expression stack and push the
    // new operator to the operatorStack
    case TokenType::TOKEN_TYPE_OPERATOR:
      if (operatorStack.size() == 0) {
        operatorStack.push(tokenizedExpression.top());
      } else {
        if (GetPrecedence(operatorStack.top().getValue()) >=
                GetPrecedence(tokenizedExpression.top().getValue()) &&
            (tokenizedExpression.top().getValue() != '_' &&
             tokenizedExpression.top().getValue() != '^')) {
          while (!operatorStack.empty() &&
                 GetPrecedence(operatorStack.top().getValue()) >=
                     GetPrecedence(tokenizedExpression.top().getValue())) {
            tokenStack.push(operatorStack.top());
            operatorStack.pop();
          }
          operatorStack.push(tokenizedExpression.top());
        } else {
          operatorStack.push(tokenizedExpression.top());
        }
      }
      break;
    // If the token is a left parenthesis push to the operatorStack
    case TokenType::TOKEN_TYPE_LEFT_PARENTHESIS:
      operatorStack.push(tokenizedExpression.top());
      break;
    // If the token is a right parenthesis move all the operators in
    // operator stack to the postfix notation stack until the top of the
    // operatorStack is a left parenthesis, after that delete the left
    // parenthesis, if a left parenthesis is not found return a empty stack.
    case TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS:
      while (operatorStack.top().type() !=
             TokenType::TOKEN_TYPE_LEFT_PARENTHESIS) {
        if (operatorStack.size() == 1 &&
            operatorStack.top().type() !=
                TokenType::TOKEN_TYPE_LEFT_PARENTHESIS) {
          cout << "ERROR: Parentesis en posición " << i + 1
               << " para parentesis " << tokenizedExpression.top().getValue()
               << ". No se ha encontrado su pareja." << endl;
          // calculadora class checks if the stack returned is not empty to
          // continue with the calculation, if a right parenthesis is not
          // found that means that the operator stack is empty therefore it
          // sends an empty stack to stop calculation.
          operatorStack.pop();
          return operatorStack;
        }
        tokenStack.push(operatorStack.top());
        operatorStack.pop();
      }
      if (GetPrecedence((operatorStack.top().getValue())) ==
          GetPrecedence((tokenizedExpression.top().getValue()))) {
        operatorStack.pop();
      } else {
        cout << "ERROR: Parentesis en posición " << i + 1 << " para parentesis "
             << tokenizedExpression.top().getValue()
             << ". No se ha encontrado su pareja." << endl;
        // Stack used only to return a empty stack as an error handler since
        // that is what calculadora uses as condition to continue.
        stack<Token> errorStack;
        return errorStack;
      }
      break;
    }
    tokenizedExpression.pop();
  }

  // If there are not tokens left, move all the operators in the operatorStack
  // to the postfix notation Stack, if there is any
  while (!operatorStack.empty()) {
    if (operatorStack.top().type() == TokenType::TOKEN_TYPE_LEFT_PARENTHESIS) {
      cout << "ERROR: Parentesis " << operatorStack.top().getValue()
           << ". Perdido, no se ha encontrado su pareja." << endl;
      // Stack used only to return a empty stack as an error handler since that
      // is what calculadora uses as condition to continue.
      stack<Token> errorStack;
      return errorStack;
    }
    tokenStack.push(operatorStack.top());
    operatorStack.pop();
  }
  return tokenStack;
}

int ShuntingYard::GetPrecedence(char token) {
  switch (token) {
  case '^':
    return 3;
    break;
  case '_':
    return 3;
    break;
  case 'v':
    return 3;
    break;
  case 'V':
    return 3;
    break;
  case '*':
    return 2;
    break;
  case '/':
    return 2;
    break;
  case '+':
    return 1;
    break;
  case '-':
    return 1;
    break;
  case '(':
    return 0;
    break;
  case ')':
    return 0;
    break;
  case '{':
    return -1;
    break;
  case '}':
    return -1;
    break;
  case '[':
    return -2;
    break;
  case ']':
    return -2;
    break;
  }
  return -4;
}

