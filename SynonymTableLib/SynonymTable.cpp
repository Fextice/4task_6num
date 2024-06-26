#include <stdexcept>
#include "SynonymTable.h"

SynonymTable::SynonymTable(std::map<std::string, std::vector<std::string>> *init) {
    if (init == nullptr) {
        throw std::invalid_argument("Synonym table shouldn't be nullptr");
    }
    synonyms = init;
}

SynonymTable::~SynonymTable() {
    delete synonyms;
}
//#include <iostream>
std::string SynonymTable::getRandomSynonymFor(const std::string &word) {
    if (synonyms->count(word)) {
        std::vector synonym = (*synonyms)[word];
        std::vector<std::string> out;
        std::sample(
                synonym.begin(),
                synonym.end(),
                std::back_inserter(out),
                1,
                std::mt19937{std::random_device{}()}
        );
        return out.at(0);
    } else {
        return word;
    }
}

const std::map<std::string, std::vector<std::string>> *SynonymTable::getValues() {
    return synonyms;
}
