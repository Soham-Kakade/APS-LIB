#include<stdio.h>
#include<stdlib.h>

struct student
{
    int rollno;
    char usn[25];
    char fname[40];
    char sname[40];
    float cgpa;
    char dob[15];
};
typedef struct student stu;



void write_details()            //To write student details in a file
{
    stu s;
    FILE *fp;
    fp=fopen("Student.txt","a");
    printf("\nEnter Roll no USN First Name Surname CGPA DOB\n");
    scanf("%d%s%s%s%f%s",&s.rollno,s.usn,s.fname,s.sname,&s.cgpa,s.dob);
    fwrite(&s,sizeof(stu),1,fp);
    fclose(fp);
}

void display()                  //To display student details from a file
{
    stu s;
    FILE *fp;
    int count=0;
    fp=fopen("Student.txt","r");
    while(1)
    {
        fread(&s,sizeof(stu),1,fp);
        if(feof(fp))
            break;
        printf("\n%d\t%s\t%s\t%s\t%.2f\t%s",s.rollno,s.usn,s.fname,s.sname,s.cgpa,s.dob);
        count++;
    }
    fclose(fp);
    printf("\nTotal Number of Records %d",count);

}

void display_array(stu s[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
     {
         printf("\n%d\t%s\t%s\t%s\t%.2f\t%s",s[i].rollno,s[i].usn,s[i].fname,s[i].sname,s[i].cgpa,s[i].dob);
         count++;
     }
     printf("\nTotal Number of Records %d",count);
}

void sort_rollno()              //To sort the student details according to roll number
{
    FILE *fp;
    int n,i;
    stu *s;
    fp=fopen("Student.txt","r");
    fseek(fp,0,SEEK_END);
    n=ftell(fp)/sizeof(struct student);
    printf("Total number of records %d",n);
    s=(stu*)malloc(n*sizeof(struct student));
    rewind(fp);
    for(i=0;i<n;i++)
        fread(&s[i],sizeof(stu),1,fp);
    fclose(fp);
    selection_sort(s,n);
    printf("\n------------Records in Roll Number sorted order------------\n");
    display_array(s,n);
    free(s);
}

void sort_cgpa()                //To sort student details according to CGPA
{
    FILE *fp;
    int n,i;
    stu *s;
    fp=fopen("Student.txt","r");
    fseek(fp,0,SEEK_END);
    n=ftell(fp)/sizeof(struct student);
    printf("Total number of records %d",n);
    s=(stu*)malloc(n*sizeof(struct student));
    rewind(fp);
    for(i=0;i<n;i++)
        fread(&s[i],sizeof(stu),1,fp);
    fclose(fp);
    insertion_sort(s,n);
    printf("\n------------Records in CGPA sorted order------------\n");
    display_array(s,n);
    free(s);
}

void search_rollno()            //To search for a particular given roll number
{
    stu s;
    FILE *fp;
    int rno,flag=0;
    fp=fopen("Student.txt","r");
    printf("\nEnter Roll number to search\n");
    scanf("%d",&rno);
    while(fread(&s,sizeof(stu),1,fp))
    {
        if(s.rollno==rno)
        {
            flag=1;
            printf("\n%d\t%s\t%s\t%s\t%.2f\t%s",s.rollno,s.usn,s.fname,s.sname,s.cgpa,s.dob);
        }
    }
    fclose(fp);
    if(flag==0)
        printf("\nInvalid Roll Number\n");
}

void selection_sort(stu a[],int n)
{
    int i,j,min;
    for(i=0;i<n;i++)
    {
        for(min=i,j=i+1;j<n;j++)
        {
            if(a[j].rollno<a[min].rollno)
                min=j;
        }
        if(i!=min)
            swap(&a[i],&a[min]);
    }

}
void swap(stu *a, stu *b)
{
    stu t;
    t=*a;
    *a=*b;
    *b=t;
}
void insertion_sort(stu a[],int n)
{
    int i,j;
    stu data;
    for(i=1;i<n;i++)
    {
        data=a[i];
        j=i-1;
        while(j>=0&&data.cgpa<a[j].cgpa)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=data;
    }
}

void Delete_Rollno()                    //To delete particular record based on roll number
{
    FILE *fp,*fp1;
    int rno,flag=0;
    printf("\nEnter rollno to delete\n");
    scanf("%d",&rno);
    stu s;
    fp=fopen("Student.txt","r");
    fp1=fopen("temp.txt","w");
    while(fread(&s,sizeof(stu),1,fp))
    {
        if(s.rollno==rno)
            flag=1;
        else
            fwrite(&s,sizeof(stu),1,fp1);

    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("Student.txt","w");
    fp1=fopen("temp.txt","r");
    while(fread(&s,sizeof(stu),1,fp1))
        fwrite(&s,sizeof(stu),1,fp);
    if(flag==0)
        printf("\nRoll no not found\n");
    else
        printf("\nDeleted rollno %d record\n",rno);
    fclose(fp);
    fclose(fp1);
}
void sort_name()                        //To sort the student details according to alphabetical order of FirstName or surname
{
    FILE *fp;
    stu *s;
    int i,n,ch;
    fp=fopen("Student.txt","r");
    fseek(fp,0,SEEK_END);
    n=ftell(fp)/sizeof(struct student);
    s=(stu*)malloc(n*sizeof(struct student));
    rewind(fp);
    for(i=0;i<n;i++)
        fread(&s[i],sizeof(stu),1,fp);
    printf("\nEnter\n1.Sort by First name\n2.Sort by Surname\n");
    scanf("%d",&ch);
    if(ch==1)
        bubble_sort_fnames(s,n);
    else if(ch==2)
            bubble_sort_snames(s,n);
         else
         {
             printf("\nInvalid Choice\n");
             return ;
         }
    printf("\n------------Records in Names sorted order------------\n");
    display_array(s,n);
    fclose(fp);

}
void bubble_sort_fnames(stu s[100],int n)
{
    stu temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(s[i].fname,s[j].fname)>0)
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
}
void bubble_sort_snames(stu s[100],int n)
{
    stu temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(s[i].sname,s[j].sname)>0)
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
}

