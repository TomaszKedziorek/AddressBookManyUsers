#include "commonFunk.h"
using namespace std;
void displayTitle( string title, bool showLine, bool screenClear ) {
    if( screenClear == true )
        system("cls");

    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 10 );
    cout<< title <<endl;
    if( showLine == false )
        cout<<"";//endl;
    else
        cout<< "------------------------------------" <<endl;
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 15 );
}
void checkFileExistence( string fileName ) {
    fstream file;
    file.open( fileName.c_str() );
    if( file.good() == false ) {
        string naglowek = "Plik o nazwie \"" + fileName + "\" nie istnieje.";
        displayTitle( naglowek, false, true );
        Sleep(1000);
    }
    file.close();
}

string IntToString( int n ){
    ostringstream ss;
    ss << n;
    string nstr=ss.str();
    return nstr;
}

string typeStringData(){
    string inputString = " ";
    getline( cin, inputString );
    return inputString;
}

