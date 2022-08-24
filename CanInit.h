#ifndef CANINIT_H_

#define CANINIT_H_
//********************************************************************************************************************************************************************
//описание общих переменных для всех модулей в системе RSU97 (01.08.21)
//--------------------------------------------------------
#define dev_ind 0
#define dev_kab 1
#define dev_irb 2
#define dev_tyl 3
#define dev_dr1 4
#define dev_dr2 5
#define dev_dr3 6
#define dev_frn 8
#define dev_buk 9
#define dev_brp 13
#define dev_y64 14
#define dev_bak 16
//-----------------------------------------
//********************************************************************************************************************************************************************
#define max_can_dev 17 //кол-во типов устройств
//********************************************************************************************************************************************************************
//					N				D0
// D1 D2			D3			D4 D5 D6 D7
// Pr		cnt			dlc n/сек
//********************************************************************************************************************************************************************
//-----------------------------------------
//
#define blok_1_spd \
    8 //???		&Speed_L//???	&Speed_H//???	&var0//???
      //&var0//???		&Osc_var//???	&R0_spd//??? &Speed_er//???
      //&Speed_gz//???	1//???		&cnt_1_spd//???	8		//128
#define blok_1_pdl \
    9 //???		&U_xod//???		&U_trm_AT//??? &R0_pdl//???
      //&tik_128//???	&U_xod_L//???	&U_xod_H//??? &U_trm_L//???
      //&U_trm_H//???	4//???		&cnt_1_pdl//???	8		//32
#define blok_1_irb \
    10 //???		&R0_irb//???	&R1_irb//???	&Zadan_L//???
       //&Zadan_H//???	&Uak_irb//???	&I2_irb//??? &PTAstat//???
       //&PTA_upr//???	4//???		&cnt_1_irb//???	8		//32
#define blok_2_irb \
    11 //???		&I0_irbL//???	&I0_irbH//???	&I1_irbL//???
       //&I1_irbH//???	&U0_irbL//???	&U0_irbH//??? &Ud_irbL//???
       //&Ud_irbH//???	4//???		&cnt_2_irb//???	8		//32
#define blok_3_irb \
    12 //???		&R1_zach//???	&R2_zach//???	&R3_zach//???
       //&R4_zach//???	&Db_irb1//???	&Db_irb2//??? &Db_irb3//???
       //&Db_irb4//???	4//???		&cnt_3_irb//???	8		//32
#define blok_2_pdl \
    13 //???		&U_trm_EBS//???	&R1_pdl//???	&Lim_xod//???
       //&R0_ebs//???	&R1_ebs//???	&Irlim_kak//??? &ebc1_cnt//???
       //&char_zad//???	4//???		&cnt_2_pdl//???	8		//32
//
#define blok_1_brp \
    15 //???     &Iak_brp_L//???	&Iak_brp_H//???	&R0_brp//???
       //&R1_brp//???    &Uak_brp//???   &brp_v1//???    &brp_v2//??? &brp_v3//
       //???4//???		&cnt_1_brp//???	8		//32
//-----------------------------------------
//
#define blok_1_frn \
    16 //???		&R0_frn//???	&R1_frn//???	&R2_frn//???
       //&R3_frn//???	&R4_frn//???	&R5_frn//???	&R6_frn//???
       //&R7_frn//???	8//???		&cnt_1_frn//???	8		//16
#define blok_2_frn \
    17 //???		&R8_frn//???	&R9_frn//???	&RA_frn//???
       //&RB_frn//???	&RC_frn//???	&RD_frn//??? &FotoR_frn//???
       //&Time_p//???	8//???		&cnt_2_frn//???	8		//16
//
#define blok_2_tyl \
    19 //???		&R0_tyl//???	&R1_tyl//???	&var0//???
       //&var0//???		&var0//???		&Speed_er//???
       //&diag0tyl//???	&diag1tyl//???	8//??? &cnt_2_tyl//???	8
       ////16
//
#define blok_1_ind \
    21 //???		&R0_ind//???	&R1_ind//???	&R2_ind//???
       //&R3_ind//???	&R4_ind//???	&ad0_ind//???	&S_ah//???
       //&Tlia_max//???		8//???		&cnt_1_ind//???	8
       ////16
#define blok_3_ind 22
//
#define blok_1_kab \
    23 //???		&R0_kab//???	&R1_kab//???	&Iak_K_L//???
       //&Iak_K_H//???	&P1_kab//???	&P2_kab//???	&P3_kab//???
       //&P4_kab//???	8//???		&cnt_1_kab//???	8		//16
#define blok_1_sas \
    24 //???		&SWA_L//???		&SWA_H//???
       //&SWA_RC//???	&var0//???		&SWA_R_L//??? &SWA_R_H//???
       //&R0_sas//???	&McMc_sas//???	8//??? &cnt_1_sas//???	8
       ////16
#define blok_1_dr1 \
    25 //???		&R0_dr1//???	&R1_dr1//???	&var0//???
       //&var0//???		&var0//???		&var0//???
       //&var0//???		&var0//???		8//???
       //&cnt_1_dr1//???	8		//16
//
#define EDSC1_dr0 24
#define EDSC1_dr1 \
    26 //???		&R0_edsc11//???	&R1_edsc11//??? &R2_edsc11//???
       //&R3_edsc11//???	&R4_edsc11//???	&R5_edsc11//??? &R6_edsc11//???
       //&R7_edsc11//???	8//???		&cnt_1_edsc11//???	8
       ////16
#define EDSC1_dr2 \
    28 //???		&R0_edsc12//???	&R1_edsc12//??? &R2_edsc12//???
       //&R3_edsc12//???	&R4_edsc12//???	&R5_edsc12//??? &R6_edsc12//???
       //&R7_edsc12//???	8//???		&cnt_1_edsc12//???	8
       ////16
#define blok_1_dr3 \
    29 //???		&R0_dr3//???	&R1_dr3//???	&var0//???
       //&var0//???		&var0//???		&var0//???
       //&var0//???		&var0//???		8//???
       //&cnt_1_dr3//???	8		//16
#define EDSC1_dr3 \
    30 //???		&R0_edsc13//???	&R1_edsc13//??? &R2_edsc13//???
       //&R3_edsc13//???	&R4_edsc13//???	&R5_edsc13//??? &R6_edsc13//???
       //&R7_edsc13//???	8//???		&cnt_1_edsc13//???	8
       ////16
//
#define blok_1_buk \
    31 //???		&R0_buk//???	&R1_buk//???	&IsnbukL//???
       //&IsnbukH//???	&R2_buk//???	&var0//??? &var0//???
       //&PWM_PNR//???	8//???		&cnt_1_buk//???	8		//16
//
#define blok_1_tab \
    33 //???		&R0_tab//???	&R1_tab//???	&Umin//???
       //&Umax,			&I1_zu1L,		&I1_zu1H,
       //&I2_zu1L,		&I2_zu1H,		8//???
       //&cnt_1_tab//???	8		//16
//
#define blok_1_zu1 \
    35 //???		&R0_zu1//???	&zu1stat//???	&zu1_upr//???
       //&Rz1_zu1//???	&Rz2_zu1//???	&Rz3_zu1//??? &Rz4_zu1//???
       //&Tav_zu1//???	8//???		&cnt_1_zu1//???	8		//16
//
#define blok_1_bak \
    37 //???		&R0_bak//???	&var0//???		&var0//???
       //&var0//???		&var0//???		&var0//???
       //&var0//???		&var0//???		8//???
       //&cnt_1_bak//???	8		//16
//
#define blok_1_con \
    41 //???		&R0_con1//???	&Tyst_con1//??? &Tsal_con1//???
       //&Tout_con1//???	&Mode_con1//???	&CO2_con1//??? &Ver_con1//???
       //&cnt_con1//???	8//???		&cnt_1_con//???	8//16
#define blok_2_con \
    42 //???		&R0_con2//???	&Tyst_con2//??? &Tsal_con2//???
       //&Tout_con2//???	&Mode_con2//???	&CO2_con2//??? &Ver_con2//???
       //&cnt_con2//???	8//???		&cnt_2_con//???	8//16
//
#define blok_1_tah \
    43 //???		&R0_tah//???	&R1_tah//???	&R2_tah//???
       //&R3_tah//???	&V1_tah_L//???	&V1_tah_H//??? &V2_tah_L//???
       //&V2_tah_H//???	8//???		&cnt_1_tah//???	8//16
#define blok_4_tah \
    44 //???		&R0_Ecas//???	&R0_Psy//???	&Cnt_Ecas//???
       //&R4_tah//???	&R5_tah//???	&R6_tah//??? &Cnt_kakam//???
       //&var0//???		16//???		&cnt_4_tah//???	8
       ////16
//
#define blok_1_y64 \
    51 //???		&R0_y64//???	&PwY_y64//???	&Ryt_y64//???
       //&Iyt_y64//???	&Fvr_y64L//???	&Fvr_y64H//??? &ver1_y64//???
       //&ver2_y64//???		16//???		&cnt_1_y64//??? 8
       ////16
#define DSC1_dr0 52
#define DSC1_dr1 \
    53 //???		&R0_dsc11//???	&R1_dsc11//??? &R2_dsc11//???
       //&R3_dsc11//???	&R4_dsc11//???	&R5_dsc11//??? &R6_dsc11//???
       //&R7_dsc11//???	8//???		&cnt_1_dsc11//???	8	//16
#define DSC1_dr2 54
#define DSC1_dr3 55
//					58
#define PSY_Upr \
    59 //???		&Up0_psy//???	&Up1_psy//???	&Up2_psy//???
       //&Up3_psy//???	&Up4_psy//???	&Up5_psy//??? &Up6_psy//???
       //&Up7_psy//???	8//???		&cnt_1_psy//???	8	//16
#define PSY_State \
    60 //???		&St0_psy//???	&St1_psy//???	&St2_psy//???
       //&St3_psy//???	&St4_psy//???	&St5_psy//??? &St6_psy//???
       //&St7_psy//???	8//???		&cnt_2_psy//???	8	//16
#define PSY_PolSt \
    61 //???		&PS0_psy//???	&PS1_psy//???	&PS2_psy//???
       //&PS3_psy//???	&PS4_psy//???	&PS5_psy//??? &PS6_psy//???
       //&PS7_psy//???	8//???		&cnt_3_psy//???	8	//16
//-----------------------------------------
//
#define blok_3_tyl \
    64 //???		&I11_tyl//???	&I12_tyl//???	&I21_tyl//???
       //&I22_tyl//???	&I31_tyl//???	&I32_tyl//??? &I41_tyl//???
       //&I42_tyl//???	32//???		&cnt_3_tyl//???	8		//4
#define blok_4_tyl \
    65 //???		&I51_tyl//???	&I52_tyl//???	&I61_tyl//???
       //&I62_tyl//???	&I71_tyl//???	&I72_tyl//??? &ad0_tyl//???
       //&ad1_tyl//???	32//???		&cnt_4_tyl//???	8		//4
#define blok_5_tyl \
    66 //???		&no_err_01//???	&no_err_02//??? &no_err_03//???
       //&no_err_04//???	&m_err_01//???	&m_err_02//??? &m_err_03//???
       //&m_err_04//???	32//???		&cnt_5_tyl//???	8		//4
//
#define blok_2_ind \
    67 //???		&secs//???		&mins//???
       //&hours//???		&days//???		&mons//???
       //&years//???		&bat1//???		&bat2//???
       // 32//???		&cnt_2_ind//???	8		//4
//
#define blok_4_irb \
    69 //???		&I_PTA//???		&I_lk//???
       //&T_PTA//???		&I_sfn//???		&CnErr2//???
       //&var0//???		&var0//???		&var0//???
       // 32//???		&cnt_4_irb//???	8		//4
//
#define blok_2_kab \
    71 //???		&I11_kab//???	&I12_kab//???	&I21_kab//???
       //&I22_kab//???	&I31_kab//???	&I32_kab//??? &I41_kab//???
       //&I42_kab//???	32//???		&cnt_2_kab//???	8		//4
#define blok_3_kab \
    72 //???		&I51_kab//???	&I52_kab//???	&I61_kab//???
       //&I62_kab//???	&I71_kab//???	&I72_kab//??? &ad0_kab//???
       //&ad1_kab//???	32//???		&cnt_3_kab//???	8		//4
#define blok_4_kab \
    73 //???		&P1_kab_L//???	&P1_kab_H//??? &P2_kab_L//???
       //&P2_kab_H//???	&P3_kab_L//???	&P3_kab_L//??? &P4_kab_L//???
       //&P1_kab_H//???	32//???		&cnt_4_kab//???	8		//4
//
#define blok_2_dr1 \
    74 //???		&I11_dr1//???	&I12_dr1//???	&I21_dr1//???
       //&I22_dr1//???	&I31_dr1//???	&I32_dr1//??? &I41_dr1//???
       //&I42_dr1//???	32//???		&cnt_2_dr1//???	8		//4
#define blok_3_dr1 \
    75 //???		&I51_dr1//???	&I52_dr1//???	&I61_dr1//???
       //&I62_dr1//???	&I71_dr1//???	&I72_dr1//??? &ad0_dr1//???
       //&ad1_dr1//???	32//???		&cnt_3_dr1//???	8		//4
//
#define blok_2_dr3 \
    80 //???		&I11_dr3//???	&I12_dr3//???	&I21_dr3//???
       //&I22_dr3//???	&I31_dr3//???	&I32_dr3//??? &I41_dr3//???
       //&I42_dr3//???	32//???		&cnt_2_dr3//???	8		//4
#define blok_3_dr3 \
    81 //???		&I51_dr3//???	&I52_dr3//???	&I61_dr3//???
       //&I62_dr3//???	&I71_dr3//???	&I72_dr3//??? &ad0_dr3//???
       //&ad1_dr3//???	32//???		&cnt_3_dr3//???	8		//4
///
#define blok_3_frn \
    83 //???		&I11_frn//???	&I12_frn//???	&I21_frn//???
       //&I31_frn//???	&I42_frn//???	&I51_frn//??? &I52_frn//???
       //&I61_frn//???	32//???		&cnt_3_frn//???	8		//4
#define blok_4_frn \
    84 //???		&I62_frn//???	&I71_frn//???	&I72_frn//???
       //&I81_frn//???	&I82_frn//???	&I91_frn//??? &I92_frn//???
       //&ad1_frn//???	32//???		&cnt_4_frn//???	8		//4
//
#define blok_2_buk \
    86 //???		&I11_buk//???	&I12_buk//???	&I21_buk//???
       //&I22_buk//???	&I31_buk//???	&I32_buk//??? &I41_buk//???
       //&I42_buk//???	32//???		&cnt_2_buk//???	8		//4
#define blok_3_buk \
    87 //???		&I51_buk//???	&I52_buk//???	&I61_buk//???
       //&I62_buk//???	&I71_buk//???	&I72_buk//??? &ad0_buk//???
       //&ad1_buk//???	32//???		&cnt_3_buk//???	8		//4
//
#define blok_2_tah \
    95 //???		&Hrtv_L//???	&Hrtv_H//???	&Hrtv_M//???
       //&Hrtv_U//???	&Hrvt_L//???	&Hrvt_H//???	&Hrvt_M//???
       //&Hrvt_U//???	32//???		&cnt_2_tah//???	8		//2
