#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "../supportingFiles/tokenType.h"

class Token {
private:
    TokenType tokenType;
    std::string data;
    std::string description;
public:
    Token(TokenType tokenType, std::string data, std::string description);
    ~Token();

    void setTokenType(int tokenType);
    void setData(std::string data);
    void setDescription(std::string description);

    TokenType getTokenType();
    std::string getData();
    std::string getDescription();
};

#endif // !TOKEN_H