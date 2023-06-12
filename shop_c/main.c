#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    struct Node* next;
    int code;
    int quantity;
    char* name;
    float price;
    char* recDate;
    char* expDate;

}Node;
typedef struct List{
    Node* head;
}List;
Node* createProduct(int code,char* name,float price, int quantity, char* recDate,char* expDate)
{
    Node* n=(Node*)malloc(sizeof (Node));
    n->code=code;
    n->name= malloc(sizeof (name));
    strcpy(n->name,name);
    n->price=price;
    n->quantity=quantity;
    n->recDate= malloc(sizeof (recDate));
    strcpy(n->recDate,recDate);
    n->expDate= malloc(sizeof (expDate));
    strcpy(n->expDate,expDate);
    return n;
}
void appendSorted(List *l,Node* n)
{
    if(l->head!=NULL)
    {Node *tmp = l->head;
        while(tmp->next!=NULL)
            tmp=tmp->next;
        n->next=tmp->next;
        tmp->next=n;
    }
    else
    {   n->next=l->head;
        l->head=n;

    }
}
void print(List l)
{
    Node *n=l.head;
    while(n!=NULL)
    {
        printf("%d %s %.1f %d %s %s\n",n->code,n->name,n->price,n->quantity,n->recDate,n->expDate);
        n=n->next;
    }
}
Node* findByCode(List l,int product_code)
{
    Node* aux=(Node*) malloc(sizeof (Node));
    aux=l.head;
    while (aux!=NULL)
    {
        if(aux->code==product_code)
            return aux;
        aux=aux->next;
    }
    printf("Product code does not exist!");
    return NULL;
}
void printExpired(List l,char *date)
{
    Node* n=l.head;
    char* string_product_year=(char*) malloc(sizeof (char)*5);
    char* string_product_month=(char *) malloc(sizeof(char)*3);
    char* string_product_day=(char *) malloc(sizeof (char )*3);
    char* string_given_year=(char *) malloc(sizeof(char)*5);
    char* string_given_month=(char *) malloc(sizeof(char)*3 );
    char* string_given_day=(char *) malloc(sizeof (char )*3);
    int num_product_year,num_product_month,num_product_day,num_given_year,num_given_month,num_given_day;
    while (n!=NULL)
    {
        if(strcmp((n->expDate),date)!=0) {
            strncpy(string_product_year, (n->expDate) + 6, strlen(n->expDate));
            strncpy(string_product_month, (n->expDate) + 3, strlen(n->expDate) - 8);
            string_product_month[2] = '\0';
            strncpy(string_product_day, (n->expDate), strlen(n->expDate) - 8);
            string_product_day[2] = '\0';
            strncpy(string_given_year, date + 6, strlen(date));
            strncpy(string_given_month, date + 3, strlen(date) - 8);
            string_given_month[2] = '\0';
            strncpy(string_given_day, date, strlen(date) - 8);
            string_given_day[2] = '\0';
            num_product_year= atoi(string_product_year);
            num_product_month= atoi(string_product_month);
            num_product_day= atoi(string_product_day);
            num_given_year= atoi(string_given_year);
            num_given_month= atoi(string_given_month);
            num_given_day= atoi(string_given_day);

            if(num_given_year>num_product_year)
                printf("%d %s %.1f %d %s %s\n",n->code,n->name,n->price,n->quantity,n->recDate,n->expDate);
            else {
                if (num_given_year < num_product_year)
                    ;
                else
                    if(num_given_year == num_product_year)
                    {
                        if(num_given_month>num_product_month)
                            printf("%d %s %.1f %d %s %s\n",n->code,n->name,n->price,n->quantity,n->recDate,n->expDate);
                        else {
                            if (num_given_month<num_product_month)
                                ;
                            else
                                if(num_given_month==num_product_month)
                                {
                                    if(num_given_day>num_product_day)
                                        printf("%d %s %.1f %d %s %s\n",n->code,n->name,n->price,n->quantity,n->recDate,n->expDate);
                                    else
                                        if(num_given_day<num_product_day)
                                            ;

                                }
                        }
                        }
            }
            }

        n=n->next;
    }

    }
