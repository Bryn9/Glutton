#include <iostream>    //�������� ��� �����/������ ����������
#include <windows.h>   /*������������ ����, ���� ������ ���������� ��� ��� ������� Windows API, �� ������� ������� � 
                       �� ���� �����, �� ���������������� ������ ��������� � ���������*/

#include <vector>

using namespace std;

char maptmp[18][32]; //��������� ����

char name[14][62] = {   //�������� ����
	"#############################################################",
	"#                                                           #",
	"#                                                           #",
	"#  #####   #      #    # ####### #######  ######  #      #  #",
	"#  #       #      #    #    #       #     #    #  ##     #  #",
	"#  #       #      #    #    #       #     #    #  # #    #  #",
	"#  #       #      #    #    #       #     #    #  #  #   #  #",
	"#  # ####  #      #    #    #       #     #    #  #   #  #  #",
	"#  #    #  #      #    #    #       #     #    #  #    # #  #",
	"#  #    #  #      #    #    #       #     #    #  #     ##  #",
	"#  ######  #####  ######    #       #     ######  #      #  #",
	"#                                                           #",
	"#                                                           #",
	"#############################################################"
	};

char map[18][32] = {             //������� �������
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	"@ ............................@",
	"@....@..@..@@@@..@@@@..@@@@...@",
	"@....@..@..@  @..@  @..@  @...@",
	"@....@@@@..@@@@..@@@@..@  @...@",
	"@....@..@..@..@..@.@...@  @...@",
	"@....@..@..@..@..@..@..@@@@...@",
	"@.............................@",
	"@.............................@", 
	"@..@....@@@..@...@..@@@..@....@",
	"@..@....@....@...@..@....@....@",
	"@..@....@@@..@...@..@@@..@....@",
	"@..@....@.....@ @...@....@....@",
	"@..@@@@.@@@....@....@@@..@@@@.@",
	"@.............................@",
	"@.............................@",
	"@.............. ..............@",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	};
	
char karta[18][32] = {           //���������� ������� 
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	"@ ............................@",
	"@.@...@..@@@@..@@@@@..@.....@.@",
	"@.@@..@..@  @..@   @..@@...@@.@",
	"@.@.@.@..@  @..@@@@@..@.@.@.@.@",
	"@.@..@@..@  @..@.@....@..@..@.@",
	"@.@...@..@@@@..@...@..@.....@.@",
	"@.............................@",
	"@.............................@",
	"@..@....@@@..@...@..@@@..@....@", 
	"@..@....@....@...@..@....@....@",
	"@..@....@@@..@...@..@@@..@....@",
	"@..@....@.....@ @...@....@....@",
	"@..@@@@.@@@....@....@@@..@@@@.@",
	"@.............................@",
	"@.............................@",
	"@.............. ..............@",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
};

char level3[18][32] = {          //������ �������
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	"@ ............................@",
	"@....@@@@..@@@@..@@@@..@...@..@",
	"@....@.....@  @..@......@.@...@",
	"@....@@@@..@@@@..@@@@....@....@",
	"@....@.....@..@.....@....@....@",
	"@....@@@@..@..@..@@@@....@....@",
	"@.............................@",
	"@.............................@", 
	"@..@....@@@..@...@..@@@..@....@",
	"@..@....@....@...@..@....@....@",
	"@..@....@@@..@...@..@@@..@....@",
	"@..@....@.....@ @...@....@....@",
	"@..@@@@.@@@....@....@@@..@@@@.@",
	"@.............................@",
	"@.............................@",
	"@.............. ..............@",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
};

char lose[10][65] = {             //������� � ���������
	"----------------------------------------------------------------",
	"|                                                              |",
	"|   *     *  ******  *    *     *       ******  *****  *****   |",
	"|    *   *   *    *  *    *     *       *    *  *      *       |",
	"|     * *    *    *  *    *     *       *    *  *****  *****   |",
	"|      *     *    *  *    *     *       *    *      *  *       |",
	"|      *     *    *  *    *     *       *    *      *  *       |",
	"|      *     ******  ******     ******  ******  *****  *****   |",
	"|                                                              |",
	"----------------------------------------------------------------"
};

char win[10][70] = {              //������� � ��������
	"---------------------------------------------------------------------",
	"|                                                                   |",
	"|  *     *  ******  *    *     *               *  ******  **     *  |",
	"|   *   *   *    *  *    *      *             *   *    *  * *    *  |",
	"|    * *    *    *  *    *       *     *     *    *    *  *  *   *  |",
	"|     *     *    *  *    *        *   * *   *     *    *  *   *  *  |",
	"|     *     *    *  *    *         * *   * *      *    *  *    * *  |",
	"|     *     ******  ******          *     *       ******  *     **  |",
	"|                                                                   |",
	"---------------------------------------------------------------------"
};

