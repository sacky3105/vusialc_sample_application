// GUISampleApplication.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "framework.h"
#include "GUISampleApplication.h"


INT_PTR CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message){
    case WM_INITDIALOG:
        return true;

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDOK:
            TCHAR szBuf[256];
            GetDlgItemText(hDlg, IDC_EDIT1, szBuf, _countof(szBuf));
            OutputDebugString(szBuf);
            OutputDebugString(TEXT("\n"));
            return true;
        case IDCANCEL:
            EndDialog(hDlg, IDCANCEL);
            return true;
        default:
            return false;
        }
    default:
        return false;
    }
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    const auto nID =DialogBoxParam
    (hInstance
        , MAKEINTRESOURCE(IDD_DIALOG1)
        , nullptr
        , DialogProc
        , 0
    );
    return 0;
}
