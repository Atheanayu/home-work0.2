/* 版权说明：
 * 1. 版权归本小组（余涵 夏雨琴 池晓威 康凯 张睿毅）所有
 * 2. 只能用于学习和参考使用
 * 3. 使用本品需经本小组全体成员同意，违者必究
 *
 * 版本号：2.0
 *
 * 生成日期：2018.9.18
 *
 * 作者：夏雨琴 池晓威 康凯 余涵
 *
 * 内容：该文件定义的函数是用于各种检查，保证用户友好
 * */
#include "gym.h"

/* 函数功能：获得一个int类型数，如果不是int类型，会报错，并要求重新输入
 * 传入参数：void
 * 返回值：获得的int类型数
 * 调用关系：无
 * 作者：康凯
 * */
int _get_int (void)
{
    int input;
    char ch;
    while (scanf ("%d", &input) != 1)
    {
        while ((ch = (char)getchar()) != '\n')
            putchar(ch);
        printf (" is not an integer.\nPlease enter an integer:\n");
    }
    getchar();
    return input;
}
/* 函数功能：获得一个char 类型数，y或者n，即使是yes，或者no，这里也是可以解决的
 * 传入参数：void
 * 返回值：获得的char 类型数
 * 调用关系：调用了 get_first 获得一个字符串的首字母
 * 作者：康凯
 * */
char get_choice(void)
{
    char ch;
    ch = get_first();
    while (ch != 'y' && ch != 'n')
    {
        printf ("Please respond with y or n.\n");
        ch = get_first();
    }
    return ch;
}
/* 函数功能：获得一个字符串的首字母
 * 传入参数：void
 * 返回值：获得的 char 类型数
 * 调用关系：无
 * 作者：康凯
 * */
char get_first (void)
{
    char ch;
    char * s;
    ch = (char)getchar();
    fgets(s,100,stdin);
//    getchar();
    return ch;
}
/* 函数功能：检查电话号码是否是11位的
 * 传入参数：电话号码
 * 返回值：判断电话号码位数是否合理，合理返回0，不合理返回-1
 * 调用关系：无
 * 作者：夏雨琴
 * */
int _check_phone(char * phone_num)
{
    if(strlen(phone_num)!=11)
    {
        printf("the phone number has to be 11\n");
        return -1;
    }
    for(int i = 0;i<11;i++)
    {
        if(!isdigit(phone_num[i]))
        {
            printf("phone num should be made up with number\n");
            return -1;
        }
    }
    return 0;
}
/* 函数功能：检查密码是否是字母与数字的组合，检查是否是6到12位
 * 传入参数：密码
 * 返回值：判断密码是否合理，合理返回0，不合理返回-1
 * 调用关系：无
 * 作者：夏雨琴
 * */
int _check_password(char * password)
{
    int is_num=0,is_alpha=0,is_other = 0;
    if(strlen(password)<6)
    {
        printf("for your security,your key has to be more than 6 words\n");
        return -1;
    }
    for(int i = 0;i<strlen(password);i++)
    {
        if(isalpha(password[i]))
        {
            is_alpha = 1;
        }else if(isdigit(password[i]))
        {
            is_num = 1;
        }else
            is_other = 1;
    }
    if((!(is_alpha && is_num)) || is_other){
        printf("sorry, your password should be consist of alpha and num\n");
        return -1;
    }
    return 0;
}
/* 函数功能：检查ID是否是字母与数字的组合，检查是否是6到12位
 * 传入参数：ID
 * 返回值：判断ID是否合理，合理返回0，不合理返回-1
 * 调用关系：无
 * 作者：夏雨琴
 * */
int _check_ID(char * ID)
{
    int is_num=0,is_alpha=0,is_other=0;
    if(strlen(ID)<6 || strlen(ID)>10)
    {
        printf("sorry, your ID should be more than 6 words ,less than 10 words\n");
        return -1;
    }
    for(int i = 0;i<strlen(ID);i++)
    {
        if(isalpha(ID[i]))
        {
            is_alpha = 1;
        }else if(isdigit(ID[i]))
        {
            is_num = 1;
        } else
        {
            is_other = 1;
        }
    }
    if((!(is_alpha && is_num))||is_other){
        printf("sorry, your ID should be consist of alpha and num\n");
        return -1;
    }
    return 0;
}
/* 函数功能：检查mail是否符合xxx@xx.xx的形式
 * 传入参数：邮箱
 * 返回值：判断mail是否合理，合理返回0，不合理返回-1
 * 调用关系：无
 * 作者：夏雨琴
 * */
int _check_mail(char * mail)
{
    int at_flag = 0,dot_flag = 0;
    for(int i = 0;i<strlen(mail);i++)
    {
        if(mail[i]=='@')
        {
            if(dot_flag == 1)
            {
                printf("sorry, your mail mode is not right\n");
                return -1;
            }
            if(at_flag == 0)
                at_flag = 1;
            else
            {
                printf("sorry, your mail mode is not right\n");
                return -1;
            }
        }else if(mail[i]=='.')
        {
            if(at_flag != 1)
            {
                printf("sorry, your mail mode is not right\n");
                return -1;
            }
            if(dot_flag == 0)
                dot_flag = 1;
            else
            {
                printf("sorry, your mail mode is not right\n");
                return -1;
            }
        }else if(!isdigit(mail[i]) && !isalpha(mail[i]))
        {
            printf("sorry, your mail mode is not right\n");
            return -1;
        }
    }
    if(!at_flag) return -1;
    if(!dot_flag) return -1;
    return 0;
}
/* 函数功能：检查是否超过24小时
 * 传入参数：开始日期
 * 返回值：判断是否超过24小时，超过返回0，未超过返回-1
 * 调用关系：调用了 get_cur_time 函数，获得当前时间
 * 作者：池晓威
 * */