void DrawMap() //������� ��������� ��������� ���� ���������
{
	for(int i = 0; i < 18; i++) {
		printf("%s\n",map[i] );
	}
}

void DrawKarta()  //������� ��������� ���������� ���� ���������
{
	for(int i = 0; i < 18; i++) {
		printf("%s\n",karta[i] );
	}
}

void DrawMap3()   //������� ��������� ������� ���� ���������
{
	for(int i = 0; i < 18; i++) {
		printf("%s\n",level3[i] );
	}
}

void ShowName()  //������� ������ ����� ��� �� �������
{
	for(int i = 0; i < 14; i++) {
		Sleep(100);
		printf("%s\n", name[i] );
	}
}

void ShowLose()   //������� ������ ������ "�� ��������"
{
	for(int i = 0; i < 10; i++) {
		Sleep(100);
		printf("%s\n", lose[i] );
	}
}

void ShowWin()   //������� ������ ������ "�� ���������"
{
	for(int i = 0; i < 10; i++) {
		Sleep(100);
		printf("%s\n", win[i] );
	}
}



void gotoxy( short x, short y ) //������� ������� ������ � ����� ������ �����������
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);  //������ ���������� �������� ������������ ������
    COORD position = { x, y };

    SetConsoleCursorPosition( hStdout, position );    //������������ ������ � ����� ������ ������������
}

class enemy { //��������� ����� ������ (enemy)
public:		
	enemy( int x, int y ){
		this -> x = x;
		this -> y = y;
	}

	void move_x( int p ){
		if( map[y][x+p] == ' ' ) x += p;
	}

	void move_y( int q ){
		if( map[y+q][x] == ' ' ) y += q;
	}

	void move( int p, int q ){
		x += p;
		y += q;
	}

	int get_x(){ return x; }
	int get_y(){ return y; }

	void draw( char p ){
		map[x][y] = p;
		gotoxy( x, y ); printf( "%c", p );
	}

private:
	int x;
	int y;
};

struct walk {       //��������� ��������� ����������
	short walk_count;
	short x;
	short y;
	short back;
};

struct target {     //��������� ��������� ����
	short x;
	short y;
};

vector<target> walk_queue;

vector<walk> BFSArray;

void AddArray( int x, int y, int wc , int back ){
	if( maptmp[y][x] == ' ' || maptmp[y][x] == '.' ){
		maptmp[y][x] = '?';
		walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = wc;
		tmp.back = back;
		BFSArray.push_back( tmp );
	}
}

void FindPath( int sx, int sy, int x, int y ){  //������� ������ ������ ��� ������ �� ���������� �����
	memcpy( maptmp, map, sizeof(map) );
	BFSArray.clear();
	walk tmp;
	tmp.x = sx;
	tmp.y = sy;
	tmp.walk_count = 0;
	tmp.back = -1;
	BFSArray.push_back( tmp );

	int i = 0;
	while( i < BFSArray.size() ){
		if( BFSArray[i].x == x && BFSArray[i].y == y ){
			walk_queue.clear();
			target tmp2;
			while( BFSArray[i].walk_count != 0 ){
				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back( tmp2 );

				i = BFSArray[i].back;
			}

			break;
		}

		AddArray( BFSArray[i].x+1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x-1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );

		i++;
	}

	BFSArray.clear();
}



