

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool Master = false;

void solutionToQueens(int row, vector<vector<char>> &Board, vector<vector<int>> FS, vector<vector<int>> &CNF);
bool NoNoSquare(int row, int col, vector<vector<int>> FS);
int possible(int row, int col, vector<vector<char>> &Board);
int getTempCol(int row, vector<vector<char>> &Board);
void printQueens(vector<vector<char>> &Board);
int getValidInt();
void getFS(vector<vector<int>> &FS, int N);
void logicalBoardLayout(int N);
void addToCNF(vector<vector<char>> &Board, vector<vector<int>> &CNF, int row, int col);
void printCNF(vector<vector<int>> &CNF, int N, string fileName);

int main(int argc, char * argv[]){


	cout << "This program will first solve all items listed and save the DIAMACS formatted file for each " <<
		"as 2_1.txt for problem 2 part 1, 2_2.txt for problem 2.2 ect. after that you may do a custom n-queens " <<
		"problem with selected forbidden squares or enter a negative N value to skip that section." << endl << endl;

	//2.1

	vector<vector<char>> Board1;
	vector<vector<int>> FS1;
	vector<vector<int>> CNF1;
	int N1 = 4;
	vector<int> tVec;
	vector<int> tVec2;
	tVec.push_back(0);
	tVec2.push_back(1);
	FS1.push_back(tVec);
	FS1.push_back(tVec2);

	for (int i = 0; i < N1; i++){
		vector<char> l;
		Board1.push_back(l);
		for (int j = 0; j < N1; j++)
			Board1[i].push_back('.');
	}
	solutionToQueens(0, Board1, FS1, CNF1);
	cout << endl; 
	logicalBoardLayout(N1);
	printCNF(CNF1, N1, "CNF_Files/2_1.txt");

	//2.2
	Master = false;


	vector<vector<char>> Board2;
	vector<vector<int>> FS2;
	vector<vector<int>> CNF2;
	int N2 = 4;
	vector<int> tVec3;
	vector<int> tVec4;
	tVec3.push_back(0);
	tVec3.push_back(1);
	tVec4.push_back(1);
	tVec4.push_back(3);
	FS2.push_back(tVec3);
	FS2.push_back(tVec4);

	for (int i = 0; i < N2; i++){
		vector<char> l;
		Board2.push_back(l);
		for (int j = 0; j < N2; j++)
			Board2[i].push_back('.');
	}
	solutionToQueens(0, Board2, FS2, CNF2);
	cout << endl;
	logicalBoardLayout(N2);
	printCNF(CNF2, N2, "CNF_Files/2_2.txt");

	//2.3
	Master = false;



	vector<vector<char>> Board3;
	vector<vector<int>> FS3;
	vector<vector<int>> CNF3;
	int N3 = 10;
	vector<int> tVec5;
	vector<int> tVec6;
	tVec5.push_back(0); tVec5.push_back(0); tVec5.push_back(0); tVec5.push_back(0); tVec5.push_back(0); 
	tVec6.push_back(0); tVec6.push_back(2); tVec6.push_back(4); tVec6.push_back(6); tVec6.push_back(8);
	FS3.push_back(tVec5);
	FS3.push_back(tVec6);

	for (int i = 0; i < N3; i++){
		vector<char> l;
		Board3.push_back(l);
		for (int j = 0; j < N3; j++)
			Board3[i].push_back('.');
	}
	solutionToQueens(0, Board3, FS3, CNF3);
	cout << endl;
	logicalBoardLayout(N3);
	printCNF(CNF3, N3, "CNF_Files2_3.txt");


	//2.4
	Master = false;


	vector<vector<char>> Board4;
	vector<vector<int>> FS4;
	vector<vector<int>> CNF4;
	int N4 = 10;
	vector<int> tVec7;
	vector<int> tVec8;
	tVec7.push_back(0); tVec7.push_back(0); tVec7.push_back(0); tVec7.push_back(0); tVec7.push_back(0); tVec7.push_back(0); tVec7.push_back(0); tVec7.push_back(0); tVec7.push_back(0); tVec7.push_back(0);
	tVec8.push_back(0); tVec8.push_back(1); tVec8.push_back(2); tVec8.push_back(3); tVec8.push_back(4); tVec8.push_back(5); tVec8.push_back(6); tVec8.push_back(7); tVec8.push_back(8); tVec8.push_back(9);
	FS4.push_back(tVec7);
	FS4.push_back(tVec8);

	for (int i = 0; i < N4; i++){
		vector<char> l;
		Board4.push_back(l);
		for (int j = 0; j < N4; j++)
			Board4[i].push_back('.');
	}
	solutionToQueens(0, Board4, FS4, CNF4);
	cout << endl;
	logicalBoardLayout(N4);
	printCNF(CNF4, N4, "CNF_Files/2_4.txt");




	//Custom
	Master = false;



	vector<vector<char>> Board;
	vector<vector<int>> FS;
	vector<vector<int>> CNF;
	int N;

	N = getValidInt();
	if (N > 0){

		getFS(FS, N);


		for (int i = 0; i < N; i++){
			vector<char> l;
			Board.push_back(l);
			for (int j = 0; j < N; j++)
				Board[i].push_back('.');
		}
		cout << endl;
		solutionToQueens(0, Board, FS, CNF);
		cout << endl;
		logicalBoardLayout(N);
		printCNF(CNF, N, "Custom.txt");
		
	}
	 
}

