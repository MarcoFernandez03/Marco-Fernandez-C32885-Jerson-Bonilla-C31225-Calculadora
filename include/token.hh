#ifndef TOKEN_HH
#define TOKEN_HH

// El resto del código irá acá

#endif

enum class TokenType {
TOKEN_TYPE_UNKNOWN,
TOKEN_TYPE_NUMBER,
TOKEN_TYPE_OPERATOR,
TOKEN_TYPE_END
};

#include <string>
using namespace std;
// El enum TokenType...

class Token {
public:
Token(TokenType type, string value);
TokenType type();
string getValue();
double getNumber();
bool isNumber();
bool isOperator();

private:
TokenType tokenType;
string value;
double numberValue;
};