#define blok_3_tah \
    96 //???		&tsecs//???		&tmins//???
       //&thours//???	&tmons//???		&tdays//???
       //&tyears//???	&tminoff//???	&thouroff//???	32//???
       //&cnt_3_tah//???	8		//2
//
#define blok_2_brp \
    101 //???    &R2_brp//???	&R3_brp//???	&R4_brp//??? &R5_brp//???
        //&R6_brp//???    &R7_brp//???    &R8_brp//???    &R9_brp// ???32//???
        //&cnt_2_brp//???	8		//4
//
#define EDSC2_dr0 109
#define EDSC2_dr1 \
    110 //???	&R0_edsc21//???	&R1_edsc21//???	&R2_edsc21//??? &R3_edsc21//???
        //&R4_edsc21//???	&R5_edsc21//???	&R6_edsc21//??? &R7_edsc21//???
        // 8//???		&cnt_1_edsc21//???	8	//16
#define EDSC2_dr2 \
    111 //???	&R0_edsc22//???	&R1_edsc22//???	&R2_edsc22//??? &R3_edsc22//???
        //&R4_edsc22//???	&R5_edsc22//???	&R6_edsc22//??? &R7_edsc22//???
        // 8//???		&cnt_1_edsc22//???	8	//16
#define EDSC2_dr3 \
    112 //???	&R0_edsc23//???	&R1_edsc23//???	&R2_edsc23//??? &R3_edsc23//???
        //&R4_edsc23//???	&R5_edsc23//???	&R6_edsc23//??? &R7_edsc23//???
        // 8//???		&cnt_1_edsc23//???	8	//16
//-----------------------------------------
//
// 128-135 информация о пробеге и потреблении
//
// 136-170 информация о ЛИА
//
// 171-187 информация оn Бакси
//
//--------------------------------------------------------------------------------------------------------------------------------
//
//
//********************************************************************************************************************************************************************
// Фронт
#define I_LampGubDnFr I11_frn // Ток освещения противотуман
#define I_Horn I12_frn        // Ток сирены
#define I_LampHighL I21_frn // Ток дальний свет левый
#define I_LampHeadL I21_frn // Ток ближний свет левый
#define I_LampHeadR I31_frn // Ток ближний свет правый
#define I_LampHighR I31_frn // Ток дальний свет правый
#define I_LampXod I31_frn   // Ток дневных ходовых огней
#define I_LampFogF I42_frn // Ток переднего противотуман
#define I_LampFrLeft I51_frn // Ток переднего поворота левого
#define I_LampFrRight I52_frn // Ток переднего поворота правого
#define I_WiperSlow I61_frn // Ток привода стеклоочистителя медленно
#define I_WiperFast I62_frn // Ток привода стеклоочистителя быстро
#define I_FanFast I71_frn // Ток вентилятора обдува фронт.печи быстр
#define I_FanSlow I72_frn // Ток вентилятора обдува фронт.печи медл
#define I_WarmFloor I81_frn // Ток реле тёплого пола
#define I_Washer I82_frn // Ток насоса стеклоомывателя
#define I_Can I91_frn // Ток сигнала питание компрессора
// Тыл
#define I_LampFog I11_tyl // Ток заднего противотуман
#define I_FanD I12_tyl    // Ток вентилятора отопителя D
#define I_KompressOn I21_tyl // Ток сигнала включение компрессора
#define I_LampOtsek I22_tyl // Ток освещения отсека
#define I_Klapan I31_tyl    // Ток управления клапаном
//#define ---			I32_tyl		// резерв
#define I_LampZadRight I41_tyl // Ток заднего поворота правого
#define I_LampZadLeft I42_tyl // Ток заднего поворота левого
#define I_Sbros I51_tyl // Ток управления сбросом конденсата
#define I_FanF I52_tyl // Ток вентилятора отопителя F
#define I_LampGubDnZad I61_tyl // Ток ламп задние габариты
#define I_LampRevers I62_tyl   // Ток ламп задний ход
#define I_LampStop I71_tyl     // Ток ламп стоп
#define I_KompressPw I72_tyl // Ток сигнала питание компрессора
// Кабина
#define I_SPP_Opdr3 \
    I11_kab // Ток сигнала к системе подсчёта пассажира "открыта дверь 3"
#define I_HeatGlass I12_kab // Ток обогрева стекла
#define I_Info_Closing \
    I21_kab // Ток сигнала к информ системе "двери закрываются"
#define I_IGN_YVEOS \
    I22_kab // Ток сигнала зажигания к УВЭОС, АСН, пультам кондиционера
#define I_Play I31_kab    // Ток обогрева кресла
#define I_LampGub I32_kab // Ток освещения габариты
#define I_ReleGyr I41_kab // Ток Реле ГУР
#define I_IGN_EKAS I42_kab // Ток сигнала зажигания к Екас и тахографу
#define I_OnGyr I51_kab // Ток вентиялтора кондиционера скорость 1
#define I_Bodr I52_kab // резерв
#define I_SPP_Opdr1 \
    I61_kab // Ток сигнала к системе подсчёта пассажира "открыта дверь 1"
#define I_IGN_EBS I62_kab // Ток сигнала зажигания к EBS
#define I_SPP_Opdr2 \
    I71_kab // Ток сигнала к системе подсчёта пассажира "открыта дверь 2"
