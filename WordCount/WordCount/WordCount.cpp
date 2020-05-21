
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 20
void countWord(char* a);
void countChar(char* a);
int main(int argc, char* argv[])
{
   
    char* cc = argv[1];
    if (argc != 3) {
        printf("未找到输入命令01");
        return -1;
    }
    if (cc[1] == 'w') { countWord(argv[2]); }
    else if (cc[1] == 'c') { countChar(argv[2]); }
    else {
        printf("未找到输入命令02");
        return -1;
    }
}
void countWord(char* a) {
    int len = 0;
    int num = 0;
    int total = 0;
    int i = 0;
    char c;
    int lastBlack = 0;
    char buf[MAX_NUM];
    FILE* file = fopen(a, "rb");
    if (file == NULL)
    {
        printf("文件打开失败!\n");

    }
    while (fgets(buf, MAX_NUM, file) != NULL) {

        len = strlen(buf);
        for (i = 0; i < len; i++) {
            c = buf[i];
            if (c == ' ' || c == '\n') {
                if (lastBlack == 0) {
                    num++;
                    lastBlack = 1;
                }
            }
            else if (c != '\n' && c != ' ') { lastBlack = 0; }
        }
        !lastBlack && num++;
        lastBlack = 1;
        total += num;
        num = 0;
    }
    printf("单词数：%d", total);
    fclose(file);				//关闭文件
    getchar();


}
void countChar(char* a) {
    int len = 0;
    int num = 0;
    char buf[MAX_NUM];
    char ch;
    FILE* file = fopen(a, "rb");
    if (file == NULL)
    {
        printf("文件打开失败!\n");

    }
    ch = fgetc(file);
    while (fgets(buf, MAX_NUM, file) != NULL) {

        len = strlen(buf);
        num += len;
    }
    printf("字符数：%d", num);
    fclose(file);				//关闭文件
    getchar();

}

