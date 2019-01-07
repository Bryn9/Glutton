#include <iostream>    //бібліотека для вводу/виводу інформації
#include <windows.h>   /*заголовочний файл, який містить декларації для всіх функцій Windows API, всі загальні макроси і 
                       всі типи даних, що використовуються різними функціями і підсистеми*/

#include <vector>

using namespace std;

char maptmp[18][32]; //тимчасова мапа

char name[14][62] = {   //Название игры
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

char map[18][32] = {             //Сложный уровень
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
	
char karta[18][32] = {           //Нормальный уровень 
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

char level3[18][32] = {          //Легкий уровень
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

char lose[10][65] = {             //Надпись о проигрыше
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

char win[10][70] = {              //Надпись о выигрыше
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

void DrawMap() //Функція малювання складного рівня складності
{
	for(int i = 0; i < 18; i++) {
		printf("%s\n",map[i] );
	}
}

void DrawKarta()  //Функція малювання середнього рівня складності
{
	for(int i = 0; i < 18; i++) {
		printf("%s\n",karta[i] );
	}
}

void DrawMap3()   //Функція малювання легкого рівня складності
{
	for(int i = 0; i < 18; i++) {
		printf("%s\n",level3[i] );
	}
}

void ShowName()  //Функція показу назви гри на початку
{
	for(int i = 0; i < 14; i++) {
		Sleep(100);
		printf("%s\n", name[i] );
	}
}

void ShowLose()   //функція показу напису "Ви програли"
{
	for(int i = 0; i < 10; i++) {
		Sleep(100);
		printf("%s\n", lose[i] );
	}
}

void ShowWin()   //функція показу напису "Ви перемогли"
{
	for(int i = 0; i < 10; i++) {
		Sleep(100);
		printf("%s\n", win[i] );
	}
}



void gotoxy( short x, short y ) //Функція переміщує курсор в точку задану координатимі
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);  //отримує дескриптор пристрою стандартного виводу
    COORD position = { x, y };

    SetConsoleCursorPosition( hStdout, position );    //Встановлюєму курсор в точку задану координатами
}

class enemy { //створюємо класс ворога (enemy)
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

struct walk {       //створюємо структуру переміщення
	short walk_count;
	short x;
	short y;
	short back;
};

struct target {     //створюємо структуру ціль
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

void FindPath( int sx, int sy, int x, int y ){  //функція пошуку дороги для ворога до головнного героя
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
	system("color 8F");     //встановлюємо колір фону на сірий, а колір символів на білий
	bool playing = true;    //змінна для гри
	while (playing){        //Поки змінна playing = true, гра не закрываэться 
    bool running = true;    //змінна для руху
	int x = 15;             //початкова координата x для героя
	int y = 16;             //початкова координата y для героя
	int old_x;				//старі координати х героя
	int old_y;				//старі координати у героя
	int ex = 1;				//початкова координата х ворога
	int ey = 1;				//початкова координата у ворога
	int pts = 0;			//кількість зібраних фруктів (точок)(.)
	int speedmod;			//Швидкість ворога
	char choise;			//Вибір після програшу/виграшу
	char diffi;				//Вибір складності
	system("cls");			//Очищення екрану
	ShowName();				//Виводимо назву гри
	printf("Rules:\n1. Use arrow to move your hero\n2. Eat the dots. You must eat 300 dots for win\n3. Be careful the enemy can eat you\n\n"); //Правила гри
	printf("Choose level of difficulty:(Use only big letters)\nE - Easy\nN - Normal\nH - Hard\n\nYour choise: ");			//Вибір складності
	cin >> diffi;
	/*-------------------------NORMAL  LEVEL-------------------------------------*/
	if( diffi == 'N' ){		//якщо вибрали N
		speedmod = 2;		//то швидкість ворога буде 2

	system("cls");			//очищуємо екран
    DrawKarta();			//малюємо карту середньої складності

	int frame = 0;

	FindPath(ex, ey, x, y);  //використувоємо функцію пошуку дороги до головного героя

	while( running ){		//поки ми рухаємося
		gotoxy( x, y ); cout << " "; //коли ми рухаэмося за нами буде зникати "їжа"

		old_x = x;       //присвоюємо нові координати до старих
		old_y = y;			

		if ( GetAsyncKeyState( VK_UP ) ){   //якщо нтиснута клавіша стрілка вгору
			if( karta[y-1][x] == '.' ){     //якщо у даному місці є "їжа"
			y--;						    //зменшуємо у на один	
			pts++;						    //додаємо +1 до змінної pts
			karta[y][x] = ' ';			    //замість "їжі" малюємо нічого
 			} else
			if( karta[y-1][x] == ' ' ) y--; //якщо у даному місці немає "їжі", то зменшуємо у на 1
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){ //якщо натиснута клавіша стрілка вниз
			if( karta[y+1][x] == '.' ){     //якщо у даному місці є "їжа"
			y++;							//збільшуємо у на один	
			pts++;							//додаємо +1 до змінної pts
			karta[y][x] = ' ';				//замість "їжі" малюємо нічого
			} else
			if( karta[y+1][x] == ' ' ) y++; //якщо у даному місці немає "їжі", то збільшуємо у на 1
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){ //якщо натиснута клавіша стрілка вліво
			if( karta[y][x-1] == '.' ){     //якщо у даному місці є "їжа"
			x--;                            //зменшуємо х на один	
			pts++;                          //додаємо +1 до змінної pts
			karta[y][x] = ' ';              //замість "їжі" малюємо нічого
			} else
			if( karta[y][x-1] == ' ' ) x--; //якщо у даному місці немає "їжі", то зменшуємо у на 1
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){ //якщо натиснута клавіша стрілка вправо
			if( karta[y][x+1] == '.' ){      //якщо у даному місці є "їжа"
			x++;                             //збільшуємо х на один
			pts++;                           //додаємо +1 до змінної pts
			karta[y][x] = ' ';               //замість "їжі" малюємо нічого
			} else
			if( karta[y][x+1] == ' ' ) x++;  //якщо у даному місці немає "їжі", то збільшуємо х на 1
		} 

		if( old_x != x || old_y != y ){    //якщо старі координати х або у не дорівнюють новим, то використовуємо функцію 
			FindPath( ex,ey,x,y );		   //пошуку дороги ворога до головного героя
		}

		gotoxy( x,y ); cout << "H";        //встановлюємо початкове місце головного героя
		   
		gotoxy( ex, ey ); cout << " ";     //коли ворог стає на місце "їжі" він також її "з'їдає"

		if( frame%speedmod == 0 && walk_queue.size() != 0 ){ //швидкість ворога
			ex = walk_queue.back().x;
			ey = walk_queue.back().y;
			walk_queue.pop_back();
		}
	
		gotoxy( ex, ey ); cout << "E";      //встановлюємо початкове положення для ворога

		if( ex == x && ey == y ){   //якщо кооржинати ворога співпадають з координатами головного героя, то виходимо з циклу running
			break;
		}
		   

		if(pts == 300) break; //ящко кількість зібраної "їжї" 300, то виходимо з циклу running

		gotoxy( 32, 1 ); cout << "Your score: " << pts; //у заданих координатах виводимо напис "Ваш рахунок"
		gotoxy( 15, 18 ); cout << "^ ";          //у заданих координатах
		gotoxy( 15, 19 ); cout << "| ";			 // виводимо інформацію	
		gotoxy( 11, 20 ); cout << "You here ";   //про положення головного героя                 	
		Sleep( 80 );
		frame++;
	}

	system("cls");
	}
		//Далі те саме тільки для рівня hard 
		
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
	//Далі те саме тільки для рівня easy
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
	

	if(pts == 300) //якщо набрано 300 очок
	{
	 ShowWin();  //малюємо повідомлення про перемогу
	 printf("If you want to play again enter R\n"); 
	 printf("If you want to exit enter X\n");
	 printf("Your choise -> ");
	 cin >> choise;
	 	if(choise == 'R')	continue; //якщо ввели R повертаємося в початок циклу playing
	 	
	 	if(choise == 'X')	return 0; //Якщо ввели Х виходимо з циклу playing
	 	
	}
	else //якщо не набрано 300 очок
	{
		ShowLose(); //малюємо повідомлення про програш
		printf("If you want to play again enter R\n");
		printf("If you want to exit enter X\n");
		printf("Your choise -> ");
		cin >> choise;
	 	if(choise == 'R')	continue; //якщо ввели R овертаэмоя в початок циклу playing
	 	
	 	if(choise == 'X') 	return 0; //Якщо ввели Х виходимо з циклу playing
	 	
	}
}
    return 0;
}

