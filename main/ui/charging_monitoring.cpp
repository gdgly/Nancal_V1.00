#include "charging_monitoring.h"
#include "ui_charging_monitoring.h"
#include "equipment_information.h"
#include "car_information.h"
#include "charging_end.h"
#include <QLabel>
#include <stdio.h>

Charging_monitoring::Charging_monitoring(QWidget *parent) : QWidget(parent), ui(new Ui::Charging_monitoring)
{
    ui->setupUi(this);


    ui->full_charge_but->setVisible(true);
    ui->charge_7but->setVisible(false);
    ui->charge_6but->setVisible(false);
    ui->charge_5but->setVisible(false);
    ui->charge_4but->setVisible(false);
    ui->charge_3but->setVisible(false);
    ui->charge_2but->setVisible(false);
    ui->charge_1but->setVisible(false);

    connect(ui->soc_set,SIGNAL(clicked()),this,SLOT(set_soc()));//查询
    //connect(ui->change_moni_but,SIGNAL(clicked()),this-,SLOT(change_moni());
    connect(ui->change_equ_but,SIGNAL(clicked()),this,SLOT(change_equinf()));//
    connect(ui->change_carinf_but,SIGNAL(clicked()),this,SLOT(change_carinf()));//
    connect(ui->change_end_but,SIGNAL(clicked()),this,SLOT(change_end()));//

#if 0
    if(bat_soc_int<100){//90
        ui->full_charge_but->setVisible(false);
        ui->charge_7but->setVisible(true);
    }else if(bat_soc_int<90 && bat_soc_int>80){//80
        ui->charge_7but->setVisible(false);
        ui->charge_6but->setVisible(true);
    }else if(bat_soc_int<80 && bat_soc_int>60){//60
        ui->charge_6but->setVisible(false);
        ui->charge_5but->setVisible(true);
    }else if(bat_soc_int<60 && bat_soc_int>30){//40
        ui->charge_5but->setVisible(false);
        ui->charge_4but->setVisible(true);
    }else if(bat_soc_int<30 && bat_soc_int>20){//30
        ui->charge_4but->setVisible(false);
        ui->charge_3but->setVisible(true);
    }else if(bat_soc_int<20 && bat_soc_int>10){//20
        ui->charge_3but->setVisible(false);
        ui->charge_2but->setVisible(true);
    }else if(bat_soc_int<20){//10
        ui->charge_2but->setVisible(false);
        ui->charge_1but->setVisible(true);
    }
#endif
    printf("successs!!!");
}

void Charging_monitoring::set_soc()
{
       ui->bat_soc->setText(ui->bat_soc->text());

       bat_soc_int =  ui->bat_soc->text().toInt();
       printf("bat_soc_txt==%d", bat_soc_int);

#if 0
       if(bat_soc_int==100 ){//90
           ui->full_charge_but->setVisible(true);
           ui->charge_7but->setVisible(false);
       }else if(bat_soc_int<100 && bat_soc_int>=90){//90
           ui->full_charge_but->setVisible(false);
           ui->charge_7but->setVisible(true);
       }else if(bat_soc_int<90 && bat_soc_int>=80){//80
           ui->charge_7but->setVisible(false);
           ui->charge_6but->setVisible(true);
       }else if(bat_soc_int<80 && bat_soc_int>=60){//60
           ui->charge_6but->setVisible(false);
           ui->charge_5but->setVisible(true);
       }else if(bat_soc_int<60 && bat_soc_int>=30){//40
           ui->charge_5but->setVisible(false);
           ui->charge_4but->setVisible(true);
       }else if(bat_soc_int<30 && bat_soc_int>=20){//30
           ui->charge_4but->setVisible(false);
           ui->charge_3but->setVisible(true);
       }else if(bat_soc_int<20 && bat_soc_int>=10){//20
           ui->charge_3but->setVisible(false);
           ui->charge_2but->setVisible(true);
       }else if(bat_soc_int<10){//10
           ui->charge_2but->setVisible(false);
           ui->charge_1but->setVisible(true);
       }
#else
       switch (bat_soc_int/10) {
       case 10://100
           ui->full_charge_but->setVisible(true);
           ui->charge_7but->setVisible(false);
           ui->charge_1but->setVisible(false);
           break;
       case 9://90
           ui->full_charge_but->setVisible(false);
           ui->charge_7but->setVisible(true);
           ui->charge_6but->setVisible(false);
           break;
       case 8://80
           ui->charge_7but->setVisible(false);
           ui->charge_6but->setVisible(true);
           ui->charge_5but->setVisible(false);
           break;
       case 7:
       case 6://60
           ui->charge_6but->setVisible(false);
           ui->charge_5but->setVisible(true);
           ui->charge_4but->setVisible(false);
           break;
       case 5:
       case 4://40
           ui->charge_5but->setVisible(false);
           ui->charge_4but->setVisible(true);
           ui->charge_3but->setVisible(false);
           break;
       case 3://30
           ui->charge_4but->setVisible(false);
           ui->charge_3but->setVisible(true);
           ui->charge_2but->setVisible(false);
           break;
       case 2://20
           ui->charge_3but->setVisible(false);
           ui->charge_2but->setVisible(true);
           ui->charge_1but->setVisible(false);
           break;
       case 1://10
       case 0:
           ui->charge_2but->setVisible(false);
           ui->charge_1but->setVisible(true);
           break;
       default:
           break;
       }
#endif
       show();
}

void Charging_monitoring::change_moni()
{
    Charging_monitoring *w_change_moni = new Charging_monitoring;
    w_change_moni->show();
}

void Charging_monitoring::change_equinf()
{
    Equipment_information *w_equipment_information = new Equipment_information;
    w_equipment_information->show();
}

void Charging_monitoring::change_carinf()
{
    Car_information *w_car_information = new Car_information;
    w_car_information->show();
}

void Charging_monitoring::change_end()
{
    charging_end *w_charging_end = new charging_end;
    w_charging_end->show();
}
Charging_monitoring::~Charging_monitoring()
{
    delete ui;
}
