#include "LoginEntry.h"
#include "Database.h"
#include <iostream>
#include <cstring>

using namespace Vaultify;
using namespace Vaultify::Entries;


int main() {
    // Create a database
    Database db;

    // Create a login entry
    LoginEntry entry("Google", "google.com", "user", "pass");

    // Add the entry to the database
    db.addEntry(&entry);

   // iterate through database and print out entries
    
    for (auto entry : db.getEntries()) {
        entry->display();
    }
    return 0;
}
