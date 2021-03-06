#ifndef __CMU_H__
#define __CMU_H__

#define	FIN		(24000000)
#define CLK27M          (27000000)

typedef enum
{
	SYSC_INIT_LOW,		// ARM  800MHz, BUS 165MHz, DMC 330MHz
	SYSC_INIT_NOR,		// ARM  800MHz, BUS 200MHz, DMC 400MHz
	SYSC_INIT_HIGH,	        // ARM 1000MHz, BUS 200MHz, DMC 400MHz
	SYSC_INIT_VERYLOW,      // ARM  200MHz <-- Do not use !! This is only valid for CMU verification
} SYSC_INIT;

typedef enum
{
	SYSC_ARMCLK,					// CMU_CPU
	SYSC_SCLK_DMC, SYSC_ACLK_CORED, SYSC_ACLK_COREP,// CMU_CORE
	SYSC_ACLK_200, SYSC_ACLK_100,			// CMU_TOP
	SYSC_ACLK_160, SYSC_ACLK_133,
	SYSC_ACLK_GDL, SYSC_ACLK_GPL,			// CMU_LEFTBUS
	SYSC_ACLK_GDR, SYSC_ACLK_GPR,			// CMU_RIGHTBUS

	SYSC_XXTI, SYSC_XUSBXTI,
	SYSC_SCLK_APLL, SYSC_SCLK_MPLL,
	SYSC_SCLK_EPLL, SYSC_SCLK_VPLL
} SYSC_CLK;

typedef enum
{
    SYSC_APLL,  SYSC_MPLL,  SYSC_EPLL,  SYSC_VPLL
} SYSC_PLL;

typedef enum
{
	SYSC_DOWN_SPREAD,
	SYSC_UP_SPREAD,
	SYSC_CENTER_SPREAD,
} SYSC_DITHER;

typedef enum
{
	SYSC_CLKOUT_LEFTBUS_SCLK_MPLL_2,
	SYSC_CLKOUT_LEFTBUS_SCLK_APLL_2,
	SYSC_CLKOUT_LEFTBUS_ACLK_GDL,
	SYSC_CLKOUT_LEFTBUS_ACLK_GPL,
	SYSC_CLKOUT_RIGHTBUS_SCLK_MPLL_2,
	SYSC_CLKOUT_RIGHTBUS_SCLK_APLL_2,
	SYSC_CLKOUT_RIGHTBUS_ACLK_GDR,
	SYSC_CLKOUT_RIGHTBUS_ACLK_GPR,
	SYSC_CLKOUT_TOP_EPLL_FOUT,
	SYSC_CLKOUT_TOP_VPLL_FOUT,
	SYSC_CLKOUT_TOP_SCLK_HDMI27M,
	SYSC_CLKOUT_TOP_SCLK_USBPHY0,
	SYSC_CLKOUT_TOP_SCLK_USBPHY1,
	SYSC_CLKOUT_TOP_SCLK_HDMIPHY,
	SYSC_CLKOUT_TOP_AUDIOCDCLK0,
	SYSC_CLKOUT_TOP_AUDIOCDCLK1,
	SYSC_CLKOUT_TOP_AUDIOCDCLK2,
	SYSC_CLKOUT_TOP_SPDIF_EXTCLK,
	SYSC_CLKOUT_TOP_ACLK_160,
	SYSC_CLKOUT_TOP_ACLK_133,
	SYSC_CLKOUT_TOP_ACLK_200,
	SYSC_CLKOUT_TOP_ACLK_100,
	SYSC_CLKOUT_TOP_SCLK_MFC,
	SYSC_CLKOUT_TOP_SCLK_G3D,
	SYSC_CLKOUT_TOP_SCLK_G2D,
	SYSC_CLKOUT_TOP_CAM_A_PCLK,
	SYSC_CLKOUT_TOP_CAM_B_PCLK,
	SYSC_CLKOUT_TOP_S_RXBYTECLKHS0_2L,
	SYSC_CLKOUT_TOP_S_RXBYTECLKHS0_4L,
	SYSC_CLKOUT_TOP_RX_HALF_BYTE_CLK_CSIS0,
	SYSC_CLKOUT_TOP_RX_HALF_BYTE_CLK_CSIS1,
	SYSC_CLKOUT_CORE_ACLK_CORED,
	SYSC_CLKOUT_CORE_ACLK_COREP,
	SYSC_CLKOUT_CORE_ACLK_ACP,
	SYSC_CLKOUT_CORE_PCLK_ACP,
	SYSC_CLKOUT_CORE_SCLK_DMC,
	SYSC_CLKOUT_CORE_SCLK_DPHY,
	SYSC_CLKOUT_CORE_SCLK_CORE_TIMERS,
	SYSC_CLKOUT_CORE_SCLK_PWI,
	SYSC_CLKOUT_CPU_APLL_FOUT_2,
	SYSC_CLKOUT_CPU_APLL_VCOOUT_4,
	SYSC_CLKOUT_CPU_MPLL_FOUT_2,
	SYSC_CLKOUT_CPU_MPLL_VCOOUT_4,
	SYSC_CLKOUT_CPU_ARMCLK_2,
	SYSC_CLKOUT_CPU_ACLK_COREM0,
	SYSC_CLKOUT_CPU_ACLK_COREM1,
	SYSC_CLKOUT_CPU_ACLK_CORES,
	SYSC_CLKOUT_CPU_ATCLK,
	SYSC_CLKOUT_CPU_PERIPHCLK,
	SYSC_CLKOUT_CPU_PCLK_DBG,
	SYSC_CLKOUT_CPU_SCLK_HPM,
	SYSC_CLKOUT_XXTI,
	SYSC_CLKOUT_XUSBXTI,
	SYSC_CLKOUT_RTC_TICCLK,
	SYSC_CLKOUT_RTCCLK,
	SYSC_CLKOUT_DISABLE
} SYSC_CLKOUT;

