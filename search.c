#include "gym.h"

CustomerInfo * search_cus_ID(char * ID){
    for(int i = 0;i<cus_size;i++){
        if(strcmp(ID,(customer[i])->ID)==0)
            return customer[i];
    }
    return NULL;
}
AdminInfo * search_adm_ID(char * ID){
    for(int i = 0;i<adm_size;i++){
        if(strcmp(ID,(admin[i])->ID)==0){
            return admin[i];
        }
    }
    return NULL;
}
RentalInfo * search_rent_ID(char * ID){
    for(int i = 0;i<rent_size;i++){
        if(strcmp(ID,(rent[i])->Appoint_ID)==0){
            return rent[i];
        }
    }
    return NULL;
}
SiteInfo * search_site_ID(char * ID){
    for(int i = 0;i<site_size;i++){
        if(strcmp(ID,(site[i])->ID)==0){
            return site[i];
        }
    }
    return NULL;
}
