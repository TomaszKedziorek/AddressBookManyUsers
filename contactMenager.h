#ifndef CONTACTMENAGER_H
#define CONTACTMENAGER_H
#include <iostream>
#include "commonFunk.h"
#include "contact.h"
#include "contactFile.h"
#include <vector>
#include <conio.h>

class ContactMenager{
    vector<Contact> contacts;
    ContactFile contactFile;
    const int LOGGED_USER_ID;
    int lastContactID;
    void showFullContact( Contact &contact );
    void backToMenu();
    void loadContactFromFile();
    int getLastContactID();
public:
    ContactMenager( string contactBookName ="ksiazkaAdresowa.txt", int loggedUserID = 0 );
    int getIDLoggedUser();
    int showNumbersOfContacts();
    void showAllUserContacts();
    void addNewContact( );

};
#endif // CONTACTMENAGER_H
