#include "contact.h"

Contact::Contact( string n , string sn, string p, string a, int cid, int uid)
:name(n),surname(sn),phone(p),address(a),ID_contact(cid),ID_user(uid)
{}
void Contact::setName( string  contactName ){
     name = contactName; }
void Contact::setSurname( string contactSurname ){
     surname =contactSurname; }
void Contact::setPhone( string contactPhone ){
     phone = contactPhone; }
void Contact::setEmail( string contactEmail ){
     email = contactEmail; }
void Contact::setAddress( string contactAddress ){
    address = contactAddress; }
void Contact::setID_contact( int contactID_contact ){
    ID_contact = contactID_contact; }
void Contact::setID_user( int contactID_user ){
    ID_user = contactID_user;}
string Contact::getName(){
    return name; }
string Contact::getSurname(){
    return surname; }
string Contact::getPhone(){
    return phone; }
string Contact::getEmail(){
    return email; }
string Contact::getAddress(){
    return address; }
int Contact::getID_contact(){
    return ID_contact; }
int Contact::getID_user(){
    return ID_user; }

string Contact::changeContactDataToOneLine(){
    string  id_contact = IntToString( getID_contact() );
    string  id_user = IntToString( getID_user() );
    string oneLineData = id_contact + "|" + id_user + "|" + getName() +
    "|" + getSurname() + "|" + getPhone() + "|" + getEmail() + "|" +  getAddress() + "|";
    return oneLineData;
}
