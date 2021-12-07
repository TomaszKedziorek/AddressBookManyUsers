#include "contactFile.h"


ContactFile::ContactFile( string bookFileName )
    :BOOK_FILE_NAME( bookFileName ) {};

vector<Contact> ContactFile::loadBookFile( int loggedUserID, bool laodAllContacts ) {
    vector<Contact> allUserContacts;
    checkFileExistence( BOOK_FILE_NAME );
    fstream bookFile;
    bookFile.open( BOOK_FILE_NAME.c_str(), ios::in );

    string fileLine;
    int nrLine=1;
    Contact newContact;
    while( getline( bookFile, fileLine, '|') ) {
        switch( nrLine % 7 ) {
        case 1:
            newContact.setID_contact( atoi( fileLine.c_str() ) );
            break;
        case 2:
            newContact.setID_user( atoi( fileLine.c_str() ) );
            break;
        case 3:
            newContact.setName( fileLine );
            break;
        case 4:
            newContact.setSurname( fileLine );
            break;
        case 5:
            newContact.setPhone( fileLine );
            break;
        case 6:
            newContact.setEmail( fileLine );
            break;
        case 0:
            newContact.setAddress( fileLine );
            break;
        }
        switch( laodAllContacts ) {
        case false:
            if( nrLine % 7 == 0 &&  newContact.getID_user() == loggedUserID ) {
                allUserContacts.push_back( newContact );
            }
            break;
        case true:
            if( nrLine % 7 == 0 ) {
                allUserContacts.push_back( newContact );
            }
            break;
        }
        nrLine ++;
    }
    bookFile.close();
    return allUserContacts;
}

void ContactFile::saveAfterAddingContact( string oneLineContactData ) {
    fstream bookFile;

    bookFile.open( BOOK_FILE_NAME.c_str(), ios::app );
    bookFile<< oneLineContactData <<endl;

    bookFile.close();
    cout<< "Zmiany zostaly zapisane.";
    Sleep(500);
}

void ContactFile::saveAfterRemovingContact( Contact &contact ) {
    string temporaryNewFileName = BOOK_FILE_NAME.substr(0, BOOK_FILE_NAME.length() - 4) + "_Tymczasowy.txt" ;
    fstream bookFile;
    fstream temporaryBookFile;
    string fileLine;

    cout<< "Zapisuje..." <<endl;
    bookFile.open( BOOK_FILE_NAME.c_str(), ios::in );
    temporaryBookFile.open( temporaryNewFileName.c_str(), ios::out );

    while( getline( bookFile, fileLine ) ) {
        if ( atoi( fileLine.c_str() ) != contact.getID_contact()  )
            temporaryBookFile<< fileLine <<endl;
    }
    bookFile.close();
    temporaryBookFile.close();
    remove( BOOK_FILE_NAME.c_str() );
    rename( temporaryNewFileName.c_str(), BOOK_FILE_NAME.c_str() );
}
