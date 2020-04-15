#ifndef G5_IO_SEN_H
#define G5_IO_SEN_H
/* History                                                                    */
/*----------------------------------------------------------------------------*/
/* Date      VDR_Number  Name    Description                                       */
/*----------------------------------------------------------------------------*/
/* 20.11.09  VDR_405	 AL    New Port assignment for B3 Sample */

/* 24.09.09  VDR_372	 AL      Mesurment of NTC and usage of new MicroController Ports
PWM could be switched to portpin by EEPROM
Usage of EEPROM Cell for Amb Night and DayThreshold
Remove EEPROM valeo for IR and FW scaling for VWK*/
/* 11.06.08  VDR_227      FS      Changed due to Lada Project*/
/* 08.12.2014 VCO_151  NB  Implement IC test */
/* 08.04.2015 VDR_870   NB    Set all unused IO ports of microcontroller to Output low */ 
/******************************************************************************/


#define INPUT   1
#define OUTPUT  0
#define HIGH  1
#define LOW   0

/* Anlaogports */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#define po_PowerSupply_g	        2
#define po_PowerSupplyAna_g		P2_bit.no2
#define po_D_PowerSupplyAna_g		PM2_bit.no2 

#define po_ASIC_AnalogOut_g	        6  
#define po_ASIC_AnalogOut_Ana_g		P2_bit.no6 
#define po_D_ASIC_AnalogOut_Ana_g	PM2_bit.no6 

#define po_ASIC_LOOP_g                  4 
#define po_ASIC_LOOP_Ana_g		P2_bit.no4 
#define po_D_ASIC_LOOP_Ana_g		PM2_bit.no4 

#define po_NTC_INPUT_g             0x80 /*address to convert the MicroController internal temperature by ADC*/
#define po_ADC_TEST_g              0x81 /*address to test functioning of the ADC */
#define po_SHT_Supply_g            0x10 /*address to the Analog channel ANI16 which is used to measure the SHT supply */

/* Digitalports */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */


/* SPI */
#define po_SPIClock_g   		    P1_bit.no0
#define po_D_SPIClock_g     		    PM1_bit.no0 

#define po_SPI_MasterIn_g		    P1_bit.no1
#define po_D_SPI_MasterIn_g		    PM1_bit.no1 

#define po_SPI_MasterOut_g		    P1_bit.no2
#define po_D_SPI_MasterOut_g		    PM1_bit.no2 

#define po_Slave_Select_g            	    P14_bit.no7
#define	po_Direction_Slave_Select_g 	    PM14_bit.no7 



/* UART */
#define po_TXD0_g		            P5_bit.no1
#define po_LINTx_g                          po_TXD0_g
#define po_D_TXD0_g         		    PM5_bit.no1 

#define po_RXD0_g		            P5_bit.no0   /* used for IC Test*/
#define po_D_RXD0_g         		    PM5_bit.no0 

/* TOOL0 */
#define po_TOOL0_g		            P4_bit.no0   /* used for IC Test*/
#define po_D_TOOL0_g         		    PM4_bit.no0 

/* WATCHDOG */

#define po_ExternalWDG_g           	    P3_bit.no0
#define po_DExternalWDG_g                   PM3_bit.no0 /*Gen5*/


/****************************************************************************/
/** IO-Port Definition for Sensirion used in HumTemp.c                     **/

/* SHT1x Data Line */

#define po_DSHT71_1_DATA_g              PM1_bit.no4  
#define po_SHT71_1_DATA_g               P1_bit.no4  

/* SHT1x Clock Line */
#define po_DSHT71_1_CLK_g               PM1_bit.no5 
#define po_SHT71_1_CLK_g                P1_bit.no5

/* 2 Pins for powersupply for the SHT module */

#define po_PS_SHT1_g         	        P0_bit.no1
#define po_D_PS_SHT1_g                  PM0_bit.no1 
#define po_PS_SHT2_g                    P1_bit.no3
#define po_D_PS_SHT2_g                  PM1_bit.no3 

