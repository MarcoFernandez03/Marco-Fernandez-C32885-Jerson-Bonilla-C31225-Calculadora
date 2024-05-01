#include <iostream>
#include <stack>
#include <token.hh>
#include <PostFix.hh>
#include <cmath>
using namespace std;

// Function that gets a stack of tokens expressed as PostFix and returns a double as the result 
Token PostFix::calculatePostFix(stack<Token> postFixExpression) {
    stack<Token> postFixStack;
    while(!postFixExpression.empty()){
        Token topToken = postFixExpression.top();
        postFixStack.push(topToken);
        postFixExpression.pop();
    }
    stack<double> operands;
    int contador = 0;
    if(validExpression(postFixStack)){
        while(!postFixStack.empty()){   
            Token currentToken = postFixStack.top();
            if(currentToken.isNumber()){
                operands.push(currentToken.getNumber());
            }
            else{
                double value1 = operands.top();
                operands.pop();
                double value2 = operands.top();
                operands.pop();
                if (operacionValida(value2, value1, currentToken.getValue())){
                    switch (currentToken.getValue()){
                    case '+':
                        operands.push(value2 + value1);
                        break;
                    case '-':
                        operands.push(value2 - value1);
                        break;
                    case '*':
                        operands.push(value2 * value1);
                        break;
                    case '/':
                        operands.push(value2 / value1);
                        break;
                    case '^':
                        operands.push(pow(value2,value1));
                        break;
                    case '_':
                        operands.push(logarithm_a_to_base_b(value2,value1));
                        break;
                    case 'v':
                        operands.push(pow(value1,1/value2));
                        break;    
                    default:
                        //Handle invalid tokens
                        cout << "ERROR: operador <" << currentToken.getValue()
                    << ">. En posición " << contador+1 << ". Expresión "
                    << value2 << currentToken.getValue() << value1 << endl;
                        Token resultadoNull(TokenType::TOKEN_TYPE_NULL, (double)0);
                        return resultadoNull;
                        break;
                    }
                }
                else{
                cout << "ERROR: expresion invalida <" << value2 << currentToken.getValue()
                    << value1 << ">. En posición " << contador << endl;
                    Token resultadoNull(TokenType::TOKEN_TYPE_NULL, (double)0);
                    return resultadoNull;
                }     
            }
            contador++;
            postFixStack.pop();
        }
        Token resultado(TokenType::TOKEN_TYPE_NUMBER, operands.top());
        return resultado;
    }
    else{
        cout << "ERROR: expresion invalida" << endl;
        Token resultadoNull(TokenType::TOKEN_TYPE_NULL, (double)0);
        return resultadoNull;
    }
}

//Function that calculates the logarithm of a to base b.
double PostFix::logarithm_a_to_base_b(double a, double b){
    return log2(a) / log2(b);
}

//Function that calculates the logarithm of a to base b.
bool PostFix::operacionValida(double a, double b, char op){
    switch(op){
        //if a/b and b=0, return false. 
        case '/':
        if(b == 0){
            return false;
        }
        break;

        //if a_b and b=0 or a<=0, return false.
        case '_':
        if(b == 0 || a<=0){
            return false;
        }
        break;

        //if a^b and a=0 and b=0 , return false.
        case '^':
        if(a == 0 && b==0){
            return false;
        }
        break;

        //if avb and a=0 or b<0, return false.
        case 'v':
        if(a == 0 || b<0){
            return false;
        }
        break;
    }
    return true;
}

bool PostFix::validExpression(stack<Token> expressionToCheck){
    int counter = 0;
    while(!expressionToCheck.empty()){
        if(expressionToCheck.top().isNumber()){
            counter++;
            expressionToCheck.pop();
        }
        else{
            counter = counter-2;
            counter++;
            expressionToCheck.pop();
        }
    }
    if(counter == 1){
        return true;
    
    }
    else{
        return false;
    }
}
