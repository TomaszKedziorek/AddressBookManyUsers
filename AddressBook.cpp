#include "AddressBook.h"
#include <iostream>
using namespace std;

AddressBook::AddressBook( string usersFileName )
:userMenager( usersFileName ){
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

void AddressBook::changePassword( int idLoggedUser ){

    userMenager.changePassword( idLoggedUser );
}

int AddressBook::signOut(){
    return userMenager.signOut();
}



