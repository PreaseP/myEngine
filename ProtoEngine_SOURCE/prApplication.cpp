#include "prApplication.h"
#include "prInput.h"

namespace pr 
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
	{
	
	}

	Application::~Application()
	{
		ReleaseDC(mHwnd, mHdc);
	}

	void Application::Initialize(HWND hwnd) 
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		mPlayer.SetPosition(0, 0);
		Input::Initialize();
	}

	void Application::Run() 
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() 
	{
		Input::Update();

		mPlayer.Update();
	}

	void Application::LateUpdate() 
	{
		
	}

	void Application::Render() 
	{
		mPlayer.Render(mHdc);
	}
}