#include <iostream>
#include <string>
#include <token.hh>
#include <tokenizer.hh>

using namespace std;
// Variables
string userExpression = "";
// TODO: agregar variables necesarias para conectar con las demas clases
//  Functions
bool hasLetters(string expression);
string toLowerCase(string expression);

int main() {
  do {
    cout << "Calculadora de Expresiones" << endl;
    cout << "Digite una expresión: " << endl;
    getline(cin, userExpression);
    if (!hasLetters(userExpression)) {
      tokenizer tokenizer;
      stack<Token> tokenizedExpression = tokenizer.tokenize(userExpression);

      // Condition to end the calculation process if the stack of tokens was
      // invalid.
      if (!tokenizedExpression.empty()) {
        cout << "Tokenize termino exitosamente" << endl;
      }

      //Puse esto nada mas para probar que se funcionaba el stack y se emitian en el orden correcto.
      while(!tokenizedExpression.empty()){
        Token w = tokenizedExpression.top();
        if(w.type() == TokenType::TOKEN_TYPE_NUMBER){
          double valor = w.getNumber();
          cout << "El valor del token es:" << valor << endl;
        }
        else{
          char valor = w.getValue();
          cout << "El valor del token es:" << valor << endl;
        }
        tokenizedExpression.pop();
      }
      cout << " " << endl;
    } else {
      userExpression = toLowerCase(userExpression);
      if (userExpression != "salida") {
        cout << "La expresion: <" << userExpression << "> no es valida" << endl;
      }
    }
  } while (userExpression != "salida");
  return 0;
}
/*
This method finds if there is any letter on the expression writen by the user
recieves a String and returns true if there is any letter on the expression,
false otherwise.
*/
bool hasLetters(string expression) {
  for (int i = 0; i < expression.length(); i++) {
    // Finds between the ASCII characters [65, 90] and [97, 122], upper case and
    // lower case respectively, it leaves ascii code 118 [v] out since its used
    // as an operator
    if ((expression[i] >= 65 && expression[i] <= 90) ||
        (expression[i] >= 97 && expression[i] <= 117) ||
        (expression[i] >= 119 && expression[i] <= 122)) {
      return true;
    }
  }
  return false;
}

/*
Function that iterates through the chars of a string changing every char to its
lower case form.
*/
string toLowerCase(string expression) {
  string loweredExpression = "";
  for (int i = 0; i < expression.length(); i++) {
    loweredExpression += tolower(expression[i]);
  }
  return loweredExpression;
}
