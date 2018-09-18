#include "gym.h"

float _get_utilize_rate(SiteInfo * siteInfo){
    int time[5];
    int time_len=0,total_time_len;
    for(int i = 0;i<siteInfo->rent_info_len;i++){
        time_len +=(siteInfo->rent_info[i]->end_time[0]-siteInfo->rent_info[i]->start_time[0]);
        if(siteInfo->rent_info[i]->start_time[1]<siteInfo->rent_info[i]->end_time[1])
            time_len += 1;
    }
    get_cur_time(time);
    total_time_len = (time[0]-start_time[0])*365*16+(time[1]-start_time[1])*30*16+(time[2]-start_time[2])*16+time[1]-start_time[1];
    return (float)time_len/(float)total_time_len;

}
void get_cur_time(int * cur_time){
    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);
    cur_time[0] = p->tm_year+1900;
    cur_time[1] = p->tm_mon+1;
    cur_time[2] = p->tm_mday;
    cur_time[3] = p->tm_hour+8;
    cur_time[4] = p->tm_min;
}

double get_venue_profit(AdminInfo * adminInfo){
    double profit = 0.00;
    for(int i = 0;i<adminInfo->site_info_len;i++){
        profit += adminInfo->site_info[i]->total_profit;
    }
    return profit;
}

int get_female_sport_num(SiteInfo * siteInfo){
    int num = 0;
    for(int i = 0;i< siteInfo->rent_info_len;i++){
        if(strcmp(siteInfo->rent_info[i]->gender,"female")==0){
            num ++;
        }
    }
    return num;
}
int get_male_sport_num(SiteInfo * siteInfo){
    int num = 0;
    for(int i = 0;i< siteInfo->rent_info_len;i++){
        if(strcmp(siteInfo->rent_info[i]->gender,"male")==0){
            num ++;
        }
    }
    return num;
}

void analyse_age(AdminInfo * adminInfo){
    int n;
    int age[3] = {0,0,0};
    for(int j = 0;j<adminInfo->site_info_len;j++){
        for(int i = 0;i<adminInfo->site_info[j]->rent_info_len;i++){
            if((n =adminInfo->site_info[j]->rent_info[i]->age)<20)
                age[0]++;
            else if(n >40)
                age[2]++;
            else
                age[1]++;
        }
        printf("%s:\t0~20:%d\t20~40:%d\t40~:%d\n",adminInfo->site_info[j]->sport,age[0],age[1],age[2]);
        age[0] = age[1] = age[2] = 0;
    }
}
int _get_time_len(int * starttime,int * endtime){
    int len = endtime[0]-starttime[0];
    if(starttime[1]<endtime[1])
        len ++;
    return len;
}