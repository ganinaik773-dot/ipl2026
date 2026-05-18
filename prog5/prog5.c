#include<stdio.h>


union decision {

unsigned char flags;

struct field {
int your_choice:1; 
int your_mothers_choice:1;
int your_fathers_choice:1;
int socially_acceptable:1;
int financially_viable:1;
int do_you_aptitude:1;
int do_you_likeit:1;
int decision:1;
}f;

};

union decision input();
/* Write an expression that closely matches how you make decision */
void make_decision(union decision *d);
/* Print a nice narrative*/
void print_decsion(union decision d);
/* think of an interesting use for flags and printt an interpretaion based on the number stored in flags */
void print_conclusion_based_on_flags( union decision d);


int main()
{
    union decision d;
    d=input();

    make_decision(&d);

    print_decsion( d);

    print_conclusion_based_on_flags(  d);

    return 0;


}
union decision input(){
     union decision d;

     int temp;

     d.flags=0;

     printf("Enter the choice if yes enter 1 otherwise 0\n");

     printf("Enter your mother choice\n");
     scanf("%d",&temp);
     d.f.your_mothers_choice=temp;

     printf("Enter your father choice\n");
     scanf("%d",&temp);
     d.f.your_fathers_choice=temp;

     printf("Enter socially_acceptable choice\n");
     scanf("%d",&temp);
     d.f.socially_acceptable=temp;

     printf("Enter financially_viable choice\n");
     scanf("%d",&temp);
     d.f.financially_viable=temp;

     printf("Enter you_aptitude choice\n");
     scanf("%d",&temp);
     d.f.do_you_aptitude=temp;

     printf("do_you_likeit\n");
     scanf("%d",&temp);
     d.f.do_you_likeit=temp;

     return d;


}
void make_decision(union decision *d){

    d->f.your_choice=d->f.do_you_likeit && d->f.financially_viable && d->f.do_you_aptitude;

    d->f.decision=d->f.your_choice && (d->f.your_fathers_choice || d->f.your_mothers_choice) && d->f.socially_acceptable;

}
void print_decsion(union decision d){

    printf("\n\n Decision Report\n\n");

    printf("morher support:%s",d.f.your_mothers_choice ? "yes" :"no");
    printf("\nfather support:%s",d.f.your_fathers_choice ? "yes" :"no");
    printf("\nfincial acceptable:%s",d.f.financially_viable ? "yes" :"no");
    printf("\nsocially acceptable:%s",d.f.socially_acceptable? "yes" :"no");
    printf("\napptitude:%s",d.f.do_you_aptitude ? "yes" :"no");
    printf("\nyou like it:%s",d.f.do_you_likeit ? "yes" :"no");
    printf("\nfinal decision:%s\n",
       d.f.decision ? "yes" : "no");
    
}
void print_conclusion_based_on_flags( union decision d){
    printf("\nFlags Value = %u\n",d.flags);

   
    if(d.f.decision)
    {
        printf("Conclusion: Go Ahead!\n");
    }
    else
    {
        printf("Conclusion: Reconsider Carefully.\n");
    }
}