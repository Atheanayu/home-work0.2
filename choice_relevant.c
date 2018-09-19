/* 版权说明：
 * 1. 版权归本小组（余涵 夏雨琴 池晓威 康凯 张睿毅）所有
 * 2. 只能用于学习和参考使用
 * 3. 使用本品需经本小组全体成员同意，违者必究
 *
 * 版本号：2.0
 *
 * 生成日期：2018.9.18
 *
 * 作者：余涵
 *
 * 内容：该文件为程序的头文件部分，声明了程序所用到的函数、宏、变量
 * */


#include "gym.h"
/* 函数功能：设计了顾客登陆过程的交互、对用户信息的验证，密码最多输入3次
 * 传入参数：void
 * 返回值：指向 该登陆用户信息结构体 的指针
 * 调用关系：调用了函数 search_cus_ID 通过ID来找到该顾客的结构体指针
 * 作者：余涵
 * */
CustomerInfo * Login_user()
{
    int i,choice;
    char cos_ID[ID_LEN],key[KEY_LEN];
    CustomerInfo * cus;
    printf("please enter your ID:\n");
    scanf("%s",cos_ID);
    getchar();
    if((cus = search_cus_ID(cos_ID))==NULL)/* 查看是否存在这个用户 */
    {
        printf("sorry,you have not registered\n");
        return NULL;
    }
    for(i = 0;i<3;i++)
    {
        printf("please enter your key:\n");
        scanf("%s", key);
        getchar();
        if(strcmp(key,cus->key)==0)/* 判断密码是否正确 */
            break;
        else /* 密码错误则可以重新输入，或者返回 */
        {
            printf("sorry,your key is wrong,do you want to try again ?(yes-1 no-2)\n");
            scanf("%d",&choice);
            getchar();
            if(choice == 2)
                break;
            else if(choice != 1)
            {
                printf("wrong choice\n");
                break;
            }
        }
    }
    if(i==3)/* 密码三次输入错误就退出 */
    {
        printf("you have enter your key wrongly for 3 times,you have to back compulsorily\n");
        return NULL;
    }else
        return cus;
}
/* 函数功能：设计了管理员登陆过程的交互，对管理员信息的验证
 * 传入参数：void
 * 返回值：指向 该登陆管理员信息的结构体 的指针
 * 调用关系：调用了 search_adm_ID 通过ID来找到该顾客的结构体指针
 * 作者：余涵
 * */
AdminInfo * Login_adm()
{
    int i,choice;
    char adm_ID[ID_LEN],key[KEY_LEN];
    AdminInfo * adm;
    printf("please enter your ID:\n");
    scanf("%s",adm_ID);
    getchar();
    if((adm = search_adm_ID(adm_ID))==NULL)/* 查看是否存在这个管理员 */
    {
        printf("sorry,you have not registered\n");
        return NULL;
    }
    for(i = 0;i<3;i++)
    {
        printf("please enter your key:\n");
        scanf("%s", key);
        getchar();
        if(strcmp(key,adm->key)==0)/* 判断密码是否正确 */
            break;
        else/* 密码错误：重新输入 或者 返回 */
        {
            printf("sorry,your key is wrong,do you want to try again ?(yes-1 no-2)\n");
            scanf("%d",&choice);
            getchar();
            if(choice == 2)
                break;
            else if(choice != 1) {
                printf("wrong choice\n");
                break;
            }
        }
    }
    if(i==3)/* 密码最多输入3次 */
    {
        printf("you have enter your key wrongly for 3 times,you have to back compulsorily\n");
        return NULL;
    }else
        return adm;
}
/* 函数功能：修改顾客信息
 * 传入参数：指向该客户信息的指针
 * 返回值：是否成功额修改客户信息
 * 调用关系：调用了_check_phone _check_password _check_mail 3个检验用函数
 * 作者：余涵
 * */
