#include "gym.h"

CustomerInfo * Login_user(){
    int i,choice;
    char cos_ID[ID_LEN],key[KEY_LEN];
    CustomerInfo * cus;
    printf("please enter your ID:\n");
    scanf("%s",cos_ID);
    getchar();
    if((cus = search_cus_ID(cos_ID))==NULL){
        printf("sorry,you have not registered\n");
        return NULL;
    }
    for(i = 0;i<3;i++) {
        printf("please enter your key:\n");
        scanf("%s", key);
        getchar();
        if(strcmp(key,cus->key)==0)
            break;
        else {
            printf("sorry,your key is wrong,do you want to try again ?(yes-1 no-2)\n");
            scanf("%d",&choice);
            getchar();
            if(choice != 1)
                break;
        }
    }
    if(i==3){
        printf("you have enter your key wrongly for 3 times,you have to back compulsorily\n");
        return NULL;
    }else
        return cus;
}
AdminInfo * Login_adm(){
    int i,choice;
    char adm_ID[ID_LEN],key[KEY_LEN];
    AdminInfo * adm;
    printf("please enter your ID:\n");
    scanf("%s",adm_ID);
    getchar();
    if((adm = search_adm_ID(adm_ID))==NULL){
        printf("sorry,you have not registered\n");
        return NULL;
    }
    for(i = 0;i<3;i++) {
        printf("please enter your key:\n");
        scanf("%s", key);
        getchar();
        if(strcmp(key,adm->key)==0)
            break;
        else {
            printf("sorry,your key is wrong,do you want to try again ?(yes-1 no-2)\n");
            scanf("%d",&choice);
            getchar();
            if(choice != 1)
                break;
        }
    }
    if(i==3){
        printf("you have enter your key wrongly for 3 times,you have to back compulsorily\n");
        return NULL;
    }else
        return adm;
}

int revise_customer_info(CustomerInfo * cos){
    int choice,i;
    char s[40];
    while(choice != 5){
        cos_modify_menu();
        scanf("%d",&choice);
        getchar();
        switch(choice) {
            case 1:
                printf("please enter your phone number:\n");
                scanf("%s", s);
                getchar();
                while(_check_phone(s)!=0){
                    printf("sorry,your phone number can not exist, do you want to try again?(yes-1 no-2)\n");
                    scanf("%d",&choice);
                    getchar();
                    if(choice != 1)
                        break;
                    printf("please enter your phone number:\n");
                    scanf("%s", s);
                    getchar();
                }
                strcpy(cos->phone_num,s);
                break;
            case 2:
                printf("please enter your original key:\n");
                for (i = 0; i < 3; i++) {
                    scanf("%s", s);
                    getchar();
                    if (strcmp(s, cos->key) == 0) {
                        printf("please enter your new key:\n");
                        printf("(for security ,there has to be both number & alpha in new key"
                                       ",but no other word ,besides the key word can not less than 6 words)\n");
                        scanf("%s",s);
                        getchar();
                        while(_check_password(s)!=0){
                            printf("sorry,your new key is not compatible,do you want to try again?(yes-1 no-2)\n");
                            scanf("%d",&choice);
                            getchar();
                            if(choice != 1)
                                break;
                            printf("please enter your new key:\n");
                            printf("(for security ,there has to be both number & alpha in new key"
                                           ",but no other word ,besides the key word can not less than 6)\n");
                            scanf("%s", s);
                            getchar();
                        }
                    } else {
                        printf("sorry, your key is wrong,do you want to try again?(yes-1 no-2)\n");
                        scanf("%d", &choice);
                        getchar();
                        if (choice != 1)
                            break;
                    }
                }
                if (i == 3)
                    printf("you have enter your key wrongly for 3 times,you have to back compulsorily\n");
                break;
            case 3:
                printf("please enter your new e_mail\n");
                scanf("%s", s);
                getchar();
                while(_check_mail(s)!=0) {
                    printf("sorry,your e_mail can not exist,do you want to try again?(yes-1 no-2)\n");
                    scanf("%d",&choice);
                    getchar();
                    if(choice != 1)
                        break;
                    printf("please enter your new e_mail\n");
                    scanf("%s", s);
                    getchar();
                    strcpy(cos->e_mail, s);
                }
                break;
            case 4:
                printf("please enter your region\n");
                scanf("%s", cos->region);
                getchar();
                break;
            case 5:
                break;
            default:
                printf("wrong choice\n");
        }
        cos_modify_menu();
    }
    return 0;
}
int revise_admin_info(AdminInfo * adm){
    int choice,i;
    char s[40];
    while(choice != 4){
        adm_modify_menu();
        scanf("%d",&choice);
        getchar();
        switch(choice) {
            case 1:
                printf("please enter your phone number:\n");
                scanf("%s", s);
                getchar();
                while(_check_phone(s)!=0){
                    printf("sorry,your phone number can not exist, do you want to try again?(yes-1 no-2)\n");
                    scanf("%d",&choice);
                    getchar();
                    if(choice != 1)
                        break;
                    printf("please enter your phone number:\n");
                    scanf("%s", s);
                    getchar();
                }
                strcpy(adm->phone_num,s);
                break;
            case 2:
                printf("please enter your original key:\n");
                for (i = 0; i < 3; i++) {
                    scanf("%s", s);
                    getchar();
                    if (strcmp(s, adm->key) == 0) {
                        printf("please enter your new key:\n");
                        printf("(for security ,there has to be both number & alpha in new key"
                                       ",but no other word ,besides the key word can not less than 6)\n");
                        scanf("%s", s);
                        getchar();
                        while(_check_password(s)!=0){
                            printf("sorry,your new key is not compatible,do you want to try again?(yes-1 no-2)\n");
                            scanf("%d",&choice);
                            getchar();
                            if(choice != 1)
                                break;
                            printf("please enter your new key:\n");
                            printf("(for security ,there has to be both number & alpha in new key"
                                           ",but no other word ,besides the key word can not less than 6)\n");
                            scanf("%s", s);
                            getchar();
                        }
                    } else {
                        printf("sorry, your key is wrong,do you want to try again?(yes-1 no-2)\n");
                        scanf("%d", &choice);
                        getchar();
                        if (choice != 1)
                            break;
                    }
                }
                if (i == 3)
                    printf("you have enter your key wrongly for 3 times,you have to back compulsorily\n");
                break;
            case 3:
                printf("please enter your new e_mail\n");
                scanf("%s", s);
                getchar();
                while(_check_mail(s)!=0) {
                    printf("sorry,your e_mail can not exist,do you want to try again?(yes-1 no-2)\n");
                    scanf("%d",&choice);
                    getchar();
                    if(choice != 1)
                        break;
                    printf("please enter your new e_mail\n");
                    scanf("%s", s);
                    getchar();
                    strcpy(adm->e_mail, s);
                }
                break;
            case 4:
                break;
            default:
                printf("wrong choice\n");
        }
    }
    return 0;
}

