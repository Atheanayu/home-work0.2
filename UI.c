/* 版权说明：
 * 1. 版权归本小组（余涵 夏雨琴 池晓威 康凯 张睿毅）所有
 * 2. 只能用于学习和参考使用
 * 3. 使用本品需经本小组全体成员同意，违者必究
 *
 * 版本号：2.0
 *
 * 生成日期：2018.9.18
 *
 * 作者：康凯
 *
 * 内容：该文件定义的函数用于和用户交互
 * */

#include "gym.h"
/* 函数功能：主交互函数
 * 传入参数：void
 * 返回值：void
 * 调用关系：调用了Login_user inter_cus_login Login_adm inter_adm_login Register _get_int
 * 作者：康凯
 * */
void inter_main(){
    CustomerInfo * customerInfo;
    AdminInfo * adminInfo;
    int n = 0;
    main_menu();
    while((n = _get_int())!=4)
    {
        switch(n)
        {
            case 1:/* 顾客登陆 */
                if((customerInfo = Login_user())==NULL)
                    printf("Login failed\n");
                else
                    inter_cus_login(customerInfo);
                break;
            case 2:/* 管理员登陆 */
                if((adminInfo = Login_adm())==NULL)
                    printf("Login failed\n");
                else
                    inter_adm_login(adminInfo);
                break;
            case 3:/* 注册 */
                Register();
                break;
            case 4:
                break;
            default:
                printf("wrong choice\n");
        }
        main_menu();
    }
}
/* 函数功能：客户登陆交互函数
 * 传入：该客户指针
 * 传出：void
 * 调用关系：inter_search revise_customer_info cus_show_orders cancel_order
 * 作者：康凯
 * */
void inter_cus_login(CustomerInfo * customerInfo)
{
    int n = 0;
    user_func_menu();
    while((n = _get_int())!=5)
    {
        switch(n)
        {
            case 1:/* 查找相关交互 */
                inter_search(customerInfo);
                break;
            case 2:/* 修改顾客信息 */
                if(revise_customer_info(customerInfo)!=0)
                    printf("revise information failed\n");
                break;
            case 3:/* 顾客展示订单 */
                cus_show_orders(customerInfo);
                break;
            case 4:/* 取消订单 */
                cancel_order(customerInfo);
                break;
            case 5:
                break;
            default:
                printf("wrong choice\n");
        }
        user_func_menu();
    }
}
/* 函数功能：管理员登陆交互函数
 * 传入：该管理员指针
 * 传出：void
 * 调用关系：adm_func_menu reserve_management site_management revise_admin_info
 * 作者：康凯
 * */
void inter_adm_login(AdminInfo * adminInfo)
{
    int n= 0;
    adm_func_menu();
    while((n = _get_int())!=4)
    {
        switch(n)
        {
            case 1:/* 订单管理 */
                reserve_management(adminInfo);
                break;
            case 2:/* 场地管理 */
                site_management(adminInfo);
                break;
            case 3:/* 修改管理员信息 */
                revise_admin_info(adminInfo);
                break;
            case 4:
                break;
            default:
                printf("wrong choice\n");
        }
        adm_func_menu();
    }
}
/* 函数功能：管理员管理订单
 * 传入：该管理员指针
 * 传出：void
 * 调用关系：reserve_management_menu adm_show_orders count_order
 * 作者：康凯
 * */
void reserve_management(AdminInfo * adminInfo)
{
    int n = 0;
    reserve_management_menu();
    while((n = _get_int())!=3)
    {
        switch(n){
            case 1:/* 展示管理员管理的订单 */
                adm_show_orders(adminInfo);
                break;
            case 2:/* 对订单统计类交互 */
                count_order(adminInfo);
                break;
            case 3:
                break;
            default:
                printf("wrong choice\n");
        }
        reserve_management_menu();
    }
}
/* 函数功能：统计相关交互
 * 传入：该管理员指针
 * 传出：void
 * 调用关系：count_order_menu get_venue_profit analyse_age
 * 作者：康凯
 * */
