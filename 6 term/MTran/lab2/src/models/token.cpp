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

std::string Token::getTokenType() {
    switch (this->tokenType) {
        case TokenType::Command:
            return "Command";

        case TokenType::DataType:
            return "Data type";

        case TokenType::ConditionalCrossing:
            return "Conditional crossing";

        case TokenType::Name:
            return "Name";

        case TokenType::Sign:
            return "Sign";
        
        case TokenType::Register:
            return "Register";

        case TokenType::Interruption:
            return "Interruption";

        default:
            return "No type";
    }
}

std::string Token::getData() {
    return this->data;
}

std::string Token::getDescription() {
    return this->description;
}
