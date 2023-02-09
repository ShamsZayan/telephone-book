#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int day;
    int month;
    int year;
} DOB;
typedef struct

{
    char last[50];
    char first[50];
    DOB birth;
    char adress[100];
    char phone[12];
    char email[100];
} contact;

contact s[100];
int count=0,n=0,m=0;
void load()
{
    int i=0;
    FILE *f=fopen("phonebook.txt","r");
    if (f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%[^,],",s[i].last);
            fscanf(f,"%[^,],",s[i].first);
            fscanf(f,"%d-%d-%d,",&s[i].birth.day,&s[i].birth.month,&s[i].birth.year);
            fscanf(f,"%[^,],",s[i].adress);
            fscanf(f,"%[^,],",s[i].phone);
            fscanf(f,"%s\n",s[i].email);
            i++;
            count++;
        }
    }
    else
        printf("error!");
    fclose(f);
}

void SortByLname()
{
    int i,pass;
    contact temp;
    for(pass=1; pass<count; pass++)
    {
        for(i=0; i<count-pass; i++)
        {
            if (strcasecmp(s[i].last,s[i+1].last)==1)
            {
                temp=s[i];
                s[i]=s[i+1];
                s[i+1]=temp;
            }
        }
    }
    for(i=0; i<count; i++)
    {
        printf("%s,",s[i].last);
        printf("%s,",s[i].first);
        printf("%d-%d-%d,",s[i].birth.day,s[i].birth.month,s[i].birth.year);
        printf("%s,",s[i].adress);
        printf("%s,",s[i].phone);
        printf("%s\n",s[i].email);
    }
}
void SortByDOB()
{
    int i;
    contact temp;
    int pass;

    for(pass=1; pass<count; pass++)
    {
        for(i=0; i<count-pass; i++)
        {
            if(s[i].birth.year>s[i+1].birth.year)
            {
                temp=s[i];
                s[i]=s[i+1];
                s[i+1]=temp;
            }
            else if(s[i].birth.year==s[i+1].birth.year)
            {
                if(s[i].birth.month>s[i+1].birth.month)
                {
                    temp=s[i];
                    s[i]=s[i+1];
                    s[i+1]=temp;
                }
                else if(s[i].birth.month==s[i+1].birth.month)
                {
                    if(s[i].birth.day>s[i+1].birth.day)
                    {
                        temp=s[i];
                        s[i]=s[i+1];
                        s[i+1]=temp;
                    }
                }
            }
        }
    }
    for(i=0; i<count; i++)
    {
        printf("%s,",s[i].last);
        printf("%s,",s[i].first);
        printf("%d-%d-%d,",s[i].birth.day,s[i].birth.month,s[i].birth.year);
        printf("%s,",s[i].adress);
        printf("%s,",s[i].phone);
        printf("%s\n",s[i].email);
    }
}


