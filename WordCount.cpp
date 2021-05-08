#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char c;
int len=0;
char buffer[5000];

int CountW(char* file)//返回文件词的数目 
{
    FILE* fp;
    int Words = 0;
    if ((fp = fopen(file, "r")) == NULL)
    {
        printf("Failure to open it\n");
        exit(0);
    }
    while(fgets(buffer, 1000, fp) != NULL)
    {
        len = strlen(buffer);
        for (int i = 0; i < len; i++)
        {
            c = buffer[i];
            if (c == ' ' || c == ',')
            {
                Words++;	 
            }
        }
        Words=Words+1;
        fclose(fp);
        printf("WordNum：%d\n", Words);
    }
}
int CountC(char* file) //返回文件的字符数 
{
    FILE* fp;
    int Chars = 0;
    fp = fopen(file, "r");
    char a;
    if ((fp = fopen(file, "r")) == NULL)
    {
        printf("Faliure to open it\n");
        exit(0);
    }
    while(fgets(buffer, 1000, fp) != NULL){
    	len = strlen(buffer);
    	
        for (int i = 0; i < len; i++){
        	c = buffer[i];
            Chars++;	    
		}
	}

    fclose(fp);
    printf("CharNum:%d ", Chars-1);
}

int main(int argc, char* argv[])
{
    FILE* fp;
    while (1)
    {
        if ((fp = fopen(argv[2], "r")) == NULL)
        {
            printf("Faliure to open it\n");
            scanf("%s%s%s", argv[0], argv[1], argv[2]);
            continue;
        }
        else if (!strcmp(argv[1], "-w"))
        {
            CountW(argv[2]);
        }
        else if (!strcmp(argv[1], "-c"))
        {
            CountC(argv[2]);
        }
        scanf("%s%s%s", argv[0], argv[1], argv[2]);
    }
    return 0;
}
