#include "headers.h"

bool isWindowFocused(HWND hWndInput);
void insertInMap(string appName);

BOOL  CALLBACK enumWindowCallback(HWND hWnd, LPARAM lparam) {

    int length = GetWindowTextLength(hWnd);
    char* buffer = new char[length + 1];
    GetWindowText(hWnd, buffer, length + 1);
    std::string windowTitle(buffer);

    // List visible windows with a non-empty title
   // if( !::IsIconic( hWnd ) ) {

    if ( isWindowFocused(hWnd)  && length != 0) {

       //cout<<"Printng IsIconic output: "<<IsIconic(hWnd)<<endl;
        //cout<<"Printng isWindowFocused: "<<isWindowFocused(hWnd)<<endl;
        insertInMap(windowTitle);
        //std::cout << hWnd << ":  " << windowTitle << std::endl;
    }
    return TRUE;
}
