#include "gym.h"

void RegisterCostumer(){
    int choice = 0;
    CustomerInfo *cus=(CustomerInfo *)malloc(sizeof(CustomerInfo));
    cus->rent_info = (RentalInfo **)malloc(sizeof(RentalInfo*)*RENT_INFO_LEN);
    cus->rent_info_len = 0;
    cus->default_num = 0;
    printf("Please follow the instructions to start registering:\n");
    int i=0,Compare=100;
    do{
        printf("请设置您的ID号（6-10个字符与数字的组合）：\n");          /* 注册ID */
        scanf("%s",cus->ID);                       /* 检测ID合法性 */
    }while(_check_ID(cus->ID)!= 0||_recheck_cusID(cus->ID)==1);
    printf("请设置您的用户名：\n");                                      /* 注册用户名 */
    scanf("%s",cus->name);
    do{
        printf("请设置您的密码：\n");
        scanf("%s",cus->key);                               /* 注册密码合法性 */
    }while(_check_password(cus->key)!=0);
    char CheckKey[KEY_LEN];
    while(Compare!=0){
        printf("请重新确认您的密码:\n");                                 /* 重新确认密码 */
        scanf("%s",CheckKey);
        if((Compare=strcmp(cus->key,CheckKey))!=0)
            printf("sorry, the keys are not compatible,please enter again\n");
    }
    while(1) {
        printf("请输入您的性别：\n1、男\n2、女\n");                      /* 注册性别 */
        scanf("%d", &choice);
        if(choice == 1){
            strcpy(cus->sex,"male");
            break;
        }else if(choice == 2){
            strcpy(cus->sex,"female");
            break;
        }else
            printf("wrong choice\n");
    }
    do{
        printf("请输入您的电话号码：\n");                                /* 注册电话号码 */
        scanf("%s",cus->phone_num);              /* 检测电话号码的合法性 */
    }while(_check_phone(cus->phone_num)!=0);
    do{
        printf("请输入您的邮箱地址：\n");                                /* 注册邮箱 */
        scanf("%s",cus->e_mail);                   /* 检测邮箱的合法性 */
    }while(_check_mail(cus->e_mail)!=0);
    do{
        printf("请输入您的年龄：\n");                                    /* 注册年龄 */
        scanf("%d",&cus->age);                      /* 检测年龄的真实性 */
    }while(_check_age(cus->age)==0);
    printf("please enter your region:\n");
    scanf("%s",cus->region);
    printf("请问您是否要充值余额？\n1、是\n2、否\n");                  /* 选择充值服务 */
    cus->balance=0;
    int newchoice=0;
//    char money[10];
    while(newchoice!=1&&newchoice!=2){
        scanf("%d",&newchoice);
        switch(newchoice){
            case 1:{
                printf("please enter the money you want to spend\n");
                scanf("%lf",&cus->balance);
                printf("您的当前余额为：%.2lf\n",cus->balance);
                break;}
            case 2:{
                printf("您的当前余额为：%.2lf\n",cus->balance);
                break;}
            default:{
                printf("请输入正确选项:\n");
                break;}
        }
    }
    if(cus_size % CUS_LEN==0)
        _increase_cus_room();
    customer[cus_size] = cus;
    cus_size++;
}