void printValid(List l,char *date)
{
    Node* n=l.head;
    char* string_product_year=(char*) malloc(sizeof (char)*5);
    char* string_product_month=(char *) malloc(sizeof(char)*3);
    char* string_product_day=(char *) malloc(sizeof (char )*3);
    char* string_given_year=(char *) malloc(sizeof(char)*5);
    char* string_given_month=(char *) malloc(sizeof(char)*3 );
    char* string_given_day=(char *) malloc(sizeof (char )*3);
    int num_product_year,num_product_month,num_product_day,num_given_year,num_given_month,num_given_day;
    while (n!=NULL)
    {
        if(strcmp((n->expDate),date)!=0) {
            strncpy(string_product_year, (n->expDate) + 6, strlen(n->expDate));
            strncpy(string_product_month, (n->expDate) + 3, strlen(n->expDate) - 8);
            string_product_month[2] = '\0';
            strncpy(string_product_day, (n->expDate), strlen(n->expDate) - 8);
            string_product_day[2] = '\0';
            strncpy(string_given_year, date + 6, strlen(date));
            strncpy(string_given_month, date + 3, strlen(date) - 8);
            string_given_month[2] = '\0';
            strncpy(string_given_day, date, strlen(date) - 8);
            string_given_day[2] = '\0';
            num_product_year= atoi(string_product_year);
            num_product_month= atoi(string_product_month);
            num_product_day= atoi(string_product_day);
            num_given_year= atoi(string_given_year);
            num_given_month= atoi(string_given_month);
            num_given_day= atoi(string_given_day);

            if(num_given_year<num_product_year)
                printf("%d %s %.1f %d %s %s\n",n->code,n->name,n->price,n->quantity,n->recDate,n->expDate);
            else {
                if (num_given_year > num_product_year)
                    ;
                else
                if(num_given_year == num_product_year)
                {
                    if(num_given_month>num_product_month)
                        printf("%d %s %.1f %d %s %s\n",n->code,n->name,n->price,n->quantity,n->recDate,n->expDate);
                    else {
                        if (num_given_month>num_product_month)
                            ;
                        else
                        if(num_given_month==num_product_month)
                        {
                            if(num_given_day<num_product_day)
                                printf("%d %s %.1f %d %s %s\n",n->code,n->name,n->price,n->quantity,n->recDate,n->expDate);
                            else
                            if(num_given_day>num_product_day)
                                ;

                        }
                    }
                }
            }
        }

        n=n->next;
    }
     }
void deleteByCode(List *l,int code_given){
    if(l->head->code==code_given)
    {
        Node* aux=l->head;
        l->head=aux->next;
        aux->next=NULL;
        free(aux);
    }
    else
    {
        Node* aux=l->head;
        while (aux->next->code!=code_given && aux->next!=NULL)
        {
            aux=aux->next;
        }
        if(aux->next!=NULL) {
            Node *tmp =aux->next;
            aux->next = tmp->next;
            tmp->next = NULL;
            free(tmp);
        } else
            printf("Nu exista codul!");
        }

}
void deleteExpired(List *l,char *date)
{
    Node* n=l->head;
    int i=0;
    int* codes=(int*) malloc(sizeof(*l));
    char* string_product_year=(char*) malloc(sizeof (char)*5);
    char* string_product_month=(char *) malloc(sizeof(char)*3);
    char* string_product_day=(char *) malloc(sizeof (char )*3);
    char* string_given_year=(char *) malloc(sizeof(char)*5);
    char* string_given_month=(char *) malloc(sizeof(char)*3 );
    char* string_given_day=(char *) malloc(sizeof (char )*3);
    int num_product_year,num_product_month,num_product_day,num_given_year,num_given_month,num_given_day;
    while (n!=NULL)
    {
        if(strcmp((n->expDate),date)!=0) {
            strncpy(string_product_year, (n->expDate) + 6, strlen(n->expDate));
            strncpy(string_product_month, (n->expDate) + 3, strlen(n->expDate) - 8);
            string_product_month[2] = '\0';
            strncpy(string_product_day, (n->expDate), strlen(n->expDate) - 8);
            string_product_day[2] = '\0';
            strncpy(string_given_year, date + 6, strlen(date));
            strncpy(string_given_month, date + 3, strlen(date) - 8);
            string_given_month[2] = '\0';
            strncpy(string_given_day, date, strlen(date) - 8);
            string_given_day[2] = '\0';
            num_product_year= atoi(string_product_year);
            num_product_month= atoi(string_product_month);
            num_product_day= atoi(string_product_day);
            num_given_year= atoi(string_given_year);
            num_given_month= atoi(string_given_month);
            num_given_day= atoi(string_given_day);

            if(num_given_year>num_product_year)
            {
                codes[i]=n->code;
                i++;
            }
            else {
                if (num_given_year < num_product_year)
                    ;
                else
                if(num_given_year == num_product_year)
                {
                    if(num_given_month>num_product_month)
                    {  codes[i]=n->code;
                        i++;
                    }
                    else {
                        if (num_given_month<num_product_month)
                            ;
                        else
                        if(num_given_month==num_product_month)
                        {
                            if(num_given_day>num_product_day)
                            {
                                codes[i]=n->code;
                                i++;
                            }
                            else
                            if(num_given_day<num_product_day)
                                ;

                        }
                    }
                }
            }
        }

        n=n->next;
    }
        int j;
    for(j=0;j<i;j++)
        deleteByCode(l,codes[j]);
    free(codes);
}
int main(){
    int n, code, quantity;
    float price;
    char name[50], recDate[50], expDate[50];
    scanf("%d", &n);
    List l;
    l.head = NULL;
    while(n){
        scanf("%d", &code);
        scanf("%s", name);
        scanf("%f", &price);
        scanf("%d", &quantity);
        scanf("%s", recDate);
        scanf("%s", expDate);
        appendSorted(&l, createProduct(code, name, price, quantity, recDate, expDate));
        n--;
    }
    printf("test 1\n");
    print(l);

    printf("test 2\n");
    Node *p = findByCode(l, 102);
    strcpy(p->name, "Poiana");
    print(l);

    printf("test 3\n");
    printValid(l, "20/03/2020");

    printf("test 4\n");
    printExpired(l, "20/03/2020");

    printf("test 5\n");
    deleteByCode(&l, 104);
    print(l);

    printf("test 6\n");
    deleteExpired(&l, "20/03/2020");
    print(l);

    return 0;
}