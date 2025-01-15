#include <OGL3D/OPreRequisites.h>
class OShaderProgram
{
public:
	OShaderProgram(const OShaderProgramDesc& desc);
	~OShaderProgram();
	uint getID();
private:
	void attach(const wchar_t* shaderPath,const OShaderType& type);
	void link();

private :
	uint m_programId;
	uint m_attachedShaders[2] = {};
};

