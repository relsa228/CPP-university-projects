#include <string>
#include <vector>

#include "services/lexAnalizeService.h"

int main(int argc, const char** argv) {
    LexAnalizeService* lexAnalizeService = new LexAnalizeService();
    std::vector<Token *> *tokenList = lexAnalizeService->initLexAnalize("test.asm");
    for(auto var : *tokenList) {
        std::cout << "Name: " << var->getData() << std::endl;
        std::cout << "Description: " << var->getDescription() << std::endl << std::endl;
    }

    return 0;
}