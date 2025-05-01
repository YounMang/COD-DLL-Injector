#include <Windows.h>
#include <string>
#include <vector>
#include <cstdio>
#include <array>
#include <fstream>
#include <filesystem>
#include "define/stdafx.h"
#include "api/xor.h"
#include <iostream>
#include <conio.h>
#include "api/api.h"
#include "cheat.h"
#include "driver/driver.h"
#include "inject/injector.h"
#include "api/drvutils.h"
#include "auth.hpp"
#include "skStr.h"
#pragma comment(lib, "urlmon.lib")

using namespace KeyAuth;

auto name = skCrypt("YOUR_NAME");
auto ownerid = skCrypt("YOUR_ID");
auto secret = skCrypt("YOUR_SECRET");
auto version = skCrypt("2.8");
auto url = skCrypt("https://keyauth.win/api/1.2/"); // change if you're self-hosting

api KeyAuthApp(name.decrypt(), ownerid.decrypt(), secret.decrypt(), version.decrypt(), url.decrypt());

HWND window;
enum class ColorTable : WORD
{
    Blue = 1,
    Green,
    Cyan,
    Red,
    Purple,
    YellowDark,
    Defaultwhite,
    Grey,
    Brightblue,
    Brigthgreen,
    Brightcyan,
    Brightred,
    PinkMagenta,
    Yellow,
    Brightwhite
};

void textColor(ColorTable color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)color);

}

void CreateConsole()
{
    if (!AllocConsole()) {
        // Add some error handling here.
        // You can call GetLastError() to get more info about the error.
        return;
    }

    // std::cout, std::clog, std::cerr, std::cin
    FILE* fDummy;
    freopen_s(&fDummy, "CONOUT$", "w", stdout);
    freopen_s(&fDummy, "CONOUT$", "w", stderr);
    freopen_s(&fDummy, "CONIN$", "r", stdin);
    std::cout.clear();
    std::clog.clear();
    std::cerr.clear();
    std::cin.clear();

    // std::wcout, std::wclog, std::wcerr, std::wcin
    HANDLE hConOut = CreateFile(("CONOUT$"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    HANDLE hConIn = CreateFile(("CONIN$"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    SetStdHandle(STD_OUTPUT_HANDLE, hConOut);
    SetStdHandle(STD_ERROR_HANDLE, hConOut);
    SetStdHandle(STD_INPUT_HANDLE, hConIn);
    std::wcout.clear();
    std::wclog.clear();
    std::wcerr.clear();
    std::wcin.clear();
}

void remove_scrollbar()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}

static void SetConsoleOnTop()
{
    HWND consoleWindowHandle = GetConsoleWindow();
    if (consoleWindowHandle)
    {
        SetWindowPos(consoleWindowHandle, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
        ShowWindow(consoleWindowHandle, SW_NORMAL);
    }
}

void MakeSexy()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    HWND handle = GetConsoleWindow();
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_EX_RIGHTSCROLLBAR & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX & ~WS_MINIMIZEBOX);
    HANDLE hInput;
    DWORD prev_mode;
    hInput = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hInput, &prev_mode);
    SetConsoleMode(hInput, prev_mode & ENABLE_EXTENDED_FLAGS);
    HWND consoleWindowHandle = GetConsoleWindow();
    if (consoleWindowHandle)
    {
        SetWindowPos(
            consoleWindowHandle,
            HWND_TOPMOST,
            0, 0,
            0, 0,
            SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW
        );
        ShowWindow(
            consoleWindowHandle,
            SW_NORMAL
        );
    }
    SetConsoleOnTop();

}
auto rndmTitle() -> void {
    constexpr int length = 15;
    const auto characters = TEXT("TD Cheats |");
    TCHAR title[length + 1]{};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100, 199);

    while (true) {
        for (int j = 0; j < length; j++) {
            title[j] += characters[dis(gen)];
        }

        SetConsoleTitle(title);
        std::this_thread::sleep_for(std::chrono::milliseconds(9000)); // Adjust the delay as needed
    }
}
HWND consoleWindow = GetConsoleWindow();
auto SetConsoleSize() -> void {
    HANDLE hOut;
    SMALL_RECT DisplayArea = { 0, 0, 0, 0 };
    int x = 60;
    int y = 20;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DisplayArea.Right = x;
    DisplayArea.Bottom = y;
    SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
}

void logo3()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    SetConsoleTextAttribute(hConsole, 9);
    std::cout <<
        R"(
                            Call of Duty MW3 (Version: 1.2)

 $$$$$$\ $$\   $$\    $$$$$\ $$$$$$$$\  $$$$$$\ $$$$$$$$\  $$$$$$\  $$$$$$$\  
 \_$$  _|$$$\  $$ |   \__$$ |$$  _____|$$  __$$\\__$$  __|$$  __$$\ $$  __$$\ 
   $$ |  $$$$\ $$ |      $$ |$$ |      $$ /  \__|  $$ |   $$ /  $$ |$$ |  $$ |
   $$ |  $$ $$\$$ |      $$ |$$$$$\    $$ |        $$ |   $$ |  $$ |$$$$$$$  |
   $$ |  $$ \$$$$ |$$\   $$ |$$  __|   $$ |        $$ |   $$ |  $$ |$$  __$$< 
   $$ |  $$ |\$$$ |$$ |  $$ |$$ |      $$ |  $$\   $$ |   $$ |  $$ |$$ |  $$ |
 $$$$$$\ $$ | \$$ |\$$$$$$  |$$$$$$$$\ \$$$$$$  |  $$ |    $$$$$$  |$$ |  $$ |
 \______|\__|  \__| \______/ \________| \______/   \__|    \______/ \__|  \__|

     Copyright: 2020-2025. All rights reserved.

        )";
}

HWND console = GetConsoleWindow();
int main()
{
    std::thread hot(MakeSexy);
    std::thread titleThread(rndmTitle);
    logo3();
    start_driver();
    CreateConsole();
    
    // Set the window style to allow transparency
    LONG_PTR windowStyle = GetWindowLongPtr(consoleWindow, GWL_EXSTYLE);
    SetWindowLongPtr(consoleWindow, GWL_EXSTYLE, windowStyle | WS_EX_LAYERED);
    int opacity = 225; // Adjust this value as needed
    SetLayeredWindowAttributes(consoleWindow, 0, opacity, LWA_ALPHA);
    SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);


    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo);

    COORD new_screen_buffer_size;

    new_screen_buffer_size.X = screenBufferInfo.srWindow.Right -
        screenBufferInfo.srWindow.Left + 1;
    new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom -
        screenBufferInfo.srWindow.Top + 1;

    SetConsoleScreenBufferSize(hConsole, new_screen_buffer_size);

    while (true)
    {
        
        cout << "\r [+] Press F2 in lobby To inject.";

        if (GetAsyncKeyState(VK_F2) & true)
        {
            Kernel_Injector("Call of Duty® HQ", reinterpret_cast<BYTE*>(&rawData));

            Sleep(1000);
            exit(0);

        }
    }
    return TRUE;
}

	
       
