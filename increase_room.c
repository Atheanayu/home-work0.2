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
 * 内容：该文件的函数达到了为存储信息的容器扩容的目的
 * 实现方法：类似于java中的arrayList 的实现方法，通过将原数组中的内容复制到一个更大的数组来达到此目的
 * */

#include "gym.h"
/* increase the room of array admin */
void _increase_adm_room()
{
    int n = adm_size/ADM_LEN +1;
    AdminInfo ** a = (AdminInfo **)malloc(sizeof(AdminInfo)*n*ADM_LEN);
    for(int i = 0;i<adm_size;i++)
        a[i] = admin[i];
    admin = a;
}
/* increase the room of array customer */
void _increase_cus_room()
{
    int n = cus_size/CUS_LEN +1;
    CustomerInfo ** a = (CustomerInfo **)malloc(sizeof(CustomerInfo)*n*CUS_LEN);
    for(int i = 0;i<cus_size;i++)
        a[i] = customer[i];
    customer  = a;
}
/* increase the room of array site */
void _increase_site_room()
{
    int n = site_size/SITE_LEN +1;
    SiteInfo ** a = (SiteInfo **)malloc(sizeof(SiteInfo)*n*SITE_LEN);
    for(int i = 0;i<site_size;i++)
        a[i] = site[i];
    site = a;
}
/* increase the room of array rent */
void _increase_rent_room()
{
    int n = rent_size/RENT_LEN +1;
    RentalInfo ** a = (RentalInfo **)malloc(sizeof(RentalInfo)*n*RENT_LEN);
    for(int i = 0;i<rent_size;i++)
        a[i] = rent[i];
    rent = a;
}
/* increase the room of array site_info in struct adm */
void _increase_adm_site_room(AdminInfo * adm)
{
    int n = adm->site_info_len/SITE_INFO_LEN +1;
    SiteInfo ** b = (SiteInfo **)malloc(sizeof(SiteInfo)*n*SITE_INFO_LEN);
    for(int i = 0;i<adm->site_info_len;i++)
        b[i] = adm->site_info[i];
    adm->site_info = b;
}
/* increase the room of array rent_info in struct site */
void _increase_site_rent_room(SiteInfo * siteInfo)
{
    int n = siteInfo->rent_info_len/SITE_INFO_LEN +1;
    RentalInfo ** b = (RentalInfo **)malloc(sizeof(RentalInfo)*n*RENT_INFO_LEN);
    for(int i = 0;i<siteInfo->rent_info_len;i++)
        b[i] = siteInfo->rent_info[i];
    siteInfo->rent_info = b;
}
/* increase the room of array rent_info in struct customer */
void _increase_cus_rent_room(CustomerInfo * cus)
{
    int n = cus->rent_info_len/RENT_INFO_LEN +1;
    RentalInfo ** b = (RentalInfo **)malloc(sizeof(RentalInfo)*n*RENT_INFO_LEN);
    for(int i = 0;i<cus->rent_info_len;i++)
        b[i] = cus->rent_info[i];
    cus->rent_info = b;
}