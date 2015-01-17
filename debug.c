#include "table.h"
#include "debug.h"
void dump_file( char* fileName[] ){
	char c;
	for (int i = 0; i < 4; ++i)
	{
		log_info("File: %s",fileName[i]);
		FILE* file = fopen(fileName[i],"rb");
		while( ( c = fgetc(file) ) != EOF )
			dump_code( c , 8 );
	}
}
void dump_code( Code code,int BitsNum )
{
	int mask = 1 << (BitsNum-1);
	for (int i = 0; i < BitsNum ; ++i)
	{
		if(i%8==0)putchar('|');
		putchar((mask & code) ? '1' : '0');
		code <<= 1;
	}
	puts("");
}
