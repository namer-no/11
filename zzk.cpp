#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
#define pi 3.1416
#define LEN sizeof(Node)
int i = 0;
class Shape                                       //ͼ����
{
public:
	virtual void GetPerimeter() = 0;
	virtual void GetArea() = 0;
	virtual void Print() = 0;
private:
	double x;
	double y;
	double Perimeter;
	double Area;
	char *ShapeName;
};
class Point :public Shape                       //����        
{
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(double a, double b, char c[])
	{
		SetPoint(a, b);
		SetName(c);
	}
	void SetPoint(double a, double b)
	{
		x = a;
		y = b;
	}
	void SetName(char c[])
	{
		int n = strlen(c);
		ShapeName = new char[n];
		strcpy(ShapeName, c);
	}
	double GetX()
	{
		return x;
	}
	double GetY()
	{
		return y;
	}
	void GetPerimeter()
	{
		Perimeter = 0;
	}
	void GetArea()
	{
		Area = 0;
	}
	void Print()
	{
		cout << ShapeName << "\n" << endl;
		cout << "�����꣺" << "[" << x << "��" << y << "]" << "\n" << endl;
		cout << "�ܳ���" << Perimeter << "\n" << endl;
		cout << "�����" << Area << "\n" << endl;
	}
	double x;
	double y;
	double Perimeter;
	double Area;
	char *ShapeName;
};
class Line :public Point                       //�߶���
{
public:
	Line(Point p1, Point p2, char c[])
	{
		po1 = p1;
		po2 = p2;
		int n = strlen(c);
		ShapeName = new char[n];
		strcpy(ShapeName, c);
	}
	void GetPerimeter()
	{
		Perimeter = sqrt((po2.x - po1.x)*(po2.x - po1.x) + (po2.y - po1.y)*(po2.y - po1.y));
	}
	void GetArea()
	{
		Area = 0;
	}
	void Print()
	{
		cout << ShapeName << "\n" << endl;
		cout << "�����꣺" << "[" << po1.x << "��" << po1.y << "] " << "[" << po2.x << "��" << po2.y << "]" << "\n" << endl;
		cout << "�ܳ���" << Perimeter << "\n" << endl;
		cout << "�����" << Area << "\n" << endl;
	}
private:
	Point po1;
	Point po2;
	double Perimeter;
	double Area;
	char *ShapeName;
};
class Oval :public Shape                   //��Բ��
{
public:
	Oval()
	{}
	Oval(double x, double y, char c[])
	{
		SetLong(x);
		SetShort(y);
		SetName(c);
	}
	void SetLong(double x)
	{
		a = x;
	}
	void SetShort(double y)
	{
		b = y;
	}
	void SetName(char c[])
	{
		int n = strlen(c);
		ShapeName = new char[n];
		strcpy(ShapeName, c);
	}
	double GetA()
	{
		return a;
	}
	double GetB()
	{
		return b;
	}
	void GetPerimeter()
	{
		Perimeter = pi * (3 * (a + b) - (sqrt(10 * a*b + 3 * (a*a + b * b))));
	}
	void GetArea()
	{
		Area = pi * a*b;
	}
	void Print()
	{
		cout << ShapeName << "\n" << endl;
		cout << "���᣺" << a << "\n" << "���᣺" << b << "\n" << endl;
		cout << "�ܳ���" << Perimeter << "\n" << endl;
		cout << "�����" << Area << "\n" << endl;
	}
	double a;
	double b;
	double Perimeter;
	double Area;
	char *ShapeName;
};
class Circle :public Oval                     //Բ��
{
public:
	Circle(Point a, double d, char c[])
	{
		p = a;
		SetRadius(d);
		SetName(c);
	}
	void SetRadius(double d)
	{
		r = d;
	}
	void SetName(char c[])
	{
		int n = strlen(c);
		ShapeName = new char[n];
		strcpy(ShapeName, c);
	}
	void GetPerimeter()
	{
		Perimeter = 2 * pi*r;
	}
	void GetArea()
	{
		Area = pi * r*r;
	}
	void Print()
	{
		cout << ShapeName << "\n" << endl;
		cout << "Բ�ģ�" << "[" << p.x << "��" << p.y << "]" << "\n" << endl;
		cout << "�뾶��" << r << "\n" << endl;
		cout << "�ܳ���" << Perimeter << "\n" << endl;
		cout << "�����" << Area << "\n" << endl;
	}
	Point p;
	double r;
	double Perimeter;
	double Area;
	char *ShapeName;
};
class Polygon :public Shape                           //�������
{
public:
	Polygon(double n)
	{
		nLength = n;
		ShapeName = new char;
		strcpy(ShapeName, "�����");
	}
	void Set(double idx, Point pnt)
	{
		Vertex[i][0] = pnt.x;
		Vertex[i][1] = pnt.y;
		i++;
	}
	void GetPerimeter()
	{
		Perimeter = 0;
		for (int i = 0;i < nLength - 1;i++)
		{
			Perimeter += sqrt((Vertex[i + 1][0] - Vertex[i][0])*(Vertex[i + 1][0] - Vertex[i][0]) + (Vertex[i + 1][1] - Vertex[i][1]) * (Vertex[i + 1][1] - Vertex[i][1]));
		}
		Perimeter += sqrt((Vertex[i - 1][0] - Vertex[0][0])*(Vertex[i - 1][0] - Vertex[0][0]) + (Vertex[i - 1][1] - Vertex[0][1]) * (Vertex[i - 1][1] - Vertex[0][1]));
	}
	void GetArea()
	{
		Area = 0;
	}
	void Print()
	{
		cout << ShapeName << "\n" << endl;
		cout << "������" << nLength << "\n" << endl;
		for (i = 0;i < nLength;i++)
		{
			cout << "������Ϊ��" << "[" << Vertex[i][0] << "��" << Vertex[i][1] << "]\n" << endl;
		}
		cout << "�ܳ���" << Perimeter << "\n" << endl;
		cout << "�����" << Area << "\n" << endl;
	}
	double Vertex[10000][2];
private:
	double nLength;
	double Perimeter;
	double Area;
	char *ShapeName;
};
void fun(Shape &ref)
{
	ref.GetPerimeter();
	ref.GetArea();
	ref.Print();
}
class Node
{
public:
	Node* next;
	char *ShapeName;             //ͼ������
	double x;                    //Բ������
	double y;
	double x1;                   //�������
	double y1;
	double x2;
	double y2;
	double Vertex[10000][2];
	double r;                     //Բ�뾶
	double a;                    //��Բ����
	double b;                    //��Բ����
	double e;                    //����α���
	double Perimeter;             //ͼ���ܳ�
	double Area;                 //ͼ�����
};
Node *open(Node *head)                        //��ȡ��Ϣ
{
	system("cls");                            //����Ļ
	FILE *fp;                              
	Node *p1 = head,*p2 = head;
	if ((fp = fopen("1.txt", "r")) == NULL)   //���ļ�  
	{
		printf("error\n");
		exit(0);
	}
	while (!feof(fp))                        //��ȡ�ļ���Ϣ
	{
		p2 = p1;
		p1 = new Node;
		p1->ShapeName = new char;
		fscanf(fp, "%s", p1->ShapeName);
		if (strcmp(p1->ShapeName, "��") == 0)
		{
			fscanf(fp, "%lf %lf", &p1->x, &p1->y);
			Point po(p1->x, p1->y, p1->ShapeName);
			fun(po);
			p2->next = p1;
		}
		else if (strcmp(p1->ShapeName, "�߶�") == 0)
		{
			fscanf(fp, "%lf %lf %lf %lf", &p1->x1, &p1->y1, &p1->x2, &p1->y2);
			char *name = new char[20];
			strcpy(name, "��");
			Point po1(p1->x1, p1->y1, name);
			Point po2(p1->x2, p1->y2, name);
			Line li(po1, po2, p1->ShapeName);
			fun(li);
			p2->next = p1;
		}
		else if (strcmp(p1->ShapeName, "��Բ") == 0)
		{
			fscanf(fp, "%lf %lf", &p1->a, &p1->b);
			Oval ov(p1->a, p1->b, p1->ShapeName);
			fun(ov);
			p2->next = p1;
		}
		else if (strcmp(p1->ShapeName, "Բ") == 0)
		{
			fscanf(fp, "%lf %lf %lf", &p1->x, &p1->y, &p1->r);
			char *name = new char[20];
			strcpy(name, "��");
			Point po(p1->x, p1->y, name);
			Circle ci(po, p1->r, p1->ShapeName);
			fun(ci);
			p2->next = p1;
		}
		else
		{
			fscanf(fp, "%lf", &p1->e);
			Point pnt;
			Polygon po(p1->e);
			for (int j = 0;j < p1->e;j++)
			{
				fscanf(fp, "%lf %lf", &p1->Vertex[j][0], &p1->Vertex[j][1]);
				pnt.x = p1->Vertex[j][0];
				pnt.y = p1->Vertex[j][1];
				po.Set(j, pnt);
			}
			fun(po);
			p2->next = p1;
		}
	}
	p1->next = NULL;
	fclose(fp);
	system("pause");
	return head;
}
Node *create(Node *head)                     //�½�
{
	Node *p = head->next;
	FILE *fp;              //���ļ�
	if ((fp = fopen("2.txt", "w")) == NULL)
	{
		printf("error\n");
		exit(0);
	}
	for (;;)
	{
		system("cls");
		cout << "* * * * * *ѡ��ͼ������* * * * * * *\n" << endl;
		cout << "*        a. ��       *\n" << endl;
		cout << "*        b. �߶�       *\n" << endl;
		cout << "*        c. ��Բ       *\n" << endl;
		cout << "*        d. Բ       *\n" << endl;
		cout << "*        e. �����       *\n" << endl;
		cout << "*        f. ����       *\n" << endl;
		cout << "*     ������'a'��'f'    *\n" << endl;
		cout << "* * * * * * * * * * * * * * * * *\n" << endl;
		char i;
		i = getchar();
		if (i == 'f')
			break;
		else switch (i)
		{
		case 'a':
		{
			p = new Node;
			cout << "�����������ꡣ" << endl;
			cin >> p->x >> p->y;
			p->ShapeName = new char;
			strcpy(p->ShapeName, "��");
			Point po(p->x, p->y, p->ShapeName);
			fun(po);
			fprintf(fp, "%s %lf %lf\n", p->ShapeName, p->x, p->y);
			system("pause");
			break;
		}
		case 'b':
		{
			p = new Node;
			char *name = new char[20];
			strcpy(name, "��");
			cout << "�����������ꡣ" << endl;
			cin >> p->x1 >> p->y1 >> p->x2 >> p->y2;
			Point p1(p->x1, p->y1, name);
			Point p2(p->x2, p->y2, name);
			p->ShapeName = new char;
			strcpy(p->ShapeName, "�߶�");
			Line li(p1, p2, p->ShapeName);
			fun(li);
			fprintf(fp, "%s %lf %lf %lf %lf\n", p->ShapeName, p->x1, p->y1, p->x2, p->y2);
			system("pause");
			break;
		}
		case 'c':
		{
			p = new Node;
			cout << "�����볤�ᡣ" << endl;
			cin >> p->a;
			cout << "��������ᡣ" << endl;
			cin >> p->b;
			p->ShapeName = new char;
			strcpy(p->ShapeName, "��Բ");
			Oval ov(p->a, p->b, p->ShapeName);
			fun(ov);
			fprintf(fp, "%s %lf %lf\n", p->ShapeName, p->a, p->b);
			system("pause");
			break;
		}
		case 'd':
		{
			p = new Node;
			char *name = new char[20];
			strcpy(name, "��");
			cout << "������Բ�ġ�" << endl;
			cin >> p->x >> p->y;
			Point po(p->x, p->y, name);
			cout << "������뾶��" << endl;
			cin >> p->r;
			p->ShapeName = new char;
			strcpy(p->ShapeName, "Բ");
			Circle ci(po, p->r, p->ShapeName);
			fun(ci);
			fprintf(fp, "%s %lf %lf %lf\n", p->ShapeName, p->x, p->y, p->r);
			system("pause");
			break;
		}
		case 'e':
		{
			Point pnt;
			p = new Node;
			p->ShapeName = new char;
			strcpy(p->ShapeName, "�����");
			cout << "�����������" << endl;
			cin >> p->e;
			if (p->e < 3)
			{
				cout << "�������" << endl;
				break;
			}
			Polygon po(p->e);
			int i;
			cout << "����������ꡣ" << endl;
			for (int j = 0;j < p->e;j++)

			{

				cin >> pnt.x >> pnt.y;

				po.Set(j, pnt);

			}
			fun(po);
			fprintf(fp, "%s %lf\n", p->ShapeName, p->e);
			for (i = 0;i < p->e;i++)
			{
				fprintf(fp, "%lf %lf\n", po.Vertex[i][0], po.Vertex[i][1]);
			}
			system("pause");
			break;
		}
		default:cout << "����������������룡" << endl;break;
		}
	}
	return p;
}

int main()
{
	char i;
	Node *head;                           //�������
	head = new Node;                      //����ռ�
	for (;;)
	{
		system("cls");
		cout << "* * * * * *ѡ����* * * * * * *\n" << endl;
		cout << "*        a. ��       *\n" << endl;
		cout << "*        b. �½�       *\n" << endl;
		cout << "*        c. �˳�       *\n" << endl;
		cout << "*     ������'a'��'c'    *\n" << endl;
		cout << "* * * * * * * * * * * * * * * * *\n" << endl;
		i = getchar();
		if (i == 'c')
			break;
		else switch (i)
		{
		case 'a':
		{
			head = open(head);
			break;
		}
		case 'b':head = create(head);break;
		default:cout << "����������������룡" << endl;break;
		}
	}
	system("pause");
	return 0;
}
