#include "Database.h"

void Database::addEntry(const Entry& entry) {
    entries.push_back(entry);
}

Entry Database::getEntry(const std::string& site) const {
    for (const auto& entry : entries) {
        if (entry.getWebsite() == site) {
            return entry;
        }
    }

    return Entry("none", "none", "none");
}
