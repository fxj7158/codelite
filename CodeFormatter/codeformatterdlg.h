//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah                            
// file name            : codeformatterdlg.h              
//                                                                          
// -------------------------------------------------------------------------
// A                                                                        
//              _____           _      _     _ _                            
//             /  __ \         | |    | |   (_) |                           
//             | /  \/ ___   __| | ___| |    _| |_ ___                      
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )                     
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/                     
//              \____/\___/ \__,_|\___\_____/_|\__\___|                     
//                                                                          
//                                                  F i l e                 
//                                                                          
//    This program is free software; you can redistribute it and/or modify  
//    it under the terms of the GNU General Public License as published by  
//    the Free Software Foundation; either version 2 of the License, or     
//    (at your option) any later version.                                   
//                                                                          
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
 #ifndef __codeformatterdlg__
#define __codeformatterdlg__


#include "codeformatterdlgbase.h"
#include "formatoptions.h"

class CodeFormatter;

class CodeFormatterDlg : public CodeFormatterBaseDlg
{
	FormatOptions m_options;
	CodeFormatter *m_cf;
	wxString m_sampleCode;
	
protected:
	// Handlers for CodeFormatterBaseDlg events.
	void OnRadioBoxPredefinedStyle( wxCommandEvent& event );
	void OnRadioBoxBrackets( wxCommandEvent& event );
	void OnCheckBox( wxCommandEvent& event );
	void OnOK(wxCommandEvent &e);
	void OnHelp(wxCommandEvent &e);
	void EnableFlag(size_t &options, size_t flag, bool enable);
	void InitDialog();
	void UpdateCheckBox(wxCheckBox *obj, size_t flag);
	void UpdatePreview();
	void UpdatePredefinedHelpText();
	void OnSplitterIdle(wxIdleEvent &e);
	
public:
	/** Constructor */
	CodeFormatterDlg( wxWindow* parent, CodeFormatter *cf, const FormatOptions& opts, const wxString &sampleCode );
	~CodeFormatterDlg();
	FormatOptions GetOptions() const{return m_options;}
};

#endif // __codeformatterdlg__
