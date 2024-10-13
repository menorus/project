
// MFCApplication3Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CMFCApplication3Dlg



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
	, poisk(_T("c:\\windows\\system32\\"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, spisok);
	DDX_Control(pDX, IDC_LIST2, otkritoe);
	DDX_Text(pDX, IDC_EDIT1, poisk);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplication3Dlg

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	SetTimer(1, 500, NULL);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication3Dlg::OnBnClickedButton2()
{
	spisok.ResetContent();
	UpdateData(TRUE);

	CFileFind finder;
	BOOL bWorking = finder.FindFile(poisk + L"*.exe", 0);
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		spisok.AddString(finder.GetFileName());
	}

	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCApplication3Dlg::OnBnClickedButton3()
{
	if (spisok.GetCurSel() != -1) {

		STARTUPINFO sStartUp = { sizeof(STARTUPINFO) };
		PROCESS_INFORMATION sPi;

		int nIndex = spisok.GetCurSel();
		spisok.GetText(nIndex, name);
		rar = poisk + name;

		LPTSTR open_ = _tcsdup(rar);
		STARTUPINFO si = { sizeof(si) };
		PROCESS_INFORMATION pi = { 0 };
		BOOL Otcr = CreateProcess(NULL, open_, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
		otkritoe.AddString(name);
		CloseHandle(pi.hThread);
		mas.push_back(pi.hProcess);
		
	}
	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCApplication3Dlg::OnBnClickedButton1()
{
	if (otkritoe.GetCurSel() != -1) {
		int nIndex = otkritoe.GetCurSel();
		TerminateProcess(mas[nIndex], Exit);
	}
	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCApplication3Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	for (int i = 0; i < mas.size(); i++) {
		DWORD const1 = 0; 
		GetExitCodeProcess(mas[i], &const1);
		if (const1 != STILL_ACTIVE) {
			CloseHandle(mas[i]);
			mas.erase(mas.begin() + i);
			otkritoe.DeleteString(i);
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}
