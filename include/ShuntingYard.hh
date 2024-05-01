#include <map>
#include <stack>
#include <token.hh>
using namespace std;
#ifndef SHUNTINGYARD_HH
#define SHUNTINGYARD_HH
class ShuntingYard {
public:
  stack<Token> parse(stack<Token> tokenizedExpression);

private:
  bool isValid(stack<Token> expressionToCheck);
  stack<Token> tokenStack;
  stack<Token> operatorStack;
  int GetPrecedence(char token);
};
#endif