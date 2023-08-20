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
    printf("�������� ���� ���� ȯ���մϴ�. \n");
    for (;;)
    {
        printf("�����Ͻ� �۾��� ������ �ֽʽÿ�. \n");
        printf(" 1.���� �˻� \n 2.���� �뿩 \n 3.���� �ݳ� \n 4.���� ��ü \n 5.������ \n");
        scanf("%d", &i);
        if (i == 1)
        {
            for (;;)
            {
                printf("\n���� �� � �׸����� �˻��Ͻðڽ��ϱ�? ��, �˻��� ���� ��ҹ��ڸ� �����մϴ�. ����� '_'�� �Է��Ͻʽÿ�. \n");
                printf("1)����\n2)����\n3)���ǻ�\n4)���� ��ȣ\n");
                scanf("%d", &j);
                if (j == 1)
                {
                    printf("�˻�� �Է��� �ֽʽÿ�. : ");
                    scanf("%s", &search);
                    printf("����� ����մϴ�. \n");
                    for (l = 0; l < 100; l++)
                    {
                        book_search(book_list[l].title, search, &m);
                        if (m == 1)
                        {
                            printf("���� : %s\n ���� : %s\n ���ǻ� : %s\n ������ȣ : %d\n", book_list[l].title, book_list[l].auth, book_list[l].pub, book_list[l].num);
                            printf("���� ���� ���� : %c\n", book_list[l].borr);
                            m = 0;
                        }
                    }

                }
                else if (j == 2)
                {
                    printf("\n�˻�� �Է��� �ֽʽÿ�. : ");
                    scanf("%s", &search);
                    printf("\n����� ����մϴ�.\n");
                    for (l = 0; l < 100; l++)
                    {
                        book_search(book_list[l].auth, search, &m);
                        if (m == 1)
                        {
                            printf("���� : %s\n ���� : %s\n ���ǻ� : %s\n ������ȣ : %d\n", book_list[l].auth, book_list[l].title, book_list[l].pub, book_list[l].num);
                            printf("���� ���� ���� : %c\n", book_list[l].borr);
                            m = 0;
                        }
                    }
                }
                else if (j == 3)
                {
                    printf("\n�˻�� �Է��� �ֽʽÿ� : ");
                    scanf("%s", &search);
                    printf("\n����� ����մϴ�.\n");
                    for (l = 0; l < 100; l++)
                    {
                        book_search(book_list[l].pub, search, &m);
                        if (m == 1)
                        {
                            printf("���ǻ� : %s\n ���� : %s\n ���� : %s\n ������ȣ : %d\n", book_list[l].pub, book_list[l].title, book_list[l].auth, book_list[l].num);
                            printf("���� ���� ���� : %c\n", book_list[l].borr);
                            m = 0;
                        }
                    }
                }
                else if (j == 4)
                {
                    printf("\n�� �� ������ �˻��Ͻðڽ��ϱ�? : ");
                    scanf("%d", &k);
                    printf("���� ��ȣ%d�� �����Դϴ�. \n", book_list[k].num);
                    printf("���� : %s\n ���� : %s\n ���ǻ� : %s\n", book_list[k].title, book_list[k].auth, book_list[k].pub);
                }
                else
                {
                    printf("\n������ �� ���� �۾��Դϴ�.\n");
                }
                printf("\n�� �˻��Ͻðڴٸ� ��Ͽ��� �ش��ϴ� ���ڸ�, �׷��� �ʴٸ� n�� �����ּ���. :");
                scanf("%c", &a);
                if (a == 'n')
                {
                    break;
                }
            }
        }
        else if (i == 2)
        {
            printf("\n������ ������ ��ȣ�� �Է��� �ֽʽÿ�. : ");
            scanf("%d", &k);
            book_borrow(&book_list[k].borr);
        }
        else if (i == 3)
        {
            printf("\n�ݳ��� ������ ��ȣ�� �Է��� �ֽʽÿ�. : ");
            scanf("%d", &k);
            book_return(&book_list[k].borr);
        }
        else if (i == 4)
        {
            printf("\n������ ������ ��ȣ�� ������ �ֽʽÿ�. : ");
            scanf("%d", &n);
            book_list[n - 1].num = n;
            book_change(&book_list[n - 1]);
        }
        else if (j = 5) {
            printf("\n���α׷��� �����մϴ�. �����մϴ�.\n");
            break;
        }
        else
        {
            printf("\n������ �� ���� �۾��Դϴ�.\n");
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
        printf("������ ����Ǿ����ϴ�.\n");
    }
    else
    {
        printf("������ �� �ִ� ������ �ƴմϴ�.\n");
    }
    return 0;
}
int book_return(char* borr)
{
    if (*borr == 'n')
    {
        *borr = 'y';
        printf("������ �ݳ��Ǿ����ϴ�.\n");
    }
    else
    {
        printf("�ݳ��� �� �ִ� ������ �ƴմϴ�.\n");
    }
    return 0;
}
char book_change(struct BOOK* book_list)
{
    int i;
    char b;
    printf("������ ����Ǿ� �ִ� ������ ������ ������ϴ�. ����Ͻðڽ��ϱ�? y/n :");
    scanf("%c", &b);
    if (b == 'y')
    {
        printf("���ο� ������ ������ �Է��� �ֽʽÿ�.\n");
        printf("���� :");
        scanf("%s", &(*book_list).title);
        printf("���� :");
        scanf("%s", &(*book_list).auth);
        printf("���ǻ� :");
        scanf("%s", &(*book_list).pub);
        (*book_list).borr = 'y';
    }
    else if (b == 'n')
    {
        printf("�۾��� ��ҵǾ����ϴ�.\n");
    }
    else
    {
        printf("�߸��� �۾��Դϴ�. \n");
    }
    return 0;
}
char book_default(char* book_info)
{
    *book_info = '\0';
    return 0;
}