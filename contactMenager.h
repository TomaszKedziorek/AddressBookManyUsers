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
    int loggedUserID;
    int lastContactID;
    void showFullContact( Contact &contact );
    void backToMenu();

    public:
    ContactMenager( string contactBookName );
    void setIDLggedUser( int idUser );
    int getIDLoggedUser();
    void loadContactFromFile();
    void showAllUserContacts();
    void addNewContact( );

};
#endif // CONTACTMENAGER_H
