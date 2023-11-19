#include<iostream>
#include<vector>


typedef struct userAndpass{
    std::string username;
    std::string password;
}userAndpass;

std::string loginCode, userInputCode;
int userChoice;
bool Quit = false;
std::vector<userAndpass> lists;

void addPassword();
void showPasswords();
void title();

int main(){
    
    std::cout << "Create password: ";
    std::getline(std::cin, loginCode);
    std::cout << "\033[1;44mPassword created successfully\033[0m" << std::endl;
    title();
    while(!Quit){
        std::cout << "1. Add Password\n2. Show Passwords\n3. Exit" << std::endl;
        std::cout << "Enter: ";
        std::cin >> userChoice;
        std::cin.ignore();
        switch (userChoice){
        case 1:
            addPassword();
            break;
        case 2:
            showPasswords();
            break;
        case 3:
        Quit = true;
            break;
        default:
            std::cout << "Invalid Input\n";
            break;
        }
    }

}
void addPassword(){
    
    userAndpass credentials;
    std::string username, password;
    std::cout << "Enter Password: ";
    std::getline(std::cin, userInputCode);

    if (userInputCode != loginCode) {
            std::cout << "\033[1;31mIncorrect Password! Try again.\033[0m" << std::endl;
            addPassword();
    }

    else{
        std::cout << "====================================\n";
        std::cout << "           ADD PASSWORDS\n";
        std::cout << "====================================\n";
        std::cout << "Username: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> password;

        credentials.username = username;
        credentials.password = password;
        
        lists.push_back(credentials);

        std::cout << "\033[1;44mPassword added successfully!\033[0m" << std::endl;
    }
    
}
void showPasswords(){
    std::cout << "====================================\n";
    std::cout << "           YOUR PASSWORDS\n";
    std::cout << "====================================\n";

    for(userAndpass e : lists){
        std::cout << "Username: " << e.username << "| Password: " << e.password << std::endl;
    }
    std::cout << "====================================\n";
}
void title(){
   std::cout << "  ____                                                      _     __  __                                                \n"
                 " |  _ \\    __ _   ___   ___  __      __   ___    _ __    __| |   |  \\/  |   __ _   _ __     __ _    __ _    ___   _ __ \n"
                 " | |_) |  / _` | / __| / __| \\ \\ /\\ / /  / _ \\  | '__|  / _` |   | |\\/| |  / _` | | '_ \\   / _` |  / _` |  / _ \\ | '__|\n"
                 " |  __/  | (_| | \\__ \\ \\__ \\  \\ V  V /  | (_) | | |    | (_| |   | |  | | | (_| | | | | | | (_| | | (_| | |  __/ | |   \n"
                 " |_|      \\__,_| |___/ |___/   \\_/\\_/    \\___/  |_|     \\__,_|   |_|  |_|  \\__,_| |_| |_|  \\__,_|  \\__, |  \\___| |_|   \n"
                 "                                                                                                   |___/               " << std::endl;
}



