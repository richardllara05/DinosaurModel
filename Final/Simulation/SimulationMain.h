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
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
//*)

class SimulationFrame: public wxFrame
{
    public:

        SimulationFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SimulationFrame();

    private:

        //(*Handlers(SimulationFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(SimulationFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(SimulationFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SIMULATIONMAIN_H
    