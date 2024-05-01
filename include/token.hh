#ifndef TOKEN_HH
#define TOKEN_HH



enum class TokenType {
TOKEN_TYPE_UNKNOWN,
TOKEN_TYPE_NUMBER,
TOKEN_TYPE_OPERATOR,
TOKEN_TYPE_RIGHT_PARENTHESIS,
TOKEN_TYPE_LEFT_PARENTHESIS,
TOKEN_TYPE_END
};

#include <string>
using namespace std;
// El enum TokenType...

class Token {
public:
Token(TokenType type, char value);
Token(TokenType type, double numberValue);
TokenType type();
char getValue();
double getNumber();
bool isNumber();
bool isOperator();

private:
TokenType tokenType;
char value;
double numberValue;
};

#endif