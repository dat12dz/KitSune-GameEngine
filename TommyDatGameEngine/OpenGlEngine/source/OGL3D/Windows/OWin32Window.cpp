#include <OGL3D/Windows/OWindow.h>
#include <Windows.h>
#include <glad/glad.h>
#include <glad/glad_wgl.h>
#include <assert.h>
LRESULT CALLBACK WndProce(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		{
			OWindow* wind = (OWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
			break;
		}
	case WM_CLOSE:
	{
		PostQuitMessage(0);
	}
	default:
		return DefWindowProc(hwnd, msg, wparam, lParam);
		break;
	}
	return 0;
}

OWindow::OWindow()
{
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"TommyDat#dWIndow";
	wc.lpfnWndProc = &WndProce;
	wc.style = CS_OWNDC;
	auto class_id = RegisterClassExW(&wc);
	// create window handles
	m_handle = CreateWindowExW(NULL, MAKEINTATOM(class_id), L"Better game engine please", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		1024, 768, NULL, NULL, NULL, NULL);
   assert(m_handle);
   SetWindowLongPtr(HWND(m_handle), GWLP_USERDATA, (LONG_PTR)this);
   ShowWindow((HWND)m_handle, SW_SHOW);
   UpdateWindow((HWND)m_handle);

   // Tạo opengl context
   auto hDC = GetDC(HWND(m_handle));

   int pixel_format_Atrtribute[] = {
	   WGL_DRAW_TO_WINDOW_ARB,GL_TRUE,
	   WGL_SUPPORT_OPENGL_ARB,GL_TRUE,
	   WGL_DOUBLE_BUFFER_ARB,GL_TRUE,
	   WGL_ACCELERATION_ARB,WGL_FULL_ACCELERATION_ARB,
	   WGL_PIXEL_TYPE_ARB,WGL_TYPE_RGBA_ARB,
	   WGL_COLOR_BITS_ARB,32,
	   WGL_DEPTH_BITS_ARB,24,
	   WGL_STENCIL_BITS_ARB,8,
	   0
   };
   int pixel_Format = 0;
   UINT num_Format = 0;
   // Chọn pixel format gần với miêu tả ở trên nhất
   wglChoosePixelFormatARB(hDC, pixel_format_Atrtribute,nullptr,1,&pixel_Format,&num_Format);
   PIXELFORMATDESCRIPTOR pixelFormatDesc;

  // Hàm DescribePixelFormat lấy thông tin mô tả chi tiết về pixel format đã chọn và lưu vào pixelFormatDesc.
   DescribePixelFormat(hDC, pixel_Format, sizeof(PIXELFORMATDESCRIPTOR), &pixelFormatDesc);
   SetPixelFormat(hDC, pixel_Format, &pixelFormatDesc);
   // Tạo phên bản
   int OpenGlAtrribute[] = {
		WGL_CONTEXT_MAJOR_VERSION_ARB,4,
		WGL_CONTEXT_MINOR_VERSION_ARB,6,
	   WGL_CONTEXT_PROFILE_MASK_ARB,WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
	   0
   };
   m_context = wglCreateContextAttribsARB(hDC,0, OpenGlAtrribute);
   assert(m_context);
   
}

OWindow:: ~OWindow()
{
	// Giải phóng context
	wglDeleteContext((HGLRC)m_context);
	DestroyWindow((HWND)m_handle);
}

Orect OWindow::getInnerWindowSize()
{
	RECT rc;
	GetClientRect((HWND)m_handle, &rc);
	return Orect(rc.right - rc.left, rc.bottom - rc.top);
}

void OWindow::makeCurrentContext()
{
	auto result =	wglMakeCurrent(GetDC((HWND)m_handle),HGLRC(m_context));
	assert(result);
}

void OWindow::present(bool vsync)
{
	wglSwapIntervalEXT(vsync);
	wglSwapLayerBuffers(GetDC((HWND)m_handle),WGL_SWAP_MAIN_PLANE);
}

