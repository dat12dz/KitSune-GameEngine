#include <glad/glad.h>
#include <OGL3D/Graphic/OVertexArrayObject.h>
OVertexArrayObject::OVertexArrayObject(const OVertexBufferDesc& buffer)
{
	// Tạo buffer object VBO
	// 1 : Số lượng buffer cần tạo
	// m_vertexBufferID : trả về ID của buffer vừa tạo
	if (buffer.listSize == 0)
	{
		OGL3D_ERROR("Lớp OVertexArrayObject | ListSize đang bằng 0");
	}
	if (buffer.vertexSize == 0)
	{
		OGL3D_ERROR("Lớp OVertexArrayObject | VertexSize đang bằng 0");
	}
	if (buffer.verticesList == nullptr)
	{
		OGL3D_ERROR("Lớp OVertexArrayObject |  VerticesList đang bằng nullptr");
	}
	glGenBuffers(1, &m_vertexBufferID);
	// Tạo VAO : Vertex Array Object
	// 1 : Số lượng VAO cần tạo
	// m_vertexArrayObjectID : trả về ID của VAO vừa tạo
	glGenVertexArrays(1, &m_vertexArrayObjectID);
	// Kích hoạt VAO , sau khi kích hoạt thì các thao tác với VAO sẽ ảnh hưởng đến VAO đó
	glBindVertexArray(m_vertexArrayObjectID);

	// liên kết BUffer với một target
	// GL_ARRAY_BUFFER : Target này chỉ định buffer sẽ chứa dữ liệu của đỉnh
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
	// Copy dữ liệu từ CPU sang card đồ họa
	// GL_ARRAY_BUFFER :					 Tham số đầu phải trùng với glBindBuffer
	// buffer.vertexSize * buffer.listSize : Dữ liệu cần cấp phát trên card (byte)
	//  buffer.verticesList :				 Con trỏ đến vertiecesList
	// GL_STATIC_DRAW :						 Hint cho openGL giúp tối ưu hiệu suất
	glBufferData(GL_ARRAY_BUFFER, buffer.vertexSize * buffer.listSize, buffer.verticesList, GL_STATIC_DRAW);
	
	// Hàm này định nghĩa cách dữ liệu đỉnh được tổ chức trong buffer
	// 0 : Index của vertex attribute
	// 3 : số lượng thành phần của attribute
	// false : Không chuẩn hóa
	// buffer.vertexSize : Số byte của mỗi đỉnh cần cấp phát
	for (uint i = 0; i < buffer.attributeListSize; i++)
	{
		glVertexAttribPointer(
			i,
			buffer.attributesList[i].numElm,
			GL_FLOAT,
			false,
			buffer.vertexSize,
			(void*)((i == 0) ? 0 : buffer.attributesList[i - 1].numElm * sizeof(float)));
		glEnableVertexAttribArray(i);
	}
		// Kích hoạt vertex Atrribute tại index 0
		// hủy liên kết với VAO hiện tại
    glBindVertexArray(0);
	m_vertBufferData = buffer;
}

OVertexArrayObject::~OVertexArrayObject()
{
	// khai tử tất cả dữ liệu
	glDeleteBuffers(1, &m_vertexBufferID);
	glDeleteVertexArrays(1, &m_vertexArrayObjectID);
}

uint OVertexArrayObject::getID()
{
	return m_vertexArrayObjectID;
}

uint OVertexArrayObject::GetVertexBufferSize()
{
	return m_vertBufferData.listSize;
}

uint OVertexArrayObject::GetVertextSize()
{
	return m_vertBufferData.vertexSize;
}
