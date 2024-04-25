#include <iostream>
#include <string>
#include <token.hh>
#include <tokenizer.hh>
using namespace std;

// Function that gets an string and classifies its characters as tokens
stack<Token> tokenizer::tokenize(string userExpression) {
  // El stack en el orden que se reciben las expresiones
  stack<Token> stackUserExpression;
  // El stack con el orden de los tokens de forma correcta (para que el primer
  // elemento ingresado sea el top en el nuevo stack).
  stack<Token> stackUserExpressionRight;
  for (int i = 0; i < userExpression.length(); i++) {
    if (isdigit(userExpression[i])) {
      // contador para sumar al i.
      int sumadorparai = 0;
      double multiplicadorDecimal = 0;
      bool tieneDecimal = false;
      double numeroActual = userExpression[i] - 48;
      for (int j = i + 1; j < userExpression.length(); j++) {
        if (!tieneDecimal) {
          if (isdigit(userExpression[j])) {
            int nuevoNumero = userExpression[j] - '0';
            numeroActual = numeroActual * 10 + nuevoNumero;
            sumadorparai++;
          } else if (userExpression[j] == '.' && !tieneDecimal) {
            tieneDecimal = true;
            multiplicadorDecimal = 0.1;
            sumadorparai++;
          } else {
            break;
          }
        } else {
          if (isdigit(userExpression[j])) {
            double nuevoNumero = userExpression[j] - '0';
            numeroActual = numeroActual + nuevoNumero * multiplicadorDecimal;
            multiplicadorDecimal = multiplicadorDecimal * 0.1;
            sumadorparai++;
          } else {
            break;
          }
        }
      }
      Token nuevoToken(TokenType::TOKEN_TYPE_NUMBER, to_string(numeroActual));
      stackUserExpression.push(nuevoToken);
      i = i + sumadorparai;
      cout << "Estoy leyendo un numero " << numeroActual << endl;
    } else {
      // Switch used to dictate an state based on the char read, create a new token based on the char and push it into the stack.
      string caracter;
      caracter += userExpression[i];
      Token nuevoToken(TokenType::TOKEN_TYPE_OPERATOR, caracter);
      switch (userExpression[i]) {
      case '(':
        stackUserExpression.push(nuevoToken);
        cout << "Estoy leyendo el parentesis " << userExpression[i] << endl;
        break;
      case ')':
        stackUserExpression.push(nuevoToken);
        cout << "Estoy leyendo el parentesis " << userExpression[i] << endl;
        break;
      case '[':
        stackUserExpression.push(nuevoToken);
        cout << "Estoy leyendo el parentesis " << userExpression[i] << endl;
        break;
      case ']':
        stackUserExpression.push(nuevoToken);
        cout << "Estoy leyendo el parentesis " << userExpression[i] << endl;
        break;
      case '{':
        stackUserExpression.push(nuevoToken);
        cout << "Estoy leyendo el parentesis " << userExpression[i] << endl;
        break;
      case '}':
        stackUserExpression.push(nuevoToken);
        cout << "Estoy leyendo el parentesis " << userExpression[i] << endl;
        break;
      case '+':
        stackUserExpression.push(nuevoToken);
        cout << "Estoy leyendo el operador " << userExpression[i] << endl;
        break;
      case '-':
        stackUserExpression.push(nuevoToken);
        cout << "Estoy leyendo el operador " << userExpression[i] << endl;
        break;
      case '*':
        stackUserExpression.push(nuevoToken);
        cout << "Estoy leyendo el operador " << userExpression[i] << endl;
        break;
      case '/':
        stackUserExpression.push(nuevoToken);
        cout << "Estoy leyendo el operador " << userExpression[i] << endl;
        break;
      case '^':
        stackUserExpression.push(nuevoToken);
        cout << "Estoy leyendo el operador " << userExpression[i] << endl;
        break;
      case '_':
        stackUserExpression.push(nuevoToken);
        cout << "Estoy leyendo el operador " << userExpression[i] << endl;
        break;
      case 'v':
        stackUserExpression.push(nuevoToken);
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
        return stackUserExpression;
      }
    }
  }

  //Reverses the order of the tokens into a new stack with the right order.
  while (!stackUserExpression.empty()) {
    Token topToken = stackUserExpression.top();
    stackUserExpression.pop();
    stackUserExpressionRight.push(topToken);
  }
  return stackUserExpressionRight;
}
