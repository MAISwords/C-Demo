//С��Ϸdemo ����Զ�
# include <iostream>
#include <windows.h> //�������ܵ�ͷ�ļ�
#include"conio.h"    //�����ַ�֮���ûس���ͷ�ļ�
#include <cstdlib>  //ȡ�����Ҫ�õ�
//����
//system("cls");
//ϵͳ��ͣ500����
//Sleep(500);
//�����������
//system("pause");
int main()
{   
	//����ʳ������food_aΪ������2-17ȡ��food_bΪ������2-17ȡ��food_c = food_a + food_b * 20
	int food_a;
	int food_b;
	int food_c;
	food_a = 5;
	food_b = 8;
	food_c = food_a + food_b * 20;
	//�ж�ʳ���Ƿ񱻳Ե�
	bool if_eat = false;
	//���û�����
	int score = 0;
	//����һ������״̬,0�����ң�1������2�����ϣ�3������
	int goTo = 0;
	//����һ������move
	int move;
	//��x��y����ʾ����move������
	int x = 3;
	int y = 3;
	move = x + y * 20;
	//���������������ļ� w�� s�� a�� d��
	char i;
	//�����鶨��һ����Ϊ20����Ϊ20�������ͼ
	//��Ϊ���������[0][0]��ʼ��[19][19]����
	int a[400] = {};
	//��ʼ�����飬��ҪΧ�ɵı߽縳ֵΪ1�����඼Ϊ0
	for (int i = 0; i < 400; i++)
	{    
		if (i < 20 || i > 380)//�õ�һ���Ǳ߽�
		{
			a[i] = 1;
		}
		else if (i % 20 == 0 || i % 20 == 19)//�õ�һ�к����һ���Ǳ߽�
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
		//ˢ����Ļ
		system("cls");
		//��ӡ�����ͼ
		for (int i = 0; i < 400; i++)
		{
			//���ж϶��㣬�ٴ�ӡ����
			if (i == move) 
			{
				
				std::cout << "��";//��ӡ���㣬ÿ����ռ�����ո��ַ���
			}
			else if (i == food_c)
			{
				std::cout << "��";//��ӡ���㣬ÿ����ռ�����ո��ַ���
			}
			else 
			{
				if (a[i] == 1)
				{
					std::cout << "��";//��ӡ�߽磬ÿ����ռ�����ո��ַ���
				}
				else
				{
					std::cout << "  ";//�հ״��ô�ӡ�����ո��ַ�������
				}
			}
			//ÿ��20�У�����һ�λ��в���
			if (i % 20 == 19)
			{
				std::cout << std::endl;
			}
		}
		//��ӡ��ǰ����
		std::cout << "��ǰ�ķ���Ϊ: "<<score << std::endl;
		//ÿִ��һ�Σ���ͣ500����
		Sleep(300);
		//ͨ��goTo���ж��ƶ�����
		switch (goTo)
		{
		case 0: { x++; }; break;
		case 1:{ x--; }; break;
		case 2: { y--; }; break;
		case 3:{ y++; }; break;
		default:break;
		}
		//�����߽���Ϸ�˳�
		if (x < 1 || x > 18 || y < 1 || y > 18) { break; }
		//��ȡ�������ı䶯��move����
		//kbhit()�ǵȴ����룬���ҳ������ִ��
		//i = getch()�ǻ�ȡ���������ֵ
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
		//���ʳ�ﱻ���ˣ�ˢ��ʳ��λ��
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
	std::cout << "���������˱߽磬��Ϸ������"<<std::endl;
	return 0;
}