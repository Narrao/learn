#include<stdio.h>
int main()
{
    struct student{
        int num;
        int age;
    };
    struct student stu[3] = {{101, 201}, {102, 19}, {103,2011}}, *p = stu;
    printf("%d %d\n",p->num,p->age);
    p++;
    printf("%d %d\n",p->num,p->age);
    system("pause");
    return 0;
}