int revise_customer_info(CustomerInfo * cos)
{
    int choice,i,choice1;
    char s[40];
    while(choice != 5)
    {
        cos_modify_menu();
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
                printf("please enter your phone number:\n");
                scanf("%s", s);
                getchar();
                while(_check_phone(s)!=0)
                {/* 检验这新电话号码是否是11位，如果不是11位，可以选择重新输入 或者 返回 */
                    printf("sorry,your phone number can not exist, do you want to try again?(yes-1 no-2)\n");
                    scanf("%d",&choice1);
                    getchar();
                    if(choice1 == 2)
                        break;
                    else if(choice1 != 1)
                    {
                        printf("wrong choice\n");
                        break;
                    }
                    printf("please enter your phone number:\n");
                    scanf("%s", s);
                    getchar();
                }
                if(_check_phone(s)==0)
                    strcpy(cos->phone_num,s);
                break;
            case 2:
                for (i = 0; i < 3; i++)
                {/* 修改密码，首先需要输入原先的密码，如果输入三次都不正确，不可修改密码 */
                    printf("please enter your original key:\n");
                    scanf("%s", s);
                    getchar();
                    if (strcmp(s, cos->key) == 0) /* 判断原密码是否正确 */
                    {
                        printf("please enter your new key:\n");
                        printf("(for security ,there has to be both number & alpha in new key"
                                       ",but no other word ,besides the key word can not less than 6 words)\n");
                        scanf("%s",s);
                        getchar();
                        while(_check_password(s)!=0)/* 查看新密码是否是数字和字母的组合，并且位数为6到12位 */
                        {
                            printf("sorry,your new key is not compatible,do you want to try again?(yes-1 no-2)\n");
                            scanf("%d",&choice1);/* 新密码格式不符合，可以选择重新输入或者放弃修改 */
                            getchar();
                            if(choice1 == 2)
                                break;
                            else if(choice1 !=1)
                            {
                                printf("wrong choice\n");
                                break;
                            }
                            printf("please enter your new key:\n");
                            printf("(for security ,there has to be both number & alpha in new key"
                                           ",but no other word ,besides the key word can not less than 6)\n");
                            scanf("%s", s);
                            getchar();
                        }
                        if(_check_password(s)==0)
                            strcpy(cos->key,s);
                        break;
                    } else
                    {
                        printf("sorry, your key is wrong,do you want to try again?(yes-1 no-2)\n");
                        scanf("%d",&choice1);
                        getchar();
                        if (choice1 == 2)
                            break;
                        else if(choice1 != 1){
                            printf("wrong choice\n");
                            break;
                        }
                    }
                }
                if (i == 3)
                    printf("you have enter your key wrongly for 3 times,you have to back compulsorily\n");
                break;
            case 3:
                printf("please enter your new e_mail\n");
                scanf("%s", s);
                getchar();
                while(_check_mail(s)!=0)/* 查看邮箱是否符合 xxxx@xx.xxx的形式 */
                {
                    printf("sorry,your e_mail can not exist,do you want to try again?(yes-1 no-2)\n");
                    scanf("%d",&choice1);
                    getchar();
                    if(choice1 == 2)
                        break;
                    else if(choice1 != 1)
                        printf("wrong choice\n");
                    printf("please enter your new e_mail\n");
                    scanf("%s",s);
                    getchar();
                    strcpy(cos->e_mail,s);
                }
                if(_check_mail(s)==0)
                    strcpy(cos->e_mail,s);
                break;
            case 4:/* 修改所在区域 */
                printf("please enter your region\n");
                scanf("%s", cos->region);
                getchar();
                break;
            case 5:
                break;
            default:
                printf("wrong choice\n");
        }
    }
    return 0;
}

/* 函数功能：修改管理员信息
 * 传入参数：指向该管理员信息的指针
 * 返回值：是否成功修改管理员信息
 * 调用关系：调用 _check_phone _check_password _check_mail 3个用于检查的函数
 * 作者：余涵
 * */
