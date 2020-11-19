#include "headers.h"

void saveMyData();

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{string s = "My application";
    switch(msg)
    {

        case WM_CLOSE:
        case WM_QUERYENDSESSION:
        case WM_ENDSESSION:
            saveMyData();
    if (MessageBox(hwnd, "Really quit?","My application" , MB_OKCANCEL) == IDOK)
    {
        DestroyWindow(hwnd);
    }
    break;
    // Else: User canceled. Do nothing.
   /* return 0;
    // Else: User canceled. Do nothing.
    return 0;
        case WM_ENDSESSION:
        {
            char szFileName[MAX_PATH];
            HINSTANCE hInstance = GetModuleHandle(NULL);

            GetModuleFileName(hInstance, szFileName, MAX_PATH);
            MessageBox(hwnd, szFileName, "This program is:", MB_OK | MB_ICONINFORMATION);
        }
        case WM_QUERYENDSESSION:
        {
            char szFileName[MAX_PATH];
            HINSTANCE hInstance = GetModuleHandle(NULL);

            GetModuleFileName(hInstance, szFileName, MAX_PATH);
            MessageBox(hwnd, szFileName, "This program is:", MB_OK | MB_ICONINFORMATION);
        }
        case WM_LBUTTONDOWN:
        {
            char szFileName[MAX_PATH];
            HINSTANCE hInstance = GetModuleHandle(NULL);

            GetModuleFileName(hInstance, szFileName, MAX_PATH);
            MessageBox(hwnd, szFileName, "This program is:", MB_OK | MB_ICONINFORMATION);
        }

        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;*/
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
