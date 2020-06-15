#ifndef SHADERHELPER_H
#define SHADERHELPER_H

#include <GLFW/glfw3.h>
#include <gl/gl3w.h>

#include "FileManager.h"

GLuint compilarShader(const char* filename,GLenum tipeShader) {
	GLint result = GL_FALSE;
	int infoLogLength;
	char* codeOfShader;

	readStringFromFile(&codeOfShader, filename); //Se obtiene el codigo del shader del archivo "filename"
	GLuint shader = glCreateShader(tipeShader);
	glShaderSource(shader, 1, &codeOfShader, NULL);
	glCompileShader(shader);  //Se compila el shader

	//Se verifica la compilacion correcta del shader
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		char* errorMessage = (char*)malloc(infoLogLength);
		glGetShaderInfoLog(shader, infoLogLength, NULL, errorMessage);
		printf("Error al compilar %s : %s\n",filename, errorMessage);
	}

	return shader;
}

GLuint cargarShader(GLuint vertexShader, GLuint fragmentShader) {
	GLint result = GL_FALSE;
	int infoLogLength;
	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, fragmentShader);  //Se enlaza el fragment shader con el programa para la GPU
	glAttachShader(shaderProgram, vertexShader);  //Se enlaza el vertex shader con el programa para la GPU
	
	glLinkProgram(shaderProgram); 

	//Se verifica que el programa este sin errores
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &result);
	glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		char* errorMessage = (char*)malloc(infoLogLength);
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, errorMessage);
		printf("Error al Linkear %s\n", errorMessage);
	}

	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}


#endif

