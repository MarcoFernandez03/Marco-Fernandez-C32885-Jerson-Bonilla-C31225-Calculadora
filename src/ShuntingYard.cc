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
  precedence['('] = 0;
  if (isValid(tokenizedExpression)) {
    int expressionSize = tokenizedExpression.size();
    for (int i = 0; i < expressionSize; i++) {
      // If the token is a number push to the postfixStack
      if (tokenizedExpression.top().type() == TokenType::TOKEN_TYPE_NUMBER) {
        tokenStack.push(tokenizedExpression.top());
        // If the token is an operator, if its precedence is equal or lower than
        // the operator on the operatorStack and its read from left to right
        // move the top operator to the postfix expression stack and push the
        // new operator to the operatorStack
      } else if (tokenizedExpression.top().type() ==
                 TokenType::TOKEN_TYPE_OPERATOR) {
        if (operatorStack.size() == 0) {
          operatorStack.push(tokenizedExpression.top());
        } else {
          if (precedence.at(operatorStack.top().getValue()) >=
                  precedence.at(tokenizedExpression.top().getValue()) &&
              (tokenizedExpression.top().getValue() != '_' &&
               tokenizedExpression.top().getValue() != '^')) {
            while (!operatorStack.empty() && precedence.at(operatorStack.top().getValue()) >=
                   precedence.at(tokenizedExpression.top().getValue())) {
              tokenStack.push(operatorStack.top());
              operatorStack.pop();
            }
            operatorStack.push(tokenizedExpression.top());
          } else {
            operatorStack.push(tokenizedExpression.top());
          }
        }

        // If the token is a left parenthesis push to the operatorStack
      } else if (tokenizedExpression.top().type() ==
                 TokenType::TOKEN_TYPE_LEFT_PARENTHESIS) {
        operatorStack.push(tokenizedExpression.top());

        // If the token is a right parenthesis move all the operators in
        // operator stack to the postfix notation stack until the top of the
        // operatorStack is a left parenthesis, after that delete the left
        // parenthesis, if a left parenthesis is not found return a empty stack.
      } else if (tokenizedExpression.top().type() ==
                 TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS) {
        while (operatorStack.top().type() !=
               TokenType::TOKEN_TYPE_LEFT_PARENTHESIS) {
          if (operatorStack.size() == 0) {
            cout << "ERROR: Parentesis en posición " << i + 1
                 << ". No se ha encontrado su pareja." << endl;
            // calculadora class checks if the stack returned is not empty to
            // continue with the calculation, if a right parenthesis is not
            // found that means that the operator stack is empty therefore it
            // sends an empty stack to stop calculation.
            return operatorStack;
          }
          tokenStack.push(operatorStack.top());
          operatorStack.pop();
        }
        operatorStack.pop();
      }
      tokenizedExpression.pop();
    }

    // If there are not tokens left, move all the operators in the operatorStack
    // to the postfix notation Stack, if there is any
    while (operatorStack.size() != 0) {
      tokenStack.push(operatorStack.top());
      operatorStack.pop();
    }
    cout << " " << endl;
    return tokenStack;
  } else {
    return tokenStack;
  }
}

// Function that returns true if the expression is mathematicaly valid,
// otherwise returns false
// TODO: Añadir mensajes de error.
bool ShuntingYard::isValid(stack<Token> expressionToCheck) {
  // Token to be used as the previous token when reading other than the first
  // one, used for error messages.
  Token previousToken = expressionToCheck.top();
  int expressionSize = expressionToCheck.size();
  for (int i = 0; i < expressionSize - 1; i++) {
    // Token to be used as the current token when reading other than the first
    // one.
    Token currentToken = expressionToCheck.top();
    expressionToCheck.pop();
    // If the token is the first token on the list it must be a number or a left
    // parenthesis
    if (i == 0) {
      if (currentToken.type() == TokenType::TOKEN_TYPE_OPERATOR ||
          currentToken.type() ==
              TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS) {
        cout << "ERROR: Símbolo <" << expressionToCheck.top().getValue()
             << ">. La expresión debe iniciar con un numero o un parentesis."
             << endl;
        return false;
      }
    } else {
      switch (currentToken.type()) {
      // If the token is a number the next one must be an operator or a right
      // parenthesis
      case TokenType::TOKEN_TYPE_NUMBER:
        if (expressionToCheck.top().type() == TokenType::TOKEN_TYPE_NUMBER ||
            expressionToCheck.top().type() ==
                TokenType::TOKEN_TYPE_LEFT_PARENTHESIS) {
          cout << "ERROR: Símbolo <" << currentToken.getValue()
               << ">. En posición " << i + 1 << ". Expresión "
               << currentToken.getValue() << expressionToCheck.top().getValue()
               << " Se esperaba operador o parentesis cerrado." << endl;
          return false;
        }
        break;
      // If the token is an operator the next one must be a number or a left
      // parenthesis
      case TokenType::TOKEN_TYPE_OPERATOR:
        if (expressionToCheck.top().type() == TokenType::TOKEN_TYPE_OPERATOR ||
            expressionToCheck.top().type() ==
                TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS) {
          cout << "ERROR: Operador <" << currentToken.getValue()
               << ">. En posición " << i + 1 << ". Expresión "
               << previousToken.getValue() << currentToken.getValue()
               << expressionToCheck.top().getValue()
               << " Se esperaba un número o parentesis." << endl;
          return false;
        }
        break;
      // If the token is a left parethesis the next one must be a number
      case TokenType::TOKEN_TYPE_LEFT_PARENTHESIS:
        if (expressionToCheck.top().type() != TokenType::TOKEN_TYPE_NUMBER) {
          cout << "ERROR: Símbolo <" << currentToken.getValue()
               << ">. En posición " << i + 1 << ". Expresión "
               << currentToken.getValue() << expressionToCheck.top().getValue()
               << " Se esperaba un número." << endl;
          return false;
        }
        break;
      // If the token is a right parethesis the next one must be an operator
      case TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS:
        if (expressionToCheck.top().type() != TokenType::TOKEN_TYPE_OPERATOR) {
          cout << "ERROR: Símbolo <" << currentToken.getValue()
               << ">. En posición " << i + 1 << ". Expresión "
               << currentToken.getValue() << expressionToCheck.top().getValue()
               << " Se esperaba un operador." << endl;
          return false;
        }
        break;
      }
    }
    previousToken = currentToken;
  }
  // If the token is the last one it must be a number or a right
      // parenthesis.
      if (expressionToCheck.top().type() == TokenType::TOKEN_TYPE_OPERATOR ||
          expressionToCheck.top().type() ==
              TokenType::TOKEN_TYPE_LEFT_PARENTHESIS) {
        cout << "ERROR: Símbolo <" << expressionToCheck.top().getValue()
             << ">. La expresión debe terminar con un numero o un parentesis "
                "cerrado."
             << endl;
        return false;
      }
  return true;
}