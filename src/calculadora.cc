#include <iostream>
#include <string.h>
#include <string>
#include <token.hh>
#include <tokenizer.hh>
#include <ShuntingYard.hh>
#include <PostFix.hh>

using namespace std;

int main() {
  string userExpression = "";
  do {
    cout << "Calculadora de Expresiones" << endl;
    cout << "Digite una expresión o Salir para salir del programa: " << endl;
    getline(cin, userExpression);
    if (strcasecmp(userExpression.c_str(), "salir") != 0) {
      tokenizer tokenizer;
      stack<Token> tokenizedExpression = tokenizer.tokenize(userExpression);
      ShuntingYard sY;
      PostFix pF;

      // Condition to end the calculation process if the stack of tokens was
      // invalid.
      if (!tokenizedExpression.empty()) {
        cout << "Tokenize termino exitosamente" << endl;
      }
      stack<Token> postFixExpression = sY.parse(tokenizedExpression);

      // Condition to end the calculation process if the stack of tokens was
      // invalid.
      if (!postFixExpression.empty()){
        Token resultado = pF.calculatePostFix(postFixExpression);
        if(resultado.type() == TokenType::TOKEN_TYPE_NULL){
        }
        else{
          cout << "El resultado de la expresion es: " << resultado.getNumber() << endl;
        }
      }
      cout << " " << endl;
    }
  } while (strcasecmp(userExpression.c_str(), "salir") != 0);
  return 0;
}
