/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           : rscan_reg.h
|    Project        : CAN Driver development
|    Description    : The file contains the register defnition.
|    Version        : V1_00
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date             Name                      Company
| --------     ---------------------     ---------------------------------------
| 18/10/2023     Jeevan Jestin N           Sloki Software Technologies Pvt Ltd.
|-------------------------------------------------------------------------------
|******************************************************************************/

#ifndef RSCAN_REG_H
#define RSCAN_REG_H
/*******************************************************************************
 *  HEARDER FILE INCLUDES
 ******************************************************************************/

/*******************************************************************************
 *  MACRO DEFNITION
 ******************************************************************************/
#define CAN_NO_ERROR                      0x00
#define CAN_BUS_OFF_STATUS                0X01
#define CAN_PASSIVE_ERROR_STATUS          0X02


#define CAN_BUSOFF_NOT_STATUS               0
#define CAN_BUS_OFF_STATUS                  1

#define CAN_PASSIVE_NOT_STATUS              0
#define CAN_PASSIVE_STATUS                  1

/* RS CAN FD Channel related Register*/
#define CFDCmNCFG(base,channel)  *((volatile uint32_t*)(base+0x00+(0x10*channel)))  
#define CFDCmCTR(base,channel)  *((volatile uint32_t*)(base+0x04+(0x10*channel)))
#define CFDCmSTS(base,channel)  *((volatile uint32_t*)(base+0x08+(0x10*channel)))
#define CFDCmERFL(base,channel)  *((volatile uint32_t*)(base+0x0C+(0x10*channel)))
#define CFDCmDCFG(base,channel)  *((volatile uint32_t*)(base+0x700+(0x20*channel)))
#define CFDCmFDCFG(base,channel)  *((volatile uint32_t*)(base+0x704+(0x20*channel)))
#define CFDCmFDCTR(base,channel)  *((volatile uint32_t*)(base+0x708+(0x20*channel)))
#define CFDCmFDSTS(base,channel)  *((volatile uint32_t*)(base+0x70C+(0x20*channel)))
#define CFDCmFDCRC(base,channel)  *((volatile uint32_t*)(base+0x710+(0x20*channel)))

/* Global related register */
#define CFDGCFG(base)   *((volatile uint32_t*)(base+0x84))
#define CFDGCTR(base)   *((volatile uint32_t*)(base+0x88))
#define CFDGSTS(base)   *((volatile uint32_t*)(base+0x8C))
#define CFDGERFL(base)   *((volatile uint32_t*)(base+0x90))
#define CFDGTSC(base)   *((volatile uint32_t*)(base+0x94))
#define CFDGTINTSTS0(base)   *((volatile uint32_t*)(base+0x610))
#define CFDGTINTSTS1(base)   *((volatile uint32_t*)(base+0x614))
#define CFDGFDCFG(base)   *((volatile uint32_t*)(base+0x624))

/* Recieve rule related registers */
#define CFDGAFLECTR(base)   *((volatile uint32_t*)(base+0x98))
#define CFDGAFLCFG0(base)   *((volatile uint32_t*)(base+0x9C))
#define CFDGAFLCFG1(base)   *((volatile uint32_t*)(base+0xA0))
#define CFDGAFLIDj(base, Rulenum) *((volatile uint32_t*)(base+0x1000+(0x10*Rulenum)))
#define CFDGAFLMj(base, Rulenum) *((volatile uint32_t*)(base+0x1004+(0x10*Rulenum)))
#define CFDGAFLP0j(base, Rulenum) *((volatile uint32_t*)(base+0x1008+(0x10*Rulenum)))
#define CFDGAFLP1j(base, Rulenum) *((volatile uint32_t*)(base+0x100C+(0x10*Rulenum)))


