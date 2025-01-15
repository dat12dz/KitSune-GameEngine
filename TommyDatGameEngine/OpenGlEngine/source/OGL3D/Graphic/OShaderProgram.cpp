#include <OGL3D/Graphic/OShaderProgram.h>
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
OShaderProgram::OShaderProgram(const OShaderProgramDesc& desc)
{
	m_programId = glCreateProgram();
	attach(desc.vertexShaderPath, VertexShader);
	attach(desc.fragmentShaderPath, FragmentShader);
	link();
}

OShaderProgram::~OShaderProgram()
{
	for (uint i = 0;i < 2;i++)
	{
		// Gỡ Shader ra khỏi Program
		glDetachShader(m_programId, m_attachedShaders[i]);
		glDeleteShader(m_attachedShaders[i]);
	}
	glDeleteProgram(m_programId);
}

uint OShaderProgram::getID()
{
	return m_programId;
}

void OShaderProgram::attach(const wchar_t* shaderPath, const OShaderType& type)
{
	std::string shaderCode;
	std::ifstream shaderStream(shaderPath);
	if (shaderStream.is_open())
	{
		std::stringstream sstr;
		sstr << shaderStream.rdbuf();
		shaderCode = sstr.str();
	}
	else
	{
		OGL3D_WARNING(L"OShaderProgram | " << shaderPath << "Không thể mở file shader");
		return;
	}
	uint shaderID = 0;
	if (type == VertexShader)
	{
		shaderID = glCreateShader(GL_VERTEX_SHADER);
	}
	else
	{
		shaderID = glCreateShader(GL_FRAGMENT_SHADER);
	}


	auto SourcePointer = shaderCode.c_str();
	// Biên dịch shader
	glShaderSource(shaderID, 1, &SourcePointer, NULL);
	glCompileShader(shaderID);

	// Kiểm tra lỗi

	int logLen;
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLen);
	if (logLen > 0)
	{
		std::vector<char> errorLog(logLen + 1);
		glGetShaderInfoLog(shaderID, logLen, NULL, &errorLog[0]);
		OGL3D_WARNING(L"Lớp OShaderProgram | " << shaderPath << L" biên dịch với lỗi" << std::endl << &errorLog[0]);
		return;
	}
	glAttachShader(m_programId, shaderID);
	m_attachedShaders[type] = shaderID;
	OGL3D_INFO(L"Lớp OShaderProgram | Biên dịch shader thành công:" << shaderPath);
}

void OShaderProgram::link()
{
	glLinkProgram(m_programId);
	int logLen;
	glGetShaderiv(m_programId, GL_INFO_LOG_LENGTH, &logLen);
	if (logLen > 0)
	{
		std::vector<char> errorLog(logLen + 1);
		glGetShaderInfoLog(m_programId, logLen, NULL, &errorLog[0]);
		OGL3D_WARNING(L"Lớp OShaderProgram | lỗi link():" << std::endl << &errorLog[0]);
		return;
	}
}
