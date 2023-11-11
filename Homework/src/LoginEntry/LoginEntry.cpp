#include "LoginEntry.h"

using namespace Vaultify::Entries;

LoginEntry::LoginEntry(const char* new_title, const char* site, const char* user, const char* pass) : Entry(new_title), website(new char[strlen(site) + 1]), username(new char[strlen(user) + 1]), password(new char[strlen(pass) + 1]) {
    strcpy(this->website, site);
    strcpy(this->username, user);
    strcpy(this->password, pass);
}

LoginEntry::LoginEntry(const LoginEntry& other) : Entry(other), website(new char[strlen(other.website) + 1]), username(new char[strlen(other.username) + 1]), password(new char[strlen(other.password) + 1]) {
    strcpy(this->website, other.website);
    strcpy(this->username, other.username);
    strcpy(this->password, other.password);
}

LoginEntry::LoginEntry(LoginEntry&& other) noexcept : Entry(std::move(other)), website(other.website), username(other.username), password(other.password) {
    other.website = nullptr;
    other.username = nullptr;
    other.password = nullptr;
}

LoginEntry::~LoginEntry() {
        delete[] this->website;
        delete[] this->username;
        delete[] this->password;
}

// assignment overload

LoginEntry& LoginEntry::operator=(const LoginEntry& other) {
    if (this != &other) {
        delete[] this->website;
        delete[] this->username;
        delete[] this->password;
        this->website = new char[strlen(other.website) + 1];
        this->username = new char[strlen(other.username) + 1];
        this->password = new char[strlen(other.password) + 1];
        strcpy(this->website, other.website);
        strcpy(this->username, other.username);
        strcpy(this->password, other.password);
    }
    return *this;
}

LoginEntry& LoginEntry::operator=(LoginEntry&& other) noexcept {
    if (this != &other) {
        delete[] this->website;
        delete[] this->username;
        delete[] this->password;
        this->website = other.website;
        this->username = other.username;
        this->password = other.password;
        other.website = nullptr;
        other.username = nullptr;
        other.password = nullptr;
    }
    return *this;
}

const char* LoginEntry::getWebsite() const {
    return this->website;
}

const char* LoginEntry::getUsername() const {
    return this->username;
}

const char* LoginEntry::getPassword() const {
    return this->password;
}

void LoginEntry::setWebsite(const char* site) {
    delete[] this->website;
    this->website = new char[strlen(site) + 1];
    strcpy(this->website, site);
}

void LoginEntry::setUsername(const char* user) {
    delete[] this->username;
    this->username = new char[strlen(user) + 1];
    strcpy(this->username, user);
}

void LoginEntry::setPassword(const char* pass) {
    delete[] this->password;
    this->password = new char[strlen(pass) + 1];
    strcpy(this->password, pass);
}

void LoginEntry::display() const {
    std::cout << "--------------------------------------------------\n";
    std::cout << "Login Entry:\n";
    std::cout << "Title: " << this->title << std::endl;
    std::cout << "Website: " << this->website << std::endl;
    std::cout << "Username: " << this->username << std::endl;
    std::cout << "Password: " << this->password << std::endl;
    std::cout << "--------------------------------------------------\n";
}