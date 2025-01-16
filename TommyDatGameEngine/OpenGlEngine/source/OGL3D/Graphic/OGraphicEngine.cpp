#include <OGL3D/Graphic/OGraphicEngine.h>
#include <glad/glad.h>
#include <glad/glad_wgl.h>
#include <assert.h>
#include <OGL3D/Math/OVec4.h>
#include <stdexcept>
#include <OGL3D/Math/ORect.h>
#include <OGL3D/Graphic/OVertexArrayObject.h>.
#include <OGL3D/Graphic/OShaderProgram.h>
#include <OGL3D/Graphic/OUniformBuffer.h>
void OGraphicEngine::clear(const OVec4& color)
{
	glClearColor(color.x, color.y, color.z, color.w);
	glClear(GL_COLOR_BUFFER_BIT);
}
void OGraphicEngine::SetViewPort(const Orect& size)
{
	glViewport(size.left, size.right, size.width, size.height);
}

void OGraphicEngine::setVertextArrayObj(const OVertexArrayObjectPtr& vao)
{
	glBindVertexArray(vao->getID());
}

OVertexArrayObjectPtr OGraphicEngine::createVertexArrayObject(const OVertexBufferDesc& buffer)
{
	return std::make_shared<OVertexArrayObject>(buffer);
}
OShaderProgramPtr OGraphicEngine::createShaderProgram(const OShaderProgramDesc& desc)
{
	return std::make_shared<OShaderProgram>(desc);
}
OUniformBufferPtr OGraphicEngine::createUniformBuffer(const OUniformBufferDesc& desc)
{
	return std::make_shared<OUniformBuffer>(desc);
}
void OGraphicEngine::SetShaderProgram(const OShaderProgramPtr& program)
{
	glUseProgram(program->getID());
}
void OGraphicEngine::DrawTriangle(const OTriangleType& triType,uint vertCount, uint offset)
{
	auto glTriType = GL_TRIANGLES;
	if (triType == TriangleList)
	{
		glTriType = GL_TRIANGLES;
	}
	else if (triType == TriangleStrip)
	{
		glTriType = GL_TRIANGLE_STRIP;
	}
	glDrawArrays(glTriType, offset, vertCount);

}

void OGraphicEngine::SetUniformBuffer(const OUniformBufferPtr& buffer, uint slot)
{
	glBindBufferBase(GL_UNIFORM_BUFFER, slot, buffer->GetID());
}

