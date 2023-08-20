#include <stdio.h>
struct BOOK
{
    char title[30];
    char auth[30];
    char pub[30];
    int num;
    char borr;
};
char book_search(char* book_info, char* search, int* result);
int book_borrow(char* borr);
int book_return(char* borr);
char book_change(struct BOOK* book_list);
char book_default(char* book_list);
int main()
{
    struct BOOK book_list[100];
    int i, j, k, l, m, n;
    char a, search[100];
    m = 0;
    for (i = 100; i < 100; i++)
    {
        book_list[i].num = i + 1;
        book_default(book_list[i].title);
        book_default(book_list[i].auth);
        book_default(book_list[i].pub);
    }
    printf("도서관에 오신 것을 환영합니다. \n");
    for (;;)
    {
        printf("수행하실 작업을 선택해 주십시오. \n");
        printf(" 1.도서 검색 \n 2.도서 대여 \n 3.도서 반납 \n 4.도서 교체 \n 5.나가기 \n");
        scanf("%d", &i);
        if (i == 1)
        {
            for (;;)
            {
                printf("\n다음 중 어떤 항목으로 검색하시겠습니까? 단, 검색은 영문 대소문자를 구분합니다. 띄어쓰기는 '_'로 입력하십시오. \n");
                printf("1)제목\n2)저자\n3)출판사\n4)도서 번호\n");
                scanf("%d", &j);
                if (j == 1)
                {
                    printf("검색어를 입력해 주십시오. : ");
                    scanf("%s", &search);
                    printf("결과를 출력합니다. \n");
                    for (l = 0; l < 100; l++)
                    {
                        book_search(book_list[l].title, search, &m);
                        if (m == 1)
                        {
                            printf("제목 : %s\n 저자 : %s\n 출판사 : %s\n 도서번호 : %d\n", book_list[l].title, book_list[l].auth, book_list[l].pub, book_list[l].num);
                            printf("대출 가능 여부 : %c\n", book_list[l].borr);
                            m = 0;
                        }
                    }

                }
                else if (j == 2)
                {
                    printf("\n검색어를 입력해 주십시오. : ");
                    scanf("%s", &search);
                    printf("\n결과를 출력합니다.\n");
                    for (l = 0; l < 100; l++)
                    {
                        book_search(book_list[l].auth, search, &m);
                        if (m == 1)
                        {
                            printf("저자 : %s\n 제목 : %s\n 출판사 : %s\n 도서번호 : %d\n", book_list[l].auth, book_list[l].title, book_list[l].pub, book_list[l].num);
                            printf("대출 가능 여부 : %c\n", book_list[l].borr);
                            m = 0;
                        }
                    }
                }
                else if (j == 3)
                {
                    printf("\n검색어를 입력해 주십시오 : ");
                    scanf("%s", &search);
                    printf("\n결과를 출력합니다.\n");
                    for (l = 0; l < 100; l++)
                    {
                        book_search(book_list[l].pub, search, &m);
                        if (m == 1)
                        {
                            printf("출판사 : %s\n 제목 : %s\n 저자 : %s\n 도서번호 : %d\n", book_list[l].pub, book_list[l].title, book_list[l].auth, book_list[l].num);
                            printf("대출 가능 여부 : %c\n", book_list[l].borr);
                            m = 0;
                        }
                    }
                }
                else if (j == 4)
                {
                    printf("\n몇 번 도서를 검색하시겠습니까? : ");
                    scanf("%d", &k);
                    printf("도서 번호%d의 정보입니다. \n", book_list[k].num);
                    printf("제목 : %s\n 저자 : %s\n 출판사 : %s\n", book_list[k].title, book_list[k].auth, book_list[k].pub);
                }
                else
                {
                    printf("\n수행할 수 없는 작업입니다.\n");
                }
                printf("\n더 검색하시겠다면 목록에서 해당하는 숫자를, 그렇지 않다면 n을 눌러주세요. :");
                scanf("%c", &a);
                if (a == 'n')
                {
                    break;
                }
            }
        }
        else if (i == 2)
        {
            printf("\n대출할 도서의 번호를 입력해 주십시오. : ");
            scanf("%d", &k);
            book_borrow(&book_list[k].borr);
        }
        else if (i == 3)
        {
            printf("\n반납할 도서의 번호를 입력해 주십시오. : ");
            scanf("%d", &k);
            book_return(&book_list[k].borr);
        }
        else if (i == 4)
        {
            printf("\n변경할 도서의 번호를 선택해 주십시오. : ");
            scanf("%d", &n);
            book_list[n - 1].num = n;
            book_change(&book_list[n - 1]);
        }
        else if (j = 5) {
            printf("\n프로그램을 종료합니다. 감사합니다.\n");
            break;
        }
        else
        {
            printf("\n수행할 수 없는 작업입니다.\n");
        }
    }
    return 0;
}
char book_search(char* book_info, char* search, int* result)
{
    int i, j;
    char a;
    i = 0;
    j = 0;
    while (*search)
    {
        if (*search == *book_info)
        {
            book_info++;
            search++;
            i++;
            j++;
        }
        else
        {
            search = search - i;
            if (*book_info == '\0')
            {
                break;
            }
            else
            {
                book_info++;
                j++;
            }
            i = 0;
        }
    }
    if (*search == '\0')
    {
        *result = 1;
        search = search - i;
    }
    book_info = book_info - j;
    i = 0;
    j = 0;
    return  0;
}
int book_borrow(char* borr)
{
    if (*borr == 'y')
    {
        *borr = 'n';
        printf("도서가 대출되었습니다.\n");
    }
    else
    {
        printf("대출할 수 있는 도서가 아닙니다.\n");
    }
    return 0;
}
int book_return(char* borr)
{
    if (*borr == 'n')
    {
        *borr = 'y';
        printf("도서가 반납되었습니다.\n");
    }
    else
    {
        printf("반납할 수 있는 도서가 아닙니다.\n");
    }
    return 0;
}
char book_change(struct BOOK* book_list)
{
    int i;
    char b;
    printf("이전에 저장되어 있던 도서의 정보는 사라집니다. 계속하시겠습니까? y/n :");
    scanf("%c", &b);
    if (b == 'y')
    {
        printf("새로운 도서의 정보를 입력해 주십시오.\n");
        printf("제목 :");
        scanf("%s", &(*book_list).title);
        printf("저자 :");
        scanf("%s", &(*book_list).auth);
        printf("출판사 :");
        scanf("%s", &(*book_list).pub);
        (*book_list).borr = 'y';
    }
    else if (b == 'n')
    {
        printf("작업이 취소되었습니다.\n");
    }
    else
    {
        printf("잘못된 작업입니다. \n");
    }
    return 0;
}
char book_default(char* book_info)
{
    *book_info = '\0';
    return 0;
}