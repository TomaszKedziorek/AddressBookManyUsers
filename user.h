#ifndef USER_H
#define USER_H
#include <iostream>
#include "commonFunk.h"

using namespace std;

class User{
    string login;
    string password;
    int userID;
    void showUserData();

public:
    User( string = "000", string ="000", int = 0 );
    void setLogin( string userName );
    void setPassword( string userPassword );
    void setID( int ID_user );
    string getLogin();
    string getPassword();
    int getID();
    string changeUserDataToOneLine();

    //friend vector<User>::iterator Reglog::findUserID( vector<User> &users, int IDLoggedUser );

};


#endif // USER_H
