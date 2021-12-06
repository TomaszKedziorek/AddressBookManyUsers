#include "contactFile.h"


ContactFile::ContactFile( string CONTACTFILENAME )
:bookFileName( CONTACTFILENAME ){};

vector<Contact> ContactFile::loadBookFile( int loggedUserID, bool laodAllContacts ){
    vector<Contact> allUserContacts;
    checkFileExistence( bookFileName );
    fstream bookFile;
    bookFile.open( bookFileName.c_str(), ios::in );

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

void ContactFile::saveAfterAddingContact( string oneLineContactData ){
    fstream bookFile;

    bookFile.open( bookFileName.c_str(), ios::app );
    bookFile<< oneLineContactData <<endl;

    bookFile.close();
    cout<< "Zmiany zostaly zapisane.";
    Sleep(500);
}
