#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

/*! \class MainFrame
	Main window of the application.
*/
class MainFrame : public wxFrame
{
public:
	//! Class constructor
	MainFrame();

	//! Class deconstructor.
	~MainFrame();
};