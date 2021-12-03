#include "AddressBook.h"
#include <iostream>
using namespace std;

AddressBook::AddressBook(){
    userMenager.loadUsersFromFile();

}
void AddressBook::showAllUsers(){
    userMenager.showAllUsers();
    Sleep(2000);
}

void AddressBook::registration(){
    userMenager.registration();
}

int AddressBook::signIn(){
    return userMenager.signIn();
}