int main()
{
	system("color 8F");     //������������ ���� ���� �� ����, � ���� ������� �� ����
	bool playing = true;    //����� ��� ���
	while (playing){        //���� ����� playing = true, ��� �� ������������ 
    bool running = true;    //����� ��� ����
	int x = 15;             //��������� ���������� x ��� �����
	int y = 16;             //��������� ���������� y ��� �����
	int old_x;				//���� ���������� � �����
	int old_y;				//���� ���������� � �����
	int ex = 1;				//��������� ���������� � ������
	int ey = 1;				//��������� ���������� � ������
	int pts = 0;			//������� ������� ������ (�����)(.)
	int speedmod;			//�������� ������
	char choise;			//���� ���� ��������/�������
	char diffi;				//���� ���������
	system("cls");			//�������� ������
	ShowName();				//�������� ����� ���
	printf("Rules:\n1. Use arrow to move your hero\n2. Eat the dots. You must eat 300 dots for win\n3. Be careful the enemy can eat you\n\n"); //������� ���
	printf("Choose level of difficulty:(Use only big letters)\nE - Easy\nN - Normal\nH - Hard\n\nYour choise: ");			//���� ���������
	cin >> diffi;
	/*-------------------------NORMAL  LEVEL-------------------------------------*/
	if( diffi == 'N' ){		//���� ������� N
		speedmod = 2;		//�� �������� ������ ���� 2

	system("cls");			//������� �����
    DrawKarta();			//������� ����� �������� ���������

	int frame = 0;

	FindPath(ex, ey, x, y);  //������������� ������� ������ ������ �� ��������� �����

	while( running ){		//���� �� ��������
		gotoxy( x, y ); cout << " "; //���� �� ��������� �� ���� ���� ������� "���"

		old_x = x;       //���������� ��� ���������� �� ������
		old_y = y;			

		if ( GetAsyncKeyState( VK_UP ) ){   //���� �������� ������ ������ �����
			if( karta[y-1][x] == '.' ){     //���� � ������ ���� � "���"
			y--;						    //�������� � �� ����	
			pts++;						    //������ +1 �� ����� pts
			karta[y][x] = ' ';			    //������ "��" ������� �����
 			} else
			if( karta[y-1][x] == ' ' ) y--; //���� � ������ ���� ���� "��", �� �������� � �� 1
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){ //���� ��������� ������ ������ ����
			if( karta[y+1][x] == '.' ){     //���� � ������ ���� � "���"
			y++;							//�������� � �� ����	
			pts++;							//������ +1 �� ����� pts
			karta[y][x] = ' ';				//������ "��" ������� �����
			} else
			if( karta[y+1][x] == ' ' ) y++; //���� � ������ ���� ���� "��", �� �������� � �� 1
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){ //���� ��������� ������ ������ ����
			if( karta[y][x-1] == '.' ){     //���� � ������ ���� � "���"
			x--;                            //�������� � �� ����	
			pts++;                          //������ +1 �� ����� pts
			karta[y][x] = ' ';              //������ "��" ������� �����
			} else
			if( karta[y][x-1] == ' ' ) x--; //���� � ������ ���� ���� "��", �� �������� � �� 1
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){ //���� ��������� ������ ������ ������
			if( karta[y][x+1] == '.' ){      //���� � ������ ���� � "���"
			x++;                             //�������� � �� ����
			pts++;                           //������ +1 �� ����� pts
			karta[y][x] = ' ';               //������ "��" ������� �����
			} else
			if( karta[y][x+1] == ' ' ) x++;  //���� � ������ ���� ���� "��", �� �������� � �� 1
		} 

		if( old_x != x || old_y != y ){    //���� ���� ���������� � ��� � �� ��������� �����, �� ������������� ������� 
			FindPath( ex,ey,x,y );		   //������ ������ ������ �� ��������� �����
		}

		gotoxy( x,y ); cout << "H";        //������������ ��������� ���� ��������� �����
		   
		gotoxy( ex, ey ); cout << " ";     //���� ����� ��� �� ���� "��" �� ����� �� "�'���"

		if( frame%speedmod == 0 && walk_queue.size() != 0 ){ //�������� ������
			ex = walk_queue.back().x;
			ey = walk_queue.back().y;
			walk_queue.pop_back();
		}
	
		gotoxy( ex, ey ); cout << "E";      //������������ ��������� ��������� ��� ������

		if( ex == x && ey == y ){   //���� ���������� ������ ���������� � ������������ ��������� �����, �� �������� � ����� running
			break;
		}
		   

		if(pts == 300) break; //���� ������� ������ "��" 300, �� �������� � ����� running

		gotoxy( 32, 1 ); cout << "Your score: " << pts; //� ������� ����������� �������� ����� "��� �������"
		gotoxy( 15, 18 ); cout << "^ ";          //� ������� �����������
		gotoxy( 15, 19 ); cout << "| ";			 // �������� ����������	
		gotoxy( 11, 20 ); cout << "You here ";   //��� ��������� ��������� �����                 	
		Sleep( 80 );
		frame++;
	}

	system("cls");
	}
		//��� �� ���� ����� ��� ���� hard 
		
		/*--------------------------------HARD LEVEL-------------------------*/
	else if( diffi == 'H' ){
		speedmod = 1;

	system("cls");
    DrawMap();

	int frame = 0;

	FindPath( ex,ey,x,y );

	while( running ){
		gotoxy( x, y ); cout << " ";

		old_x = x;
		old_y = y;

		if ( GetAsyncKeyState( VK_UP ) ){
			if( map[y-1][x] == '.' ){ 
			y--;
			pts++;
			map[y][x] = ' ';
			} else
			if( map[y-1][x] == ' ' ) y--;
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){
			if( map[y+1][x] == '.' ){ 
			y++;
			pts++;
			map[y][x] = ' ';
			} else
			if( map[y+1][x] == ' ' ) y++;
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){
			if( map[y][x-1] == '.' ){
			x--;
			pts++;
			map[y][x] = ' ';
			} else
			if( map[y][x-1] == ' ' ) x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){
			if( map[y][x+1] == '.' ){
			x++;
			pts++;
			map[y][x] = ' ';
			} else
			if( map[y][x+1] == ' ' ) x++;
		}

		if( old_x != x || old_y != y ){
			FindPath( ex,ey,x,y );
		}

		gotoxy( x,y ); cout << "H";
		
		gotoxy( ex, ey ); cout << " ";

		if( frame%speedmod == 0 && walk_queue.size() != 0 ){
			ex = walk_queue.back().x;
			ey = walk_queue.back().y;
			walk_queue.pop_back();
		}
	
		gotoxy( ex, ey ); cout << "E";

		if( ex == x && ey == y ){
			break;
		}

	if(pts == 300) break;

		gotoxy( 32, 1 ); cout << "Your score: " << pts;
		gotoxy( 15, 18 ); cout << "^ ";
		gotoxy( 15, 19 ); cout << "| ";
		gotoxy( 11, 20 ); cout << "You here ";
		Sleep( 80 );
		frame++;
	}

	system("cls");
	}
	//��� �� ���� ����� ��� ���� easy
	/*--------------EASY LEVEL----------------*/
	else if( diffi == 'E' ){
		speedmod = 3;
		system("cls");
		DrawMap3();

	int frame = 0;

	FindPath( ex,ey,x,y );

	while( running ){
		gotoxy( x, y ); cout << " ";

		old_x = x;
		old_y = y;

		if ( GetAsyncKeyState( VK_UP ) ){
			if( level3[y-1][x] == '.' ){ 
			y--;
			pts++;
			level3[y][x] = ' ';
			} else
			if( level3[y-1][x] == ' ' ) y--;
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){
			if( level3[y+1][x] == '.' ){ 
			y++;
			pts++;
			level3[y][x] = ' ';
			} else
			if( level3[y+1][x] == ' ' ) y++;
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){
			if( level3[y][x-1] == '.' ){
			x--;
			pts++;
			level3[y][x] = ' ';
			} else
			if( level3[y][x-1] == ' ' ) x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){
			if( level3[y][x+1] == '.' ){
			x++;
			pts++;
			level3[y][x] = ' ';
			} else
			if( level3[y][x+1] == ' ' ) x++;
		}

		if( old_x != x || old_y != y ){
			FindPath( ex,ey,x,y );
		}

		gotoxy( x,y ); cout << "H";

		gotoxy( ex, ey ); cout << " ";

		if( frame%speedmod == 0 && walk_queue.size() != 0 ){
			ex = walk_queue.back().x;
			ey = walk_queue.back().y;
			walk_queue.pop_back();
		}
	
		gotoxy( ex, ey ); cout << "E";

		if( ex == x && ey == y ){
			break;
		}

		if(pts == 300) break;

		gotoxy( 32, 1 ); cout << "Your score: " << pts;	
		gotoxy( 15, 18 ); cout << "^ ";
		gotoxy( 15, 19 ); cout << "| ";
		gotoxy( 11, 20 ); cout << "You here ";
		Sleep( 80 );
		frame++;
	}

	system("cls");
	}
	

	if(pts == 300) //���� ������� 300 ����
	{
	 ShowWin();  //������� ����������� ��� ��������
	 printf("If you want to play again enter R\n"); 
	 printf("If you want to exit enter X\n");
	 printf("Your choise -> ");
	 cin >> choise;
	 	if(choise == 'R')	continue; //���� ����� R ����������� � ������� ����� playing
	 	
	 	if(choise == 'X')	return 0; //���� ����� � �������� � ����� playing
	 	
	}
	else //���� �� ������� 300 ����
	{
		ShowLose(); //������� ����������� ��� �������
		printf("If you want to play again enter R\n");
		printf("If you want to exit enter X\n");
		printf("Your choise -> ");
		cin >> choise;
	 	if(choise == 'R')	continue; //���� ����� R ���������� � ������� ����� playing
	 	
	 	if(choise == 'X') 	return 0; //���� ����� � �������� � ����� playing
	 	
	}
}
    return 0;
}