void RegisterAdmin(){
    int choice;
    AdminInfo *CurrentAdmin=(AdminInfo *)malloc(sizeof(AdminInfo));
    CurrentAdmin->site_info = (SiteInfo **)malloc(sizeof(SiteInfo*)*SITE_INFO_LEN);
    CurrentAdmin->site_info_len = 0;
    printf("Please follow the instructions to start registering:\n");
    int i=0,Compare=100;
    do{
        printf("请设置您的ID号（6-10个字符与数字的组合）：\n");          /* 注册ID */
        scanf("%s",CurrentAdmin->ID);                       /* 检测ID合法性 */
    }while(_check_ID(CurrentAdmin->ID)!=0||_recheck_admID(CurrentAdmin->ID)!=0);
    do{
        printf("请输入您新注册的场馆ID（6-10个字符与数字的组合）：\n");
        scanf("%s",CurrentAdmin->venue_name);
    }while(_check_ID(CurrentAdmin->venue_name)!=0||_check_venue_name(CurrentAdmin->venue_name)==0);
    printf("请设置您的用户名：\n");                                      /* 注册用户名 */
    scanf("%s",CurrentAdmin->name);
    do{
        printf("请设置您的密码：\n");
        scanf("%s",CurrentAdmin->key);                               /* 注册密码合法性 */
    }while(_check_password(CurrentAdmin->key)!=0);
    char CheckKey[KEY_LEN];
    while(Compare!=0){
        printf("请重新确认您的密码:\n");                                 /* 重新确认密码 */
        scanf("%s",CheckKey);
        if((Compare=strcmp(CurrentAdmin->key,CheckKey))!=0)
            printf("sorry, the keys are not compatible,please enter again\n");
    }
    while(1) {
        printf("请输入您的性别：\n1、男\n2、女\n");                      /* 注册性别 */
        scanf("%d", &choice);
        if(choice == 1){
            strcpy(CurrentAdmin->sex,"male");
            break;
        }else if(choice == 2){
            strcpy(CurrentAdmin->sex,"female");
            break;
        }else
            printf("wrong choice\n");
    }
    do{
        printf("请输入您的电话号码：\n");                                /* 注册电话号码 */
        scanf("%s",CurrentAdmin->phone_num);              /* 检测电话号码的合法性 */
    }while(_check_phone(CurrentAdmin->phone_num)!=0);
    do{
        printf("请输入您的邮箱地址：\n");                                /* 注册邮箱 */
        scanf("%s",CurrentAdmin->e_mail);                /* 检测邮箱的合法性 */
    }while(_check_mail(CurrentAdmin->e_mail	)!=0);
    if(adm_size % ADM_LEN==0)
        _increase_adm_room();
    admin[adm_size] = CurrentAdmin;
    adm_size++;
}
void RegisterSite(AdminInfo * adm){
    char s[40];
    SiteInfo * temp;
    SiteInfo *sit=(SiteInfo *)malloc(sizeof(SiteInfo));
    sit->rent_info = (RentalInfo **)malloc(sizeof(RentalInfo*)*RENT_INFO_LEN);
    sit->rent_info_len = 0;
    sit->admin_info = adm;
    sit->order_num = 0;
    sit->total_profit = 0.00;
    adm->site_info[adm->site_info_len] = sit;
    adm->site_info_len++;
    printf("Please follow the instructions to start registering your account:\n");
    do{
        printf("请设置您新场地的ID号（6-10个字符与数字的组合）：\n");          /* 注册ID */
        scanf("%s",sit->ID);
        getchar();/* 检测ID合法性 */
    }while(_check_ID(sit->ID)!=0||_recheck_sitID(sit->ID)!=0);
    printf("请设置您新场地所在区域:\n");
    scanf("%s",sit->region);
    getchar();
    printf("请设置您新场地的运动:\n");
    scanf("%s",sit->sport);
    getchar();
    if((temp = _recheck_site_sport(sit->sport))!=NULL)
        strcpy(sit->intro,temp->intro);
    else{
        printf("this is a new sport ,please enter its intro\n");
        fgets(s,100,stdin);
        s[strlen(s)-1]='\0';
        strcpy(sit->intro,s);
    }
    do{
        printf("请设置您新场地的准入年龄：\n");
        scanf("%d",&(sit->enter_age));
        getchar();
    }while(_check_age(sit->enter_age)==0);
    printf("请设置您新场地的租金：\n");
    scanf("%lf",&(sit->rent));
    getchar();
    if(site_size%SITE_LEN==0)
        _increase_site_room();
    site[site_size] = sit;
    site_size++;
}
void RegisterRent(CustomerInfo* cus) {
    int flag=0;
    char ID[40];
    char s[40];
    int num=0;
    SiteInfo *temp;
    RentalInfo *rentalInfo = (RentalInfo *) malloc(sizeof(RentalInfo));
    rentalInfo->cus_info = cus;
    rentalInfo->is_complete = 0;
    rentalInfo->age = cus->age;
    strcpy(rentalInfo->gender, cus->sex);
    get_cur_time(rentalInfo->appoint_time);
    sprintf(rentalInfo->Appoint_ID,"%s|%d:%02d:%02d:%02d:%02d",cus->ID,rentalInfo->appoint_time[0],rentalInfo->appoint_time[1],
            rentalInfo->appoint_time[2],rentalInfo->appoint_time[3],rentalInfo->appoint_time[4]);
    printf("Please follow the instructions to start registering:\n");
    while (1) {
        printf("please enter the site you want to reserve\n");
        scanf("%s", ID);
        getchar();
        if ((temp = search_site_ID(ID)) != NULL)
            break;
        else
            printf("can not find the site, please enter again\n");
    }
    rentalInfo->site_info = temp;
    while(1){
        printf("please enter the start date:(int form: yyyy:mm:dd)\n");
        scanf("%s",s);
        getchar();
        for(int i = 0;i<strlen(s);i++){
            if(s[i]==':')
                num ++;
            else if(s[i]<'0'||s[i]>'9') {
                printf("wrong time mode\n");
                flag = 1;
                break;
            }
        }
        if(flag == 1) continue;
        if(num != 2) {
            printf("wrong time mode\n");
            continue;
        }
        sscanf(s,"%d:%d:%d",&rentalInfo->start_date[0],&rentalInfo->start_date[1],&rentalInfo->start_date[2]);
        if(rentalInfo->start_date[1]>12 || rentalInfo->start_date[2]>31) {
            printf("wrong time\n");
            continue;
        } else if(_check_7_day(rentalInfo->start_date)!=0) {
            printf("wrong time\n");
            continue;
        } else
            break;
    }
    while(1){
        printf("please enter the start time:(in form hh:mm)\n");
        scanf("%s",s);
        getchar();
        if(_check_time_mode(s)!=0) {
            printf("wrong time mode\n");
            continue;
        } else{
            sscanf(s,"%d:%d",&rentalInfo->start_time[0],&rentalInfo->start_time[1]);
            if(rentalInfo->start_time[0]>22 || rentalInfo->start_time[0]<6 || rentalInfo->start_time[1]>60) {
                printf("wrong time");
                continue;
            } else
                break;
        }
    }
    while(1){
        printf("please enter the end time:(in form hh:mm)\n");
        scanf("%s",s);
        getchar();
        if(_check_time_mode(s)!=0)
            printf("wrong time mode\n");
        else{
            sscanf(s,"%d:%d",&rentalInfo->end_time[0],&rentalInfo->end_time[1]);
            if(rentalInfo->end_time[0]>22 || rentalInfo->end_time[0]<6 || rentalInfo->end_time[1]>60)
                printf("wrong time\n");
            else if(rentalInfo->end_time[0]==22 && rentalInfo->end_time[1]!=0)
                printf("wrong time\n");
            else
                break;
        }
    }
    rentalInfo->is_intime = 0;
    if(rent_size == RENT_LEN)
        _increase_rent_room();
    rent[rent_size] = rentalInfo;
    rent_size++;
}