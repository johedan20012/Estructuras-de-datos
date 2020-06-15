#ifdef _MSC_VER
	#define _CRT_SECURE_NO_DEPRECATE 
#endif

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

#include "FileManager.h"
#include "ShaderHelper.h"

const int ANCHO = 800, ALTO = 600;

int main() {
	if (!glfwInit()) {
		printf("Error al inicar glfw");
		glfwTerminate();
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* ventana = glfwCreateWindow(ANCHO, ALTO, "Hola mundo", NULL, NULL);
	if (ventana == NULL) {
		printf("No se pudo crear la ventana GLFW");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(ventana);
	glfwSwapInterval(1);

	if (gl3wInit()) {
		printf("No se pudo inicalizar OpenGL");
		return -1;
	}

	if (!gl3wIsSupported(3, 3)) {
		printf("No soporta OpenGl 3.3");
		return -1;
	}
	printf("OpenGL %s \nGLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

	glfwSwapInterval(1);

	glClearColor(0, 0, 125, 0);

	float points[] = {  //Arreglo de puntos que representan 3 vertices para dibujar un triangulo
	-1.0f,  1.0f, 0.0f,
	 1.0f, -1.0f, 0.0f,
	-1.0f, -1.0f, 0.0f,
	 1.0f,  1.0f, 0.0f
	};

	GLuint indices[] = {
		0,1,2,
		0,1,3
	};

	GLuint vbo = 0;  //Vertex Buffer Object(VBO) es un buffer para almacenar objetos vertices
	glGenBuffers(1, &vbo); //glGenBuffers(int numBuffers,Uint* arregloBuffers)  
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vio = 0; //Vertex Index Object 
	glGenBuffers(1, &vio);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vio);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);


	GLuint shaderProgram = cargarShader(compilarShader("VertexShader.glsl", GL_VERTEX_SHADER), compilarShader("MandelbrotFragmentShader.glsl", GL_FRAGMENT_SHADER));
	
	GLuint textura;
	glGenTextures(1, &textura);
	
	glActiveTexture(GL_TEXTURE0);
	
	glBindTexture(GL_TEXTURE_1D, textura);
	float datosTextura[] = {
		0.0f,0.0f,0.0f,1.0f,
		0.12f,0.f,0.0f,1.0f,
		0.345f,0.0f,0.0f,1.0f,
		0.674f,0.0f,0.0f,1.0f,
		0.89f,0.43f,0.0f,1.0f,
		0.95f,0.70f,0.0f,1.0f,
		0.98f,0.86f,0.39f,1.0f,
		0.985f,0.90f,0.67f,1.0f,
		0.99f,0.95f,0.86f,1.0f,

		1.0f,1.0f,1.0f,1.0f,

		0.99f,0.95f,0.86f,1.0f,
		0.985f,0.90f,0.67f,1.0f,
		0.98f,0.86f,0.39f,1.0f,
		0.95f,0.70f,0.0f,1.0f,
		0.89f,0.43f,0.0f,1.0f,
		0.674f,0.0f,0.0f,1.0f,
		0.345f,0.0f,0.0f,1.0f,
		0.12f,0.f,0.0f,1.0f,
		0.0f,0.0f,0.0f,1.0f
	};

	glTexImage1D(GL_TEXTURE_1D, 0, GL_RGB16F, 19, 0, GL_RGBA, GL_FLOAT, datosTextura);

	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_1D, 0);

	int width, height;
	float  contador = 0;
	while (!glfwWindowShouldClose(ventana)) {
		contador += 0.001; if(contador > 2)contador = 0;

		glUniform1f(glGetUniformLocation(shaderProgram, "scala"), contador);

		glfwGetFramebufferSize(ventana, &width, &height);
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);


		glUseProgram(shaderProgram);

		//GLint adicion = glGetUniformLocation(shaderProgram, "adicion");
		//glUniform1i(adicion, (int)(contador / 2));
		
		glUniform1i(glGetUniformLocation(shaderProgram, "tex"), 0);

		glActiveTexture(GL_TEXTURE0+0);
		glBindTexture(GL_TEXTURE_1D, textura);

		
		glBindVertexArray(vao);
		// draw points 0-3 from the currently bound VAO with current in-use shader
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);

		

		glfwSwapBuffers(ventana);
		glfwPollEvents();
	}

	
	glfwDestroyWindow(ventana);
	glfwTerminate;
	exit(EXIT_SUCCESS);
}