#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <gdiplus.h>
#include "Cell.h"

#pragma comment(lib,"GdiPlus.lib")

using namespace std;
using namespace Gdiplus;

const short N = 4000;
const short size_cell = 4;


//������� ��������� ������ ���� �����, ��������� �� �������� � ��������� ������
bool check_neighbors(vector<vector<Cell>>& mas, const Cell* c, Cell* &n) 
{
	
	int x = c->x, y = c->y, choice = 0;//x,y ���������� ������, choice - ����� ��������� ������ �� ������ �����
	vector<Cell*> neighbor;
	//���� �� ������������ ������ ������
	if (y > 0 && !mas[x][y - 1].visited) 
	{ 
		neighbor.push_back(&mas[x][y - 1]); 
		choice++; 
	}
	
	if (x > 0 && !mas[x - 1][y].visited) 
	{ neighbor.push_back(&mas[x - 1][y]); 
	choice++; 
	}

	if (x < N - 1 && !mas[x + 1][y].visited) 
	{
		neighbor.push_back(&mas[x + 1][y]); 
		choice++; 
	}
	
	if (y < N - 1 && !mas[x][y + 1].visited) 
	{ neighbor.push_back(&mas[x][y + 1]); 
	choice++; 
	}

	if (choice > 0) 
	{ 
		//���� ���� ������ ���� �� ���� ������������ ������
		choice = rand() % choice;//������� ��������� ������
		n = neighbor[choice]; //��� ������ ��������� 
		
		return true; //������ ������ - �� ������� ��������� ������
	}
	else return false; //������ ���� - ��� ������ ������������ �����
	
}

// ��������
bool move(vector<vector<Cell>>& mas, const Cell* c, Cell*& n) 
{
	int x = c->x, y = c->y, choice = 0;//x,y ���������� ������, choice - ����� ��������� ������ �� ������ �����
	vector<Cell*> neighbor;
	//���� �� ������������ ������ ������
	if (y > 0) if (!mas[x][y - 1].visited && !mas[x][y - 1].bottom) 
	{ 
		neighbor.push_back(&mas[x][y - 1]); 
		choice++; 
	}

	if (x > 0) if (!mas[x - 1][y].visited && !mas[x - 1][y].right) 
	{ 
		neighbor.push_back(&mas[x - 1][y]); 
		choice++; 
	}

	if (x < N - 1) if (!mas[x + 1][y].visited && !mas[x + 1][y].left) 
	{ 
		neighbor.push_back(&mas[x + 1][y]); 
		choice++; 
	}

	if (y < N - 1) if (!mas[x][y + 1].visited && !mas[x][y + 1].top) 
	{ 
		neighbor.push_back(&mas[x][y + 1]); 
		choice++; 
	}

	if (choice > 0) 
	{ 
		//���� ���� ������ ���� �� ���� ������������ ������
		choice = rand() % choice;//������� ��������� ������
		n = neighbor[choice]; //��� ������ ��������� 

		return true; //������ ������ - �� ������� ��������� ������
	}
	else return false; //������ ���� - ��� ������ ������������ �����


}

//���������� � ����
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes

	ImageCodecInfo* pImageCodecInfo = NULL;

	Gdiplus::GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;  // Failure

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
		return -1;  // Failure

	Gdiplus::GetImageEncoders(num, size, pImageCodecInfo);

	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}
	}

	free(pImageCodecInfo);
	return -1;  // Failure
}

