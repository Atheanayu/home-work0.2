#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gym.h"


void _arr_init(){
    int p;
    size_t len;
    char c;
    char ID[40];
    char litter[40];
    FILE * fpc = fopen(FILE_COS_PATH,"r");
    FILE * fps = fopen(FILE_SITE_PATH,"r");
    FILE * fpa = fopen(FILE_ADM_PATH,"r");
    FILE * fpr = fopen(FILE_RENT_PATH,"r");
    for(int i = 0;fgetc(fpc)!=EOF;i++) {
        fgetc(fpc);
        customer[i] = (CustomerInfo*)malloc(sizeof(CustomerInfo));
        customer[i]->rent_info = (RentalInfo **)malloc(RENT_INFO_LEN * sizeof(RentalInfo*));
        fscanf(fpc,"rent_info:\n");
        while (fgetc(fpc) == '-') {
            fgets(litter, 100, fpc);
        }
        fgetc(fpc);
        fscanf(fpc,"ID:%s\n",(customer[i])->ID);
        fscanf(fpc,"name:%s\n",(customer[i])->name);
        fscanf(fpc,"phone_num:%s\n",(customer[i])->phone_num);
        fscanf(fpc,"key:%s\n",(customer[i])->key);
        fscanf(fpc,"e_mail:%s\n",(customer[i])->e_mail);
        fscanf(fpc,"sex:%s\n",(customer[i])->sex);
        fscanf(fpc,"region:%s\n",(customer[i])->region);
        fscanf(fpc,"balance:%lf\n",&((customer[i])->balance));
        fscanf(fpc,"age:%d\n",&((customer[i])->age));
        fscanf(fpc,"default_num:%d\n",&((customer[i])->default_num));
        fscanf(fpc,"rent_info_len:%d\n",&((customer[i])->rent_info_len));
        cus_size ++;
    }
    for(int i = 0;fgetc(fps)!=EOF;i++){
        fgetc(fps);
        site[i] = (SiteInfo *)malloc(sizeof(SiteInfo));
        site[i]->rent_info = (RentalInfo **)malloc(RENT_INFO_LEN * sizeof(RentalInfo*));
        fscanf(fps,"rent_info:\n");
        while(fgetc(fps)=='-'){
            fgets(litter,100,fps);
        }
        fgetc(fps);
        fgets(litter,100,fps);
        fscanf(fps,"ID:%s\n",(site[i])->ID);
        fscanf(fps,"region:%s\n",(site[i])->region);
        fscanf(fps,"sport:%s\n",(site[i])->sport);
        fscanf(fps,"intro:");
//        fgets((site[i]->intro),INTRO_LEN,fps);
//        len = strlen(site[i]->intro);
//        site[i]->intro[len-1] = '\0';
//        fscanf(fps,"intro:%s\n",(site[i])->intro);
        for(p = 0;(c=(char)getc(fps))!='\n';p++){
            site[i]->intro[p] = c;
        }
        site[i]->intro[p] = '\0';
        fscanf(fps,"enter_age:%d\n",&((site[i])->enter_age));
        fscanf(fps,"rent:%lf\n",&((site[i])->rent));
        fscanf(fps,"total_profit:%lf\n",&((site[i])->total_profit));
        fscanf(fps,"order_num:%d\n",&((site[i])->order_num));
        fscanf(fps,"rent_info_len:%d\n",&((site[i])->rent_info_len));
        site_size ++;
    }
    for(int i = 0;fgetc(fpa)!=EOF;i++){
        fgetc(fpa);
        admin[i] = (AdminInfo *)malloc(sizeof(AdminInfo));
        admin[i]->site_info = (SiteInfo **)malloc(SITE_INFO_LEN * sizeof(SiteInfo*));
        fscanf(fpa,"site_info:\n");
        while(fgetc(fpa)=='-'){
            fgets(litter,100,fpa);
        }
        fgetc(fpa);
        fscanf(fpa,"ID:%s\n",(admin[i])->ID);
        fscanf(fpa,"name:%s\n",(admin[i])->name);
        fscanf(fpa,"venue_name:%s\n",(admin[i])->venue_name);
        fscanf(fpa,"key:%s\n",(admin[i])->key);
        fscanf(fpa,"e_mail:%s\n",(admin[i])->e_mail);
        fscanf(fpa,"sex:%s\n",(admin[i])->sex);
        fscanf(fpa,"phone_num:%s\n",(admin[i])->phone_num);
        fscanf(fpa,"site_info_len:%d\n",&((admin[i])->site_info_len));
        adm_size ++;
    }
    for(int i = 0;fgetc(fpr)!=EOF;i++){
        fgetc(fpr);
        rent[i] = (RentalInfo *)malloc(sizeof(RentalInfo));
        fgets(litter,100,fpr);
        fgets(litter,100,fpr);
        fscanf(fpr,"Appoint_ID:%s\n",(rent[i])->Appoint_ID);
        fscanf(fpr,"start_time:%d:%d\n",&((rent[i])->start_time[0]),&((rent[i])->start_time[1]));
        fscanf(fpr,"end_time:%d:%d\n",&((rent[i])->end_time[0]),&((rent[i])->end_time[1]));
        fscanf(fpr,"appoint_time:%d:%d:%d:%d:%d\n",&((rent[i])->appoint_time[0]),&((rent[i])->appoint_time[1]),
               &((rent[i])->appoint_time[2]),&((rent[i])->appoint_time[3]),&((rent[i])->appoint_time[4]));
        fscanf(fpr,"start_date:%d:%d:%d\n",&((rent[i])->start_date[0]),&((rent[i])->start_date[1]),&((rent[i])->start_date[2]));
        fscanf(fpr,"price:%lf\n",&((rent[i])->price));
        fscanf(fpr,"is_intime:%d\n",&((rent[i])->is_intime));
        fscanf(fpr,"gender:%s\n",(rent[i])->gender);
        fscanf(fpr,"age:%d\n",&((rent[i])->age));
        fscanf(fpr,"is_complete:%d\n",&((rent[i])->is_complete));
        rent_size ++;
    }
    fseek(fpc,0,SEEK_SET);
    fseek(fps,0,SEEK_SET);
    fseek(fpa,0,SEEK_SET);
    fseek(fpr,0,SEEK_SET);
    for(int j = 0;j<cus_size;j++) {
        fscanf(fpc,"#\n");
        fscanf(fpc,"rent_info:\n");
        for (int i = 0;fgetc(fpc) == '-'; i++) {
            fscanf(fpc,"%s\n",ID);
            if(((customer[j])->rent_info[i] = search_rent_ID(ID))==NULL){
                printf("can not find rent info\n");
                break;
            }
        }
        fgetc(fpc);
        for(int i = 0;i<11;i++){
            fgets(litter,100,fpc);
        }
    }
    for(int j = 0;j<site_size;j++){
        fscanf(fps,"#\n");
        fscanf(fps,"rent_info:\n");
        for(int i = 0;fgetc(fps) == '-';i++){
            fscanf(fps,"%s\n",ID);
            if(((site[j])->rent_info[i] = search_rent_ID(ID))==NULL){
                printf("can not find rent info\n");
                break;
            }
        }
        fgetc(fps);
        fscanf(fps,"admin_info:%s\n",ID);
        if(((site[j])->admin_info = search_adm_ID(ID))==NULL){
            printf("can not find admin info\n");
            break;
        }
        for(int i = 0;i<9;i++){
            fgets(litter,100,fps);
        }
    }
    for(int j = 0;j<adm_size;j++){
        fscanf(fpa,"#\n");
        fscanf(fpa,"site_info:\n");
        for(int i = 0;fgetc(fpa)=='-';i++){
            fscanf(fpa,"%s\n",ID);
            if(((admin[j])->site_info[i] = search_site_ID(ID))==NULL){
                printf("can not find site info\n");
                break;
            }
        }
        fgetc(fpa);
        for(int i = 0;i<8;i++)
            fgets(litter,100,fpa);
    }
    for(int j = 0;j<rent_size;j++){
        fscanf(fpr,"#\n");
        fscanf(fpr,"cus_info:%s\n",ID);
        if(((rent[j])->cus_info = search_cus_ID(ID))==NULL){
            printf("can not find cus info\n");
            break;
        }
        fscanf(fpr,"site_info:%s\n",ID);
        if(((rent[j])->site_info = search_site_ID(ID))==NULL){
            printf("can not find site info\n");
            break;
        }
        for(int i = 0;i<10;i++)
            fgets(litter,100,fpr);
    }
    fclose(fpc);
    fclose(fpa);
    fclose(fpr);
    fclose(fps);
}

