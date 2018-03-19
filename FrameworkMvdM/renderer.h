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
		Renderer(unsigned int w, unsigned int h);
		virtual ~Renderer();

		void renderSprite(Sprite* sprite, float px, float py, float sx, float sy, float rot);
		GLFWwindow* window() { return _window; };

		/// @brief get a pointer to the Camera
		/// @return Camera* a pointer to the Camera
		Camera* camera() { return _camera; };

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

		Camera* _camera; ///< @brief the Camera instance

		glm::mat4 _projectionMatrix;
		glm::mat4 _viewMatrix;
};

#endif RENDERER_H