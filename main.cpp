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
    AddressBook addressBook( "wszyscyUzytkownicy.txt", "ksiazkaAdresowa.txt" );
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
                while( IDuser > 0) {
                    displayTitle( "   Ksiazka Adresowa", true, true );
                    displayTitle( "Zalogowany: ", false, false );
                    cout<<  "ID: " << IDuser;
                    cout<< "\tLiczba kontaktow:" << addressBook.showNumbersOfContacts();
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

                    choise2 = cin.get();
                    switch( choise2 ) {
                    case '1':
                        addressBook.showAllUserContacts();
                        break;
                    case '2':
                        addressBook.addNewContact();
                        break;
                    case '3':
                        addressBook.findContactByName();
                        break;
                    case '4':
                        addressBook.findContactBySurname();
                        break;
                    case '6':
                        addressBook.editContact();
                        break;
                    case '7':
                        addressBook.removeContact();
                        break;
                    case '8':
                        addressBook.changePassword( IDuser );
                        break;
                    case '9':
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