typedef enum
{
	SYSC_MUX_GDL,
	SYSC_MUX_GDR,
	SYSC_MUX_ONENAND,
	SYSC_MUX_ACLK_133,
	SYSC_MUX_ACLK_160,
	SYSC_MUX_ACLK_100,
	SYSC_MUX_ACLK_200,
	SYSC_MUX_VPLL,
	SYSC_MUX_EPLL,
	SYSC_MUX_VPLLSRC,
	SYSC_MUX_CSIS1,
	SYSC_MUX_CSIS0,
	SYSC_MUX_CAM1,
	SYSC_MUX_CAM0,
	SYSC_MUX_FIMC3_LCLK,
	SYSC_MUX_FIMC2_LCLK,
	SYSC_MUX_FIMC1_LCLK,
	SYSC_MUX_FIMC0_LCLK,
	SYSC_MUX_DAC,
	SYSC_MUX_MIXER,
	SYSC_MUX_HDMI,
	SYSC_MUX_MFC,
	SYSC_MUX_MFC_1,
	SYSC_MUX_MFC_0,
	SYSC_MUX_G3D,
	SYSC_MUX_G3D_1,
	SYSC_MUX_G3D_0,
	SYSC_MUX_G2D,
	SYSC_MUX_G2D_1,
	SYSC_MUX_G2D_0,
	SYSC_MUX_MIPI0,
	SYSC_MUX_MDNIE_PWM0,
	SYSC_MUX_MDNIE0,
	SYSC_MUX_FIMD0,
	SYSC_MUX_MIPI1,
	SYSC_MUX_MDNIE_PWM1,
	SYSC_MUX_MDNIE1,
	SYSC_MUX_FIMD1,
	SYSC_MUX_AUDIO0,
	SYSC_MUX_SATA,
	SYSC_MUX_MMC4,
	SYSC_MUX_MMC3,
	SYSC_MUX_MMC2,
	SYSC_MUX_MMC1,
	SYSC_MUX_MMC0,
	SYSC_MUX_PWM,
	SYSC_MUX_UART5,
	SYSC_MUX_UART4,
	SYSC_MUX_UART3,
	SYSC_MUX_UART2,
	SYSC_MUX_UART1,
	SYSC_MUX_UART0,
	SYSC_MUX_SPI3,
	SYSC_MUX_SPI2,
	SYSC_MUX_SPI1,
	SYSC_MUX_SPI0,
	SYSC_MUX_SPDIF,
	SYSC_MUX_AUDIO2,
	SYSC_MUX_AUDIO1,
	SYSC_MUX_PWI,
	SYSC_MUX_CORE_TIMERS,
	SYSC_MUX_DPHY,
	SYSC_MUX_CORE_BUS,
	SYSC_MUX_HPM,
	SYSC_MUX_CORE,
	SYSC_MUX_MPLLFOUT,		// hidden spec (will be removed from manual & code)
	SYSC_MUX_MPLL,
	SYSC_MUX_APLLFOUT,		// hidden spec (will be removed from manual & code)
	SYSC_MUX_APLL
} SYSC_MUX;

