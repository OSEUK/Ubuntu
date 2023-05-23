#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TelBook {
	char name[30];
	char phone[20];
	char memo[40];
};

void search_tel(const char *filename,  char *contents);
void add_tel(const char *filename, struct TelBook *book);
void delete_tel(const char *filename, struct TelBook *book, const char *contents);
void print_list(const char *filename, struct TelBook *book);

int main(int argc, char *argv[])
{	
	struct TelBook *book;
	char choice;
	

	if (argc < 2){
		printf("전화번호부 관리 프로그램입니다.\n");
		printf("찾기 : $tel (contents)으로 일치하는 요소를 찾아줍니다.\n");
		printf("추가 : $tel -a (contents)으로 전화번호부에 추가합니다.\n");
		printf("삭제 : $tel -d (name)으로 전화번호부에서 삭제합니다.\n");
		printf("리스트 : $tel -l 이름 순으로 정렬하여 전화번호부 전체를 출력합니다.\n");
	}
	else if ( strcmp(argv[1],"-a") == 0 ){
		struct TelBook *book = malloc(sizeof(struct TelBook));

		strcpy(book->name, argv[2]);
		strcpy(book->phone, argv[3]);
		strcpy(book->memo, argv[4]);
		
		printf("add? [Y/N]: ");
		scanf("%c", &choice);\
		
		if(choice == 'Y')
			add_tel("data.txt", book);
		return 0;

	}
	else if ( strcmp(argv[1],"-d") == 0 ){
		
		delete_tel("data.txt", book, argv[2]);
		return 0;
	}
	else if ( strcmp(argv[1],"-l") == 0 ){
		print_list("data.txt", book);
		return 0;
	}
	else {
		search_tel("data.txt", argv[2]);
		return 0;
	}

	return 0;
		
}
void search_tel(const char *filename, char *contents)
{
        FILE *file = fopen(filename, "r");
        int i = 0;
        if ( file == NULL ){
                printf("파일을 열 수 없습니다.\n");
             	return ;
        }

        char line[1000];
        while (fgets(line, sizeof(line), file)) {
                char name[30], phone[20], memo[40];
                sscanf(line, "%[^:]:%[^:]:%[^\n]", name, phone, memo);

                if (strstr(name, contents) != NULL || strstr(phone, contents) != NULL || strstr(memo, contents) != NULL) {

                printf("%d %s %s %s\n", i+1, name, phone, memo);
		i++;
                }

        }
        fclose(file);
        if( i > 0)
                printf("match found.");
        else
                printf("no match found.");

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

void delete_tel(const char *filename,struct TelBook *book, const char *contents) {
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
                printf("파일을 열 수 없습니다.\n");
                return ;
        }

        char line[100];
        char tempFilename[] = "temp.txt";
        FILE *tempFile = fopen(tempFilename, "w");

        int i= 0,j = 0;
        char *dnode[100];
        while(fgets(line, sizeof(line), file)){
                strcpy(book[i].name,strtok(line, ":"));
                strcpy(book[i].phone , strtok(NULL, ":"));
                strcpy(book[i].memo , strtok(NULL, ":"));

                if(strstr(book[i].name, contents) != NULL || strstr(book[i].phone, contents) != NULL || strstr(book[i].memo, contents) != NULL) {


                printf("%d %s %s %s\n", ++j, book[i].name, book[i].phone, book[i].memo);
                strcpy(dnode[j-1],line );

                i++;
                }
                else
                        fputs(line, tempFile);

        }
	int k;
        printf("which one? : ");
        scanf("%d", &k);

        int s = 0;
        while (dnode[s] != NULL){
                if( s == (k-1))
                continue;
                fputs(dnode[s], tempFile);

                s++;
        }

        fclose(file);
        fclose(tempFile);

        remove(filename);
        rename(tempFilename, filename);


}

int compare_names(const void *a, const void *b) {
    const struct TelBook *entry_a = (const struct TelBook *)a;
    const struct TelBook *entry_b = (const struct TelBook *)b;
    return strcmp(entry_a->name, entry_b->name);
}

void print_list(const char *filename, struct TelBook *book) {
        FILE *file = fopen(filename, "r");
        if ( file == NULL ) {
                printf("파일을 열 수 없습니다.\n");
                return ;
        }
        int i = 0;
        char line[100];
        while (fgets(line, sizeof(line), file)) {
                strcpy(book[i].name,strtok(line,":"));
                strcpy(book[i].phone,strtok(NULL,":"));
                strcpy(book[i].memo,strtok(NULL,":"));
                i++;
        }

        int numEntries = i;
        qsort(book, numEntries, sizeof(struct TelBook), compare_names);

        for (i = 0; i < numEntries; i++) {
        printf("%d %s %s %s\n", i + 1, book[i].name, book[i].phone, book[i].memo);
        }

    fclose(file);
}


