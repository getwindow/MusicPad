#pragma once
#include "SpinEdit.h"
#include "Common.h"

// CAddNoteDlg 对话框

class CAddNoteDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddNoteDlg)

public:
	CAddNoteDlg(Note note, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAddNoteDlg();

	const Note& GetNote() const { return m_note; }

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_NOTE_DIALOG };
#endif

protected:
	//控件变量
	CSpinEdit m_note_name_edit;
	CSpinEdit m_octave_edit;
	CSpinEdit m_note_type_edit;
	CSpinEdit m_signature_edit;

	Note m_note;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();
};
