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

