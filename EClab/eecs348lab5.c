/*348 lab 5 problem 2
Football score possiblities
Author: Jeff Burns
Date Created: 10/13/2023
*/
#include <stdio.h>
int score=0;
int safety=0;
int fg=0;
int td=0;
int td1=0; 
int td2=0;
int main() {

int test = 1;
while(test==1){
printf("What score breakdown do you want to see?\n");
scanf("%d",&score);

if (score < 2){
    test = 0;
}
if (score >=2) {
    breakdownsafety(score);
    safety=fg=td=td1=td2=0;
}
if (score >=3){
    breakdownfg(score);
     safety=fg=td=td1=td2=0;
}
if (score >= 6){
    breakdowntd(score);
     safety=fg=td=td1=td2=0;
}
if (score >= 7){
    breakdowntd1(score);
    safety=fg=td=td1=td2=0;
}
if (score >= 8){
    breakdowntd2(score);
     safety=fg=td=td1=td2=0;
}


}
}
int breakdownsafety(int num){
    
    if (num==0){
        printf("%d TD + 2 pts, %d TD + 1 pt, %d TD, %d 3pt FG %d safety\n", td2, td1, td, fg, safety);
    } else if(num == 2){
        safety+=1;
        breakdownsafety(num - 2);
    } else if(num > 2 && num%2 == 0){
        safety+=1;
        breakdownsafety(num - 2);
    } else if( num > 2 && num%2==1){
         fg+=1;
        breakdownsafety(num - 3);
    }//return 0;
}

int breakdownfg(num){
    if(num <= 2){
        breakdownsafety(num);
    }else if (num == 3){
        fg+=1;
        breakdownsafety(num - 3);
    }else if (num > 3 && num%3==0){
        fg+=1;
        breakdownfg(num - 3);
    }else if (num > 3 && num - 3 >= 2){
        fg+=1;
        breakdownfg(num - 3);
    }else if (num > 3 && num%3 >0){
        safety +=1;
        breakdownsafety(num - 2);
    
    }return 0;

}

int breakdowntd(num){
    if(num <= 2){
        breakdownsafety(num);
    }else if (num == 3){
        fg+=1;
        breakdownsafety(num - 3);
    }else if (num < 6 ){
        breakdownfg(num);
    }else if (num == 6){
        td+=1;
        breakdownsafety(num - 6);
    }else if(num > 6 && (num%6 !=1)){
        td+=1;
        breakdowntd(num - 6);
    }else if (num > 6 && (num%6 ==1)){
        breakdownfg(num);
    }return 0;
}

int breakdowntd1(num){
    if(num <= 2){
        breakdownsafety(num);
    }else if (num == 3){
        fg+=1;
        breakdownsafety(num - 3);
    }else if (num < 7 ){
        breakdowntd(num);
    }else if (num == 7){
        td1+=1;
        breakdownsafety(num - 7);
    }else if(num > 7 && (num%7 !=1)){
        td1+=1;
        breakdowntd1(num - 7);
    }else if (num > 7 && (num%7 ==1)){
        breakdowntd(num);
    }return 0;

}

int breakdowntd2(num){
       if(num <= 2){
        breakdownsafety(num);
    }else if (num == 3){
        fg+=1;
        breakdownsafety(num - 3);
    }else if (num < 8 ){
        breakdowntd1(num);
    }
    else if (num == 8){
        td2+=1;
        breakdownsafety(num - 8);
    }else if(num > 8 && (num%8 != 1)){
        td2 +=1;
        breakdowntd2(num);
    }else if (num > 8 && (num%8==1)){
        breakdowntd1(num);
        
    }return 0;


}



