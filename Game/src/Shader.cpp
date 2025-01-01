#include "Shader.h"

//void Shader::CreateFromFiles(const char* vertexLocation, const char* fragmentLocation)
//{
//	std::string vertexString = ReadFile(vertexLocation);
//	std::string fragmentString = ReadFile(fragmentLocation);
//	const char* vertexCode = vertexString.c_str();
//	const char* fragmentCode = fragmentString.c_str();
//
//	CompileShader(vertexCode, fragmentCode);
//}

Shader::Shader(const char* vertexLocation, const char* fragmentLocation)
{
	std::string vertexString = ReadFile(vertexLocation);
	std::string fragmentString = ReadFile(fragmentLocation);
	const char* vertexCode = vertexString.c_str();
	const char* fragmentCode = fragmentString.c_str();

	CompileShader(vertexCode, fragmentCode);
}

std::string Shader::ReadFile(const char* fileLocation)
{
	std::string content;
	std::ifstream fileStream(fileLocation, std::ios::in);

	if (!fileStream.is_open()) {
		printf("Failed to read %s! File doesn't exist.\n", fileLocation);
		return "";
	}

	std::string line = "";
	while (!fileStream.eof())
	{
		std::getline(fileStream, line);
		content.append(line + "\n");
	}

	fileStream.close();
	return content;
}

void Shader::UseShader() const
{
	glUseProgram(m_ShaderID);
}

void Shader::ClearShader()
{
		if (m_ShaderID != 0)
		{
			glDeleteProgram(m_ShaderID);
			m_ShaderID = 0;
		}
}

void Shader::SetUniformMatrix(const std::string& name, glm::mat4 matrix)
{
	GLuint location = glGetUniformLocation(m_ShaderID, name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::SetUnifromVec3(const std::string& name, glm::vec3 vector)
{
	GLuint location = glGetUniformLocation(m_ShaderID, name.c_str());
	glUniform3fv(location, 1, glm::value_ptr(vector));
}

void Shader::CompileShader(const char* vertexCode, const char* fragmentCode)
{
	m_ShaderID = glCreateProgram();

	if (!m_ShaderID)
	{
		printf("Error creating shader program!\n");
		return;
	}

	AddShader(m_ShaderID, vertexCode, GL_VERTEX_SHADER);
	AddShader(m_ShaderID, fragmentCode, GL_FRAGMENT_SHADER);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glLinkProgram(m_ShaderID);
	glGetProgramiv(m_ShaderID, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(m_ShaderID, sizeof(eLog), NULL, eLog);
		printf("Error linking program: '%s'\n", eLog);
		return;
	}

	glValidateProgram(m_ShaderID);
	glGetProgramiv(m_ShaderID, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(m_ShaderID, sizeof(eLog), NULL, eLog);
		printf("Error validating program: '%s'\n", eLog);
		return;
	}
}

void Shader::AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
{
	GLuint theShader = glCreateShader(shaderType);

	const GLchar* theCode[1];
	theCode[0] = shaderCode;

	GLint codeLength[1];
	codeLength[0] = strlen(shaderCode);

	glShaderSource(theShader, 1, theCode, codeLength);
	glCompileShader(theShader);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
		printf("Error compiling the %d shader: '%s'\n", shaderType, eLog);
		return;
	}

	glAttachShader(theProgram, theShader);
}
