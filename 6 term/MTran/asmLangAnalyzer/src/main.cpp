#include <string>
#include <vector>

#include "services/lexAnalizeService.h"
#include "services/tableCreateService.h"
#include "services/syntaxTreeService.h"
#include "services/semanticAnalizeService.h"

#include "models/syntaxTreeNode.h"

void printTree(SyntaxTreeNode *syntaxTree, int lvl) {
    std::string stick = "|";
    int i = 0;
    while(i != lvl) {
        stick += "|";
        i++;
    }

    for(auto token : *syntaxTree->getChildList()) {
        std::string printToken = stick + token->getData()->getData();
        printf("%s\n", printToken.c_str());
        if(token->getChildList()->size() != 0)
            printTree(token, lvl + 1);
    }
}

int main(int argc, const char** argv) {
    std::string filename = "test_2_2.asm";
    SyntaxTreeNode *syntaxTree = new SyntaxTreeNode();

    LexAnalizeService* lexAnalizeService = new LexAnalizeService();
    TableCreateService* tableCreateService = new TableCreateService();
    SyntaxTreeService* syntaxTreeService = new SyntaxTreeService();
    SemanticAnalizeService* semanticAnalizeService = new SemanticAnalizeService();

    std::vector<Token *> *tokenList = lexAnalizeService->initLexAnalize(filename);
    syntaxTreeService->buildTree(filename, syntaxTree, 0, INT32_MAX);
    semanticAnalizeService->initSemanticAnalize(syntaxTree);
    //tableCreateService->createTable(tokenList);
    
    //printf("|.code\n");
    //printTree(syntaxTree, 0);
    return 0;
}