//小游戏demo 大嘴吃豆
# include <iostream>
#include <windows.h> //清屏功能的头文件
#include"conio.h"    //输入字符之后不用回车的头文件
#include <cstdlib>  //取随机数要用到
//清屏
//system("cls");
//系统暂停500毫秒
//Sleep(500);
//按任意键继续
//system("pause");
int main()
{   
	//设置食物坐标food_a为横坐标2-17取，food_b为纵坐标2-17取，food_c = food_a + food_b * 20
	int food_a;
	int food_b;
	int food_c;
	food_a = 5;
	food_b = 8;
	food_c = food_a + food_b * 20;
	//判断食物是否被吃到
	bool if_eat = false;
	//设置积分器
	int score = 0;
	//设置一个方向状态,0代表右，1代表左，2代表上，3代表下
	int goTo = 0;
	//设置一个动点move
	int move;
	//用x和y来表示动点move的坐标
	int x = 3;
	int y = 3;
	move = x + y * 20;
	//用来保存键盘输入的键 w上 s下 a左 d右
	char i;
	//用数组定义一个长为20，宽为20的世界地图
	//人为定义坐标从[0][0]开始到[19][19]结束
	int a[400] = {};
	//初始化数组，令要围成的边界赋值为1，其余都为0
	for (int i = 0; i < 400; i++)
	{    
		if (i < 20 || i > 380)//让第一行是边界
		{
			a[i] = 1;
		}
		else if (i % 20 == 0 || i % 20 == 19)//让第一列和最后一列是边界
		{
			a[i] = 1;
		}
		else
		{
			a[i] = 0;
		}
	}
	while (1)
	{
		//刷新屏幕
		system("cls");
		//打印世界地图
		for (int i = 0; i < 400; i++)
		{
			//先判断动点，再打印定点
			if (i == move) 
			{
				
				std::cout << "●";//打印动点，每个●占两个空格字符串
			}
			else if (i == food_c)
			{
				std::cout << "○";//打印动点，每个●占两个空格字符串
			}
			else 
			{
				if (a[i] == 1)
				{
					std::cout << "■";//打印边界，每个■占两个空格字符串
				}
				else
				{
					std::cout << "  ";//空白处用打印两个空格字符串代替
				}
			}
			//每隔20行，进行一次换行操作
			if (i % 20 == 19)
			{
				std::cout << std::endl;
			}
		}
		//打印当前积分
		std::cout << "当前的分数为: "<<score << std::endl;
		//每执行一次，暂停500毫秒
		Sleep(300);
		//通过goTo来判定移动方向
		switch (goTo)
		{
		case 0: { x++; }; break;
		case 1:{ x--; }; break;
		case 2: { y--; }; break;
		case 3:{ y++; }; break;
		default:break;
		}
		//碰到边界游戏退出
		if (x < 1 || x > 18 || y < 1 || y > 18) { break; }
		//获取输入来改变动点move坐标
		//kbhit()是等待输入，并且程序继续执行
		//i = getch()是获取键盘输入的值
		if (kbhit()) {
			i = getch();
			switch (i)
			{
			case 'w': { if (goTo != 3) { goTo = 2; } }; break;
			case 's': { if (goTo != 2) { goTo = 3; }}; break;
			case 'a': { if (goTo != 0) { goTo = 1; }}; break;
			case 'd': { if (goTo != 1) { goTo = 0; } }; break;
			default:break;
			}
		}
		move = x + y * 20;
		//如果食物被吃了，刷新食物位置
		if (move == food_c)
		{
			score = score + 1;
			if_eat = true;
		}
		if (if_eat == true)
		{
			food_a = rand() % (17 - 2 + 1) + 2;
			food_b = rand() % (17 - 2 + 1) + 2;
			food_c = food_a + food_b * 20;
			if_eat = false;
		}
	}
	std::cout << "大嘴碰到了边界，游戏结束！"<<std::endl;
	return 0;
}