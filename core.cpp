#include <iostream>
#include <unordered_set>
#include <string>

// Function to generate a nickname
std::string generateNickname(const std::string& profession, const std::string& firstName, const std::string& lastName, std::unordered_set<std::string>& nicknameDatabase) {
    // Combine short form of profession with the first index of the first name and last name
    std::string shortProfession = "";
    if (profession.length() > 0) {
        shortProfession = profession.substr(0, 1);
    }

    std::string nickname = shortProfession + firstName.substr(0, 1) + lastName.substr(0, 1);

    // Ensure nickname is unique by appending numbers if necessary
    int counter = 1;
    std::string originalNickname = nickname;
    while (nicknameDatabase.find(nickname) != nicknameDatabase.end()) {
        nickname = originalNickname + std::to_string(counter);
        counter++;
    }

    // Add the generated nickname to the database
    nicknameDatabase.insert(nickname);

    return nickname;
}

int main() {
    // Database to store generated nicknames
    std::unordered_set<std::string> nicknameDatabase;

    // Example usage
    std::string profession = "Developer";
    std::string firstName = "John";
    std::string lastName = "Doe";

    // Generate and print the nickname
    std::string nickname = generateNickname(profession, firstName, lastName, nicknameDatabase);
    std::cout << "Generated Nickname: " << nickname << std::endl;

    return 0;
}
