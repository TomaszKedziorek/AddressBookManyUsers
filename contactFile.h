#ifndef CONTACTFILE_H
#define CONTACTFILE_H
#include "contact.h"
#include <vector>

using namespace std;

class ContactFile{
    const string BOOK_FILE_NAME;
public:
    ContactFile( string bookFileName );
    vector<Contact> loadBookFile( int loggedUserID, bool laodAllContacts = false );
    void saveAfterAddingContact( string oneLineContactData );
    void saveAfterRemovingContact( string oneLineContactData );
    void saveAfterEditing( string oneLineContactData  );
};

#endif // CONTACT_H
