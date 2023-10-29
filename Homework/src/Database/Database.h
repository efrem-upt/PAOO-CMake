#pragma once
#include "Entry.h"
#include <vector>

class Database {
private:
    std::vector<Entry> entries;

public:
    Database();
    ~Database();
    void addEntry(const Entry& entry);
    void addEntry(const char* site, const char* user, const char* pass);
    const Entry& getEntry(const std::string& site) const;
};
