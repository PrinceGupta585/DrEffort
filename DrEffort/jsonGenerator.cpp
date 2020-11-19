#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
#include <wtsapi32.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <utility>
#include <windows.h>
#include <Lmcons.h>
#include <fstream>
#include <iomanip>
#include "globalMap.h"

using namespace std;
string getUsername();


string generateDynamicPartJson()
{
     string usageData;
     for(auto app= usage.begin() ; app!=usage.end();app++)
     {
         //char temp[1000];
         string title = app->first;
         int timeUsed = app->second;
         //cout<<title<<endl;

          string data = "{\"windowsTitle\" : \"" + title + "\", \"usage\" : \"" + to_string(timeUsed) + "\" },";

          usageData = usageData + data + "\r";
     }

     return usageData;
}
string generateJson()
{
    string json;
    string jsonOpener ="{\"data\": {\"userid\": \"";
    string USERNAME = getUsername();
    jsonOpener = jsonOpener + USERNAME +"\",";


    time_t now = time(0);

   // convert now to string form
   string dt = ctime(&now);
  //cout << "Number of sec since January 1,1970 is:: " << now << endl;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    //std::cout << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S.%z%Z") << "\n";
    string timestampBuilder = "\"timestamp\" : \"";
    stringstream timestamp;
    timestamp<< put_time(&tm, "%d-%m-%Y %H:%M:%S");
    timestampBuilder += timestamp.str();
    //timestampBuilder.append(dt);
    timestampBuilder += "\", ";
    string timeStamp = timestampBuilder;
    string usageData = generateDynamicPartJson();
    string jsonCloser ="]}}";

    json = jsonOpener + timeStamp+ "\"attributes\" : [ " + usageData + jsonCloser;
    return json;
}
