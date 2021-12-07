#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <iostream>
#include "user.h"
#include "userMenager.h"
#include "contactMenager.h"
using namespace std;

class AddressBook{
    UserMenager userMenager;
    ContactMenager *contactMenager;
    const string CONTACTS_FILE_NAME;
    void showAllUsers();
public:
    AddressBook( string usersFileName ="wszyscyUzytkownicy.txt", string contactsFileName ="ksiazkaAdresowa.txt" );
    ~AddressBook(){
        delete contactMenager;
        contactMenager = NULL;
    };
    void registration();
    int signIn();
    int showNumbersOfContacts();
    void showAllUserContacts();
    void addNewContact( );
    void changePassword( int idLoggedUser );
    void editContact();
    void removeContact( );
    void findContactByName();
    void findContactBySurname();
    int signOut();


};



#endif //ADDRESSBOOK_H
