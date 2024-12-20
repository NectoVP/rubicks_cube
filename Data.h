#ifndef H_DATA
#define H_DATA

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const int width = 800;
const int height = 800;

GLfloat origin_vert[] = {
	-0.9f, -0.9f, -0.9f,
	-0.9f, -0.9f, -0.3f,
	-0.3f, -0.9f, -0.3f,
	-0.3f, -0.9f, -0.9f,

	-0.9f, -0.3f, -0.9f,
	-0.9f, -0.3f, -0.3f,
	-0.3f, -0.3f, -0.3f,
	-0.3f, -0.3f, -0.9f,
};

GLfloat colors_origin[] = {
	-0.91f, -0.8f, -0.8f,
	-0.91f, -0.8f, -0.4f, 
	-0.91f, -0.4f, -0.4f, 
	-0.91f, -0.4f, -0.8f, 

	-0.8f, -0.8f, 0.91f,
	-0.4f, -0.8f, 0.91f,
	-0.4f, -0.4f, 0.91f,
	-0.8f, -0.4f, 0.91f,

	0.91f, -0.8f, 0.8f,
	0.91f, -0.8f, 0.4f, 
	0.91f, -0.4f, 0.4f, 
	0.91f, -0.4f, 0.8f, 

	0.8f, -0.8f, -0.91f,	
	0.4f, -0.8f, -0.91f,
	0.4f, -0.4f, -0.91f,
	0.8f, -0.4f, -0.91f,

	-0.8f, 0.91f, -0.8f,
	-0.4f, 0.91f, -0.8f,
	-0.4f, 0.91f, -0.4f,
	-0.8f, 0.91f, -0.4f,

	-0.8f, -0.91f, -0.8f,
	-0.4f, -0.91f, -0.8f, 
	-0.4f, -0.91f, -0.4f, 
	-0.8f, -0.91f, -0.4f, 
};

GLuint indices[] = {
	0, 1, 2,
	0, 2, 3,
	0, 1, 4,
	1, 4, 5,
	1, 2, 6,
	5, 6, 1,
	2, 3, 6,
	3, 6, 7,
	3, 0, 7,
	0, 7, 4,
	6, 7, 4,
	5, 6, 4,
};

GLuint color_indices[] = {
	0, 1, 2,
	2, 3, 0,
};

std::vector<int> void_v;

std::vector<int> all = {
	0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,
	19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,
	37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53
};

std::vector<int> right = {
	2,5,8,42,43,44,24,21,18,53,52,51,2,5,8
};

std::vector<int> right_edge = {
	10,12,16,14,10
};

std::vector<int> right_corner = {
	9,15,17,11,9
};

std::vector<int> down = {
	0,1,2,9,10,11,18,19,20,27,28,29,0,1,2
};

std::vector<int> down_edge = {
	46,48,52,50,46
};

std::vector<int> down_corner = {
	45,51,53,47,45
};

std::vector<int> front = {
	15,12,9,51,48,45,29,32,35,36,39,42,15,12,9
};

std::vector<int> front_edge = {
	1,3,7,5,1
};

std::vector<int> front_corner = {
	0,6,8,2,0
};

std::vector<int> left = {
	6,3,0,45,46,47,20,23,26,38,37,36,6,3,0
};

std::vector<int> left_edge = {
	28,30,34,32,28
};

std::vector<int> left_corner = {
	27,33,35,29,27
};

std::vector<int> up = {
	8,7,6,35,34,33,26,25,24,17,16,15,8,7,6
};

std::vector<int> up_edge = {
	37,41,43,39,37
};

std::vector<int> up_corner = {
	36,38,44,42,36
};

std::vector<int> back = {
	11,14,17,44,41,38,33,30,27,47,50,53,11,14,17
};

std::vector<int> back_edge = {
	19,21,25,23,19
};

std::vector<int> back_corner = {
	18,24,26,20,18,
};

std::vector<int> middle = {
	41,40,39,7,4,1,48,49,50,19,22,25,41,40,39
};

std::vector<int> equator = {
	3,4,5,12,13,14,21,22,23,30,31,32,3,4,5
};

std::vector<int> side = {
	37,40,43,16,13,10,52,49,46,28,31,34,37,40,43
};

std::vector<glm::vec3> side_colors = {
	glm::vec3(0.26f, 0.27f, 0.25f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(1.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 1.0f),
	glm::vec3(0.99f, 0.57f, 0.09f),
	glm::vec3(1.0f, 1.0f, 1.0f),
	glm::vec3(1.0f, 0.97f, 0.0f),
};

union one_side {
	uint32_t num_in_file;
	struct {
		unsigned int x0 : 3;
		unsigned int x1 : 3;
		unsigned int x2 : 3;
		unsigned int x3 : 3;
		unsigned int x4 : 3;
		unsigned int x5 : 3;
		unsigned int x6 : 3;
		unsigned int x7 : 3;
		unsigned int x8 : 3;
		unsigned int rest : 5;
	};
};

#endif