/* Receieve buffer related register */
#define CFDRMNB(base)   *((volatile uint32_t*)(base+0xA4))
#define CFDRMNDy(base,x)   *((volatile uint32_t*)(base+0xA8+(0x04*x)))
#define CFDRMIDq(base,Rxbuff) *((volatile uint32_t*)(base+0x2000+(0x80*Rxbuff)))
#define CFDRMPTRq(base,Rxbuff) *((volatile uint32_t*)(base+0x2004+(0x80*Rxbuff)))
#define CFDRMFDSTSq(base,Rxbuff) *((volatile uint32_t*)(base+0x2008+(0x80*Rxbuff)))
#define CFDRMDFb_q(base,x,Rxbuff) *((volatile uint32_t*)(base+0x200C+(0x04*x)+(0x80*Rxbuff)))


/* Recieve FIFO buffer related register */
#define CFDRFCCx(base,Rxfifo)  *((volatile uint32_t*)(base+0xB8+(0x04*Rxfifo)))
#define CFDRFSTSx(base,Rxfifo)  *((volatile uint32_t*)(base+0xD8+(0x04*Rxfifo)))
#define CFDRFPCTRx(base,Rxfifo)  *((volatile uint32_t*)(base+0xF8+(0x04*Rxfifo)))
#define CFDRFIDx(base,Rxfifo)  *((volatile uint32_t*)(base+0x6000+(0x80*Rxfifo)))
#define CFDRFPTRx(base,Rxfifo)  *((volatile uint32_t*)(base+0x6004+(0x80*Rxfifo)))
#define CFDRFFDSTSx(base,Rxfifo)  *((volatile uint32_t*)(base+0x6008+(0x80*Rxfifo)))
#define CFDRFDFd_x(base,x,Rxfifo)  *((volatile uint32_t*)(base+0x600C+(0x80*Rxfifo)+(0x04*x)))

/* Transmit/receive FIFO buffer related register */
#define CFDCFCCk(base ,TxRxfifo) *((volatile uint32_t*)(base+0x118+(0x04*TxRxfifo)))
#define CFDCFSTSk(base ,TxRxfifo) *((volatile uint32_t*)(base+0x178+(0x04*TxRxfifo)))
#define CFDCFPCTRk(base ,TxRxfifo) *((volatile uint32_t*)(base+0x1D8+(0x04*TxRxfifo)))
#define CFDCFIDk(base ,TxRxfifo) *((volatile uint32_t*)(base+0x6400+(0x80*TxRxfifo)))
#define CFDCFPTRk(base ,TxRxfifo) *((volatile uint32_t*)(base+0x6404+(0x80*TxRxfifo)))
#define CFDCFFDCSTSk(base ,TxRxfifo) *((volatile uint32_t*)(base+0x6408+(0x80*TxRxfifo)))
#define RCFDCnCFDCFDFd_k(base,d,TxRxfifo)   *((volatile uint32_t*)(base+0x640C+(0x80*TxRxfifo)+(0x04*d)))

/* FIFO status related register */
#define CFDFESTS(base)   *((volatile uint32_t*)(base+0x238))
#define CFDFFSTS(base)   *((volatile uint32_t*)(base+0x23C))
#define CFDFMSTS(base)   *((volatile uint32_t*)(base+0x240))
#define CFDRFISTS(base)   *((volatile uint32_t*)(base+0x244))
#define CFDCFRISTS(base)   *((volatile uint32_t*)(base+0x248))
#define CFDCFTISTS(base)   *((volatile uint32_t*)(base+0x24C))

/* FIFO DMA related register */
#define CFDCDTCT(base)      *((volatile uint32_t*)(base+0x640))
#define CFDCDTSTS(base)     *((volatile uint32_t*)(base+0x644))


/* Transmit buffer related registers */
#define CFDTMCp(base,Txbuff)    *((volatile uint32_t*)(base+0x250+(0x01*Txbuff)))
#define CFDTMSTSp(base,Txbuff)    *((volatile uint32_t*)(base+0x350+(0x01*Txbuff)))
#define CFDTMIDp(base,Txbuff)    *((volatile uint32_t*)(base+0x8000+(0x80*Txbuff)))
#define CFDTMPTRp(base,Txbuff)    *((volatile uint32_t*)(base+0x8004+(0x80*Txbuff)))
#define CFDTMFDCTRp(base,Txbuff)    *((volatile uint32_t*)(base+0x8008+(0x80*Txbuff)))
#define CFDTMDFb_p(base,d,Txbuff)   *((volatile uint32_t*)(base+0x800C+(0x80*Txbuff)+(0x04*d)))
#define CFDTMIECm(base,channel)     *((volatile uint32_t*)(base+0x4D0+(0x04*channel)))


