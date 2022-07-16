#pragma once

enum Color { WHITE, BROWN };
enum Types { EGG, QUEEN };

struct Egg {
	Color color;
	Types type;
	void promote() {
		if (type == EGG) {
			type = QUEEN;
		}
	}
	Egg(Color ncol, Types ntpe) :color{ncol}, type{ntpe} {}
};

class Board {
	public:
		Egg* board[6][5]; //board[y][x], 5x6 array
		void clean();
		void start();
		Board() {this->clean();}
};

void Board::clean() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			if (this->board[i][j] != NULL) {
				delete this->board[i][j];
			}
			this->board[i][j] = NULL;
		}
	}
}

void Board::start() {
	Color col = WHITE;
	for (int i = 0; i < 6; i++) {
		if ((i == 2) || (i == 3)) {
			col = BROWN;
			continue;
		}

		for (int j = 0; j < 5; j++) {
			this->board[j][i] = new Egg(col, EGG);
		}
	}
}