typedef enum
{
	SYSC_DIV_GPL,
	SYSC_DIV_GDL,
	SYSC_DIV_GPR,
	SYSC_DIV_GDR,
	SYSC_DIV_ONENAND,
	SYSC_DIV_ACLK_133,
	SYSC_DIV_ACLK_160,
	SYSC_DIV_ACLK_100,
	SYSC_DIV_ACLK_200,
	SYSC_DIV_CSIS1,
	SYSC_DIV_CSIS0,
	SYSC_DIV_CAM1,
	SYSC_DIV_CAM0,
	SYSC_DIV_FIMC3_LCLK,
	SYSC_DIV_FIMC2_LCLK,
	SYSC_DIV_FIMC1_LCLK,
	SYSC_DIV_FIMC0_LCLK,
	SYSC_DIV_TV_BLK,
	SYSC_DIV_MFC,
	SYSC_DIV_G3D,
	SYSC_DIV_G2D,
	SYSC_DIV_MIPI0_PRE,
	SYSC_DIV_MIPI0,
	SYSC_DIV_MDNIE_PWM0_PRE,
	SYSC_DIV_MDNIE_PWM0,
	SYSC_DIV_MDNIE0,
	SYSC_DIV_FIMD0,
	SYSC_DIV_MIPI1_PRE,
	SYSC_DIV_MIPI1,
	SYSC_DIV_MDNIE_PWM1_PRE,
	SYSC_DIV_MDNIE_PWM1,
	SYSC_DIV_MDNIE1,
	SYSC_DIV_FIMD1,
	SYSC_DIV_PCM0,
	SYSC_DIV_AUDIO0,
	SYSC_DIV_SATA,
	SYSC_DIV_MMC1_PRE,
	SYSC_DIV_MMC1,
	SYSC_DIV_MMC0_PRE,
	SYSC_DIV_MMC0,
	SYSC_DIV_MMC3_PRE,
	SYSC_DIV_MMC3,
	SYSC_DIV_MMC2_PRE,
	SYSC_DIV_MMC2,
	SYSC_DIV_MMC4_PRE,
	SYSC_DIV_MMC4,
	SYSC_DIV_UART5,
	SYSC_DIV_UART4,
	SYSC_DIV_UART3,
	SYSC_DIV_UART2,
	SYSC_DIV_UART1,
	SYSC_DIV_UART0,
	SYSC_DIV_SPI1_PRE,
	SYSC_DIV_SPI1,
	SYSC_DIV_SPI0_PRE,
	SYSC_DIV_SPI0,
	SYSC_DIV_SPI3_PRE,
	SYSC_DIV_SPI3,
	SYSC_DIV_SPI2_PRE,
	SYSC_DIV_SPI2,
	SYSC_DIV_SLIMBUS,
	SYSC_DIV_PWM,
	SYSC_DIV_PCM2,
	SYSC_DIV_AUDIO2,
	SYSC_DIV_PCM1,
	SYSC_DIV_AUDIO1,
	SYSC_DIV_I2S2,
	SYSC_DIV_I2S1,
	SYSC_DIV2_GPS_BLK,
	SYSC_DIV2_TV_BLK,
	SYSC_DIV2_LCD1_BLK,
	SYSC_DIV2_LCD0_BLK,
	SYSC_DIV2_IMG_BLK,
	SYSC_DIV2_CAM_BLK,
	SYSC_DIV2_FSYS_BLK,
	SYSC_DIV_CORE_TIMERS,
	SYSC_DIV_COPY2,
	SYSC_DIV_COREP,
	SYSC_DIV_CORED,
	SYSC_DIV_DMC,
	SYSC_DIV_DPHY,
	SYSC_DIV_ACP_PCLK,
	SYSC_DIV_ACP,
	SYSC_DIV_DPM,
	SYSC_DIV_DVSEM,
	SYSC_DIV_PWI,
	SYSC_DIV_APLL,
	SYSC_DIV_PCLK_DBG,
	SYSC_DIV_ATB,
	SYSC_DIV_PERIPH,
	SYSC_DIV_COREM1,
	SYSC_DIV_COREM0,
	SYSC_DIV_CORE,
	SYSC_DIV_HPM,
	SYSC_DIV_COPY
} SYSC_DIV;

