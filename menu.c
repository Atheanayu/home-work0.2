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
 * 内容：该文件定义的函数用于打印菜单
 * */

#include "gym.h"

void main_menu(void)
{	   					//1
    printf("****** Integrated Gymnasium Management System *******\n");
    printf("*                1.  User login				        *\n");
    printf("*                2.  Administrator login            *\n");
    printf("*                3.  Register                       *\n");
    printf("*                4.  Exit                           *\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
void user_func_menu(void)
{					//1.1
    printf("******************* User Function *******************\n");
    printf("*                1.  Query and Reserve		        *\n");
    printf("*                2.  Modify personal information    *\n");
    printf("*                3.  View my order                  *\n");
    printf("*                4.  Cancel my order                *\n");
    printf("*                5.  Log off                        *\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
void adm_func_menu(void)
{					//1.2
    printf("************** Administrator Function ***************\n");
    printf("*                1.  Reserving management 		    *\n");
    printf("*                2.  Site management                *\n");
    printf("*                3.  Modify personal information    *\n");
    printf("*                4.  Log off                        *\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
void reserve_management_menu(void)
{                   //1.2.1
    printf("*************** Reserving Management ****************\n");
    printf("*                1.  Query historical order		    *\n");
    printf("*                2.  Count order                    *\n");
    printf("*                3.  Back to administrator function  *\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
void count_order_menu(void)
{	 					//1.2.1.2
    printf("******************* Count Order *********************\n");
    printf("*                1. Sort by quantity 				*\n");
    printf("*                2. Sort by turnover 				*\n");
    printf("*                3. Sort by utilize rate            *\n");
    printf("*                4. Count turnover   				*\n");
    printf("*                5. Count best liked sport			*\n");
    printf("*                6. Count distribution of user's age*\n");
    printf("*                7. Back to reserving management	*\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
void site_management_menu()
{						//1.2.2
    printf("***************** Site Management *******************\n");
    printf("*                1. Query all the sites 			*\n");
    printf("*                2. Add a new site 					*\n");
    printf("*                3. Back to reserving management	*\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
void cos_modify_menu()
{
    printf("***************** cos_modify ************************\n");
    printf("*                1. phone number        			*\n");
    printf("*                2. key         					*\n");
    printf("*                3. e_mail                       	*\n");
    printf("*                4. region                      	*\n");
    printf("*                5. back to main menu               *\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
void adm_modify_menu()
{
    printf("***************** adm_modify ************************\n");
    printf("*                1. phone number        			*\n");
    printf("*                2. key         					*\n");
    printf("*                3. e_mail                       	*\n");
    printf("*                4. back to main menu               *\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
void register_menu()
{						//1.3
    printf("********************* Register **********************\n");
    printf("*                1. User                 			*\n");
    printf("*                2. Administrator 					*\n");
    printf("*                3. Back to homepage             	*\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
void search_menu(void)
{
    printf("******************* SEARCH MODE *********************\n");
    printf("*                1.  BY Site ID				        *\n");
    printf("*                2.  BY CATEGORY                    *\n");
    printf("*                3.  SORT                           *\n");
    printf("*                4.  BACK TO HOMEPAGE               *\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
void category_menu(void)
{
    printf("******************** CATEGORY ***********************\n");
    printf("*                1.  VENUE					        *\n");
    printf("*                2.  SPORT			                *\n");
    printf("*                3.  REGION                         *\n");
    printf("*                4.  BACK TO SEARCH MODE            *\n");
    printf("*****************************************************\n");
    printf("Please choose the category: \n");
}
void book_venue_menu()
{
    printf("********************* VENUE *************************\n");
    printf("*                1.  CP_CENTER				        *\n");
    printf("*                2.  HD_CENTER                      *\n");
    printf("*                3.  CY_CENTER                      *\n");
    printf("*                4.  BACK TO CATEGORY               *\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
void book_sport_menu()
{
    printf("********************* SPORT *************************\n");
    printf("*                1.  SOCCER				            *\n");
    printf("*                2.  BASKETBALL                     *\n");
    printf("*                3.  BADMINTON                      *\n");
    printf("*                4.  BACK TO CATEGORY               *\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
void book_region_menu()
{
    printf("********************* REGION ************************\n");
    printf("*                1.  BEI_CP				            *\n");
    printf("*                2.  BEI_HD		                    *\n");
    printf("*                3.  BEI_CY                         *\n");
    printf("*                4.  BACK TO CATEGORY               *\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
void sort_menu(void)
{
    printf("********************** SORT *************************\n");
    printf("*                1.  RENT ↑				            *\n");
    printf("*                2.  RENT ↓                         *\n");
    printf("*                3.  QUANTITY↑                      *\n");
    printf("*                4.  QUANTITY↓                      *\n");
    printf("*                5.  BACK TO SEARCH MODE            *\n");
    printf("*****************************************************\n");
    printf("Please enter your choice: \n");
}
