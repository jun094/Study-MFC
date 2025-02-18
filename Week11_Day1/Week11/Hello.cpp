#include <afxwin.h>
#include "Hello.h"

CMyApp myApp; // 전역변수 -> 가장 먼저 실행 -> 여기에 main함수가 숨겨져있음. -> main 가장 먼저 실행됨
			  // main은 모든 코드에서 뼈대로 동일하기 때문에 숨겨져있음

/////////////////////////////////////////////////////////////////////////
// CMyApp member functions

BOOL CMyApp::InitInstance () // InitInstance : 객체 초기화
{
    m_pMainWnd = new CMainWindow; // CMainWindow : 화면에 보이는 창 그 자체
	

   m_pMainWnd->ShowWindow (m_nCmdShow); // CMainWindow의 ShowWindow메소드 : 창의 가시적으로 보여주는 메소드
    m_pMainWnd->UpdateWindow (); 
    return TRUE;
}

/////////////////////////////////////////////////////////////////////////
// CMainWindow message map and member functions

BEGIN_MESSAGE_MAP (CMainWindow, CFrameWnd)
    ON_WM_PAINT ()
	//직접 핸들러 추가한 부분 
	ON_WM_LBUTTONDOWN () 

END_MESSAGE_MAP ()

CMainWindow::CMainWindow ()
{
    Create (NULL, _T ("The Hello Application"));
}

void CMainWindow::OnPaint () // 우리가 커스터마이징 할 곳
{
    CPaintDC dc (this); // dc : main window의 하얀 화면
	static int x = 0; // 이 클래스에서만 사용하는 전역변수
	int y = 100; // 초기 좌표 설정

	dc.Rectangle(x,y,x+200,y+200); // 하얀 화면에 사각형 그릴꺼야
	//dc.Ellipse(150,150,250,350); // 하얀 화면에 타원형 그릴꺼야
	
	x++; // 중요 !!!!   화면 크기가 이동할 때마다 움직임 -> 계속에서 wm(윈도우메세지)가 계속 보내진다는 뜻..!!! 



    /*CRect rect;
    GetClientRect (&rect);

    dc.DrawText (_T ("Hello, MFC"), -1, &rect,
        DT_SINGLELINE | DT_CENTER | DT_VCENTER);*/
}


// Header에서 직접 핸들러 추가한 부분
void CMainWindow::OnLButtonDown(UINT flagas, CPoint point)
{
	//AfxMessageBox(_T("haha!"));
	Invalidate(); // 강제로 wm_paint를 부름 -> 왼쪽 마우스 클릭할떄마다 강제로 사각형 이동됨
}

