#include <OGL3D/Math/ORect.h>

class OWindow
{

public :
	OWindow();
	~OWindow();
	Orect getInnerWindowSize();
	void makeCurrentContext();
	void present(bool vsync);
private:
	void* m_handle;
	void* m_context;
};

