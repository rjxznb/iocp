#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <mswsock.h>
#include <stdio.h>
#include<vector>
#include<string>
using namespace std;

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Mswsock.lib")

class A {
public:
	A(int a, int b) :a{ a }, b{b} {
		cout << "A" << endl;
	}
	int a;
	int b;
};

int main() {
	STARTUPINFOW info{};
	memset(&info, 0, sizeof(info));
	info.cb = sizeof(info);
	PROCESS_INFORMATION pinfo{};
	memset(&pinfo, 0, sizeof(pinfo));
	TCHAR cmdline[] = L"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\Common7\\IDE\\devenv.exe";
	if (CreateProcess(NULL, cmdline, NULL, NULL, false, CREATE_NEW_CONSOLE, NULL, NULL, &info, &pinfo)) {
		WaitForSingleObject(pinfo.hProcess, INFINITE);
	}
}