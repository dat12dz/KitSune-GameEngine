#include <OGL3D/OPreRequisites.h>

class OVertexArrayObject
{
public:
	OVertexArrayObject(const OVertexBufferDesc& buffer );
	~OVertexArrayObject();

	uint getID();
	uint GetVertexBufferSize();
	uint GetVertextSize();
private:
	int m_vertexAraay;
	unsigned int m_vertexBufferID,
				 m_vertexArrayObjectID;
	OVertexBufferDesc m_vertBufferData;

};

