
// MusicPadDlg.h: 头文件
//

#pragma once
#include "MusicSource.h"
#include "Common.h"
#include "NotePlayer.h"
#include "AddNoteDlg.h"


// CMusicPadDlg 对话框
class CMusicPadDlg : public CDialog
{
// 构造
public:
	CMusicPadDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MUSICPAD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	//控件变量
	CListCtrl m_note_list_ctrl;

	//
	CMusicSource m_music_source;
	CNotePlayer m_music_note;
	//int m_mode;				//调式
	//int m_full_note_time;	//一个全音符的时间

	CString m_file_path;
	bool m_modified{ false };				//如果文件被编辑过，则m_modified为true
	int m_item_selected{};

	void ListCtrlInsertBackItem(Note note);
	void ListCtrlModifyItem(int index, Note note);
	void ListCtrlDeleteItem(int index);
	void ListCtrlDeleteBackItem();
	void ShowNoteList();
	void AllToUI();

	bool SaveInquiry(LPCTSTR info = NULL);	//询问用户是否保存，参数为提示信息(用户点击了取消后返回false，否则返回true)
	void SetTitle();				//设置窗口标题
	bool _OnFileSave();		//如果已经执行了保存操作，则返回true，否则返回false
	bool _OnFileSaveAs();	//

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPlayButton();
	afx_msg void OnBnClickedAddNoteButton();
	afx_msg void OnBnClickedDeleteBackButton();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	CComboBox m_mode_combo;
	afx_msg void OnCbnSelchangeModeCombo();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnNMDblclkNoteList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClose();
	afx_msg void OnBnClickedEditSelectButton();
	afx_msg void OnNMClickNoteList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickNoteList(NMHDR *pNMHDR, LRESULT *pResult);
};
