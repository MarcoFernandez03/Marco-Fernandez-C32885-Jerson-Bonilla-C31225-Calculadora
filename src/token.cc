#include <token.hh>
using namespace std;

/*Constructor of class Token, the parameters asked for are TokenType type (number, operator) and a string value. 
If it is a number then assigns to the double "numberValue" the value turned into a double through stod function.
*/
Token::Token(TokenType type, char value) : tokenType(type), value(value) {
}

Token::Token(TokenType type, double value) : tokenType(type), value(value) {
  if (type == TokenType::TOKEN_TYPE_NUMBER) {
    numberValue = value;
    }
}

//Returns the TokenType of the token.
TokenType Token::type() { return tokenType; }

//Returns the value of the token as a char.
char Token::getValue() { return value; }

//Returns the double numberValue of the token, whether it exists or not.
double Token::getNumber() { return numberValue; }

//Returns true if tokenType is a number.
bool Token::isNumber() {
  if (tokenType == TokenType::TOKEN_TYPE_NUMBER) {
    return true;
  }
  return false;
}
//Returns true if tokenType is not a number, thus being an operator.
bool Token::isOperator() {
  if (tokenType != TokenType::TOKEN_TYPE_NUMBER) {
    return true;
  }
  return false;
}
