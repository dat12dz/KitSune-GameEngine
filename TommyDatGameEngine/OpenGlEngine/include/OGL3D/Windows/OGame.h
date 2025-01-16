#include <memory>
#include <OGL3D/OPreRequisites.h>
#include <OGL3d/Graphic/OVertexArrayObject.h>
#include <OGL3D/Graphic/OShaderProgram.h>
#include <chrono>
class OWindow;
class OGraphicEngine;
class OGame
{
public:
	OGame();
	~OGame();
	void Run();
	virtual void OnCreate();
	virtual void OnUpdate();
	virtual void OnQuit();
	void Quit();
	float m_scale;
	OShaderProgramPtr m_shader;
	std::chrono::system_clock::time_point m_prevTime;
protected:
	bool m_isRunning = true;
    std::unique_ptr<OWindow> m_display = 0;
	std::unique_ptr<OGraphicEngine> m_graphicEngine;
	OVertexArrayObjectPtr m_PolyVAO;
	OUniformBufferPtr m_uniform;
};

