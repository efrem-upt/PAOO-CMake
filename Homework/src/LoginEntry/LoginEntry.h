#pragma once
#include "Entry.h"
#include <memory>
#include <cstring>

namespace Vaultify::Entries {
    class LoginEntry : public Entry {
    private:
        std::unique_ptr<char[]> website;
        std::unique_ptr<char[]> username;
        std::unique_ptr<char[]> password;

    public:
        LoginEntry(const char* title, const char* site, const char* user, const char* pass);
        LoginEntry(const LoginEntry& other);
        LoginEntry(LoginEntry&& other) noexcept;
        ~LoginEntry() = default;
        LoginEntry& operator=(const LoginEntry& other);
        LoginEntry& operator=(LoginEntry&& other) noexcept;
        virtual void display() const override;
        const char* getWebsite() const { return website.get(); }
        const char* getUsername() const { return username.get(); }
        const char* getPassword() const { return password.get(); }
        void setWebsite(const char* site);
        void setUsername(const char* user);
        void setPassword(const char* pass);
    };
}
