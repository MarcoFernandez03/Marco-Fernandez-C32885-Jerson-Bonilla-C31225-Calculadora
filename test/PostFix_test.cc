#include <gtest/gtest.h>
#include <PostFix.hh>
#include <iostream>
#include <stack>
#include <token.hh>
using namespace std;
TEST(CalculatePostFixTest, SumOfNumbers){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)5);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)4);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '+');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.getNumber(), 9);
}

TEST(CalculatePostFixTest, SumOfDecimalNumbers){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, 5.5);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, 4.5);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '+');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.getNumber(), 10);    
}

TEST(CalculatePostFixTest, SubstractionOfNumbers){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)5);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)4);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '-');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.getNumber(), 1);    
}

TEST(CalculatePostFixTest, MultiplicationOfNumbers){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)5);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)4);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '*');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.getNumber(), 20);    
}


TEST(CalculatePostFixTest, DivisionOfNumbers){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)5);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)4);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '/');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.getNumber(), (double)5/4);    
}

TEST(CalculatePostFixTest, PowerOfTwo){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)3);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '^');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.getNumber(), 8);    
}

TEST(CalculatePostFixTest, Logarithm){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)8);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '_');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.getNumber(), 3);    
}

TEST(CalculatePostFixTest, SquareRootOfNumber){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)4);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, 'v');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.getNumber(), 2);    
}

TEST(CalculatePostFixTest, CubeRootOfNumber){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)3);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)8);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, 'v');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.getNumber(), 2);    
}

TEST(CalculatePostFixTest, DividedByCero){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)5);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)0);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '/');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.type(), TokenType::TOKEN_TYPE_NULL);    
}

TEST(CalculatePostFixTest, CeroPoweredByCero){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)0);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)0);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '^');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.type(), TokenType::TOKEN_TYPE_NULL);    
}

TEST(CalculatePostFixTest, CeroRootOfNumber){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)0);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, 'v');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.type(), TokenType::TOKEN_TYPE_NULL);    
}

TEST(CalculatePostFixTest, SquareRootOfNegativeNumber){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)2);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)-2);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, 'v');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.type(), TokenType::TOKEN_TYPE_NULL);    
}

TEST(CalculatePostFixTest, UndefinedLogarithm){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)8);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)0);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '_');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.type(), TokenType::TOKEN_TYPE_NULL);    
}

TEST(CalculatePostFixTest, InvalidExpression){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)8);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_OPERATOR, '+');
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '+');
    tokenStack.push(token2);
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.type(), TokenType::TOKEN_TYPE_NULL);    
}

TEST(CalculatePostFixTest, InvalidExpression2){
    stack<Token> tokenStack;
    PostFix pF;
    Token token(TokenType::TOKEN_TYPE_NUMBER, (double)8);
    tokenStack.push(token);
    Token token1(TokenType::TOKEN_TYPE_NUMBER, (double)8);
    tokenStack.push(token1);
    Token token2(TokenType::TOKEN_TYPE_OPERATOR, '+');
    tokenStack.push(token2);
    Token token3(TokenType::TOKEN_TYPE_OPERATOR, '+');
    tokenStack.push(token3);
    
    Token result = pF.calculatePostFix(tokenStack);
    EXPECT_EQ(result.type(), TokenType::TOKEN_TYPE_NULL);    
}

