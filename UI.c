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
    while((n = _get_int())!=4){
        switch(n){
            case 1:
                inter_search();
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
                printf("wrong choice\n");
                break;
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
                break;
            case 2:
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_site_profit_down);
                break;
            case 3:
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_site_untilize_down);
                break;
            case 4:
                printf("The total turnover is %.2lf.\n",get_venue_profit(adminInfo));
                break;
            case 5:
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_female_sport);
                printf("the most popular sport in female: %s",adminInfo->site_info[0]->sport);
                qsort(adminInfo->site_info,(size_t)adminInfo->site_info_len,sizeof(SiteInfo *),_comp_male_sport);
                printf("the most popular sport in male: %s",adminInfo->site_info[0]->sport);
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
    while((n = getchar())!=3){
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
    while((n = getchar())!=3){
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

void inter_search(){

}
