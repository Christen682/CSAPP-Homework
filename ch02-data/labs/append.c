#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

char *s_gets(char *st, int n);
void append(FILE *source, FILE *dest);

int main()
{
    FILE *fa, *fs;       // fa指向目标文件，fs指向源文件
    int files = 0;       // 追加的文件数
    char file_app[SLEN]; // 存储目标文件名
    char file_src[SLEN]; // 存储源文件名
    int ch;

    puts("Enter name of destination file:");
    s_gets(file_app, SLEN);
    if (!(fa = fopen(file_app, "a+")))
    {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE)) // 设置全缓冲
    {
        fprintf(stderr, "Can't create output buffer\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter name of source file (empty line to quit):");
    while (s_gets(file_src, SLEN) && file_src[0] != '\0')
    {
        if (strcmp(file_app, file_src) == 0) // 如果目标文件和源文件相同
            fputs("Can't append file to itself\n", stderr);
        else if (!(fs = fopen(file_src, "r")))
            fprintf(stderr, "Can't open file %s\n", file_src);
        else
        {
            if (!(setvbuf(fs, NULL, _IOFBF, BUFSIZE)))
                fputs("Can't create input buffer\n", stderr);

            append(fs, fa);
            if (!(ferror(fs)))
                fprintf(stderr, "Error in reading file %s\n", file_src);
            if (!(ferror(fa)))
                fprintf(stderr, "Error in writing file %s\n", file_app);

            fclose(fs);
            files++;
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit):");
        }
    }
    printf("Done. %d files appended.\n", files);
    printf("%s contents:\n", file_app);

    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);

    return 0;
}
// 把source文件的内容追加到dest文件中，末尾追加\0
void append(FILE *source, FILE *dest)
{
    static char temp[BUFSIZE];
    size_t bytes;

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}

// 从标准输入读取字符串，存储在st指向的数组中，最多读取n-1个字符
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}