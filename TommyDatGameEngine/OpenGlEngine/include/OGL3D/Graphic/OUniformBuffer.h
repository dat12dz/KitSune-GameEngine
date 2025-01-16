#include <OGL3D/OPreRequisites.h>

class OUniformBuffer
{
public:
	OUniformBuffer(const OUniformBufferDesc& desc);
	OUniformBuffer();
	~OUniformBuffer();
	void SetData(void* data);
	uint GetID()
	{
		return m_id;
	}

private:
	uint m_size;
	uint m_id;
};