#define I_Info_Opened I72_kab // Ток сигнала к информ системе "двери открыты"
// Дверь 1
#define I_CoolKabin2 I11_dr1 // Ток Кондиционер кабины скорость 2
#define I_LampGubUpFr I12_dr1 // Ток верхних передних габаритов
#define I_CoolKabin3 I21_dr1 // Ток Кондиционер кабины скорость 3
#define I_CoolKabinOn I22_dr1 // Ток Кондиционер кабины включение
#define I_LampSalonL I31_dr1 // Ток освещения салон левый
#define I_LampSalonR I32_dr1 // Ток освещения салон правый
#define I_LampUpFrRight I41_dr1 // Ток повторителя поворота правого
#define I_RainSensor I42_dr1 // Ток Включения датчика дождя и света
#define I_LampDezur I51_dr1 // Ток дежурного освещения
#define I_Media I52_dr1 // Ток реле медиа комплекса и автоинформатора
#define I_CoolKabin1 I61_dr1 // Ток Кондиционер кабины скорость 1
#define I_SKOP_Terminal I62_dr1 // Ток питания СКОП терминал водителя
#define I_LampCabin I71_dr1   // Ток освещения кабины
#define I_HeatMirrors I72_dr1 // Ток обогрева зеркал
// Дверь 3
#define I_SKO_ViewOn I11_dr3 // Ток системы кругового обзора задний ход
#define I_CoolFanS1 I12_dr3 // Ток питания кнопки открывания дверь 3
#define I_SKO_Left I21_dr3 // Ток системы кругового обзора левый поворот
#define I_SKO_Right I22_dr3 // Ток системы кругового обзора правый поворот
#define I_LampDekorL I31_dr3 // Ток декоративного освещения 1
#define I_CoolFanS3 I32_dr3 // Ток декоративного освещения 2
#define I_LampGubUpZad I41_dr3 // Ток верхн задних габаритов дверь 3
#define I_FanC I42_dr3 // Ток вентилятора отопителя C
#define I_FanE I51_dr3 // Ток вентилятора отопителя E
#define I_CoolFanS2 I52_dr3 // резерв
#define I_CoolOnS I61_dr3 // Ток кондиционера салона включение
#define I_PSY_Cam I62_dr3  // Ток Камеры ПШУ
#define I_Prev_Cam I71_dr3 // Ток предыдущей камеры
#define I_Next_Cam I72_dr3 // Ток следующей камеры
// Бук
#define I_HeatD I11_buk  // Ток контактора печи D
#define I_PSY_Pw I21_buk // Ток ПШУ питание
#define I_HeatE I22_buk  // Ток контактора печи E
#define I_HeatF I11_buk  // Ток контактора печи F
#define I_HeatC I22_buk  // Ток контактора печи C
#define I_PNR I31_buk    // Ток контактора ПНР
#define I_CondKompr I32_buk // Ток контактора компрессора кондиционера
#define Shim_PNR I41_buk // Ток шим управления ПНР
#define I_LampShtang I42_buk // Ток ламп освещения токоприёмников
#define I_SmallAX I51_buk // Ток ключа малого АХ
//#define ---			I52_buk		// резерв
#define I_HeatA I61_buk // Ток контактора печи А
#define I_HeatB I62_buk // Ток контактора печи B
#define I_Kompress I71_buk // Ток контактора компрессора пневмосистемы
#define I_HeatO I72_buk // Ток контактора печи O
//-----------------------------------------
//Коэффициенты аналоговых измерений (Кключа=4800)
//токи в нагрузках плат Фронт20, КВП30, Дверь*v20, Бук20
// 1кнуц = 46 мА (1А =21.76 кнуц)
//ток CAN шины
// 1кнуц = 4.4 мА (1А =227 кнуц)
//токи в нагрузках платы МСИрбис
// 1кнуц = 37.65 мА (1А =26.5625 кнуц)
//токи в нагрузках платы Тыл20
// 1кнуц =  30.33мА (1А =32.97 кнуц)
//напряжение аккумулятора из ирбиса
// 1кнуц = 1.375 мВ (1В = 727.27кнуц)(мах 45В)
//ток аккумулятора из КВП
// 1кнуц = 22.89 мА (1А =43.69 кнуц)(+-375А)
//ток аккумулятора из Тыла
// 1кнуц = 15.1 мА (1А =66.2 кнуц)(+-247А)
//ток собственных нужд из КВП
// 1кнуц = 7.63 мА (1А =131.072 кнуц)(+-125А)
//-----------------------------------------
/*#define  d_w_SIDH	b'11110111'
#define  d_w_SIDL	b'10111110'
#define  d_w_EIDH	b'11110111'
#define  d_w_DLC	b'00001000'
#define  m_w_EIDH	b'11111111'
#define  m_w_EIDL	b'10000000'
//-----------------------------------------
#define  d_c_SIDH	b'11110111'
#define  d_c_SIDL	b'10111110'
#define  d_c_EIDH	b'11110110'
//#define  d_c_EIDL	b'00000000'
#define  d_c_DLC	b'00001000'
#define  m_c_EIDH	b'11111111'	//1
#define  m_c_EIDL	b'11111111'	//1
*///-----------------------------------------
#define D_wheel 100      //диаметр колеса в см
#define K_reduction 1067 //коэф редуктора *100
//-----------------------------------------
//----------------------------------------------
//--команда 0 - остановка "боевой" передачи данных
// SIDH = d_c_SIDH
// SIDL = d_c_SIDL
// EIDH = d_c_EIDH + device	//адресуемое устройство
// EIDL = 0			//0 - команда "стоп передатчики"
// DLC  = d_c_DLC
//
//--команда 1 - запуск "боевой" передачи данных
// SIDH = d_c_SIDH
// SIDL = d_c_SIDL
// EIDH = d_c_EIDH + device	//адресуемое устройство
// EIDL = 1			//1 - команда "запуск передатчиков"
//
//--для Фронта
// DLC  = 3
// DAT0 = key_heat_C      	//расписание
// DAT1 = key_heat_D      	// подключения печек
// DAT2 = key_heat_E      	// к контакторам C,D,E
// DAT3 = senser_heat      	//наличие датчиков в печках
// DAT4 = fan_heat	      	//наличие низковольтных вентилляторов в печках
//
//--для Ирбиса
// DLC  = 3
// DAT0 = drive_feature		//+0 - DC, +4 - AC...
// DAT1 = low (колесо/редуктор)	//
// DAT2 = high (колесо/редуктор)	// для одометра
//
//--для Тыла
// DLC  = 3
// DAT0 = low (кол-во зубьев)	//
// DAT1 = high (кол-во зубьев)	//
// DAT2 = drive_feature		//+0 - DC, +4 - AC...
//
//--для Дверей и КВП
// DLC  = 0
//
//---------------------------------------------------------------------------------------
//команды для обмена с EEPROM
//--команда 2 - запись в EEPROM
// SIDH = d_c_SIDH
// SIDL = d_c_SIDL
// EIDH = d_c_EIDH + device	//адресуемое устройство
// EIDL = 2			//2 - команда "запись в EEPROM"
// DLC  = d_c_DLC
// DAT0 = adr_eeprom_L		//
// DAT1 = adr_eeprom_H		//
// DAT2 = data_eeprom		//
//
//--команда 5 - ответ на запись
// SIDH = d_c_SIDH
// SIDL = d_c_SIDL
// EIDH = d_c_EIDH + 0		//адресуемое устройство
// EIDL = 5			//5 - команда "ответ после правильной записи
// EEPROM" DLC  = d_c_DLC
//
//--команда 3 - чтение EEPROM
// SIDH = d_c_SIDH
// SIDL = d_c_SIDL
// EIDH = d_c_EIDH + device	//адресуемое устройство
// EIDL = 3			//3 - команда "чтение EEPROM"
// DLC  = d_c_DLC
// DAT0 = adr_eeprom_L		//
// DAT1 = adr_eeprom_H		//
//
//--команда 4 - ответ на чтение
// SIDH = d_c_SIDH
// SIDL = d_c_SIDL
// EIDH = d_c_EIDH + 0		//адресуемое устройство - индикатор
// EIDL = 4			//4 - команда "ответ чтения EEPROM"
// DLC  = d_c_DLC
// DAT0 = data_eeprom		//
//-------------------------------------------------------------
//--команда 6 - чтение/запись данных ПТА в режиме настройки
// SIDH = d_c_SIDH
// SIDL = d_c_SIDL
// EIDH = d_c_EIDH + dev_irb	//адресуемое устройство - плата крыша
// EIDL = 6			//6 - команда "чтение данных ПТА в режиме
// настройки" DLC  = d_c_DLC DAT0 = 			//группа функций DAT1 =
// //функция DAT2 = 			//данные 1 high DAT3 =
// //данные 1 low DAT4 = 			//данные 2 high DAT5 =
// //данные 2 low
//
//--команда 7 - прочитанные данные из ПТА в режиме настройки
// SIDH = d_c_SIDH
// SIDL = d_c_SIDL
// EIDH = d_c_EIDH + 0		//адресуемое устройство - индикатор
// EIDL = 7			//7 - команда "прочитанные данные из ПТА"
// DLC  = d_c_DLC
// DAT0 = 			//данные 1 high
// DAT1 = 			//данные 1 low
// DAT2 = 			//данные 2 high
// DAT3 = 			//данные 2 low
// DAT4 = 			//данные 3 high
// DAT5 = 			//данные 3 low
// DAT6 = 			//данные 4 high
// DAT7 = 			//данные 4 low
//
//--команда 8 - запись данных ПТА в режиме настройки
// SIDH = d_c_SIDH
// SIDL = d_c_SIDL
// EIDH = d_c_EIDH + dev_irb	//адресуемое устройство - плата крыша
// EIDL = 8			//8 - команда "запись данных ПТА в режиме
// настройки" DLC  = d_c_DLC DAT0 = 			//группа функций DAT1 =
// //функция + 128 DAT2 = 			//данные 1 high DAT3 =
// //данные 1 low DAT4 = 			//данные 2 high DAT5 =
// //данные 2 low DAT6 = 			//данные 3 high DAT7 =
// //данные 3 low
//
//---------------------------------------------------------------------------------------
//*********************************************************************************************************************************************************************************//
//Инициализация переменных
//----------------------------------------------------------------------------------
#define Speed_L can_mes.can_mes_char[8][0]
#define Speed_H can_mes.can_mes_char[8][1]
#define Osc_var can_mes.can_mes_char[8][4]
#define R0_spd can_mes.can_mes_char[8][5]
#define Speed_er1 can_mes.can_mes_char[8][6]
#define Speed_er4 can_mes.can_mes_char[8][7]
#define cnt_1_spd can_cnt[8]
#define U_xod can_mes.can_mes_char[9][0]
#define U_trm_AT can_mes.can_mes_char[9][1]
#define R0_pdl can_mes.can_mes_char[9][2]
#define tik_128 can_mes.can_mes_char[9][3]
#define U_xod_L can_mes.can_mes_char[9][4]
#define U_xod_H can_mes.can_mes_char[9][5]
#define U_trm_L can_mes.can_mes_char[9][6]
#define U_trm_H can_mes.can_mes_char[9][7]
#define cnt_1_pdl can_cnt[9]
#define R0_irb can_mes.can_mes_char[10][0]
#define R1_irb can_mes.can_mes_char[10][1]
#define Zadan_L can_mes.can_mes_char[10][2]
#define Zadan_H can_mes.can_mes_char[10][3]
#define Uak_irb can_mes.can_mes_char[10][4]
#define I2_irb can_mes.can_mes_char[10][5]
#define PTAstat can_mes.can_mes_char[10][6]
#define PTA_upr can_mes.can_mes_char[10][7]
#define cnt_1_irb can_cnt[10]
#define I0_irbL can_mes.can_mes_char[11][0]
#define I0_irbH can_mes.can_mes_char[11][1]
#define I1_irbL can_mes.can_mes_char[11][2]
#define I1_irbH can_mes.can_mes_char[11][3]
#define U0_irbL can_mes.can_mes_char[11][4]
#define U0_irbH can_mes.can_mes_char[11][5]
#define Ud_irbL can_mes.can_mes_char[11][6]
#define Ud_irbH can_mes.can_mes_char[11][7]
#define cnt_2_irb can_cnt[11]
#define R1_zach can_mes.can_mes_char[12][0]
#define R2_zach can_mes.can_mes_char[12][1]
#define R3_zach can_mes.can_mes_char[12][2]
#define R4_zach can_mes.can_mes_char[12][3]
#define Db_irb1 can_mes.can_mes_char[12][4]
#define Db_irb2 can_mes.can_mes_char[12][5]
#define Db_irb3 can_mes.can_mes_char[12][6]
#define Db_irb4 can_mes.can_mes_char[12][7]
#define cnt_3_irb can_cnt[12]
#define U_trm_EBS can_mes.can_mes_char[13][0]
#define R1_pdl can_mes.can_mes_char[13][1]
#define Lim_xod can_mes.can_mes_char[13][2]
#define R0_ebs can_mes.can_mes_char[13][3]
#define R1_ebs can_mes.can_mes_char[13][4]
#define Irlim_kak can_mes.can_mes_char[13][5]
#define ebc1_cnt can_mes.can_mes_char[13][6]
#define char_zad can_mes.can_mes_char[13][7]
#define cnt_2_pdl can_cnt[13]
#define U1yki_L can_mes.can_mes_char[14][0]
#define U1yki_H can_mes.can_mes_char[14][1]
#define U2yki_L can_mes.can_mes_char[14][2]
#define U2yki_H can_mes.can_mes_char[14][3]
#define R0_yki can_mes.can_mes_char[14][4]
#define avg_lv_yki can_mes.can_mes_char[14][5]
#define min_lv_yki can_mes.can_mes_char[14][6]
#define max_lv_yki can_mes.can_mes_char[14][7]
#define cnt_2_yki can_cnt[14]
#define Iak_brp_L can_mes.can_mes_char[15][0]
#define Iak_brp_H can_mes.can_mes_char[15][1]
#define Pwm_Akb can_mes.can_mes_char[15][2]
#define Pwm_Gyr can_mes.can_mes_char[15][3]
#define Uak_brp can_mes.can_mes_char[15][4]
#define R0_brp can_mes.can_mes_char[15][5]
#define brp_v1 can_mes.can_mes_char[15][6]
#define brp_v2 can_mes.can_mes_char[15][7]
#define cnt_1_brp can_cnt[15]
#define R0_frn can_mes.can_mes_char[16][0]
#define R1_frn can_mes.can_mes_char[16][1]
#define R2_frn can_mes.can_mes_char[16][2]
#define R3_frn can_mes.can_mes_char[16][3]
#define R4_frn can_mes.can_mes_char[16][4]
#define R5_frn can_mes.can_mes_char[16][5]
#define R6_frn can_mes.can_mes_char[16][6]
#define R7_frn can_mes.can_mes_char[16][7]
#define cnt_1_frn can_cnt[16]
#define R8_frn can_mes.can_mes_char[17][0]
#define R9_frn can_mes.can_mes_char[17][1]
#define RA_frn can_mes.can_mes_char[17][2]
#define RB_frn can_mes.can_mes_char[17][3]
#define RC_frn can_mes.can_mes_char[17][4]
#define RD_frn can_mes.can_mes_char[17][5]
#define FotoR_frn can_mes.can_mes_char[17][6]
#define Time_p can_mes.can_mes_char[17][7]
#define cnt_2_frn can_cnt[17]
#define R0_tyl can_mes.can_mes_char[19][0]
#define R1_tyl can_mes.can_mes_char[19][1]
#define Res_BK_com1 can_mes.can_mes_char[19][5]
#define cnt_2_tyl can_cnt[19]
#define R0_ind can_mes.can_mes_char[21][0]
#define R1_ind can_mes.can_mes_char[21][1]
#define R2_ind can_mes.can_mes_char[21][2]
#define R3_ind can_mes.can_mes_char[21][3]
#define R4_ind can_mes.can_mes_char[21][4]
#define ad0_ind can_mes.can_mes_char[21][5]
#define S_ah can_mes.can_mes_char[21][6]
#define Tlia_Max can_mes.can_mes_char[21][7]
#define cnt_1_ind can_cnt
#define R0_kab can_mes.can_mes_char[23][0]
#define R1_kab can_mes.can_mes_char[23][1]
#define IsnkabL can_mes.can_mes_char[23][2]
#define IsnkabH can_mes.can_mes_char[23][3]
#define P1_kab can_mes.can_mes_char[23][4]
#define P2_kab can_mes.can_mes_char[23][5]
#define P3_kab can_mes.can_mes_char[23][6]
#define P4_kab can_mes.can_mes_char[23][7]
#define cnt_1_kab can_cnt[23]
#define SWA_L can_mes.can_mes_char[blok_1_sas][0]
#define SWA_H can_mes.can_mes_char[blok_1_sas][1]
#define SWA_RC can_mes.can_mes_char[blok_1_sas][2]
//#define ---	 	can_mes.can_mes_char[blok_1_sas][3]
#define SWA_R_L can_mes.can_mes_char[blok_1_sas][4]
#define SWA_R_H can_mes.can_mes_char[blok_1_sas][5]
#define R0_sas can_mes.can_mes_char[blok_1_sas][6]
#define McMc_sas can_mes.can_mes_char[blok_1_sas][7]
#define cnt_1_sas can_cnt[blok_1_sas]
#define R0_dr1 can_mes.can_mes_char[25][0]
#define R1_dr1 can_mes.can_mes_char[25][1]
#define Rain_adc can_mes.can_mes_char[25][2]
#define CDr2_cnt can_mes.can_mes_char[25][3]
#define CDr3_cnt can_mes.can_mes_char[25][4]
#define cnt_1_dr1 can_cnt[25]
#define cnt_1_edsc11 can_cnt[26]
#define cnt_1_edsc12 can_cnt[28]
#define cnt_1_edsc13 can_cnt[30]
#define cnt_1_edsc21 can_cnt[110]
#define cnt_1_edsc22 can_cnt[111]
#define cnt_1_edsc23 can_cnt[112]
#define cnt_1_dsc11 can_cnt[52]
#define cnt_1_dsc12 can_cnt[54]
#define cnt_1_dsc13 can_cnt[56]
#define cnt_1_dsc21 can_cnt[53]
#define cnt_1_dsc22 can_cnt[55]
#define cnt_1_dsc23 can_cnt[57]
#define R0_dr3 can_mes.can_mes_char[29][0]
#define R1_dr3 can_mes.can_mes_char[29][1]
#define cnt_1_dr3 can_cnt[29]
#define R0_buk can_mes.can_mes_char[31][0]
#define R1_buk can_mes.can_mes_char[31][1]
#define PWM_PNR can_mes.can_mes_char[31][7]
#define cnt_1_buk can_cnt[31]
#define R0_bak can_mes.can_mes_char[37][0]
#define cnt_1_bak can_cnt[37]
#define R0_con1 can_mes.can_mes_char[41][0]
#define Tyst_con1 can_mes.can_mes_char[41][1]
#define Tsal_con1 can_mes.can_mes_char[41][2]
#define Tout_con1 can_mes.can_mes_char[41][3]
#define Mode_con1 can_mes.can_mes_char[41][4]
#define CO2_con1 can_mes.can_mes_char[41][5]
#define Ver_con1 can_mes.can_mes_char[41][6]
#define cnt_con1 can_mes.can_mes_char[41][7]
#define cnt_1_con can_cnt[41]
#define R0_con2 can_mes.can_mes_char[42][0]
#define Tyst_con2 can_mes.can_mes_char[42][1]
#define Tsal_con2 can_mes.can_mes_char[42][2]
#define Tout_con2 can_mes.can_mes_char[42][3]
#define Mode_con2 can_mes.can_mes_char[42][4]
#define CO2_con2 can_mes.can_mes_char[42][5]
#define Ver_con2 can_mes.can_mes_char[42][6]
#define cnt_con2 can_mes.can_mes_char[42][7]
#define cnt_2_con can_cnt[42]
#define R0_tah can_mes.can_mes_char[43][0]
#define R1_tah can_mes.can_mes_char[43][1]
#define R2_tah can_mes.can_mes_char[43][2]
#define R3_tah can_mes.can_mes_char[43][3]
#define V1_tah_L can_mes.can_mes_char[43][4]
#define V1_tah_H can_mes.can_mes_char[43][5]
#define V2_tah_L can_mes.can_mes_char[43][6]
#define V2_tah_H can_mes.can_mes_char[43][7]
#define cnt_1_tah can_cnt[43]
#define R0_Ecas can_mes.can_mes_char[44][0]
#define R0_Psy can_mes.can_mes_char[44][1]
#define Cnt_Ecas can_mes.can_mes_char[44][2]
#define R4_tah can_mes.can_mes_char[44][3]
#define R5_tah can_mes.can_mes_char[44][4]
#define R6_tah can_mes.can_mes_char[44][5]
#define Cnt_kakam can_mes.can_mes_char[44][6]
#define cnt_4_tah can_cnt[44]
#define R0_y64 can_mes.can_mes_char[51][0]
#define PwY_y64 can_mes.can_mes_char[51][1]
#define Ryt_y64 can_mes.can_mes_char[51][2]
#define Iyt_y64 can_mes.can_mes_char[51][3]
#define Fvr_y64L can_mes.can_mes_char[51][4]
#define Fvr_y64H can_mes.can_mes_char[51][5]
#define ver1_y64 can_mes.can_mes_char[51][6]
#define ver2_y64 can_mes.can_mes_char[51][7]
#define cnt_1_y64 can_cnt[51]
#define Up0_psy can_mes.can_mes_char[59][0]
#define Up1_psy can_mes.can_mes_char[59][1]
#define Up2_psy can_mes.can_mes_char[59][2]
#define Up3_psy can_mes.can_mes_char[59][3]
#define Up4_psy can_mes.can_mes_char[59][4]
#define Up5_psy can_mes.can_mes_char[59][5]
#define Up6_psy can_mes.can_mes_char[59][6]
#define Up7_psy can_mes.can_mes_char[59][7]
#define cnt_1_psy can_cnt[59]
#define cnt_2_psy can_cnt[60]
#define PolStAngle can_mes.can_mes_char[61][6]
#define cnt_3_psy can_cnt[61]
#define I11_tyl can_mes.can_mes_char[64][0]
#define I12_tyl can_mes.can_mes_char[64][1]
#define I21_tyl can_mes.can_mes_char[64][2]
#define I22_tyl can_mes.can_mes_char[64][3]
#define I31_tyl can_mes.can_mes_char[64][4]
#define I32_tyl can_mes.can_mes_char[64][5]
#define I41_tyl can_mes.can_mes_char[64][6]
#define I42_tyl can_mes.can_mes_char[64][7]
#define cnt_3_tyl can_cnt[64]
#define I51_tyl can_mes.can_mes_char[65][0]
#define I52_tyl can_mes.can_mes_char[65][1]
#define I61_tyl can_mes.can_mes_char[65][2]
#define I62_tyl can_mes.can_mes_char[65][3]
#define I71_tyl can_mes.can_mes_char[65][4]
#define I72_tyl can_mes.can_mes_char[65][5]
#define ad0_tyl can_mes.can_mes_char[65][6]
#define ad1_tyl can_mes.can_mes_char[65][7]
#define cnt_4_tyl can_cnt[65]
#define no_err_(x) can_mes.can_mes_char[66][x]
#define m_err_(x) can_mes.can_mes_char[66][x + 4]
#define cnt_5_tyl can_cnt[66]
#define c_secs can_mes.can_mes_char[67][0]
#define c_mins can_mes.can_mes_char[67][1]
#define c_hours can_mes.can_mes_char[67][2]
#define c_days can_mes.can_mes_char[67][3]
#define c_mons can_mes.can_mes_char[67][4]
#define c_years can_mes.can_mes_char[67][5]
#define bat1 can_mes.can_mes_char[67][6]
#define bat2 can_mes.can_mes_char[67][7]
#define cnt_2_ind can_cnt[67]
#define I_PTA can_mes.can_mes_char[69][0]
#define I_lk can_mes.can_mes_char[69][1]
#define T_PTA can_mes.can_mes_char[69][2]
#define I_sfn can_mes.can_mes_char[69][3]
#define CnErr2 can_mes.can_mes_char[69][4]
#define cnt_4_irb can_cnt[69]
#define I11_kab can_mes.can_mes_char[71][0]
#define I12_kab can_mes.can_mes_char[71][1]
#define I21_kab can_mes.can_mes_char[71][2]
#define I22_kab can_mes.can_mes_char[71][3]
#define I31_kab can_mes.can_mes_char[71][4]
#define I32_kab can_mes.can_mes_char[71][5]
#define I41_kab can_mes.can_mes_char[71][6]
#define I42_kab can_mes.can_mes_char[71][7]
#define cnt_2_kab can_cnt[71]
#define I51_kab can_mes.can_mes_char[72][0]
#define I52_kab can_mes.can_mes_char[72][1]
#define I61_kab can_mes.can_mes_char[72][2]
#define I62_kab can_mes.can_mes_char[72][3]
#define I71_kab can_mes.can_mes_char[72][4]
#define I72_kab can_mes.can_mes_char[72][5]
#define ad0_kab can_mes.can_mes_char[72][6]
#define ad1_kab can_mes.can_mes_char[72][7]
#define cnt_3_kab can_cnt[72]
#define P1_kab_L can_mes.can_mes_char[73][0]
#define P1_kab_H can_mes.can_mes_char[73][1]
#define P2_kab_L can_mes.can_mes_char[73][2]
#define P2_kab_H can_mes.can_mes_char[73][3]
#define P3_kab_L can_mes.can_mes_char[73][4]
#define P3_kab_H can_mes.can_mes_char[73][5]
#define P4_kab_L can_mes.can_mes_char[73][6]
#define P4_kab_H can_mes.can_mes_char[73][7]
#define cnt_4_kab can_cnt[73]
#define I11_dr1 can_mes.can_mes_char[74][0]
#define I12_dr1 can_mes.can_mes_char[74][1]
#define I21_dr1 can_mes.can_mes_char[74][2]
#define I22_dr1 can_mes.can_mes_char[74][3]
#define I31_dr1 can_mes.can_mes_char[74][4]
#define I32_dr1 can_mes.can_mes_char[74][5]
#define I41_dr1 can_mes.can_mes_char[74][6]
#define I42_dr1 can_mes.can_mes_char[74][7]
#define cnt_2_dr1 can_cnt[74]
#define I51_dr1 can_mes.can_mes_char[75][0]
#define I52_dr1 can_mes.can_mes_char[75][1]
#define I61_dr1 can_mes.can_mes_char[75][2]
#define I62_dr1 can_mes.can_mes_char[75][3]
#define I71_dr1 can_mes.can_mes_char[75][4]
#define I72_dr1 can_mes.can_mes_char[75][5]
#define ad0_dr1 can_mes.can_mes_char[75][6]
#define ad1_dr1 can_mes.can_mes_char[75][7]
#define cnt_3_dr1 can_cnt[75]
#define I11_dr3 can_mes.can_mes_char[80][0]
#define I12_dr3 can_mes.can_mes_char[80][1]
#define I21_dr3 can_mes.can_mes_char[80][2]
#define I22_dr3 can_mes.can_mes_char[80][3]
#define I31_dr3 can_mes.can_mes_char[80][4]
#define I32_dr3 can_mes.can_mes_char[80][5]
#define I41_dr3 can_mes.can_mes_char[80][6]
#define I42_dr3 can_mes.can_mes_char[80][7]
#define cnt_2_dr3 can_cnt[80]
#define I51_dr3 can_mes.can_mes_char[81][0]
#define I52_dr3 can_mes.can_mes_char[81][1]
#define I61_dr3 can_mes.can_mes_char[81][2]
#define I62_dr3 can_mes.can_mes_char[81][3]
#define I71_dr3 can_mes.can_mes_char[81][4]
#define I72_dr3 can_mes.can_mes_char[81][5]
#define ad0_dr3 can_mes.can_mes_char[81][6]
#define ad1_dr3 can_mes.can_mes_char[81][7]
#define cnt_3_dr3 can_cnt[81]
#define I11_frn can_mes.can_mes_char[83][0]
#define I12_frn can_mes.can_mes_char[83][1]
#define I21_frn can_mes.can_mes_char[83][2]
#define I31_frn can_mes.can_mes_char[83][3]
#define I42_frn can_mes.can_mes_char[83][4]
#define I51_frn can_mes.can_mes_char[83][5]
#define I52_frn can_mes.can_mes_char[83][6]
#define I61_frn can_mes.can_mes_char[83][7]
#define cnt_3_frn can_cnt[83]
#define I62_frn can_mes.can_mes_char[84][0]
#define I71_frn can_mes.can_mes_char[84][1]
#define I72_frn can_mes.can_mes_char[84][2]
#define I81_frn can_mes.can_mes_char[84][3]
#define I82_frn can_mes.can_mes_char[84][4]
#define I91_frn can_mes.can_mes_char[84][5]
#define I92_frn can_mes.can_mes_char[84][6]
#define ad1_frn can_mes.can_mes_char[84][7]
#define cnt_4_frn can_cnt[84]
#define I11_buk can_mes.can_mes_char[86][0]
#define I12_buk can_mes.can_mes_char[86][1]
#define I21_buk can_mes.can_mes_char[86][2]
#define I22_buk can_mes.can_mes_char[86][3]
#define I31_buk can_mes.can_mes_char[86][4]
#define I32_buk can_mes.can_mes_char[86][5]
#define I41_buk can_mes.can_mes_char[86][6]
#define I42_buk can_mes.can_mes_char[86][7]
#define cnt_2_buk can_cnt[86]
#define I51_buk can_mes.can_mes_char[87][0]
#define I52_buk can_mes.can_mes_char[87][1]
#define I61_buk can_mes.can_mes_char[87][2]
#define I62_buk can_mes.can_mes_char[87][3]
#define I71_buk can_mes.can_mes_char[87][4]
#define I72_buk can_mes.can_mes_char[87][5]
#define ad0_buk can_mes.can_mes_char[87][6]
#define ad1_buk can_mes.can_mes_char[87][7]
#define cnt_3_buk can_cnt[87]
#define Hrtv_L can_mes.can_mes_char[95][0]
#define Hrtv_H can_mes.can_mes_char[95][1]
#define Hrtv_M can_mes.can_mes_char[95][2]
#define Hrtv_U can_mes.can_mes_char[95][3]
#define Hrvt_L can_mes.can_mes_char[95][4]
#define Hrvt_H can_mes.can_mes_char[95][5]
#define Hrvt_M can_mes.can_mes_char[95][6]
#define Hrvt_U can_mes.can_mes_char[95][7]
#define cnt_2_tah can_cnt[95]
#define tsecs can_mes.can_mes_char[96][0]
#define tmins can_mes.can_mes_char[96][1]
#define thours can_mes.can_mes_char[96][2]
#define tmons can_mes.can_mes_char[96][3]
#define tdays can_mes.can_mes_char[96][4]
#define tyears can_mes.can_mes_char[96][5]
#define tminoff can_mes.can_mes_char[96][6]
#define thouroff can_mes.can_mes_char[96][7]
#define cnt_3_tah can_cnt[96]
#define R2_brp can_mes.can_mes_char[101][0]
#define R3_brp can_mes.can_mes_char[101][1]
#define R4_brp can_mes.can_mes_char[101][2]
#define R5_brp can_mes.can_mes_char[101][3]
#define R6_brp can_mes.can_mes_char[101][4]
#define R7_brp can_mes.can_mes_char[101][5]
#define R8_brp can_mes.can_mes_char[101][6]
#define R9_brp can_mes.can_mes_char[101][7]
#define cnt_2_brp can_cnt[101]
//*********************************************************************************************************************************************************************************//
//----------------------------------------------------------------------------------
//Инициализация битовых переменных
//----------------------------------------------------------------------------------
//--------Тыл----(быстрые)----------------------------------------------------------------------------------------
#define SP_ER_GOT              \
    can_mes.can_mes_1bit[8][5] \
            .b0 // 1 - обнаружен скачёк скорости более 500кнуцев
