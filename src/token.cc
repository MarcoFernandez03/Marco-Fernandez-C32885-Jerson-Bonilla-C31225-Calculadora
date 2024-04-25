#include <token.hh>
using namespace std;

/*Constructor of class Token, the parameters asked for are TokenType type (number, operator) and a string value. 
If it is a number then assigns to the double "numberValue" the value turned into a double through stod function.
*/
Token::Token(TokenType type, string value) : tokenType(type), value(value) {
  if (type == TokenType::TOKEN_TYPE_NUMBER) {
    numberValue = stod(value);
  } else {
    charValue = value[0];
  }
}

//Returns the TokenType of the token.
TokenType Token::type() { return tokenType; }
//Returns the value of the token as a string.
string Token::getValue() { return value; }
//Returns the charValue of the token, whether it exists or not.
char Token::getCharValue() { return charValue; }
//Returns the double numberValue of the token, whether it exists or not.
double Token::getNumber() { return numberValue; }
//Returns true if the value is a digit at 0.
bool Token::isNumber() {
  if (isdigit(value[0])) {
    return true;
  }
  return false;
}
//Returns true if the value is not a digit at 0, thus being an operator.
bool Token::isOperator() {
  if (!isdigit(value[0])) {
    return true;
  }
  return false;
}
