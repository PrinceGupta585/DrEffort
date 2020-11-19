#include "headers.h"

unordered_map<string, int> usage;


string getUsername();
string generateJson();
bool isDesktopAvailable();
BOOL  CALLBACK enumWindowCallback(HWND hWnd, LPARAM lparam);
void insertInMap(string appName);
void printData();
void save();
void saveMyData();
void sendData();
void sendFile();
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

string Windows_locked = "Window locked";



bool isWindowFocused(HWND hWndInput){
    if(GetForegroundWindow() == hWndInput)
        return true;
    return false;
}



const char g_szClassName[] = "myWindowClass";
string USERNAME = getUsername();






int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
HWND window;
AllocConsole();
window = FindWindowA("ConsoleWindowClass", NULL);
//ShowWindow(window,NULL);
//    String USERNAME = getUsername();
//     std::cout <<" For User: "<<USERNAME<<" Enmumerating windows..." << std::endl;
//
//string jsonOpener ="{\"data\": {\"userid\": \"";
//
//char jsonHeader[1000]="{\"data\": {\"userid\": \"a001\",\"timestamp\": \"13.0836\",\"attributes\" [{: \"80.2392\",\"ch_1\": 10.2,\"ch_2\": 34.32,\"ch_6\": 65.34";
//string jsonCloser ="]}}"
//string jsonRequest

bool alreadyPrinted = false;

for(int i=1;i<=10;i++) {
            alreadyPrinted = false;
            if(!isDesktopAvailable())
             {
                 //cout<< "user logged out"<<endl;
                 insertInMap(Windows_locked);

             }
        EnumWindows(enumWindowCallback, NULL);
        if(i && i%5==0)
        {

            //saveMyData();
            sendData();
            usage.clear();
            alreadyPrinted = true;
        }
       std::this_thread::sleep_for(std::chrono::seconds(2));
       }
       ShowWindow(window, nCmdShow);

    //std::cin.ignore();
    //if(!alreadyPrinted)
    //printData();
//    WNDCLASSEX wc;
//    HWND hwnd;
//    MSG Msg;
//
//    wc.cbSize        = sizeof(WNDCLASSEX);
//    wc.style         = 0;
//    wc.lpfnWndProc   = WndProc;
//    wc.cbClsExtra    = 0;
//    wc.cbWndExtra    = 0;
//    wc.hInstance     = hInstance;
//    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
//    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
//    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
//    wc.lpszMenuName  = NULL;
//    wc.lpszClassName = g_szClassName;
//    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
//
//    if(!RegisterClassEx(&wc))
//    {
//        MessageBox(NULL, "Window Registration Failed!", "Error!",
//            MB_ICONEXCLAMATION | MB_OK);
//        return 0;
//    }
//
//    hwnd = CreateWindowEx(
//        WS_EX_CLIENTEDGE,
//        g_szClassName,
//        "The title of my window",
//        WS_OVERLAPPEDWINDOW,
//        CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
//        NULL, NULL, hInstance, NULL);
//
//    if(hwnd == NULL)
//    {
//        MessageBox(NULL, "Window Creation Failed!", "Error!",
//            MB_ICONEXCLAMATION | MB_OK);
//        return 0;
//    }
//
//    ShowWindow(hwnd, nCmdShow);
//    UpdateWindow(hwnd);
//
//    while(GetMessage(&Msg, NULL, 0, 0) > 0)
//    {
//        TranslateMessage(&Msg);
//        DispatchMessage(&Msg);
//    }
//    return Msg.wParam;
    return 0;

}
