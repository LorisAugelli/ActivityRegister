//
// Created by Z3X0S on 14/07/24.
//

#ifndef ACTIVITYREGISTER_MAINFRAME_H
#define ACTIVITYREGISTER_MAINFRAME_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "Register.h"

class MainFrame : public wxFrame {
    public:
        MainFrame(const wxString& title);
    private:
        void OnAddActivityClicked(wxCommandEvent& evt);
        void refreshList();
        Register registro = Register();
        wxPanel* panel;
        wxButton* addActButton;
        wxTextCtrl* actName;
        wxTextCtrl* actDesc;
        wxSpinCtrl* actHStart;
        wxSpinCtrl* actHEnd;
        wxSpinCtrl* actMStart;
        wxSpinCtrl* actMEnd;
        wxListBox* actList;

};


#endif //ACTIVITYREGISTER_MAINFRAME_H
