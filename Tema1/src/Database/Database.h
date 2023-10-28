#pragma once
#include "Entry.h"
#include <vector>

class Database {
private:
    std::vector<Entry> entries;

public:
    void addEntry(const Entry& entry);
    Entry getEntry(const std::string& site) const;
};
