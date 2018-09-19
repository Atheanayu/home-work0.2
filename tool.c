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
 * 内容：该文件提供了排序的规则
 * */

#include "gym.h"

int _comp_cus_age_down(const void *a,const void *b){/* 客户按年龄排序从上到下排序 */
    return (*((CustomerInfo**)b))->age - (*((CustomerInfo**)a))->age;
}
int _comp_cus_age_up(const void *a,const void *b){/* 客户按年龄从下到上排序 */
    return (*((CustomerInfo**)a))->age - (*((CustomerInfo**)b))->age;
}
int _comp_site_rent_down(const void *a,const void *b){/* 场地按租金从上到下排序 */
    return ((*((SiteInfo**)b))->rent - (*((SiteInfo**)a))->rent>0)? 1:-1;
}
int _comp_site_rent_up(const void *a,const void *b){/* 场地按租金从下到上排序 */
    return ((*((SiteInfo**)b))->rent - (*((SiteInfo**)a))->rent>0)? -1:1;
}
int _comp_site_order_down(const void *a,const void *b){/* 场地按订单数从上到下排序 */
    return (*((SiteInfo**)b))->order_num - (*((SiteInfo**)a))->order_num;
}
int _comp_site_order_up(const void *a,const void *b){/* 场地按订单数从下到上排序 */
    return (*((SiteInfo**)a))->order_num - (*((SiteInfo**)b))->order_num;
}
int _comp_site_profit_down(const void *a,const void *b){/* 场地按场地的利润从上到下排序 */
    return ((*((SiteInfo**)b))->total_profit - (*((SiteInfo**)a))->total_profit>0)? 1:-1;
}
int _comp_site_profit_up(const void *a,const void *b){/* 场地按利润从下到上排序 */
    return ((*((SiteInfo**)b))->total_profit - (*((SiteInfo**)a))->total_profit>0)? -1:1;
}
int _comp_site_untilize_down(const void *a,const void *b){/* 场地按时间占用率从上到下排序 */
    return _get_utilize_rate((*(SiteInfo**)b)) - _get_utilize_rate((*((SiteInfo**)a)))>0 ? 1:-1;
}
int _comp_site_untilize_up(const void *a,const void *b){/* 场地按时间占用率从下到上排序 */
    return _get_utilize_rate((*(SiteInfo**)b)) - _get_utilize_rate((*((SiteInfo**)a)))>0 ? -1:1;
}
int _comp_female_sport(const void *a,const void *b){/* 场地按女性预定人数从上到下排序 */
    return get_female_sport_num(*(SiteInfo**)b) - get_female_sport_num(*(SiteInfo**)a)>0 ? 1:-1;
}
int _comp_male_sport(const void *a,const void *b){/* 场地按男性预定人数从上到下排序 */
    return get_male_sport_num(*(SiteInfo**)b) - get_male_sport_num(*(SiteInfo**)a)>0 ? 1:-1;
}