void printCNF(vector<vector<int>> &CNF, int N, string fileName){
	cout << "Writing to file "<< fileName << "...\n"<<"Please Wait..." << endl;
	string s_cnf = "";
	ofstream file;
	file.open(fileName);
	s_cnf = "p cnf " + to_string(N*N) + ' ' + to_string(CNF.size()) + '\n';
	file << s_cnf;
	for (auto line : CNF){
		s_cnf = "";
		for (auto num : line){

			s_cnf = s_cnf + to_string(num) + ' ';
		}
		s_cnf = s_cnf +'0' + '\n';
		file << s_cnf;
	}
	
	file.close();

	cout << fileName << " has been created with the CNF output in DIMACS format." << endl;
}


void logicalBoardLayout(int N){
	cout << "The Logical Board Layout will be:" << endl << endl;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (i + N*j + 1 < 10)
				cout << i + N*j + 1 << "   ";
			else if (i + N*j + 1 < 100)
				cout << i + N*j + 1  << "  ";
			else
				cout << i + N*j + 1 << " ";
		}
		cout << endl << endl;
	}
}


void getFS(vector<vector<int>> &FS, int N){
	cout << endl << "Enter the forbidden squares:" << endl << "Enter a negative value in for Y when you are finished." << endl << endl;
	int holdVal;
	vector<int> thing;
	FS.push_back(thing);
	FS.push_back(thing);
	while (1){
		for (;;) {
			cout << "Please enter the X value: ";
			if (cin >> holdVal) {
				if (holdVal < N){
					FS[0].push_back(holdVal);
					break;
				}
				else{
					cout << "Please enter an int value less than N." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else {
				cout << "Please enter a valid integer" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		if (FS[0][(FS[0].size() - 1)] < 0){
			FS[0].push_back(holdVal);
			break;
		}
		for (;;) {
			cout << "Please enter the Y value: ";
			if (cin >> holdVal) {
				if (holdVal >= 0 && holdVal < N){
					FS[1].push_back(holdVal);
					cout << endl;
					break;
				}
				else{
					cout << "Please enter a positive int value between 0 and N." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else {
				cout << "Please enter a valid integer" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}

}

int getValidInt(){
	int ValidInt;
	for (;;) {
		cout << "Please enter N or \nEnter a negative value to skip the Custom n-Queens section.\n";
		if (cin >> ValidInt) {
			break;
		}
		else {
			cout << "Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return ValidInt;
}



void printQueens(vector<vector<char>> &Board){
	int i, j;
	for (i = 0; i < Board.size(); i++){
		for (j = 0; j < Board.size(); j++)
			cout << Board[i][j] << " ";
		cout << endl << endl;
	}
}


int getTempCol(int row, vector<vector<char>> &Board){
	for (int i = 0; i < Board.size(); i++)
	if (Board[row][i] == 'Q'){
		return i;
	}
	return Board.size();
}


int possible(int row, int col, vector<vector<char>> &Board){
	for (int tempRow = 0; tempRow < Board.size(); tempRow++){
		int tempCol = getTempCol(tempRow, Board);
		if (tempCol == Board.size())
			break;
		if (col == tempCol || abs(row - tempRow) == abs(col - tempCol))
			return 0;
	}
	return 1;
}


bool NoNoSquare(int row, int col, vector<vector<int>> FS){
	for (int i = 0; i < FS[0].size(); i++){
		if (FS[0][i] == col){
			if (FS[1][i] == row)
				return true;
		}
	}
	return false;
}

void addToCNF(vector<vector<char>> &Board, vector<vector<int>> &CNF, int row, int col){
	vector<int> Temp;
	for (int i = 0; i < Board.size(); i++){
		for (int j = 0; j < Board[i].size(); j++){
			if (Board[i][j] == 'Q')
				Temp.push_back((i + Board.size() * j + 1)*-1);
		}
	
	}
	Temp.push_back((row + col*Board.size() + 1)*-1);
	CNF.push_back(Temp);
}

void solutionToQueens(int row, vector<vector<char>> &Board, vector<vector<int>> FS, vector<vector<int>> &CNF){
	if (row < Board.size()){
		for (int col = 0; col < Board.size(); col++){
			if (possible(row, col, Board) && !NoNoSquare(row, col, FS)){
				Board[row][col] = 'Q';
				solutionToQueens(row + 1, Board, FS, CNF);
				Board[row][col] = '.';
			}
			else{
				addToCNF(Board, CNF, row, col);
			}
		}
	}
	else{
		if (!Master){
			cout << "A solution is: " << endl;
			printQueens(Board);
			Master = true;
		}
	}
}
