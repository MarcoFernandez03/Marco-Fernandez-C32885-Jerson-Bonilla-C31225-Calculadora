#include <token.hh>
using namespace std;

Token::Token(TokenType type, char value):
tokenType(type),
value(value)
{
    if (type == TokenType::TOKEN_TYPE_NUMBER) {
    numberValue = value;
    }
}

TokenType Token::type(){
    return tokenType;
}

char Token::getValue(){
    return value;
}

double Token::getNumber(){
    return numberValue;
}

bool Token::isNumber(){
    if(isdigit(value)){
        return true;
    }
    return false;
}

bool Token::isOperator(){
    if(!isdigit(value)){
        return true;
    }
    return false;
}
