// ¶ÔÅÄ³ÌÐò
#include <windows.h>

using namespace std;

int main()
{
	while (1)
	{
		system("gen.exe");
		system("baoli.exe");	// ab.ans
		system("ab.exe");		// ab.out

		system("fc ab.ans ab.out /n");
		if (system("fc ab.ans ab.out"))
			system("pause");
		
		Sleep(500);
	}
}
