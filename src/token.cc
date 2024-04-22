#include <token.hh>
using namespace std;

Token::Token(TokenType type, string value):
tokenType(type),
value(value)
{
    if (type == TokenType::TOKEN_TYPE_NUMBER) {
    numberValue = stod(value);
    }
}

TokenType Token::type(){
    return tokenType;
}

string Token::getValue(){
    return value;
}

double Token::getNumber(){
    return numberValue;
}

bool Token::isNumber(){
    for(int i=0; i<=value.length(); i++){
        if(isdigit(value[i])){
            return true;
        }
    }
    return false;
}

bool Token::isOperator(){
    for(int i=0; i<=value.length(); i++){
        if(!isdigit(value[i])){
            return true;
        }
    }
    return false;
}
