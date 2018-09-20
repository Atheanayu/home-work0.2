#include "gym.h"
int cus_size= 0;
int adm_size= 0;
int rent_size= 0;
int site_size= 0;

CustomerInfo ** customer = NULL;
AdminInfo ** admin = NULL;
RentalInfo ** rent = NULL;
SiteInfo ** site = NULL;


int main()
{
//    welcome();
    customer = (CustomerInfo **)malloc(sizeof(CustomerInfo*)*CUS_LEN);
    admin = (AdminInfo **)malloc(sizeof(AdminInfo*)*ADM_LEN);
    rent = (RentalInfo **)malloc(sizeof(RentalInfo*)*RENT_LEN);
    site = (SiteInfo **)malloc(sizeof(SiteInfo*)*SITE_LEN);
    _arr_init();
    inter_main();
    _write_to_file();
    free_all();
    printf("Thank you very much for your trust and support .Your satisfaction is the goal we pursue.\n");
    return 0;
}