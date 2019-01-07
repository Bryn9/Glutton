#include <iostream>    //á³áë³îòåêà äëÿ ââîäó/âèâîäó ³íôîðìàö³¿
#include <windows.h>   /*çàãîëîâî÷íèé ôàéë, ÿêèé ì³ñòèòü äåêëàðàö³¿ äëÿ âñ³õ ôóíêö³é Windows API, âñ³ çàãàëüí³ ìàêðîñè ³ 
                       âñ³ òèïè äàíèõ, ùî âèêîðèñòîâóþòüñÿ ð³çíèìè ôóíêö³ÿìè ³ ï³äñèñòåìè*/

#include <vector>

using namespace std;

char maptmp[20][35]; //òèì÷àñîâà ìàïà

char name[14][62] = {   //Íàçâàíèå èãðû
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

char map[20][35] = {             //Ñëîæíûé óðîâåíü
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	"@ ...............................@",
	"@................................@",
	"@................................@",
	"@.....@..@..@@@@..@@@@..@@@@.....@",
	"@.....@..@..@  @..@  @..@  @.....@",
	"@.....@@@@..@@@@..@@@@..@  @.....@",
	"@.....@..@..@..@..@.@...@  @.....@",
	"@.....@..@..@..@..@..@..@@@@.....@",
	"@................................@",
	"@................................@", 
	"@...@....@@@..@...@..@@@..@......@",
	"@...@....@....@...@..@....@......@",
	"@...@....@@@..@...@..@@@..@......@",
	"@...@....@.....@ @...@....@......@",
	"@...@@@@.@@@....@....@@@..@@@@...@",
	"@................................@",
	"@................................@",
	"@............................... @",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	};
	
char karta[20][35] = {           //Íîðìàëüíûé óðîâåíü 
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	"@ ...............................@",
	"@................................@",
	"@................................@",
	"@..@...@..@@@@..@@@@@..@.....@...@",
	"@..@@..@..@  @..@   @..@@...@@...@",
	"@..@.@.@..@  @..@@@@@..@.@.@.@...@",
	"@..@..@@..@  @..@.@....@..@..@...@",
	"@..@...@..@@@@..@...@..@.....@...@",
	"@................................@",
	"@................................@",
	"@...@....@@@..@...@..@@@..@......@", 
	"@...@....@....@...@..@....@......@",
	"@...@....@@@..@...@..@@@..@......@",
	"@...@....@.....@ @...@....@......@",
	"@...@@@@.@@@....@....@@@..@@@@...@",
	"@................................@",
	"@................................@",
	"@............................... @",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
};

char level3[20][35] = {          //Ëåãêèé óðîâåíü
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	"@ ...............................@",
	"@................................@",
	"@................................@",
	"@.....@@@@..@@@@..@@@@..@...@....@",
	"@.....@.....@  @..@......@.@.....@",
	"@.....@@@@..@@@@..@@@@....@......@",
	"@.....@.....@..@.....@....@......@",
	"@.....@@@@..@..@..@@@@....@......@",
	"@................................@",
	"@................................@", 
	"@...@....@@@..@...@..@@@..@......@",
	"@...@....@....@...@..@....@......@",
	"@...@....@@@..@...@..@@@..@......@",
	"@...@....@.....@ @...@....@......@",
	"@...@@@@.@@@....@....@@@..@@@@...@",
	"@................................@",
	"@................................@",
	"@............................... @",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
};

char lose[10][65] = {             //Íàäïèñü î ïðîèãðûøå
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

char win[10][70] = {              //Íàäïèñü î âûèãðûøå
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

void DrawMap() //Ôóíêö³ÿ ìàëþâàííÿ ñêëàäíîãî ð³âíÿ ñêëàäíîñò³
{
	for(int i = 0; i < 20; i++) {
		printf("%s\n",map[i] );
	}
}

void DrawKarta()  //Ôóíêö³ÿ ìàëþâàííÿ ñåðåäíüîãî ð³âíÿ ñêëàäíîñò³
{
	for(int i = 0; i < 20; i++) {
		printf("%s\n",karta[i] );
	}
}

void DrawMap3()   //Ôóíêö³ÿ ìàëþâàííÿ ëåãêîãî ð³âíÿ ñêëàäíîñò³
{
	for(int i = 0; i < 20; i++) {
		printf("%s\n",level3[i] );
	}
}

void ShowName()  //Ôóíêö³ÿ ïîêàçó íàçâè ãðè íà ïî÷àòêó
{
	for(int i = 0; i < 14; i++) {
		Sleep(100);
		printf("%s\n", name[i] );
	}
}

void ShowLose()   //ôóíêö³ÿ ïîêàçó íàïèñó "Âè ïðîãðàëè"
{
	for(int i = 0; i < 10; i++) {
		Sleep(100);
		printf("%s\n", lose[i] );
	}
}

void ShowWin()   //ôóíêö³ÿ ïîêàçó íàïèñó "Âè ïåðåìîãëè"
{
	for(int i = 0; i < 10; i++) {
		Sleep(100);
		printf("%s\n", win[i] );
	}
}



void gotoxy( short x, short y ) //Ôóíêö³ÿ ïåðåì³ùóº êóðñîð â òî÷êó çàäàíó êîîðäèíàòèì³
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);  //îòðèìóº äåñêðèïòîð ïðèñòðîþ ñòàíäàðòíîãî âèâîäó
    COORD position = { x, y };

    SetConsoleCursorPosition( hStdout, position );    //Âñòàíîâëþºìó êóðñîð â òî÷êó çàäàíó êîîðäèíàòàìè
}

class enemy { //ñòâîðþºìî êëàññ âîðîãà (enemy)
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

struct walk {       //ñòâîðþºìî ñòðóêòóðó ïåðåì³ùåííÿ
	short walk_count;
	short x;
	short y;
	short back;
};

struct target {     //ñòâîðþºìî ñòðóêòóðó ö³ëü
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

void FindPath( int sx, int sy, int x, int y ){  //ôóíêö³ÿ ïîøóêó äîðîãè äëÿ âîðîãà äî ãîëîâííîãî ãåðîÿ
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
	system("color 8F");     //âñòàíîâëþºìî êîë³ð ôîíó íà ñ³ðèé, à êîë³ð ñèìâîë³â íà á³ëèé
	bool playing = true;    //çì³ííà äëÿ ãðè
	while (playing){        //Ïîêè çì³ííà playing = true, ãðà íå çàêðûâàýòüñÿ 
    bool running = true;    //çì³ííà äëÿ ðóõó
	int x = 32;             //ïî÷àòêîâà êîîðäèíàòà x äëÿ ãåðîÿ
	int y = 18;             //ïî÷àòêîâà êîîðäèíàòà y äëÿ ãåðîÿ
	int old_x;				//ñòàð³ êîîðäèíàòè õ ãåðîÿ
	int old_y;				//ñòàð³ êîîðäèíàòè ó ãåðîÿ
	int ex = 1;				//ïî÷àòêîâà êîîðäèíàòà õ âîðîãà
	int ey = 1;				//ïî÷àòêîâà êîîðäèíàòà ó âîðîãà
	int pts = 0;			//ê³ëüê³ñòü ç³áðàíèõ ôðóêò³â (òî÷îê)(.)
	int speedmod;			//Øâèäê³ñòü âîðîãà
	char choise;			//Âèá³ð ï³ñëÿ ïðîãðàøó/âèãðàøó
	char diffi;				//Âèá³ð ñêëàäíîñò³
	system("cls");			//Î÷èùåííÿ åêðàíó
	ShowName();				//Âèâîäèìî íàçâó ãðè
	printf("Rules:\n1. Use arrow to move your hero\n2. Eat the dots. You must eat 350 dots for win\n3. Be careful the enemy can eat you\n\n"); //Ïðàâèëà ãðè
	printf("Choose level of difficulty:(Use only big letters)\nE - Easy\nN - Normal\nH - Hard\n\nYour choise: ");			//Âèá³ð ñêëàäíîñò³
	cin >> diffi;
	/*-------------------------NORMAL  LEVEL-------------------------------------*/
	if( diffi == 'N' ){		//ÿêùî âèáðàëè N
		speedmod = 2;		//òî øâèäê³ñòü âîðîãà áóäå 2

	system("cls");			//î÷èùóºìî åêðàí
    DrawKarta();			//ìàëþºìî êàðòó ñåðåäíüî¿ ñêëàäíîñò³

	int frame = 0;

	FindPath(ex, ey, x, y);  //âèêîðèñòóâîºìî ôóíêö³þ ïîøóêó äîðîãè äî ãîëîâíîãî ãåðîÿ

	while( running ){		//ïîêè ìè ðóõàºìîñÿ
		gotoxy( x, y ); cout << " "; //êîëè ìè ðóõàýìîñÿ çà íàìè áóäå çíèêàòè "¿æà"

		old_x = x;       //ïðèñâîþºìî íîâ³ êîîðäèíàòè äî ñòàðèõ
		old_y = y;			

		if ( GetAsyncKeyState( VK_UP ) ){   //ÿêùî íòèñíóòà êëàâ³øà ñòð³ëêà âãîðó
			if( karta[y-1][x] == '.' ){     //ÿêùî ó äàíîìó ì³ñö³ º "¿æà"
			y--;						    //çìåíøóºìî ó íà îäèí	
			pts++;						    //äîäàºìî +1 äî çì³ííî¿ pts
			karta[y][x] = ' ';			    //çàì³ñòü "¿æ³" ìàëþºìî í³÷îãî
 			} else
			if( karta[y-1][x] == ' ' ) y--; //ÿêùî ó äàíîìó ì³ñö³ íåìàº "¿æ³", òî çìåíøóºìî ó íà 1
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){ //ÿêùî íàòèñíóòà êëàâ³øà ñòð³ëêà âíèç
			if( karta[y+1][x] == '.' ){     //ÿêùî ó äàíîìó ì³ñö³ º "¿æà"
			y++;							//çá³ëüøóºìî ó íà îäèí	
			pts++;							//äîäàºìî +1 äî çì³ííî¿ pts
			karta[y][x] = ' ';				//çàì³ñòü "¿æ³" ìàëþºìî í³÷îãî
			} else
			if( karta[y+1][x] == ' ' ) y++; //ÿêùî ó äàíîìó ì³ñö³ íåìàº "¿æ³", òî çá³ëüøóºìî ó íà 1
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){ //ÿêùî íàòèñíóòà êëàâ³øà ñòð³ëêà âë³âî
			if( karta[y][x-1] == '.' ){     //ÿêùî ó äàíîìó ì³ñö³ º "¿æà"
			x--;                            //çìåíøóºìî õ íà îäèí	
			pts++;                          //äîäàºìî +1 äî çì³ííî¿ pts
			karta[y][x] = ' ';              //çàì³ñòü "¿æ³" ìàëþºìî í³÷îãî
			} else
			if( karta[y][x-1] == ' ' ) x--; //ÿêùî ó äàíîìó ì³ñö³ íåìàº "¿æ³", òî çìåíøóºìî ó íà 1
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){ //ÿêùî íàòèñíóòà êëàâ³øà ñòð³ëêà âïðàâî
			if( karta[y][x+1] == '.' ){      //ÿêùî ó äàíîìó ì³ñö³ º "¿æà"
			x++;                             //çá³ëüøóºìî õ íà îäèí
			pts++;                           //äîäàºìî +1 äî çì³ííî¿ pts
			karta[y][x] = ' ';               //çàì³ñòü "¿æ³" ìàëþºìî í³÷îãî
			} else
			if( karta[y][x+1] == ' ' ) x++;  //ÿêùî ó äàíîìó ì³ñö³ íåìàº "¿æ³", òî çá³ëüøóºìî õ íà 1
		} 

		if( old_x != x || old_y != y ){    //ÿêùî ñòàð³ êîîðäèíàòè õ àáî ó íå äîð³âíþþòü íîâèì, òî âèêîðèñòîâóºìî ôóíêö³þ 
			FindPath( ex,ey,x,y );		   //ïîøóêó äîðîãè âîðîãà äî ãîëîâíîãî ãåðîÿ
		}

		gotoxy( x,y ); cout << "H";        //âñòàíîâëþºìî ïî÷àòêîâå ì³ñöå ãîëîâíîãî ãåðîÿ
		   
		gotoxy( ex, ey ); cout << " ";     //êîëè âîðîã ñòàº íà ì³ñöå "¿æ³" â³í òàêîæ ¿¿ "ç'¿äàº"

		if( frame%speedmod == 0 && walk_queue.size() != 0 ){ //øâèäê³ñòü âîðîãà
			ex = walk_queue.back().x;
			ey = walk_queue.back().y;
			walk_queue.pop_back();
		}
	
		gotoxy( ex, ey ); cout << "E";      //âñòàíîâëþºìî ïî÷àòêîâå ïîëîæåííÿ äëÿ âîðîãà

		if( ex == x && ey == y ){   //ÿêùî êîîðæèíàòè âîðîãà ñï³âïàäàþòü ç êîîðäèíàòàìè ãîëîâíîãî ãåðîÿ, òî âèõîäèìî ç öèêëó running
			break;
		}
		   

		if(pts == 350) break; //ÿùêî ê³ëüê³ñòü ç³áðàíî¿ "¿æ¿" 300, òî âèõîäèìî ç öèêëó running

		gotoxy( 36, 1 ); cout << "Your score: " << pts; //ó çàäàíèõ êîîðäèíàòàõ âèâîäèìî íàïèñ "Âàø ðàõóíîê"
		gotoxy( 36, 18 ); cout << "<--- You here ";     //ó çàäàíèõ êîîðäèíàòàõ
				                                        // âèâîäèìî ³íôîðìàö³þ	
		                                                //ïðî ïîëîæåííÿ ãîëîâíîãî ãåðîÿ                 	
		Sleep( 80 );
		frame++;
	}

	system("cls");
	}
		//Äàë³ òå ñàìå ò³ëüêè äëÿ ð³âíÿ hard 
		
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

	if(pts == 350) break;

		gotoxy( 36, 1 ); cout << "Your score: " << pts; 
		gotoxy( 36, 18 ); cout << "<--- You here ";               	
		Sleep( 80 );
		frame++;
	}

	system("cls");
	}
	//Äàë³ òå ñàìå ò³ëüêè äëÿ ð³âíÿ easy
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

		if(pts == 350) break;

		gotoxy( 36, 1 ); cout << "Your score: " << pts; 
		gotoxy( 36, 18 ); cout << "<--- You here ";               	
		Sleep( 80 );
		frame++;
	}

	system("cls");
	}
	

	if(pts == 350) //ÿêùî íàáðàíî 350 î÷îê
	{
	 ShowWin();  //ìàëþºìî ïîâ³äîìëåííÿ ïðî ïåðåìîãó
	 printf("If you want to play again enter R\n"); 
	 printf("If you want to exit enter X\n");
	 printf("Your choise -> ");
	 cin >> choise;
	 	if(choise == 'R')	continue; //ÿêùî ââåëè R ïîâåðòàºìîñÿ â ïî÷àòîê öèêëó playing
	 	
	 	if(choise == 'X')	return 0; //ßêùî ââåëè Õ âèõîäèìî ç öèêëó playing
	 	
	}
	else //ÿêùî íå íàáðàíî 350 î÷îê
	{
		ShowLose(); //ìàëþºìî ïîâ³äîìëåííÿ ïðî ïðîãðàø
		printf("If you want to play again enter R\n");
		printf("If you want to exit enter X\n");
		printf("Your choise -> ");
		cin >> choise;
	 	if(choise == 'R')	continue; //ÿêùî ââåëè R îâåðòàýìîÿ â ïî÷àòîê öèêëó playing
	 	
	 	if(choise == 'X') 	return 0; //ßêùî ââåëè Õ âèõîäèìî ç öèêëó playing
	 	
	}
}
    return 0;
}
