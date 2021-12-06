#include <iostream>
#include "commonFunk.h"
#include "AddressBook.h"
#include "User.h"
#include "userMenager.h"
#include "contact.h"
#include "contactMenager.h"


using namespace std;

int main() {
    AddressBook addressBook( "wszyscyUzytkownicy.txt" );
    addressBook.showAllUsers();
    addressBook.registration();
    int i =0;
    while( i< 4) {
        int id = addressBook.signIn();
        if (id!=0) {
            ContactMenager contact( "ksiazkaAdresowa.txt" );
            contact.setIDLggedUser( id );
            contact.loadContactFromFile();
            contact.showAllUserContacts();
            contact.addNewContact();
            contact.showAllUserContacts();
            addressBook.changePassword( id );
            addressBook.signOut();
        }
        i++;
    }

    return 0;
}
