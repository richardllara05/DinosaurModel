/***************************************************************
 * Name:      SimulationMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2020-03-30
 * Copyright:  ()
 * License:
 **************************************************************/

#include "SimulationMain.h"

//(*InternalHeaders(SimulationFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(SimulationFrame)
const long SimulationFrame::ID_NOTEBOOK1 = wxNewId();
const long SimulationFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SimulationFrame,wxFrame)
    //(*EventTable(SimulationFrame)
    //*)
    EVT_TIMER(TIMER_ID, SimulationFrame::Render)
END_EVENT_TABLE()

SimulationFrame::SimulationFrame(wxWindow* parent,wxWindowID id):elapsed_time(this, TIMER_ID)
{
    //(*Initialize(SimulationFrame)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(8,8), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxDefaultPosition, wxSize(392,448), wxHSCROLL, _T("ID_NOTEBOOK1"));
    //*)

    // Add wxImageList Here
    AddArena();
    Notebook1->Layout();

   // Create environment with dinosaur array in random spots
}

SimulationFrame::~SimulationFrame()
{
    //(*Destroy(SimulationFrame)
    //*)
}

// Adds pages to each tab
// AddPage accepts any object that inherits from wxWindow
void SimulationFrame::AddArena(wxImageList* images)
{
   for(auto image_index = 0; image_index != images.GetImageCount(); ++image_index){
       wxString index = wxString::Format("%i", image_index + 1);
       Notebook1->AddPage(images.Draw(image_index), wxString::Format("Arena %i"), image_index);

       //Notebook1->AddPage(new wxStaticText(Notebook1, wxID_ANY, "Hello"), index); // For testing
   }
}

void SimulationFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void SimulationFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

// Executes every 1 second
void SimulationFrame::Render(wxTimerEvent& event)
{
   // Add tick event here
}