void count_order(AdminInfo * adminInfo)
{
    int n = 0;
    count_order_menu();
    while((n = _get_int())!=7)
    {
        switch(n){
            case 1:/* 按订单降序排场地 */
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_site_order_down);
                show_adm_site(adminInfo);
                break;
            case 2:/* 按利润降序排场地 */
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_site_profit_down);
                show_adm_site(adminInfo);
                break;
            case 3:/* 按时间利用率降序排场地 */
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_site_untilize_down);
                show_adm_site(adminInfo);
                break;
            case 4:/* 获得场馆总利润 */
                printf("The total turnover is %.2lf.\n",get_venue_profit(adminInfo));
                show_adm_site(adminInfo);
                break;
            case 5:/* 最受男女欢迎的运动 */
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_female_sport);
                printf("the most popular sport in female: %s\n",adminInfo->site_info[0]->sport);
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_male_sport);
                printf("the most popular sport in male: %s\n",adminInfo->site_info[0]->sport);
                break;
            case 6:/* 年龄层分析 */
                analyse_age(adminInfo);
                break;
            case 7:
                break;
            default:
                printf("wrong choice\n");
        }
        count_order_menu();
    }
}
/* 函数功能：场地管理相关交互
 * 传入：该管理员指针
 * 传出：void
 * 调用关系：adm_show_site RegisterSite site_management_menu
 * 作者：康凯
 * */
void site_management(AdminInfo * adminInfo)
{
    int n;
    site_management_menu();
    while((n = _get_int())!=3)
    {
        switch(n)
        {
            case 1:/* 展示管理员相关场地 */
                adm_show_site(adminInfo);
                break;
            case 2:/* 增加场地 */
                RegisterSite(adminInfo);
                break;
            case 3:
                break;
            default:
                printf("wrong choice\n");
        }
        site_management_menu();
    }
}
/* 函数功能：注册相关交互
 * 传入：void
 * 传出：void
 * 调用关系：RegisterCostumer RegisterAdmin
 * 作者：夏雨琴
 * */
void Register()
{
    int n;
    register_menu();
    while((n = _get_int())!=3){
        switch(n)
        {
            case 1:/* 用户注册 */
                RegisterCostumer();
                break;
            case 2:/* 管理员注册 */
                RegisterAdmin();
                break;
            case 3:
                break;
            default:
                printf("wrong choice\n");
        }
        register_menu();
    }
}
/* 函数功能：查找相关交互
 * 传入：指向该顾客的zhizhen
 * 传出：void
 * 调用关系：search_menu search_site_ID get_choice inter_category_search inter_sort_search
 * 作者：康凯
 * */
void inter_search(CustomerInfo * cus)
{
    int n;
    SiteInfo * siteInfo;
    char s[40];
    search_menu();
    while((n = _get_int())!=4)
    {
        switch(n)
        {
            case 1:/* 通过场地ID查询 */
                printf("Please enter the Site ID to search:\n");
                scanf("%s",s);
                getchar();
                if((siteInfo = search_site_ID(s))==NULL){
                    printf("we don't have this site\n");
                    break;
                }else{
                    printf("\n");
                    printf("Site Info:\n");
                    printf("ID\t\tvenue name\tregion\tsport\tenter age\trent\tintroduction\n");
                    printf("%s\t%s\t%s\t%s\t%d\t\t\t%.2f\t%s\n",siteInfo->ID,siteInfo->admin_info->venue_name,siteInfo->region,siteInfo->sport,
                           siteInfo->enter_age,siteInfo->rent,siteInfo->intro);
                    printf("Do you want to reserve?(y/n)\n");
                    if(get_choice()=='y'){
                        RegisterRent(cus);
                    }
                }
                break;
            case 2:/* 分类查询 */
                inter_category_search(cus);
                break;
            case 3:/* 排序查询 */
                inter_sort_search();
                break;
            case 4:
                break;
            default:
                printf("wrong choice\n");
        }
        search_menu();
    }
}
/* 函数功能：分类查询相关交互
 * 传入：该顾客
 * 传出：void
 * 调用关系：category_menu search_venue_name adm_show_site get_choice
 * 作者：康凯
 * */
