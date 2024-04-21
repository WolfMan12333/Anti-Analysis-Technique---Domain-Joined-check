#include <windows.h>
#include <stdio.h>
#include "WinDef.h"
#include "lm.h"

#pragma comment(lib, "netapi32")

int InDomain(bool* b) {

    DWORD s = 0;

    // get the computer name and domain

    LPWSTR name = NULL;
    NETSETUP_JOIN_STATUS status;

    *b = false;

    s = NetGetJoinInformation(NULL, &name, &status);

    if (s != 0)
        return HRESULT_FROM_WIN32(s);
    
    NetApiBufferFree(name);
    name = NULL;

    // if status variable is equal NetSetupDomainName value then we have joined target
    if (status != NetSetupDomainName) {
        wprintf(L"NetSetupDomainName is not in status\n");
        *b = true;
        return 0;
    }
    else {
        wprintf(L"NetSetupDomainName in status\n");
        return 1;
    }
}

int main() {

    bool b;

    // checking if we are on target joined to Domain
    if (InDomain(&b) == 1) {

        #define InDomain
    } else {
        wprintf(L"Unable to determine if joined to domain\n");
        return 1;
    }

#ifdef InDomain
    wprintf(L"You should run rest of the code here like injection");
    return 0;
#endif
}