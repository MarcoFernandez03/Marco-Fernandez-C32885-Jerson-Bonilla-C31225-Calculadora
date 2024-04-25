#include <string>
#include <stack>
#include <token.hh>
using namespace std;
#ifndef TOKENIZER_HH
#define TOKENIZER_HH
class tokenizer
{
    public:
    stack<Token> tokenize(string userExpression);
};
#endif