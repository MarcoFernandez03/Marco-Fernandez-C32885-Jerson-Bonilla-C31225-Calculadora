#include <ShuntingYard.hh>
#include <gtest/gtest.h>
#include <iostream>
#include <stack>
#include <string>
#include <token.hh>
#include <tokenizer.hh>
using namespace std;

TEST(TokenizeAndShuntingYardTest, SumofNumbers) {
  tokenizer tokenizer;
  ShuntingYard sY;
  stack<Token> tokenizedExpression = tokenizer.tokenize("5+5");
  stack<Token> postFixExpression = sY.parse(tokenizedExpression);
  EXPECT_EQ(postFixExpression.size(), 3);
}

TEST(TokenizeAndShuntingYardTest, SubstractionOfNumbers) {
  tokenizer tokenizer;
  ShuntingYard sY;
  stack<Token> tokenizedExpression = tokenizer.tokenize("5-5");
  stack<Token> postFixExpression = sY.parse(tokenizedExpression);
  EXPECT_EQ(postFixExpression.size(), 3);
}

TEST(TokenizeAndShuntingYardTest, MultiplicationOfNumbers) {
  tokenizer tokenizer;
  ShuntingYard sY;
  stack<Token> tokenizedExpression = tokenizer.tokenize("5*5");
  stack<Token> postFixExpression = sY.parse(tokenizedExpression);
  EXPECT_EQ(postFixExpression.size(), 3);
}

TEST(TokenizeAndShuntingYardTest, DivisionOfNumbers) {
  tokenizer tokenizer;
  ShuntingYard sY;
  stack<Token> tokenizedExpression = tokenizer.tokenize("5/5");
  stack<Token> postFixExpression = sY.parse(tokenizedExpression);
  EXPECT_EQ(postFixExpression.size(), 3);
}

TEST(TokenizeAndShuntingYardTest, NumberPoweredByNumber) {
  tokenizer tokenizer;
  ShuntingYard sY;
  stack<Token> tokenizedExpression = tokenizer.tokenize("5^5");
  stack<Token> postFixExpression = sY.parse(tokenizedExpression);
  EXPECT_EQ(postFixExpression.size(), 3);
}

TEST(TokenizeAndShuntingYardTest, SquareRoot) {
  tokenizer tokenizer;
  ShuntingYard sY;
  stack<Token> tokenizedExpression = tokenizer.tokenize("2v4");
  stack<Token> postFixExpression = sY.parse(tokenizedExpression);
  EXPECT_EQ(postFixExpression.size(), 3);
}

TEST(TokenizeAndShuntingYardTest, SquareRoot2) {
  tokenizer tokenizer;
  ShuntingYard sY;
  stack<Token> tokenizedExpression = tokenizer.tokenize("2V4");
  stack<Token> postFixExpression = sY.parse(tokenizedExpression);
  EXPECT_EQ(postFixExpression.size(), 3);
}

TEST(TokenizeAndShuntingYardTest, Logarithm) {
  tokenizer tokenizer;
  ShuntingYard sY;
  stack<Token> tokenizedExpression = tokenizer.tokenize("45_5");
  stack<Token> postFixExpression = sY.parse(tokenizedExpression);
  EXPECT_EQ(postFixExpression.size(), 3);
}

TEST(TokenizeAndShuntingYardTest, Parenthesis) {
  tokenizer tokenizer;
  ShuntingYard sY;
  stack<Token> tokenizedExpression = tokenizer.tokenize("(5+5)");
  stack<Token> postFixExpression = sY.parse(tokenizedExpression);
  EXPECT_EQ(postFixExpression.size(), 3);
}
