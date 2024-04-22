#include <map>
#include <stack>
#include <token.hh>
using namespace std;
#ifndef TOKENIZER_HH
#define TOKENIZER_HH
class ShuntingYard
{
    public:
    stack<Token> parse(stack<Token> tokenizedExpression);
    private:
    bool isValid(stack<Token> expressionToCheck);
    stack<Token> tokenStack;
    stack<Token> operatorStack;
    map<char, int> precedence;

};
#endif