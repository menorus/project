#pragma once

#include <vector>

class Cell
{
public:
	int x, y, size;
	bool top, right, left, bottom, visited, in_path;
	Cell(int x, int y, int size) {
		this->x = x;
		this->y = y;
		this->size = size;
		top = right = left = bottom = true;
		visited = in_path = false;
	}
	void visit() {
		this->visited = true;
	}

	void add() {
		this->in_path = true;
	}

	void delete_() {
		this->in_path = false;
	}
};

void delete_walls(Cell* actual, Cell* next) {
	int dx = actual->x - next->x;
	int dy = actual->y - next->y;
	if (dx == 1) {
		actual->left = false;
		next->right = false;
	}
	else if (dx == -1) {
		actual->right = false;
		next->left = false;
	}
	else if (dy == 1) {
		actual->top = false;
		next->bottom = false;
	}
	else if (dy == -1) {
		actual->bottom = false;
		next->top = false;
	}
}



