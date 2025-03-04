#pragma once
#include "CUserManager.h"
#include "CConfigManager.h"
// CStarRTCMenuDialog 对话框

class CStarRTCMenuDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CStarRTCMenuDialog)

public:
	CStarRTCMenuDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CStarRTCMenuDialog();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MENU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_UserIDEdit;
	CStatic m_UserPicPicControl;
	afx_msg void OnBnClickedButtonIm();
	afx_msg void OnBnClickedButtonMultipleMeeting();
	afx_msg void OnBnClickedButtonInteracteLive();

private:
	CUserManager* m_pUserManager;
	CConfigManager* m_pConfig;
public:
	//afx_msg void OnBnClickedButtonParamSetting();
	virtual BOOL OnInitDialog();
	bool m_bLogIn;
	afx_msg void OnBnClickedButtonLiveMonitor();
	afx_msg void OnBnClickedButtonLogin();
	afx_msg void OnBnClickedButtonVoip();
	afx_msg void OnBnClickedButtonVoiceChatroom();
	afx_msg void OnBnClickedButtonVoipP2p();
	afx_msg void OnBnClickedButtonMinClass();
	afx_msg void OnBnClickedButtonSuperChatroom();
};
