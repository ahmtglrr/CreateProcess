#include <Windows.h>
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hinst,HINSTANCE hprevinst,LPSTR cmd_line,int show_cmd)
{
	STARTUPINFO sai;
	PROCESS_INFORMATION pi;
	char size[128];
	MessageBox(NULL,"Not defteri baþlatýlýyor","Mesaj",MB_OK);


	sai.cb=sizeof(sai);
	CreateProcess(NULL,"notepad.exe",NULL,NULL,FALSE,0,NULL,NULL,&sai,&pi);

	sprintf(size,"EBEVEYN PID : %d NOT DEFTERÝ PID : %d",GetProcessId(GetCurrentProcess()),pi.dwProcessId);


	WaitForSingleObject(pi.hProcess,INFINITE);

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

}