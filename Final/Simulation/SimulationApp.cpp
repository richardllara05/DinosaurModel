/***************************************************************
 * Name:      SimulationApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2020-03-30
 * Copyright:  ()
 * License:
 **************************************************************/

#include "SimulationApp.h"

//(*AppHeaders
#include "SimulationMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SimulationApp);

bool SimulationApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	SimulationFrame* Frame = new SimulationFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