#define po_Div_ON_g		        P0_bit.no0
#define po_D_Div_ON_g	                PM0_bit.no0  


#define po_I2C_Debug_CLK_g		P6_bit.no0
#define po_D_I2C_Debug_CLK_g		PM6_bit.no0 

#define po_I2C_Debug_DATA_g	        P6_bit.no1
#define po_D_I2C_Debug_DATA_g		PM6_bit.no1  


/* Port 3 */

#define po_VoltageRegulatorEnable_g	P3_bit.no1
#define po_DVoltageRegulatorEnable_g	PM3_bit.no1   /* Gen5*/




/* Unused Ports */


#define po_unused6_0_g		       P6_bit.no0
#define po_D_unused6_0_g	       PM6_bit.no0  

#define po_unused6_1_g		       P6_bit.no1
#define po_D_unused6_1_g	       PM6_bit.no1  

#define po_unused6_2_g		       P6_bit.no2
#define po_D_unused6_2_g	       PM6_bit.no2  


#define po_unused7_0_g		        P7_bit.no0
#define po_D_unused7_0_g		PM7_bit.no0  

#define po_unused1_7_g		        P1_bit.no7
#define po_D_unused1_7_g		PM1_bit.no7  

#define po_unused1_6_g		       P1_bit.no6
#define po_D_unused1_6_g	       PM1_bit.no6  

#define po_unused2_3_g		        P2_bit.no3
#define po_D_unused2_3_g		PM2_bit.no3  

#define po_unused12_0_g		        P12_bit.no0
#define po_D_unused12_0_g		PM12_bit.no0  




/******************************************************************************/
/*** BINARY NUMBERS  * HEX *  *   DEC *                                     ***/
/******************************************************************************/

#define _0000_0000b   0x00U   /*    0  */
#define _0000_0001b   0x01U   /*    1  */
#define _0000_0010b   0x02U   /*    2  */
#define _0000_0011b   0x03U   /*    3  */
#define _0000_0100b   0x04U   /*    4  */
#define _0000_0101b   0x05U   /*    5  */
#define _0000_0110b   0x06U   /*    6  */
#define _0000_0111b   0x07U   /*    7  */
#define _0000_1000b   0x08U   /*    8  */
#define _0000_1001b   0x09U   /*    9  */
#define _0000_1010b   0x0aU   /*   10  */
#define _0000_1011b   0x0bU   /*   11  */
#define _0000_1100b   0x0cU   /*   12  */
#define _0000_1101b   0x0dU   /*   13  */
#define _0000_1110b   0x0eU   /*   14  */
#define _0000_1111b   0x0fU   /*   15  */

#define _0001_0000b   0x10U   /*   16  */
#define _0001_0001b   0x11U   /*   17  */
#define _0001_0010b   0x12U   /*   18  */
#define _0001_0011b   0x13U   /*   19  */
#define _0001_0100b   0x14U   /*   20  */
#define _0001_0101b   0x15U   /*   21  */
#define _0001_0110b   0x16U   /*   22  */
#define _0001_0111b   0x17U   /*   23  */
#define _0001_1000b   0x18U   /*   24  */
#define _0001_1001b   0x19U   /*   25  */
#define _0001_1010b   0x1aU   /*   26  */
#define _0001_1011b   0x1bU   /*   27  */
#define _0001_1100b   0x1cU   /*   28  */
#define _0001_1101b   0x1dU   /*   29  */
#define _0001_1110b   0x1eU   /*   30  */
#define _0001_1111b   0x1fU   /*   31  */

#define _0010_0000b   0x20U   /*   32  */
#define _0010_0001b   0x21U   /*   33  */
#define _0010_0010b   0x22U   /*   34  */
#define _0010_0011b   0x23U   /*   35  */
#define _0010_0100b   0x24U   /*   36  */
#define _0010_0101b   0x25U   /*   37  */
#define _0010_0110b   0x26U   /*   38  */
#define _0010_0111b   0x27U   /*   39  */
#define _0010_1000b   0x28U   /*   40  */
#define _0010_1001b   0x29U   /*   41  */
#define _0010_1010b   0x2aU   /*   42  */
#define _0010_1011b   0x2bU   /*   43  */
#define _0010_1100b   0x2cU   /*   44  */
#define _0010_1101b   0x2dU   /*   45  */
#define _0010_1110b   0x2eU   /*   46  */
#define _0010_1111b   0x2fU   /*   47  */