void cus_show_orders(CustomerInfo * cos){
    for(int i = 0;cos->rent_info[i]!=NULL;i++){
        printf("site_ID\tAppoint_ID\tAppoint_time\tstart_date\tstart_time\tend_time\tprice\tis_intime\n");
        printf("%s\t%s\t",cos->rent_info[i]->site_info->ID,cos->rent_info[i]->Appoint_ID);
        printf("%d:%02d:%02d:%02d:%02d\t ",cos->rent_info[i]->appoint_time[0],cos->rent_info[i]->appoint_time[1],cos->rent_info[i]->appoint_time[2],
                cos->rent_info[i]->appoint_time[3],cos->rent_info[i]->appoint_time[4]);
        printf("%d:%02d:%02d\t",cos->rent_info[i]->start_date[0],cos->rent_info[i]->start_date[1],cos->rent_info[i]->start_date[2]);
        printf("%d:%02d\t",cos->rent_info[i]->start_time[0],cos->rent_info[i]->start_time[1]);
        printf("%d:%02d\t",cos->rent_info[i]->end_time[0],cos->rent_info[i]->end_time[1]);
        printf("%.2f\t%d\n",cos->rent_info[i]->price,cos->rent_info[i]->is_intime);
    }
}
void adm_show_orders(AdminInfo * adm){
    for(int j = 0;j<adm->site_info_len;j++){
        for(int i = 0;i<adm->site_info[j]->rent_info_len;i++) {
            printf("site_ID\tAppoint_ID\tAppoint_time\tstart_date\tstart_time\tend_time\tprice\tis_intime\n");
            printf("%s\t%s\t", adm->site_info[j]->ID, adm->site_info[j]->rent_info[i]->Appoint_ID);
            printf("%d:%02d:%02d:%02d:%02d\t ", adm->site_info[j]->rent_info[i]->appoint_time[0], adm->site_info[j]->rent_info[i]->appoint_time[1],
                   adm->site_info[j]->rent_info[i]->appoint_time[2],
                   adm->site_info[j]->rent_info[i]->appoint_time[3], adm->site_info[j]->rent_info[i]->appoint_time[4]);
            printf("%d:%02d:%02d\t", adm->site_info[j]->rent_info[i]->start_date[0], adm->site_info[j]->rent_info[i]->start_date[1],
                   adm->site_info[j]->rent_info[i]->start_date[2]);
            printf("%d:%02d\t", adm->site_info[j]->rent_info[i]->start_time[0], adm->site_info[j]->rent_info[i]->start_time[1]);
            printf("%d:%02d\t", adm->site_info[j]->rent_info[i]->end_time[0], adm->site_info[j]->rent_info[i]->end_time[1]);
            printf("%.2f\t%d\n", adm->site_info[j]->rent_info[i]->price, adm->site_info[j]->rent_info[i]->is_intime);
        }
    }
}
void adm_show_site(AdminInfo * adm){
    for(int i = 0;i< adm->site_info_len;i++){
        printf("\n");
        printf("Site Info:\n");
        printf("ID\tvenue name\tregion\tsport\tenter age\trent\tintroduction\n");
        printf("%s\t%s\t%s\t%s\t%d\t%.2f\t%s",adm->site_info[i]->ID,adm->venue_name,adm->site_info[i]->region,adm->site_info[i]->sport,
                adm->site_info[i]->enter_age,adm->site_info[i]->rent,adm->site_info[i]->intro);
    }
}

int cancel_order(){
    char ID[ID_LEN];
    int cur_time[5];
    RentalInfo * r=NULL;
    get_cur_time(cur_time);
    printf("please enter the order ID you want to cancel:\n");
    scanf("%s",ID);
    getchar();
    for(int i = 0;i<RENT_LEN;i++){
        if(strcmp(ID,rent[i]->Appoint_ID)==0)
            r = rent[i];
    }
    if(r==NULL){
        printf("sorry,can not find your order\n");
        return -1;
    }
    if(_check_24_hour(r->start_time)==0){
        r->is_complete = -1;
        r->site_info->order_num--;
        r->site_info->total_profit-=_get_time_len(r->start_time,r->end_time)*r->site_info->rent;
        printf("cancel your order successfully\n");
    } else{
        printf("your order can only be canceled in 24h");
        return -1;
    }
}