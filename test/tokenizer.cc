#include <gtest/gtest.h>
#include <tokenizer.hh>
#include <iostream>
#include <stack>
#include <string>
#include <token.hh>
using namespace std;
TEST(TokenizeTest, TokenizeNumber){
    tokenizer tokenizer;
    stack<Token> tokenizedExpression = tokenizer.tokenize("5");
    EXPECT_EQ(tokenizedExpression.size(), 1);    
    EXPECT_EQ(tokenizedExpression.top().getNumber(), 5);
}

TEST(TokenizeTest, TokenizeDecimalNumber){
    tokenizer tokenizer;
    stack<Token> tokenizedExpression = tokenizer.tokenize("5.55");
    EXPECT_EQ(tokenizedExpression.size(), 1);
    EXPECT_EQ(tokenizedExpression.top().getNumber(), 5.55);    
}

TEST(TokenizeTest, TokenizeArithmeticOperation){
    tokenizer tokenizer;
    stack<Token> tokenizedExpression = tokenizer.tokenize("5+5");
    EXPECT_EQ(tokenizedExpression.size(), 3);   
}

TEST(TokenizeTest, TokenizeSquareRoot){
    tokenizer tokenizer;
    stack<Token> tokenizedExpression = tokenizer.tokenize("2v5");
    EXPECT_EQ(tokenizedExpression.size(), 3);   
}

TEST(TokenizeTest, TokenizeLogarithm){
    tokenizer tokenizer;
    stack<Token> tokenizedExpression = tokenizer.tokenize("2v5");
    EXPECT_EQ(tokenizedExpression.size(), 3);   
}

TEST(TokenizeTest, TokenizeExponentiation){
    tokenizer tokenizer;
    stack<Token> tokenizedExpression = tokenizer.tokenize("5v5");
    EXPECT_EQ(tokenizedExpression.size(), 3);   
}

TEST(TokenizeTest, BlankSpace){
    tokenizer tokenizer;
    stack<Token> tokenizedExpression = tokenizer.tokenize(" ");
    EXPECT_EQ(tokenizedExpression.size(), 0);    
}

TEST(TokenizeTest, Point){
    tokenizer tokenizer;
    stack<Token> tokenizedExpression = tokenizer.tokenize(".");
    EXPECT_EQ(tokenizedExpression.size(), 0);    
}

TEST(TokenizeTest, Nothing){
    tokenizer tokenizer;
    stack<Token> tokenizedExpression = tokenizer.tokenize("");
    EXPECT_EQ(tokenizedExpression.size(), 0);    
}