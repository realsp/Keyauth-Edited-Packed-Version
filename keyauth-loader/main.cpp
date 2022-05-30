#include "auth/auth.hpp"
#include "core/encryption/xorstr.hpp"
#include "core/util.h"
#include "core/logo.h"
#include "security/AntiDebug.h"
#include <iostream>
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#pragma comment(lib, "urlmon.lib")
using namespace KeyAuth;
/* setup keyauth */
std::string name = XorStr("");
std::string ownerid = XorStr("");
std::string secret = XorStr("");
std::string version = XorStr("");
api KeyAuthApp(name, ownerid, secret, version);

/* setup protection*/
void antishit();
bool AntiDebugRunning = true;

/* setup general stuff */
std::string licensekey;
int option;
std::ofstream hwidfile;

void spoofhwid()
{
	Util::Clear();
	Util::SetColor(WHITE);
	std::cout << XorStr("[").c_str();
	Util::SetColor(YELLOW);
	std::cout << XorStr("WARNING").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("] - Spoofing process started").c_str();
	std::string mapperurl = XorStr("https://yoururl.com").c_str();
	std::string mapperpath = XorStr("your path").c_str();
	std::string driverurl = XorStr("https://yoururl.com").c_str();
	std::string driverpath = XorStr("your path").c_str();
	URLDownloadToFileA(NULL, mapperurl.c_str(), mapperpath.c_str(), 0, NULL);
	URLDownloadToFileA(NULL, driverurl.c_str(), driverpath.c_str(), 0, NULL);
	system(XorStr("yourpath\\mapper.exe yourpath\\driver.sys").c_str());
	DeleteFileA(mapperpath.c_str());
	DeleteFileA(driverpath.c_str());
	Beep(400, 1000);
	hwidfile.open(XorStr("hwid").c_str());
	hwidfile << Util::get_hwid();
	hwidfile.close();
	Util::SetColor(WHITE);
	std::cout << XorStr("[").c_str();
	Util::SetColor(GREEN);
	std::cout << XorStr("SUCCESS").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("] - Spoofing process completed").c_str();
	Sleep(2000);
	exit(0);
}

void clean()
{
	Util::Clear();
	Util::SetColor(WHITE);
	std::cout << XorStr("[").c_str();
	Util::SetColor(YELLOW);
	std::cout << XorStr("WARNING").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("] - Cleaning process started").c_str();
	std::string cleanerurl = XorStr("https://yoururl.com").c_str();
	std::string cleanerpath = XorStr("your path").c_str();
	URLDownloadToFileA(NULL, cleanerurl.c_str(), cleanerpath.c_str(), 0, NULL);
	system(XorStr("yourpath\\cleaner.bat").c_str());
	DeleteFileA(cleanerpath.c_str());
	Beep(400, 1000);
	Util::SetColor(WHITE);
	std::cout << XorStr("[").c_str();
	Util::SetColor(GREEN);
	std::cout << XorStr("SUCCESS").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("] - Cleaning process completed").c_str();
	Sleep(2000);
	exit(0);
}

int main()
{
	SetConsoleTitleA(XorStr("").c_str());
	std::thread anti(antishit);
	KeyAuthApp.init();
	//logo();
	Util::SetColor(WHITE);
	std::cout << XorStr("[").c_str();
	Util::SetColor(YELLOW);
	std::cout << XorStr("WARNING").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("] - License key: ").c_str();
	std::cin >> licensekey;
	KeyAuthApp.license(licensekey);
	Util::SetColor(WHITE);
	std::cout << XorStr("[").c_str();
	Util::SetColor(GREEN);
	std::cout << XorStr("SUCCESS").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("] - Key is valid, please wait").c_str();
	Sleep(2000);
	mainmenu:
	Util::Clear();
	Util::SetColor(WHITE);
	std::cout << XorStr("[").c_str();
	Util::SetColor(YELLOW);
	std::cout << XorStr("OPT - 1").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("] - Spoof").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("\n[").c_str();
	Util::SetColor(YELLOW);
	std::cout << XorStr("OPT - 2").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("] - Clean").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("\n[").c_str();
	Util::SetColor(YELLOW);
	std::cout << XorStr("OPT - 3").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("] - Discord").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("\n[").c_str();
	Util::SetColor(YELLOW);
	std::cout << XorStr("OPT - 4").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("] - Exit").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("\n\n[").c_str();
	Util::SetColor(YELLOW);
	std::cout << XorStr("OPTION").c_str();
	Util::SetColor(WHITE);
	std::cout << XorStr("]: ").c_str();
	std::cin >> option;
	switch (option)
	{
	case 1:
		spoofhwid();
		break;
	case 2:
		clean();
		break;
	case 3:
		system(XorStr("start https://drklight.xyz/discord").c_str());
		goto mainmenu;
		break;
	case 4:
		exit(0);
		break;
	}
}

void antishit()
{
	while (AntiDebugRunning)
	{
		AntiDebug::EndTask();
	}
}