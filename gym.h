/* 版权说明：
 * 1. 版权归本小组（余涵 夏雨琴 池晓威 康凯 张睿毅）所有
 * 2. 只能用于学习和参考使用
 * 3. 使用本品需经本小组全体成员同意，违者必究
 *
 * 版本号：2.0
 *
 * 生成日期：2018.9.18
 *
 * 作者：余涵 夏雨琴 池晓威 康凯 张睿毅
 *
 * 内容：该文件为程序的头文件部分，声明了程序所用到的函数、宏、变量
 * */
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define FILE_COS_PATH "CustomerInfo.txt"
#define FILE_ADM_PATH "AdminInfo.txt"
#define FILE_RENT_PATH "RentalInfo.txt"
#define FILE_SITE_PATH "SiteInfo.txt"

#define ID_LEN 40
#define NAME_LEN 20
#define PHONE_NUM_LEN 12
#define KEY_LEN 20
#define MAIL_ADDRESS_LEN 20
#define TIME_LEN 20
#define INTRO_LEN 300

#define RENT_INFO_LEN 20
#define SITE_INFO_LEN 20
#define CUS_INFO_LEN 20

#define CUS_LEN 40
#define ADM_LEN 40
#define RENT_LEN 40
#define SITE_LEN 40

#define VENUE_NAME_LEN 20
#define SEX_LEN 10
#define REGION_LEN 20
#define SPORT_LEN 20

extern int cus_size;
extern int adm_size;
extern int rent_size;
extern int site_size;

/* 存储客户信息 */
typedef struct CustomerInfo
{
    struct RentalInfo * (*rent_info);/* 该客户的所有订单 */
    char ID[ID_LEN];/* 该客户ID */
    char name[NAME_LEN];/* 客户名字 */
    char phone_num[PHONE_NUM_LEN];/* 客户电话 */
    char key[KEY_LEN];/* 登陆密码 */
    char e_mail[MAIL_ADDRESS_LEN];/* 客户电邮 */
    char sex[SEX_LEN];/* 客户性别 */
    char region[REGION_LEN];/* 客户所在地区 */
    double balance;/* 余额 */
    int age;/* 年龄*/
    int default_num;/* 爽约次数 */
    int rent_info_len;/* 该客户订单信息个数 */
}CustomerInfo;

/* 存储管理员信息 */
typedef struct AdminInfo
{
    struct SiteInfo * (*site_info);/* 该管理员管理的所有场地 */
    char ID[ID_LEN];/* 管理员ID */
    char name[NAME_LEN];/* 管理员名字 */
    char venue_name[VENUE_NAME_LEN];/* 管理员所管理的场馆名称 */
    char key[KEY_LEN];/* 登陆密码*/
    char e_mail[MAIL_ADDRESS_LEN];/* 管理员电邮 */
    char sex[SEX_LEN];/* 性别 */
    char phone_num[PHONE_NUM_LEN];/* 电话号码 */
    int site_info_len;/* 该管理员管理的场地个数 */
}AdminInfo;

/* 存储订单信息 */
typedef struct RentalInfo
{
    struct CustomerInfo * cus_info;/* 订单的客户 */
    struct SiteInfo * site_info;/* 订单的场地 */
    char Appoint_ID[ID_LEN];/* 订单ID */
    int start_time[2];/* 开始时间 */
    int end_time[2];/* 结束时间 */
    int appoint_time[5];/* 预约的时间 */
    int start_date[3];/* 订单的日期 */
    double price;/* 花的价钱 */
    int is_intime;/* 是否即使到场 */
    char gender[SEX_LEN];/* 客户性别*/
    int age;/* 客户年龄*/
    int is_complete;/* 该订单的完成情况，-1 取消状态，0 未完成状态，1 已完成状态 */
}RentalInfo;

/* 场地信息 */
typedef struct SiteInfo
{
    struct RentalInfo * (*rent_info);/* 预约该场地的所有订单 */
    struct AdminInfo * admin_info;/* 管理该场地的管理员 */
    char ID[ID_LEN];/* 场地ID */
    char region[REGION_LEN];/* 所在地区 */
    char sport[SPORT_LEN];/* 什么运动场 */
    char intro[INTRO_LEN];/* 有关这个运动的介绍 */
    int enter_age;/* 准入年龄 */
    double rent;/* 按小时收费的租金 */
    double total_profit;/* 总利润 */
    int order_num;/* 预定数量 */
    int rent_info_len;/* 该场地的所有订单数量 */
}SiteInfo;

/* 声明指针数组  */
extern CustomerInfo ** customer;
extern AdminInfo ** admin;
extern SiteInfo ** site;
extern RentalInfo ** rent;

//void welcome();
/* 开业时间 */
static int start_time[5]={2018,9,10,0,0};

/* 三个底层的函数，用于构建起该程序所用的数据结构 */
void _arr_init();/* 从文件中读取数据，为数组赋值，建立，结构体之间的互相指向的关系 */
void _write_to_file();/* 将数组中的值重新写回到文件当中 */
void free_all();/* 将先前分配的内存空间free掉 */

/* 查找函数 */
CustomerInfo * search_cus_ID(char * ID);/* 通过ID查找顾客 */
AdminInfo * search_adm_ID(char * ID);/* 通过ID查找管理员 */
RentalInfo * search_rent_ID(char * ID);/* 通过ID查找订单 */
SiteInfo * search_site_ID(char * ID);/* 通过ID查找场地 */
AdminInfo * search_venue_name(char * name);/* 通过场馆名称查找管理员 */

