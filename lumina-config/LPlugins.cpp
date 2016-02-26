//===========================================
//  Lumina-DE source code
//  Copyright (c) 2014, Ken Moore
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
#include "LPlugins.h"

#include <LuminaUtils.h>

LPlugins::LPlugins(){
  LoadPanelPlugins();
  LoadDesktopPlugins();
  LoadMenuPlugins();
  LoadColorItems();
}

LPlugins::~LPlugins(){
}

//Plugin lists
QStringList LPlugins::panelPlugins(){
  QStringList pan = PANEL.keys();
    pan.sort();
  return pan;
}
QStringList LPlugins::desktopPlugins(){
  QStringList desk = DESKTOP.keys();
	desk.sort();
  return desk;
}
QStringList LPlugins::menuPlugins(){
    QStringList men = MENU.keys();
	men.sort();
  return men;
}
QStringList LPlugins::colorItems(){
  return COLORS.keys();
}
//Information on individual plugins
LPI LPlugins::panelPluginInfo(QString plug){
  if(PANEL.contains(plug)){ return PANEL[plug]; }
  else{ return LPI(); }
}
LPI LPlugins::desktopPluginInfo(QString plug){
  if(DESKTOP.contains(plug)){ return DESKTOP[plug]; }
  else{ return LPI(); }
}
LPI LPlugins::menuPluginInfo(QString plug){
  if(MENU.contains(plug)){ return MENU[plug]; }
  else{ return LPI(); }
}
LPI LPlugins::colorInfo(QString item){
  if(COLORS.contains(item)){ return COLORS[item]; }
  else{ return LPI(); }  
}

//===================
//             PLUGINS
//===================
void LPlugins::LoadPanelPlugins(){
  PANEL.clear();
  //User Button
  LPI info;
    info.name = QObject::tr("User Button");
    info.description = QObject::tr("This is the main system access button for the user (applications, directories, settings, log out).");
    info.ID = "userbutton";
    info.icon = "user-identity";
  PANEL.insert(info.ID, info);
   //Application Menu
  info = LPI(); //clear it
    info.name = QObject::tr("Application Menu");
    info.description = QObject::tr("This provides instant-access to application that are installed on the system.");
    info.ID = "appmenu";
    info.icon = "format-list-unordered";
  PANEL.insert(info.ID, info);   
  //Desktop Bar
  info = LPI(); //clear it
    info.name = QObject::tr("Desktop Bar");
    info.description = QObject::tr("This provides shortcuts to everything in the desktop folder - allowing easy access to all your favorite files/applications.");
    info.ID = "desktopbar";
    info.icon = "user-desktop";
  PANEL.insert(info.ID, info);  
  //Spacer
  info = LPI(); //clear it
    info.name = QObject::tr("Spacer");
    info.description = QObject::tr("Invisible spacer to separate plugins.");
    info.ID = "spacer";
    info.icon = "transform-move";
  PANEL.insert(info.ID, info);
  //Line
  info = LPI(); //clear it
    info.name = QObject::tr("Line");
    info.description = QObject::tr("Simple line to provide visual separation between items.");
    info.ID = "line";
    info.icon = "insert-horizontal-rule";
  PANEL.insert(info.ID, info);  	
  //Desktop Switcher
  info = LPI(); //clear it
    info.name = QObject::tr("Workspace Switcher");
    info.description = QObject::tr("Controls for switching between the various virtual desktops.");
    info.ID = "desktopswitcher";
    info.icon = "preferences-desktop-display-color";
  PANEL.insert(info.ID, info);  	
  //Battery
  info = LPI(); //clear it
    info.name = QObject::tr("Battery Monitor");
    info.description = QObject::tr("Keep track of your battery status.");
    info.ID = "battery";
    info.icon = "battery-charging";
  PANEL.insert(info.ID, info);  	
  //Clock
  info = LPI(); //clear it
    info.name = QObject::tr("Time/Date");
    info.description = QObject::tr("View the current time and date.");
    info.ID = "clock";
    info.icon = "preferences-system-time";
  PANEL.insert(info.ID, info);  
  //System Dachboard plugin
  info = LPI(); //clear it
    info.name = QObject::tr("System Dashboard");
    info.description = QObject::tr("View or change system settings (audio volume, screen brightness, battery life, virtual desktops).");
    info.ID = "systemdashboard";
    info.icon = "dashboard-show";
  PANEL.insert(info.ID, info);  
  //Task Manager
  info = LPI(); //clear it
    info.name = QObject::tr("Task Manager");
    info.description = QObject::tr("View and control any running application windows (every application has a button)");
    info.ID = "taskmanager";
    info.icon = "preferences-system-windows";
  PANEL.insert(info.ID, info); 
  //Task Manager
  info = LPI(); //clear it
    info.name = QObject::tr("Task Manager (No Groups)");
    info.description = QObject::tr("View and control any running application windows (every window has a button)");
    info.ID = "taskmanager-nogroups";
    info.icon = "preferences-system-windows";
  PANEL.insert(info.ID, info); 
  //System Tray
  info = LPI(); //clear it
    info.name = QObject::tr("System Tray");
    info.description = QObject::tr("Display area for dockable system applications");
    info.ID = "systemtray";
    info.icon = "preferences-system-windows-actions";
  PANEL.insert(info.ID, info);  
  //Home Button
  info = LPI(); //clear it
    info.name = QObject::tr("Show Desktop");
    info.description = QObject::tr("Hide all open windows and show the desktop");
    info.ID = "homebutton";
    info.icon = "user-desktop";
  PANEL.insert(info.ID, info);
  //Start Menu
  info = LPI(); //clear it
    info.name = QObject::tr("Start Menu");
    info.description = QObject::tr("Unified system access and application launch menu.");
    info.ID = "systemstart";
    info.icon = "Lumina-DE";
  PANEL.insert(info.ID, info);  
  //Application Launcher
  info = LPI(); //clear it
    info.name = QObject::tr("Application Launcher");
    info.description = QObject::tr("Pin an application shortcut directly to the panel");
    info.ID = "applauncher";
    info.icon = "quickopen";
  PANEL.insert(info.ID, info); 
}

