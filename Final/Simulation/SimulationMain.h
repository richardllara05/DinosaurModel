/***************************************************************
 * Name:      SimulationMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2020-03-30
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef SIMULATIONMAIN_H
#define SIMULATIONMAIN_H
//(*Headers(SimulationFrame)
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/frame.h>
//*)
#include <wx/timer.h>
#include <wx/msgdlg.h>
#include <wx/log.h>
#include <string>
#include <wx/stattext.h>

#define SECONDS \
1000


static long TIMER_ID = -5;


class SimulationFrame: public wxFrame
{
    public:

        SimulationFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SimulationFrame();

    private:

        //(*Handlers(SimulationFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnNotebook1PageChanged(wxNotebookEvent& event);
        //*)

        //(*Identifiers(SimulationFrame)
        static const long ID_NOTEBOOK1;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(SimulationFrame)
        wxPanel* Panel1;
        wxNotebook* Notebook1;
        //*)
        void AddArena(wxImageList* images);
        void Render(wxTimerEvent& event);
        wxTimer elapsed_time;
        DECLARE_EVENT_TABLE()
};

#endif // SIMULATIONMAIN_H