void inter_category_search(CustomerInfo * cus)
{
    int n,flag = 0;
    char s[40];
    AdminInfo * adminInfo;
    category_menu();
    while((n = _get_int())!=4)
    {
        switch(n)
        {
            case 1:/* 通过场馆查询订单 */
                printf("Please enter the Venue name to search:\n");
                scanf("%s",s);
                getchar();
                if((adminInfo = search_venue_name(s))==NULL)
                    printf("we don't have this venue\n");
                else{
                    adm_show_site(adminInfo);
                    printf("Do you want to reserve?(y/n)\n");
                    if(get_choice()=='y'){
                        RegisterRent(cus);
                    }
                }
                break;
            case 2:/* 通过运动种类查询订单 */
                flag = 0;
                printf("Please enter the Sport name to search:\n");
                scanf("%s",s);
                getchar();
                for(int i= 0;i<site_size;i++)
                    if(strcmp(site[i]->sport,s)==0){
                        flag = 1;
                        printf("\nSite Info:\n");
                        printf("ID\t\tvenue name\tregion\tsport\tenter age\trent\tintroduction\n");
                        printf("%s\t%s\t%s\t%s\t%d\t\t\t%.2f\t%s\n",site[i]->ID,site[i]->admin_info->venue_name,site[i]->region,site[i]->sport,
                               site[i]->enter_age,site[i]->rent,site[i]->intro);
                    }
                if(flag== 0)
                    printf("we don't have this sport\n");
                else {
                    printf("do you want to reserve?(y/n)\n");
                    if(get_choice()=='y'){
                        RegisterRent(cus);
                    }
                }
                break;
            case 3:/* 通过地区查询订单 */
                flag = 0;
                printf("Please enter the Region name to search:\n");
                scanf("%s",s);
                getchar();
                for(int i = 0;i<site_size;i++)
                    if(strcmp(site[i]->region,s)==0){
                        flag = 1;
                        printf("\nSite Info:\n");
                        printf("ID\t\tvenue name\tregion\tsport\tenter age\trent\tintroduction\n");
                        printf("%s\t%s\t%s\t%s\t%d\t\t\t%.2f\t%s\n",site[i]->ID,site[i]->admin_info->venue_name,site[i]->region,site[i]->sport,
                               site[i]->enter_age,site[i]->rent,site[i]->intro);
                    }
                if(flag == 0)
                    printf("we don't have this region\n");
                else{
                    printf("do you want to reserve?(y/n)\n");
                    if(get_choice()=='y'){
                        RegisterRent(cus);
                    }
                }
                break;
            case 4:
                break;
            default:
                printf("Wrong Choice\n");
                break;
        }
        category_menu();
    }
}
/* 函数功能：排序查询相关交互
 * 传入：void
 * 传出：void
 * 调用关系：一系列排序依据
 * 作者：康凯
 * */
void inter_sort_search()
{
    int n;
    sort_menu();
    scanf("%d",&n);
    getchar();
    while((n!=5))
    {
        switch(n)
        {
            case 1:/* 升序排租金 */
                qsort(site,site_size,sizeof(SiteInfo *),_comp_site_rent_up);
                show_site();
                break;
            case 2:/* 降序排租金 */
                qsort(site,site_size,sizeof(SiteInfo *),_comp_site_rent_down);
                show_site();
                break;
            case 3:/* 升序排订单数 */
                qsort(site,site_size,sizeof(SiteInfo *),_comp_site_order_up);
                show_site();
                break;
            case 4:/* 降序排订单数 */
                qsort(site,site_size,sizeof(SiteInfo *),_comp_site_order_down);
                show_site();
                break;
            case 5:
                break;
            default:
                printf("Wrong Choice\n");
        }
        sort_menu();
        scanf("%d",&n);
        getchar();
    }
}
