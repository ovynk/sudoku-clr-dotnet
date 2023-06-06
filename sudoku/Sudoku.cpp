#include <iostream>
#include <time.h>
#include <cmath>
#include "Sudoku.h"

using namespace std;

	Sudoku::Sudoku(int N, int K)
	{
		this->N = N;
		this->K = K;

		double SRNd = sqrt(N);
		SRN = (int)SRNd;
		mat = new int* [N];
		copymat = new int* [N];

		// Create a row for every pointer
		for (int i = 0; i < N; i++)
		{
			mat[i] = new int[N];
			copymat[i] = new int[N];

			// Initialize all entries as false to indicate
			// that there are no edges initially
			memset(mat[i], 0, N * sizeof(int));
			memset(copymat[i], 0, N * sizeof(int));
		}
	}

	void Sudoku::fillValues()
	{
		// Fill the diagonal of SRN x SRN matrices
		fillDiagonal();

		// Fill remaining blocks
		fillRemaining(0, SRN);

		copyMat();

		// Remove Randomly K digits to make game
		removeKDigits();
	}

	void Sudoku::fillDiagonal()
	{
		for (int i = 0; i < N; i = i + SRN)
		{
			fillBox(i, i);
		}
	}

	bool Sudoku::unUsedInBox(int rowStart, int colStart, int num)
	{
		for (int i = 0; i < SRN; i++) 
		{
			for (int j = 0; j < SRN; j++) 
			{
				if (mat[rowStart + i][colStart + j] == num) 
				{
					return false;
				}
			}
		}
		return true;
	}

	void Sudoku::fillBox(int row, int col)
	{
		srand(time(NULL));

		int num;
		for (int i = 0; i < SRN; i++) 
		{
			for (int j = 0; j < SRN; j++) 
			{
				do {
					num = randomGenerator(N);
				} while (!unUsedInBox(row, col, num));
				mat[row + i][col + j] = num;
			}
		}
	}

	int Sudoku::randomGenerator(int num)
	{
		return (int)floor((float)(rand() / double(RAND_MAX) * num + 1));
	}

	bool Sudoku::CheckIfSafe(int i, int j, int num)
	{
		return (unUsedInRow(i, num) && unUsedInCol(j, num)
			&& unUsedInBox(i - i % SRN, j - j % SRN, num));
	}

	bool Sudoku::unUsedInRow(int i, int num)
	{
		for (int j = 0; j < N; j++) 
		{
			if (mat[i][j] == num) 
			{
				return false;
			}
		}
		return true;
	}

	bool Sudoku::unUsedInCol(int j, int num)
	{
		for (int i = 0; i < N; i++) 
		{
			if (mat[i][j] == num) 
			{
				return false;
			}
		}
		return true;
	}

	bool Sudoku::fillRemaining(int i, int j)
	{
		if (j >= N && i < N - 1)
		{
			i = i + 1;
			j = 0;
		}
		if (i >= N && j >= N) 
		{
			return true;
		}
		if (i < SRN) 
		{
			if (j < SRN) 
			{
				j = SRN;
			}
		}
		else if (i < N - SRN) 
		{
			if (j == (int)(i / SRN) * SRN) 
			{
				j = j + SRN;
			}
		}
		else 
		{
			if (j == N - SRN)
			{
				i = i + 1;
				j = 0;
				if (i >= N) 
				{
					return true;
				}
			}
		}
		for (int num = 1; num <= N; num++)
		{
			if (CheckIfSafe(i, j, num))
			{
				mat[i][j] = num;
				if (fillRemaining(i, j + 1))
				{
					return true;
				}
				mat[i][j] = 0;
			}
		}
		return false;
	}

	void Sudoku::removeKDigits()
	{
		int count = K;
		while (count != 0) 
		{
			int cellId = randomGenerator(N * N) - 1;
			// extract coordinates i and j
			int i = (cellId / N);
			int j = cellId % 9;
			
			if (mat[i][j] != 0) 
			{
				count--;
				mat[i][j] = 0;
			}
		}
	}

	void Sudoku::copyMat()
	{
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++) 
			{
				copymat[i][j] = mat[i][j];
			}
		}
    }
