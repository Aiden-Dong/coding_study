#include<windows.h>
#include<tchar.h>
#include<time.h>
#include<list>

#define ID_TIMER 1
#define ID_START 2
#define ID_PAUSE 3
#define ID_HELP 4
#define ID_RESTART 5
#define ID_QUIT 6
#define ID_COMBOBOX 7
#define LEFT 8
#define UP 9
#define RIGHT 10
#define DOWN 11
#define ID_ESC 27

HWND hHelp;						     //帮助信息对话框句柄
HINSTANCE hInst;					     //实例句柄
RECT rtSnakeHead, rtSnakeNeck, rtSnakeTail, rtFood, rtScore; //重绘区域   
RECT rtMap;						     //地图区域
unsigned int score = 0;					     //得分
int nextDirection;					     //蛇头的下一运动方向
bool foodFlag = false;                                       //标记食物是否还存在
bool gameOver = true;                                        //标记游戏是否结束

//蛇身结点定义
typedef struct{
	int left;
	int top;
	int right;
	int bottom;
	int currentDirection;

}SnakeNode;
std::list<SnakeNode>snake;   //整个蛇身

// 此代码模块中包含的函数的前向声明:
ATOM			   MyRegisterClass(HINSTANCE hInstance);                 //注册窗口类
BOOL			   InitInstance(HINSTANCE, int);		         //初始化窗口各种控件
LRESULT CALLBACK   WndProc(HWND, UINT, WPARAM, LPARAM);                          //主窗口回调函数
VOID               DrawSurroundings(HDC hdc, HWND hWnd, RECT rtFood);            //绘制地图
VOID			   DrawTheSnake(HDC hdc, HWND hWnd);                     //绘制蛇身
VOID			   GetTimerElapse(int cursel, unsigned int& timerElapse);//获取用户选择的速度
VOID               SnakeMove(RECT rtFood, int timerElapse);                      //蛇身移动
RECT			   CreateFood(HDC hdc);					 //生成食物
BOOL               JudgeGameOver(SnakeNode headNode);                            //判断是否达到游戏结束条件
INT_PTR CALLBACK   Help(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);  //帮助信息对话框回调函数

