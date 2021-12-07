#include "AddressBook.h"
#include <iostream>
using namespace std;

AddressBook::AddressBook( string usersFileName, string contactsFileName )
:userMenager( usersFileName ), CONTACTS_FILE_NAME( contactsFileName ){
    contactMenager = NULL;
}

void AddressBook::showAllUsers(){
    userMenager.showAllUsers();
    Sleep(2000);
}

void AddressBook::registration(){
    userMenager.registration();
}

int AddressBook::signIn(){
    int IDuser = userMenager.signIn();
    if ( IDuser > 0 ){
        contactMenager = new ContactMenager( CONTACTS_FILE_NAME, IDuser );
    }
    return IDuser;
}

int AddressBook::showNumbersOfContacts(){
    return contactMenager -> showNumbersOfContacts();
}

void AddressBook::showAllUserContacts(){
    contactMenager -> showAllUserContacts();
}
void AddressBook::addNewContact( ){
    contactMenager -> addNewContact();
}

void AddressBook::removeContact( ){
    contactMenager -> removeContact();
}
void AddressBook::editContact(){
    contactMenager -> editContact();
}

void AddressBook::changePassword( int idLoggedUser ){
    userMenager.changePassword( idLoggedUser );
}

int AddressBook::signOut(){
    int IDuser = userMenager.signOut();
    delete contactMenager;
    contactMenager = NULL;
    return IDuser;
}



