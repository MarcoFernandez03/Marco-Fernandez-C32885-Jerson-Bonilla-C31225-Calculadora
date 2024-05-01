#include <ShuntingYard.hh>
#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <string>
#include <token.hh>
using namespace std;
TEST(ParseTest, SmallExpression) {
  ShuntingYard sy;
  stack<Token> tokenStack;
  Token token(TokenType::TOKEN_TYPE_NUMBER, '3');
  tokenStack.push(token);
  Token token1(TokenType::TOKEN_TYPE_OPERATOR, '+');
  tokenStack.push(token1);
  Token token2(TokenType::TOKEN_TYPE_NUMBER, '2');
  tokenStack.push(token2);
  stack<Token> tokenizedStack = sy.parse(tokenStack);
  EXPECT_EQ(tokenizedStack.top().getValue(), '+');
}

TEST(ParseTest, MediumExpression) {
  ShuntingYard sy;
  stack<Token> tokenStack;
  Token token(TokenType::TOKEN_TYPE_NUMBER, '3');
  tokenStack.push(token);
  Token token1(TokenType::TOKEN_TYPE_OPERATOR, '^');
  tokenStack.push(token1);
  Token token2(TokenType::TOKEN_TYPE_NUMBER, '2');
  tokenStack.push(token2);
  Token token9(TokenType::TOKEN_TYPE_OPERATOR, '+');
  tokenStack.push(token9);
  Token token8(TokenType::TOKEN_TYPE_NUMBER, '2');
  tokenStack.push(token8);
  Token token3(TokenType::TOKEN_TYPE_OPERATOR, '-');
  tokenStack.push(token3);
  Token token4(TokenType::TOKEN_TYPE_NUMBER, '2');
  tokenStack.push(token4);
  Token token5(TokenType::TOKEN_TYPE_OPERATOR, '*');
  tokenStack.push(token5);
  Token token6(TokenType::TOKEN_TYPE_NUMBER, '2');
  tokenStack.push(token6);
  stack<Token> tokenizedStack = sy.parse(tokenStack);
  EXPECT_EQ(tokenizedStack.top().getValue(), '+');
}

TEST(ParseTest, BigExpression) {
  ShuntingYard sy;
  stack<Token> tokenStack;
  Token token(TokenType::TOKEN_TYPE_NUMBER, '3');
  tokenStack.push(token);
  Token token1(TokenType::TOKEN_TYPE_OPERATOR, '^');
  tokenStack.push(token1);
  Token token2(TokenType::TOKEN_TYPE_NUMBER, '2');
  tokenStack.push(token2);
  Token token3(TokenType::TOKEN_TYPE_OPERATOR, '^');
  tokenStack.push(token3);
  Token token4(TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS, ')');
  tokenStack.push(token4);
  Token token5(TokenType::TOKEN_TYPE_NUMBER, '5');
  tokenStack.push(token5);
  Token token6(TokenType::TOKEN_TYPE_OPERATOR, '-');
  tokenStack.push(token6);
  Token token7(TokenType::TOKEN_TYPE_NUMBER, '1');
  tokenStack.push(token7);
  Token token8(TokenType::TOKEN_TYPE_LEFT_PARENTHESIS, '(');
  tokenStack.push(token8);
  Token token9(TokenType::TOKEN_TYPE_OPERATOR, '/');
  tokenStack.push(token9);
  Token token10(TokenType::TOKEN_TYPE_NUMBER, '2');
  tokenStack.push(token10);
  Token token11(TokenType::TOKEN_TYPE_OPERATOR, '*');
  tokenStack.push(token11);
  Token token12(TokenType::TOKEN_TYPE_NUMBER, '4');
  tokenStack.push(token12);
  Token token13(TokenType::TOKEN_TYPE_OPERATOR, '+');
  tokenStack.push(token13);
  Token token14(TokenType::TOKEN_TYPE_NUMBER, '3');
  tokenStack.push(token14);
  stack<Token> tokenizedStack = sy.parse(tokenStack);
  EXPECT_EQ(tokenizedStack.top().getValue(), '+');
}

TEST(ParseTest, IncorrectParenthesisPartner) {
  ShuntingYard sy;
  stack<Token> tokenStack;
  Token token4(TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS, ']');
  tokenStack.push(token4);
  Token token5(TokenType::TOKEN_TYPE_NUMBER, '5');
  tokenStack.push(token5);
  Token token6(TokenType::TOKEN_TYPE_OPERATOR, '-');
  tokenStack.push(token6);
  Token token7(TokenType::TOKEN_TYPE_NUMBER, '1');
  tokenStack.push(token7);
  Token token8(TokenType::TOKEN_TYPE_LEFT_PARENTHESIS, '(');
  tokenStack.push(token8);
  Token token9(TokenType::TOKEN_TYPE_OPERATOR, '/');
  tokenStack.push(token9);
  Token token10(TokenType::TOKEN_TYPE_NUMBER, '2');
  tokenStack.push(token10);
  stack<Token> tokenizedStack = sy.parse(tokenStack);
  EXPECT_EQ(tokenizedStack.size(), 0);
}

TEST(ParseTest, LParenthesisNoPartner) {
  ShuntingYard sy;
  stack<Token> tokenStack;
  Token token5(TokenType::TOKEN_TYPE_NUMBER, '5');
  tokenStack.push(token5);
  Token token6(TokenType::TOKEN_TYPE_OPERATOR, '-');
  tokenStack.push(token6);
  Token token7(TokenType::TOKEN_TYPE_NUMBER, '1');
  tokenStack.push(token7);
  Token token8(TokenType::TOKEN_TYPE_LEFT_PARENTHESIS, '(');
  tokenStack.push(token8);
  Token token9(TokenType::TOKEN_TYPE_OPERATOR, '/');
  tokenStack.push(token9);
  Token token10(TokenType::TOKEN_TYPE_NUMBER, '2');
  tokenStack.push(token10);
  stack<Token> tokenizedStack = sy.parse(tokenStack);
  EXPECT_EQ(tokenizedStack.size(), 0);
}

TEST(ParseTest, RParenthesisNoPartner) {
  ShuntingYard sy;
  stack<Token> tokenStack;
  Token token4(TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS, ']');
  tokenStack.push(token4);
  Token token5(TokenType::TOKEN_TYPE_NUMBER, '5');
  tokenStack.push(token5);
  Token token6(TokenType::TOKEN_TYPE_OPERATOR, '-');
  tokenStack.push(token6);
  Token token7(TokenType::TOKEN_TYPE_NUMBER, '1');
  tokenStack.push(token7);
  Token token9(TokenType::TOKEN_TYPE_OPERATOR, '/');
  tokenStack.push(token9);
  Token token10(TokenType::TOKEN_TYPE_NUMBER, '2');
  tokenStack.push(token10);
  stack<Token> tokenizedStack = sy.parse(tokenStack);
  EXPECT_EQ(tokenizedStack.size(), 0);
}
