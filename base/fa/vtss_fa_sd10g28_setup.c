#ifndef _VTSS_ANT__API_SD10G28_UTE
#define _VTSS_ANT__API_SD10G28_UTE

/*
Copyright (c) 2004-2019 Microsemi Corporation "Microsemi".

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/* Generation Tag is temp */

/* ================================================================= *
 *               Note: This code is autogenerated from the
 *                     Universal Tcl Environment (UTE) which provides
 *                     consistent setup functions for
 *       ^             - Verification
 *      / \            - Validation
 *     /   \           - Test Pattern Generation and
 *    /  |  \          - Software
 *   /   !   \         It should not be modified manually.
 *  /_________\        In case there is a need for modifications,
 *                     please contact
 *                       Srinivas Bandari <srinivas.bandari@microchip.com> 
 * ================================================================= */

#include <vtss/api/options.h>  // To get the ARCH define
#if defined(VTSS_ARCH_SPARX5)
#include "vtss_fa_inc.h"


vtss_rc  vtss_ant_sd10g28_cmu_reg_cfg(vtss_state_t *vtss_state, u32 cmu_num) {
    vtss_rc rc = VTSS_RC_OK;
    u32 value;
	u32 cmu_tgt = VTSS_TO_SD_CMU(cmu_num);
	u32 cmu_cfg_tgt = VTSS_TO_SD_CMU_CFG(cmu_num);
    u32 spd10g = 1;

    if (cmu_num == 1 || cmu_num == 4 || cmu_num == 7 || cmu_num == 10 || cmu_num == 13) {
        spd10g = 0;
    }

    REG_WRM(VTSS_SD_CMU_TERM_TARGET_SD_CMU_CFG(cmu_cfg_tgt),
                VTSS_F_SD_CMU_TERM_TARGET_SD_CMU_CFG_EXT_CFG_RST(1),
                VTSS_M_SD_CMU_TERM_TARGET_SD_CMU_CFG_EXT_CFG_RST);

    REG_WRM(VTSS_SD_CMU_TERM_TARGET_SD_CMU_CFG(cmu_cfg_tgt),
                VTSS_F_SD_CMU_TERM_TARGET_SD_CMU_CFG_EXT_CFG_RST(0),
                VTSS_M_SD_CMU_TERM_TARGET_SD_CMU_CFG_EXT_CFG_RST);

    REG_WRM(VTSS_SD_CMU_TERM_TARGET_SD_CMU_CFG(cmu_cfg_tgt),
                VTSS_F_SD_CMU_TERM_TARGET_SD_CMU_CFG_CMU_RST(1),
                VTSS_M_SD_CMU_TERM_TARGET_SD_CMU_CFG_CMU_RST);

    REG_WRM(VTSS_SD10G_CMU_TARGET_CMU_45(cmu_tgt),
                VTSS_F_SD10G_CMU_TARGET_CMU_45_R_DWIDTHCTRL_FROM_HWT(0x1) |
        VTSS_F_SD10G_CMU_TARGET_CMU_45_R_REFCK_SSC_EN_FROM_HWT(0x1) |
        VTSS_F_SD10G_CMU_TARGET_CMU_45_R_LINK_BUF_EN_FROM_HWT(0x1) |
        VTSS_F_SD10G_CMU_TARGET_CMU_45_R_BIAS_EN_FROM_HWT(0x1) |
        VTSS_F_SD10G_CMU_TARGET_CMU_45_R_EN_RATECHG_CTRL(0x0),
                VTSS_M_SD10G_CMU_TARGET_CMU_45_R_DWIDTHCTRL_FROM_HWT |
        VTSS_M_SD10G_CMU_TARGET_CMU_45_R_REFCK_SSC_EN_FROM_HWT |
        VTSS_M_SD10G_CMU_TARGET_CMU_45_R_LINK_BUF_EN_FROM_HWT |
        VTSS_M_SD10G_CMU_TARGET_CMU_45_R_BIAS_EN_FROM_HWT |
        VTSS_M_SD10G_CMU_TARGET_CMU_45_R_EN_RATECHG_CTRL);

    REG_WRM(VTSS_SD10G_CMU_TARGET_CMU_47(cmu_tgt),
                VTSS_F_SD10G_CMU_TARGET_CMU_47_R_PCS2PMA_PHYMODE_4_0(0),
                VTSS_M_SD10G_CMU_TARGET_CMU_47_R_PCS2PMA_PHYMODE_4_0);

    REG_WRM(VTSS_SD10G_CMU_TARGET_CMU_1B(cmu_tgt),
                VTSS_F_SD10G_CMU_TARGET_CMU_1B_CFG_RESERVE_7_0(0),
                VTSS_M_SD10G_CMU_TARGET_CMU_1B_CFG_RESERVE_7_0);

    REG_WRM(VTSS_SD10G_CMU_TARGET_CMU_0D(cmu_tgt),
                VTSS_F_SD10G_CMU_TARGET_CMU_0D_CFG_JC_BYP(0x1),
                VTSS_M_SD10G_CMU_TARGET_CMU_0D_CFG_JC_BYP);

    REG_WRM(VTSS_SD10G_CMU_TARGET_CMU_1F(cmu_tgt),
                VTSS_F_SD10G_CMU_TARGET_CMU_1F_CFG_VTUNE_SEL(1),
                VTSS_M_SD10G_CMU_TARGET_CMU_1F_CFG_VTUNE_SEL);

    REG_WRM(VTSS_SD10G_CMU_TARGET_CMU_00(cmu_tgt),
                VTSS_F_SD10G_CMU_TARGET_CMU_00_CFG_PLL_TP_SEL_1_0(3),
                VTSS_M_SD10G_CMU_TARGET_CMU_00_CFG_PLL_TP_SEL_1_0);

    REG_WRM(VTSS_SD10G_CMU_TARGET_CMU_05(cmu_tgt),
                VTSS_F_SD10G_CMU_TARGET_CMU_05_CFG_BIAS_TP_SEL_1_0(3),
                VTSS_M_SD10G_CMU_TARGET_CMU_05_CFG_BIAS_TP_SEL_1_0);

    REG_WRM(VTSS_SD10G_CMU_TARGET_CMU_30(cmu_tgt),
                VTSS_F_SD10G_CMU_TARGET_CMU_30_R_PLL_DLOL_EN(1),
                VTSS_M_SD10G_CMU_TARGET_CMU_30_R_PLL_DLOL_EN);

    REG_WRM(VTSS_SD10G_CMU_TARGET_CMU_09(cmu_tgt),
                VTSS_F_SD10G_CMU_TARGET_CMU_09_CFG_SW_10G(spd10g),
                VTSS_M_SD10G_CMU_TARGET_CMU_09_CFG_SW_10G);

    REG_WRM(VTSS_SD_CMU_TERM_TARGET_SD_CMU_CFG(cmu_cfg_tgt),
                VTSS_F_SD_CMU_TERM_TARGET_SD_CMU_CFG_CMU_RST(0),
                VTSS_M_SD_CMU_TERM_TARGET_SD_CMU_CFG_CMU_RST);

    VTSS_MSLEEP(20);

    REG_WRM(VTSS_SD10G_CMU_TARGET_CMU_44(cmu_tgt),
                VTSS_F_SD10G_CMU_TARGET_CMU_44_R_PLL_RSTN(0),
                VTSS_M_SD10G_CMU_TARGET_CMU_44_R_PLL_RSTN);

    REG_WRM(VTSS_SD10G_CMU_TARGET_CMU_44(cmu_tgt),
                VTSS_F_SD10G_CMU_TARGET_CMU_44_R_PLL_RSTN(1),
                VTSS_M_SD10G_CMU_TARGET_CMU_44_R_PLL_RSTN);

    VTSS_MSLEEP(20);

    REG_RD(VTSS_SD10G_CMU_TARGET_CMU_E0(cmu_tgt), &value);
    value = VTSS_X_SD10G_CMU_TARGET_CMU_E0_PLL_LOL_UDL(value);
    value = (value > 0) ? 1 : 0;
    if(value != 0x0) {
        VTSS_E("CMU:%d The expected value for CMU_E0 pll_lol_udl was 0x0 but is 0x%x\n",cmu_num, value);
        rc = VTSS_RC_ERROR;
    } else {
        VTSS_D("Note: The value of CMU_E0 pll_lol_udl was 0x%x\n", value);
    }

    REG_WRM(VTSS_SD10G_CMU_TARGET_CMU_0D(cmu_tgt),
                VTSS_F_SD10G_CMU_TARGET_CMU_0D_CFG_PMA_TX_CK_PD(0),
                VTSS_M_SD10G_CMU_TARGET_CMU_0D_CFG_PMA_TX_CK_PD);


  return rc;
}

