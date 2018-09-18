#include "gym.h"

int _comp_cus_age_down(const void *a,const void *b){
    return (*((CustomerInfo**)b))->age - (*((CustomerInfo**)a))->age;
}
int _comp_cus_age_up(const void *a,const void *b){
    return (*((CustomerInfo**)a))->age - (*((CustomerInfo**)b))->age;
}
int _comp_site_rent_down(const void *a,const void *b){
    return ((*((SiteInfo**)b))->rent - (*((SiteInfo**)a))->rent>0)? 1:-1;
}
int _comp_site_rent_up(const void *a,const void *b){
    return ((*((SiteInfo**)b))->rent - (*((SiteInfo**)a))->rent>0)? -1:1;
}
int _comp_site_order_down(const void *a,const void *b){
    return (*((SiteInfo**)b))->order_num - (*((SiteInfo**)a))->order_num;
}
int _comp_site_order_up(const void *a,const void *b){
    return (*((SiteInfo**)a))->order_num - (*((SiteInfo**)b))->order_num;
}
int _comp_site_profit_down(const void *a,const void *b){
    return ((*((SiteInfo**)b))->total_profit - (*((SiteInfo**)a))->total_profit>0)? 1:-1;
}
int _comp_site_profit_up(const void *a,const void *b){
    return ((*((SiteInfo**)b))->total_profit - (*((SiteInfo**)a))->total_profit>0)? -1:1;
}
int _comp_site_untilize_down(const void *a,const void *b){
    return _get_utilize_rate((*(SiteInfo**)b)) - _get_utilize_rate((*((SiteInfo**)a)))>0 ? 1:-1;
}
int _comp_site_untilize_up(const void *a,const void *b){
    return _get_utilize_rate((*(SiteInfo**)b)) - _get_utilize_rate((*((SiteInfo**)a)))>0 ? -1:1;
}
int _comp_female_sport(const void *a,const void *b){
    return get_female_sport_num(*(SiteInfo**)b) - get_female_sport_num(*(SiteInfo**)a)>0 ? 1:-1;
}
int _comp_male_sport(const void *a,const void *b){
    return get_male_sport_num(*(SiteInfo**)b) - get_male_sport_num(*(SiteInfo**)a)>0 ? -1:1;
}