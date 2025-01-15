#include <OGL3D/OPreRequisites.h>
class Orect
{
public:
	int width = 0, height = 0,left = 0,right = 0;
public:
	Orect()
	{
	}
	Orect(int width, int height) : width(width), height(height)
	{
	}
	Orect(int width, int height,int left, int right) : left(left), right(right), width(width), height(height)
	{
	}
	Orect(const Orect& other)
	{
		width = other.width;
		height = other.height;
		left = other.left;
		right = other.right;
	}
};