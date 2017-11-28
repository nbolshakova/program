
// kaskadDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "kaskad.h"
#include "kaskadDlg.h"
#include "afxdialogex.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ïîääåðæêà DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// диалоговое окно CkaskadDlg

CkaskadDlg::CkaskadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CkaskadDlg::IDD, pParent)

	, m_veroyat()
	, m_lenght_message()
	, m_potok_error(_T(""))
	, m_nu(0)
	, m_alfa()
	, m_dlit()
	, m_error_for_OPP(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CkaskadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT3, m_veroyat);
	DDX_Text(pDX, IDC_EDIT4, m_lenght_message);
	DDX_Text(pDX, IDC_EDIT5, m_potok_error);
	DDX_Text(pDX, IDC_EDIT6, m_nu);
	DDX_Text(pDX, IDC_EDIT7, m_alfa);
	DDX_Text(pDX, IDC_EDIT8, m_dlit);
	DDX_Text(pDX, IDC_EDIT11, m_error_for_OPP);
	DDX_Control(pDX, IDC_LIST3, m_list);
	DDX_Control(pDX, IDC_LIST4, m_listDCK);
}

BEGIN_MESSAGE_MAP(CkaskadDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CkaskadDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CkaskadDlg::OnBnClickedButton2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST4, &CkaskadDlg::OnLvnItemchangedList4)
END_MESSAGE_MAP()


// обработчики сообщений CkaskadDlg

BOOL CkaskadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//  Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	CString Header;
	int arColWidth[] = {250,110};
	//int iNumCols = 7; //кол-во колонок

	for (int i=0; i<2; i++)
	{
		Header.LoadStringW(IDS_LISTCOL+i);
		m_list.InsertColumn(i,Header,LVCFMT_LEFT,arColWidth[i]);
	}
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	for (int i=0; i<2; i++)
	{
		Header.LoadStringW(IDS_LISTCOL+i);
		m_listDCK.InsertColumn(i,Header,LVCFMT_LEFT,arColWidth[i]);
	}
	m_listDCK.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	flag2=false;
	flag1=false;

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CkaskadDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CkaskadDlg::OnPaint()
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
HCURSOR CkaskadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CkaskadDlg::OnBnClickedButton1()
{
	unsigned int N;
	float P, r;
	UpdateData(true);

	//Считываем с экрана
	P = m_veroyat;   //
	N = m_lenght_message;

	if(N <= 0)
	{
		MessageBox(_T("N > 0 !"));
		return;
	}
	if(P > 1.0)
	{
		MessageBox(_T("P <= 1 !"));
		return;
	} 
	int counter=0;
	bool* message = new bool[N];
	CString str, str_err;
	int cnt_err=0,pos_err=0, h;

	for (counter=0; counter < N; counter++)
	{
	    r=((float)(rand() % 100) / 100);   //генерируем вероятность ошибки в бите
		if (P < r)
			message[counter]=0; //ошибка в текущем бите ???поменять на 1???		
		else
			message[counter]=1; //нет ошибки   ????поменять на 0?????
	}
	
	//регистрация ошибок ДСК
	for (counter=0; counter < N; counter++)
	{
	  if( message[counter] == 1)
	  {
		  str += "1";  //error - для вывода результата в виде строки

		  str_err.Format(_T("От %d до %d ошибки"), cnt_err, cnt_err+1);
		  h = m_listDCK.GetItemCount();
		  m_listDCK.InsertItem(h,_T(""));
		  m_listDCK.SetItemText(cnt_err,0,str_err);
		  if(cnt_err == 0)
			str_err.Format(_T("%d"), counter - pos_err);
		  else
			str_err.Format(_T("%d"), counter - pos_err-1);
		  m_listDCK.SetItemText(cnt_err,1,str_err);
		  cnt_err++;		  
		  pos_err = counter;
	  }
	  else
		  str += "0";   //ok - для вывода результата в виде строки
	}
	m_potok_error=str;

	if(flag1 == true) 
		for(int t=0;t<=cnt_err_del1; t++)
		{
			m_listDCK.SetItemText(cnt_err+t,0,_T(""));
			m_listDCK.SetItemText(cnt_err+t,1,_T(""));
		}
	UpdateData(false);

	flag1=true;
	cnt_err_del1 = cnt_err;
}

void CkaskadDlg::OnBnClickedButton2()
{
	unsigned int N;
	float P, r,x,alfa,nu;
	UpdateData(true);
	
	nu = m_nu;
	if(nu < 1.0)
	{
		MessageBox(_T("NU > 1.0 !"));
		return;
	}

	alfa=m_alfa;
	N=m_dlit;
	if(N <= 0)
	{
		MessageBox(_T("N > 0 !"));
		return;
	}
	int counter=0, lenght, a=0;
	bool* message = new bool[N];

    counter=0;
	r=((float)(rand() % 100) / 100.0);   
	float v = powf(r, 1.0/nu);
	x = alfa/v-alfa;
	lenght= (int)(x + 1.0);   //берем ближайшее большее целое

	do{
		if (counter==(a+lenght))
		{
			if ((a+lenght) < N)
			{
				 message[counter]=1; //ошибка в текущем бите.
				 r=((float)(rand() % 100) / 100.0);   //генерируем вероятность ошибки в бите
				 v = powf(r, 1.0/nu);
				 x = alfa/v-alfa;
				 lenght= (int)(x + 1.0);   //берем ближайшее большее целое
				 a=counter;
			}
		}
		else 
			message[counter]=0; //нет ошибки в текущем бите.Текущий бит=0
		counter++;
	}while(counter != N);

	CString str = _T("");
	for (counter=0; counter < N; counter++)
	{
	  if( message[counter] == 0)
		  str += "0";  
	  else
		  str += "1";
	}
	m_error_for_OPP=str;  //в строчку
	
	/**********/
		
	int cnt_err=0,pos_err=0, h;
	CString str_err;
	for (counter=0; counter < N; counter++)
	{
	  if( message[counter] == 1)
	  {
		  //str += "1";  //error
		  str_err.Format(_T("От %d до %d ошибки"), cnt_err, cnt_err+1);
		  h = m_list.GetItemCount();
		  m_list.InsertItem(h,_T(""));
		  m_list.SetItemText(cnt_err,0,str_err);
		  if(cnt_err == 0)
			str_err.Format(_T("%d"), counter - pos_err);
		  else
			str_err.Format(_T("%d"), counter - pos_err-1);

		  //str_err.Format(_T("%d"), counter - pos_err);
		  m_list.SetItemText(cnt_err,1,str_err);
		  cnt_err++;		  
		  pos_err = counter;
	  }
	 // else
		 // str += "1";
	}
	/**********/
	if(flag2 == true) 
		for(int t=0;t<=cnt_err_del2; t++)
		{
			m_list.SetItemText(cnt_err+t,0,_T(""));
			m_list.SetItemText(cnt_err+t,1,_T(""));
		}
	UpdateData(false);
	UpdateWindow();

	flag2=true;
	cnt_err_del2 = cnt_err;
}


void CkaskadDlg::OnLvnItemchangedList4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}
