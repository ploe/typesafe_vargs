#include <stdio.h>

typedef struct ShaderProgram_New_Arg {
	const char *filename;
	int *index, constant;
} ShaderProgram_New_Arg;

typedef ShaderProgram_New_Arg ShaderProgram_New_Args[];

#define END_SHADERPROGRAM_NEW {NULL, NULL, 0}

void ShaderProgram_New(ShaderProgram_New_Args args) {

	ShaderProgram_New_Arg arg = *args;
	while (arg.filename && arg.index && arg.constant) {
		puts(arg.filename);

		args += 1;
		arg = *args;
	}

	puts("end of args");
}

#define SHADERPROGRAM_NEW(...) ShaderProgram_New(args, END_SHADERPROGRAM_NEW)

#define GL_CONSTANT_VERTEX 1
#define GL_CONSTANT_FRAGMENT 2

int main(int argc, char *argv[]) {
	int vert, frag;

	ShaderProgram_New((ShaderProgram_New_Args) {
		{"default.vert", &vert, GL_CONSTANT_VERTEX},
		{"default.frag", &frag, GL_CONSTANT_FRAGMENT},
		END_SHADERPROGRAM_NEW,
	});

	return 0;
}