/* Transmit buffer status related register */
#define CFDTMTRSTSm(base,channel)   *((volatile uint32_t*)(base+0x450+(0x04*channel)))
#define CFDTMTARSTSm(base,channel)  *((volatile uint32_t*)(base+0x470+(0x04*channel))) 
#define CFDTMTCSTSm(base,channel)   *((volatile uint32_t*)(base+0x490+(0x04*channel)))
#define CFDTMTASTSm(base,channel)   *((volatile uint32_t*)(base+0x4B0+(0x04*channel)))


/* Transmit queue related registers */
#define CFDTXQCCm(base,channel)   *((volatile uint32_t*)(base+0x550+(0x04*channel)))
#define CFDTXQSTSm(base,channel)   *((volatile uint32_t*)(base+0x570+(0x04*channel)))
#define CFDTXQPCTRm(base,channel)   *((volatile uint32_t*)(base+0x590+(0x04*channel)))


/* Transmit history related register */
#define CFDTHLCCm(base,channel)   *((volatile uint32_t*)(base+0x5B0+(0x04*channel)))
#define CFDTHLSTSm(base,channel)   *((volatile uint32_t*)(base+0x5D0+(0x04*channel)))
#define CFDTHLPCTRm(base,channel)   *((volatile uint32_t*)(base+0x5F0+(0x04*channel)))
#define CFDTHLACC0m(base,channel)   *((volatile uint32_t*)(base+0x10000+(0x08*channel)))
#define CFDTHLACC1m(base,channel)   *((volatile uint32_t*)(base+0x10004+(0x08*channel)))


/* Test related register */
#define CFDGTSTCFG(base)        *((volatile uint32_t*)(base+0x618))
#define CFDGTSTCTR(base)        *((volatile uint32_t*)(base+0x61C))
#define CFDGLOCKK(base)        *((volatile uint32_t*)(base+0x62C))
#define CFDRPGACCr(base,page)        *((volatile uint32_t*)(base+0x10400+(0x04*page)))

#define MAX_DATA_FIELD          15
#define NEXT_TXRXFIFO_MSG       0xFF


#define CAN_RAM_INIT_STS_MASK   (0x08)
#define GLOBAL_RESET_MODE_STS_MASK  (0x01)

#define GLOBAL_MODE_MASK_INV        (~0x07)
#define GLOBAL_MODE_MASK            (0x07)
#define GLOBAL_OPERATING_MODE   (0x00)
#define GLOBAL_RESET_MODE       (0x01)
#define GLOBAL_TEST_MODE        (0x02)

#define CHANNEL_MODE_MASK_INV      (~0x07)
#define CHANNEL_MODE_MASK           (0x07)
#define CHANNEL_OPERATING_MODE   (0x00)
#define CHANNEL_RESET_MODE       (0x01)
#define CHANNEL_HALT_MODE        (0x02)

#define CLK_XICAN                (0x10)
#define CLKC                     (0x10)

#define NSJW                      (0x00008000)
#define NTSEG_1                   (0x00040000)
#define NTSEG_2                   (0x01000000)
#define NBRP_1MBPS                     (0x04)
#define NBRP_500KBPS                   (0x09)
#define NBRP_250KBPS                   (0x013)
#define NBRP_125KBPS                   (0x027)

#define DSJW                      (0x01000000)
#define DTSEG_2                   (0x00100000)
#define DTSEG_1                   (0x00040000)
#define DTSEG_2_4MBPS             (0x00200000)
#define DTSEG_1_4MBPS             (0x00050000)
#define DTSEG_2_2MBPS             (0x00200000)
#define DTESG_1_2MBPS             (0x00050000)  

#define DBRP_5MBPS                (0x00000000)
#define DBRP_4MBPS                (0x00000000)
#define DBRP_2MBPS                (0x00000001)
#define DBRP_1MBPS                (0x00000004)
#define DBRP_500KBPS              (0x00000009)   
#define DBRP_250KBPS              (0x00000013)
#define DBRP_125KBPS              (0x00000027) 

