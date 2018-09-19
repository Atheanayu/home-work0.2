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
 * 内容：该文件中定义的函数用于找到相应的结构体指针
 * */
#include "gym.h"
/* 函数功能：通过ID查找顾客
 * 传入参数：客户ID
 * 返回值：客户指针，如果没有找到，返回NULL
 * 调用关系：无
 * 作者：康凯
 * */
CustomerInfo * search_cus_ID(char * ID)
{
    for(int i = 0;i<cus_size;i++)
        if(strcmp(ID,(customer[i])->ID)==0)
            return customer[i];
    return NULL;
}
/* 函数功能：通过ID查找管理员
 * 传入参数：管理员ID
 * 返回值：管理员指针，如果没有找到，返回NULL
 * 调用关系：无
 * 作者：康凯
 * */
AdminInfo * search_adm_ID(char * ID)
{
    for(int i = 0;i<adm_size;i++)
        if(strcmp(ID,(admin[i])->ID)==0)
            return admin[i];
    return NULL;
}
/* 函数功能：通过名字查找场馆
 * 传入参数：场馆名称
 * 返回值：管理员指针，如果没有找到，返回NULL
 * 调用关系：无
 * 作者：康凯
 * */
AdminInfo * search_venue_name(char * name){
    for(int i = 0;i<adm_size;i++)
        if(strcmp(name,(admin[i])->venue_name)==0)
            return admin[i];
    return NULL;
}
/* 函数功能：通过ID查找订单信息
 * 传入参数：订单ID
 * 返回值：订单指针，如果没有找到，返回NULL
 * 调用关系：无
 * 作者：康凯
 * */
RentalInfo * search_rent_ID(char * ID){
    for(int i = 0;i<rent_size;i++){
        if(strcmp(ID,(rent[i])->Appoint_ID)==0){
            return rent[i];
        }
    }
    return NULL;
}
/* 函数功能：通过ID查找场地信息
 * 传入参数：场地ID
 * 返回值：场地指针，如果没有找到，返回NULL
 * 调用关系：无
 * 作者：康凯
 * */
SiteInfo * search_site_ID(char * ID){
    for(int i = 0;i<site_size;i++){
        if(strcmp(ID,(site[i])->ID)==0){
            return site[i];
        }
    }
    return NULL;
}
