//
// Created by Z3X0S on 14/07/24.
//

#include "MainFrame.h"
#include <wx/wx.h>
#include "Register.h"



MainFrame::MainFrame(const wxString &title): wxFrame(nullptr, wxID_ANY, title) {
    Register registro = Register();
    panel = new wxPanel(this);
    addActButton = new wxButton(panel, wxID_ANY, "Add Activity", wxDefaultPosition, wxSize(100,35));
    deleteActButton = new wxButton(panel, wxID_ANY, "Delete Activity", wxPoint(250,200), wxSize(100,35));
    actName = new wxTextCtrl(panel, wxID_ANY, "Name", wxPoint(120,10), wxSize(100,20));
    actDesc = new wxTextCtrl(panel, wxID_ANY, "Description", wxPoint(10,50), wxSize(210,20));
    actHStart = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(230, 10), wxSize(50,20), wxSP_WRAP, 0,23);
    actHEnd = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(230, 50), wxSize(50,20), wxSP_WRAP, 0,23);
    actMStart = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(290, 10), wxSize(50,20), wxSP_WRAP, 0,59);
    actMEnd = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(290, 50), wxSize(50,20), wxSP_WRAP, 0,59);
    actList = new wxListBox(panel, wxID_ANY, wxPoint(10,100), wxSize(350,100));

    addActButton->Bind(wxEVT_BUTTON, &MainFrame::OnAddActivityClicked, this);
    deleteActButton->Bind(wxEVT_BUTTON, &MainFrame::OnDeleteActivityClicked, this);

}

void MainFrame::refreshList() {
    actList->Clear();
    list<Activity> activities = registro.getActivities();
    for (auto it = activities.begin(); it != activities.end(); ++it){
        actList->Insert(it->toString(), actList->GetCount());
    }

}

void MainFrame::OnAddActivityClicked(wxCommandEvent &evt) {

    string nameVal = string(actName->GetValue().mb_str());
    string descVal = string(actDesc->GetValue());


    int hStartVal = int(actHStart->GetValue());
    int hEndVal = int(actHEnd->GetValue());
    int mStartVal = int(actMStart->GetValue());
    int mEndVal = int(actMEnd->GetValue());
    try {
        registro.addActivity(nameVal, descVal, hStartVal, mStartVal, hEndVal, mEndVal);
    }
    catch (invalid_argument &e){
        wxMessageDialog dialog(this, e.what(), "Message");
        dialog.ShowModal();
    }
    actName->Clear();
    actDesc->Clear();
    refreshList();
}

void MainFrame::OnDeleteActivityClicked(wxCommandEvent &evt){
    string selection = string(actList->GetStringSelection().mb_str());
    registro.removeActivity(selection);
    refreshList();
}