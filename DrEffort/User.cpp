#include <fstream>
#include <string>
#include "headers.h"

using namespace std;
string getUsername()
{
char username[UNLEN+1];
DWORD username_len = UNLEN+1;
GetUserName(username, &username_len);
return username;
}
