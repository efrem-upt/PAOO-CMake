#include "SecureNoteEntry.h"
#include <cstring>
#include <iostream>

using namespace Vaultify::Entries;

SecureNoteEntry::SecureNoteEntry(const char* title, const char* note) 
    : Entry(title),
      note(std::make_unique<char[]>(strlen(note) + 1)) {
    strcpy(this->note.get(), note);
}

SecureNoteEntry::SecureNoteEntry(const SecureNoteEntry& other) 
    : Entry(other),
      note(std::make_unique<char[]>(strlen(other.note.get()) + 1)) {
    strcpy(this->note.get(), other.note.get());
}

SecureNoteEntry::SecureNoteEntry(SecureNoteEntry&& other) noexcept 
    : Entry(std::move(other)),
      note(std::move(other.note)) {
}

SecureNoteEntry& SecureNoteEntry::operator=(const SecureNoteEntry& other) {
    if (this != &other) {
        Entry::operator=(other); // Call base class copy assignment operator
        note = std::make_unique<char[]>(strlen(other.note.get()) + 1);
        strcpy(note.get(), other.note.get());
    }
    return *this;
}

SecureNoteEntry& SecureNoteEntry::operator=(SecureNoteEntry&& other) noexcept {
    if (this != &other) {
        Entry::operator=(std::move(other)); // Call base class move assignment operator
        note = std::move(other.note);
    }
    return *this;
}

void SecureNoteEntry::display() const {
    std::cout << "--------------------------------------------------\n";
    std::cout << "Secure Note Entry\n";
    std::cout << "Title: " << getTitle() << "\n"; // Assuming getTitle() is a method of Entry
    std::cout << "Note: " << note.get() << "\n";
    std::cout << "--------------------------------------------------\n";
}

const char* SecureNoteEntry::getNote() const {
    return note.get();
}

void SecureNoteEntry::setNote(const char* new_note) {
    note = std::make_unique<char[]>(strlen(new_note) + 1);
    strcpy(note.get(), new_note);
}
