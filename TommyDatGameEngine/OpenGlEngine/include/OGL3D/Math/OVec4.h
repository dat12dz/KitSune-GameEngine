#include <OGL3D/OPreRequisites.h>
#ifndef OVec4_HEADER
class OVec4
{
public:
	OVec4(f32 x, f32 y, f32 z, f32 w) : x(x), y(y), z(z), w(w)
	{

	}
	~OVec4()
	{

	}
public:
	f32 x = 0, y = 0, z = 0, w = 0;
};
#define OVec4_HEADER
#endif // !OVec4_HEADER
