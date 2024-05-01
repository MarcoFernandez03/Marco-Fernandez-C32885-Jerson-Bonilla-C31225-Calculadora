#include <gtest/gtest.h>
#include <token.hh>
TEST(TokenTest, TokenNumber) {
Token token(TokenType::TOKEN_TYPE_NUMBER, (double)5);
EXPECT_EQ(token.getValue(), '5'-'0');
EXPECT_TRUE(token.isNumber());
EXPECT_FALSE(token.isOperator());
EXPECT_EQ(token.getNumber(), 5);
}

TEST(TokenTest, TokenOperator){
Token token(TokenType::TOKEN_TYPE_OPERATOR, '+');
EXPECT_EQ(token.getValue(), '+');
EXPECT_FALSE(token.isNumber());
EXPECT_TRUE(token.isOperator());
}

TEST(TokenTest, TokenLeftParenthesis){
Token token(TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS, '[');
EXPECT_EQ(token.getValue(), '[');
EXPECT_FALSE(token.isNumber());
EXPECT_EQ(token.type(), TokenType::TOKEN_TYPE_RIGHT_PARENTHESIS);
}

TEST(TokenTest, TokenRightParenthesis){
Token token(TokenType::TOKEN_TYPE_LEFT_PARENTHESIS, '}');
EXPECT_EQ(token.getValue(), '}');
EXPECT_FALSE(token.isNumber());
EXPECT_EQ(token.type(), TokenType::TOKEN_TYPE_LEFT_PARENTHESIS);
}