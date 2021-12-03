#include "usersFile.h"
#include "commonFunk.h"
#include "user.h"

UsersFile::UsersFile( string fileName ) {
    usersFileName = fileName;
}

void UsersFile::setUsersFileName( string fileName ) {
    usersFileName = fileName;
}

string UsersFile::getUsersFileName() {
    return usersFileName;
}

vector<User> UsersFile::loadUsersFile( ) {
    checkFileExistence( usersFileName );
    fileUsers.open( usersFileName.c_str(), ios::in );
    string fileLine;
    int nrLine=1;
    vector<User> loadedUsers;
    User newUser;
    while( getline( fileUsers, fileLine, '|') ) {
        switch( nrLine % 3 ) {
        case 1:
            newUser.setID( atoi( fileLine.c_str() ) );
            break;
        case 2:
            newUser.setLogin( fileLine.c_str()  );
            break;
        case 0:
            newUser.setPassword( fileLine.c_str()  );
            break;
        }
        if( nrLine % 3 == 0 ) {
            loadedUsers.push_back( newUser );
        }
        nrLine++;
    }
    fileUsers.close();
    return loadedUsers;
}

void UsersFile::saveNewUser( string userOneLineData ) {
    fileUsers.open( usersFileName.c_str(),  ios::app );
    fileUsers<< userOneLineData <<endl;
    fileUsers.close();
}

void UsersFile::saveAfterPasswordChange ( string userOneLineData, int userID ) {
    string temporaryFileName = usersFileName.substr(0, usersFileName.length() - 4) + "_Tymczasowy.txt" ;
    fstream tempUsersFile;

    string fileLine;
    fileUsers.open( usersFileName.c_str(),  ios::in );
    tempUsersFile.open( temporaryFileName.c_str(),  ios::out );

    while( getline( fileUsers, fileLine ) ) {
        if( atoi( fileLine.c_str() ) == userID ) {
            tempUsersFile<< userOneLineData <<endl;
        } else {
            tempUsersFile<< fileLine <<endl;
        }
    }
    tempUsersFile.close();
    fileUsers.close();
    remove( usersFileName.c_str() );
    rename( temporaryFileName.c_str(), usersFileName.c_str() );
}
