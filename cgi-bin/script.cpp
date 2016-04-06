#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void UrlDecode(char *st) {
    char *p=st;
    char hex[3];
    int code;
    do{
        if(*st == '%'){
            hex[0]=*(++st); hex[1]=*(++st); hex[2]=0;
            sscanf(hex, "%X", &code);
            *p++=(char)code;
        } else if(*st=='+') *p++=' ';
        else *p++=*st;
    }while(*st++!=0);
}

int main() {
    setlocale(LC_ALL, "Russian");
    char *RemoteAddr = getenv("REMOTE_ADDR");
    char *ContentLength = getenv("CONTENT_LENGTH");
    char *QueryString = (char*)malloc(strlen(getenv("QUERY_STRING")) + 1);
    strcpy(QueryString, getenv("QUERY_STRING"));
    UrlDecode(QueryString);
    int NumBytes = atoi(ContentLength);
    char *Data = (char*)malloc(NumBytes + 1);
    fread(Data, 1, NumBytes, stdin);
    Data[NumBytes] = 0;
    UrlDecode(Data);
    printf("Content-type: text/html\n\n");
    printf("<html><body>");
    printf("<h1>Здрасте! Мы знаем о вас все!</h1>");
    printf("Ваш IP: %s<br>", RemoteAddr);
    printf("Количество байтов данных: %s<br>", NumBytes);
    printf("Указанные параметры: %s", Data);
    printf("Вот что мы получили через URL: %s", QueryString);
    printf("</body></html>");
 }
//    char *RemoteAddr = getenv("REMOTE_ADDR");
//    char *QueryString = getenv("QUERY_STRING");
//
//    printf("Content-type: text/html\n\n");
//    printf("<html><body>");
//    printf("<h1>Здрасте! Мы знаем о вас все!</h1>");
//    printf("Ваш IP: %s<br>", RemoteAddr);
//    printf("Указанные параметры: %s", QueryString);
//    printf("</body></html>");


