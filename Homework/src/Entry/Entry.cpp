#include "Entry.h"

uint32_t Entry::idCounter = 1;

Entry::Entry(const char* site, const char* user, const char* pass)
    : id(idCounter++), website(new char[strlen(site) + 1]), username(new char[strlen(user) + 1]), password(new char[strlen(pass) + 1])
 {
    std::cout << "(constructor): Constructor for entry " << id << " called\n";
    snprintf(website, strlen(site) + 1, "%s", site);
    snprintf(username, strlen(user) + 1, "%s", user);
    snprintf(password, strlen(pass) + 1, "%s", pass);
}

Entry::Entry(const Entry& other) 
    : id(idCounter++), website(new char[strlen(other.website) + 1]), username(new char[strlen(other.username) + 1]), password(new char[strlen(other.password) + 1])
{
    std::cout << "(copy_constructor): Copied contents of entry " << other.id << " to entry " << id << "\n";
    snprintf(website, strlen(other.website) + 1, "%s", other.website);
    snprintf(username, strlen(other.username) + 1, "%s", other.username);
    snprintf(password, strlen(other.password) + 1, "%s", other.password);
}

Entry::Entry(Entry&& other) noexcept 
    : id(other.id), website(other.website), username(other.username), password(other.password)
{
    std::cout << "(move_constructor): Moved contents of entry " << id << "\n";
    other.website = nullptr;
    other.username = nullptr;
    other.password = nullptr;
}

Entry::~Entry() {
    if (website == nullptr && username == nullptr && password == nullptr)
        std::cout << "(destructor): Destructor for already moved entry " << id << " called\n";
    else {
        std::cout << "(destructor): Destructor for entry " << id << " called\n";
        delete[] website;
        delete[] username;
        delete[] password;
    }
}

const char* Entry::getWebsite() const {
    return website;
}

const char* Entry::getUsername() const {
    return username;
}

const char* Entry::getPassword() const {
    return password;
}

void Entry::setWebsite(const char* site) {
    delete[] website;
    website = new char[strlen(site) + 1];
    snprintf(website, strlen(site) + 1, "%s", site);
}

void Entry::setUsername(const char* user) {
    delete[] username;
    username = new char[strlen(user) + 1];
    snprintf(username, strlen(user) + 1, "%s", user);
}

void Entry::setPassword(const char* pass) {
    delete[] password;
    password = new char[strlen(pass) + 1];
    snprintf(password, strlen(pass) + 1, "%s", pass);
}