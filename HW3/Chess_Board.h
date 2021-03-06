#ifndef _chess_board_dac
#define _chess_board_dac

#include <iostream>
#include <ostream>

using namespace std;


class Chess_Board
{
  friend ostream& operator<<(ostream& output, const Chess_Board& CB);
  // needs to be a friend to look at internal data...
  public: 
   	Chess_Board (int N);//
    bool goodMove(int i, int j); // Row i, col j is free from capture from existing queens
	void AddQueen(int i, int j); // add queen at (i,j)
	void RemoveQueen(int i, int j); // remove queen at (i,j)
	int getSize();
	void ClearBoard();
	void Solve(){DFS(0);}
    
  private:
    const static int Nmax = 50;
    int Nsize;
    int A[Nmax][Nmax]; // 0 where there are no queens, 1 where there are queens
	bool DFS(int row);
};

Chess_Board::Chess_Board(int N){  // no queens to start
        if (N > Nmax){
			cout << "Too big of a board " << endl;
			exit(1);
		}
		Nsize = N;
		for (int i = 0;i<N;i++){
			for (int j=0;j<N;j++){
				A[i][j]=0;
			}
		}
}

bool Chess_Board::DFS(int row){  // Add queen to row...
	bool found = false;
	int NN = getSize();
	//
	//This is the key function you need to write, which does DFS row by row looking for a placement
	// where previous queens cannot capture the current position.
	// This will use the goodMove function to check whether a queen position can be captured by 
	// queens on the board in previous rows.
	// Using DFS row by row calculate placement of queens on the board.
	if(row >= NN){
		found = true;
	}
	else{
		for(int i = 0; i < NN; i++){
			if(goodMove(row, i)){
				AddQueen(row, i);
				if(DFS(row+1)){
					found = true;
				}
				else{
					RemoveQueen(row, i);
				}
			}
		}
	}
    return found;
}

void Chess_Board::AddQueen(int i, int j){
	A[i][j] = 1;
}

void Chess_Board::RemoveQueen(int i, int j){
	A[i][j]=0;
}

bool Chess_Board::goodMove(int irow, int jcol){ // square is not captured by queens...
      int row,col,min;
	  //
	  //  This is the other function you have to create.  It checks whether the square in row irow, column
	  //  jcol can be captured by the existing queens on the board in rows 0 .. irow-1. 
	  //
	  //
	  //  This function should return true if the square is not captured by the existing queens.
	  //  Otherwise, it should return false.
	  //
	  //  The function should use the A[][] array to check whether the square is captured.
	  //  A[i][j] = 0 means that the square is not captured by any queen.
	  //  A[i][j] = 1 means that the square is captured by a queen in row i.
	  //
	  //  The function should also use the getSize() function to get the size of the board.
	  //	
	  //  The function should use the min function to find the minimum of two values.
	  //
	  //  The function should use the abs function to find the absolute value of a number.
	  //
	  for(row = 0; row < irow; row++){
		  col = jcol - (irow - row);
		  if(col >= 0 && col < getSize() && A[row][col] == 1){
			  return false;
		  }
		  col = jcol + (irow - row);
		  if(col >= 0 && col < getSize() && A[row][col] == 1){
			  return false;
		  }
		  return true;
	  	}
}

int Chess_Board::getSize(){
	return Nsize;
}

void Chess_Board::ClearBoard(){
   for (int i = 0;i<Nsize;i++)
	   for (int j = 0; j<Nsize;j++)
		   A[i][j] = 0;
}

ostream& operator<<(ostream& output, const Chess_Board& CB){

	for (int i =0; i<CB.Nsize;i++){
		for (int j = 0; j<CB.Nsize;j++){
		   output << " " << CB.A[i][j] ;
		}
		output << endl;
	}
	return output;
}

#endif