#include "LoginEntry.h"
#include <cstring>
#include <iostream>

using namespace Vaultify::Entries;

LoginEntry::LoginEntry(const char* new_title, const char* site, const char* user, const char* pass) 
    : Entry(new_title),
      website(std::make_unique<char[]>(strlen(site) + 1)),
      username(std::make_unique<char[]>(strlen(user) + 1)),
      password(std::make_unique<char[]>(strlen(pass) + 1)) {
    strcpy(website.get(), site);
    strcpy(username.get(), user);
    strcpy(password.get(), pass);
}

LoginEntry::LoginEntry(const LoginEntry& other) 
    : Entry(other),
      website(std::make_unique<char[]>(strlen(other.website.get()) + 1)),
      username(std::make_unique<char[]>(strlen(other.username.get()) + 1)),
      password(std::make_unique<char[]>(strlen(other.password.get()) + 1)) {
    strcpy(website.get(), other.website.get());
    strcpy(username.get(), other.username.get());
    strcpy(password.get(), other.password.get());
}

LoginEntry::LoginEntry(LoginEntry&& other) noexcept 
    : Entry(std::move(other)),
      website(std::move(other.website)),
      username(std::move(other.username)),
      password(std::move(other.password)) {
}

LoginEntry& LoginEntry::operator=(const LoginEntry& other) {
    if (this != &other) {
        Entry::operator=(other);
        website = std::make_unique<char[]>(strlen(other.website.get()) + 1);
        username = std::make_unique<char[]>(strlen(other.username.get()) + 1);
        password = std::make_unique<char[]>(strlen(other.password.get()) + 1);
        strcpy(website.get(), other.website.get());
        strcpy(username.get(), other.username.get());
        strcpy(password.get(), other.password.get());
    }
    return *this;
}

LoginEntry& LoginEntry::operator=(LoginEntry&& other) noexcept {
    if (this != &other) {
        Entry::operator=(std::move(other));
        website = std::move(other.website);
        username = std::move(other.username);
        password = std::move(other.password);
    }
    return *this;
}

void LoginEntry::setWebsite(const char* site) {
    website = std::make_unique<char[]>(strlen(site) + 1);
    strcpy(website.get(), site);
}

void LoginEntry::setUsername(const char* user) {
    username = std::make_unique<char[]>(strlen(user) + 1);
    strcpy(username.get(), user);
}

void LoginEntry::setPassword(const char* pass) {
    password = std::make_unique<char[]>(strlen(pass) + 1);
    strcpy(password.get(), pass);
}

void LoginEntry::display() const {
    std::cout << "--------------------------------------------------\n";
    std::cout << "Login Entry:\n";
    std::cout << "Title: " << getTitle() << "\n"; // Assuming getTitle() is a method of Entry
    std::cout << "Website: " << website.get() << std::endl;
    std::cout << "Username: " << username.get() << std::endl;
    std::cout << "Password: " << password.get() << std::endl;
    std::cout << "--------------------------------------------------\n";
}
