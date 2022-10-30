#pragma once
#include "MainFrame.h"

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

/*! \class ImagifyApp
    Main application component.
*/
class ImagifyApp: public wxApp
{
public:
    //! Class constructor.
    ImagifyApp();
    
    //! Class deconstructor.
    ~ImagifyApp();

    virtual bool OnInit();

private:
    MainFrame* frame; //!< Currently displayed window.
};