void _write_to_file(){
    FILE * fpa = fopen(FILE_ADM_PATH,"w");
    for(int j = 0;j<adm_size;j++){
        fprintf(fpa,"#\n");
        fprintf(fpa,"site_info:\n");
        for(int i = 0;i<admin[j]->site_info_len;i++){
            fprintf(fpa,"-%s\n",admin[j]->site_info[i]->ID);
        }
        fprintf(fpa,"~\n");
        fprintf(fpa,"ID:%s\n",admin[j]->ID);
        fprintf(fpa,"name:%s\n",admin[j]->name);
        fprintf(fpa,"venue_name:%s\n",admin[j]->venue_name);
        fprintf(fpa,"key:%s\n",admin[j]->key);
        fprintf(fpa,"e_mail:%s\n",admin[j]->e_mail);
        fprintf(fpa,"sex:%s\n",admin[j]->sex);
        fprintf(fpa,"phone_num:%s\n",admin[j]->phone_num);
        fprintf(fpa,"site_info_len:%d\n",admin[j]->site_info_len);
    }
    fclose(fpa);
    FILE * fpr = fopen(FILE_RENT_PATH,"w");
    for(int j = 0;j<rent_size;j++){
        fprintf(fpr,"#\n");
        fprintf(fpr,"cus_info:%s\n",rent[j]->cus_info->ID);
        fprintf(fpr,"site_info:%s\n",rent[j]->site_info->ID);
        fprintf(fpr,"Appoint_ID:%s\n",rent[j]->Appoint_ID);
        fprintf(fpr,"start_time:%02d:%02d\n",rent[j]->start_time[0],rent[j]->start_time[1]);
        fprintf(fpr,"end_time:%02d:%02d\n",rent[j]->end_time[0],rent[j]->end_time[1]);
        fprintf(fpr,"appoint_time:%d:%02d:%02d:%02d:%02d\n",rent[j]->appoint_time[0],rent[j]->appoint_time[1],
                rent[j]->appoint_time[2],rent[j]->appoint_time[3],rent[j]->appoint_time[4]);
        fprintf(fpr,"start_date:%d:%02d:%02d\n",rent[j]->start_date[0],rent[j]->start_date[1],rent[j]->start_date[2]);
        fprintf(fpr,"price:%.2f\n",rent[j]->price);
        fprintf(fpr,"is_intime:%d\n",rent[j]->is_intime);
        fprintf(fpr,"gender:%s\n",rent[j]->gender);
        fprintf(fpr,"age:%d\n",rent[j]->age);
        fprintf(fpr,"is_complete:%d\n",rent[j]->is_complete);
    }
    fclose(fpr);
    FILE * fps = fopen(FILE_SITE_PATH,"w");
    for(int j= 0;j<site_size;j++){
        fprintf(fps,"#\n");
        fprintf(fps,"rent_info:\n");
        for(int i = 0;i<site[j]->rent_info_len;i++){
            fprintf(fps,"-%s\n",site[j]->rent_info[i]->Appoint_ID);
        }
        fprintf(fps,"~\n");
        fprintf(fps,"admin_info:%s\n",site[j]->admin_info->ID);
        fprintf(fps,"ID:%s\n",site[j]->ID);
        fprintf(fps,"region:%s\n",site[j]->region);
        fprintf(fps,"sport:%s\n",site[j]->sport);
        fprintf(fps,"intro:%s\n",site[j]->intro);
        fprintf(fps,"enter_age:%d\n",site[j]->enter_age);
        fprintf(fps,"rent:%.2f\n",site[j]->rent);
        fprintf(fps,"total_profit:%.2f\n",site[j]->total_profit);
        fprintf(fps,"order_num:%d\n",site[j]->order_num);
        fprintf(fps,"rent_info_len:%d\n",site[j]->rent_info_len);
    }
    fclose(fps);
    FILE * fpc = fopen(FILE_COS_PATH,"w");
    for(int j = 0;j<cus_size;j++){
        fprintf(fpc,"#\n");
        fprintf(fpc,"rent_info:\n");
        for(int i = 0;i<customer[j]->rent_info_len;i++){
            fprintf(fpc,"-%s\n",customer[j]->rent_info[i]->Appoint_ID);
        }
        fprintf(fpc,"~\n");
        fprintf(fpc,"ID:%s\n",customer[j]->ID);
        fprintf(fpc,"name:%s\n",customer[j]->name);
        fprintf(fpc,"phone_num:%s\n",customer[j]->phone_num);
        fprintf(fpc,"key:%s\n",customer[j]->key);
        fprintf(fpc,"e_mail:%s\n",customer[j]->e_mail);
        fprintf(fpc,"sex:%s\n",customer[j]->sex);
        fprintf(fpc,"region:%s\n",customer[j]->region);
        fprintf(fpc,"balance:%.2f\n",customer[j]->balance);
        fprintf(fpc,"age:%d\n",customer[j]->age);
        fprintf(fpc,"default_num:%d\n",customer[j]->default_num);
        fprintf(fpc,"rent_info_len:%d\n",customer[j]->default_num);
    }
    fclose(fpc);
}
void free_all(){
    for(int i = 0;i<site_size;i++){
        free(site[i]);
    }
    for(int i = 0;i<rent_size;i++){
        free(rent[i]);
    }
    for(int i = 0;i<cus_size;i++){
        free(customer[i]);
    }
    for(int i = 0;i<adm_size;i++){
        free(admin[i]);
    }
}