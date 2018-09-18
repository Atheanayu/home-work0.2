#include "gym.h"

void inter_main(){
    CustomerInfo * customerInfo;
    AdminInfo * adminInfo;
    int n = 0;
    main_menu();
    while((n = _get_int())!=4){
        switch(n){
            case 1:
                if((customerInfo = Login_user())==NULL){
                    printf("Login failed\n");
                }else{
                    inter_cus_login(customerInfo);
                }
                break;
            case 2:
                if((adminInfo = Login_adm())==NULL){
                    printf("Login failed\n");
                }else{
                    inter_adm_login(adminInfo);
                }
                break;
            case 3:
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
void inter_cus_login(CustomerInfo * customerInfo){
    int n = 0;
    user_func_menu();
    while((n = _get_int())!=5){
        switch(n){
            case 1:
                inter_search(customerInfo);
                break;
            case 2:
                if(revise_customer_info(customerInfo)!=0){
                    printf("revise information failed\n");
                }
                break;
            case 3:
                cus_show_orders(customerInfo);
                break;
            case 4:
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
void inter_adm_login(AdminInfo * adminInfo){
    int n= 0;
    adm_func_menu();
    while((n = _get_int())!=4){
        switch(n){
            case 1:
                reserve_management(adminInfo);
                break;
            case 2:
                site_management(adminInfo);
                break;
            case 3:
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

void reserve_management(AdminInfo * adminInfo){
    int n = 0;
    reserve_management_menu();
    while((n = _get_int())!=3){
        switch(n){
            case 1:
                adm_show_orders(adminInfo);
                break;
            case 2:
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
void count_order(AdminInfo * adminInfo){
    int n = 0;
    count_order_menu();
    while((n = _get_int())!=7){
        switch(n){
            case 1:
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_site_order_down);
                show_adm_site(adminInfo);
                break;
            case 2:
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_site_profit_down);
                show_adm_site(adminInfo);
                break;
            case 3:
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_site_untilize_down);
                show_adm_site(adminInfo);
                break;
            case 4:
                printf("The total turnover is %.2lf.\n",get_venue_profit(adminInfo));
                show_adm_site(adminInfo);
                break;
            case 5:
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_female_sport);
                printf("the most popular sport in female: %s\n",adminInfo->site_info[0]->sport);
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_male_sport);
                printf("the most popular sport in male: %s\n",adminInfo->site_info[0]->sport);
                break;
            case 6:
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

void site_management(AdminInfo * adminInfo){
    int n;
    site_management_menu();
    while((n = _get_int())!=3){
        switch(n){
            case 1:
                adm_show_site(adminInfo);
                break;
            case 2:
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

void Register(){
    int n;
    register_menu();
    while((n = _get_int())!=3){
        switch(n){
            case 1:
                RegisterCostumer();
                break;
            case 2:
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

void inter_search(CustomerInfo * cus){
    int n;
    SiteInfo * siteInfo;
    char s[40];
    search_menu();
    while((n = _get_int())!=4){
        switch(n){
            case 1:
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
            case 2:
                inter_category_search(cus);
                break;
            case 3:
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
void inter_category_search(CustomerInfo * cus){
    int n,flag = 0;
    char s[40];
    AdminInfo * adminInfo;
    category_menu();
    while((n = _get_int())!=4){
        switch(n){
            case 1:
                printf("Please enter the Venue name to search:\n");
                scanf("%s",s);
                getchar();
                if((adminInfo = search_venue_name(s))==NULL){
                    printf("we don't have this venue\n");
                }else{
                    adm_show_site(adminInfo);
                    printf("Do you want to reserve?(y/n)\n");
                    if(get_choice()=='y'){
                        RegisterRent(cus);
                    }
                }
                break;
            case 2:
                flag = 0;
                printf("Please enter the Sport name to search:\n");
                scanf("%s",s);
                getchar();
                for(int i= 0;i<site_size;i++){
                    if(strcmp(site[i]->sport,s)==0){
                        flag = 1;
                        printf("\nSite Info:\n");
                        printf("ID\t\tvenue name\tregion\tsport\tenter age\trent\tintroduction\n");
                        printf("%s\t%s\t%s\t%s\t%d\t\t\t%.2f\t%s\n",site[i]->ID,site[i]->admin_info->venue_name,site[i]->region,site[i]->sport,
                               site[i]->enter_age,site[i]->rent,site[i]->intro);
                    }
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
            case 3:
                flag = 0;
                printf("Please enter the Region name to search:\n");
                scanf("%s",s);
                getchar();
                for(int i = 0;i<site_size;i++){
                    if(strcmp(site[i]->region,s)==0){
                        flag = 1;
                        printf("\nSite Info:\n");
                        printf("ID\t\tvenue name\tregion\tsport\tenter age\trent\tintroduction\n");
                        printf("%s\t%s\t%s\t%s\t%d\t\t\t%.2f\t%s\n",site[i]->ID,site[i]->admin_info->venue_name,site[i]->region,site[i]->sport,
                               site[i]->enter_age,site[i]->rent,site[i]->intro);
                    }
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
void inter_sort_search(){
    int n;
    sort_menu();
    scanf("%d",&n);
    getchar();
    while((n!=5)){
        switch(n){
            case 1:
                qsort(site,site_size,sizeof(SiteInfo *),_comp_site_rent_up);
                show_site();
                break;
            case 2:
                qsort(site,site_size,sizeof(SiteInfo *),_comp_site_rent_down);
                show_site();
                break;
            case 3:
                qsort(site,site_size,sizeof(SiteInfo *),_comp_site_order_up);
                show_site();
                break;
            case 4:
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
