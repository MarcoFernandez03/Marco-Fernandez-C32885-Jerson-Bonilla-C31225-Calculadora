#include <stack>
#include <token.hh>
using namespace std;
#ifndef POSTFIX_HH
#define POSTFIX_HH
class PostFix
{
    public:
    Token calculatePostFix(stack<Token> postFixExpression);
    private:
    double logarithm_a_to_base_b(double a, double b);
    bool operacionValida(double a, double b, char op);
    bool validExpression(stack<Token> expressionToCheck);
};
#endif