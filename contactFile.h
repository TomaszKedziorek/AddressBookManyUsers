#ifndef CONTACTFILE_H
#define CONTACTFILE_H
#include "contact.h"
#include <vector>

using namespace std;

class ContactFile{
    const string bookFileName;
public:
    ContactFile( string CONTACTFILENAME );
    vector<Contact> loadBookFile( int loggedUserID, bool laodAllContacts = false );
    void saveAfterAddingContact( string oneLineContactData );
};

#endif // CONTACT_H