#define TDC_OFFSET     (0x80000) /*Position 23-16bit*/
#define TDC_ENABLE  (0x200)
#define TDC_OFFSET_EN  (0x100)

#define RECIEVE_RULE_TABLE_ENABLE       (0x0100)
#define RECIEVE_RULE_TABLE_DISABLE      (~0x0100)
#define INIT_RECEIVE_PAGE_NUMBER        (0x00)
#define CHANNEL_0_RULE_POS              (24u)
#define CHANNEL_1_RULE_POS              (16u)
#define CHANNEL_2_RULE_POS              (8u)
#define MAX_RULE_PER_PAGE               (16u)
#define TOTAL_PAGE                      (64)
#define IDE_POS                         (31)

#define ON_MSG_INTC                     (0x00001000)
#define RX_FIFO_DEPTH                   (0x00000700)
#define RX_FIFO_INT_EN                  (0x00000002)
#define RX_FIFO_EN                      (0x00000001)
#define TXRX_FIFO_FULL                  (0x02)

#define TXRX_FIFO_SEL_POS                 (8)
#define TXRX_FIFO_DEPTH                   (0x00600000)
#define RECEIVE_MODE                      (0x00000000)
#define TRANSMIT_MODE                     (0x00000100)
#define TXRXFIFO_PAYLOAD_SIZE             (0x00000070)
#define TXRX_TRANSMIT_INT_EN              (0x04)
#define TXRX_RECEIVE_INT_EN               (0x02)
#define TXRX_FIFO_EN                      (0x01)
#define TXRXFIFO_EMPTY_MASK               (0x00000001)
#define TXRXFIFO_RX_INT_MASK              (0x00000008)
#define TXRXFIFO_TX_INT_MASK              (0x00000010)
#define TXRXFIFO_IDE_MASK                 (0x80000000)  
#define TXRXFIFO_RTR_MASK                 (0x40000000)  
#define EXTENDED_ID_MASK                  (0x1FFFFFFF) 
#define STD_IDE                           (0x00000000)
#define EXT_IDE                           (0x80000000)
#define STANDARD_ID_MASK                  (0x7FF)       
#define DLC_MASK                          (0xF0000000)    
#define DLC_POS                           (28)      
#define CANFD_FRAME                    (0x06)  
#define CAN_FRAME_MASK                  (0x04)
#define TXRXFIFO_CHNL_0     0
#define TXRXFIFO_CHNL_1     3
#define TXRXFIFO_CHNL_2     6

#define DLC_DATA_12            (9U)
#define DLC_DATA_16            (10U)
#define DLC_DATA_20            (11U)
#define DLC_DATA_24            (12U)
#define DLC_DATA_32            (13U)
#define DLC_DATA_48            (14U)
#define DLC_DATA_64            (15)

#define NO_OF_CHANNEL               3



/*******************************************************************************
 *  STRUCTURES, ENUMS and TYPEDEFS
 ******************************************************************************/
typedef struct {
    uint32_t BRP : 10;        // Bits 0-9: BRP[9:0]
    uint32_t reserved1 : 6;   // Bits 10-15: Reserved
    uint32_t TSEG1 : 4;       // Bits 16-19: TSEG1[3:0]
    uint32_t TSEG2 : 3;       // Bits 20-22: TSEG2[2:0]
    uint32_t reserved2 : 1;   // Bit  23: Reserved
    uint32_t SJW : 2;         // Bits 24-25: SJW[1:0]
    uint32_t reserved3 : 6;   // Bits 26-31: Reserved
} RSCAN0CmCfg_St_t;

