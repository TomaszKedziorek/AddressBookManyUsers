#include <iostream>
#include "commonFunk.h"
#include "AddressBook.h"
#include "User.h"
#include "userMenager.h"
#include "contact.h"
#include "contactMenager.h"


using namespace std;

int main() {
    char choice1, choise2;
    int IDuser = 0;
    AddressBook addressBook( "wszyscyUzytkownicy.txt" );
    while( true ) {
        if( IDuser == 0) {
            displayTitle( "   Ksiazka Adresowa" );
            cout<< "1. Rejestracja." <<endl;
            cout<< "2. Logowanie." <<endl;
            cout<< "9. Wyjscie." <<endl;
            choice1 = getch();

            switch( choice1 ) {
            case '1':
                addressBook.registration();
                break;
            case '2':
                IDuser = addressBook.signIn();
                ContactMenager *contactMenager;
                contactMenager = NULL;

                while( IDuser > 0) {
                    contactMenager = new ContactMenager( "ksiazkaAdresowa.txt", IDuser );
                    displayTitle( "   Ksiazka Adresowa", true, true );
                    displayTitle( "Zalogowany: ", false, false );
                    cout<<  "\tID: " << IDuser;
                    cout<< "\tLiczba kontaktow:" << contactMenager -> showNumbersOfContacts();
                    displayTitle( "", true, false );
                    cout<< "1. Wyswitl wszystko." <<endl;
                    cout<< "2. Dodaj nowy kontakt." <<endl;
                    cout<< "3. Wyszukaj po imieniu." <<endl;
                    cout<< "4. Wyszukaj po nazwisku." <<endl;
                    cout<< "6. Edytuj kontakt." <<endl;
                    cout<< "7. Usun kontakt." <<endl;
                    cout<< "8. Zmien haslo." <<endl;
                    cout<< "9. Wyloguj sie." <<endl;
                    cout<< "Twoj wybor:";

                    choise2 = getch();
                    switch( choise2 ) {
                    case '1':
                        contactMenager -> showAllUserContacts();
                        break;
                    case '2':
                        contactMenager -> addNewContact();
                        break;
                    case '3':
                        break;
                    case '4':
                        break;
                    case '6':
                        break;
                    case '7':
                        break;
                    case '8':
                        addressBook.changePassword( IDuser );
                        break;
                    case '9':
                        delete contactMenager;
                        contactMenager = NULL;
                        IDuser = addressBook.signOut();
                        break;
                    }
                }
                break;

            case '9':
                exit( 0 );
                break;
            }
        }
    }
    return 0;
}

int _main() {
    AddressBook addressBook( "wszyscyUzytkownicy.txt" );
    addressBook.showAllUsers();
    addressBook.registration();
    int i =0;
    while( i< 4) {
        int id = addressBook.signIn();
        if (id!=0) {
            ContactMenager contact( "ksiazkaAdresowa.txt" );
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