#define AVDU_extroOFF \
    can_mes.can_mes_1bit[8][5].b1 // 1 - необходимо разомкнуть АВДУ
#define SP_ER4_GOT \
    can_mes.can_mes_1bit[8][5].b2 // 1 - обнаружен скачёк скорости более
                                  // 500кнуцев у датчика на каждый 4ый зуб
//#define	---			can_mes.can_mes_1bit[8][5].b2	//1 -
#define DCV1Zone               \
    can_mes.can_mes_1bit[8][5] \
            .b4 // 1 - достигнута зона 1 (переход на скорость от 1го датчика)
#define DCV4Zone \
    can_mes.can_mes_1bit[8][5].b5 // 1 - достигнута зона 2 (переход на скорость
                                  // от датчика на каждый 4ый)
#define Sens_SIN \
    can_mes.can_mes_1bit[8][5].b6 //лог состояние 1 датчика скорости
#define Sens_COS \
    can_mes.can_mes_1bit[8][5].b7 //лог состояние 2 датчика скорости
//--------Фронт--(быстрые)----------------------------------------------------------------------------------------
#define Xod can_mes.can_mes_1bit[9][2].b0     // 1 - нажат ход
#define Torm_AT can_mes.can_mes_1bit[9][2].b1 // 1 - нажат тормоз
//--------МС_can-(быстрые)----------------------------------------------------------------------------------------
//-10-0
#define PredZar can_mes.can_mes_1bit[10][0].b5 // 1 - Предзаряд запитан
#define PowLK can_mes.can_mes_1bit[10][0].b6 // 1 - Процессор Ирбиса запитан
//-10-1
#define Pow_Avtomat \
    can_mes.can_mes_1bit[10][1].b0 // 1 - Есть 24в в проводе питания автомата..
#define Pow_Fan                 \
    can_mes.can_mes_1bit[10][1] \
            .b1 // 1 - Есть 24в в проводе питания вентиллятора..
#define err_pr14 \
    can_mes.can_mes_1bit[10][1].b2 // 1 - больше 0.5сек не исчезают защщты ПТА..
#define err_3_opto              \
    can_mes.can_mes_1bit[10][1] \
            .b3 // 1 - давно не было сигнала от 3-го оптокабеля..
#define Avaria_PTA              \
    can_mes.can_mes_1bit[10][1] \
            .b4 // 1 - aварийное превышение напряжение конт сети у ирбисов
#define text_p18                \
    can_mes.can_mes_1bit[10][1] \
            .b5 // 1 - сообщи водителю почему не работает педаль..
#define pta_akt \
    can_mes.can_mes_1bit[10][1].b6 // 1 - ПТА в контакте с блоком "МС CAN"
//-10-6
#define FReady \
    can_mes.can_mes_1bit[10][6].b0 // 1 = электропривод готов к
                                   // работе
#define FRun \
    can_mes.can_mes_1bit[10][6].b1 // 1 = электропривод включен в
                                   // работу
#define FAlarm                  \
    can_mes.can_mes_1bit[10][6] \
            .b2 // 1 = сработала какая-то защита электропривода
#define FBrake \
    can_mes.can_mes_1bit[10][6].b3 // 1 = тормозной резистор включен в работу
#define FRegen \
    can_mes.can_mes_1bit[10][6].b4 // 1 = рекуперация энергии в конт. сеть
#define FField                  \
    can_mes.can_mes_1bit[10][6] \
            .b5 // 1 = постоянство мощности при частоте вращения
                // электродвигателя выше номинальной
#define FIlim \
    can_mes.can_mes_1bit[10][6].b6 // 1 = режим ограничения фазового тока
#define FAjust can_mes.can_mes_1bit[10][6].b7 // 1 = режим настройки
//-10-7
#define FStr \
    can_mes.can_mes_1bit[10][7].b0 // 1 = включается режим перевода стрелки
#define FBrk                    \
    can_mes.can_mes_1bit[10][7] \
            .b1 // 1 = переход в режим рекуперации энергии в контактную сеть.
                // (Устанавливается при нажатии на педаль тормоза).
#define FRes \
    can_mes.can_mes_1bit[10][7].b2 // 1 = сброс сбрасываемых защит
                                   // электропривода
#define FAut can_mes.can_mes_1bit[10][7].b3 // 1 = включен автономный ход
#define FDir can_mes.can_mes_1bit[10][7].b4 // 1 = назад
#define FUpr2 \
    can_mes.can_mes_1bit[10][7].b5 //  \ 111 = включение электропривода
#define FUpr3 \
    can_mes.can_mes_1bit[10][7].b6 //  / 000 = выключение электропривода
#define FUpr4 can_mes.can_mes_1bit[10][7].b7 // /
//-12-0
#define DrivR2                  \
    can_mes.can_mes_1bit[12][0] \
            .b0 // 1 = сраб защита драйвера ключа R2 рекуператора
#define DrivR1                  \
    can_mes.can_mes_1bit[12][0] \
            .b1 // 1 = сраб защита драйвера ключа R1 рекуператора
#define DrivW2 \
    can_mes.can_mes_1bit[12][0].b2 // 1 = сраб защита драйвера ключа W2
                                   // инвертора
#define DrivW1 \
    can_mes.can_mes_1bit[12][0].b3 // 1 = сраб защита драйвера ключа W1
                                   // инвертора
#define DrivV2 \
    can_mes.can_mes_1bit[12][0].b4 // 1 = сраб защита драйвера ключа V2
                                   // инвертора
#define DrivV1 \
    can_mes.can_mes_1bit[12][0].b5 // 1 = сраб защита драйвера ключа V1
                                   // инвертора
#define DrivU2 \
    can_mes.can_mes_1bit[12][0].b6 // 1 = сраб защита драйвера ключа U2
                                   // инвертора
#define DrivU1 \
    can_mes.can_mes_1bit[12][0].b7 // 1 = сраб защита драйвера ключа U1
                                   // инвертора
//-12-1
#define Fuse \
    can_mes.can_mes_1bit[12][1].b0 // 1 = сработал предохранитель контактной
                                   // сети
#define Tmax can_mes.can_mes_1bit[12][1].b1 // 1 = перегрев силовых ключей
#define Imax \
    can_mes.can_mes_1bit[12][1].b2 // 1 = превышение фазного тока двигателя
#define Us_min \
    can_mes.can_mes_1bit[12][1].b3 // 1 = пониж напряж питания системы
                                   // управления
#define U0_max \
    can_mes.can_mes_1bit[12][1].b4 // 1 = пониж напряж контактной
                                   // сети
#define Imax_app                \
    can_mes.can_mes_1bit[12][1] \
            .b5 // 1 = превышения фазного тока электродвигателя
#define Ud_max                  \
    can_mes.can_mes_1bit[12][1] \
            .b6 // 1 = повыш напряж звена пост тока(конденсатор)
#define DrivBr \
    can_mes.can_mes_1bit[12][1].b7 // 1 = сраб защита драйвера ключа Br
                                   // инвертора
//-12-2
#define I1_sys                  \
    can_mes.can_mes_1bit[12][2] \
            .b0 // 1 = ограничения фазного тока электродвигателя
#define I0max can_mes.can_mes_1bit[12][2].b1 // 1 = превышение входного тока
#define Iw_disc                 \
    can_mes.can_mes_1bit[12][2] \
            .b2 // 1 = сработала защита от неисправности датчика тока фазы W
#define Iv_disc                 \
    can_mes.can_mes_1bit[12][2] \
            .b3 // 1 = сработала защита от неисправности датчика тока фазы V
#define Iu_disc                 \
    can_mes.can_mes_1bit[12][2] \
            .b4 // 1 = сработала защита от неисправности датчика тока фазы U
#define FoltE2 \
    can_mes.can_mes_1bit[12][2].b5 // 1 = сработала защита от неисправности
                                   // энергонезависимой памяти платы ПУ94
#define FNoIK1                  \
    can_mes.can_mes_1bit[12][2] \
            .b6 // 1 = отсутствует связь с управляющим контроллером
#define FoltBraking \
    can_mes.can_mes_1bit[12][2].b7 // 1 = неисправности элементов цепи сброса
                                   // энергии торможения в балластный резистор
//-12-3
#define FoltParAD \
    can_mes.can_mes_1bit[12][3].b5 // 1 = сработала защита от неправильного
                                   // ввода параметров двигателя
#define BreakBrk \
    can_mes.can_mes_1bit[12][3].b6 // 1 = неисправность драйвера или самого
                                   // транзисторного ключа Br (разрыв)
#define ShortBrk                \
    can_mes.can_mes_1bit[12][3] \
            .b7 // 1 = неисправность балластного резистора (разрыв),
//--------EBS----------------------------------------------------------------------------------------------------
// 13-1
#define Torm_EBS can_mes.can_mes_1bit[13][1].b0 // 1 - нажат тормоз
#define StopSignal \
    can_mes.can_mes_1bit[13][1].b1 // 1 - необходимо зажечь стоп сигнал
