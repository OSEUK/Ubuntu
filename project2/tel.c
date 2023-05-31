#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define MIN_ENTRY 200
// 이름, 전화번호, 메모를 한번에 관리할 구조체 TelBook 정의
struct TelBook {
	char name[30];
	char phone[20];
	char memo[40];
};

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;

char *choices[] = {
		"Search",
		"Add",
		"Delete",
		"List",
		"Exit",
};

// 검색, 추가, 삭제, 리스트 출력 함수 선언
void search_tel(const char *filename, char *contents);
void add_tel(const char *filename, struct TelBook *book);
void delete_tel(const char *filename,  const char *contents);
void print_list(const char *filename );
int compare(const void *a, const void *b);

int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);

int main()
{
	WINDOW *menu_win;
	int highlight = 1;
	int choice = 0;
	int c;

	initscr();
	clear();
	noecho();
	cbreak();
	int Mx, My;
	getmaxyx(stdscr, My, Mx);

	menu_win = newwin(9, Mx-5, 6, 0);
	keypad(menu_win, TRUE);
	printw("TelBook Program of ncurses.\n");
	printw("1. search : insert (contents) \n");
	printw("2. add : insert (name) (phone) (memo)\n");
	printw("3. delete : insert (contents) \n");
	printw("4. list : sort data and print \n");
	refresh();
	print_menu(menu_win, highlight);
	while(1)
	{
		c = wgetch(menu_win);
		switch(c)
		{
			case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else
					++highlight;
				break;
			case 10 :
				choice = highlight;
				break;
			default :
				mvprintw(20, 0, "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		print_menu(menu_win, highlight);
		if (choice != 0)
			break;
	}
	mvprintw(18, 0, "You chose choice %d with choice string %s\n", choice, choices[choice-1]);
	clrtoeol();
	refresh();

	if ( choice == 2 ){
		// TelBook 동적 할당 후 arg값 설정 
		
		struct TelBook *book = malloc(sizeof(struct TelBook));
		char ch;
		mvprintw(24,0,"name: "); getstr(book->name); mvprintw(24, 10,"%s", book->name); refresh();
		mvprintw(25,0,"phone :"); getstr(book->phone); mvprintw(25, 10,"%s", book->phone); refresh();
		mvprintw(26,0,"memo : "); getstr(book->memo); mvprintw(26, 10, "%s", book->memo); refresh();
		
		// 추가할 것인지 확인
		mvprintw(27, 0, "%s %s %s\n", book->name, book->phone, book->memo);
		refresh();
		printf("add? [Y/N]: ");
		refresh();
		ch = getchar();
		
		// Y입력시 data.txt에 추가한다.
		if(ch == 'Y' || ch == 'y'){
			mvprintw(28,0,"Add Succeed.\n");
			add_tel("data.txt", book);
		}
		else
			mvprintw(28,0,"Add failed.\n");

	}
	// -d 입력시 delete_tel 작동
	else if ( choice == 3 ){
		char *contents;
		mvprintw(23,0, "Which string ?:");
		getstr(contents);	
		delete_tel("data.txt",contents  );
		
	}
	// -l 입력시 list 출력 함수 작동
	else if ( choice == 4 ){
		print_list("data.txt");
		
	}
	// 위 커맨드 외에 다른 것이 입력되었다면 search_tel을 활용하여 일치하는 값이 있는지 찾는다.
	else if ( choice == 1){
		char *contents;
		mvprintw(19,0,"Which string? :");
		getstr(contents);
		search_tel("data.txt", contents);
	}
	
	getch();	
	endwin();
	return 0;
}

void print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;
	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	mvwprintw(menu_win,0,0,"Select One");
	for(i=0 ; i < n_choices; ++i)
	{
		if(highlight == i+1)
		{
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}
// 찾기 함수. filename과 찾을 요소를 입력받음
void search_tel(const char *filename,  char *contents)
{
	// fopen을 통해 data.txt를 불러온다. read모드
        FILE *file = fopen(filename, "r");
        int i = 0;	
	// 없는 파일이면 찾기 x
        if ( file == NULL ){
                printf("You can't open file.\n");
             	return ;
        }
	
	// TelBook과 파일을 한줄씩 읽어올 line배열 선언
	struct TelBook book;
        char line[MIN_ENTRY];
	// 한 줄씩 읽어와서 name, phone, memo를 구분자로 나누어서 받아온다.
        while (fgets(line, sizeof(line), file)) {
                strcpy(book.name, strtok(line, ":"));
                strcpy(book.phone , strtok(NULL, ":"));
        	strcpy(book.memo, strtok(NULL,":"));	
		
		// name, phone, memo중에서 찾는 요소를 포함하고 있는 부분이 있다면 화면에 출력한다.
                if (strstr(book.name, contents) != NULL || strstr(book.phone, contents) != NULL || strstr(book.memo, contents) != NULL) {
		// 읽어온 라인 순서대로 1, 2, 3순서로 받기 위해 i변수 선언
                mvprintw(i+20,0,"%d %s %s %s", i+1, book.name, book.phone, book.memo);		
		i++;
                }
        }
	// file 닫기
        fclose(file);
        
	// 찾은 라인이 있다면 추가로 match foound 출력
	if( i > 0)
                mvprintw(i+20,0,"match found.\n");
        else
                mvprintw(i+20,0,"no match found.\n");
}
// 전화번호부에 목록을 추가하는 함수, filename과 TelBook을 받는다.
void add_tel(const char *filename, struct TelBook *book)
{
        FILE *file = fopen(filename, "a");
        if (file == NULL) {
                printf("You can't open file.\n");
                return ;
        }
	// add함수를 실행하기 전 에 argv를 활용하여 미리 구조체를 선언해두었다. file에 추가로 쓰기 위해 fprintf함수를 사용.
        fprintf(file, "%s:%s:%s\n", book->name, book->phone, book->memo);

        fclose(file);
}
// 전화번호부에서 목록을 제거하는 함수, filename과 제거할 요소를 포함하고있는 부분을 입력받음
void delete_tel(const char *filename, const char *contents) {
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
                printf("You can't open file.\n");
                return ;
        }
	// line배열으로 한 줄씩 입력받는다.
	// d[]배열을 사용하여 삭제할 line이 txt원본의 몇 번째 줄에 있는지 기록한다.
        char line[MIN_ENTRY];
        int i= 0,j = 0;
	int *d = NULL;
	// 삭제할 줄을 제거하고 처음부터 입력하기 위해 data를 순서대로 book에 저장한다.
	struct TelBook book[MIN_ENTRY];
        while(fgets(line, sizeof(line), file)){
                strcpy(book[i].name, strtok(line, ":"));
                strcpy(book[i].phone , strtok(NULL, ":"));
                strcpy(book[i].memo , strtok(NULL, ":"));
		
		// search와 마찬가지로 찾는다. 3번째 줄에서 처음 삭제 대상 요소가 발견된다면 d[0] = 3이 된다.
                if(strstr(book[i].name, contents) != NULL || strstr(book[i].phone, contents) != NULL || strstr(book[i].memo, contents) != NULL){
	                mvprintw(j+24,0,"%d %s %s %s\n", j + 1, book[i].name, book[i].phone, book[i].memo);
			d = realloc(d, (j + 1) * sizeof(int));
			d[j] = i;
			j++;
		}
		i++;
        }
 	// 다시 줄만큼 출력하기 위해 num변수 저장
	int num = i;
	
	fclose(file);

	// 파일을 닫은 뒤 w쓰기모드로 다시 연다.
	file = fopen(filename, "w");
	
	// 삭제 대상 line중 몇 번째 line을 지울 건지 선택
	int k;
        mvprintw(j+24,0,"which one? : ");
        mvscanw(j+24, 10, "%d", &k);
	
	if ( k <= 0 || k > j ){
		mvprintw(j+24,0, "No range. can't remove.\n");
		for( i=0; i<num; i++ )
                        fprintf(file, "%s:%s:%s", book[i].name, book[i].phone, book[i].memo);
	}
	else {
	// d[k-1]으로 삭제 대상 줄이 원 본의 몇 번째 줄인지 알 수 있다. 그 줄을 제외하고 다시 입력.
		mvprintw(j+24,0,"removed.\n");
        	for( i=0; i<num; i++ ){
			if( i == d[k-1])
				continue;
			else
				fprintf(file, "%s:%s:%s", book[i].name, book[i].phone, book[i].memo);
		}
	}
	free(d);
        fclose(file);
}
// qsort를 사용하기 위해 compare함수 제작. name을 기준으로 비교한다.
int compare(const void *a, const void *b) {
    const struct TelBook *A = (const struct TelBook *)a;
    const struct TelBook *B = (const struct TelBook *)b;
    return strcmp(A->name, B->name);
}
// 정렬된 list를 출력하는 함수. filename을 인수로 받음
void print_list(const char *filename) {
        FILE *file = fopen(filename, "r");
        if ( file == NULL ) {
                printf("You can't open file.\n");
                return ;
        }
	// delete와 마찬가지로 book을 선언하여 line별로 저장한다.
        int i = 0;
        char line[MIN_ENTRY];
	struct TelBook book[MIN_ENTRY];
        while (fgets(line, sizeof(line), file)) {
                strcpy(book[i].name,strtok(line,":"));
                strcpy(book[i].phone,strtok(NULL,":"));
                strcpy(book[i].memo,strtok(NULL,":"));
                i++;
        }
	// 입력된 만큼 출력하기 위해 num에 저장
	int num = i;
	// qsort를 사용하여 name별로 정렬한다.
	qsort(book , i, sizeof(struct TelBook), compare);
        
	// 출력
        for (i = 0; i < num; i++) {
        mvprintw(i+24,0,"%d %s %s %s\n", i + 1, book[i].name, book[i].phone, book[i].memo);
        }

    fclose(file);
}

