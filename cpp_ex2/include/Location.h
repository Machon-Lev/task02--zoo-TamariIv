#pragma once
#include <iostream>

struct Location {
	int row;
	int col;

	Location(int r = 0, int c = 0) : row(r), col(c) {}

	// Output stream operator
	friend std::ostream& operator<<(std::ostream& os, const Location& loc) {
		os << "[" << loc.row << ", " << loc.col << "]";
		return os;
	}

	// Addition operator
	Location operator+(const Location& rhs) const {
		return Location(row + rhs.row, col + rhs.col);
	}

	// Addition-assignment operator
	Location& operator+=(const Location& rhs) {
		row += rhs.row;
		col += rhs.col;
		return *this;
	}

	// Multiplication operator
	Location operator*(int scale) const {
		return Location(row * scale, col * scale);
	}

	// Multiplication-assignment operator
	Location& operator*=(int scale) {
		row *= scale;
		col *= scale;
		return *this;
	}

	// Equality operator
	bool operator==(const Location& rhs) const {
		return row == rhs.row && col == rhs.col;
	}

	// Inequality operator
	bool operator!=(const Location& rhs) const {
		return !(*this == rhs);
	}
};


