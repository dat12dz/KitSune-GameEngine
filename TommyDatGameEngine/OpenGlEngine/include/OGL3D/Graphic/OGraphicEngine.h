#pragma once
#include <OGL3D/OPreRequisites.h>
#include <OGL3D/Math/OVec4.h>
class OVec4;
class Orect;
class OGraphicEngine
{
	public:
	OGraphicEngine();
	~OGraphicEngine();

	void clear(const OVec4& color);
	void SetViewPort(const Orect& size);
	void setVertextArrayObj(const OVertexArrayObjectPtr& vao);
	void SetShaderProgram(const OShaderProgramPtr& program);
	void DrawTriangle(uint vertCount, uint offset);

	OVertexArrayObjectPtr createVertexArrayObject(const OVertexBufferDesc& buffer);
	OShaderProgramPtr createShaderProgram(const OShaderProgramDesc& desc);
};

