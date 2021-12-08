//#include <iostream>
#include "user.h"

using namespace std;

User::User( string log, string pass, int id ) {
    login = log;
    password = pass;
    userID = id;
}

void User::setLogin( string userName ) {
    login = userName;
}

void User::setPassword( string userPassword ) {
    password = userPassword;
}

void User::setID( int ID_user) {
    userID = ID_user;
}

void User::showUserData() {
    cout<< login << " " << password <<endl;
    cout<< "ID: "<< userID <<endl;
}
string User::getLogin() {
    return login;
}

string User::getPassword() {
    return password;
}
int User::getID() {
    return userID;
}
string User::changeUserDataToOneLine() {
    int id = getID();
    return IntToString( id ) + "|" + getLogin() + "|" + getPassword() + "|";
}
