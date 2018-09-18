#include "gym.h"
int cus_size= 0;
int adm_size= 0;
int rent_size= 0;
int site_size= 0;

CustomerInfo ** customer = NULL;
AdminInfo ** admin = NULL;
RentalInfo ** rent = NULL;
SiteInfo ** site = NULL;


int main() {
    customer = (CustomerInfo **)malloc(sizeof(CustomerInfo*)*CUS_LEN);
    admin = (AdminInfo **)malloc(sizeof(AdminInfo*)*ADM_LEN);
    rent = (RentalInfo **)malloc(sizeof(RentalInfo*)*RENT_LEN);
    site = (SiteInfo **)malloc(sizeof(SiteInfo*)*SITE_LEN);
    _arr_init();
    return 0;
}