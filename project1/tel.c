#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TelBook {
	char name[30];
	char phone[20];
	char memo[40];
};

void search_tel(const char *filename, char *contents);
void add_tel(const char *filename, struct TelBook *book);
void delete_tel(const char *filename,  const char *contents);
void print_list(const char *filename );

int main(int argc, char *argv[])
{	
	char choice;
	

	if (argc < 2){
		printf("전화번호부 관리 프로그램입니다.\n");
		printf("찾기 : $tel (contents)으로 일치하는 요소를 찾아줍니다.\n");
		printf("추가 : $tel -a (contents)으로 전화번호부에 추가합니다.\n");
		printf("삭제 : $tel -d (name)으로 전화번호부에서 삭제합니다.\n");
		printf("리스트 : $tel -l 이름 순으로 정렬하여 전화번호부 전체를 출력합니다.\n");
	}
	else{
	if ( strcmp(argv[1],"-a") == 0 ){
		struct TelBook *book = malloc(sizeof(struct TelBook));

		strcpy(book->name, argv[2]);
		strcpy(book->phone, argv[3]);
		strcpy(book->memo, argv[4]);
		
		printf("add? [Y/N]: ");
		choice = getchar();

		
		
		if(choice == 'Y')
			add_tel("data.txt", book);

	}
	else if ( strcmp(argv[1],"-d") == 0 ){
		
		delete_tel("data.txt",  argv[2]);
		
	}
	else if ( strcmp(argv[1],"-l") == 0 ){
		print_list("data.txt");
		
	}
	else {
		search_tel("data.txt", argv[1]);
	}
	}

	return 0;
		
}
void search_tel(const char *filename,  char *contents)
{
        FILE *file = fopen(filename, "r");
        int i = 0;

        if ( file == NULL ){
                printf("파일을 열 수 없습니다.\n");
             	return ;
        }
	
	struct TelBook book;
        char line[1000];
        while (fgets(line, sizeof(line), file)) {
                strcpy(book.name, strtok(line, ":"));
                strcpy(book.phone , strtok(NULL, ":"));
        	strcpy(book.memo, strtok(NULL,":"));	


                if (strstr(book.name, contents) != NULL || strstr(book.phone, contents) != NULL || strstr(book.memo, contents) != NULL) {

                printf("%d %s %s %s", i+1, book.name, book.phone, book.memo);		
		i++;
                }

        }

        fclose(file);
        
	if( i > 0)
                printf("match found.\n");
        else
                printf("no match found.\n");
}

void add_tel(const char *filename, struct TelBook *book)
{
        FILE *file = fopen(filename, "a");
        if (file == NULL) {
                printf("파일을 열 수 없습니다.\n");
                return ;
        }

        fprintf(file, "%s:%s:%s\n", book->name, book->phone, book->memo);

        fclose(file);
}

void delete_tel(const char *filename, const char *contents) {
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
                printf("파일을 열 수 없습니다.\n");
                return ;
        }

        char line[1000];
        char tempFilename[] = "temp.txt";
        FILE *tempFile = fopen(tempFilename, "w");

        int i= 0,j = 0;
        struct TelBook book;
	struct TelBook rm[100];
        while(fgets(line, sizeof(line), file)){
                strcpy(book.name,strtok(line, ":"));
                strcpy(book.phone , strtok(NULL, ":"));
                strcpy(book.memo , strtok(NULL, ":"));

                if(strstr(book.name, contents) != NULL || strstr(book.phone, contents) != NULL || strstr(book.memo, contents) != NULL) {


                printf("%d %s %s %s\n", i + 1, book.name, book.phone, book.memo);
                rm[i] = book;

                i++;
                }
                else
                        fprintf(tempFile, "%s:%s:%s\n", book.name, book.phone, book.memo);

        }
	int k;
        printf("which one? : ");
        scanf("%d", &k);

        while( i > 0)
	{
		if( i == k )
		      ;
		else
			fprintf(tempFile, "%s:%s:%s\n", rm[i].name, rm[i].phone, rm[i].memo);
		--i;
	}	
      

        fclose(file);
        fclose(tempFile);

        remove(filename);
        rename(tempFilename, filename);


}

void print_list(const char *filename) {
        FILE *file = fopen(filename, "r");
        if ( file == NULL ) {
                printf("파일을 열 수 없습니다.\n");
                return ;
        }
        int i = 0;
        char line[100];
	struct TelBook book;
        while (fgets(line, sizeof(line), file)) {
                strcpy(book.name,strtok(line,":"));
                strcpy(book.phone,strtok(NULL,":"));
                strcpy(book.memo,strtok(NULL,":"));
                i++;
        }

        int numEntries = i;
        
        for (i = 0; i < numEntries; i++) {
        printf("%d %s %s %s\n", i + 1, book.name, book.phone, book.memo);
        }

    fclose(file);
}