#define _0011_0000b   0x30U   /*   48  */
#define _0011_0001b   0x31U   /*   49  */
#define _0011_0010b   0x32U   /*   50  */
#define _0011_0011b   0x33U   /*   51  */
#define _0011_0100b   0x34U   /*   52  */
#define _0011_0101b   0x35U   /*   53  */
#define _0011_0110b   0x36U   /*   54  */
#define _0011_0111b   0x37U   /*   55  */
#define _0011_1000b   0x38U   /*   56  */
#define _0011_1001b   0x39U   /*   57  */
#define _0011_1010b   0x3aU   /*   58  */
#define _0011_1011b   0x3bU   /*   59  */
#define _0011_1100b   0x3cU   /*   60  */
#define _0011_1101b   0x3dU   /*   61  */
#define _0011_1110b   0x3eU   /*   62  */
#define _0011_1111b   0x3fU   /*   63  */

#define _0100_0000b   0x40U   /*   64  */
#define _0100_0001b   0x41U   /*   65  */
#define _0100_0010b   0x42U   /*   66  */
#define _0100_0011b   0x43U   /*   67  */
#define _0100_0100b   0x44U   /*   68  */
#define _0100_0101b   0x45U   /*   69  */
#define _0100_0110b   0x46U   /*   70  */
#define _0100_0111b   0x47U   /*   71  */
#define _0100_1000b   0x48U   /*   72  */
#define _0100_1001b   0x49U   /*   73  */
#define _0100_1010b   0x4aU   /*   74  */
#define _0100_1011b   0x4bU   /*   75  */
#define _0100_1100b   0x4cU   /*   76  */
#define _0100_1101b   0x4dU   /*   77  */
#define _0100_1110b   0x4eU   /*   78  */
#define _0100_1111b   0x4fU   /*   79  */

#define _0101_0000b   0x50U   /*   80  */
#define _0101_0001b   0x51U   /*   81  */
#define _0101_0010b   0x52U   /*   82  */
#define _0101_0011b   0x53U   /*   83  */
#define _0101_0100b   0x54U   /*   84  */
#define _0101_0101b   0x55U   /*   85  */
#define _0101_0110b   0x56U   /*   86  */
#define _0101_0111b   0x57U   /*   87  */
#define _0101_1000b   0x58U   /*   88  */
#define _0101_1001b   0x59U   /*   89  */
#define _0101_1010b   0x5aU   /*   90  */
#define _0101_1011b   0x5bU   /*   91  */
#define _0101_1100b   0x5cU   /*   92  */
#define _0101_1101b   0x5dU   /*   93  */
#define _0101_1110b   0x5eU   /*   94 */
#define _0101_1111b   0x5fU   /*   95 */

#define _0110_0000b   0x60U   /*   96  */
#define _0110_0001b   0x61U   /*   97  */
#define _0110_0010b   0x62U   /*   98  */
#define _0110_0011b   0x63U   /*   99  */
#define _0110_0100b   0x64U   /*  100  */
#define _0110_0101b   0x65U   /*  101  */
#define _0110_0110b   0x66U   /*  102  */
#define _0110_0111b   0x67U   /*  103  */
#define _0110_1000b   0x68U   /*  104  */
#define _0110_1001b   0x69U   /*  105  */
#define _0110_1010b   0x6aU   /*  106  */
#define _0110_1011b   0x6bU   /*  107  */
#define _0110_1100b   0x6cU   /*  108  */
#define _0110_1101b   0x6dU   /*  109  */
#define _0110_1110b   0x6eU   /*  110  */
#define _0110_1111b   0x6fU   /*  111  */

