//
// Created by Z3X0S on 14/07/24.
//

#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    MainFrame* mainFrame = new MainFrame("Activity Register");
    mainFrame->Center();
    mainFrame->SetClientSize(370,270);
    mainFrame->Show();
    return true;
}