#include "SecureNoteEntry.h"

using namespace Vaultify::Entries;

SecureNoteEntry::SecureNoteEntry(const char* title, const char* note) : Entry(title), note(new char[strlen(note) + 1]) {
    strcpy(this->note, note);
}

SecureNoteEntry::SecureNoteEntry(const SecureNoteEntry& other) : Entry(other), note(new char[strlen(other.note) + 1]) {
    strcpy(this->note, other.note);
}

SecureNoteEntry::SecureNoteEntry(SecureNoteEntry&& other) noexcept : Entry(std::move(other)), note(other.note) {
    other.note = nullptr;
}

SecureNoteEntry::~SecureNoteEntry() {
    delete[] this->note;
}

SecureNoteEntry& SecureNoteEntry::operator=(const SecureNoteEntry& other) {
    if (this != &other) {
        delete[] this->note;
        this->note = new char[strlen(other.note) + 1];
        strcpy(this->note, other.note);
    }
    return *this;
}

SecureNoteEntry& SecureNoteEntry::operator=(SecureNoteEntry&& other) noexcept {
    if (this != &other) {
        delete[] this->note;
        this->note = other.note;
        other.note = nullptr;
    }
    return *this;
}

void SecureNoteEntry::display() const {
    std::cout << "--------------------------------------------------\n";
    std::cout << "Secure Note Entry\n";
    std::cout << "Title: " << this->getTitle() << "\n";
    std::cout << "Note: " << this->note << "\n";
    std::cout << "--------------------------------------------------\n";
}

const char* SecureNoteEntry::getNote() const {
    return this->note;
}

void SecureNoteEntry::setNote(const char* note) {
    delete[] this->note;
    this->note = new char[strlen(note) + 1];
    strcpy(this->note, note);
}