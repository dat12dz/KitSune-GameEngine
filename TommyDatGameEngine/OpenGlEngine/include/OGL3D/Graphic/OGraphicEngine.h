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
	void DrawTriangle(const OTriangleType& triType, uint vertCount, uint offset);
	void SetUniformBuffer(const OUniformBufferPtr& buffer, uint slot);

	OVertexArrayObjectPtr createVertexArrayObject(const OVertexBufferDesc& buffer);
	OShaderProgramPtr createShaderProgram(const OShaderProgramDesc& desc);
	OUniformBufferPtr createUniformBuffer(const OUniformBufferDesc& desc);
};

