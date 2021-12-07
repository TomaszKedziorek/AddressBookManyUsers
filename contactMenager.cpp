#include "contactMenager.h"
ContactMenager::ContactMenager( string contactBookName, int loggedUserID )
:CONTACTS_FILE_NAME(contactBookName),contactFile( contactBookName ),LOGGED_USER_ID(loggedUserID){
     vector<Contact> allContactsFromFile = contactFile.loadBookFile( 0, true );
     if( allContactsFromFile.empty() )
        lastContactID = 0;
     else{
        lastContactID = allContactsFromFile.back().getID_contact();
        loadContactFromFile();
     }
    allContactsFromFile.clear();
}


int ContactMenager::getIDLoggedUser(){
    return LOGGED_USER_ID;
}

void ContactMenager::loadContactFromFile( ){
    contacts = contactFile.loadBookFile( getIDLoggedUser() );
}

void ContactMenager::showFullContact( Contact &contact ){
    cout<< contact.getName() << " " << contact.getSurname() <<endl;
    cout<< "tel.: " << contact.getPhone() << " email: " << contact.getEmail() <<endl;
    cout<< contact.getAddress() <<endl;
    cout<< "ID: "<< contact.getID_contact() <<endl;
}

void ContactMenager::showAllUserContacts(){
    displayTitle( "   Wszystkie kontakty." );
    for( unsigned int i=0; i<contacts.size(); i++ ) {
        showFullContact( contacts[i] );
        displayTitle( "------------------------------------", false, false );
    }
    backToMenu();
}

void ContactMenager::backToMenu() {
    cout<< "Wcisnij dowolny klawisz aby wrocic do menu." <<endl;
    getch();
}
int ContactMenager::showNumbersOfContacts(){
    return contacts.size();
}

int ContactMenager::getLastContactID(){
    return lastContactID;
}

void ContactMenager::setLastContactID(){
    lastContactID++;
}

void ContactMenager::addNewContact( ){
    string name,surname,email,address,phone;
    int newContactID;
    displayTitle( "   Dodaj nowy kontakt." );

    cout<< "Imie: ";
    cin>> name ;
    cin.ignore();
    cout<< "Nazwisko: ";
    getline( cin, surname );
    cout<< "Telefon: ";
    getline( cin, phone );
    cout<< "email: ";
    getline( cin, email );
    cout<< "Adres: ";
    getline( cin, address );
    newContactID = getLastContactID() +1;
    setLastContactID();

    Contact newContact;
    newContact.setName( name );
    newContact.setSurname( surname );
    newContact.setPhone( phone );
    newContact.setEmail( email );
    newContact.setAddress( address );
    newContact.setID_contact( newContactID );
    newContact.setID_user( LOGGED_USER_ID );

    contacts.push_back( newContact );
    contactFile.saveAfterAddingContact( newContact.changeContactDataToOneLine() );
}

void ContactMenager::confirmRemoving( vector<Contact>::iterator &contactToRemove ) {
    char yesNo;
    do {
        cout<< "t/n ";
        cin>> yesNo;
        if( yesNo == 't' ) {
            contactFile.saveAfterRemovingContact( contactToRemove -> changeContactDataToOneLine()  );
            contacts.erase( contactToRemove );
            cout<< "Usunieto." <<endl;
            Sleep(500);
        } else if( yesNo == 'n' ) {
            cout<< "Nie usunieto." <<endl;
            Sleep(500);
        } else
            continue;
    } while( yesNo != 't' && yesNo != 'n' );
}

void ContactMenager::removeContact( ) {
    string nameToRemove,surnameToRemove;
    int idToRemove;
    char choice;
    int numberOfFoundContacts = 0;

    displayTitle( "   Usun kontakt.");
    cout<< "1. Wedlug imienia i naywiska.\n2. Wedlug ID." <<endl;
    choice = getch();
    switch(choice) {
    case '1': {
        cout<< "Wpisz imie i nazwisko kontaktu do usuniecia." <<endl;
        cout<< "Imie: " ;
        cin>> nameToRemove;
        cin.ignore();
        cout<< "Nazwisko: ";
        getline( cin, surnameToRemove);
        break;
    }
    case '2': {
        cout<< "Wpisz ID kontaktu do usuniecia." <<endl;
        cin>> idToRemove;
        break;
    }
    }
    vector<Contact>::iterator contactToRemove = contacts.begin();
    for( unsigned int i=0; i<contacts.size(); i++ ) {
        if( ( contacts[i].getName() == nameToRemove && contacts[i].getSurname() == surnameToRemove) || (contacts[i].getID_contact() == idToRemove) ) {
            displayTitle( "Czy napewno chcesz usunicto ten kontakt?", false, false );
            showFullContact( contacts[i] );
            displayTitle( "------------------------------------", false, false );
            confirmRemoving( contactToRemove );
            numberOfFoundContacts++;
            ++contactToRemove;
        } else {
            ++contactToRemove;
        }
    }
    if( numberOfFoundContacts == 0 ) {
        cout<< "Nie ma takiego kontaktu";
        Sleep(1000);
    }
}

vector<Contact>::iterator ContactMenager::findContactByID( int idOfSearchedContact ) {
    vector<Contact>::iterator searchedContact = contacts.begin();
    vector<Contact>::iterator vectorEnd = contacts.end();
    while( searchedContact != vectorEnd ) {
        if( searchedContact-> getID_contact() == idOfSearchedContact )
            break;
        ++searchedContact;
    }
    return searchedContact;
}

void ContactMenager::editContact() {
    char choice;
    int idEditedContact;
    string newData;
    displayTitle( "   Edytuj kontakt.");
    displayTitle( "Podaj ID kontaktu do edycji: ", false, false);
    cin>> idEditedContact;
    vector<Contact>::iterator contactToEdit = findContactByID( idEditedContact );
    if( contactToEdit == contacts.end() ) {
        cout<< "Nie ma kontaktu o ID: " << idEditedContact <<endl;
        Sleep(1000);
    } else {
        showFullContact( (*contactToEdit) );
        displayTitle( "------------------------------------", false, false );
        cout<<"1. Imie\n2. Nazwisko\n3. Numer telefonu\n4. email\n5. Adres\n6. Powrot do menu" <<endl;
        choice = getch();
        if( choice != '6') {
            cout<< "Wpisz nowe: " <<endl;
            cin.ignore();
            getline(cin, newData);
        }
        switch( choice ) {
        case '1':
            contactToEdit->setName( newData );
            break;
        case '2':
            contactToEdit->setSurname( newData );
            break;
        case '3':
            contactToEdit->setPhone( newData );
            break;
        case '4':
            contactToEdit->setEmail( newData );
            break;
        case '5':
            contactToEdit->setAddress( newData );
            break;
        case '6':
            backToMenu();
            break;
        }
        if( choice != '6') {
            displayTitle( "Kontakt po edycji:", false, false );
            showFullContact( (*contactToEdit) );
            Sleep(1500);
            contactFile.saveAfterEditing( contactToEdit -> changeContactDataToOneLine()  );
        }
    }
}
