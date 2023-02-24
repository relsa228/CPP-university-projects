#include "token.h"

Token::Token(TokenType tokenType, std::string data, std::string description) :
data(data),
description(description),
tokenType(tokenType) {}

Token::~Token() {}

void Token::setTokenType(int tokenType) {
    this->tokenType = TokenType(tokenType);
}

void Token::setData(std::string data) {
    this->data = data;
}

void Token::setDescription(std::string description) {
    this->description = description;
}

TokenType Token::getTokenType() {
    return this->tokenType;
}

std::string Token::getData() {
    return this->data;
}

std::string Token::getDescription() {
    return this->description;
}
