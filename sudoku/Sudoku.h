class Sudoku {
public:
	int** mat;
	int** copymat;
	int N;

	// number of columns/rows.
	int SRN;

	// No. Of missing digits
	int K;

	Sudoku(int N, int K);

	// Sudoku Generator
	void fillValues();

	// Fill the diagonal SRN number of SRN x SRN matrices
	void fillDiagonal();

	// Returns false if given 3 x 3 block contains num.
	bool unUsedInBox(int rowStart, int colStart, int num);

	// Fill a 3 x 3 matrix.
	void fillBox(int row, int col);

	int randomGenerator(int num);

	// Check if safe to put in cell
	bool CheckIfSafe(int i, int j, int num);

	// check in the row for existence
	bool unUsedInRow(int i, int num);
	
	// check in the row for existence
	bool unUsedInCol(int j, int num);
	
	// A recursive function to fill remaining matrix
	bool fillRemaining(int i, int j);
	
	void removeKDigits();

	void copyMat();
	
};

