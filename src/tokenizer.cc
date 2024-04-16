#include <iostream>
#include <string>
#include <tokenizer.hh>
using namespace std;

int tokenizer::tokenize(string userExpression) {
  for (int i = 0; i < userExpression.length(); i++) {
    if (isdigit(userExpression[i])) {
      // PlaceHolder cambiar por lógica cuando Token esté implementada
      cout << "Estoy leyendo un numero " << userExpression[i] << endl;
    } else {
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
      }
    }
  }
  return 0;
}