static vtss_rc  vtss_ant_sd10g28_reg_cfg(vtss_state_t *vtss_state, vtss_sd10g28_setup_struct_t *const res_struct, vtss_port_no_t port_no) {
    vtss_rc rc = VTSS_RC_OK;
    u32 value;
    u32 sd_lane_tgt;
    u32 sd_tgt;
   // u32 cmu_num;

/*    cmu_num=vtss_fa_sd10g28_get_cmu(vtss_state, res_struct->cmu_sel[0],port_no);*/
/*    vtss_ant_sd10g28_cmu_reg_cfg(vtss_state, cmu_num);*/

    u32 indx = vtss_fa_port2sd_indx(vtss_state, port_no);
    if(res_struct->is_6g[0] == 1) {
        sd_tgt = VTSS_TO_SD6G_LANE(indx);
        sd_lane_tgt = VTSS_TO_SD_LANE(indx);
    } else {
        sd_tgt = VTSS_TO_SD10G_LANE(indx);
        sd_lane_tgt = VTSS_TO_SD_LANE(indx+VTSS_SERDES_10G_START);
    } 

/* Note: SerDes SD10G_LANE_1 is configured in 10G_LAN mode */
    REG_WRM(VTSS_SD_LANE_TARGET_SD_LANE_CFG(sd_lane_tgt),
                VTSS_F_SD_LANE_TARGET_SD_LANE_CFG_EXT_CFG_RST(1),
                VTSS_M_SD_LANE_TARGET_SD_LANE_CFG_EXT_CFG_RST);

    VTSS_MSLEEP(1);

    REG_WRM(VTSS_SD_LANE_TARGET_SD_LANE_CFG(sd_lane_tgt),
                VTSS_F_SD_LANE_TARGET_SD_LANE_CFG_EXT_CFG_RST(0),
                VTSS_M_SD_LANE_TARGET_SD_LANE_CFG_EXT_CFG_RST);

    REG_WRM(VTSS_SD_LANE_TARGET_SD_LANE_CFG(sd_lane_tgt),
                VTSS_F_SD_LANE_TARGET_SD_LANE_CFG_MACRO_RST(1),
                VTSS_M_SD_LANE_TARGET_SD_LANE_CFG_MACRO_RST);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_93(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_93_R_DWIDTHCTRL_FROM_HWT(0x0) |
        VTSS_F_SD10G_LANE_TARGET_LANE_93_R_REG_MANUAL(0x1) |
        VTSS_F_SD10G_LANE_TARGET_LANE_93_R_AUXCKSEL_FROM_HWT(0x1) |
        VTSS_F_SD10G_LANE_TARGET_LANE_93_R_LANE_ID_FROM_HWT(0x1) |
        VTSS_F_SD10G_LANE_TARGET_LANE_93_R_EN_RATECHG_CTRL(0x0),
                VTSS_M_SD10G_LANE_TARGET_LANE_93_R_DWIDTHCTRL_FROM_HWT |
        VTSS_M_SD10G_LANE_TARGET_LANE_93_R_REG_MANUAL |
        VTSS_M_SD10G_LANE_TARGET_LANE_93_R_AUXCKSEL_FROM_HWT |
        VTSS_M_SD10G_LANE_TARGET_LANE_93_R_LANE_ID_FROM_HWT |
        VTSS_M_SD10G_LANE_TARGET_LANE_93_R_EN_RATECHG_CTRL);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_94(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_94_R_ISCAN_REG(0x1) |
        VTSS_F_SD10G_LANE_TARGET_LANE_94_R_TXEQ_REG(0x1) |
        VTSS_F_SD10G_LANE_TARGET_LANE_94_R_MISC_REG(0x1) |
        VTSS_F_SD10G_LANE_TARGET_LANE_94_R_SWING_REG(0x1),
                VTSS_M_SD10G_LANE_TARGET_LANE_94_R_ISCAN_REG |
        VTSS_M_SD10G_LANE_TARGET_LANE_94_R_TXEQ_REG |
        VTSS_M_SD10G_LANE_TARGET_LANE_94_R_MISC_REG |
        VTSS_M_SD10G_LANE_TARGET_LANE_94_R_SWING_REG);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_9E(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_9E_R_RXEQ_REG(0x1),
                VTSS_M_SD10G_LANE_TARGET_LANE_9E_R_RXEQ_REG);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_A1(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_A1_R_SSC_FROM_HWT(0x0) |
        VTSS_F_SD10G_LANE_TARGET_LANE_A1_R_CDR_FROM_HWT(0x0) |
        VTSS_F_SD10G_LANE_TARGET_LANE_A1_R_PCLK_GATING_FROM_HWT(0x1),
                VTSS_M_SD10G_LANE_TARGET_LANE_A1_R_SSC_FROM_HWT |
        VTSS_M_SD10G_LANE_TARGET_LANE_A1_R_CDR_FROM_HWT |
        VTSS_M_SD10G_LANE_TARGET_LANE_A1_R_PCLK_GATING_FROM_HWT);

    REG_WRM(VTSS_SD_LANE_TARGET_SD_LANE_CFG(sd_lane_tgt),
                VTSS_F_SD_LANE_TARGET_SD_LANE_CFG_RX_REF_SEL(res_struct->cmu_sel[0]) |
        VTSS_F_SD_LANE_TARGET_SD_LANE_CFG_TX_REF_SEL(res_struct->cmu_sel[0]),
                VTSS_M_SD_LANE_TARGET_SD_LANE_CFG_RX_REF_SEL |
        VTSS_M_SD_LANE_TARGET_SD_LANE_CFG_TX_REF_SEL);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_40(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_40_CFG_LANE_RESERVE_7_0(res_struct->cfg_lane_reserve_7_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_40_CFG_LANE_RESERVE_7_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_50(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_50_CFG_SSC_RTL_CLK_SEL(res_struct->cfg_ssc_rtl_clk_sel[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_50_CFG_SSC_RTL_CLK_SEL);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_35(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_35_CFG_TXRATE_1_0(res_struct->cfg_txrate_1_0[0]) |
        VTSS_F_SD10G_LANE_TARGET_LANE_35_CFG_RXRATE_1_0(res_struct->cfg_rxrate_1_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_35_CFG_TXRATE_1_0 |
        VTSS_M_SD10G_LANE_TARGET_LANE_35_CFG_RXRATE_1_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_94(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_94_R_DWIDTHCTRL_2_0(res_struct->r_DwidthCtrl_2_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_94_R_DWIDTHCTRL_2_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_01(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_01_CFG_PMA_TX_CK_BITWIDTH_2_0(res_struct->cfg_pma_tx_ck_bitwidth_2_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_01_CFG_PMA_TX_CK_BITWIDTH_2_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_30(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_30_CFG_RXDIV_SEL_2_0(res_struct->cfg_rxdiv_sel_2_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_30_CFG_RXDIV_SEL_2_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_A2(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_A2_R_PCS2PMA_PHYMODE_4_0(res_struct->r_pcs2pma_phymode_4_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_A2_R_PCS2PMA_PHYMODE_4_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_13(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_13_CFG_CDRCK_EN(res_struct->cfg_cdrck_en[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_13_CFG_CDRCK_EN);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_23(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_23_CFG_DFECK_EN(res_struct->cfg_dfeck_en[0]) |
        VTSS_F_SD10G_LANE_TARGET_LANE_23_CFG_DFE_PD(res_struct->cfg_dfe_pd[0]) |
        VTSS_F_SD10G_LANE_TARGET_LANE_23_CFG_ERRAMP_PD(res_struct->cfg_erramp_pd[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_23_CFG_DFECK_EN |
        VTSS_M_SD10G_LANE_TARGET_LANE_23_CFG_DFE_PD |
        VTSS_M_SD10G_LANE_TARGET_LANE_23_CFG_ERRAMP_PD);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_22(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_22_CFG_DFETAP_EN_5_1(res_struct->cfg_dfetap_en_5_1[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_22_CFG_DFETAP_EN_5_1);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_1A(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_1A_CFG_PI_DFE_EN(res_struct->cfg_pi_DFE_en[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_1A_CFG_PI_DFE_EN);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_02(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_02_CFG_EN_ADV(res_struct->cfg_en_adv[0]) |
        VTSS_F_SD10G_LANE_TARGET_LANE_02_CFG_EN_MAIN(res_struct->cfg_en_main[0]) |
        VTSS_F_SD10G_LANE_TARGET_LANE_02_CFG_EN_DLY(res_struct->cfg_en_dly[0]) |
        VTSS_F_SD10G_LANE_TARGET_LANE_02_CFG_TAP_ADV_3_0(res_struct->cfg_tap_adv_3_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_02_CFG_EN_ADV |
        VTSS_M_SD10G_LANE_TARGET_LANE_02_CFG_EN_MAIN |
        VTSS_M_SD10G_LANE_TARGET_LANE_02_CFG_EN_DLY |
        VTSS_M_SD10G_LANE_TARGET_LANE_02_CFG_TAP_ADV_3_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_03(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_03_CFG_TAP_MAIN(res_struct->cfg_tap_main[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_03_CFG_TAP_MAIN);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_04(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_04_CFG_TAP_DLY_4_0(res_struct->cfg_tap_dly_4_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_04_CFG_TAP_DLY_4_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_2F(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_2F_CFG_VGA_CTRL_3_0(res_struct->cfg_vga_ctrl_3_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_2F_CFG_VGA_CTRL_3_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_2F(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_2F_CFG_VGA_CP_2_0(res_struct->cfg_vga_cp_2_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_2F_CFG_VGA_CP_2_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_0B(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_0B_CFG_EQ_RES_3_0(res_struct->cfg_eq_res_3_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_0B_CFG_EQ_RES_3_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_0D(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_0D_CFG_EQR_BYP(res_struct->cfg_eqR_byp[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_0D_CFG_EQR_BYP);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_0E(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_0E_CFG_EQC_FORCE_3_0(res_struct->cfg_eqC_force_3_0[0]) |
        VTSS_F_SD10G_LANE_TARGET_LANE_0E_CFG_SUM_SETCM_EN(res_struct->cfg_sum_setcm_en[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_0E_CFG_EQC_FORCE_3_0 |
        VTSS_M_SD10G_LANE_TARGET_LANE_0E_CFG_SUM_SETCM_EN);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_23(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_23_CFG_EN_DFEDIG(res_struct->cfg_en_dfedig[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_23_CFG_EN_DFEDIG);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_06(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_06_CFG_EN_PREEMPH(res_struct->cfg_en_preemph[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_06_CFG_EN_PREEMPH);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_33(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_33_CFG_ITX_IPPREEMP_BASE_1_0(res_struct->cfg_itx_ippreemp_base_1_0[0]) |
        VTSS_F_SD10G_LANE_TARGET_LANE_33_CFG_ITX_IPDRIVER_BASE_2_0(res_struct->cfg_itx_ipdriver_base_2_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_33_CFG_ITX_IPPREEMP_BASE_1_0 |
        VTSS_M_SD10G_LANE_TARGET_LANE_33_CFG_ITX_IPDRIVER_BASE_2_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_52(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_52_CFG_IBIAS_TUNE_RESERVE_5_0(res_struct->cfg_ibias_tune_reserve_5_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_52_CFG_IBIAS_TUNE_RESERVE_5_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_37(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_37_CFG_TXSWING_HALF(res_struct->cfg_txswing_half[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_37_CFG_TXSWING_HALF);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_3C(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_3C_CFG_DIS_2NDORDER(res_struct->cfg_dis_2ndOrder[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_3C_CFG_DIS_2NDORDER);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_39(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_39_CFG_RX_SSC_LH(res_struct->cfg_rx_ssc_lh[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_39_CFG_RX_SSC_LH);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_1A(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_1A_CFG_PI_FLOOP_STEPS_1_0(res_struct->cfg_pi_floop_steps_1_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_1A_CFG_PI_FLOOP_STEPS_1_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_16(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_16_CFG_PI_EXT_DAC_23_16(res_struct->cfg_pi_ext_dac_23_16[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_16_CFG_PI_EXT_DAC_23_16);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_15(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_15_CFG_PI_EXT_DAC_15_8(res_struct->cfg_pi_ext_dac_15_8[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_15_CFG_PI_EXT_DAC_15_8);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_26(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_26_CFG_ISCAN_EXT_DAC_7_0(res_struct->cfg_iscan_ext_dac_7_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_26_CFG_ISCAN_EXT_DAC_7_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_42(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_42_CFG_CDR_KF_GEN1_2_0(res_struct->cfg_cdr_kf_gen1_2_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_42_CFG_CDR_KF_GEN1_2_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_0F(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_0F_R_CDR_M_GEN1_7_0(res_struct->r_cdr_m_gen1_7_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_0F_R_CDR_M_GEN1_7_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_24(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_24_CFG_PI_BW_GEN1_3_0(res_struct->cfg_pi_bw_gen1_3_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_24_CFG_PI_BW_GEN1_3_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_14(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_14_CFG_PI_EXT_DAC_7_0(res_struct->cfg_pi_ext_dac_7_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_14_CFG_PI_EXT_DAC_7_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_1A(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_1A_CFG_PI_STEPS(res_struct->cfg_pi_steps[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_1A_CFG_PI_STEPS);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_3A(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_3A_CFG_MP_MAX_3_0(res_struct->cfg_mp_max_3_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_3A_CFG_MP_MAX_3_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_31(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_31_CFG_RSTN_DFEDIG(res_struct->cfg_rstn_dfedig[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_31_CFG_RSTN_DFEDIG);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_48(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_48_CFG_ALOS_THR_3_0(res_struct->cfg_alos_thr_3_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_48_CFG_ALOS_THR_3_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_36(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_36_CFG_PREDRV_SLEWRATE_1_0(res_struct->cfg_predrv_slewrate_1_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_36_CFG_PREDRV_SLEWRATE_1_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_32(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_32_CFG_ITX_IPCML_BASE_1_0(res_struct->cfg_itx_ipcml_base_1_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_32_CFG_ITX_IPCML_BASE_1_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_37(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_37_CFG_IP_PRE_BASE_1_0(res_struct->cfg_ip_pre_base_1_0[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_37_CFG_IP_PRE_BASE_1_0);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_41(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_41_CFG_LANE_RESERVE_15_8(res_struct->cfg_lane_reserve_15_8[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_41_CFG_LANE_RESERVE_15_8);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_9E(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_9E_R_EN_AUTO_CDR_RSTN(res_struct->r_en_auto_cdr_rstn[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_9E_R_EN_AUTO_CDR_RSTN);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_0C(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_0C_CFG_OSCAL_AFE(res_struct->cfg_oscal_afe[0]) |
        VTSS_F_SD10G_LANE_TARGET_LANE_0C_CFG_PD_OSDAC_AFE(res_struct->cfg_pd_osdac_afe[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_0C_CFG_OSCAL_AFE |
        VTSS_M_SD10G_LANE_TARGET_LANE_0C_CFG_PD_OSDAC_AFE);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_0B(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_0B_CFG_RESETB_OSCAL_AFE(res_struct->cfg_resetb_oscal_afe[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_0B_CFG_RESETB_OSCAL_AFE);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_0B(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_0B_CFG_RESETB_OSCAL_AFE(res_struct->cfg_resetb_oscal_afe[1]),
                VTSS_M_SD10G_LANE_TARGET_LANE_0B_CFG_RESETB_OSCAL_AFE);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_83(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_83_R_TX_POL_INV(res_struct->r_tx_pol_inv[0]) |
        VTSS_F_SD10G_LANE_TARGET_LANE_83_R_RX_POL_INV(res_struct->r_rx_pol_inv[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_83_R_TX_POL_INV |
        VTSS_M_SD10G_LANE_TARGET_LANE_83_R_RX_POL_INV);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_06(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_06_CFG_RX2TX_LP_EN(res_struct->cfg_rx2tx_lp_en[0]) |
        VTSS_F_SD10G_LANE_TARGET_LANE_06_CFG_TX2RX_LP_EN(res_struct->cfg_tx2rx_lp_en[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_06_CFG_RX2TX_LP_EN |
        VTSS_M_SD10G_LANE_TARGET_LANE_06_CFG_TX2RX_LP_EN);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_0E(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_0E_CFG_RXLB_EN(res_struct->cfg_rxlb_en[0]) |
        VTSS_F_SD10G_LANE_TARGET_LANE_0E_CFG_TXLB_EN(res_struct->cfg_txlb_en[0]),
                VTSS_M_SD10G_LANE_TARGET_LANE_0E_CFG_RXLB_EN |
        VTSS_M_SD10G_LANE_TARGET_LANE_0E_CFG_TXLB_EN);

    REG_WRM(VTSS_SD_LANE_TARGET_SD_LANE_CFG(sd_lane_tgt),
                VTSS_F_SD_LANE_TARGET_SD_LANE_CFG_MACRO_RST(0),
                VTSS_M_SD_LANE_TARGET_SD_LANE_CFG_MACRO_RST);

    REG_WRM(VTSS_SD10G_LANE_TARGET_LANE_50(sd_tgt),
                VTSS_F_SD10G_LANE_TARGET_LANE_50_CFG_SSC_RESETB(1),
                VTSS_M_SD10G_LANE_TARGET_LANE_50_CFG_SSC_RESETB);

    VTSS_MSLEEP(3);

    REG_RD(VTSS_SD_LANE_TARGET_SD_LANE_STAT(sd_lane_tgt), &value);
    value = VTSS_X_SD_LANE_TARGET_SD_LANE_STAT_PMA_RST_DONE(value);
    value = (value > 0) ? 1 : 0;
    if(value != 0x1) {
        VTSS_E("The expected value for sd_lane_stat pma_rst_done was 0x1 but is 0x%x\n", value);
        rc = VTSS_RC_ERROR;
    } else {
        VTSS_D("Note: The value of sd_lane_stat pma_rst_done was 0x%x\n", value);
    }

    // Local fix until this is integrated into UTE
    REG_WRM(VTSS_SD_LANE_TARGET_SD_SER_RST(sd_lane_tgt),
            VTSS_F_SD_LANE_TARGET_SD_SER_RST_SER_RST(0),
            VTSS_M_SD_LANE_TARGET_SD_SER_RST_SER_RST);

    REG_WRM(VTSS_SD_LANE_TARGET_SD_DES_RST(sd_lane_tgt),
            VTSS_F_SD_LANE_TARGET_SD_DES_RST_DES_RST(0),
            VTSS_M_SD_LANE_TARGET_SD_DES_RST_DES_RST);

  return rc;
}

vtss_rc vtss_ant_sd10g28_setup_lane(vtss_state_t *vtss_state, const vtss_sd10g28_setup_args_t config, vtss_port_no_t port_no) {
    vtss_sd10g28_setup_struct_t calc_results;
    vtss_rc rc;
    VTSS_D("This function is generated with UTE based on TAG: temp");

    rc = vtss_calc_sd10g28_setup_lane(config, &calc_results);
    if(rc == VTSS_RC_OK) {
        rc |= vtss_ant_sd10g28_reg_cfg(vtss_state, &calc_results, port_no);
    }
    return rc;
}


#endif
#endif
