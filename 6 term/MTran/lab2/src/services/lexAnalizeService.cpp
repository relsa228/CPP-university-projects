#include "lexAnalizeService.h"

LexAnalizeService::LexAnalizeService() {}

LexAnalizeService::~LexAnalizeService() {}

std::vector<Token *> *LexAnalizeService::initLexAnalize(std::string filename) {
    std::vector<Token *> *resultVector = new std::vector<Token *>();
    checkDataValNames(filename, resultVector);
    checkCodeValNames(filename, resultVector);

    return resultVector;
}

void LexAnalizeService::trim(std::string &str) {
    int comment = str.find(";");
    //str.erase(comment);
    str.erase(str.find_last_not_of(' ') + 1);        
    str.erase(0, str.find_first_not_of(' '));
}

void LexAnalizeService::checkDataValNames(std::string filename, std::vector<Token*>* tokenList) {
    std::ifstream codeFile(filename);
    std::string dataRow;

    while(getline(codeFile, dataRow)) {
        auto chkPos = dataRow.find(".data");
        if (chkPos != std::string::npos)
            break;
    }

    while(getline(codeFile, dataRow)) {
        auto chkPos = dataRow.find(".code");
        if (chkPos != std::string::npos)
            break;

        trim(dataRow);
        bool dataTypeFlag = false;
        std::string valName, dataType;
        for(auto ch : dataRow) {
            if (ch == ' ' && dataTypeFlag )
                break;
            if (ch == ' ' ) {
                dataTypeFlag = true;
                continue;
            }

            if(dataTypeFlag)
                dataType += ch;
            else 
                valName += ch;
        }
        std::transform(dataType.begin(), dataType.end(), dataType.begin(), ::toupper);
        if (std::find(dataTypesList.begin(), dataTypesList.end(), dataType) != dataTypesList.end()) {
            nameList.push_back(valName);
            tokenList->push_back(new Token(TokenType::Name, valName, dataType + " variable"));
        }
        else 
            std::cout << "Datatype error" << std::endl;
    }
    
    codeFile.close();
}

void LexAnalizeService::checkCodeValNames(std::string filename, std::vector<Token *> *tokenList) {
    std::ifstream codeFile(filename);
    std::string codeRow;

    while(getline(codeFile, codeRow)) {
        auto chkPos = codeRow.find(".code");
        if (chkPos != std::string::npos)
            break;
    }

    while(getline(codeFile, codeRow)) {
        auto chkPos = codeRow.find(".data");
        if (chkPos != std::string::npos)
            break;

        trim(codeRow);
        if (!std::regex_match(codeRow, std::regex("^[\\S][^:]+:(.*)") ))
            continue;

        std::string pointName;
        for(auto ch : codeRow) {
            if(ch == ':')
                tokenList->push_back(new Token(TokenType::Name, pointName, "Code point name"));
            
            if(ch == ';') {
                printf("Point name error");
                break;
            }

            pointName += ch;
        }
    }
    
    codeFile.close();
}

void LexAnalizeService::checkCodeLex(std::string filename, std::vector<Token *> *tokenList) {
}
