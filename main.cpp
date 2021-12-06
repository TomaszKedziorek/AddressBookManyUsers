#include <iostream>
#include "commonFunk.h"
#include "AddressBook.h"
#include "User.h"
#include "userMenager.h"
#include "contact.h"
#include "contactMenager.h"


using namespace std;

int main()
{
    ContactMenager contact( "ksiazkaAdresowa.txt" );
    contact.setIDLggedUser( 6 );
    contact.loadContactFromFile();
    contact.showAllUserContacts();
    contact.addNewContact();
    contact.showAllUserContacts();

    AddressBook addressBook( "wszyscyUzytkownicy.txt" );
    //addressBook.showAllUsers();

    //addressBook.registration();
    addressBook.showAllUsers();

    int id=addressBook.signIn();
    cout<<id<<endl;
    if (id!=0)
        addressBook.changePassword( id );
    cout<<addressBook.signOut();
    return 0;
}