int main() 
{
	//������� ������ �����
	setlocale(LC_ALL, "ru");

	vector<vector<Cell>> cells;
	//cout << "�������� ������ �����" << endl;
	for (int i = 0; i < N; i++) 
	{
		vector<Cell>row_cells;
		for (int j = 0; j < N; j++)
		{
			row_cells.push_back(Cell(i,j,size_cell));
		}
		cells.push_back(row_cells);
	}

	//������ ���������� �� ���������� ������
	vector<Cell*> stack;
	//cout << "������������ ��������" << endl;
	//���������� ��������
	bool IsGenerated = false; //������ �� ��������
	Cell* actual = &cells[0][0], * next = &cells[0][0]; //����������� ����� ������ �� ������� ���������
	actual = &cells[0][0]; //������ � ������� ������
	while (!IsGenerated) { //���� �������� �� ������ 
		actual->visited = true;
		if (check_neighbors(cells, actual, next))
		{
			next->visit();
			stack.push_back(next);
			delete_walls(actual, next);
			actual = next;
		}
		else if (stack.size() > 0) 
		{
			actual = stack.back();
			stack.pop_back();
		}
		else if (stack.size() == 0) 
		{
			IsGenerated = true;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++) 
				{
					cells[i][j].visited = false;
				}
			}
		}
		//cout << "������ �����" << stack.size() << endl;

	}
	//cout << "������ ����� = " << stack.size() << endl;
	//cout << "�������� ������������" << endl;

	int start = N - 1, finish = 0;
	actual = &cells[0][start];
	actual->visit();
	actual->add();
	bool Escape = false; //����� �� �����
	while (!Escape) 
	{
		if (move(cells, actual, next))
		{
			stack.push_back(actual);
			actual = next;
			actual->visit();
			actual->add();
			if (actual == &cells[N - 1][finish])
			{
				Escape = true;
			}

		}
		else if (stack.size() > 0) 
		{
			actual->delete_();
			actual = stack.back();
			stack.pop_back();
		}
		else if (stack.size() == 0) 
		{
			Escape = true;
		}
	}
	//cout << "�������� ��������" << endl; 	//������ ��������

	//���-�� ��� gdi+
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	//������� bitmap
	Bitmap myBitmap(N * size_cell, N * size_cell);
	Graphics* grr = Graphics::FromImage(&myBitmap); //�������  ������ ������ ��� ��������� ��������

	grr->Clear(Color::White);//������� ���
	Pen walls(Color::Aqua, size_cell * 0.02);//����� ��� ��������� ����
	SolidBrush in_path(Color::Indigo);
	SolidBrush visited(Color::RoyalBlue);
	SolidBrush exits(Color::Red);

	//�������� ��������
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
		//if (cells[i][j].visited) grr->FillRectangle(&visited, i * size_cell, j * size_cell, size_cell, size_cell);
			//if (cells[i][j].in_path) grr->FillRectangle(&in_path, i * size_cell, j * size_cell, size_cell, size_cell);
			
			if (cells[i][j].top) grr->DrawLine(&walls, i * size_cell, j * size_cell, (i + 1) * size_cell, j * size_cell);
			if (cells[i][j].bottom) grr->DrawLine(&walls, i * size_cell, (j+1) * size_cell, (i + 1) * size_cell, (j+1) * size_cell);
			if (cells[i][j].left) grr->DrawLine(&walls, i * size_cell, j * size_cell, i * size_cell, (j+1) * size_cell);
			if (cells[i][j].right) grr->DrawLine(&walls, (i+1) * size_cell, j * size_cell, (i+1) * size_cell, (j + 1) * size_cell);

		}
	}

	//�������� ���� � �����
	grr->FillRectangle(&exits, 0, start * size_cell, size_cell, size_cell);
	grr->FillRectangle(&exits, (N - 1) * size_cell, finish * size_cell, size_cell, size_cell);
	if (cells[0][start].top) grr->DrawLine(&walls, 0 * size_cell, start * size_cell, (0 + 1) * size_cell, start * size_cell);
	if (cells[0][start].bottom) grr->DrawLine(&walls, 0 * size_cell, (start + 1) * size_cell, (0 + 1) * size_cell, (start + 1) * size_cell);
	if (cells[0][start].left) grr->DrawLine(&walls, 0 * size_cell, start * size_cell, 0 * size_cell, (start + 1) * size_cell);
	if (cells[0][start].right) grr->DrawLine(&walls, (0 + 1) * size_cell, start * size_cell, (0 + 1) * size_cell, (start + 1) * size_cell);

	if (cells[N-1][finish].top) grr->DrawLine(&walls, N-1 * size_cell, finish * size_cell, (N-1 + 1) * size_cell, finish * size_cell);
	if (cells[N-1][finish].bottom) grr->DrawLine(&walls, N-1 * size_cell, (finish + 1) * size_cell, (N-1 + 1) * size_cell, (finish + 1) * size_cell);
	if (cells[N-1][finish].left) grr->DrawLine(&walls, N-1 * size_cell, finish * size_cell, N-1 * size_cell, (finish + 1) * size_cell);
	if (cells[N-1][finish].right) grr->DrawLine(&walls, (N-1 + 1) * size_cell, finish * size_cell, (N-1 + 1) * size_cell, (finish + 1) * size_cell);

	CLSID pngClsid;
	cout << "������" << endl;
	GetEncoderClsid(L"image/png", &pngClsid);
	myBitmap.Save(L"C:\\Users\\79877\\Desktop\\Labirint.png", &pngClsid);
	delete grr;
}