void LPlugins::LoadDesktopPlugins(){
  DESKTOP.clear();
  //Calendar Plugin
  LPI info;
    info.name = QObject::tr("Calendar");
    info.description = QObject::tr("Display a calendar on the desktop");
    info.ID = "calendar";
    info.icon = "view-calendar";
  DESKTOP.insert(info.ID, info);
  //Application Launcher Plugin
  info = LPI(); //clear it
    info.name = QObject::tr("Application Launcher");
    info.description = QObject::tr("Desktop button for launching an application");
    info.ID = "applauncher";
    info.icon = "quickopen";
  DESKTOP.insert(info.ID, info);
  //Desktop View Plugin
  info = LPI(); //clear it
    info.name = QObject::tr("Desktop Icons View");
    info.description = QObject::tr("Area for automatically showing desktop icons");
    info.ID = "desktopview";
    info.icon = "preferences-desktop-icons";
  DESKTOP.insert(info.ID, info);
  //Notepad Plugin
  info = LPI(); //clear it
    info.name = QObject::tr("Note Pad");
    info.description = QObject::tr("Keep simple text notes on your desktop");
    info.ID = "notepad";
    info.icon = "text-enriched";
  DESKTOP.insert(info.ID, info);
  //Audio Player Plugin
  info = LPI(); //clear it
    info.name = QObject::tr("Audio Player");
    info.description = QObject::tr("Play through lists of audio files");
    info.ID = "audioplayer";
    info.icon = "media-playback-start";
  DESKTOP.insert(info.ID, info);
  //System Monitor Plugin
  info = LPI(); //clear it
    info.name = QObject::tr("System Monitor");
    info.description = QObject::tr("Keep track of system statistics such as CPU/Memory usage and CPU temperatures.");
    info.ID = "systemmonitor";
    info.icon = "cpu";
  DESKTOP.insert(info.ID, info);
  //Available QtQuick scripts
  /*QStringList quickID = LUtils::listQuickPlugins();
  for(int i=0; i<quickID.length(); i++){
    QStringList quickinfo = LUtils::infoQuickPlugin(quickID[i]); //Returns: [name, description, icon]
    if(quickinfo.length() < 3){ continue; } //invalid file (unreadable/other)
    info = LPI();
      info.name = quickinfo[0];
      info.description = quickinfo[1];
      info.ID = "quick-"+quickID[i]; //the "quick-" prefix is required for the desktop plugin syntax 
      info.icon = quickinfo[2];
    DESKTOP.insert(info.ID, info);	  
  }*/
}

void LPlugins::LoadMenuPlugins(){
  MENU.clear();
  //Terminal
  LPI info;
    info.name = QObject::tr("Terminal");
    info.description = QObject::tr("Start the default system terminal.");
    info.ID = "terminal";
    info.icon = "utilities-terminal";
  MENU.insert(info.ID, info);
  //File Manager
  info = LPI(); //clear it
    info.name = QObject::tr("File Manager");
    info.description = QObject::tr("Browse the system with the default file manager.");
    info.ID = "filemanager";
    info.icon = "Insight-FileManager";
  MENU.insert(info.ID, info);
  //Applications
  info = LPI(); //clear it
    info.name = QObject::tr("Applications");
    info.description = QObject::tr("Show the system applications menu.");
    info.ID = "applications";
    info.icon = "system-run";
  MENU.insert(info.ID, info);
  //Line seperator
  info = LPI(); //clear it
    info.name = QObject::tr("Separator");
    info.description = QObject::tr("Static horizontal line.");
    info.ID = "line";
    info.icon = "insert-horizontal-rule";
  MENU.insert(info.ID, info);
  //Settings
  info = LPI(); //clear it
    info.name = QObject::tr("Settings");
    info.description = QObject::tr("Show the desktop settings menu.");
    info.ID = "settings";
    info.icon = "configure";
  MENU.insert(info.ID, info);
  //Window List
  info = LPI(); //clear it
    info.name = QObject::tr("Window List");
    info.description = QObject::tr("List the open application windows");
    info.ID = "windowlist";
    info.icon = "preferences-system-windows";
  MENU.insert(info.ID, info);  
  //Custom Apps
  info = LPI(); //clear it
    info.name = QObject::tr("Custom App");
    info.description = QObject::tr("Start a custom application");
    info.ID = "app";
    info.icon = "application-x-desktop";
  MENU.insert(info.ID, info);
}

