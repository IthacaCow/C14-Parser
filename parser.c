#include <stdio.h>
#include <stdlib.h>
#include "lineProcess.h"
#include "writeFile.h"
#ifdef DEBUG
	#include "debug.h"
#endif
void file_init(FILE** src,const char *filename,char* type ){
	*src = malloc(sizeof(FILE));
	if((*src = fopen(filename,type)) == NULL)
		printf("Fail to open %s",filename);
}

int main(int argc, char *argv[]){
	
	if (argc != 2) {
		printf("Correct Usage: %s [filenname]\n", argv[0]);
		exit(1);
	}
	FILE *src = NULL; 
	FILE* out[4];
	char* out_filename[4] = {
		"controlSignal3.bin","controlSignal2.bin","controlSignal1.bin","memory.bin"
	};
	

	file_init(&src, argv[1],"r");
	for (int i = 0; i < FILENUM; ++i)
		file_init(out+i, out_filename[i],"wb");

	Instruction* instructions = NULL;
	int instructions_number = 0;
	getInstructions( src, &instructions, &instructions_number );
	writeFile( out, instructions, instructions_number );

	#ifdef DEBUG
		log_info("File dump:");
		dump_file( out_filename );
	#endif
	return 0;
}
