#include <ShuntingYard.hh>
#include <iostream>
#include <stack>
#include <string>
#include <token.hh>
using namespace std;

// Function that receives a stack of tokens to be parsed to a stack of tokens in
// postfix notation
stack<Token> ShuntingYard::parse(stack<Token> tokenizedExpression) {
  precedence['^'] = 3;
  precedence['_'] = 3;
  precedence['v'] = 3;
  precedence['*'] = 2;
  precedence['/'] = 2;
  precedence['+'] = 1;
  precedence['-'] = 1;

  if (isValid(tokenizedExpression)) {
    for (int i = 0; i < tokenizedExpression.size(); i++) {
      // If the token is a number push to the postfixStack
      if (tokenizedExpression.top().type() == TokenType::TOKEN_TYPE_NUMBER) {
        tokenStack.push(tokenizedExpression.top());
        tokenizedExpression.pop();
        // If the token is an operator, if its precedence is equal or lower than
        // the operator on the operatorStack and its read from left to right
        // move the top operator to the postfix expression stack and push the
        // new operator to the operatorStack
      } else if (tokenizedExpression.top().type() ==
                 TokenType::TOKEN_TYPE_OPERATOR) {
        if (operatorStack.size() == 0) {
          operatorStack.push(tokenizedExpression.top());
        } else if (operatorStack.top().getValue() >=
                       tokenizedExpression.top().getValue() &&
                   (tokenizedExpression.top().getValue() != '_' ||
                    tokenizedExpression.top().getValue() != '^')) {
          tokenStack.push(operatorStack.top());
          operatorStack.pop();
          operatorStack.push(tokenizedExpression.top());
        } else if (operatorStack.top().getValue() >=
                       tokenizedExpression.top().getValue() &&
                   (tokenizedExpression.top().getValue() == '_' ||
                    tokenizedExpression.top().getValue() == '^')) {
          operatorStack.push(tokenizedExpression.top());
        }
        tokenizedExpression.pop();
        // If the token is a left parenthesis push to the operatorStack
      } else if (tokenizedExpression.top().type() ==
                 TokenType::TOKEN_TYPE_LEFT_PARENTHESIS) {
        operatorStack.push(tokenizedExpression.top());
        tokenizedExpression.pop();
        // If the token is a right parenthesis move all the operators in
        // operator stack to the postfix notation stack until the top of the
        // operatorStack is a leftParenthesis, after that delete the left
        // parenthesis.
      } else if (tokenizedExpression.top().type() ==
                 TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS) {
        while (operatorStack.top().type() !=
               TokenType::TOKEN_TYPE_LEFT_PARENTHESIS) {
          tokenStack.push(operatorStack.top());
          operatorStack.pop();
        }
        operatorStack.pop();
        tokenizedExpression.pop();
      }
    }

    // If there are not tokens left, move all the operators in the operatorStack
    // to the postfix notation Stack, if there is any
    while (operatorStack.size() != 0) {
      tokenStack.push(operatorStack.top());
      operatorStack.pop();
    }
    return tokenStack;
  } else {
    return tokenStack;
  }
}

// Function that returns true if the expression is mathematicaly valid,
// otherwise returns false
// TODO: Añadir mensajes de error.
bool ShuntingYard::isValid(stack<Token> expressionToCheck) {
  for (int i = 0; i < expressionToCheck.size(); i++) {
    // If the token is the first token on the list it must be a number or a left
    // parenthesis
    if (i == 0) {
      if ((!expressionToCheck.top().isNumber()) ||
          !(expressionToCheck.top().type() ==
            TokenType::TOKEN_TYPE_LEFT_PARENTHESIS)) {
        return false;
      }
      expressionToCheck.pop();
    } else {
      Token currentToken = expressionToCheck.top();
      expressionToCheck.pop();
      // If the token is a number the next one must be an operator or a right
      // parenthesis
      if (currentToken.type() == TokenType::TOKEN_TYPE_NUMBER &&
          (!(expressionToCheck.top().type() ==
             TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS) ||
           !(expressionToCheck.top().type() ==
             TokenType::TOKEN_TYPE_OPERATOR))) {
        return false;
      }
      // If the token is an operator the next one must be a number or a left
      // parenthesis
      if (currentToken.type() == TokenType::TOKEN_TYPE_OPERATOR &&
          (!(expressionToCheck.top().type() == TokenType::TOKEN_TYPE_NUMBER) ||
           !(expressionToCheck.top().type() ==
             TokenType::TOKEN_TYPE_LEFT_PARENTHESIS))) {
        return false;
      }
      // If the token is a left parethesis the next one must be a number
      if (currentToken.type() == TokenType::TOKEN_TYPE_LEFT_PARENTHESIS &&
          !(expressionToCheck.top().type() == TokenType::TOKEN_TYPE_NUMBER)) {
        return false;
      }
      // If the token is a right parethesis the next one must be an operator
      if (currentToken.type() == TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS &&
          !(expressionToCheck.top().type() == TokenType::TOKEN_TYPE_OPERATOR)) {
        return false;
      }
    }
  }
  return true;
}