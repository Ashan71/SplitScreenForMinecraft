// 包含必要的头文件
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// 返回屏幕分辨率
int ScreenWH(int type)
{
	// 获取窗口
	HWND desktop = GetDesktopWindow();
	// 获取分辨率
	RECT rect;
	GetWindowRect(desktop, &rect);
	int screenWidth = rect.right - rect.left;
	int screenHeight = rect.bottom - rect.top;

	if (type == 0)
	{
		return screenWidth;
	}
	else
	{
		return screenHeight;
	}
}

// 分屏
void SplitScreen2(int PlayerID)
{
	while (true)
	{
		system("cls");
		//提示输入
		cout << "请输入" << PlayerID << "号玩家窗口标题" << endl;
		//获取窗口
		wstring WindowName;
		wcin >> WindowName;
		HWND Window = FindWindow(NULL, WindowName.c_str());
		//判读窗口是否有效
		if (Window != NULL)
		{
			// 将窗口设置为无边框窗口模式
			SetWindowLong(Window, GWL_STYLE, GetWindowLong(Window, GWL_STYLE) and not WS_CAPTION);
			// 设置窗口大小
			int Width = ScreenWH(0);
			int Height = ScreenWH(1) / 2;
			// 设置窗口位置
			int Y = PlayerID == 1 ? 0 : Height;
			//if (PlayerID == 1)
			//{
			//	Y = 0;
			//}
			//else
			//{
			//	Y = Height;
			//}
			// 移动和调整窗口大小
			SetWindowPos(Window, HWND_TOPMOST, 0, Y, Width, Height, SWP_SHOWWINDOW);
			break;
		}
		else
		{
			system("cls");
			cout << "找不到窗口..." << endl;
			Sleep(1000);
		}
	}

}

void SplitScreen3(int PlayerID) {
	while (true)
	{
		system("cls");
		//提示输入
		cout << "请输入" << PlayerID << "号玩家窗口标题" << endl;
		//获取窗口
		wstring WindowName;
		wcin >> WindowName;
		HWND Window = FindWindow(NULL, WindowName.c_str());
		//判读窗口是否有效
		if (Window != NULL)
		{
			// 将窗口设置为无边框窗口模式
			SetWindowLong(Window, GWL_STYLE, GetWindowLong(Window, GWL_STYLE) and not WS_CAPTION);
			// 设置窗口大小和位置
			int Width = 0, Height = 0, X = 0, Y = 0;
			switch (PlayerID)
			{
			case 1: {
				Width = ScreenWH(0);
				Height = ScreenWH(1) / 2;
				X = 0;
				Y = ScreenWH(1) / 2;
				break;
				}
			case 2: {
				Width = ScreenWH(0) / 2;
				Height = ScreenWH(1) / 2;
				X = 0;
				Y = 0;
				break;
				}
			case 3: {
				Width = ScreenWH(0) / 2;
				Height = ScreenWH(1) / 2;
				X = ScreenWH(0) / 2;
				Y = 0;
				break;
				}
			}
			// 移动和调整窗口大小
			SetWindowPos(Window, HWND_TOPMOST, X, Y, Width, Height, SWP_SHOWWINDOW);
			break;
		}
		else
		{
			system("cls");
			cout << "找不到窗口..." << endl;
			Sleep(1000);
		}
	}
}

void SplitScreen4(int PlayerID) {
	while (true)
	{
		system("cls");
		//提示输入
		cout << "请输入" << PlayerID << "号玩家窗口标题" << endl;
		//获取窗口
		wstring WindowName;
		wcin >> WindowName;
		HWND Window = FindWindow(NULL, WindowName.c_str());
		//判读窗口是否有效
		if (Window != NULL)
		{
			// 将窗口设置为无边框窗口模式
			SetWindowLong(Window, GWL_STYLE, GetWindowLong(Window, GWL_STYLE) and not WS_CAPTION);
			// 设置窗口大小和位置
			int Width = 0, Height = 0, X = 0, Y = 0;
			switch (PlayerID)
			{
			case 1: {
				Width = ScreenWH(0) / 2;
				Height = ScreenWH(1) / 2;
				X = 0;
				Y = 0;
				break;
			}
			case 2: {
				Width = ScreenWH(0) / 2;
				Height = ScreenWH(1) / 2;
				X = ScreenWH(0) / 2;
				Y = 0;
				break;
			}
			case 3: {
				Width = ScreenWH(0) / 2;
				Height = ScreenWH(1) / 2;
				X = 0;
				Y = ScreenWH(1) / 2;
				break;
			}
			case 4: {
				Width = ScreenWH(0) / 2;
				Height = ScreenWH(1) / 2;
				X = ScreenWH(0) / 2;
				Y = ScreenWH(1) / 2;
				break;
			}
			}
			// 移动和调整窗口大小
			SetWindowPos(Window, HWND_TOPMOST, X, Y, Width, Height, SWP_SHOWWINDOW);
			break;
		}
		else
		{
			system("cls");
			cout << "找不到窗口..." << endl;
			Sleep(1000);
		}
	}
}

int main()
{
	//此处置顶控制台，以免多人分屏时控制台被游戏窗口挡住
	HWND console = GetForegroundWindow();
	SetWindowPos(console, HWND_TOPMOST, NULL, NULL, NULL, NULL, SWP_NOMOVE | SWP_NOSIZE);
	// 获取用户输入
	int number = 0;
	string input;
	//检查用户输入是否有效
	while (true)
	{
		system("cls");
		cout << "您的分辨率是: " << ScreenWH(0) << "x" << ScreenWH(1) << endl << endl;
		cout << "注：多人分屏时游戏窗口将置顶，可能会挡住其他窗口" << endl << "项目Github网址：https://github.com/KingTom871/SplitScreenForMinecraft" << endl << endl;
		cout << "单人无边框全屏 --- 1" << endl
			<< "双人上下分屏 --- 2" << endl
			<< "三人分屏 --- 3" << endl
			<< "四人分屏 --- 4" << endl
			<< "请选择..." << endl;

		cin >> input;

		try
		{
			number = stoi(input);
			if (number >= 1 && number <= 4)
			{
				break;
			}
		}
		catch (const exception& e)
		{
		}
	}

	switch (number)
	{
		//单人全屏无边框
	case 1:
	{
		while (true)
		{
			system("cls");
			cout << "请输入游戏窗口标题" << endl;
			//获取窗口
			wstring WindowName;
			wcin >> WindowName;
			HWND Window = FindWindow(NULL, WindowName.c_str());

			//判断窗口是否有效
			if (Window != NULL)
			{
				SetWindowLong(Window, GWL_STYLE, GetWindowLong(Window, GWL_STYLE) and not WS_CAPTION);
				SetWindowPos(Window, NULL, 0, 0, ScreenWH(0), ScreenWH(1), SWP_SHOWWINDOW);
				break;
			}
			else {
				system("cls");
				cout << "找不到窗口...";
				Sleep(1000);
			}
		}
		break;
	}
	case 2:
	{
		SplitScreen2(1);
		SplitScreen2(2);
		break;
	}
	case 3: {
		SplitScreen3(1);
		SplitScreen3(2);
		SplitScreen3(3);
		break;
	}
	case 4: {
		SplitScreen4(1);
		SplitScreen4(2);
		SplitScreen4(3);
		SplitScreen4(4);
		break;
	}
	return 0;
	}
}