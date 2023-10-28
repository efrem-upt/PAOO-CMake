#include <iostream>
#include <cstring>
#include "Entry.h"

Entry::Entry(const char* site, const char* user, const char* pass) {
    std::cout << "Constructor called\n";
    website = new char[strlen(site) + 1];
    strcpy(website, site);
    username = new char[strlen(user) + 1];
    strcpy(username, user);
    password = new char[strlen(pass) + 1];
    strcpy(password, pass);
}

Entry::Entry(const Entry& other) {
    std::cout << "Copy constructor called\n";
    website = new char[strlen(other.website) + 1];
    strcpy(website, other.website);
    username = new char[strlen(other.username) + 1];
    strcpy(username, other.username);
    password = new char[strlen(other.password) + 1];
    strcpy(password, other.password);
}

Entry::Entry(Entry&& other) noexcept {
    std::cout << "Move constructor called\n";
    website = other.website;
    username = other.username;
    password = other.password;
    other.website = nullptr;
    other.username = nullptr;
    other.password = nullptr;
}

Entry::~Entry() {
    std::cout << "Destructor called\n";
    delete[] website;
    delete[] username;
    delete[] password;
}

char* Entry::getWebsite() const {
    return website;
}

char* Entry::getUsername() const {
    return username;
}

char* Entry::getPassword() const {
    return password;
}
