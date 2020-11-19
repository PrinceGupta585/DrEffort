#include "headers.h"

void printData()
{
    //cout<<"inside printData"<<endl;
    int count=1;
     for(auto i= usage.begin() ; i!=usage.end();i++)
     {
         cout<<count<<". The application used: "<<i->first<<endl;
         cout<<" The time it has been used in last 1 hour: "<<i->second<<" sec"<<endl;
         cout<<endl;
         cout<<endl;
         count++;
     }

}
