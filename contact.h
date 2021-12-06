#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include "commonFunk.h"

class Contact {
    string name;
    string surname;
    string phone;
    string email;
    string address;
    int ID_contact;
    int ID_user;

public:
    Contact( string = "none",string = "none",string = "none",string = "none",int = 0, int=0 );
    void setName( string  contactName );
    void setSurname( string contactSurname );
    void setPhone( string contactPhone );
    void setEmail( string contactEmail );
    void setAddress( string contactAddress );
    void setID_contact( int contactID_contact );
    void setID_user( int contactID_user );
    string getName();
    string getSurname();
    string getPhone();
    string getEmail();
    string getAddress();
    int getID_contact();
    int getID_user();
    string changeContactDataToOneLine();
};


#endif // CONTACT_H

