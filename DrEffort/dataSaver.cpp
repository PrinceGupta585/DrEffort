#include "headers.h"

string generateJson();

void save(){
    char fileName[] ="usage.json";
    ifstream file(fileName);
    if(file){
            cout<<"deleting existing file..."<<endl;
            remove(fileName);
    }
    ofstream myfile (fileName);

   // std::unordered_map<string, int>::iterator iter;
  if (myfile.is_open())
  {
      string usageData = generateJson();
      myfile<<usageData;
     /*for(iter=usage.begin(); iter!=usage.end(); iter++){
        myfile<<(iter->first)<<":";
        myfile<<(iter->second)<<";";*/
    //}
    myfile.close();
  }
  else cout << "Unable to open file";

}

/*void load(){
    string line;
  ifstream myfile ("usage.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      std::istringstream key(line,:);
      std::istringstream val(line,;);
      usage.insert(make_pair((string)key,(int)val));
    }
    myfile.close();
  }

  else cout << "Unable to open file";
    FILE *f = fopen("map", "rb");
    string key;
    int val;
    while(fread(&key, 8, 1, f)){
        fread(&val, 1, 1, f);
        usage.insert(make_pair(key,val));
    }
    fclose(f);
}*/
void saveMyData()
{
    std::cout<<"saving data..."<<endl;
    save();
}
void sendData()
{
     string usageData = generateJson();
     string YOUR_URI = "www.youtube.com";
     //curl -X POST http://www.yourwebsite.com/login/ -d 'username=yourusername&password=yourpassword'
     std::string command = "curl -H \"Content-Type: application/json\" -X POST http://www.yourwebsite.com/login/ -d @usage.json ";

     system(command.c_str());
     //system("curl -X PUT -H Content-Type: application/json -d ${usageData} YOUR_URI");
}
void sendFile()
{
    string usageData = generateJson();
     string YOUR_URI = "www.youtube.com";
     system("curl -X PUT -H Content-Type: application/json -d @usage.json YOUR_URI");
}
