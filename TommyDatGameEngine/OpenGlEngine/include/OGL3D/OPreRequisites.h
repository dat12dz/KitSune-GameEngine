#ifndef OGL3D_OPREREQUISITES_H
#define OGL3D_OPREREQUISITES_H
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
typedef float f32;
typedef int i32;
typedef unsigned int uint;

class OVertexArrayObject;
class OShaderProgram;
typedef std::shared_ptr<OVertexArrayObject> OVertexArrayObjectPtr;
typedef std::shared_ptr<OShaderProgram> OShaderProgramPtr;
struct OVertexAtrribute
{
	uint numElm = 0;

};
struct OVertexBufferDesc
{
	void* verticesList = nullptr;
	uint vertexSize = 0;
	uint listSize = 0;

	OVertexAtrribute* attributesList = 0;
	uint attributeListSize = 0;
};
struct OShaderProgramDesc
{
	const wchar_t* vertexShaderPath;
	const wchar_t* fragmentShaderPath;
};

enum OShaderType
{
	VertexShader = 0,
	FragmentShader = 1
};
#endif // OGL3D_OPREREQU

#define OGL3D_ERROR(mess)\
{\
    std::stringstream m;\
	m << L"OpenGL3D lỗi: " << mess << std::endl;\
	throw std::runtime_error(m.str());\
}
#define OGL3D_WARNING(mess)\
{\
	std::wclog << L"OpenGL3D cảnh báo: " << mess << std::endl;\
}
#define OGL3D_INFO(mess)\
{\
	std::wclog << L"OpenGL3D thông báo: " << mess << std::endl;\
}