#define Torm_state can_mes.can_mes_1bit[13][1].b2 //
// 13-3
#define EBS_RW can_mes.can_mes_1bit[13][3].b0 // Красный сигнал тревоги EBS
#define EBS_AW can_mes.can_mes_1bit[13][3].b1 // Жёлтый сигнал тревоги EBS
#define ASR_TC_MIG can_mes.can_mes_1bit[13][3].b2 // Жёлтый сигнал TC мигать
#define ASR_TC_NOT can_mes.can_mes_1bit[13][3].b3 // Жёлтый сигнал TC_NOT горит
#define ESC_BUS_MIG can_mes.can_mes_1bit[13][3].b4 // Жёлтый сигнал BUS мигать
#define ESC_BUS can_mes.can_mes_1bit[13][3].b5 // Жёлтый сигнал BUS горит
#define ESC_BUS_NOT \
    can_mes.can_mes_1bit[13][3].b6 // Жёлтый сигнал BUS_NOT горит
// 13-4
#define HIL_HOLD can_mes.can_mes_1bit[13][4].b0 // Жёлтый сигнал BUS_naklon
#define HIL_HOLD_MIG \
    can_mes.can_mes_1bit[13][4].b1 // Жёлтый сигнал BUS_naklon мигать
#define EBS_Brake_Switch \
    can_mes.can_mes_1bit[13][4].b2 // 1 - Сигнал о нажатии педали от ЕБС
#define Foundation_Brake_Use \
    can_mes.can_mes_1bit[13][4].b3 // 1 - Сигнал о срабатывании тормозов от ЕБС
#define Emergency_Braking_Active \
    can_mes.can_mes_1bit[13][4].b4 // 1 - Сигнал об аварийном торможении от ЕБС
#define Anti_Lock_Braking_ABS_Active \
    can_mes.can_mes_1bit[13][4].b5 // 1 - Активна система АБС
#define HIL_HOLD_ON \
    can_mes.can_mes_1bit[13][4].b6 // 1 - Включена система Hill Hold
#define Halt_brake_switch \
    can_mes.can_mes_1bit[13][4].b7 // 1 -
                                   // Halt_brake_switch
//--------БРП-03-------------------------------------------------------------------------------------------------
// 15-5
#define Akb_got_ON can_mes.can_mes_1bit[15][5].b0 // 1 - Принята команда вкл Акб
#define Akb_state \
    can_mes.can_mes_1bit[15][5].b1 // 1 - Состояние контактора Акб замкнут
#define Akb_ON_stable \
    can_mes.can_mes_1bit[15][5].b2 // 1 - Контактор Акб гарантировано замкнут
                                   // (питание не просело при замыкании)
#define Akb_ON_Error \
    can_mes.can_mes_1bit[15][5].b3 // 1 - Ошибка включения контактора Акб
#define Gyr_got_ON can_mes.can_mes_1bit[15][5].b4 // 1 - Принята команда вкл Гур
#define Gyr_state \
    can_mes.can_mes_1bit[15][5].b5 // 1 - Состояние контактора Гур замкнут
#define Gyr_ON_stable \
    can_mes.can_mes_1bit[15][5].b6 // 1 - Контактор Гур гарантировано замкнут
                                   // (питание не просело при замыкании)
#define Gyr_ON_Error \
    can_mes.can_mes_1bit[15][5].b7 // 1 - Ошибка включения контактора Гур
// 15-6
//#define	---			can_mes.can_mes_1bit[15][6].b0	// 1 -
//#define	---			can_mes.can_mes_1bit[15][6].b1	// 1 -
#define Akb_was_Error           \
    can_mes.can_mes_1bit[15][6] \
            .b2 // 1 - Была зафиксирована ошибка включения Акб
#define Gyr_was_Error           \
    can_mes.can_mes_1bit[15][6] \
            .b3 // 1 - Была зафиксирована ошибка включения Гур
#define En12v_ON                \
    can_mes.can_mes_1bit[15][6] \
            .b4 // 1 - цепи измерения тока и второй половины запитаны
#define SpNotLow_got            \
    can_mes.can_mes_1bit[15][6] \
            .b5 // 1 - Получена команда о появлении скорости >1км/ч
#define Pow_Low                 \
    can_mes.can_mes_1bit[15][6] \
            .b6 // 1 - Зафиксировано снижение напряжения ниже 16v
#define Got_Jumper \
    can_mes.can_mes_1bit[15][6].b7 // 1 - Джампер на контакте программирования
//--------Фронт--------------------------------------------------------------------------------------------------
//-16-0
#define K_Horn \
    can_mes.can_mes_1bit[16][0].b0 // 1 - замкнут контакт "Сирена"
                                   // ,X4_01
#define K_Washer \
    can_mes.can_mes_1bit[16][0].b1 // 1 - замкнут контакт "Поливалка стекла"
                                   // ,X4_02
#define Oil \
    can_mes.can_mes_1bit[16][0].b2 // 1 - уровень масла - в норме
                                   // ,X4_03
#define K_En_PTA \
    can_mes.can_mes_1bit[16][0].b3 // 1 - замкнут контакт "Вкл ПТА"
                                   // ,X4_04
#define K_Dis_PTA \
    can_mes.can_mes_1bit[16][0].b4 // 1 - замкнут контакт "Выкл ПТА"
                                   // ,X4_05
#define K_Right \
    can_mes.can_mes_1bit[16][0].b5 // 1 - разрешен правый поворот
                                   // ,X4_07
#define K_Left \
    can_mes.can_mes_1bit[16][0].b6 // 1 - разрешен левый поворот
                                   // ,X4_08
#define K_Wiper_S \
    can_mes.can_mes_1bit[16][0].b7 // 1 - замкнут контакт "Дворник медленно"
                                   // ,X4_10
//-16-1
#define K_Wiper_F \
    can_mes.can_mes_1bit[16][1].b0 // 1 - замкнут контакт "Дворник быстро"
                                   // ,X4_11
#define K_High_Low \
    can_mes.can_mes_1bit[16][1].b1 // 1 - замкнут контакт "Дальний/ближний свет"
                                   // ,X4_13
#define K_High_Flash \
    can_mes.can_mes_1bit[16][1].b2 // 1 - замкнут контакт "Моргнуть дальним
                                   // светом"		,X4_14
#define K_Wiper_T \
    can_mes.can_mes_1bit[16][1].b3 // 1 - замкнут контакт "Дворник прерывисто"
                                   // ,X4_15
#define stat_wiper \
    can_mes.can_mes_1bit[16][1].b4 // 1 - замкнут контакт в дворнике
                                   // ,X6_09
#define PP_Lamp_Mark \
    can_mes.can_mes_1bit[16][1].b5 // 1 - замкнут контакт габариты на подрулевом
                                   // п.		,X6_11
#define PP_Lamp_Head            \
    can_mes.can_mes_1bit[16][1] \
            .b6 // 1 - замкнут контакт ближний свет на подрулевом п.	,X6_14
#define Termo_KontAB \
    can_mes.can_mes_1bit[16][1].b7 // 1 - замкнут термоконтакт печки водителя
                                   // ,X6_17
//-16-2
#define Front_PowA1 \
    can_mes.can_mes_1bit[16][2].b0 // 1 - есть питание "A1" у блока "фронт"
#define K_Door_Close            \
    can_mes.can_mes_1bit[16][2] \
            .b1 // 1 - замкнут наружный контакт "закрывания 1 двери"	,X5_14
#define K_Door_Open             \
    can_mes.can_mes_1bit[16][2] \
            .b2 // 1 - замкнут наружный контакт "Открывания 1 двери"	,X5_17
#define Front_PowA2 \
    can_mes.can_mes_1bit[16][2].b3 // 1 - есть питание "A2" у блока "фронт"
#define UP_ECS can_mes.can_mes_1bit[16][2].b4 // команда поднятия уровня
#define DOWN_ECS can_mes.can_mes_1bit[16][2].b5 // команда опускания уровня
#define TRANS_ECS \
    can_mes.can_mes_1bit[16][2].b6 // команда установки транспортного уровня
#define NAKL_ECS can_mes.can_mes_1bit[16][2].b7 // команда наклона
//-16-3
#define En_Lamp_Fog \
    can_mes.can_mes_1bit[16][3].b0 // 1 - разрешен задний противотуманный свет
#define En_Lamp_Mark \
    can_mes.can_mes_1bit[16][3].b1 // 1 - разрешен габаритный свет
#define En_Lamp_Dezur \
    can_mes.can_mes_1bit[16][3].b2 // 1 - включено дежурное освещение
#define SpeedNotLow can_mes.can_mes_1bit[16][3].b3 // 1 - Скорость не близка к 0
#define En_Blinker \
    can_mes.can_mes_1bit[16][3].b4 // 1 - период горения ламп поворотников
#define En_alarm_sign \
    can_mes.can_mes_1bit[16][3].b5 // 1 - разрешена аварийная сигнализация
#define En_AutoXod \
    can_mes.can_mes_1bit[16][3].b6 // 1 - разрешен AutoXod или Маневр
#define Gyr_ON_com              \
    can_mes.can_mes_1bit[16][3] \
            .b7 // 1 - команда включения контактора гидроусилителя руля
//-16-4
#define Akb_ON_com \
    can_mes.can_mes_1bit[16][4].b0 // 1 - Дана команда на вкл контактора АКБ
#define K_Forv_frn \
    can_mes.can_mes_1bit[16][4].b1 // 1 - Нажата кнопка вперед на баяне фронта
#define K_Neit_frn \
    can_mes.can_mes_1bit[16][4].b2 // 1 - Нажата кнопка нейтраль на баяне фронта
#define K_Reve_frn \
    can_mes.can_mes_1bit[16][4].b3 // 1 - Нажата кнопка реверс на баяне фронта
#define K_off_AVDU \
    can_mes.can_mes_1bit[16][4].b4 // 1 - нажата клава выключение АВДУ
#define K_on_AVDU \
    can_mes.can_mes_1bit[16][4].b5 // 1 - нажата клава включение АВДУ
#define beep_bajan \
    can_mes.can_mes_1bit[16][4].b6 // 1 - надо пропищять от клавиш баяна
#define En_Shtang_Light \
    can_mes.can_mes_1bit[16][4].b7 // 1 - Разрешено освещение штанг
//-16-5
#define open_door0 can_mes.can_mes_1bit[16][5].b0 // 1 - команда открыть дверь 0
#define close_door0 \
    can_mes.can_mes_1bit[16][5].b1 // 1 - команда закрыть дверь
                                   // 0
#define open_door1 can_mes.can_mes_1bit[16][5].b2 // 1 - команда открыть дверь 1
#define close_door1 \
    can_mes.can_mes_1bit[16][5].b3 // 1 - команда закрыть дверь
                                   // 1
#define open_door2 can_mes.can_mes_1bit[16][5].b4 // 1 - команда открыть дверь 2
#define close_door2 \
    can_mes.can_mes_1bit[16][5].b5 // 1 - команда закрыть дверь
                                   // 2
#define open_door3 can_mes.can_mes_1bit[16][5].b6 // 1 - команда открыть дверь 3
#define close_door3 \
    can_mes.can_mes_1bit[16][5].b7 // 1 - команда закрыть дверь
                                   // 3
//-16-6
#define Left_strelka \
    can_mes.can_mes_1bit[16][6].b0 // 1 - включен режим "левая стрелка"
#define Right_strelka \
    can_mes.can_mes_1bit[16][6].b1 // 1 - включен режим "правая стрелка"
#define En_Akkum \
    can_mes.can_mes_1bit[16][6].b2 // 1 - разрешено питание цепей А/В
#define En_P                    \
    can_mes.can_mes_1bit[16][6] \
            .b3 // 1 - разрешено открытие дверей с кнопок на дверях
#define OFF_CC_Kabin \
    can_mes.can_mes_1bit[16][6].b4 // 1 - нажата кнопка печи кабины нужно
                                   // отключить климат контроль кабины
#define OFF_CC_Salon \
    can_mes.can_mes_1bit[16][6].b5 // 1 - нажата кнопка печи салона нужно
                                   // отключить климат контроль салона
#define En_Lamp_FogF \
    can_mes.can_mes_1bit[16][6].b6 // 1 - разрешен передний противотуманный свет
#define En_Booster \
    can_mes.can_mes_1bit[16][6].b7 // 1 - Включение работы гидроусилителя руля
//-16-7
#define En_RainSensor can_mes.can_mes_1bit[16][7].b0 // 1 - Включен датчик дождя
#define En_Lamp_Kabin \
    can_mes.can_mes_1bit[16][7].b1 // 1 - разрешено освещение кабины
#define En_Lamp_Salon1 \
    can_mes.can_mes_1bit[16][7].b2 // 1 - разрешен освещение салона 1
#define En_Lamp_Salon2 \
    can_mes.can_mes_1bit[16][7].b3 // 1 - разрешен освещение салона 2
#define En_Tablo can_mes.can_mes_1bit[16][7].b4 // 1 - разрешено питание табло
#define key_Fan_drive \
    can_mes.can_mes_1bit[16][7].b5 // 1 - нажата кнопка обдува фронтальной печи
#define En_Kompressor \
    can_mes.can_mes_1bit[16][7].b6 // 1 - разрешено питание реле компрессора
#define En_PNR can_mes.can_mes_1bit[16][7].b7 // 1 - разрешено питание реле ПНР
//-17-0
#define En_Heating_AB \
    can_mes.can_mes_1bit[17][0].b0 // 1 - разрешено питание реле печки A (Бук)
#define En_Heating_O \
    can_mes.can_mes_1bit[17][0].b1 // 1 - разрешено питание реле печки B (Бук)
#define En_Heating_C \
    can_mes.can_mes_1bit[17][0].b2 // 1 - разрешено питание реле печки C (Бук)
#define En_Heating_D \
    can_mes.can_mes_1bit[17][0].b3 // 1 - разрешено питание реле печки D (Бук)
#define En_Heating_E \
    can_mes.can_mes_1bit[17][0].b4 // 1 - разрешено питание реле печки E (Бук)
#define En_Heating_F \
    can_mes.can_mes_1bit[17][0].b5 // 1 - разрешено питание реле печки F (Бук)
#define En_Heat_mirror \
    can_mes.can_mes_1bit[17][0].b6 // 1 - разрешено питание обогрева зеркалл
#define En_Heat_glass \
    can_mes.can_mes_1bit[17][0].b7 // 1 - разрешен обогрев стекла
//-17-1
#define En_Butt_Heat \
    can_mes.can_mes_1bit[17][1].b0 // 1 - разрешен подоогрев сидения водителя
#define motor_low \
    can_mes.can_mes_1bit[17][1].b1 // 1 - обдув фронтальной печи скорость 1
#define motor_high \
    can_mes.can_mes_1bit[17][1].b2 // 1 - обдув фронтальной печи скорость 2
#define auto_L_Head can_mes.can_mes_1bit[17][1].b3 // 1 - авто головной свет
#define key_alarm_sist \
    can_mes.can_mes_1bit[17][1].b4 // 1 - Нажата кнопка катапультирования
#define En_Charge can_mes.can_mes_1bit[17][1].b5 // 1 - разрешена зарядка
#define En_Head_Lamp \
    can_mes.can_mes_1bit[17][1].b6 // 1 - Включёно головное освещение
