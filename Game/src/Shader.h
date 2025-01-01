#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <string>

class Shader {
public:
		Shader() = default;
		Shader(const char* vertexLocation, const char* fragmentLocation);

		/*void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);*/

		std::string ReadFile(const char* fileLocation);

		void UseShader() const;
		void ClearShader();
		void SetUniformMatrix(const std::string& name, glm::mat4 matrix);
		void SetUnifromVec3(const std::string& name, glm::vec3 vector);

		~Shader() = default;

	private:
		
		void CompileShader(const char* vertexCode, const char* fragmentCode);
		void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);

		GLuint m_ShaderID;
};