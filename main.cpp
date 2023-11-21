#include<iostream>
#include<vector>

struct userAndpass{
        std::string username;
        std::string password;
};
class PasswordManager{
public:
    void run();

private:
    std::string loginCode; 
    std::string userInputCode;
    std::vector<userAndpass> PasswordList;
   
    void addPassword();
    void showPasswords();
    void title();

};
int main(){
    PasswordManager manager;
    manager.run();
    return 1;
}

void PasswordManager::run(){

    std::cout << "Create password: ";
    std::getline(std::cin, loginCode);
    std::cout << "\033[1;44mPassword created successfully\033[0m" << std::endl;
    title();

    int userChoice;
    bool quit = false;

    while (!quit){
        std::cout << "1. Add Password\n2. Show Passwords\n3. Exit" << std::endl;
        std::cout << "Enter: ";
        std::cin >> userChoice;
        std::cin.ignore();

        //A switch-case for menu
        switch (userChoice){
        case 1:
            addPassword();
            break;
        case 2:
            showPasswords();
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

void PasswordManager::addPassword(){
    userAndpass credentials;
    std::string username, password;

    //To check if password is correct, if not -recursion
    do {
        std::cout << "Enter Password: ";
        std::getline(std::cin, userInputCode);
        if(userInputCode != loginCode)
            std::cout << "\033[1;31mIncorrect Password! Try again.\033[0m" << std::endl;

    } while (userInputCode != loginCode);

        //if correct, push credentials to the vector 'PasswordList'
        std::cout << "====================================\n";
        std::cout << "           ADD PASSWORDS\n";
        std::cout << "====================================\n";

        do {
            std::cout << "Username: ";
            std::getline(std::cin, credentials.username);

            if(credentials.username == ""){
                std::cout << "\033[1;31mUsername cannot be empty!\033[0m" << std::endl;
            }

        }while(credentials.username == "");

        do{
            std::cout << "Password: ";
            std::getline(std::cin, credentials.password);

            if(credentials.password == ""){
                std::cout << "\033[1;31mPassword cannot be empty!\033[0m" << std::endl;
            }

        } while(credentials.password == "");
        

        PasswordList.push_back(credentials);

        std::cout << "\033[1;44mPassword added successfully!\033[0m" << std::endl;
    
    
}

void PasswordManager::showPasswords(){
    std::cout << "====================================\n";
    std::cout << "           YOUR PASSWORDS\n";
    std::cout << "====================================\n";

    for (const auto& entry : PasswordList){
        std::cout << "Username: " << entry.username << "| Password: " << entry.password << std::endl;
    }
    std::cout << "====================================\n";
}

void PasswordManager::title(){
   std::cout << "  ____                                                      _     __  __                                                \n"
                 " |  _ \\    __ _   ___   ___  __      __   ___    _ __    __| |   |  \\/  |   __ _   _ __     __ _    __ _    ___   _ __ \n"
                 " | |_) |  / _` | / __| / __| \\ \\ /\\ / /  / _ \\  | '__|  / _` |   | |\\/| |  / _` | | '_ \\   / _` |  / _` |  / _ \\ | '__|\n"
                 " |  __/  | (_| | \\__ \\ \\__ \\  \\ V  V /  | (_) | | |    | (_| |   | |  | | | (_| | | | | | | (_| | | (_| | |  __/ | |   \n"
                 " |_|      \\__,_| |___/ |___/   \\_/\\_/    \\___/  |_|     \\__,_|   |_|  |_|  \\__,_| |_| |_|  \\__,_|  \\__, |  \\___| |_|   \n"
                 "                                                                                                   |___/               " << std::endl;
}



