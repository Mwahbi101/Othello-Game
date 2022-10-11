#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define VIDE ' '
#include "Les_Outils.h"
#include "manVsmachine.h"
#include "ManVsMan.h"
#include "manVsmachine_AI.h"

int main()
{
    int joueur=1,c,b;
    char a;
    start();
    scanf("%c",&a);
    c=(int)(a)-48;
    if(a=='r'|| a=='R') {printf("\n\n\n\n\n\n\n");main();}
    else if(a=='q'|| a=='Q') {printf("\n\n\n\n\n\n\n");EXIT();exit(1);}
    else{
    if (c==1){without_help();}
    else if (c==2){
        setting();
        scanf("%d",&b);
        if (b==1) with_help();
        else without_help();
    }
    else if (c==3) EXIT() ;
    else main();}


    return 0;
}
