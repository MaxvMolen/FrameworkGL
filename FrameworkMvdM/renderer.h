/**
* @file renderer.h
*
* @brief The Renderer header file.
*/

#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <FrameworkMvdM/entity.h>
#include <FrameworkMvdM/scene.h>
#include <FrameworkMvdM/sprite.h>

class Renderer
{
	public:
		Renderer();
		virtual ~Renderer();

		int init();

		/// @brief Renders a Scene with all its children.
		/// @param scene The Scene that needs to be rendered
		/// @return void
		void renderScene(Scene* scene);

		GLFWwindow* window() { return _window; };

		unsigned int width() { return _window_width; };
		unsigned int height() { return _window_height; };

	private:
		GLFWwindow* _window;
		unsigned int _window_width;
		unsigned int _window_height;

		void _renderSprite(Sprite* sprite, float px, float py, float sx, float sy, float rot);

		/// @brief Recursive function that renders an Entity which is a child of the Scene or parent Entity.
		/// @param modelMatrix The modelMatrix of the parent
		/// @param entity The Entity that needs rendering
		/// @param camera The camera in case we need to cull Sprites
		/// @return void
		void _renderEntity(glm::mat4 modelMatrix, Entity* entity, Camera* camera);

		GLuint loadShaders(
			const char* vertex_file_path,
			const char* fragment_file_path
		);

		GLuint _programID;

		glm::mat4 _projectionMatrix;
		glm::mat4 _viewMatrix;
};

#endif RENDERER_H