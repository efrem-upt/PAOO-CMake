#include "Database.h"

using namespace Vaultify;

Database::Database() {
    std::cout << "(constructor): Constructor for database called\n";
}

Database::~Database() {
    std::cout << "(destructor): Destructor for database called\n";
    for (auto entry : this->entries) {
        delete entry;
    }
}

void Database::addEntry(Entry* entry) {
    std::cout << "(add_entry): Added entry " << entry->getId() << " to database\n";
    this->entries.push_back(entry);
}

const std::vector<Entry*>& Database::getEntries() const {
    return this->entries;
}

