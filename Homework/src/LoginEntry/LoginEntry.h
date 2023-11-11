#pragma once
#include "Entry.h"

namespace Vaultify::Entries {
    class LoginEntry : public Entry {
    private:
        char* website;
        char* username;
        char* password;

    public:
        LoginEntry(const char* title, const char* site, const char* user, const char* pass);
        LoginEntry(const LoginEntry& other);
        LoginEntry(LoginEntry&& other) noexcept;
        ~LoginEntry();
        LoginEntry& operator=(const LoginEntry& other);
        LoginEntry& operator=(LoginEntry&& other) noexcept;
        virtual const char* getTitle() const override;
        virtual void setTitle(const char* title) override;
        virtual void display() const override;
        const char* getWebsite() const;
        const char* getUsername() const;
        const char* getPassword() const;
        void setWebsite(const char* site);
        void setUsername(const char* user);
        void setPassword(const char* pass);
    };
}