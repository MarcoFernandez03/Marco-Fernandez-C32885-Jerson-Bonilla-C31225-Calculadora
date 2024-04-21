#include <iostream>
#include <string>
#include <tokenizer.hh>
using namespace std;

// Function that gets an string and classifies its characters as tokens
int tokenizer::tokenize(string userExpression) {
  for (int i = 0; i < userExpression.length(); i++) {
    if (isdigit(userExpression[i])) {
      // PlaceHolder cambiar por lógica cuando Token esté implementada
      cout << "Estoy leyendo un numero " << userExpression[i] << endl;
    } else {
      // Switch used to dictate an state based on the char read.
      switch (userExpression[i]) {
      case '(':
        cout << "Estoy leyendo el parentesis " << userExpression[i] << endl;
        break;
      case ')':
        cout << "Estoy leyendo el parentesis " << userExpression[i] << endl;
        break;
      case '[':
        cout << "Estoy leyendo el parentesis " << userExpression[i] << endl;
        break;
      case ']':
        cout << "Estoy leyendo el parentesis " << userExpression[i] << endl;
        break;
      case '{':
        cout << "Estoy leyendo el parentesis " << userExpression[i] << endl;
        break;
      case '}':
        cout << "Estoy leyendo el parentesis " << userExpression[i] << endl;
        break;
      case '+':
        cout << "Estoy leyendo el operador " << userExpression[i] << endl;
        break;
      case '-':
        cout << "Estoy leyendo el operador " << userExpression[i] << endl;
        break;
      case '*':
        cout << "Estoy leyendo el operador " << userExpression[i] << endl;
        break;
      case '/':
        cout << "Estoy leyendo el operador " << userExpression[i] << endl;
        break;
      case '^':
        cout << "Estoy leyendo el operador " << userExpression[i] << endl;
        break;
      case '_':
        cout << "Estoy leyendo el operador " << userExpression[i] << endl;
        break;
      case 'v':
        cout << "Estoy leyendo el operador " << userExpression[i] << endl;
        break;
      case '.':
        cout << "Leí el punto decimal" << endl;
        break;
      case ' ':
        cout << " " << endl;
        break;
      default:
        cout << "ERROR: Operador no valido <" << userExpression[i] << ">"
             << endl;
        return 1;
      }
    }
  }
  return 0;
}