#define _0111_0000b   0x70U   /*  112  */
#define _0111_0001b   0x71U   /*  113  */
#define _0111_0010b   0x72U   /*  114  */
#define _0111_0011b   0x73U   /*  115  */
#define _0111_0100b   0x74U   /*  116  */
#define _0111_0101b   0x75U   /*  117  */
#define _0111_0110b   0x76U   /*  118  */
#define _0111_0111b   0x77U   /*  119  */
#define _0111_1000b   0x78U   /*  120  */
#define _0111_1001b   0x79U   /*  121  */
#define _0111_1010b   0x7aU   /*  122  */
#define _0111_1011b   0x7bU   /*  123  */
#define _0111_1100b   0x7cU   /*  124  */
#define _0111_1101b   0x7dU   /*  125  */
#define _0111_1110b   0x7eU   /*  126  */
#define _0111_1111b   0x7fU   /*  127  */

#define _1000_0000b   0x80U   /*  128  */
#define _1000_0001b   0x81U   /*  129  */
#define _1000_0010b   0x82U   /*  130  */
#define _1000_0011b   0x83U   /*  131  */
#define _1000_0100b   0x84U   /*  132  */
#define _1000_0101b   0x85U   /*  133  */
#define _1000_0110b   0x86U   /*  134  */
#define _1000_0111b   0x87U   /*  135  */
#define _1000_1000b   0x88U   /*  136  */
#define _1000_1001b   0x89U   /*  137  */
#define _1000_1010b   0x8aU   /*  138  */
#define _1000_1011b   0x8bU   /*  139  */
#define _1000_1100b   0x8cU   /*  140  */
#define _1000_1101b   0x8dU   /*  141  */
#define _1000_1110b   0x8eU   /*  142  */
#define _1000_1111b   0x8fU   /*  143  */

#define _1001_0000b   0x90U   /*  144  */
#define _1001_0001b   0x91U   /*  145  */
#define _1001_0010b   0x92U   /*  146  */
#define _1001_0011b   0x93U   /*  147  */
#define _1001_0100b   0x94U   /*  148  */
#define _1001_0101b   0x95U   /*  149  */
#define _1001_0110b   0x96U   /*  150  */
#define _1001_0111b   0x97U   /*  151  */
#define _1001_1000b   0x98U   /*  152  */
#define _1001_1001b   0x99U   /*  153  */
#define _1001_1010b   0x9aU   /*  154  */
#define _1001_1011b   0x9bU   /*  155  */
#define _1001_1100b   0x9cU   /*  156  */
#define _1001_1101b   0x9dU   /*  157  */
#define _1001_1110b   0x9eU   /*  158  */
#define _1001_1111b   0x9fU   /*  159  */

#define _1010_0000b   0xa0U   /*  160  */
#define _1010_0001b   0xa1U   /*  161  */
#define _1010_0010b   0xa2U   /*  162  */
#define _1010_0011b   0xa3U   /*  163  */
#define _1010_0100b   0xa4U   /*  164  */
#define _1010_0101b   0xa5U   /*  165  */
#define _1010_0110b   0xa6U   /*  166  */
#define _1010_0111b   0xa7U   /*  167  */
#define _1010_1000b   0xa8U   /*  168  */
#define _1010_1001b   0xa9U   /*  169  */
#define _1010_1010b   0xaaU   /*  170  */
#define _1010_1011b   0xabU   /*  171  */
#define _1010_1100b   0xacU   /*  172  */
#define _1010_1101b   0xadU   /*  173  */
#define _1010_1110b   0xaeU   /*  174  */
#define _1010_1111b   0xafU   /*  175  */

#define _1011_0000b   0xb0U   /*  176  */
#define _1011_0001b   0xb1U   /*  177  */
#define _1011_0010b   0xb2U   /*  178  */
#define _1011_0011b   0xb3U   /*  179  */
#define _1011_0100b   0xb4U   /*  180  */
#define _1011_0101b   0xb5U   /*  181  */
#define _1011_0110b   0xb6U   /*  182  */
#define _1011_0111b   0xb7U   /*  183  */
#define _1011_1000b   0xb8U   /*  184  */
#define _1011_1001b   0xb9U   /*  185  */
#define _1011_1010b   0xbaU   /*  186  */
#define _1011_1011b   0xbbU   /*  187  */
#define _1011_1100b   0xbcU   /*  188  */
#define _1011_1101b   0xbdU   /*  189  */
#define _1011_1110b   0xbeU   /*  190  */
#define _1011_1111b   0xbfU   /*  191  */