int revise_admin_info(AdminInfo * adm){
    int choice,i,choice1;
    char s[40];
    while(choice != 4)
    {
        adm_modify_menu();
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:/* 修改电话号码 */
                printf("please enter your phone number:\n");
                scanf("%s", s);
                getchar();
                while(_check_phone(s)!=0)/* 判断电话号码是否是11位 */
                {
                    printf("sorry,your phone number can not exist, do you want to try again?(yes-1 no-2)\n");
                    scanf("%d",&choice1);/* 电话号码位数错误，可以选择重新输入和放弃修改 */
                    getchar();
                    if(choice1 == 2)
                        break;
                    else if(choice1 != 1)
                    {
                        printf("wrong choice\n");
                        break;
                    }
                    printf("please enter your phone number:\n");
                    scanf("%s", s);
                    getchar();
                }
                if(_check_phone(s)==0)
                    strcpy(adm->phone_num,s);
                break;
            case 2:/* 修改密码 */
                for (i = 0; i < 3; i++) /* 原密码输入最多3次 */
                {
                    printf("please enter your original key:\n");
                    scanf("%s", s);
                    getchar();
                    if (strcmp(s, adm->key) == 0) /* 判断原密码是否符合 */
                    {
                        printf("please enter your new key:\n");
                        printf("(for security ,there has to be both number & alpha in new key"
                                       ",but no other word ,besides the key word can not less than 6)\n");
                        scanf("%s", s);
                        getchar();
                        while(_check_password(s)!=0)/* 判断新密码是否是数字和字母的组合，并且是6到12位 */
                        {
                            printf("sorry,your new key is not compatible,do you want to try again?(yes-1 no-2)\n");
                            scanf("%d",&choice1);/* 密码格式错误，可以选择重新输入 或者 放弃修改 */
                            getchar();
                            if(choice1 == 2)
                                break;
                            else if(choice1 != 1)
                            {
                                printf("wrong choice\n");
                                break;
                            }
                            printf("please enter your new key:\n");
                            printf("(for security ,there has to be both number & alpha in new key"
                                           ",but no other word ,besides the key word can not less than 6)\n");
                            scanf("%s", s);
                            getchar();
                        }
                        if(_check_password(s)==0)
                            strcpy(adm->key,s);
                    } else
                    {
                        printf("sorry, your key is wrong,do you want to try again?(yes-1 no-2)\n");
                        scanf("%d", &choice1);/* 输入原密码错误，可以选择重新输入，可以选择放弃修改 */
                        getchar();
                        if (choice1 == 2)
                            break;
                        else if(choice1 != 1){
                            printf("wrong choice\n");
                        }
                    }
                }
                if (i == 3)
                    printf("you have enter your key wrongly for 3 times,you have to back compulsorily\n");
                break;
            case 3:/* 修改邮箱 */
                printf("please enter your new e_mail\n");
                scanf("%s", s);
                getchar();
                while(_check_mail(s)!=0) /* 判断邮箱的格式是否是：xxxx@xx.xxx */
                {
                    printf("sorry,your e_mail can not exist,do you want to try again?(yes-1 no-2)\n");
                    scanf("%d",&choice1);/* 邮箱格式不正确可以选择重新输入 或者 放弃修改 */
                    getchar();
                    if(choice1 == 2)
                        break;
                    else if(choice1 != 1){
                        printf("wrong choice\n");
                        break;
                    }
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
/* 函数功能：展示客户的所有订单
 * 传入参数：指向这个客户的指针
 * 返回值：void
 * 调用关系：无
 * 作者：余涵
 * */
void cus_show_orders(CustomerInfo * cos)
{
    for(int i = 0;i<cos->rent_info_len;i++)
    {
        printf("site_ID\tAppoint_ID\t\t\t\tAppoint_time\t\tstart_date\tstart_time\tend_time\tprice\tis_intime\n");
        printf("%s\t%s\t",cos->rent_info[i]->site_info->ID,cos->rent_info[i]->Appoint_ID);
        printf("%d:%02d:%02d:%02d:%02d\t ",cos->rent_info[i]->appoint_time[0],cos->rent_info[i]->appoint_time[1],cos->rent_info[i]->appoint_time[2],
                cos->rent_info[i]->appoint_time[3],cos->rent_info[i]->appoint_time[4]);
        printf("%d:%02d:%02d\t",cos->rent_info[i]->start_date[0],cos->rent_info[i]->start_date[1],cos->rent_info[i]->start_date[2]);
        printf("%d:%02d\t\t",cos->rent_info[i]->start_time[0],cos->rent_info[i]->start_time[1]);
        printf("%d:%02d\t\t",cos->rent_info[i]->end_time[0],cos->rent_info[i]->end_time[1]);
        printf("%.2f\t%d\n",cos->rent_info[i]->price,cos->rent_info[i]->is_intime);
    }
}
/* 函数功能：展示管理员的所有订单
 * 传入参数：指向这个管理员的指针
 * 返回值：void
 * 调用关系：无
 * 作者：余涵
 * */
void adm_show_orders(AdminInfo * adm)
{
    for(int j = 0;j<adm->site_info_len;j++)
        for(int i = 0;i<adm->site_info[j]->rent_info_len;i++)
        {
            printf("site_ID\tAppoint_ID\t\t\t\tAppoint_time\t\tstart_date\tstart_time\tend_time\tprice\tis_intime\n");
            printf("%s\t%s\t", adm->site_info[j]->ID, adm->site_info[j]->rent_info[i]->Appoint_ID);
            printf("%d:%02d:%02d:%02d:%02d\t ", adm->site_info[j]->rent_info[i]->appoint_time[0], adm->site_info[j]->rent_info[i]->appoint_time[1],
                   adm->site_info[j]->rent_info[i]->appoint_time[2],
                   adm->site_info[j]->rent_info[i]->appoint_time[3], adm->site_info[j]->rent_info[i]->appoint_time[4]);
            printf("%d:%02d:%02d\t", adm->site_info[j]->rent_info[i]->start_date[0], adm->site_info[j]->rent_info[i]->start_date[1],
                   adm->site_info[j]->rent_info[i]->start_date[2]);
            printf("%d:%02d\t\t", adm->site_info[j]->rent_info[i]->start_time[0], adm->site_info[j]->rent_info[i]->start_time[1]);
            printf("%d:%02d\t\t", adm->site_info[j]->rent_info[i]->end_time[0], adm->site_info[j]->rent_info[i]->end_time[1]);
            printf("%.2f\t%d\n", adm->site_info[j]->rent_info[i]->price, adm->site_info[j]->rent_info[i]->is_intime);
        }
}
/* 函数功能：展示管理员的管理的所有场地
 * 传入参数：指向这个管理员的指针
 * 返回值：void
 * 调用关系：无
 * 作者：余涵
 * */
void adm_show_site(AdminInfo * adm)
{
    for(int i = 0;i< adm->site_info_len;i++)
    {
        printf("\n");
        printf("Site Info:\n");
        printf("ID\t\tvenue name\tregion\tsport\tenter age\trent\tintroduction\n");
        printf("%s\t%s\t%s\t%s\t%d\t\t\t%.2f\t%s\n",adm->site_info[i]->ID,adm->venue_name,adm->site_info[i]->region,adm->site_info[i]->sport,
                adm->site_info[i]->enter_age,adm->site_info[i]->rent,adm->site_info[i]->intro);
    }
}
/* 函数功能：展示所有的场地信息
 * 传入参数：void
 * 返回值：void
 * 调用关系：无
 * 作者：余涵
 * */
void show_site()
{
    for(int i = 0;i<site_size;i++)
    {
        printf("\n");
        printf("Site Info:\n");
        printf("ID\t\tvenue name\tregion\tsport\tenter age\trent\tintroduction\n");
        printf("%s\t%s\t%s\t%s\t%d\t\t\t%.2f\t%s\n",site[i]->ID,site[i]->admin_info->venue_name,site[i]->region,site[i]->sport,
               site[i]->enter_age,site[i]->rent,site[i]->intro);
    }
}
/* 函数功能：展示场馆的所有场地的信息
 * 传入参数：指向管理员的指针
 * 返回值：void
 * 调用关系：无
 * 作者：余涵
 * */
void show_adm_site(AdminInfo * adm)
{
    for(int i = 0;i<adm->site_info_len;i++)
    {
        printf("\n");
        printf("Site Info:\n");
        printf("ID\t\tvenue name\tregion\tsport\tenter age\trent\tintroduction\n");
        printf("%s\t%s\t%s\t%s\t%d\t\t\t%.2f\t%s\n",adm->site_info[i]->ID,adm->venue_name,adm->site_info[i]->region,adm->site_info[i]->sport,
               adm->site_info[i]->enter_age,adm->site_info[i]->rent,adm->site_info[i]->intro);
    }
}
/* 函数功能：取消订单
 * 传入参数：指向 要执行取消订单用户 的指针
 * 返回值：是否成功取消订单
 * 调用关系：_check_24_hour 检查时间函数
 * 作者：余涵
 * */
int cancel_order(CustomerInfo* cus)
{
    char ID[ID_LEN];
    int cur_time[5];
    RentalInfo * r=NULL;
    get_cur_time(cur_time);
    printf("please enter the order ID you want to cancel:\n");
    scanf("%s",ID);
    getchar();
    for(int i = 0;i<rent_size;i++){/* 找到想要取消的订单 */
        if(strcmp(ID,rent[i]->Appoint_ID)==0)
            r = rent[i];
    }
    if(r==NULL){/* 找不到则发出错误信息，并返回 */
        printf("sorry,can not find your order\n");
        return -1;
    }
    if(_check_24_hour(r->start_date)==0)
    {/* 检查是否在24小时之外，24小时之外才能取消预定 */
        if(r->is_complete==1 || r->is_complete==-1)
            printf("sorry,your order has been cancel or used");
        r->is_complete = -1;
        r->site_info->order_num--;
        r->site_info->total_profit-=_get_time_len(r->start_time,r->end_time)*r->site_info->rent;
        cus->balance += _get_time_len(r->start_time,r->end_time)*r->site_info->rent;
        printf("cancel your order successfully\n");
    } else
    {/* 不在24小时之外，发出错误信息，并返回 */
        printf("your order can only be canceled in 24h");
        return -1;
    }
    return 0;
}