void search()
{
    int i,check=0;
    char c[50];
    do
    {
        printf("enter last name:  ");
        scanf("%s",c);
        for(i=0; i<count+n; i++)
        {
            if(strcasecmp(s[i].last,c)==0)
            {
                printf("%s,",s[i].last);
                printf("%s,",s[i].first);
                printf("%d-%d-%d,",s[i].birth.day,s[i].birth.month,s[i].birth.year);
                printf("%s,",s[i].adress);
                printf("%s,",s[i].phone);
                printf("%s\n",s[i].email);
                check=1;
            }
        }
        if(check==0)
            printf("searching about an entry that is not in the file\n try again\n");
    }
    while(check==0);


}
void Add()
{

    int i,h,j;
    printf("Enter number of contacts that will be added: ");
    scanf("%d",&n);
    for(i=count; i<count+n; i++)
    {
        printf("last name: ");
        scanf("%s",s[i].last);
        printf("first name: ");
        scanf("%s",s[i].first);
        printf("date of birth: day month year:\n ");
        scanf("%d %d %d",&s[i].birth.day,&s[i].birth.month,&s[i].birth.year);
        while(s[i].birth.month>12||s[i].birth.month<1)
        {
            printf("enter month again: ");
            scanf("%d",&s[i].birth.month);
        }

        if(s[i].birth.month==1||s[i].birth.month==3||s[i].birth.month==1||s[i].birth.month==5||s[i].birth.month==8||s[i].birth.month==10||s[i].birth.month==12||s[i].birth.month==7)
        {
            while(s[i].birth.day>31||s[i].birth.day<1)
            {
                printf("enter day again: ");
                scanf("%d",&s[i].birth.day);
            }
        }
        else  if(s[i].birth.month==4||s[i].birth.month==6||s[i].birth.month==9||s[i].birth.month==11)
        {
            while(s[i].birth.day>30||s[i].birth.day<1)
            {
                printf("enter day again: ");
                scanf("%d",&s[i].birth.day);
            }
        }
        else if(s[i].birth.month==2)
        {
            while(s[i].birth.day>29||s[i].birth.day<1)
            {
                printf("enter day again: ");
                scanf("%d",&s[i].birth.day);
            }

        }
        while(s[i].birth.year>2021||s[i].birth.year<1)
        {
            printf("enter year again: ");
            scanf("%d",&s[i].birth.year);
        }

        printf("address : ");
        getchar();
        fgets(s[i].adress,sizeof(s[i].adress),stdin);
        printf("phone number: ");
        scanf("%s",s[i].phone);
        int j=strlen(s[i].phone);
        while(j>11||j<11||(s[i].phone[0]!='0'&&s[i].phone[1]!='1'))
        {
            printf("enter number again: ");
            scanf("%s",s[i].phone);
            j=strlen(s[i].phone);
        }
        do
        {
            h=0;
            printf("Email : ");
            scanf("%s",s[i].email);
            for(j=0; j<strlen(s[i].email)+1; j++)
                if(s[i].email[j]=='@')
                    h++;
            if(s[i].email[strlen(s[i].email)-1]!='m'||s[i].email[strlen(s[i].email)-2]!='o'||s[i].email[strlen(s[i].email)-3]!='c'||s[i].email[strlen(s[i].email)-4]!='.'||s[i].email[strlen(s[i].email)-5]=='@'||h!=1)
                printf("enter email again: \n");
        }
        while(s[i].email[strlen(s[i].email)-1]!='m'||s[i].email[strlen(s[i].email)-2]!='o'||s[i].email[strlen(s[i].email)-3]!='c'||s[i].email[strlen(s[i].email)-4]!='.'||s[i].email[strlen(s[i].email)-5]=='@'||h!=1);
    }


}
void save()
{
    int i;
    FILE *f=fopen("phonebook.txt","w");
    if (f!=NULL)
    {
        for(i=0; i<count+n; i++)
        {
            fprintf(f,"%s,",s[i].last);
            fprintf(f,"%s,",s[i].first);
            fprintf(f,"%d-%d-%d,",s[i].birth.day,s[i].birth.month,s[i].birth.year);
            fprintf(f,"%s,",s[i].adress);
            fprintf(f,"%s,",s[i].phone);
            fprintf(f,"%s\n",s[i].email);

        }
    }
    else
        printf("error!");
    fclose(f);

}
void print()
{
    int x,check=0;
    do
    {
        printf("1-sort by date of birth\n2-sort by last name \n");
        scanf("%d",&x);
        if(x==1)
        {
            SortByDOB();
            check=1;
        }

        else if(x==2)
        {
            SortByLname();
            check=1;
        }

        if(check==0)
            printf("you entered wrong number\n try again\n");
    }
    while(check==0);
}
void Delete()
{
    int i,check=0;
    char l[50],f[50];
    do
    {
        printf("enter last and first name: ");
        scanf("%s %s",l,f);
        for(i=0; i<count+n; i++)
        {
            if(strcasecmp(l,s[i].last)==0&&strcasecmp(f,s[i].first)==0)
            {
                while(i<count+n)
                {
                    s[i]=s[i+1];
                    i++;
                }
                count--;
                check=1;
            }
        }
        if(check==0)
            printf("trying to delete an entry that is not in the file\n try again\n");
    }
    while(check==0);

}