#define isDay can_mes.can_mes_1bit[17][1].b7 // 1 - дневной режим
//-17-2
#define Act_osysh \
    can_mes.can_mes_1bit[17][2].b0 // 1 - Включение осушителя принудительно
#define App_warning             \
    can_mes.can_mes_1bit[17][2] \
            .b1 // 1 - Сигнал о не возможности закрыть дверь из за аппарели
#define En_LampDekor \
    can_mes.can_mes_1bit[17][2].b2 // 1 - Включено декоративное освещение
//#define	---			can_mes.can_mes_1bit[17][2].b3	//1 -
#define En_FanC \
    can_mes.can_mes_1bit[17][2].b4 // 1 - необходим продув отопителя C
#define En_FanD \
    can_mes.can_mes_1bit[17][2].b5 // 1 - необходим продув отопителя D
#define En_FanE \
    can_mes.can_mes_1bit[17][2].b6 // 1 - необходим продув отопителя E
#define En_FanF \
    can_mes.can_mes_1bit[17][2].b7 // 1 - необходим продув отопителя F
//-17-5
#define wip_slow_on can_mes.can_mes_1bit[17][5].b0 // медл мотор включен
#define wip_fast_on can_mes.can_mes_1bit[17][5].b1 // медл мотор включен
#define ON_PSY \
    can_mes.can_mes_1bit[17][5].b2 // команда включения питания на ПШУ
#define UP_PSY can_mes.can_mes_1bit[17][5].b3 // Команда подъёма пшу
#define DOWN_PSY can_mes.can_mes_1bit[17][5].b4 // команда опускания пшу
#define En_SKOP                 \
    can_mes.can_mes_1bit[17][5] \
            .b5 // разрешено включение Система контроля оплаты проезда
#define En_WarmFloor can_mes.can_mes_1bit[17][5].b6 // 1 -
#define En_AutoEcas can_mes.can_mes_1bit[17][5].b7  // 1 -
#define K_MW1_Up \
    can_mes.can_mes_1bit[17][6].b4 // 1 - нажата кнопка мультируля вверх
#define K_MW1_Down \
    can_mes.can_mes_1bit[17][6].b5 // 1 - нажата кнопка мультируля вниз
#define K_MW1_Enter \
    can_mes.can_mes_1bit[17][6].b6 // 1 - нажата кнопка мультируля enter
#define K_MW1_Back \
    can_mes.can_mes_1bit[17][6].b7 // 1 - Нажата кнопка мультируля назад
//-------Тыл----------------------------------------------------------------------------------------------------------
//- R0_tyl
#define Termo_KontD \
    can_mes.can_mes_1bit[19][0].b0 // 1 - замкнут термоконтакт D печки ,
                                   // Test_kont_1/20 x4
#define Termo_KontF \
    can_mes.can_mes_1bit[19][0].b1 // 1 - замкнут термоконтакт F печки ,
                                   // Test_kont_2/17 x4
#define Termo_KontC \
    can_mes.can_mes_1bit[19][0].b2 // 1 - замкнут термоконтакт C печки ,
                                   // Test_kont_3/21 x4
//#define ---				can_mes.can_mes_1bit[19][0].b3	//1 -
//, Test_kont_4/14 x4
#define Termo_KontE \
    can_mes.can_mes_1bit[19][0].b4 // 1 - замкнут термоконтакт E печки ,
                                   // Test_kont_5/11 x4
#define Add_Pressure1           \
    can_mes.can_mes_1bit[19][0] \
            .b5 // 1 - недостаточно давл 1 (ком компр)	, Test_kont_6/03 x5
#define Add_Pressure2           \
    can_mes.can_mes_1bit[19][0] \
            .b6 // 1 - недостаточно давл 2 (ком компр)	, Test_kont_7/05 x5
#define Termo_Kompressor \
    can_mes.can_mes_1bit[19][0].b7 // 1 - термодатчик компрессора
                                   // , Test_kont_8/08 x5
//- R1_tyl
#define Termo_KontG \
    can_mes.can_mes_1bit[19][1].b0 // 1 - замкнут термоконтакт 3 печки Лиаб
                                   // , Test_kont_9/09 x5
//#define ---				can_mes.can_mes_1bit[19][1].b1	//1 -
//, Test_U1/20 x4 #define ---
// can_mes.can_mes_1bit[19][1].b2	//1 -
//, Test_U3/21 x4 #define ---
// can_mes.can_mes_1bit[19][1].b3	//1 -
//, Test_U6/03 x5
#define PSK_1 \
    can_mes.can_mes_1bit[19][1].b4 // 1 - диагностика компрессора
                                   // , Test_U9/09 x5
#define tyl_PowA can_mes.can_mes_1bit[19][1].b5 // 1 - Есть питание +24в(А)
//#define ---				can_mes.can_mes_1bit[19][1].b6	//1 -
//#define ---				can_mes.can_mes_1bit[19][1].b7	//1 -
//- R2_tyl
#define COND_IN_1 \
    can_mes.can_mes_1bit[19][4].b0 // 1 - Условия на включение кондея от
                                   // внешнего воздуха 1 контейнер
#define COND_IN_2 \
    can_mes.can_mes_1bit[19][4].b1 // 1 - Условия на включение кондея от
                                   // внешнего воздуха 2 контейнер
#define COND_IN_3 \
    can_mes.can_mes_1bit[19][4].b2 // 1 - Условия на включение кондея от
                                   // внешнего воздуха 3 контейнер
#define COND_IN_4 \
    can_mes.can_mes_1bit[19][4].b3 // 1 - Условия на включение кондея от
                                   // внешнего воздуха 4 контейнер
//#define	En_Heating_Liab		can_mes.can_mes_1bit[19][4].b4 //1 -
//Условия на включение Подогрева ЛИАБ
#define K_15acc \
    can_mes.can_mes_1bit[19][4].b6 // 1 - есть разрешение на работу от АХ
#define K_15com \
    can_mes.can_mes_1bit[19][4].b7 // 1 - подана команда на замыкание К15
//--------Би-04----------------------------------------------------------------------------------------------------
//-21-0
#define BI_SoundPlay can_mes.can_mes_1bit[21][0].b0
#define BI_ErrorShow can_mes.can_mes_1bit[21][0].b1
#define BI_AutoDipBeam \
    can_mes.can_mes_1bit[21][0].b2 // Автоматическое управление ближним светом
#define BI_AutoParkLight        \
    can_mes.can_mes_1bit[21][0] \
            .b3 // Автоматическое управление габаритными огнями
#define BI_AutoBrightness \
    can_mes.can_mes_1bit[21][0].b4 // Автоматическое управление яркостью экранов
#define BI_AutoShtangLight \
    can_mes.can_mes_1bit[21][0].b5 // Автоматическое управление освещением штанг
#define BI_AutoSalonLight       \
    can_mes.can_mes_1bit[21][0] \
            .b6 // Автоматическое управление овсещением салона
#define BI_ZapretPTA can_mes.can_mes_1bit[21][0].b7
#define every_slope \
    can_mes.can_mes_1bit[21][1].b0 // 0 - норм определение скорости, 1 -
                                   // прерывание на каждом фронте..
#define Forvard can_mes.can_mes_1bit[21][1].b1 // 1 - вперед
#define Revers can_mes.can_mes_1bit[21][1].b2  // 1 - назад
#define isNoch can_mes.can_mes_1bit[21][1].b3  // 1 - назад
#define BI_OpDoorAccess \
    can_mes.can_mes_1bit[21][1].b4 // 1 - Разрешено движение с открытыми дверями
//Необходимо включить подогрев кабины по климат контролю #define ---
#define BI_CondNoCan \
    can_mes.can_mes_1bit[21][1].b5 // 1 - Необходимо включить подогрев
// салона по климат контролю #define ---
// can_mes.can_mes_1bit[21][1].b6	// 1 - Включен климат контроль кабины
//#define --- can_mes.can_mes_1bit[21][1].b7	// 1 - Включен климат контроль
// салона -21-2
#define Yki0604_test can_mes.can_mes_1bit[21][2].b0 // 1 - команда тест уки
//#define ---			can_mes.can_mes_1bit[21][2].b1	// 1 -
#define TRIP_RESET \
    can_mes.can_mes_1bit[21][2].b2 // 1 - команда Сброса статистики в тахограф
#define BAKS_START \
    can_mes.can_mes_1bit[21][2].b3 // 1 - нажата кнопка "Тест Уакси"
#define BAKS_ACCES \
    can_mes.can_mes_1bit[21][2].b4 // 1 - тестирование Уакси разрешено
#define RKI_10 can_mes.can_mes_1bit[21][2].b5 // 1 - нажата кнопка "назад"
#define RKI_11 can_mes.can_mes_1bit[21][2].b6 // 1 - нажата кнопка "вперед"
#define RKI_12 can_mes.can_mes_1bit[21][2].b7 // 1 - нажата кнопка "нейтраль"
//-21-3
#define CC_Cool_Kabin \
    can_mes.can_mes_1bit[21][3].b0 // 1 - Необходимо включить охлаждение кабины
                                   // по климат контролю
#define CC_Cool_Salon \
    can_mes.can_mes_1bit[21][3].b1 // 1 - Необходимо включить охлаждение салона
                                   // по климат контролю
#define CC_HEAT_Kabin           \
    can_mes.can_mes_1bit[21][3] \
            .b2 // 1 - Необходимо включить подогрев кабины по климат контролю
#define CC_HEAT_Salon           \
    can_mes.can_mes_1bit[21][3] \
            .b3 // 1 - Необходимо включить подогрев салона по климат контролю
#define EN_CC_Kabin \
    can_mes.can_mes_1bit[21][3].b4 // 1 - Включен климат контроль кабины
#define EN_CC_Salon \
    can_mes.can_mes_1bit[21][3].b5 // 1 - Включен климат контроль салона
#define CoolFan1 can_mes.can_mes_1bit[21][3].b6
#define CoolFan2 can_mes.can_mes_1bit[21][3].b7
#define CoolFan3 can_mes.can_mes_1bit[21][4].b0
#define EN_Cool_Kabin           \
    can_mes.can_mes_1bit[21][4] \
            .b1 // 1 - разрешено включение кондиционера кабины
#define En_Cool_Salon           \
    can_mes.can_mes_1bit[21][4] \
            .b2 // 1 - разрешено включение кондиционера салона
#define CoolFanSalon1           \
    can_mes.can_mes_1bit[21][4] \
            .b3 // 1 - включена первая скорость обдува кондиционера кабины
#define CoolFanSalon2           \
    can_mes.can_mes_1bit[21][4] \
            .b4 // 1 - включена вторая скорость обдува кондиционера кабины
//-21-4
#define CoolFanSalon3           \
    can_mes.can_mes_1bit[21][4] \
            .b5 // 1 - включена третья скорость обдува кондиционера кабины
//#define ---			can_mes.can_mes_1bit[21][4].b4	// 1 - нажата
//кнопка включения хилхолдера
//#define ---			can_mes.can_mes_1bit[21][4].b5	//
#define En_NO_STRM \
    can_mes.can_mes_1bit[21][4].b6 // 1 - выключение режима светофорного тормоза
#define CoolManual \
    can_mes.can_mes_1bit[21][4].b7 // 1 - ручной режим кондиционера
//#define ---			can_mes.can_mes_1bit[21][4].b7	// разрешено
//включение Система контроля оплаты проезда
//-----------------------------------------------
//-22-0
#define BI_PSY_UP               \
    can_mes.can_mes_1bit[22][0] \
            .b0 // 1 - нажата сенсорная кнопка на БИ ПШУ вверх
#define BI_PSY_DN \
    can_mes.can_mes_1bit[22][0].b1 // 1 - нажата сенсорная кнопка на БИ ПШУ вниз
#define BI_PSY_ON \
    can_mes.can_mes_1bit[22][0].b2 // 1 - нажата сенсорная кнопка на БИ ПШУ вкл
#define BI_AVDU_ON \
    can_mes.can_mes_1bit[22][0].b3 // 1 - нажата сенсорная кнопка на БИ АВДУ вкл
#define BI_AVDU_OFF             \
    can_mes.can_mes_1bit[22][0] \
            .b4 // 1 - нажата сенсорная кнопка на БИ АВДУ выкл
#define BI_AutoXod \
    can_mes.can_mes_1bit[22][0].b5 // 1 - нажата сенсорная кнопка на БИ АвтоХод
#define BI_Charge \
    can_mes.can_mes_1bit[22][0].b6 // 1 - нажата сенсорная кнопка на БИ Заряд
#define BI_Kompr                \
    can_mes.can_mes_1bit[22][0] \
            .b7 // 1 - нажата сенсорная кнопка на БИ Компрессор
//-22-1
#define BI_PNR \
    can_mes.can_mes_1bit[22][1].b0 // 1 - нажата сенсорная кнопка на БИ ПНР
#define BI_KSI \
    can_mes.can_mes_1bit[22][1].b1 // 1 - нажата сенсорная кнопка на БИ КСИ
#define BI_GYR \
    can_mes.can_mes_1bit[22][1].b2 // 1 - нажата сенсорная кнопка на БИ ГУР
#define BI_ST_TRM               \
    can_mes.can_mes_1bit[22][1] \
            .b3 // 1 - нажата сенсорная кнопка на БИ Светофорный тормоз
#define BI_F1 \
    can_mes.can_mes_1bit[22][1].b4 // 1 - нажата сенсорная кнопка на БИ F1
#define BI_ABS \
    can_mes.can_mes_1bit[22][1].b5 // 1 - нажата сенсорная кнопка на БИ АБС
#define BI_IRT \
    can_mes.can_mes_1bit[22][1].b6 // 1 - нажата сенсорная кнопка на БИ ИРТ
#define BI_SKOP \
    can_mes.can_mes_1bit[22][1].b7 // 1 - нажата сенсорная кнопка на БИ СКОП
//-22-2
#define BI_HEAT_1 \
    can_mes.can_mes_1bit[22][2].b0 // 1 - нажата сенсорная кнопка на БИ Печь1
#define BI_HEAT_2 \
    can_mes.can_mes_1bit[22][2].b1 // 1 - нажата сенсорная кнопка на БИ Печь2
#define BI_HEAT_3 \
    can_mes.can_mes_1bit[22][2].b2 // 1 - нажата сенсорная кнопка на БИ Печь3
#define BI_HEAT_4 \
    can_mes.can_mes_1bit[22][2].b3 // 1 - нажата сенсорная кнопка на БИ Печь4
#define BI_HEAT_5 \
    can_mes.can_mes_1bit[22][2].b4 // 1 - нажата сенсорная кнопка на БИ Печь5
#define BI_HEAT_6 \
    can_mes.can_mes_1bit[22][2].b5 // 1 - нажата сенсорная кнопка на БИ Печь6
#define BI_FAN                  \
    can_mes.can_mes_1bit[22][2] \
            .b6 // 1 - нажата сенсорная кнопка на БИ вентилятор
#define BI_MIRROR               \
    can_mes.can_mes_1bit[22][2] \
            .b7 // 1 - нажата сенсорная кнопка на БИ подогрев зеркал
//-22-3
#define BI_Tablo \
    can_mes.can_mes_1bit[22][3].b0 // 1 - нажата сенсорная кнопка на БИ Табло
#define BI_Kabin \
    can_mes.can_mes_1bit[22][3].b1 // 1 - нажата сенсорная кнопка на БИ Кабина