void update_rollno()                    //To update the details of particular roll number
{
    FILE *fp,*fp1;
    int rno,flag=0;
    printf("\nEnter rollno to update\n");
    scanf("%d",&rno);
    stu s;
    fp=fopen("Student.txt","r");
    fp1=fopen("temp.txt","w");
    while(fread(&s,sizeof(stu),1,fp))
    {
        if(s.rollno==rno)
        {
             flag=1;
             printf("\nEnter new Roll no USN First Name Surname CGPA DOB\n");
             scanf("%d%s%s%s%f%s",&s.rollno,s.usn,s.fname,s.sname,&s.cgpa,s.dob);
             fwrite(&s,sizeof(stu),1,fp1);
        }
        else
            fwrite(&s,sizeof(stu),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("Student.txt","w");
    fp1=fopen("temp.txt","r");
    while(fread(&s,sizeof(stu),1,fp1))
        fwrite(&s,sizeof(stu),1,fp);
    if(flag==0)
        printf("\nInvalid Roll Number\n");
    else
        printf("\nUpdated Roll Number %d\n",rno);
    fclose(fp);
    fclose(fp1);
}

int brute(char text[40],char pattern[40])
{
    int i,j,m,n;
    n=strlen(text);
    m=strlen(pattern);
    for(i=0;i<n;i++)
    {   j=0;
        while(j<m && text[i+j]==pattern[j])
        {
            j++;
            if(j==m)
                return 1;
        }
    }
    return 0;
}

void search_name()                  //To search for a particular FirstName or a Surname
{
    stu s,a[10];
    FILE *fp;
    int flag=0,ch,i=0;
    char name[40];
    fp=fopen("Student.txt","r");
    printf("\nEnter\n1.Search by First name\n2.Search by Surname\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("\nEnter FirstName to search\n");
        scanf("%s",name);
        while(fread(&s,sizeof(stu),1,fp))
        {
            if(brute(s.fname,name))
            {
                flag=1;
                printf("\n%d\t%s\t%s\t%s\t%.2f\t%s\n",s.rollno,s.usn,s.fname,s.sname,s.cgpa,s.dob);
            }
        }
    }
    else if(ch==2)
         {
            printf("\nEnter Surname to search\n");
            scanf("%s",name);
            while(fread(&s,sizeof(stu),1,fp))
            {
                if(brute(s.sname,name))
                {
                    flag=1;
                    printf("\n%d\t%s\t%s\t%s\t%.2f\t%s\n",s.rollno,s.usn,s.fname,s.sname,s.cgpa,s.dob);
                }
            }
         }
         else
         {
             printf("\nInvalid Choice\n");
             return;
         }

    if(flag==0)
        printf("\nName not found\n");
    fclose(fp);
}


int main()
{
    int ch;
    while(1)
    {
        printf("\nEnter\n1.Add\n2.Display\n3.Sort Roll Number\n4.Sort on CGPA\n5.Search on Roll Number\n6. Delete by Rollno\n7. Sort by Name\n8. Update by Roll Number\n9.Search by Name\n10.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:write_details();
                   break;
            case 2:display();
                   break;
            case 3:sort_rollno();
                   break;
            case 4:sort_cgpa();
                   break;
            case 5:search_rollno();
                   break;
            case 6:Delete_Rollno();
                   break;
            case 7:sort_name();
                   break;
            case 8:update_rollno();
                   break;
            case 9:search_name();
                   break;
            case 10:exit(0);
                   break;
            default:printf("\nInvalid Choice\n");

        }
    }
}

