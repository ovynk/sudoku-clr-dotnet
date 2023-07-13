# Project “Sudoku game” CLR Windows Forms
It was made as exercise for university

This program allows the user to play the popular Sudoku game. The program is written in the c++ programming language using Windows Forms technology to create a graphical interface.

The program has the following main functions:
- Check that the cells are filled in correctly (Check button)
- Counter of the number of correct sudoku (above the Check button)
- Generation of a new sudoku (New game button)
- Difficulty settings, changing the number of skipped cells (default 26)

![image1](https://github.com/ovynk/sudoku-clr-dotnet/assets/90598021/29535126-8ff3-42d2-bf08-e9fc2905aa88)

The program consists of two classes: Sudoku and MyForm. The Sudoku class is divided into Sudoku.cpp and Sudoku.h, responsible for Sudoku generation. It has such variables as N - sudoku length, K - number of missed cells, SRN - number of cells, mat - two-dimensional matrix array (sudoku) and copymat - a copy of sudoku that is created before K cells are removed, so that it can be compared later .

The MyForm class is responsible for the graphical interface, such as displaying the game field, buttons, setting the N value, text, and messages. The game field is created using the DataGridView element; buttons New game checks the label (text: N of empty cells), creates a new sudoku and changes the DataGridView; Check checks each DataGridView cell row by row for coincidence with the matrix (copymat) of Sudoku class, if successful then label “Count wins : 0” outputs a new value (“Count wins : 1”) and the message “Correct sudoku” is output otherwise “Incorrect sudoku” .

![image2](https://github.com/ovynk/sudoku-clr-dotnet/assets/90598021/839df735-4c28-4fb0-a616-0177ffb79edd)
![image3](https://github.com/ovynk/sudoku-clr-dotnet/assets/90598021/23a07b75-b794-44fa-8588-7aefd78aba5f)

The Sudoku game project demonstrates the use of the c++ programming language to create Windows Forms applications. The project also shows the use of algorithms and data structures to implement a logic game.
