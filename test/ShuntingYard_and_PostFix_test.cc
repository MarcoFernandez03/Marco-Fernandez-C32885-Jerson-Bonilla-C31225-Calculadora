#include <gtest/gtest.h>
#include <ShuntingYard.hh>
#include <PostFix.hh>
#include <iostream>
#include <stack>
#include <string>
#include <token.hh>
using namespace std;

TEST(ShuntingYardAndPostFixTest, SumOfNumbers){
    ShuntingYard sY;
    PostFix pF;
    stack<Token> tokenizedExpression;
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '+');
    tokenizedExpression.push(token2);
    Token token3(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token3);
    stack<Token> PostFixExpression = sY.parse(tokenizedExpression);
    Token result = pF.calculatePostFix(PostFixExpression);
    EXPECT_EQ(result.getNumber(), 4);    
}

TEST(ShuntingYardAndPostFixTest, SubstractionOfNumbers){
    ShuntingYard sY;
    PostFix pF;
    stack<Token> tokenizedExpression;
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '-');
    tokenizedExpression.push(token2);
    Token token3(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token3);
    stack<Token> PostFixExpression = sY.parse(tokenizedExpression);
    Token result = pF.calculatePostFix(PostFixExpression);
    EXPECT_EQ(result.getNumber(), 0);    
}

TEST(ShuntingYardAndPostFixTest, MultiplicationOfNumbers){
    ShuntingYard sY;
    PostFix pF;
    stack<Token> tokenizedExpression;
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '*');
    tokenizedExpression.push(token2);
    Token token3(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token3);
    stack<Token> PostFixExpression = sY.parse(tokenizedExpression);
    Token result = pF.calculatePostFix(PostFixExpression);
    EXPECT_EQ(result.getNumber(), 4);    
}

TEST(ShuntingYardAndPostFixTest, DivisionOfNumbers){
    ShuntingYard sY;
    PostFix pF;
    stack<Token> tokenizedExpression;
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '/');
    tokenizedExpression.push(token2);
    Token token3(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token3);
    stack<Token> PostFixExpression = sY.parse(tokenizedExpression);
    Token result = pF.calculatePostFix(PostFixExpression);
    EXPECT_EQ(result.getNumber(), 1);    
}

TEST(ShuntingYardAndPostFixTest, PoweredByTwo){
    ShuntingYard sY;
    PostFix pF;
    stack<Token> tokenizedExpression;
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '^');
    tokenizedExpression.push(token2);
    Token token3(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token3);
    stack<Token> PostFixExpression = sY.parse(tokenizedExpression);
    Token result = pF.calculatePostFix(PostFixExpression);
    EXPECT_EQ(result.getNumber(), 4);    
}

TEST(ShuntingYardAndPostFixTest, Logarithm){
    ShuntingYard sY;
    PostFix pF;
    stack<Token> tokenizedExpression;
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)10);
    tokenizedExpression.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '_');
    tokenizedExpression.push(token2);
    Token token3(TokenType::TOKEN_TYPE_NUMBER, (double)100);
    tokenizedExpression.push(token3);
    stack<Token> PostFixExpression = sY.parse(tokenizedExpression);
    Token result = pF.calculatePostFix(PostFixExpression);
    EXPECT_EQ(result.getNumber(), 2);    
}

TEST(ShuntingYardAndPostFixTest, SquareRoot){
    ShuntingYard sY;
    PostFix pF;
    stack<Token> tokenizedExpression;
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)4);
    tokenizedExpression.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, 'v');
    tokenizedExpression.push(token2);
    Token token3(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token3);
    stack<Token> PostFixExpression = sY.parse(tokenizedExpression);
    Token result = pF.calculatePostFix(PostFixExpression);
    EXPECT_EQ(result.getNumber(), 2); 
}  

TEST(ShuntingYardAndPostFixTest, Parenthesis){
    ShuntingYard sY;
    PostFix pF;
    stack<Token> tokenizedExpression;
    Token token5(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token5);
    Token token4(TokenType::TOKEN_TYPE_OPERATOR, '+');
    tokenizedExpression.push(token4);
    Token tokenParenthesis2(TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS, ')');
    tokenizedExpression.push(tokenParenthesis2);
    Token token3(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token3);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '+');
    tokenizedExpression.push(token2);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenizedExpression.push(token1);
    Token tokenParenthesis1(TokenType::TOKEN_TYPE_LEFT_PARENTHESIS, '(');
    tokenizedExpression.push(tokenParenthesis1);
    stack<Token> PostFixExpression = sY.parse(tokenizedExpression);
    Token result = pF.calculatePostFix(PostFixExpression);
    EXPECT_EQ(result.getNumber(), 6); 
}   