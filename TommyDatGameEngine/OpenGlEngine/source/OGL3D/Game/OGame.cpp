#include <OGL3D/Windows/OGame.h>
#include <OGL3D/Windows/OWindow.h>
#include <OGL3D/Graphic/OGraphicEngine.h>
#include <Windows.h>

OGame::OGame()
{
	m_graphicEngine = std::make_unique<OGraphicEngine>();
	m_display = std::make_unique<OWindow>();
	m_display->makeCurrentContext();
	m_graphicEngine->SetViewPort(m_display->getInnerWindowSize());
}
void OGame::Run()
{

	MSG msg;
	OnCreate();
	while (m_isRunning)
	{
		if (PeekMessageW(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				m_isRunning = false;
				continue;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		OnUpdate();
	}
	OnQuit();
}
void OGame::OnCreate()
{
	const float triVert[] = {
		-0.5f, -0.5f, 0.0f,
		1,		0,		0,
		0.5f, -0.5f, 0.0f,
		0,		1,		0,
		0.0f, 0.5f, 0.0f,
		0,		0,		1
	};
	OVertexAtrribute attributesList[] = {
	3,// pos
	3 // color
	};
	m_triangleVAO = m_graphicEngine->createVertexArrayObject({ 
															(void*)triVert,// Mảng thông tin của hình
															sizeof(float) * 6,// Kích cỡ của cả hình ở trong bộ nhớ ram
															3, // Số điểm trong hình
															attributesList,
															2
	});

	m_shader = m_graphicEngine->createShaderProgram({
		 L"Asset/Shader/BasicShader.vert",
		 L"Asset/Shader/BasicShader.frag"
	});
}
void OGame::OnUpdate()
{
	m_graphicEngine->clear(OVec4(0, 0, 0, 1));
	m_graphicEngine->setVertextArrayObj(m_triangleVAO);
	m_graphicEngine->SetShaderProgram(m_shader);
	m_graphicEngine->DrawTriangle(m_triangleVAO->GetVertexBufferSize(), 0);
	m_display->present(false);
}
void OGame::OnQuit()
{
}
void OGame::Quit()
{
	m_isRunning = false;
}
OGame :: ~OGame()
{
	m_isRunning = false;
}