typedef enum
{
	SYSC_GATE_PPMULEFT,
	SYSC_GATE_PPMURIGHT,
	SYSC_GATE_PIXELASYNCM1,
	SYSC_GATE_PIXELASYNCM0,
	SYSC_GATE_PPMUCAMIF,
	SYSC_GATE_QEFIMC3,
	SYSC_GATE_QEFIMC2,
	SYSC_GATE_QEFIMC1,
	SYSC_GATE_QEFIMC0,
	SYSC_GATE_SMMUJPEG,
	SYSC_GATE_SMMUFIMC3,
	SYSC_GATE_SMMUFIMC2,
	SYSC_GATE_SMMUFIMC1,
	SYSC_GATE_SMMUFIMC0,
	SYSC_GATE_JPEG,
	SYSC_GATE_CSIS1,
	SYSC_GATE_CSIS0,
	SYSC_GATE_FIMC3,
	SYSC_GATE_FIMC2,
	SYSC_GATE_FIMC1,
	SYSC_GATE_FIMC0,
	SYSC_GATE_PPMUTV,
	SYSC_GATE_SMMUTV,
	SYSC_GATE_HDMI,
	SYSC_GATE_TVENC,
	SYSC_GATE_MIXER,
	SYSC_GATE_VP,
	SYSC_GATE_PPMUMFC_R,
	SYSC_GATE_PPMUMFC_L,
	SYSC_GATE_SMMUMFC_R,
	SYSC_GATE_SMMUMFC_L,
	SYSC_GATE_MFC,
	SYSC_GATE_PPMUG3D,
	SYSC_GATE_G3D,
	SYSC_GATE_PPMUIMAGE,
	SYSC_GATE_QEMDMA2,
	SYSC_GATE_QEROTATOR,
	SYSC_GATE_QEG2D,
	SYSC_GATE_SMMUMDMA2,
	SYSC_GATE_SMMUROTATOR,
	SYSC_GATE_SMMUG2D,
	SYSC_GATE_MDMA2,
	SYSC_GATE_ROTATOR,
	SYSC_GATE_G2D,
	SYSC_GATE_PPMULCD0,
	SYSC_GATE_SMMUFIMD0,
	SYSC_GATE_DSIM0,
	SYSC_GATE_MDNIE0,
	SYSC_GATE_MIE0,
	SYSC_GATE_FIMD0,
	SYSC_GATE_PPMULCD1,
	SYSC_GATE_SMMUFIMD1,
	SYSC_GATE_DSIM1,
	SYSC_GATE_MDNIE1,
	SYSC_GATE_MIE1,
	SYSC_GATE_FIMD1,
	SYSC_GATE_PPMUPCIE,
	SYSC_GATE_PPMUFILE,
	SYSC_GATE_NFCON,
	SYSC_GATE_ONENAND,
	SYSC_GATE_PCIE,
	SYSC_GATE_USBOTG,
	SYSC_GATE_USBHOST,
	SYSC_GATE_SROMC,
	SYSC_GATE_SATA,
	SYSC_GATE_SDMMC4,
	SYSC_GATE_SDMMC3,
	SYSC_GATE_SDMMC2,
	SYSC_GATE_SDMMC1,
	SYSC_GATE_SDMMC0,
	SYSC_GATE_TSI,
	SYSC_GATE_SATAPHY,
	SYSC_GATE_PCIEPHY,
	SYSC_GATE_PDMA1,
	SYSC_GATE_PDMA0,
	SYSC_GATE_SMMUGPS,
	SYSC_GATE_GPS,
	SYSC_GATE_MODEMIF,
	SYSC_GATE_AC97,
	SYSC_GATE_SPDIF,
	SYSC_GATE_SLIMBUS,
	SYSC_GATE_PWM,
	SYSC_GATE_PCM2,
	SYSC_GATE_PCM1,
	SYSC_GATE_I2S2,
	SYSC_GATE_I2S1,
	SYSC_GATE_SPI3,
	SYSC_GATE_SPI2,
	SYSC_GATE_SPI1,
	SYSC_GATE_SPI0,
	SYSC_GATE_TSADC,
	SYSC_GATE_I2CHDMI,
	SYSC_GATE_I2C7,
	SYSC_GATE_I2C6,
	SYSC_GATE_I2C5,
	SYSC_GATE_I2C4,
	SYSC_GATE_I2C3,
	SYSC_GATE_I2C2,
	SYSC_GATE_I2C1,
	SYSC_GATE_I2C0,
	SYSC_GATE_UART5,
	SYSC_GATE_UART4,
	SYSC_GATE_UART3,
	SYSC_GATE_UART2,
	SYSC_GATE_UART1,
	SYSC_GATE_UART0,
	SYSC_GATE_KEYIF,
	SYSC_GATE_RTC,
	SYSC_GATE_WDT,
	SYSC_GATE_ST,
	SYSC_GATE_SECKEY,
	SYSC_GATE_HDMI_CEC,
	SYSC_GATE_TZPC5,
	SYSC_GATE_TZPC4,
	SYSC_GATE_TZPC3,
	SYSC_GATE_TZPC2,
	SYSC_GATE_TZPC1,
	SYSC_GATE_TZPC0,
	SYSC_GATE_CMU_COREPART,
	SYSC_GATE_CMU_TOPPART,
	SYSC_GATE_PMU_APBIF,
	SYSC_GATE_SYSREG,
	SYSC_GATE_CHIP_ID,
	SYSC_GATE_GIC,
	SYSC_GATE_CORE_TIMERS,
	SYSC_GATE_IEM_IEC,
	SYSC_GATE_IEM_APC,
	SYSC_GATE_PPMUACP,
	SYSC_GATE_QESSS,
	SYSC_GATE_QEMDMA,
	SYSC_GATE_ID_REMAPPER,
	SYSC_GATE_SMMUSSS,
	SYSC_GATE_SMMUMDMA,
	SYSC_GATE_PPMUCPU,
	SYSC_GATE_PPMUDMC1,
	SYSC_GATE_PPMUDMC0,
	SYSC_GATE_QECPU,
	SYSC_GATE_SECJTAG,
	SYSC_GATE_SSS,
	SYSC_GATE_MDMA,
	SYSC_GATE_INT_COMB,
	SYSC_GATE_DMC1,
	SYSC_GATE_DMC0
} SYSC_GATE_IP;