#define _1100_0000b   0xc0U   /*  192  */
#define _1100_0001b   0xc1U   /*  193  */
#define _1100_0010b   0xc2U   /*  194  */
#define _1100_0011b   0xc3U   /*  195  */
#define _1100_0100b   0xc4U   /*  196  */
#define _1100_0101b   0xc5U   /*  197  */
#define _1100_0110b   0xc6U   /*  198  */
#define _1100_0111b   0xc7U   /*  199  */
#define _1100_1000b   0xc8U   /*  200  */
#define _1100_1001b   0xc9U   /*  201  */
#define _1100_1010b   0xcaU   /*  202  */
#define _1100_1011b   0xcbU   /*  203  */
#define _1100_1100b   0xccU   /*  204  */
#define _1100_1101b   0xcdU   /*  205  */
#define _1100_1110b   0xceU   /*  206  */
#define _1100_1111b   0xcfU   /*  207  */

#define _1101_0000b   0xd0U   /*  208  */
#define _1101_0001b   0xd1U   /*  209  */
#define _1101_0010b   0xd2U   /*  210  */
#define _1101_0011b   0xd3U   /*  211  */
#define _1101_0100b   0xd4U   /*  212  */
#define _1101_0101b   0xd5U   /*  213  */
#define _1101_0110b   0xd6U   /*  214  */
#define _1101_0111b   0xd7U   /*  215  */
#define _1101_1000b   0xd8U   /*  216  */
#define _1101_1001b   0xd9U   /*  217  */
#define _1101_1010b   0xdaU   /*  218  */
#define _1101_1011b   0xdbU   /*  219  */
#define _1101_1100b   0xdcU   /*  220  */
#define _1101_1101b   0xddU   /*  221  */
#define _1101_1110b   0xdeU   /*  222  */
#define _1101_1111b   0xdfU   /*  223  */

#define _1110_0000b   0xe0U   /*  224  */
#define _1110_0001b   0xe1U   /*  225  */
#define _1110_0010b   0xe2U   /*  226  */
#define _1110_0011b   0xe3U   /*  227  */
#define _1110_0100b   0xe4U   /*  228  */
#define _1110_0101b   0xe5U   /*  229  */
#define _1110_0110b   0xe6U   /*  230  */
#define _1110_0111b   0xe7U   /*  231  */
#define _1110_1000b   0xe8U   /*  232  */
#define _1110_1001b   0xe9U   /*  233  */
#define _1110_1010b   0xeaU   /*  234  */
#define _1110_1011b   0xebU   /*  235  */
#define _1110_1100b   0xecU   /*  236  */
#define _1110_1101b   0xedU   /*  237  */
#define _1110_1110b   0xeeU   /*  238  */
#define _1110_1111b   0xefU   /*  239  */

#define _1111_0000b   0xf0U   /*  240  */
#define _1111_0001b   0xf1U   /*  241  */
#define _1111_0010b   0xf2U   /*  242  */
#define _1111_0011b   0xf3U   /*  243  */
#define _1111_0100b   0xf4U   /*  244  */
#define _1111_0101b   0xf5U   /*  245  */
#define _1111_0110b   0xf6U   /*  246  */
#define _1111_0111b   0xf7U   /*  247  */
#define _1111_1000b   0xf8U   /*  248  */
#define _1111_1001b   0xf9U   /*  249  */
#define _1111_1010b   0xfaU   /*  250  */
#define _1111_1011b   0xfbU   /*  251  */
#define _1111_1100b   0xfcU   /*  252  */
#define _1111_1101b   0xfdU   /*  253  */
#define _1111_1110b   0xfeU   /*  254  */
#define _1111_1111b   0xffU   /*  255  */



#endif