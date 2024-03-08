// i needed to organize customloadinglayer.cpp
#include <Geode/Geode.hpp>
#include <Geode/Bindings.hpp>
#include "CustomLoadingLayer.hpp"
#include "LoadingLayerEditor.hpp"
#include <Windows.h> // who cares about cross platform anyway (jk ill look into mobile support soon, we dont talk about mac.)
#include <cocos2d.h>
#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>

using namespace geode::prelude;

// think of this as a house, the structure is CCMenuItemSpriteExtra, the decoration is ButtonSprite, the electricity is whatever is down below
// dont mind the copy pasting
void LoadingLayerEditor::onBG(CCObject* sender) {
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

    OPENFILENAMEW ofn;
    wchar_t szFile[MAX_PATH] = L"";

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = L'\0';
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = L"PNG Files\0*.png\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;

    if (GetOpenFileNameW(&ofn) == TRUE) {
        std::wstring wstrFilePath = ofn.lpstrFile;

        std::filesystem::path filePath(wstrFilePath);
        std::string fileName = filePath.filename().string();

        std::string saveDir = Mod::get()->getSaveDir().string();

        std::wstring destFilePath = std::wstring(saveDir.begin(), saveDir.end()) + L"\\BG.png";



        std::ifstream source(wstrFilePath, std::ios::binary);
        std::ofstream dest(destFilePath, std::ios::binary);
        dest << source.rdbuf();

        source.close();
        dest.close();

        Notification::create("File copied successfully to the save directory.")->show();
    }

    CoUninitialize();
}

void LoadingLayerEditor::onGJLogoSpr(CCObject* sender) {
    
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

    
    OPENFILENAMEW ofn;
    wchar_t szFile[MAX_PATH] = L"";

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = L'\0';
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = L"PNG Files\0*.png\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;


    if (GetOpenFileNameW(&ofn) == TRUE) {
        std::wstring wstrFilePath = ofn.lpstrFile;


        std::filesystem::path filePath(wstrFilePath);
        std::string fileName = filePath.filename().string();


        std::string saveDir = Mod::get()->getSaveDir().string();

        std::wstring destFilePath = std::wstring(saveDir.begin(), saveDir.end()) + L"\\GJLogo.png";



        std::ifstream source(wstrFilePath, std::ios::binary);
        std::ofstream dest(destFilePath, std::ios::binary);
        dest << source.rdbuf();

        source.close();
        dest.close();

        Notification::create("File copied successfully to the save directory.")->show();
    }

    CoUninitialize();
}

void LoadingLayerEditor::onRobert(CCObject* sender) {
    
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

    
    OPENFILENAMEW ofn;
    wchar_t szFile[MAX_PATH] = L"";

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = L'\0';
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = L"PNG Files\0*.png\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;


    if (GetOpenFileNameW(&ofn) == TRUE) {
        std::wstring wstrFilePath = ofn.lpstrFile;


        std::filesystem::path filePath(wstrFilePath);
        std::string fileName = filePath.filename().string();


        std::string saveDir = Mod::get()->getSaveDir().string();

        std::wstring destFilePath = std::wstring(saveDir.begin(), saveDir.end()) + L"\\RobTopLogo.png"; // Convert saveDir to wide string, concatenate with filename



        std::ifstream source(wstrFilePath, std::ios::binary);
        std::ofstream dest(destFilePath, std::ios::binary); // Use wide string for the destination file path
        dest << source.rdbuf();

        source.close();
        dest.close();

        Notification::create("File copied successfully to the save directory.")->show();
    }

    CoUninitialize();
}

void LoadingLayerEditor::onCocos(CCObject* sender) {
    
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

    
    OPENFILENAMEW ofn;
    wchar_t szFile[MAX_PATH] = L"";

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = L'\0';
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = L"PNG Files\0*.png\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;


    if (GetOpenFileNameW(&ofn) == TRUE) {
        std::wstring wstrFilePath = ofn.lpstrFile;


        std::filesystem::path filePath(wstrFilePath);
        std::string fileName = filePath.filename().string();


        std::string saveDir = Mod::get()->getSaveDir().string();

        std::wstring destFilePath = std::wstring(saveDir.begin(), saveDir.end()) + L"\\Cocos.png"; // Convert saveDir to wide string, concatenate with filename



        std::ifstream source(wstrFilePath, std::ios::binary);
        std::ofstream dest(destFilePath, std::ios::binary);
        dest << source.rdbuf();

        source.close();
        dest.close();

        Notification::create("File copied successfully to the save directory.")->show();
    }

    CoUninitialize();
}

void LoadingLayerEditor::onFMod(CCObject* sender) {
    
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

    
    OPENFILENAMEW ofn;
    wchar_t szFile[MAX_PATH] = L"";

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = L'\0';
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = L"PNG Files\0*.png\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;


    if (GetOpenFileNameW(&ofn) == TRUE) {
        std::wstring wstrFilePath = ofn.lpstrFile;


        std::filesystem::path filePath(wstrFilePath);
        std::string fileName = filePath.filename().string();


        std::string saveDir = Mod::get()->getSaveDir().string();

        std::wstring destFilePath = std::wstring(saveDir.begin(), saveDir.end()) + L"\\FMod.png"; // Convert saveDir to wide string, concatenate with filename


        std::ifstream source(wstrFilePath, std::ios::binary);
        std::ofstream dest(destFilePath, std::ios::binary); // Use wide string for the destination file path
        dest << source.rdbuf();

        source.close();
        dest.close();

        Notification::create("File copied successfully to the save directory.")->show();
    }

    CoUninitialize();
}