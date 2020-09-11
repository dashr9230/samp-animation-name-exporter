
#include <stdio.h>

extern "C" bool _stdcall Load(void**)
{
	FILE* f;
	if (*(unsigned long*)0x48F870 == 0x24448B66) {
		fopen_s(&f, "anims.txt", "a");
		if (f) {
			for (short i = 1; i <= 1812; i++) {
				char* a = ((char* (__cdecl*)(short))0x48F870)(i);
				fprintf(f, "\"%s\",\n", a);
				fflush(f);
			}
			fclose(f);
		}
		return true;
	}
	printf("animation_exporter.dll only runs on 0.3.7DL-R1.\n");
	return false;
}

extern "C" unsigned int _stdcall Supports()
{
	return 0x220;
}
