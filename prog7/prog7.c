#include<stdio.h>
#include<string.h>

void computelps(char pattern[],int m,int lps[]){
    int len=0;
    lps[0]=0;
    int i=1;

    while(i<m)
    {
        if(pattern[i]==pattern[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len !=0)
            {
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }


}

int kmpsearch(char text[],char pattern[])
{
    int n=strlen(text);
    int m=strlen(pattern);

    int lps[m];

    computelps(pattern,m,lps);

    int i=0,j=0;

    while(i<n)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            return i-j;
        }
        else if(i<n && text[i]!=pattern[j]){
            if(j!=0)
            {
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return -1;
}

int main()
{
    char text[]="ganeshhhhershhhty";
    char pattern[]="shhh";

    int index=kmpsearch(text,pattern);

    printf("found at index:%d",index);


    return 0;

}