void LPlugins::LoadColorItems(){
  COLORS.clear();
  //Primary Text Color
  LPI info;
    info.name = QObject::tr("Primary text");
    info.description = QObject::tr("Color to use for all visible primary text.");
    info.ID = "PRIMARYTEXTCOLOR";
  COLORS.insert(info.ID, info);
  //Primary Text Color (Disabled)
  info = LPI(); //clear it
    info.name = QObject::tr("Primary text (Disabled)");
    info.description = QObject::tr("Primary text color for disabled or inactive items.");
    info.ID = "PRIMARYTEXTDISABLECOLOR";
  COLORS.insert(info.ID, info);
  //Primary Text Color (Highlighted)
  info = LPI(); //clear it
    info.name = QObject::tr("Primary text (Highlighted)");
    info.description = QObject::tr("Primary text color when selection is highlighted.");
    info.ID = "PRIMARYTEXTHIGHLIGHTCOLOR";
  COLORS.insert(info.ID, info);
  //Secondary Text Color
  info = LPI(); //clear it
    info.name = QObject::tr("Secondary text");
    info.description = QObject::tr("Color to use for all visible secondary text.");
    info.ID = "SECONDARYTEXTCOLOR";
  COLORS.insert(info.ID, info);
  //Secondary Text Color (Disabled)
  info = LPI(); //clear it
    info.name = QObject::tr("Secondary text (Disabled)");
    info.description = QObject::tr("Secondary text color for disabled or inactive items.");
    info.ID = "SECONDARYTEXTDISABLECOLOR";
  COLORS.insert(info.ID, info);
  //Secondary Text Color (Highlighted)
  info = LPI(); //clear it
    info.name = QObject::tr("Secondary text (Highlighted)");
    info.description = QObject::tr("Secondary text color when selection is highlighted.");
    info.ID = "SECONDARYTEXTHIGHLIGHTCOLOR";
  COLORS.insert(info.ID, info);
  //Base Color (Normal)
  info = LPI(); //clear it
    info.name = QObject::tr("Base Window Color");
    info.description = QObject::tr("Main background color for the window/dialog.");
    info.ID = "BASECOLOR";
  COLORS.insert(info.ID, info);
  //Base Color (Alternate)
  info = LPI(); //clear it
    info.name = QObject::tr("Base Window Color (Alternate)");
    info.description = QObject::tr("Main background color for widgets that list or display collections of items.");
    info.ID = "ALTBASECOLOR";
  COLORS.insert(info.ID, info);
  //Primary Color (Normal)
  info = LPI(); //clear it
    info.name = QObject::tr("Primary Color");
    info.description = QObject::tr("Dominant color for the theme.");
    info.ID = "PRIMARYCOLOR";
  COLORS.insert(info.ID, info);
  //Primary Color (Disabled)
  info = LPI(); //clear it
    info.name = QObject::tr("Primary Color (Disabled)");
    info.description = QObject::tr("Dominant color for the theme (more subdued).");
    info.ID = "PRIMARYDISABLECOLOR";
  COLORS.insert(info.ID, info);
  //Secondary Color (Normal)
  info = LPI(); //clear it
    info.name = QObject::tr("Secondary Color");
    info.description = QObject::tr("Alternate color for the theme.");
    info.ID = "SECONDARYCOLOR";
  COLORS.insert(info.ID, info);
  //Secondary Color (Disabled)
  info = LPI(); //clear it
    info.name = QObject::tr("Secondary Color (Disabled)");
    info.description = QObject::tr("Alternate color for the theme (more subdued).");
    info.ID = "SECONDARYDISABLECOLOR";
  COLORS.insert(info.ID, info);
  //Accent Color (Normal)
  info = LPI(); //clear it
    info.name = QObject::tr("Accent Color");
    info.description = QObject::tr("Color used for borders or other accents.");
    info.ID = "ACCENTCOLOR";
  COLORS.insert(info.ID, info);
  //Accent Color (Disabled)
  info = LPI(); //clear it
    info.name = QObject::tr("Accent Color (Disabled)");
    info.description = QObject::tr("Color used for borders or other accents (more subdued).");
    info.ID = "ACCENTDISABLECOLOR";
  COLORS.insert(info.ID, info);
  //Highlight Color (Normal)
  info = LPI(); //clear it
    info.name = QObject::tr("Highlight Color");
    info.description = QObject::tr("Color used for highlighting an item.");
    info.ID = "HIGHLIGHTCOLOR";
  COLORS.insert(info.ID, info);
  //Highlight Color (Disabled)
  info = LPI(); //clear it
    info.name = QObject::tr("Highlight Color (Disabled)");
    info.description = QObject::tr("Color used for highlighting an item (more subdued).");
    info.ID = "HIGHLIGHTDISABLECOLOR";
  COLORS.insert(info.ID, info);
}