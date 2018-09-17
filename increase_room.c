#include "gym.h"

void _increase_adm_room(){
    int n = adm_size/ADM_LEN +1;
    AdminInfo ** a = (AdminInfo **)malloc(sizeof(AdminInfo)*n*ADM_LEN);
    for(int i = 0;i<adm_size;i++){
        a[i] = admin[i];
    }
    admin = a;
}

void _increase_cus_room(){
    int n = cus_size/CUS_LEN +1;
    CustomerInfo ** a = (CustomerInfo **)malloc(sizeof(CustomerInfo)*n*CUS_LEN);
    for(int i = 0;i<cus_size;i++){
        a[i] = customer[i];
    }
    customer  = a;
}

void _increase_site_room(){
    int n = site_size/SITE_LEN +1;
    SiteInfo ** a = (SiteInfo **)malloc(sizeof(SiteInfo)*n*SITE_LEN);
    for(int i = 0;i<site_size;i++){
        a[i] = site[i];
    }
    site = a;
}

void _increase_rent_room(){
    int n = rent_size/RENT_LEN +1;
    RentalInfo ** a = (RentalInfo **)malloc(sizeof(RentalInfo)*n*RENT_LEN);
    for(int i = 0;i<rent_size;i++){
        a[i] = rent[i];
    }
    rent = a;
}

void _increase_adm_site_room(AdminInfo * adm){
    int n = adm->site_info_len/SITE_INFO_LEN +1;
    SiteInfo ** b = (SiteInfo **)malloc(sizeof(SiteInfo)*n*SITE_INFO_LEN);
    for(int i = 0;i<adm->site_info_len;i++){
        b[i] = adm->site_info[i];
    }
    adm->site_info = b;
}

void _increase_site_rent_room(SiteInfo * siteInfo){
    int n = siteInfo->rent_info_len/SITE_INFO_LEN +1;
    RentalInfo ** b = (RentalInfo **)malloc(sizeof(RentalInfo)*n*RENT_INFO_LEN);
    for(int i = 0;i<siteInfo->rent_info_len;i++){
        b[i] = siteInfo->rent_info[i];
    }
    siteInfo->rent_info = b;
}

void _increase_cus_rent_room(CustomerInfo * cus){
    int n = cus->rent_info_len/RENT_INFO_LEN +1;
    RentalInfo ** b = (RentalInfo **)malloc(sizeof(RentalInfo)*n*RENT_INFO_LEN);
    for(int i = 0;i<cus->rent_info_len;i++){
        b[i] = cus->rent_info[i];
    }
    cus->rent_info = b;
}