#define BI_Mark \
    can_mes.can_mes_1bit[22][3].b2 // 1 - нажата сенсорная кнопка на БИ Габариты
#define BI_Head                 \
    can_mes.can_mes_1bit[22][3] \
            .b3 // 1 - нажата сенсорная кнопка на БИ Головной свет
#define BI_FogF                 \
    can_mes.can_mes_1bit[22][3] \
            .b4 // 1 - нажата сенсорная кнопка на БИ Противотуманки передние
#define BI_Fog                  \
    can_mes.can_mes_1bit[22][3] \
            .b5 // 1 - нажата сенсорная кнопка на БИ Противотуманки задние
#define BI_Salon1               \
    can_mes.can_mes_1bit[22][3] \
            .b6 // 1 - нажата сенсорная кнопка на БИ Свет салон1
#define BI_Salon2               \
    can_mes.can_mes_1bit[22][3] \
            .b7 // 1 - нажата сенсорная кнопка на БИ Свет салон2
//-22-4
#define BI_Katapult             \
    can_mes.can_mes_1bit[22][4] \
            .b0 // 1 - нажата сенсорная кнопка на БИ Катапультации
#define BI_Alarm \
    can_mes.can_mes_1bit[22][4].b1 // 1 - нажата сенсорная кнопка на БИ Аварийки
#define BI_ECS_Rez              \
    can_mes.can_mes_1bit[22][4] \
            .b2 // 1 - нажата сенсорная кнопка на БИ Екас режим
#define BI_ECS_Nakl             \
    can_mes.can_mes_1bit[22][4] \
            .b3 // 1 - нажата сенсорная кнопка на БИ Екас наклон
#define BI_ECS_Tran             \
    can_mes.can_mes_1bit[22][4] \
            .b4 // 1 - нажата сенсорная кнопка на БИ Екас тр.уровень
#define BI_ECS_Up               \
    can_mes.can_mes_1bit[22][4] \
            .b5 // 1 - нажата сенсорная кнопка на БИ Екас вверх
#define BI_ECS_Dn               \
    can_mes.can_mes_1bit[22][4] \
            .b6 // 1 - нажата сенсорная кнопка на БИ Екас вниз
#define BI_EnAkkum \
    can_mes.can_mes_1bit[22][4].b7 // 1 - нажата сенсорная кнопка на БИ АКБ
//-22-5
#define BI_Dr0_Open             \
    can_mes.can_mes_1bit[22][5] \
            .b0 // 1 - нажата сенсорная кнопка на БИ Открыть дверь 0
#define BI_Dr0_Clos             \
    can_mes.can_mes_1bit[22][5] \
            .b1 // 1 - нажата сенсорная кнопка на БИ Закрыть дверь 0
#define BI_Dr1_Open             \
    can_mes.can_mes_1bit[22][5] \
            .b2 // 1 - нажата сенсорная кнопка на БИ Открыть дверь 1
#define BI_Dr1_Clos             \
    can_mes.can_mes_1bit[22][5] \
            .b3 // 1 - нажата сенсорная кнопка на БИ Закрыть дверь 1
#define BI_Dr2_Open             \
    can_mes.can_mes_1bit[22][5] \
            .b4 // 1 - нажата сенсорная кнопка на БИ Открыть дверь 2
#define BI_Dr2_Clos             \
    can_mes.can_mes_1bit[22][5] \
            .b5 // 1 - нажата сенсорная кнопка на БИ Закрыть дверь 2
#define BI_Dr3_Open             \
    can_mes.can_mes_1bit[22][5] \
            .b6 // 1 - нажата сенсорная кнопка на БИ Открыть дверь 3
#define BI_Dr3_Clos             \
    can_mes.can_mes_1bit[22][5] \
            .b7 // 1 - нажата сенсорная кнопка на БИ Закрыть дверь 3
//-22-6
#define BI_DrS_Open             \
    can_mes.can_mes_1bit[22][6] \
            .b0 // 1 - нажата сенсорная кнопка на БИ Открыть все двери
#define BI_DrS_Clos             \
    can_mes.can_mes_1bit[22][6] \
            .b1 // 1 - нажата сенсорная кнопка на БИ Закрыть все двери
#define BI_St_Left              \
    can_mes.can_mes_1bit[22][6] \
            .b2 // 1 - нажата сенсорная кнопка на БИ Левая стрелка
#define BI_St_Right             \
    can_mes.can_mes_1bit[22][6] \
            .b3 // 1 - нажата сенсорная кнопка на БИ Правая стрелка
#define BI_ASR                  \
    can_mes.can_mes_1bit[22][6] \
            .b4 // 1 - нажата сенсорная кнопка на БИ функция АСР
#define BI_HillHold             \
    can_mes.can_mes_1bit[22][6] \
            .b5 // 1 - нажата сенсорная кнопка на БИ функция HillHolder
#define BI_En_P \
    can_mes.can_mes_1bit[22][6].b6 // 1 - нажата сенсорная кнопка на БИ
                                   // Разрешение открытия с дверных кнопок
#define BI_Glass                \
    can_mes.can_mes_1bit[22][6] \
            .b7 // 1 - нажата сенсорная кнопка на БИ подогрев ломбового стекла
//-22-7
#define BI_RainSensor           \
    can_mes.can_mes_1bit[22][7] \
            .b0 // 1 - нажата сенсорная кнопка на БИ Датчик дождя
#define BI_LighSensor           \
    can_mes.can_mes_1bit[22][7] \
            .b1 // 1 - нажата сенсорная кнопка на БИ Датчик света
#define BI_MediaSystem          \
    can_mes.can_mes_1bit[22][7] \
            .b2 // 1 - нажата сенсорная кнопка на БИ Медиа система
#define BI_WarmFloor            \
    can_mes.can_mes_1bit[22][7] \
            .b3 // 1 - нажата сенсорная кнопка на БИ Теплый пол
#define BI_HeatButt             \
    can_mes.can_mes_1bit[22][7] \
            .b4 // 1 - нажата сенсорная кнопка на БИ Подогрев сидения водителя
#define BI_AutoEcas \
    can_mes.can_mes_1bit[22][7].b5 // 1 - нажата сенсорная кнопка на БИ Подогрев
                                   // сидения кондуктора
#define BI_ShtangLight \
    can_mes.can_mes_1bit[22][7].b6 // 1 - нажата сенсорная кнопка на БИ Подогрев
                                   // сидения кондуктора
#define BI_LampDekor            \
    can_mes.can_mes_1bit[22][7] \
            .b7 // 1 - Нажата сенсорная кнопка на БИ Декоративное освещение
//--------Кабина-------------------------------------------------------------------------------------------------
//- R0_kab
#define Termo_KontO \
    can_mes.can_mes_1bit[23][0].b0 // 1 - замкнут термоконтакт B печки ,
                                   // Test_kont_1/20 x4
#define P_Parking \
    can_mes.can_mes_1bit[23][0].b1 // 1 - давление стояночного тормоза ,
                                   // Test_kont_2/17 x4
#define Braking \
    can_mes.can_mes_1bit[23][0].b2 // 1 - Колодки стёрлсиь
                                   // , Test_kont_3/21 x4
//#define ---			can_mes.can_mes_1bit[23][0].b3	//1 -
//, Test_kont_4/14 x4
#define PP_Lamp_FogF \
    can_mes.can_mes_1bit[23][0].b4 // 1 - Замкнут контакт противотуманки фронт
//, Test_kont_5/11 x4
#define DisDriver \
    can_mes.can_mes_1bit[23][0].b5 // 1 - Отсутствует водитель
                                   // , Test_kont_6/03 x5
#define SafeBelt \
    can_mes.can_mes_1bit[23][0].b6 // 1 - замкнут датчик ремня безопасности
                                   // , Test_kont_7/05 x5
#define Kont_WarmFloor \
    can_mes.can_mes_1bit[23][0].b7 // 1 - замкнут контроль тёплого пола ,
                                   // Test_kont_8/08 x5
//- R1_kab
#define Pas2_kab \
    can_mes.can_mes_1bit[23][1].b0 // 1 - Сигнал водителю от пас (лев борт)
                                   // , Test_kont_9/09 x5
//#define ---			can_mes.can_mes_1bit[23][1].b1	//1 -
//, Test_U1/20 x4 #define ---			can_mes.can_mes_1bit[23][1].b2
////1 - , Test_U3/21
// x4 #define ---			can_mes.can_mes_1bit[23][1].b3	//1 -
//, Test_U6/03 x5 #define ---			can_mes.can_mes_1bit[23][1].b4
////1 - , Test_U9/09
// x5
#define kab_PowA can_mes.can_mes_1bit[23][1].b5 // 1 - Есть питание +24в(А)
#define kab_off_wait            \
    can_mes.can_mes_1bit[23][1] \
            .b6 // 1 - запрет выключения идёт отключение кондиционера
//#define ---			can_mes.can_mes_1bit[23][1].b7	//1 -
//--------Дверь-1------------------------------------------------------------------------------------------------
//- R0_dr1
//#define ---			can_mes.can_mes_1bit[25][0].b0	//1 -
//, Test_kont_1/20 x4
//#define ---			can_mes.can_mes_1bit[25][0].b1	//1 -
//, Test_kont_2/17 x4
//#define ---			can_mes.can_mes_1bit[25][0].b2	//1 -
//, Test_kont_3/21 x4
//#define ---			can_mes.can_mes_1bit[25][0].b3	//1 -
//, Test_kont_4/14 x4
#define D_Svet \
    can_mes.can_mes_1bit[25][0].b4 // 1 - замкнут датчик света
                                   // , Test_kont_5/11 x4
//#define ---			can_mes.can_mes_1bit[25][0].b5	//1 -
//, Test_kont_6/03 x5
//#define ---			can_mes.can_mes_1bit[25][0].b6	//1 -
//, Test_kont_7/05 x5
//#define ---			can_mes.can_mes_1bit[25][0].b7	//1 -
//, Test_kont_8/08 x5
//- R1_dr1
//#define ---			can_mes.can_mes_1bit[25][1].b0	//1 -
//, Test_kont_9/09 x5
#define D_Dozd \
    can_mes.can_mes_1bit[25][1].b1 // 1 - сигнал датчик дождя
                                   // , Test_U1/20 x4
#define BB_Signal can_mes.can_mes_1bit[25][1].b2 // 1 -
#define BB_Alarm can_mes.can_mes_1bit[25][1].b3
////1 - , Test_U6/03
#define BB_Stop can_mes.can_mes_1bit[25][1].b4 // 1 -
//, Test_U9/09 x5
#define dr1_PowA can_mes.can_mes_1bit[25][1].b5 // 1 - Есть питание +24в(А)
//#define ---			can_mes.can_mes_1bit[25][1].b6	//1 -
//#define ---			can_mes.can_mes_1bit[25][1].b7	//1 -
//--------Дверь3-------------------------------------------------------------------------------------------------
//- R0_dr3
//#define ---			can_mes.can_mes_1bit[29][0].b0	//1 -
//, Test_kont_1/20 x4
//#define ---			can_mes.can_mes_1bit[29][0].b1	//1 -
//, Test_kont_2/17 x4
//#define ---			can_mes.can_mes_1bit[29][0].b2	//1 -
//, Test_kont_3/21 x4
//#define ---			can_mes.can_mes_1bit[29][0].b3	//1 -
//, Test_kont_4/14 x4
//#define ---			can_mes.can_mes_1bit[29][0].b4	//1 -
//, Test_kont_5/11 x4
//#define ---			can_mes.can_mes_1bit[29][0].b5	//1 -
//, Test_kont_6/03 x5
//#define ---			can_mes.can_mes_1bit[29][0].b6	//1 -
//, Test_kont_7/05 x5
#define P_Door \
    can_mes.can_mes_1bit[29][0].b7 // 1 - Давл.дверного.конт - норма ,
                                   // Test_kont_8/08 x5
//- R1_dr3
//#define ---			can_mes.can_mes_1bit[29][1].b0	//1 -
//, Test_kont_9/09 x5
//#define ---			can_mes.can_mes_1bit[29][1].b1	//1 -
//, Test_U1/20 x4 #define ---			can_mes.can_mes_1bit[29][1].b2
////1 - , Test_U3/21
// x4
#define PSY_IND \
    can_mes.can_mes_1bit[29][1].b3 // 1 - Индикация ПШУ
                                   // , Test_U6/03 x5
//#define ---			can_mes.can_mes_1bit[29][1].b4	//1 -
//, Test_U9/09 x5
#define dr3_PowA can_mes.can_mes_1bit[29][1].b5 // 1 - Есть питание +24в(А)
//#define ---			can_mes.can_mes_1bit[29][1].b6	//1 -
//#define ---			can_mes.can_mes_1bit[29][1].b7	//1 -
//--------Комоци-двери---------------------------------------------------------------------------------------------
#define Dr_Open 0b0001
#define Dr_Open_ 0b0011
#define Dr_Opening 0b0101
#define Dr_Clos 0b0000
#define Dr_Clos_ 0b0010
#define Dr_Closing 0b0100
#define Dr_Unknown 0b0110
#define Dr_NotUse 0b1111
//состояние дверей
#define Door1_State (can_mes.can_mes_char[EDSC1_dr1][0] & 0x0F)
#define Door2_State (can_mes.can_mes_char[EDSC1_dr2][0] & 0x0F)
#define Door3_State (can_mes.can_mes_char[EDSC1_dr3][0] & 0x0F)
// двери открыты
#define Door1_Open                                            \
    (((can_mes.can_mes_char[EDSC1_dr1][0] & 0x0F) == Dr_Open) \
     || ((can_mes.can_mes_char[EDSC1_dr1][0] & 0x0F) == Dr_Open_))
#define Door2_Open                                            \
    (((can_mes.can_mes_char[EDSC1_dr2][0] & 0x0F) == Dr_Open) \
     || ((can_mes.can_mes_char[EDSC1_dr2][0] & 0x0F) == Dr_Open_))
#define Door3_Open                                            \
    (((can_mes.can_mes_char[EDSC1_dr3][0] & 0x0F) == Dr_Open) \
     || ((can_mes.can_mes_char[EDSC1_dr3][0] & 0x0F) == Dr_Open_))
// двери открываются
#define Door1_Opening \
    ((can_mes.can_mes_char[EDSC1_dr1][0] & 0x0F) == Dr_Opening)
#define Door2_Opening \
    ((can_mes.can_mes_char[EDSC1_dr2][0] & 0x0F) == Dr_Opening)
#define Door3_Opening \
    ((can_mes.can_mes_char[EDSC1_dr3][0] & 0x0F) == Dr_Opening)
// двери закрыты
#define Door1_Clos                                            \
    (((can_mes.can_mes_char[EDSC1_dr1][0] & 0x0F) == Dr_Clos) \
     || ((can_mes.can_mes_char[EDSC1_dr1][0] & 0x0F) == Dr_Clos_))
#define Door2_Clos                                            \
    (((can_mes.can_mes_char[EDSC1_dr2][0] & 0x0F) == Dr_Clos) \
     || ((can_mes.can_mes_char[EDSC1_dr2][0] & 0x0F) == Dr_Clos_))
#define Door3_Clos                                            \
    (((can_mes.can_mes_char[EDSC1_dr3][0] & 0x0F) == Dr_Clos) \
     || ((can_mes.can_mes_char[EDSC1_dr3][0] & 0x0F) == Dr_Clos_))
