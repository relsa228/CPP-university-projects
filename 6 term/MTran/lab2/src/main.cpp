#include <string>
#include <vector>

#include "services/lexAnalizeService.h"
#include "services/tableCreateService.h"

int main(int argc, const char** argv) {
    std::string filename = argv[1];

    LexAnalizeService* lexAnalizeService = new LexAnalizeService();
    TableCreateService* tableCreateService = new TableCreateService();

    std::vector<Token *> *tokenList = lexAnalizeService->initLexAnalize(filename);
    tableCreateService->createTable(tokenList);
    return 0;
}