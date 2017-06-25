// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <tchar.h>
#include <psapi.h>
#include <vector>
#include <iostream>
#include <string>

#include "MyLibrary/MyLibrary.h"

int PrintModules(DWORD processID)
{
    std::vector<HMODULE> modules;
    HANDLE process;
    DWORD bytesNeeded;

    std::cout << "Process ID:" << processID << std::endl;
    process = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
    if(NULL == process)
        return 1;

    EnumProcessModulesEx(process, nullptr, 0, &bytesNeeded, LIST_MODULES_ALL);
    modules.resize(bytesNeeded / sizeof(HMODULE));
    if(EnumProcessModulesEx(process, modules.data(), modules.size() * sizeof(HMODULE), &bytesNeeded, LIST_MODULES_ALL))
    {
        for(auto handle : modules)
        {
            std::vector<char> moduleName(1024, 0);
            auto newSize = GetModuleFileNameEx(process, handle, moduleName.data(), moduleName.size());
            moduleName.resize(newSize);
            std::cout << "\t" << moduleName.data() << std::endl;
        }
    }
    CloseHandle(process);
    return 0;
}

int main()
{
    auto res = fnMyLibrary();
    PrintModules(GetCurrentProcessId());
    return 0;
}
