#include "headers.h"

void insertInMap(string appName)
{
    if(usage.find(appName)!=usage.end())
            usage[appName]++;
        usage.insert(make_pair(appName,1));
}
