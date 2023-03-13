#include "syntaxBase.h"

std::vector<std::string> zeroTerminalCommands = {
    "RET",
    "ENDP"
};

std::vector<std::string> oneTerminalCommands = {
    "IMUL",
    "MUL",
    "DIV",
    "IDIV",
    "INT",
    "CMP",
    "NEG",
    "INC",
    "PUSH",
    "POP",
    "CALL",
    "DEC",
    "PROC"
};

std::vector<std::string> twoTerminalCommands = {
    "MOV",
    "MOVS",
    "OR",
    "SUB",
    "ADD",
    "CMP",
    "TEST",
    "NEG",
    "XOR"
};

std::vector<Token*> codePointNames;
