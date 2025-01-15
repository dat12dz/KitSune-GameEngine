#include <memory>
#include <OGL3D/OPreRequisites.h>
#include <OGL3d/Graphic/OVertexArrayObject.h>
#include <OGL3D/Graphic/OShaderProgram.h>
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
	OShaderProgramPtr m_shader;
protected:
	bool m_isRunning = true;
    std::unique_ptr<OWindow> m_display = 0;
	std::unique_ptr<OGraphicEngine> m_graphicEngine;
	OVertexArrayObjectPtr m_triangleVAO;
};

