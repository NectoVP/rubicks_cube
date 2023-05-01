#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Base.h"
#include "Shader.h"

const int width = 800;
const int height = 800;

void create_window(GLFWwindow** window) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	*window = glfwCreateWindow(width, height, "test", NULL, NULL);
	if (*window == NULL) {
		std::cerr << "Failed window construction" << std::endl;
		glfwTerminate();
		exit(0);
	}

	glfwMakeContextCurrent(*window);
	gladLoadGL();
	glViewport(0, 0, width, height);
}

void free_all_memory(GLFWwindow** window, std::vector<GLfloat*>& all_verts) {
	
	glfwDestroyWindow(*window);
	glfwTerminate();

	//for (int i = 0; i < all_verts.size(); ++i)
		//delete[] all_verts[i];
}

void rotate_by_angle(float angle, Shader& shader) {
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);

	model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0, 1.0f, 0.0f));
	view = glm::translate(view, glm::vec3(-1.0f, -0.5f, -3.5f));
	proj = glm::perspective(glm::radians(90.0f), (float)(width / height), 0.1f, 100.0f);

	int modelLoc = glGetUniformLocation(shader.ID, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	int viewLoc = glGetUniformLocation(shader.ID, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	int projLoc = glGetUniformLocation(shader.ID, "proj");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
}

int main() {
	GLFWwindow* window;
	create_window(&window);
	
	Shader shader("default.vert", "default.frag");

	GLint color_u = glGetUniformLocation(shader.ID, "aaa_Color");
	
	std::vector<GLfloat*> all_verts;
	std::vector<GLuint> VAOs;
	create_cubes(all_verts, VAOs);

	float rotation = 0.0f;
	double prevTime = glfwGetTime();

	glEnable(GL_DEPTH_TEST);

	int flag = 0;
	GLuint Cube_or_side_color_u = glGetUniformLocation(shader.ID, "aCube_or_side_color");
	
	while (!glfwWindowShouldClose(window)) {
		glUniform4f(color_u, 1.0f, 0.0f, 0.0f, 1.0f);
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.Activate();

		double crnt_time = glfwGetTime();
		if (crnt_time - prevTime >= 1/15) {
			rotation += 0.05f;
			prevTime = crnt_time;
			if (rotation >= 360.0f)
				rotation = 0.0f;
		}

		for (int i = 0; i < 9; ++i) {
			flag = i % 2;
			glUniform1i(Cube_or_side_color_u, flag);
			glBindVertexArray(VAOs[i]);
			rotate_by_angle(rotation, shader);
			glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
		}
		for (int i = 9; i < 18; ++i) {
			flag = i % 2;
			glUniform1i(Cube_or_side_color_u, flag);
			glBindVertexArray(VAOs[i]);
			rotate_by_angle(-rotation, shader);
			glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
		}
		for (int i = 18; i < all_verts.size(); ++i) {
			flag = i % 2;
			glUniform1i(Cube_or_side_color_u, flag);
			glBindVertexArray(VAOs[i]);
			rotate_by_angle(rotation, shader);
			glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
		}



		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	free_all_memory(&window, all_verts);
	
	return 0;
}