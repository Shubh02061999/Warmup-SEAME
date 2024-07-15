#include <iostream>
#include <vector>
#include <unordered_map>
// EXIT#include <sstream>  // For stringstream
#include <cctype>   // For isdigit

class Contact {
public:
    std::string name;
    std::string phoneNumber;
    std::string nickname;
    bool isBookmarked;

    Contact(std::string n, std::string p, std::string nn)
        : name(n), phoneNumber(p), nickname(nn), isBookmarked(false) {}
};

class Phonebook {
private:
    std::vector<Contact> contacts;
    std::unordered_map<std::string, int> phoneIndexMap; // to ensure unique phone numbers

public:
    void addContact(const std::string &name, const std::string &phoneNumber, const std::string &nickname) {
        if (!isValidPhoneNumber(phoneNumber)) {
            std::cout << "Invalid phone number format! Please enter a valid 10-digit number." << std::endl;
            return;
        }

        if (phoneIndexMap.find(phoneNumber) != phoneIndexMap.end()) {
            std::cout << "Phone number already exists!" << std::endl;
            return;
        }
        contacts.push_back(Contact(name, phoneNumber, nickname));
        phoneIndexMap[phoneNumber] = contacts.size() - 1;
        std::cout << "Contact added successfully!" << std::endl;
    }

    void searchContact() {
        for (size_t i = 0; i < contacts.size(); ++i) {
            std::cout << i << ": " << contacts[i].name << " (" << contacts[i].nickname << ")" << std::endl;
        }

        if (contacts.empty()) return;

        std::cout << "Enter index to view details: ";
        size_t index;
        std::cin >> index;
        if (index >= contacts.size()) {
            std::cout << "Invalid index!" << std::endl;
            return;
        }

        std::cout << "Name: " << contacts[index].name << std::endl;
        std::cout << "Phone Number: " << contacts[index].phoneNumber << std::endl;
        std::cout << "Nickname: " << contacts[index].nickname << std::endl;

        std::cout << "Do you want to bookmark this contact? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'y') {
            contacts[index].isBookmarked = true;
            std::cout << "Contact bookmarked!" << std::endl;
        }
    }

    void removeContact() {
        std::cout << "Enter index or phone number to remove: ";
        std::string input;
        std::cin >> input;

        size_t index = -1;
        try {
            index = std::stoi(input);
            if (index >= contacts.size()) {
                throw std::out_of_range("Invalid index!");
            }
        } catch (const std::invalid_argument&) {
            if (phoneIndexMap.find(input) != phoneIndexMap.end()) {
                index = phoneIndexMap[input];
            } else {
                std::cout << "Invalid input! Neither index nor phone number found." << std::endl;
                return;
            }
        } catch (const std::out_of_range& e) {
            std::cout << e.what() << std::endl;
            return;
        }

        phoneIndexMap.erase(contacts[index].phoneNumber);
        contacts.erase(contacts.begin() + index);

        // Update phoneIndexMap
        for (size_t i = index; i < contacts.size(); ++i) {
            phoneIndexMap[contacts[i].phoneNumber] = i;
        }

        std::cout << "Contact removed successfully!" << std::endl;
    }

    void listBookmarks() {
        bool hasBookmarks = false;
        for (const auto &contact : contacts) {
            if (contact.isBookmarked) {
                std::cout << contact.name << " (" << contact.nickname << ")" << std::endl;
                hasBookmarks = true;
            }
        }
        if (!hasBookmarks) {
            std::cout << "No bookmarked contacts." << std::endl;
        }
    }

    void exitProgram() {
        std::cout << "Exiting the program." << std::endl;
        exit(0);
    }

private:
    bool isValidPhoneNumber(const std::string &phoneNumber) {
        // Check if the phone number is exactly 10 digits
        if (phoneNumber.length() != 10) {
            return false;
        }

        // Check if all characters are digits
        for (char c : phoneNumber) {
            if (!isdigit(c)) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Phonebook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, REMOVE, BOOKMARK, EXIT): ";
        std::cin >> command;

        if (command == "ADD") {
            std::string name, phoneNumber, nickname;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter phone number (10 digits): ";
            std::cin >> phoneNumber;
            std::cout << "Enter nickname: ";
            std::cin >> nickname;
            phonebook.addContact(name, phoneNumber, nickname);
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else if (command == "REMOVE") {
            phonebook.removeContact();
        } else if (command == "BOOKMARK") {
            phonebook.listBookmarks();
        } else if (command == "EXIT") {
            phonebook.exitProgram();
        } else {
            std::cout << "Invalid command!" << std::endl;
        }

        // Clear input buffer to handle incorrect inputs gracefully
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