/* 排序时候的比较依据 */
int _comp_cus_age_down(const void *,const void *);
int _comp_cus_age_up(const void *a,const void *b);
int _comp_site_rent_down(const void *a,const void *b);
int _comp_site_rent_up(const void *a,const void *b);
int _comp_site_order_down(const void *a,const void *b);
int _comp_site_order_up(const void *a,const void *b);
int _comp_site_profit_down(const void *a,const void *b);
int _comp_site_profit_up(const void *a,const void *b);
int _comp_site_untilize_down(const void *a,const void *b);
int _comp_site_untilize_up(const void *a,const void *b);
int _comp_female_sport(const void *a,const void *b);
int _comp_male_sport(const void *a,const void *b);

/* 菜单 */
void main_menu(void);
void user_func_menu(void);
void adm_func_menu(void);
void reserve_management_menu(void);
void count_order_menu(void);
void site_management_menu();
void cos_modify_menu();
void adm_modify_menu();
void register_menu();
void search_menu(void);
void category_menu(void);
void sort_menu(void);

/* 一些用户友好的操作 */
int _get_int (void);/* 获得一个int类型的数据，如果不是int，会警告，并重新读 */
int _check_phone(char * phone_num);/* 确保电话号码是11位 */
int _check_password(char * password);/* 保证密码是数字和字母的组合，并大于等于6位，小于等于12位 */
int _check_ID(char * ID);/* 确保ID是数字和字母的组合，并大于等于6位，小于等于12位 */
int _check_mail(char * mail);/* 确保邮箱的形式： xxxx@xx.xxx */
int _check_24_hour(int* startdate);/* 判断传入的时间和当前时间相差是否超过24h */
int _recheck_cusID(char ID[]);/* 判断这个ID是否被用过*/
int _check_age(int age);/* 判断这个年龄是否是可能的 */
int _recheck_admID(char ID[]);/* 判断这个ID是否被用过 */
int _check_venue_name(char venue_name[]);/* 判断这个名字是否被用过*/
int _recheck_sitID(char ID[]);/* 判断这个ID是否被用过 */
SiteInfo * _recheck_site_sport(char * sport);/* 判断这是否是一项新的运动 */
int _check_7_day(int * startdate);/* 判断当前时间和传入的时间是否相差超过7天 */
int _check_time_mode(char * time);/* 判断用户输入的时间是否是正确的格式 */
char get_choice(void);/* 判断这个选择是否是可能的 */
char get_first (void);/* 得到一个字符串的第一个字符 */

/* 与菜单中的选项相关的一些函数 */
CustomerInfo * Login_user();/* 顾客登陆 */
AdminInfo * Login_adm();/* 管理员登陆 */
int revise_customer_info(CustomerInfo * cos);/* 修改顾客信息 */
int revise_admin_info(AdminInfo * adm);/* 修改管理员信息 */
void cus_show_orders(CustomerInfo * cos);/* 展示顾客的所有订单 */
void adm_show_orders(AdminInfo * adm);/* 展示管理员管理的所有订单 */
void adm_show_site(AdminInfo * adm);/* 展示管理员管理的所有场地 */
void show_site();/* 展示所有的场地 */
void show_adm_site(AdminInfo * adm);/* 展示管理员管理的所有场地 */
int cancel_order(CustomerInfo *cus);/* 取消订单 */

/* 数据统计 */
float _get_utilize_rate(SiteInfo * siteInfo);/* 获得时间占用率 */
void get_cur_time(int * cur_time);/* 获得当前时间 */
double get_venue_profit(AdminInfo * adminInfo);/* 获得场馆的所有利润 */
int get_female_sport_num(SiteInfo * siteInfo);/* 获得这项运动中女性参与的人数 */
int get_male_sport_num(SiteInfo * siteInfo);/* 获得这项运动中男性参与的人数 */
void analyse_age(AdminInfo * adminInfo);/* 分析不同年龄层的人数问题 */
int _get_time_len(int * starttime,int * endtime);/* 获得时间差 */


/* 扩容函数 */
void _increase_adm_room();
void _increase_cus_room();
void _increase_site_room();
void _increase_rent_room();
void _increase_adm_site_room(AdminInfo * adm);
void _increase_site_rent_room(SiteInfo * siteInfo);
void _increase_cus_rent_room(CustomerInfo * cus);

/* 用户交互相关函数 */
void inter_main();/* 主交互函数 */
void inter_cus_login(CustomerInfo * customerInfo);/* 顾客入口 */
void inter_adm_login(AdminInfo * adminInfo);/* 管理员入口 */
void reserve_management(AdminInfo * adminInfo);/* 关于订单的一些操作 */
void count_order(AdminInfo * adminInfo);/* 处理订单相关的计算 */
void site_management(AdminInfo * adminInfo);/* 管理场地相关 */
void Register();/* 注册 */
void inter_category_search(CustomerInfo * cus);/* 分类查找 */
void inter_search(CustomerInfo * cus);/* 查找 */
void inter_sort_search();/* 获得排序好的数据 */

/* 为结构体数组增加元素 */
void RegisterCostumer();/* 顾客注册 */
void RegisterAdmin();/* 管理员组册 */
void RegisterSite(AdminInfo * adm);/* 新增场地 */
void RegisterRent(CustomerInfo * cus);/* 预约 */
