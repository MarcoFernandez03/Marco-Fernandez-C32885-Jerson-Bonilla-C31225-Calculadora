#include <token.hh>
using namespace std;

//Functions
//Function that gets a TokenType and a char and assigns the given value to numberValue if it is a number. Otherwise it assigns the given value to value if it is an operator
Token::Token(TokenType type, char value) : tokenType(type), value(value) {
  if (type == TokenType::TOKEN_TYPE_NUMBER) {
    numberValue = (double)value;
  }
  else if (type == TokenType::TOKEN_TYPE_OPERATOR) {
    value = value;
  }
}

// Function that returns the tokenType of the token
TokenType Token::type() { return tokenType; }

// Function that returns the value of the token
char Token::getValue() { return value; }

// Function that returns the numberValue of the token
double Token::getNumber() { return numberValue - '0'; }

// Function that returns true if the value is a digit and therefore a number
bool Token::isNumber() {
  if (isdigit(value)) {
    return true;
  }
  return false;
}

// Function that returns true if the value is not digit and therefore is not a number
bool Token::isOperator() {
  if (!isdigit(value)) {
    return true;
  }
  return false;
}