int _check_24_hour(int* startdate)
{
    int cur_time[5];
    get_cur_time(cur_time);
    if(startdate[0]>cur_time[0]) return 0;
    if(startdate[0]<cur_time[0]) return -1;
    if(startdate[1]>cur_time[1]) return 0;
    if(startdate[1]<cur_time[1]) return -1;
    if (startdate[2] > cur_time[2]) return 0;
    else return -1;
}
/* 函数功能：检查是否超过7天
 * 传入参数：开始日期
 * 返回值：判断是否超过7天，超时返回0，未超时返回-1
 * 调用关系：调用 get_cur_time 函数，获得当前时间
 * 作者：池晓威
 * */
int _check_7_day(int * startdate)
{
    int len;
    int cur_time[5];
    get_cur_time(cur_time);
    len = (startdate[0]-cur_time[0])*365+(startdate[1]-cur_time[1])*30+startdate[2]-cur_time[2];
    return (len>7)? 0:-1;

}
/* 函数功能：检查时间输入模式是否正确
 * 传入参数：用户输入的时间字符串
 * 返回值：判断这个字符串格式是否正确，正确返回0，错误返回-1
 * 调用关系：无
 * 作者：余涵
 * */
int _check_time_mode(char * time)
{
    int num = 0;
    for(int i = 0;i<strlen(time);i++)
    {
        if(time[i]==':')
            num++;
        else if(time[i]>'9' || time[i]<'0')
            return -1;
    }
    if(num!=1)
        return -1;
    return 0;
}
/* 函数功能：检查这个ID是否已经被占用
 * 传入参数：用户输入的ID
 * 返回值：判断这个ID是否已经被用过，被用过返回1，没有返回0
 * 调用关系：无
 * 作者：夏雨琴
 * */
int _recheck_cusID(char ID[])
{/* to see that if there is the same ID */
    int i;
    for(i=0;i<cus_size;i++)
    {
        if(strcmp(ID,customer[i]->ID)==0)
        {
            printf("sorry this ID has been used\n");
            return 1;
        }
    }
    return 0;
}
/* 函数功能：检查这个ID是否已经被占用
 * 传入参数：用户输入的ID
 * 返回值：判断这份ID是否已经被用过了，被用过返回1，没有返回0
 * 调用关系：无
 * 作者：夏雨晴
 * */
int _recheck_admID(char ID[])
{
    int i;
    for(i=0;i<adm_size;i++)
    {
        if(strcmp(ID,admin[i]->ID)==0)
        {
            printf("sorry this ID has been used\n");
            return 1;
        }
    }
    return 0;
}
/* 函数功能：检查这个年龄是否是可能的年龄
 * 传入参数：用户输入的年龄
 * 返回值：判断这个年龄是否是可能的，可能返回1，否则返回0
 * 调用关系：无
 * 作者：夏雨琴
 * */
int _check_age(int age)
{/* to see that if the age is possible */
    if(age<=0||age>=100)
    {
        printf("请输入合法年龄");
        return 0;}
    else
        return 1;
}
/* 函数功能：检查这个场馆名称是否已经被占用
 * 传入参数：管理输入的场馆名
 * 返回值：名称被占用返回0，没有被占用返回1
 * 调用关系：无
 * 作者：夏雨琴
 * */
int _check_venue_name(char venue_name[])
{/* to see that if there are different venue have same name */
    int i;
    for(i=0;i<adm_size;i++)
    {
        if(strcmp(venue_name,admin[i]->venue_name)==0)
        {
            printf("sorry this name has been used\n");
            return 0;
        }
    }
    return 1;
}
/* 函数功能：检查这个场地ID是否已经被占用
 * 传入参数：ID
 * 返回值：判断是否被占用，占用 1，没占用 0
 * 调用关系：无
 * 作者：夏雨琴
 * */
int _recheck_sitID(char ID[])
{
    int i;
    for(i=0;i<site_size;i++)
    {
        if(strcmp(ID,site[i]->ID)==0)
        {
            printf("sorry this ID has been used\n");
            return 1;
        }
    }
    return 0;
}
/* 函数功能：检查这种运动场地之前是否存在
 * 传入参数：运动名称
 * 返回值：判断存在，存在则返回一个同类型场地，否在返回NULL
 * 调用关系：无
 * 作者：夏雨琴
 * */
SiteInfo * _recheck_site_sport(char * sport)
{
    for(int i= 0;i<site_size;i++)
    {
        if(strcmp(sport,site[i]->sport)==0)
            return site[i];
    }
    return NULL;
}
/* 函数功能：在开头一个单词一个单词的打印
 * 传入参数：void
 * 返回值：void
 * 调用关系：无
 * 注：这个使用的是非标准库函数，只能在unix系统下运行
 * 作者：余涵
 * */
//void welcome(){
//    char arr[100] = {"welcome to our system, your satisfaction is the goal we pursue\n "};
//    char temp[30];
//    int j= 0,i;
//    for(i = 0;i<strlen(arr);i++){
//        temp[j] = arr[i];
//        j++;
//        if(arr[i]==' '){
//            temp[j+1] = '\0';
//            write(STDOUT_FILENO,temp,(size_t)j);
//            sleep(1);
//            j = 0;
//        }
//    }
//}