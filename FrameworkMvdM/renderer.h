/**
* @file renderer.h
*
* @brief The Renderer header file.
*/

#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <glfw3.h>

#include <FrameworkMvdM/entity.h>
#include <FrameworkMvdM/sprite.h>
#include <FrameworkMvdM/scene.h>
#include <FrameworkMvdM/mvdmconfig.h>

class Renderer
{
public:
	Renderer(/*unsigned int w, unsigned int h*/);
	virtual ~Renderer();

	void renderScene(Scene* scene);
	void renderEntity(glm::mat4 modelMatrix, Entity* entity, Camera* camera);
	void renderSprite(Sprite* sprite, float px, float py, float sx, float sy, float rot);

	GLFWwindow* window() { return _window; };

	unsigned int width() { return _window_width; };
	unsigned int height() { return _window_height; };

private:
	int init();

	GLFWwindow* _window;
	unsigned int _window_width;
	unsigned int _window_height;

	GLuint loadShaders(
		const char* vertex_file_path,
		const char* fragment_file_path
	);

	GLuint _programID;

	glm::mat4 _viewMatrix;
	glm::mat4 _projectionMatrix;
};

#endif /* RENDERER_H */
