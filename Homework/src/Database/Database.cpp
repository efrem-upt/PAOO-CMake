#include "Database.h"

Database::Database() {
    std::cout << "(constructor): Constructor for database called\n";
}

Database::~Database() {
    std::cout << "(destructor): Destructor for database called\n";
}

void Database::addEntry(const Entry& entry) {
    entries.push_back(entry);
}

void Database::addEntry(const char* site, const char* user, const char* pass) {
        entries.emplace_back(site, user, pass);
}

const Entry& Database::getEntry(const std::string& site) const {
    for (const auto& entry : entries) {
        if (entry.getWebsite() == site) {
            return entry;
        }
    }

    throw std::runtime_error("Entry not found");
}