// двери закрываются
#define Door1_Closing \
    ((can_mes.can_mes_char[EDSC1_dr1][0] & 0x0F) == Dr_Closing)
#define Door2_Closing \
    ((can_mes.can_mes_char[EDSC1_dr2][0] & 0x0F) == Dr_Closing)
#define Door3_Closing \
    ((can_mes.can_mes_char[EDSC1_dr3][0] & 0x0F) == Dr_Closing)
// аппарель
#define ApparelAct                               \
    ((can_mes.can_mes_char[EDSC2_dr2][3] & 0b11) \
     == 0b01) // 1 - датчик аппарели активен

#define Door2_InvSalon (BIT2((can_mes.can_mes_char[EDSC2_dr2][0]), 4) == 1)
#define Door2_InvOut (BIT2((can_mes.can_mes_char[EDSC2_dr2][0]), 6) == 1)
#define Door1_Pas2 (BIT2((can_mes.can_mes_char[EDSC2_dr1][0]), 0) == 1)
#define Door2_Pas2 (BIT2((can_mes.can_mes_char[EDSC2_dr2][0]), 0) == 1)
#define Door3_Pas2 (BIT2((can_mes.can_mes_char[EDSC2_dr3][0]), 0) == 1)
#define Door1_Pas (BIT2((can_mes.can_mes_char[EDSC2_dr1][6]), 4) == 1)
#define Door2_Pas (BIT2((can_mes.can_mes_char[EDSC2_dr2][6]), 4) == 1)
#define Door3_Pas (BIT2((can_mes.can_mes_char[EDSC2_dr3][6]), 4) == 1)
#define Door1_KranSalon (BIT2(can_mes.can_mes_char[EDSC2_dr1][1], 2) == 1)
#define Door2_KranSalon (BIT2(can_mes.can_mes_char[EDSC2_dr2][1], 2) == 1)
#define Door3_KranSalon (BIT2(can_mes.can_mes_char[EDSC2_dr3][1], 2) == 1)
#define Door1_KranOut (BIT2(can_mes.can_mes_char[EDSC2_dr1][1], 4) == 1)
#define Door2_KranOut (BIT2(can_mes.can_mes_char[EDSC2_dr2][1], 4) == 1)
#define Door3_KranOut (BIT2(can_mes.can_mes_char[EDSC2_dr3][1], 4) == 1)
#define Door1_KranCapSalon (BIT2(can_mes.can_mes_char[EDSC2_dr1][1], 6) == 1)
#define Door2_KranCapSalon (BIT2(can_mes.can_mes_char[EDSC2_dr2][1], 6) == 1)
#define Door3_KranCapSalon (BIT2(can_mes.can_mes_char[EDSC2_dr3][1], 6) == 1)
#define Door1_KranCapOut (BIT2(can_mes.can_mes_char[EDSC2_dr1][2], 0) == 1)
#define Door2_KranCapOut (BIT2(can_mes.can_mes_char[EDSC2_dr2][2], 0) == 1)
#define Door3_KranCapOut (BIT2(can_mes.can_mes_char[EDSC2_dr3][2], 0) == 1)
//--------Бук----------------------------------------------------------------------------------------------------
//- R0_buk
#define rele_kondic \
    can_mes.can_mes_1bit[31][0].b0 // 1 -
                                   // , Test_kont_1/20 x4
#define rele_PNR \
    can_mes.can_mes_1bit[31][0].b1 // 1 - включен контактор ПНР
                                   // , Test_kont_2/17 x4
//#define ---			can_mes.can_mes_1bit[31][0].b2	//1 -
//, Test_kont_3/21 x4
//#define ---			can_mes.can_mes_1bit[31][0].b3	//1 -
//, Test_kont_4/14 x4
#define rele_AB                 \
    can_mes.can_mes_1bit[31][0] \
            .b4 // 1 - включен один из контакторов кабины, Test_kont_5/11 x4
//#define ---			can_mes.can_mes_1bit[31][0].b5	//1 -
//, Test_kont_6/03 x5
#define rele_kompr \
    can_mes.can_mes_1bit[31][0].b6 // 1 - включен контактор компрессора ,
                                   // Test_kont_7/05 x5
#define rele_OCDEF              \
    can_mes.can_mes_1bit[31][0] \
            .b7 // 1 - включен один из контакторов салона, Test_kont_8/08 x5
//- R1_buk
//#define ---			can_mes.can_mes_1bit[31][1].b0	//1 -
//, Test_kont_9/09 x5
//#define NO_CH_PW		can_mes.can_mes_1bit[31][1].b1	//1 -
//, Test_U1/20 x4 #define ---			can_mes.can_mes_1bit[31][1].b2
////1 - , Test_U3/21
// x4
#define ALARM_PNR1 \
    can_mes.can_mes_1bit[31][1].b3 // 1 - ошибка работы ПНР1
                                   // , Test_U6/03 x5
#define ALARM_PNR2 \
    can_mes.can_mes_1bit[31][1].b4 // 1 - ошибка работы ПНР2
                                   // , Test_U9/09 x5
#define buk_PowA can_mes.can_mes_1bit[31][1].b5 // 1 - Есть питание +24в(А)
#define Kont_AVDU_NC            \
    can_mes.can_mes_1bit[31][1] \
            .b6 // 1 - замкнут Н/3 контакт АВДУ			, x3 06
#define Kont_AVDU               \
    can_mes.can_mes_1bit[31][1] \
            .b7 // 1 - замкнут Н/Р контакт АВДУ			, x3 09
//- R2_buk
#define PNR1 can_mes.can_mes_1bit[31][4].b0 // 1 - Норма работы ПНР1
#define PNR2 can_mes.can_mes_1bit[31][4].b1 // 1 - Норма работы ПНР2
#define AVDU_STATE \
    can_mes.can_mes_1bit[31][4].b2 // 1 - Программно АВДУ должен быть включен
#define COND_READY              \
    can_mes.can_mes_1bit[31][4] \
            .b3 // 1 - Готов к работе(обратная связь кондиционера)
#define Avdu_Out_ON \
    can_mes.can_mes_1bit[31][4].b4 // 1 - Состояние выхода ВКЛ АВДУ
#define Avdu_Out_OFF \
    can_mes.can_mes_1bit[31][4].b5 // 1 - Состояние выхода ВЫКЛ АВДУ
#define BreakGotBuk             \
    can_mes.can_mes_1bit[31][4] \
            .b6 // 1 - пойман бит ошибки резистора, вкл АВДУ запрещено
//--------Бакси--------------------------------------------------------------------------------------------------
//
#define BAKSI_GRE can_mes.can_mes_1bit[37][0].b0 // green baksi led
#define BAKSI_YEL can_mes.can_mes_1bit[37][0].b1 // yellow baksi led
#define BAKSI_RED can_mes.can_mes_1bit[37][0].b2 // red baksi led
//--------Кондиционер-Heavac---------------------------------------------------------------------------------------------------
// R0_con1
#define Work1_ok \
    can_mes.can_mes_1bit[41][0].b0 // 1 - работа кондиционера салона 1 ОК
// R0_con2
#define Work2_ok \
    can_mes.can_mes_1bit[42][0].b0 // 1 - работа кондиционера салона 2 ОК
//--------Екас---------------------------------------------------------------------------------------------------
// R0_Ecas
#define RED_ECS \
    can_mes.can_mes_1bit[44][0].b4 // команда на зажигание красного светодиода
#define YEL_ECS \
    can_mes.can_mes_1bit[44][0].b5 // команда на зажигание жёлтого светодиода
#define GRE_ECS \
    can_mes.can_mes_1bit[44][0].b6 // команда на зажигание зеленого светодиода
#define DOOR_ACC \
    can_mes.can_mes_1bit[44][0].b7 // команда авторежима от тахографа
//--------Уки0604------------------------------------------------------------------------------------------------
// R0_y64
#define FaultI_y64 can_mes.can_mes_1bit[51][0].b0  //
#define FaultR_y64 can_mes.can_mes_1bit[51][0].b1  //
#define Off_VT_y64 can_mes.can_mes_1bit[51][0].b2  //
#define TestGot_y64 can_mes.can_mes_1bit[51][0].b3 //
//*********************************************************************************************************************************************************************************//
//Инициализация 2 байтных переменных
//----------------------------------------------------------------------------------
#define Speed_LH can_mes.can_mes_int[8][0]
#define Speed2_LH can_mes.can_mes_int[8][1]
#define U_xod_LH can_mes.can_mes_int[9][2]
#define U_trm_LH can_mes.can_mes_int[9][3]
#define Zadan_LH can_mes.can_mes_int[10][1]
#define I0_irbLH can_mes.can_mes_int[11][0]
#define I1_irbLH can_mes.can_mes_int[11][1]
#define U0_irbLH can_mes.can_mes_int[11][2]
#define Ud_irbLH can_mes.can_mes_int[11][3]
#define U1yki_LH can_mes.can_mes_int[14][0]
#define U2yki_LH can_mes.can_mes_int[14][1]
#define Iak_brp_LH can_mes.can_mes_int[15][0]
#define R01_frn can_mes.can_mes_int[16][0]
#define R23_frn can_mes.can_mes_int[16][1]
#define R01_tyl can_mes.can_mes_int[19][0]
#define R01_kab can_mes.can_mes_int[23][0]
#define Iak_K_LH can_mes.can_mes_int[23][1]
#define R01_dr1 can_mes.can_mes_int[25][0]
#define R01_dr3 can_mes.can_mes_int[29][0]
#define R01_buk can_mes.can_mes_int[31][0]
#define IsnbukLH can_mes.can_mes_int[31][1]
#define V1_tah_LH can_mes.can_mes_int[43][2]
#define V2_tah_LH can_mes.can_mes_int[43][3]
#define Fvr_y64LH can_mes.can_mes_int[51][2]
#define P1_kab_LH can_mes.can_mes_int[73][0]
#define P2_kab_LH can_mes.can_mes_int[73][1]
#define P3_kab_LH can_mes.can_mes_int[73][2]
#define P4_kab_LH can_mes.can_mes_int[73][3]
#define Hrtv_LH can_mes.can_mes_int[95][0]
#define Hrvt_LH can_mes.can_mes_int[95][2]
//-------------------------------------------------------------------////-------------------------------------------------------------------//
/*************************************************************************************************************/
#define T_Pw_0 can_mes.can_mes_char[231][0]
#define T_Pw_1 can_mes.can_mes_char[231][1]
#define T_Pw_2 can_mes.can_mes_char[231][2]
#define T_Pw_3 can_mes.can_mes_char[231][3]
#define T_PwA_0 can_mes.can_mes_char[231][4]
#define T_PwA_1 can_mes.can_mes_char[231][5]
#define T_PwA_2 can_mes.can_mes_char[231][6]
#define T_PwA_3 can_mes.can_mes_char[231][7]
#define cnt_1_st can_cnt[231]
#define T_Rk_0 can_mes.can_mes_char[232][0]
#define T_Rk_1 can_mes.can_mes_char[232][1]
#define T_Rk_2 can_mes.can_mes_char[232][2]
#define T_Rk_3 can_mes.can_mes_char[232][3]
#define T_Sn_0 can_mes.can_mes_char[232][4]
#define T_Sn_1 can_mes.can_mes_char[232][5]
#define T_Sn_2 can_mes.can_mes_char[232][6]
#define T_Sn_3 can_mes.can_mes_char[232][7]
#define cnt_2_st can_cnt[232]
#define T_Km_0 can_mes.can_mes_char[233][0]
#define T_Km_1 can_mes.can_mes_char[233][1]
#define T_Km_2 can_mes.can_mes_char[233][2]
#define T_Km_3 can_mes.can_mes_char[233][3]
#define T_KmA_0 can_mes.can_mes_char[233][4]
#define T_KmA_1 can_mes.can_mes_char[233][5]
#define T_KmA_2 can_mes.can_mes_char[233][6]
#define T_KmA_3 can_mes.can_mes_char[233][7]
#define cnt_3_st can_cnt[233]
#define E_Pw_0 can_mes.can_mes_char[234][0]
#define E_Pw_1 can_mes.can_mes_char[234][1]
#define E_Pw_2 can_mes.can_mes_char[234][2]
#define E_Pw_3 can_mes.can_mes_char[234][3]
#define E_PwA_0 can_mes.can_mes_char[234][4]
#define E_PwA_1 can_mes.can_mes_char[234][5]
#define E_PwA_2 can_mes.can_mes_char[234][6]
#define E_PwA_3 can_mes.can_mes_char[234][7]
#define cnt_4_st can_cnt[234]
#define E_Rk_0 can_mes.can_mes_char[235][0]
#define E_Rk_1 can_mes.can_mes_char[235][1]
#define E_Rk_2 can_mes.can_mes_char[235][2]
#define E_Rk_3 can_mes.can_mes_char[235][3]
#define E_Sn_0 can_mes.can_mes_char[235][4]
#define E_Sn_1 can_mes.can_mes_char[235][5]
#define E_Sn_2 can_mes.can_mes_char[235][6]
#define E_Sn_3 can_mes.can_mes_char[235][7]
#define cnt_5_st can_cnt[235]
#define E_Km_0 can_mes.can_mes_char[236][0]
#define E_Km_1 can_mes.can_mes_char[236][1]
#define E_Km_2 can_mes.can_mes_char[236][2]
#define E_Km_3 can_mes.can_mes_char[236][3]
#define E_KmA_0 can_mes.can_mes_char[236][4]
#define E_KmA_1 can_mes.can_mes_char[236][5]
#define E_KmA_2 can_mes.can_mes_char[236][6]
#define E_KmA_3 can_mes.can_mes_char[236][7]
#define cnt_6_st can_cnt[236]
#define V_Pw_0 can_mes.can_mes_char[237][0]
#define V_Pw_1 can_mes.can_mes_char[237][1]
#define V_Pw_2 can_mes.can_mes_char[237][2]
#define V_Pw_3 can_mes.can_mes_char[237][3]
#define V_PwA_0 can_mes.can_mes_char[237][4]
#define V_PwA_1 can_mes.can_mes_char[237][5]
#define V_PwA_2 can_mes.can_mes_char[237][6]
#define V_PwA_3 can_mes.can_mes_char[237][7]
#define cnt_7_st can_cnt[237]
#define V_Rk_0 can_mes.can_mes_char[238][0]
#define V_Rk_1 can_mes.can_mes_char[238][1]
#define V_Rk_2 can_mes.can_mes_char[238][2]
#define V_Rk_3 can_mes.can_mes_char[238][3]
#define V_Sn_0 can_mes.can_mes_char[238][4]
#define V_Sn_1 can_mes.can_mes_char[238][5]
#define V_Sn_2 can_mes.can_mes_char[238][6]
#define V_Sn_3 can_mes.can_mes_char[238][7]
#define cnt_8_st can_cnt[237]
#define V_Km_0 can_mes.can_mes_char[239][0]
#define V_Km_1 can_mes.can_mes_char[239][1]
#define V_Km_2 can_mes.can_mes_char[239][2]
#define V_Km_3 can_mes.can_mes_char[239][3]
#define V_KmA_0 can_mes.can_mes_char[239][4]
#define V_KmA_1 can_mes.can_mes_char[239][5]
#define V_KmA_2 can_mes.can_mes_char[239][6]
#define V_KmA_3 can_mes.can_mes_char[239][7]
#define cnt_9_st can_cnt[238]
/******************************************************************/

#endif // CANINIT_H
