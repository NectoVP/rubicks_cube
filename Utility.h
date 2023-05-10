#pragma once

#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

void create_window(GLFWwindow** window);

void free_all_memory(GLFWwindow** window, std::vector<GLfloat*>& all_verts);

void get_rotation(double prev_time, float& rotation);

void init_frame(Shader& shader);