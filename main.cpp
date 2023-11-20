#include<iostream>
#include<vector>


struct userAndpass{
    std::string username;
    std::string password;
};

//Function declaration
void addPassword(std::string loginCode, std::string userInputCode, std::vector<userAndpass>& PasswordList);
void showPasswords(std::vector<userAndpass>& PasswordList);
void title();

int main(){
    
    //Declaration of variables and vector
    std::string loginCode, userInputCode;
    std::vector<userAndpass> PasswordList;
    int userChoice;
    bool quit = false;

    std::cout << "Create password: ";
    std::getline(std::cin, loginCode);
    std::cout << "\033[1;44mPassword created successfully\033[0m" << std::endl;
    title();

    //To loop until 'quit' is false
    while (!quit){
        std::cout << "1. Add Password\n2. Show Passwords\n3. Exit" << std::endl;
        std::cout << "Enter: ";
        std::cin >> userChoice;
        std::cin.ignore();

        //A switch-case for menu
        switch (userChoice){
        case 1:
            addPassword(loginCode, userInputCode, PasswordList);
            break;
        case 2:
            showPasswords(PasswordList);
            break;
        case 3:
        quit = true;
            break;
        default:
            std::cout << '\n';
            std::cout << "\033[1;31mInvalid Input!\033[0m\n";
            std::cout << '\n';
            break;
        }
    }

}

//Function to add passwords
void addPassword(std::string loginCode, std::string userInputCode, std::vector<userAndpass>& PasswordList){
    
    //Declaration of variables
    userAndpass credentials;
    std::string username, password;

    //To check if password is correct, if not -recursion
    do {
        std::cout << "Enter Password: ";
        std::getline(std::cin, userInputCode);
        if(userInputCode != loginCode)
            std::cout << "\033[1;31mIncorrect Password! Try again.\033[0m" << std::endl;
    }
    while (userInputCode != loginCode);

        //if correct, push credentials to the vector 'PasswordList'
        std::cout << "====================================\n";
        std::cout << "           ADD PASSWORDS\n";
        std::cout << "====================================\n";

        std::cout << "Username: ";
        std::getline(std::cin, credentials.username);

        std::cout << "Password: ";
        std::getline(std::cin, credentials.password);

        PasswordList.push_back(credentials);

        std::cout << "\033[1;44mPassword added successfully!\033[0m" << std::endl;
    
    
}

//Function to display all the passwords
void showPasswords(std::vector<userAndpass>& PasswordList){
    std::cout << "====================================\n";
    std::cout << "           YOUR PASSWORDS\n";
    std::cout << "====================================\n";

    for (const auto& entry : PasswordList){
        std::cout << "Username: " << entry.username << "| Password: " << entry.password << std::endl;
    }
    std::cout << "====================================\n";
}

//TItle
void title(){
   std::cout << "  ____                                                      _     __  __                                                \n"
                 " |  _ \\    __ _   ___   ___  __      __   ___    _ __    __| |   |  \\/  |   __ _   _ __     __ _    __ _    ___   _ __ \n"
                 " | |_) |  / _` | / __| / __| \\ \\ /\\ / /  / _ \\  | '__|  / _` |   | |\\/| |  / _` | | '_ \\   / _` |  / _` |  / _ \\ | '__|\n"
                 " |  __/  | (_| | \\__ \\ \\__ \\  \\ V  V /  | (_) | | |    | (_| |   | |  | | | (_| | | | | | | (_| | | (_| | |  __/ | |   \n"
                 " |_|      \\__,_| |___/ |___/   \\_/\\_/    \\___/  |_|     \\__,_|   |_|  |_|  \\__,_| |_| |_|  \\__,_|  \\__, |  \\___| |_|   \n"
                 "                                                                                                   |___/               " << std::endl;
}