//程序入口
int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	srand((UINT)time(0));   //时间作为随机数种子
	MSG msg;
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	// 主消息循环:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		SnakeNode& headNode = snake.back();  //获取蛇头所在结点
		//获取方向键消息
		switch(msg.wParam)
		{
		case VK_LEFT:
			if(headNode.currentDirection != RIGHT)
				nextDirection = LEFT;
			break;
		case VK_UP:
			if(headNode.currentDirection != DOWN)
				nextDirection = UP;
			break;
		case VK_RIGHT:
			if(headNode.currentDirection != LEFT)
				nextDirection = RIGHT;
			break;
		case VK_DOWN:
			if(headNode.currentDirection != UP)
				nextDirection = DOWN;
			break;
		}

		if (!TranslateMessage(&msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}

//注册窗口类
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(wcex);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName  = _T("贪吃蛇");
	wcex.hIconSm		= NULL;

	return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance; // 将实例句柄存储在全局变量中

	hWnd = CreateWindowExA(0, "贪吃蛇", "贪吃蛇蛋疼版", WS_OVERLAPPED|WS_SYSMENU|WS_MINIMIZEBOX,
		380, 90, 606, 568, NULL, NULL, hInstance, NULL);
	CreateWindowA("button", "开始游戏", WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, 
		20, 10, 100, 30, hWnd, (HMENU)ID_START, hInstance, NULL);
	CreateWindowA("button", "暂停/继续", WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, 
		150, 10, 100, 30, hWnd, (HMENU)ID_PAUSE, hInstance, NULL);
	CreateWindowA("button", "帮助", WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, 
		280, 12, 40, 25, hWnd, (HMENU)ID_HELP, hInstance, NULL);
	CreateWindowA("button", "重玩一局", WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, 
		350, 10, 100, 30, hWnd, (HMENU)ID_RESTART, hInstance, NULL);
	CreateWindowA("button", "退出游戏", WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, 
		480, 10, 100, 30, hWnd, (HMENU)ID_QUIT, hInstance, NULL);
	CreateWindowA("ComboBox", "速度选择", WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST,
		60, 55, 55, 200, hWnd, (HMENU)ID_COMBOBOX, hInstance, NULL);

	//创建帮助信息对话框
	static DLGTEMPLATE Dlg;
	Dlg.cdit = 0;
	Dlg.cx = 200;
	Dlg.cy = 140;
	Dlg.dwExtendedStyle = 0;
	Dlg.style = WS_POPUPWINDOW|WS_CAPTION;
	Dlg.x = 50;
	Dlg.y = 60;
	hHelp = CreateDialogIndirect(hInst, &Dlg, hWnd, Help);
	SetWindowTextA(hHelp, "帮助");
	ShowWindow(hHelp, SW_HIDE);

	//注册快捷键
	RegisterHotKey(hWnd, ID_START, MOD_CONTROL, VK_RIGHT);
	RegisterHotKey(hWnd, ID_PAUSE, NULL, VK_SPACE);
	RegisterHotKey(hWnd, ID_RESTART, MOD_CONTROL|MOD_SHIFT, VK_SPACE);
	RegisterHotKey(hWnd, ID_HELP, NULL, VK_F1);
	RegisterHotKey(hWnd, ID_ESC, NULL, VK_ESCAPE);

	SendMessageA(GetDlgItem(hWnd,ID_COMBOBOX),
		CB_ADDSTRING, NULL, (LPARAM)("特快"));
	SendMessageA(GetDlgItem(hWnd,ID_COMBOBOX),
		CB_ADDSTRING, NULL, (LPARAM)("较快"));
	SendMessageA(GetDlgItem(hWnd,ID_COMBOBOX),
		CB_ADDSTRING, NULL, (LPARAM)("普通"));
	SendMessageA(GetDlgItem(hWnd,ID_COMBOBOX),
		CB_ADDSTRING, NULL, (LPARAM)("缓慢"));
	SendMessageA(GetDlgItem(hWnd,ID_COMBOBOX),
		CB_ADDSTRING, NULL, (LPARAM)("龟速"));
	SendMessageA(GetDlgItem(hWnd,ID_COMBOBOX), CB_SETCURSEL, 2, NULL);  //默认选择第三项

	EnableWindow(GetDlgItem(hWnd, ID_PAUSE), false); //游戏未开始【暂停/继续】按钮无效

	//初始化蛇身长度及位置
	for(int i=rtMap.left+40;i<140;i+=20)
	{
		SnakeNode node;
		node.left = i;
		node.top = rtMap.top+40;
		node.right = i+20;
		node.bottom = rtMap.top+60;
		node.currentDirection = RIGHT;
		snake.push_back(node);
	}
	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	static bool bPause;              //游戏是否暂停
	static unsigned int timerElapse; //定时器时间间隔
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_CREATE:
		RECT rtClient;
		int xBrickAmount,yBrickAmount;     //X轴、Y轴砖块数量（每块砖的边长为20）
		GetClientRect(hWnd, &rtClient);    //获取客户区域大小
		xBrickAmount = (rtClient.right-rtClient.left)/20;
		yBrickAmount = (rtClient.bottom-rtClient.top)/20;
		rtMap.left = rtClient.left;
		rtMap.top = rtClient.top+80;
		rtMap.right = rtClient.left+xBrickAmount*20;
		rtMap.bottom = rtClient.top+yBrickAmount*20;

		//输出得分的区域
		rtScore.left = 260;
		rtScore.top = rtMap.top-29;
		rtScore.right = 400;
		rtScore.bottom = rtMap.top-1;
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		switch (wmId)
		{
		case ID_START:
			{
				bPause = false;
				gameOver = false;
				nextDirection = RIGHT;                                                             //初始方向向右
				int cursel = SendMessage(GetDlgItem(hWnd, ID_COMBOBOX), CB_GETCURSEL, NULL, NULL); //获取用户选择的速度索引号
				GetTimerElapse(cursel, timerElapse);   
				SetTimer(hWnd, ID_TIMER, timerElapse, NULL);
				EnableWindow(GetDlgItem(hWnd,ID_COMBOBOX), false);
				EnableWindow(GetDlgItem(hWnd, ID_PAUSE), true);
				EnableWindow(GetDlgItem(hWnd, ID_START), false);
			}
			break;
		case ID_PAUSE:
			{
				if(!gameOver)
				{
					if(bPause)
					{
						SetTimer(hWnd, ID_TIMER, timerElapse, NULL);
						bPause = false;
					}
					else
					{
						KillTimer(hWnd, ID_TIMER);
						bPause = true;
					}
				}
			}
			break;
		case ID_RESTART:
			{
				KillTimer(hWnd, ID_TIMER);
				snake.clear();               //清空蛇身所有结点
				//重新初始化蛇身长度及位置
				for(int i=rtMap.left+40; i<140; i+=20)
				{
					SnakeNode node;
					node.left = i;
					node.top = rtMap.top+40;
					node.right = i+20;
					node.bottom = node.top+20;
					node.currentDirection = RIGHT;
					snake.push_back(node);
				}
				gameOver = true;
				score = 0;
				EnableWindow(GetDlgItem(hWnd, ID_START), true);
				EnableWindow(GetDlgItem(hWnd, ID_PAUSE), false);
				EnableWindow(GetDlgItem(hWnd, ID_COMBOBOX), true);
				InvalidateRect(hWnd, &rtMap, true);
				InvalidateRect(hWnd, &rtScore, true);
			}
			break;
		case ID_HELP:
			{
				if(!bPause)
				{
					SendMessage(hWnd, WM_COMMAND, ID_PAUSE, NULL);
				}
				ShowWindow(hHelp, SW_SHOWNORMAL);
			}
			break;
		case ID_QUIT:
			SendMessage(hWnd, WM_CLOSE, NULL, NULL);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		//食物被吃掉后重绘分数并再次生成食物
		if(!foodFlag)
		{
			InvalidateRect(hWnd, &rtScore, true);
			rtFood = CreateFood(hdc);
			InvalidateRect(hWnd, &rtFood, true);
		}
		DrawSurroundings(hdc, hWnd, rtFood);
		DrawTheSnake(hdc, hWnd);
		EndPaint(hWnd, &ps);
		break;
		//热键消息处理
	case WM_HOTKEY:
		{
			if((wParam == ID_ESC) && (hHelp == GetActiveWindow()))
				ShowWindow(hHelp, SW_HIDE);	
			else if(hWnd == GetActiveWindow())  //判断窗口是否处于激活状态
			{
				switch(wParam)
				{
				case ID_START:
					if(IsWindowEnabled(GetDlgItem(hWnd, ID_START)))
						SendMessage(hWnd, WM_COMMAND, ID_START, NULL);
					break;
				case ID_PAUSE:
					SendMessage(hWnd, WM_COMMAND, ID_PAUSE, NULL);
					break;
				case ID_RESTART:
					SendMessage(hWnd, WM_COMMAND, ID_RESTART, NULL);
					break;
				case ID_HELP:
					SendMessage(hWnd, WM_COMMAND, ID_HELP, NULL);
					break;
				case ID_ESC:
					SendMessage(hWnd, WM_CLOSE, NULL, NULL);
					break;
				}
			}
		}
		break;
		//定时器消息处理
	case WM_TIMER:
		SnakeMove(rtFood, timerElapse);
		InvalidateRect(hWnd, &rtSnakeHead, true);
		InvalidateRect(hWnd, &rtSnakeNeck, false);
		InvalidateRect(hWnd, &rtSnakeTail, true);
		break;
		//处理窗口最小化的消息
	case WM_SIZE:
		wmId = LOWORD(wParam);
		if(wmId == SIZE_MINIMIZED)
		{
			if(!gameOver && !bPause)
				SendMessage(hWnd, WM_COMMAND, ID_PAUSE, NULL);
		}
		break;
		//处理关闭窗口的消息
	case WM_CLOSE:
		{
			if(!gameOver)
			{
				KillTimer(hWnd, ID_TIMER);
				if(MessageBoxA(hWnd, "游戏正在进行，确认退出？", "提醒", MB_OKCANCEL|MB_ICONQUESTION) == IDOK)
				{
					DestroyWindow(hWnd);
					PostQuitMessage(0);
				}
				else if(!bPause && !gameOver)
					SetTimer(hWnd, ID_TIMER, timerElapse, NULL);
			}		
			if(gameOver && MessageBoxA(hWnd, "确认退出贪吃蛇蛋疼版？", "提醒", MB_OKCANCEL|MB_ICONQUESTION) == IDOK)
			{
				DestroyWindow(hWnd);
				PostQuitMessage(0);
			}
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

VOID DrawSurroundings(HDC hdc, HWND hWnd, RECT rtFood)
{	
	//绘制分割线
	MoveToEx(hdc, rtMap.left, rtMap.top-30, NULL);
	LineTo(hdc, rtMap.right, rtMap.top-30);

	TextOutA(hdc, 23, rtMap.top-22, "速度:", strlen("速度:")); 
	TextOutA(hdc, 480, rtMap.top-22, "By:非洲小白脸", strlen("By:非洲小白脸"));

	//自定义字体并输出得分
	char szScore[10];
	LOGFONT font;
	memset(&font, 0, sizeof(font));
	font.lfWidth = 11;
	font.lfHeight = 20;
	font.lfWeight = FW_HEAVY;
	lstrcpy(font.lfFaceName, _T("宋体"));
	HFONT hFont = CreateFontIndirect(&font);
	SelectObject(hdc, hFont);
	wsprintfA(szScore, "得分:%d", score);
	SetTextColor(hdc, RGB(0,99,201));
	TextOutA(hdc, 260, rtMap.top-24, szScore, strlen(szScore));
	DeleteObject(hFont);

	//绘制地图（砖块边长为20）
	HBRUSH hBrush = CreateSolidBrush(RGB(139,69,19));
	SelectObject(hdc, hBrush);
	for(int i=rtMap.left; i<rtMap.right; i+=20)
	{
		Rectangle(hdc, i, rtMap.top, i+20, rtMap.top+20);
		Rectangle(hdc, i, rtMap.bottom-20, i+20, rtMap.bottom);
	}
	for(int j=rtMap.top; j<rtMap.bottom; j+=20)
	{
		Rectangle(hdc, rtMap.left, j, rtMap.left+20, j+20);
		Rectangle(hdc, rtMap.right-20, j, rtMap.right, j+20);
	}

	//绘制食物
	hBrush = CreateSolidBrush(RGB(255,0,0));
	SelectObject(hdc, hBrush);
	Ellipse(hdc, rtFood.left, rtFood.top, rtFood.right, rtFood.bottom);
	DeleteObject(hBrush);
}

VOID GetTimerElapse(int cursel, unsigned int& timerElapse)	
{
	switch(cursel)
	{
	case 0:
		timerElapse = 50;
		break;
	case 1:
		timerElapse = 100;
		break;
	case 2:
		timerElapse = 200;
		break;
	case 3:
		timerElapse = 400;
		break;
	case 4:
		timerElapse = 600;
		break;
	}
}

VOID DrawTheSnake(HDC hdc, HWND hWnd)
{
	//画蛇身
	HBRUSH hBrush = CreateSolidBrush(RGB(124,252,0));
	SelectObject(hdc, hBrush);
	std::list<SnakeNode>::iterator sIter = snake.begin();
	for(unsigned int i=0; i<snake.size()-1; i++,sIter++)
		Rectangle(hdc, sIter->left, sIter->top, sIter->right, sIter->bottom);

	//画蛇头
	SnakeNode headNode = snake.back();
	switch(headNode.currentDirection)
	{
	case LEFT:
		{
			POINT ptHead[] = {sIter->left,sIter->top+5,
				sIter->right,sIter->top,
				sIter->right,sIter->bottom,
				sIter->left,sIter->bottom-5};
			Polygon(hdc, ptHead, 4);
		}
		break;
	case UP:
		{
			POINT ptHead[] = {sIter->left+5,sIter->top,
				sIter->right-5,sIter->top,
				sIter->right,sIter->bottom,
				sIter->left,sIter->bottom};
			Polygon(hdc, ptHead, 4);
		}
		break;
	case RIGHT:
		{
			POINT ptHead[] = {sIter->left,sIter->top,
				sIter->right,sIter->top+5,
				sIter->right,sIter->bottom-5,
				sIter->left,sIter->bottom};
			Polygon(hdc, ptHead, 4);
		}
		break;
	case DOWN:
		{
			POINT ptHead[] = {sIter->left,sIter->top,
				sIter->right,sIter->top,
				sIter->right-5,sIter->bottom,
				sIter->left+5,sIter->bottom,
			};
			Polygon(hdc, ptHead, 4);
		}
		break;
	}

	//判断游戏结束
	if(!gameOver)
	{
		if(JudgeGameOver(headNode))
		{
			KillTimer(hWnd, ID_TIMER);
			EnableWindow(GetDlgItem(hWnd, ID_PAUSE), false);
			MessageBoxA(hWnd, "Game Over!", "提醒", MB_OK);
		}
	}
}

VOID SnakeMove(RECT rtFood, int timerElapse)
{
	SnakeNode headNode = snake.back();
	//获取蛇颈区域
	rtSnakeNeck.left = headNode.left;
	rtSnakeNeck.top = headNode.top;
	rtSnakeNeck.right = headNode.right;
	rtSnakeNeck.bottom = headNode.bottom;

	SnakeNode node;
	//根据蛇头的下一方向算出蛇头的新位置
	switch(nextDirection)
	{
	case LEFT:
		node.left = headNode.left-20;
		node.top = headNode.top;
		node.right = headNode.left;
		node.bottom = headNode.bottom;
		node.currentDirection = LEFT;
		snake.push_back(node);
		break;
	case UP:
		node.left = headNode.left;
		node.top = headNode.top-20;
		node.right = headNode.right;
		node.bottom = headNode.top;
		node.currentDirection = UP;
		snake.push_back(node);
		break;
	case RIGHT:
		node.left = headNode.right;
		node.top = headNode.top;
		node.right = headNode.right+20;
		node.bottom = headNode.bottom;
		node.currentDirection = RIGHT;
		snake.push_back(node);
		break;
	case DOWN:
		node.left = headNode.left;
		node.top = headNode.bottom;
		node.right = headNode.right;
		node.bottom = headNode.bottom+20;
		node.currentDirection = DOWN;
		snake.push_back(node);
		break;
	}
	//获取蛇头区域
	headNode = snake.back();
	rtSnakeHead.left = headNode.left;
	rtSnakeHead.top = headNode.top;
	rtSnakeHead.right = headNode.right;
	rtSnakeHead.bottom = headNode.bottom;

	//未吃到食物
	if(!(headNode.left==rtFood.left && headNode.top==rtFood.top))
	{
		std::list<SnakeNode>::iterator iTail = snake.begin();
		rtSnakeTail.left = iTail->left;
		rtSnakeTail.top = iTail->top-1;
		rtSnakeTail.right = iTail->right;
		rtSnakeTail.bottom = iTail->bottom+1;
		snake.pop_front();      
	}
	//吃到食物
	else    	{
		switch(timerElapse)
		{
		case 50:
			score+=100;
			break;
		case 100:
			score+=60;
			break;
		case 200:
			score+=40;
			break;
		case 400:
			score+=20;
			break;
		case 600:
			score+=10;
			break;
		}
		foodFlag = false;
	}
}

RECT CreateFood(HDC hdc)
{
	RECT rtFood;                                //食物所在区域
	int xNumber, yNumber;			    //食物所在处对应的砖块序号
	int xBrickAmount,yBrickAmount;	            //X轴、Y轴砖块总量
	xBrickAmount = (rtMap.right-rtMap.left)/20; 
	yBrickAmount = (rtMap.bottom-rtMap.top)/20;
	//随机生成砖块序号
	xNumber = rand()%(xBrickAmount-2);          
	yNumber = rand()%(yBrickAmount-2);

	//根据砖块序号确定食物位置
	rtFood.left = rtMap.left+(xNumber+1)*20;
	rtFood.right = rtFood.left+20;
	rtFood.top = rtMap.top+(yNumber+1)*20;
	rtFood.bottom = rtFood.top+20;

	foodFlag = true;

	return rtFood;

}

BOOL JudgeGameOver(SnakeNode headNode)
{
	//碰到墙则游戏结束
	if(headNode.left==rtMap.left || headNode.top==rtMap.top 
		|| headNode.right==rtMap.right || headNode.bottom==rtMap.bottom)
	{
		gameOver = true;
		return true;
	}
	//咬到自己身体则游戏结束
	else
	{
		SnakeNode head = snake.back();
		std::list<SnakeNode>::iterator sIter = snake.begin();
		for(unsigned int i=0; i<snake.size()-1; i++,sIter++)
			if(head.left==sIter->left && head.top==sIter->top)
			{
				gameOver = true;
				return true;
			}
	}
	return false;
}

INT_PTR CALLBACK Help(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
		if(LOWORD(wParam) == IDCANCEL)
		{	
			ShowWindow(hDlg, SW_HIDE);
			return (INT_PTR)TRUE;
		}
		break;
	case WM_PAINT:
		{
			PAINTSTRUCT dPs;
			HDC hdc = BeginPaint(hDlg, &dPs);
			LOGFONT font;
			memset(&font, 0, sizeof(font));
			font.lfWidth = 8;
			font.lfHeight = 16;
			font.lfWeight = FW_HEAVY;
			lstrcpy(font.lfFaceName, _T("宋体"));
			HFONT hFont = CreateFontIndirect(&font);
			SelectObject(hdc, hFont);
			SetTextColor(hdc, RGB(111,55,155));
			SetBkColor(hdc, GetSysColor(COLOR_3DFACE));

			TextOutA(hdc, 5, 5, "游戏规则:", sizeof("游戏规则:"));
			std::string str = "1.通过方向键上、下、左、右控制蛇游动的方向。";
			TextOutA(hdc, 5, 25, str.c_str(), str.size());
			str = "2.该蛇有五种游动速度可供玩家选