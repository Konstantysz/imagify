#include "ImagifyApp.h"

wxIMPLEMENT_APP(ImagifyApp);

ImagifyApp::ImagifyApp()
{
}

ImagifyApp::~ImagifyApp()
{
}

bool ImagifyApp::OnInit()
{
	frame = new MainFrame();
	frame->Show();

	return true;
}
