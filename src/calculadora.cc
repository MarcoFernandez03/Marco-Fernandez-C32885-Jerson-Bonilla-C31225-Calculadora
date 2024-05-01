#include <iostream>
#include <string.h>
#include <string>
#include <token.hh>
#include <tokenizer.hh>

using namespace std;

int main() {
  string userExpression = "";
  do {
    cout << "Calculadora de Expresiones" << endl;
    cout << "Digite una expresión o Salir para salir del programa: " << endl;
    getline(cin, userExpression);
    if (strcasecmp(userExpression.c_str(), "salir") != 0) {
      tokenizer tokenizer;
      // PlaceHolder cambiar a tipo correcto una vez esté implementado
      // Recieves a stack of tokens.
      int tokenizedExpression = tokenizer.tokenize(userExpression);

      // Condition to end the calculation process if the stack of tokens was
      // invalid.
      if (tokenizedExpression == 0) {
        // PlaceHolder para probar funcionalidad, cambiar una vez se implementen
        // las clases restantes
        cout << "Tokenize termino exitosamente" << endl;
        // TODO: Implementar clase ShuntingYard e implementar condición para
        // continuar con el calculo solo si el stack recibido de esta clase
        // tiene elementos.
      }
    }
  } while (strcasecmp(userExpression.c_str(), "salir") != 0);
  return 0;
}