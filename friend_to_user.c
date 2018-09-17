#include "gym.h"

int _get_int (void) {
    int input;
    char ch;
    while (scanf ("%d", &input) != 1) {
        while ((ch = (char)getchar()) != '\n') {
            putchar(ch);
        }
        printf (" is not an integer.\nPlease enter an integer:\n");
    }
    getchar();
    return input;
}

int _check_phone(char * phone_num){
    if(strlen(phone_num)!=11){
        printf("the phone number has to be 11");
        return -1;
    }
    for(int i = 0;i<11;i++){
        if(!isdigit(phone_num[i])){
            printf("phone num should be made up with number\n");
            return -1;
        }
    }
    return 0;
}

int _check_password(char * password){
    int is_num=0,is_alpha=0,is_other = 0;
    if(strlen(password)<6){
        printf("for your security,your key has to be more than 6 words\n");
        return -1;
    }
    for(int i = 0;i<strlen(password);i++){
        if(isalpha(password[i])){
            is_alpha = 1;
        }else if(isdigit(password[i])){
            is_num = 1;
        }else
            is_other = 1;
    }
    if((!(is_alpha && is_num)) || is_other){
        printf("sorry, your password should be consist of alpha and num\n");
        return -1;
    }
    return 0;
}

int _check_ID(char * ID){
    int is_num=0,is_alpha=0,is_other=0;
    if(strlen(ID)<6 || strlen(ID)>10){
        printf("sorry, your ID should be more than 6 words ,less than 10 words\n");
        return -1;
    }
    for(int i = 0;i<strlen(ID);i++){
        if(isalpha(ID[i])){
            is_alpha = 1;
        }else if(isdigit(ID[i])){
            is_num = 1;
        } else{
            is_other = 1;
        }
    }
    if((!(is_alpha && is_num))&&is_other){
        printf("sorry, your ID should be consist of alpha and num\n");
        return -1;
    }
    return 0;
}

int _check_mail(char * mail){
    int at_flag = 0,dot_flag = 0;
    for(int i = 0;i<strlen(mail);i++){
        if(mail[i]=='@'){
            if(dot_flag == 1){
                printf("sorry, your mail mode is not right\n");
            }
            if(at_flag == 0)
                at_flag = 1;
            else{
                printf("sorry, your mail mode is not right\n");
                return -1;
            }
        }else if(mail[i]=='.'){
            if(at_flag != 1){
                printf("sorry, your mail mode is not right\n");
            }
            if(dot_flag == 0)
                dot_flag = 1;
            else{
                printf("sorry, your mail mode is not right\n");
                return -1;
            }
        }else if(!isdigit(mail[i]) && !isalpha(mail[i])){
            printf("sorry, your mail mode is not right\n");
            return -1;
        }
    }
    return 0;
}
int _check_24_hour(int* startdate){
    int cur_time[5];
    get_cur_time(cur_time);
    if(startdate[0]==cur_time[0] && startdate[1]==cur_time[1]){
        if(startdate[2] > cur_time[2])
            return 0;
        else
            return -1;
    }else{
        return 0;/* can cancel order */
    }
}
