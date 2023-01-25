#include<windows.h>

void Tm(HWND);
HWND hWnd;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain( HINSTANCE hInst, HINSTANCE hPrevInst,LPSTR lpCmdLine, int nCmdShow)
{ 
    MessageBox(NULL, L"HELLO", NULL, NULL);
    WNDCLASSW wcex = { 0 };
    wcex.lpfnWndProc = WndProc;
    wcex.hInstance = hInst;
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wcex.lpszClassName = L"windclass";
 
    if (!RegisterClassW(&wcex))
        return -1;

    CreateWindow( L"windclass", L"Main", WS_VISIBLE | WS_OVERLAPPEDWINDOW, 100, 100, 800, 800, NULL, NULL, NULL, NULL);

    MSG msg = { 0 };

    while (GetMessage(&msg, NULL, NULL, NULL))
    {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CREATE:
        
        break;

    case WM_PAINT:
        Tm(hWnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProcW(hWnd, msg, wParam, lParam);
    }
}
void Tm(HWND hWnd)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    Ellipse(hdc, 40, 40, 700, 700);
    TextOut(hdc, 40, 370, L"9", 1);
    TextOut(hdc, 700, 370, L"3", 1);
    TextOut(hdc, 370, 700, L"6", 1);
    TextOut(hdc, 370, 40, L"12", 2);
    MoveToEx(hdc, 370, 370,NULL);
    LineTo(hdc, 400, 450);
 
    

    MoveToEx(hdc, 100, 450, NULL);
    LineTo(hdc, 370, 370);

    MoveToEx(hdc, 250, 500, NULL);
    LineTo(hdc, 370, 370);

  

        EndPaint(hWnd, &ps);

}