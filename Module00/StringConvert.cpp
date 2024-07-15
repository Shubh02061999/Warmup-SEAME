#include <iostream>
#include <string>
using namespace std;

// Function to convert string to uppercase
void to_upper(std::string &str) {
    // Iterate through each character in the string
    for (char &c : str) {
        // If the character is lowercase, convert it to uppercase
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }
    }
}

// Function to convert string to lowercase
void to_lower(std::string &str) {
    // Iterate through each character in the string
    for (char &c : str) {
        // If the character is uppercase, convert it to lowercase
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
}

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc < 3) {
        // Print usage message if not enough arguments
        std::cerr << "Usage: ./convert {up|down} {string}" << std::endl;
        return 1; // Return 1 to indicate failure
    }

    // Retrieve the command argument ("up" or "down")
    std::string command = argv[1];
    // Initialize an empty string to store the input string
    std::string input;

    // Concatenate all the remaining arguments into one string
    for (int i = 2; i < argc; ++i) {
        // Add a space before each new argument except the first one
        if (i > 2) {
            input += " ";
        }
        // Append the current argument to the input string
        input += argv[i];
    }

    // Check the command and apply the appropriate transformation
    if (command == "up") {
        to_upper(input); // Convert the string to uppercase
    } else if (command == "down") {
        to_lower(input); // Convert the string to lowercase
    } else {
        // Print error message for invalid command
        std::cerr << "Invalid command. Use 'up' or 'down'." << std::endl;
        return 1; // Return 1 to indicate failure
    }

    // Print the transformed string
    std::cout << input << std::endl;
    return 0; // Return 0 to indicate success
}