// Define the Channel Control Register structure
typedef struct 
{
    uint32_t CHMDC : 2;       // Bits 0-1: CHMDC[1:0]
    uint32_t CSLPR : 1;       // Bit 2: CSLPR
    uint32_t RTBO : 1;        // Bit 3: RTBO
    uint32_t reserved1 : 4;   // Bits 4-7: Reserved
    uint32_t BEIE : 1;        // Bit 8: BEIE
    uint32_t EWIE : 1;        // Bit 9: EWIE
    uint32_t EPIE : 1;        // Bit 10: EPIE
    uint32_t BOEIE : 1;       // Bit 11: BOEIE
    uint32_t BORIE : 1;       // Bit 12: BORIE
    uint32_t OLIE : 1;        // Bit 13: OLIE
    uint32_t BLIE : 1;        // Bit 14: BLIE
    uint32_t ALIE : 1;        // Bit 15: ALIE
    uint32_t TAIE : 1;        // Bit 16: TAIE
    uint32_t reserved2 : 4;   // Bit 17-20: Reserved
    uint32_t BOM : 2;         // Bits 21-22: BOM[1:0]
    uint32_t ERRD : 1;        // Bit 23: ERRD
    uint32_t CTME : 1;        // Bit 24: CTME
    uint32_t CTMS : 2;        // Bits 25-26: CTMS[1:0]
    uint32_t reserved3 : 4;   // Bits 27-31: Reserved
}RSCAN0CmCTR_St_t;

// Define the structure for the RSCAN0CmSTS — Channel Status Register
typedef struct {
    uint32_t CRSTSTS : 1;       // Bit 0: CRSTS
    uint32_t CHLTSTS : 1;     // Bit 1: CHLTSTS
    uint32_t CSLPSTS : 1;     // Bit 2: CSLPSTS
    uint32_t EPSTS : 1;       // Bit 3: EPSTS
    uint32_t BOSTS : 1;       // Bit 4: BOSTS
    uint32_t TRMSTS : 1;      // Bit 5: TRMSTS
    uint32_t RECSTS : 1;      // Bit 6: RECSTS
    uint32_t COMSTS : 1;      // Bit 7: COMSTS
    uint32_t reserved : 16;   // Bits 8-23: Reserved
    uint32_t TEC : 8;         // Bits 24-31: REC[7:0]
} RSCAN0CmSTS_St_t;

// Define the strcuture for the RSCAN0CmERFL - Channel Error Flag Register
typedef struct {
    uint32_t BEF : 1;         // Bit 0: BEF
    uint32_t EWF : 1;         // Bit 1: EWF
    uint32_t EPF : 1;         // Bit 2: EPF
    uint32_t BOEF : 1;        // Bit 3: BOEF
    uint32_t BORF : 1;        // Bit 4: BORF
    uint32_t OVLF : 1;        // Bit 5: OVLF
    uint32_t BLF : 1;         // Bit 6: BLF
    uint32_t ALF : 1;         // Bit 7: ALF
    uint32_t SERR : 1;        // Bit 8: SERR
    uint32_t FERR : 1;        // Bit 9: FERR
    uint32_t AERR : 1;        // Bit 10: AERR
    uint32_t CERR : 1;        // Bit 11: CERR
    uint32_t B1ERR : 1;       // Bit 12: B1ERR
    uint32_t BOERR : 1;       // Bit 13: BOERR
    uint32_t ADERR : 1;       // Bit 14: ADERR
    uint32_t reserved : 1;    // Bit 15: Reserved
    uint32_t CRCREG : 15;     // Bits 16-30: CRCREG[14:0]
    uint32_t reserved2 : 1;   // Bit 31: Reserved
} RSCAN0CmERFL_St_t;

typedef struct 
{
    RSCAN0CmCfg_St_t CmCfg;                          // Channel 0 configuration register
    RSCAN0CmCTR_St_t CmCTR;                          // Channel 0 control register
    RSCAN0CmSTS_St_t CmSTS;                          // Channel 0 status register
    RSCAN0CmERFL_St_t CmERFL;                        // Channel 0 error flag register
}RSCANChnlReg_St_t;



typedef struct
{          
    RSCANChnlReg_St_t ChnlReg[NO_OF_CHANNEL];                           // 0x0000  //

} RSCANReg_St_t;
/*******************************************************************************
 *  EXTERN GLOBAL VARIABLES
 ******************************************************************************/

/*******************************************************************************
 *  EXTERN FUNCTION
 ******************************************************************************/

#endif
/*---------------------- End of File -----------------------------------------*/