typedef enum
{
	SYSC_GATE_BLK_LCD1,
	SYSC_GATE_BLK_LCD0,
	SYSC_GATE_BLK_G3D,
	SYSC_GATE_BLK_MFC,
	SYSC_GATE_BLK_TV,
	SYSC_GATE_BLK_CAM
} SYSC_GATE_BLK;


typedef struct tag_CPU_DIV
{	
	u32 uDivApll;
	u32 uDivCore;
	u32 uDivCoreM0;
	u32 uDivCoreM1;
	u32 uDivPeriph;
	u32 uDivAtb;
	u32 uDivPclkDbg;
	u32 uDivCopy;
	u32 uDivHpm;
} oCPU_DIV;


typedef struct tag_CORE_DIV
{	
	u32 uDivDmc;
	u32 uDivCoreD;
	u32 uDivCoreP;
	u32 uDivAcp;
	u32 uDivAcpPclk;
	u32 uDivDphy;
	u32 uDivDpm;
	u32 uDivDvsem;
	u32 uDivCopy2;
	u32 uDivCoreTimers;
} oCORE_DIV;

typedef struct tag_TOPBUS_DIV
{	
	u32 uDivAclk200;
	u32 uDivAclk100;
	u32 uDivAclk160;
	u32 uDivAclk133;
	u32 uDivGdl;
	u32 uDivGpl;
	u32 uDivGdr;
	u32 uDivGpr;
} oTOPBUS_DIV;


/*
 * CMU API Driver : PLL drivers
 *
 * [Set P,M,S,K value to register ]
 * Return PLL fout
*/

float SYSC_SetPllByPms(SYSC_PLL ePLL, u32 uPdiv, u32 uMdiv, u32 uSdiv, u32 uKdiv);

// [Set P,M,S,K value to register by fout value ]
void SYSC_SetPllByFout(SYSC_PLL ePLL, u32 uFout);

// [Get pll fout from reading register ]
// Return PLL fout
float SYSC_GetFoutPll(SYSC_PLL ePLL);

// [Get pll vco from reading register ]
// Return PLL vco
float SYSC_GetVcoPll(SYSC_PLL ePLL);

// [Calc pll fout ]
// Return PLL fout
float SYSC_CalcPllFout(SYSC_PLL ePLL, u32 uPdiv, u32 uMdiv, u32 uSdiv, u32 uKdiv);

// [Set pll lock time (us) ]
void SYSC_SetLocktimeVal(SYSC_PLL ePLL, u32 uMicroSec);

// [Check pll lock ]
u32 SYSC_CheckPllLock(SYSC_PLL ePLL);

// [Set pll enable ]
void SYSC_EnablePll(SYSC_PLL ePLL);

// [Set pll disable ]
void SYSC_DisablePll(SYSC_PLL ePLL);