void Modify()
{
    int i,h,j,w,k=0,number,check1=0,check2=0,check3=0;
    char LN[30];
    char a[count][30];
    do
    {
        printf("enter the last name: ");
        scanf("%s",LN);
        for(i=0; i<count+n; i++)
        {
            if(strcasecmp(s[i].last,LN)==0)
            {
                printf("%d-%s %s\n",k+1,s[i].first,s[i].last);
                strcpy(a[k],s[i].first);
                k++;
                check1=1;
            }
        }
        if(check1==0)
            printf("trying to modify an entry that is not in the file\n try again\n");
    }
    while(check1==0);
    do
    {
        printf("please choose number from 1 to %d: \n",k);
        scanf("%d",&number);
        for(j=0; j<k; j++)
        {
            if(j+1==number)
            {
                check2=1;
                for(i=0; i<count+n; i++)
                {
                    if(strcasecmp(s[i].first,a[j])==0)
                    {
                        do
                        {
                            printf("what you want to modify?\n1.last name\n2.fist name\n3.birth of date\n4.address\n5.phone number\n6.email\n");
                            printf("enter a number: ");
                            scanf("%d",&w);
                            if(w==1)
                            {
                                printf("enter new last name: ");
                                scanf("%s",s[i].last);
                                check3=1;
                            }
                            else if(w==2)
                            {
                                printf("enter new fist name: ");
                                scanf("%s",s[i].first);
                                check3=1;
                            }
                            else if(w==3)
                            {
                                printf("enter new date of birth: day month year ");
                                scanf("%d %d %d",&s[i].birth.day,&s[i].birth.month,&s[i].birth.year);

                                while(s[i].birth.month>12||s[i].birth.month<1)
                                {
                                    printf("enter month again");
                                    scanf("%d",&s[i].birth.month);
                                }
                                if(s[i].birth.month==1||s[i].birth.month==3||s[i].birth.month==1||s[i].birth.month==5||s[i].birth.month==8||s[i].birth.month==10||s[i].birth.month==12||s[i].birth.month==7)
                                {
                                    while(s[i].birth.day>31||s[i].birth.day<1)
                                    {
                                        printf("enter day again: ");
                                        scanf("%d",&s[i].birth.day);
                                    }
                                }
                                else  if(s[i].birth.month==4||s[i].birth.month==6||s[i].birth.month==9||s[i].birth.month==11)
                                {
                                    while(s[i].birth.day>30||s[i].birth.day<1)
                                    {
                                        printf("enter day again: ");
                                        scanf("%d",&s[i].birth.day);
                                    }
                                }
                                else if(s[i].birth.month==2)
                                {
                                    while(s[i].birth.day>29||s[i].birth.day<1)
                                    {
                                        printf("enter day again: ");
                                        scanf("%d",&s[i].birth.day);
                                    }

                                }
                                while(s[i].birth.year>2021||s[i].birth.year<1)
                                {
                                    printf("enter year again");
                                    scanf("%d",&s[i].birth.year);
                                }
                                check3=1;
                            }
                            else if(w==4)
                            {
                                printf("enter new address: ");
                                getchar();
                                fgets(s[i].adress,sizeof(s[i].adress),stdin);
                                check3=1;
                            }
                            else if(w==5)
                            {
                                printf("enter new phone number: ");
                                scanf("%s",s[i].phone);

                                int j=strlen(s[i].phone);
                                while(j>11||j<11||(s[i].phone[0]!='0'&&s[i].phone[1]!='1'))
                                {
                                    printf("enter number again: ");
                                    scanf("%s",s[i].phone);
                                    j=strlen(s[i].phone);
                                }
                                check3=1;
                            }
                            else if(w==6)
                            {
                                do
                                {
                                    h=0;
                                    printf("Email : ");
                                    scanf("%s",s[i].email);
                                    for(j=0; j<strlen(s[i].email)+1; j++)
                                        if(s[i].email[j]=='@')
                                            h++;
                                    if(s[i].email[strlen(s[i].email)-1]!='m'||s[i].email[strlen(s[i].email)-2]!='o'||s[i].email[strlen(s[i].email)-3]!='c'||s[i].email[strlen(s[i].email)-4]!='.'||s[i].email[strlen(s[i].email)-5]=='@'||h!=1)
                                        printf("enter email again: \n");
                                }
                                while(s[i].email[strlen(s[i].email)-1]!='m'||s[i].email[strlen(s[i].email)-2]!='o'||s[i].email[strlen(s[i].email)-3]!='c'||s[i].email[strlen(s[i].email)-4]!='.'||s[i].email[strlen(s[i].email)-5]=='@'||h!=1);
                                check3=1;
                            }

                            if(check3==0)
                                printf("enter number again\n try again\n");
                        }
                        while(check3==0);
                    }

                }

            }

        }
        if(check2==0)
            printf("enter number again\n try again\n");
    }
    while(check2==0);
}
void Quit()
{
    if(m==0)
        printf("Warning: All have you done will be discarded");
    exit(0);

}
int main()
{
    int x,k=1,y,check=0,check2=0;
    load();
    do
    {
        printf("what do you want to make?\n1.Search\n2.Add\n3.Delete\n4.Modify\n5.Print\n6.Save\n7.Quit\n");
        printf("choose number: ");
        scanf("%d",&x);
        if(x==1)
        {
            search();
            check=1;

        }
        if(x==2)
        {
            Add();
            check=1;

        }
        if(x==3)
        {
            Delete();
            check=1;

        }
        if(x==4)
        {
            Modify();
            check=1;

        }
        if(x==5)
        {
            print();
            check=1;

        }
        if(x==6)
        {
            save();
            m=1;
            check=1;
        }
        if(x==7)
        {
            do
            {
                printf("Do you want to exit the program\n1.Yes\n2.No\n");
                scanf("%d",&y);
                if(y==1)
                {
                    Quit();
                }
                if (y==2)
                {
                    check=1;
                    check2=1;
                }
            }
            while(check2==0);
        }

        if(check==0)
            printf("Enter Number Again: \n");
    }
    while(check==0||k==1);


    return 0;
}
