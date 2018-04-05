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
	Renderer();
	virtual ~Renderer();

	/// @brief render the scene and its children
	/// @param scene the scene that you want to render
	/// @return void
	void renderScene(Scene* scene);
	/// @brief render the entity and its children
	/// @param modelmatrix the modelmatrix of the parent
	/// @param entity the entity that you want to render
	/// @return void
	void renderEntity(glm::mat4 modelMatrix, Entity* entity);
	/// @brief render the given sprite
	/// @param sprite the spirte that you want to render
	/// @param px the x position of the sprite
	/// @param py the y position of the sprite
	/// @param sx the x scale of the sprite
	/// @param sy the y scale of the sprite
	/// @param rot the rotation scale of the sprite
	/// @return void
	void renderSprite(Sprite* sprite, float px, float py, float sx, float sy, float rot);

	/// @brief access the GLFWwindow.
	/// @return GLFWwindow* _window
	GLFWwindow* window() { return _window; };

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