// [Set vpll dither mode param ]
void SYSC_SetDitherParam( bool bEnDither, u32 uMrr, u32 uMfr, SYSC_DITHER eDitherMethod);

///////////////////////////////////
// CMU API Driver : MUX drivers
///////////////////////////////////
// [Set mux src clk]
void SYSC_SetMuxSrc(SYSC_MUX eMux, u32 uMuxSelVal);

// [Get mux src clk state]
u32 SYSC_GetMuxSrc(SYSC_MUX eMux);

///////////////////////////////////
// CMU API Driver : Divider drivers
///////////////////////////////////
// [Set divider value]
void SYSC_SetClkDiv(SYSC_DIV eDiv, u32 uRatio);

// [Get divider value]
u32 SYSC_GetClkDiv(SYSC_DIV eDiv);

///////////////////////////////////
// CMU API Driver : Clock Gate drivers
///////////////////////////////////
// [Set ip clk gate]
void SYSC_SetClkGateIp(SYSC_GATE_IP eIp, bool bIsPass);

// [Get ip clk gate]
u32 SYSC_GetClkGateIp(SYSC_GATE_IP eIp);

// [Set blk clk gate]
void SYSC_SetClkGateBlock(SYSC_GATE_BLK eBlk, bool bIsPass);

// [Get blk clk gate]
u32 SYSC_GetClkGateBlock(SYSC_GATE_BLK eBlk);

///////////////////////////////////
// CMU API Driver : ETC drivers
///////////////////////////////////
// [Get Clock Frequency]
// Return SYSC_CLK clock frequency
float SYSC_GetClkFreq(SYSC_CLK eClk);

// [Initialize System Clock]
void SYSC_InitSysClk(SYSC_INIT eInit);

// [Set clk out]
void SYSC_SetClkOut( SYSC_CLKOUT eClkOut, u32 uDivVal );

void SYSC_SetCpuDiv(oCPU_DIV *poCpuDiv);
void SYSC_SetCoreDiv(oCORE_DIV *poCoreDiv);
void SYSC_SetTopBusDiv(oTOPBUS_DIV *poTopBusDiv);
void SYSC_SetDivDefaultVal(oCPU_DIV *poCpuDiv, oCORE_DIV *poCoreDiv, oTOPBUS_DIV *poTopBusDiv);
void SYSC_ChangePllnDiv(SYSC_PLL ePll, u32 uPdiv, u32 uMdiv, u32 uSdiv, u32 uKdiv, u32 uLockTime, oCPU_DIV *poCpuDiv, oCORE_DIV *poCoreDiv, oTOPBUS_DIV *poTopBusDiv);

/////////////////////////////////////////////
// CMU API Driver : CMU Test drivers (Do not use !!)
/////////////////////////////////////////////
void ExitIfNull(char* str);
u32 SYSC_GetNumOfClkOut(void);
void SYSC_GetClkOutName( u32 uClkOutIdx, char* strClkOutName );
void SYSC_SetClkOutByIdx( u32 uClkOutIdx, u32 uDivVal );
u32 SYSC_GetClkOutVal( u32 uClkOutIdx );

u32 SYSC_GetNumOfMux();
void SYSC_GetMuxName(  u32 uMuxIdx, char* strMuxName );
u32 SYSC_GetNumOfMuxSrc( u32 uMuxIdx );
void SYSC_GetMuxSrcName( u32 uMuxIdx, u32 uIdxOfMuxSrc, char* strMuxSrcName );
void SYSC_SetMuxSrcByIdx( u32 uMuxIdx, u32 uIdxOfMuxSrc );
u32 SYSC_GetMuxSrcClkVal( u32 uMuxIdx, u32 uIdxOfMuxSrc );
u32 SYSC_GetIdxOfClkOutForMux( u32 uMuxIdx );
u32 SYSC_GetClkOutValForMux( u32 uMuxIdx, u32 uIdxOfMuxSrc );

u32 SYSC_GetNumOfDiv();
void SYSC_GetDivName( u32 uDivIdx, char* strDivName );
u32 SYSC_GetDivInClkVal( u32 uDivIdx );
u32 SYSC_GetMaxDivVal( u32 uDivIdx );
void SYSC_SetDivValByIdx( u32 uDivIdx, u32 uDivVal );
u32 SYSC_GetDivValByIdx( u32 uDivIdx );
u32 SYSC_GetIdxOfClkOutForDiv( u32 uDivIdx );
u32 SYSC_GetClkOutValForDiv( u32 uDivIdx );

void SYSC_SelectClkGating(void);

#endif /* __CMU_H_ */_
