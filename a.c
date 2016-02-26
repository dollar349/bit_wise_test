#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <sys/types.h>

typedef struct {
    u_int8_t diag_mode;
    u_int8_t diag_OnOff;
    union {
       u_int8_t Byte[2];
	   
       struct {
        unsigned pwr:1;
        unsigned ca1:1;
        unsigned ca2:1;
        unsigned hh1:1;
        unsigned hwa:1;
        unsigned Reserve:11;
       }_2ton;
	   
       struct {
        unsigned as:1;    //0
        unsigned ca1:1;   //1
        unsigned ca2:1;   //2
        unsigned hwa:1;   //3
        unsigned sp3:1;   //4
        unsigned hpa:1;   //5
        unsigned fc:1;    //6
        unsigned mfol:1;  //7
        unsigned hh2:1;   //8
        unsigned c2ol:1;  //9
        unsigned pwr:1;   //10
        unsigned lp2:1;   //11
        unsigned sp1:1;   //12
        unsigned c1ol:1;  //13
        unsigned hh1:1;   //14
        unsigned Reserve:2; 
       }_8ton;       
    }InputSt;
    union {
       u_int8_t Byte[3];
       struct {
        unsigned low_spd:1;                //0
        unsigned Reserve1:1;               //1    /* Reserve */
        unsigned hum:1;                    //2
        unsigned llsv1_cool1_open_vlv:1;   //3
        unsigned hgbp1_cls_vlv:1;          //4
        unsigned reh1:1;                   //5
        unsigned Reserve2:12;              //6~17 /* Reserve */
        unsigned c_a_relay:1;              //18
        unsigned mfan:1;                   //19
        unsigned Reserve3:5;               //20~24 /* Reserve */
       }_2ton;
       struct {
        unsigned mfan:1;                   //0
        unsigned reh1:1;                   //1
        unsigned reh2:1;                   //2
        unsigned reh3:1;                   //3
        unsigned hmv:1;                    //4
        unsigned hum:1;                    //5
        unsigned c_a_relay:1;              //6
        unsigned Reserve1:1;               //7    /* Reserve */
        unsigned r5:1;                     //8
        unsigned llsv2:1;                  //9
        unsigned c2:1;                     //10
        unsigned hgbp2:1;                  //11
        unsigned hgbp1:1;                  //12
        unsigned c1:1;                     //13
        unsigned llsv1:1;                  //14
        unsigned Reserve2:5;               //15~19 /* Reserve */
        unsigned vlv_open:1;               //20
        unsigned vlv_cls:1;                //21
        unsigned Reserve3:3;               //22~24 /* Reserve */
       }_8ton;       
    }OutputSt;       
} COOL_DEV_DIAGNOSTIC_s;

int main()
{
    COOL_DEV_DIAGNOSTIC_s  DST={0};
	DST.OutputSt._8ton.c1 = 1;
	printf("DST.OutputSt = 0x%02x 0x%02x 0x%02x\n",DST.OutputSt.Byte[0],DST.OutputSt.Byte[1],DST.OutputSt.Byte[2]);
	printf("DST.InputSt = 0x%02x 0x%02x \n",DST.InputSt.Byte[0],DST.InputSt.Byte[1]);
}
