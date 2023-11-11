#include "LoginEntry.h"
#include "CreditCardEntry.h"
#include "SecureNoteEntry.h"
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

    // create a credit card entry

    CreditCardEntry ccEntry("Visa", "1234 5678 9012 3456", "John Doe", "01/23", "123");

    // create a secure note entry

    SecureNoteEntry snEntry("My Note", "This is a note");

    // Add the entry to the database
    db.addEntry(&entry);

    // Add the credit card entry to the database

    db.addEntry(&ccEntry);

    // Add the secure note entry to the database

    db.addEntry(&snEntry);

   // iterate through database and print out entries
    
    for (auto entry : db.getEntries()) {
        entry->display();
    }
    return 0;
}
