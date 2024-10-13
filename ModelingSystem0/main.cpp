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


//функци€ принимает список всех €чеек, указатели на текующую и следующую €чейки
bool check_neighbors(vector<vector<Cell>>& mas, const Cell* c, Cell* &n) 
{
	
	int x = c->x, y = c->y, choice = 0;//x,y координаты €чейки, choice - выбор случайной €чейки из списка €чеек
	vector<Cell*> neighbor;
	//есть ли непосещенные €чейки вокруг
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
		//если есть вокруг хот€ бы одна непосещенна€ €чейка
		choice = rand() % choice;//выбирем случайную €чейку
		n = neighbor[choice]; //она станет следующей 
		
		return true; //вернем правду - мы выбрали следующую €чейку
	}
	else return false; //вернем ложь - нет вокруг непосещенных €чеек
	
}

// движение
bool move(vector<vector<Cell>>& mas, const Cell* c, Cell*& n) 
{
	int x = c->x, y = c->y, choice = 0;//x,y координаты €чейки, choice - выбор случайной €чейки из списка €чеек
	vector<Cell*> neighbor;
	//есть ли непосещенные €чейки вокруг
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
		//если есть вокруг хот€ бы одна непосещенна€ €чейка
		choice = rand() % choice;//выбирем случайную €чейку
		n = neighbor[choice]; //она станет следующей 

		return true; //вернем правду - мы выбрали следующую €чейку
	}
	else return false; //вернем ложь - нет вокруг непосещенных €чеек


}

//сохранение в файл
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
	//создаем массив €чеек
	setlocale(LC_ALL, "ru");

	vector<vector<Cell>> cells;
	//cout << "—оздаЄтс€ вектор €чеек" << endl;
	for (int i = 0; i < N; i++) 
	{
		vector<Cell>row_cells;
		for (int j = 0; j < N; j++)
		{
			row_cells.push_back(Cell(i,j,size_cell));
		}
		cells.push_back(row_cells);
	}

	//массив указателей на пройденные €чейки
	vector<Cell*> stack;
	//cout << "√енерируетс€ лабиринт" << endl;
	//√енерируем лабиринт
	bool IsGenerated = false; //создан ли лабиринт
	Cell* actual = &cells[0][0], * next = &cells[0][0]; //указател€ми будем ходить по €чейкам лабиринта
	actual = &cells[0][0]; //начнем с нулевой €чейки
	while (!IsGenerated) { //пока лабиринт не создан 
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
		//cout << "–азмер стека" << stack.size() << endl;

	}
	//cout << "–азмер стека = " << stack.size() << endl;
	//cout << "Ћабиринт сгенерирован" << endl;

	int start = N - 1, finish = 0;
	actual = &cells[0][start];
	actual->visit();
	actual->add();
	bool Escape = false; //нашли ли выход
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
	//cout << "–исуетс€ картинка" << endl; 	//рисуем лабиринт

	//что-то дл€ gdi+
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	//создаем bitmap
	Bitmap myBitmap(N * size_cell, N * size_cell);
	Graphics* grr = Graphics::FromImage(&myBitmap); //создаем  объект класса дл€ рисовани€ объектов

	grr->Clear(Color::White);//очистим фон
	Pen walls(Color::Aqua, size_cell * 0.02);//ручка дл€ рисовани€ осей
	SolidBrush in_path(Color::Indigo);
	SolidBrush visited(Color::RoyalBlue);
	SolidBrush exits(Color::Red);

	//нарисуем лабиринт
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

	//нарисуем вход и выход
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
	cout << "готово" << endl;
	GetEncoderClsid(L"image/png", &pngClsid);
	myBitmap.Save(L"C:\\Users\\79877\\Desktop\\Labirint.png", &pngClsid);
	delete grr;
}
