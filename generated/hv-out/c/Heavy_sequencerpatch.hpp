/**
 * Copyright (c) 2025 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_CONTEXT_SEQUENCERPATCH_HPP_
#define _HEAVY_CONTEXT_SEQUENCERPATCH_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlDelay.h"
#include "HvControlSystem.h"
#include "HvControlUnop.h"
#include "HvControlIf.h"
#include "HvControlRandom.h"
#include "HvControlCast.h"
#include "HvControlSlice.h"
#include "HvControlPrint.h"
#include "HvControlTabwrite.h"
#include "HvTable.h"
#include "HvControlPack.h"
#include "HvControlTabread.h"

class Heavy_sequencerpatch : public HeavyContext {

 public:
  Heavy_sequencerpatch(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_sequencerpatch();

  const char *getName() override { return "sequencerpatch"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 0; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    
    struct Out {
      enum ParameterOut : hv_uint32_t {
        TBD_STEPLED = 0xBD7A3EC7, // tbd_stepled
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void hTable_DUXj3mZE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3cEXG27M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RfYGqXNN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zRhnZ16D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4dsh7jPl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BExx3yss_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_j0cV1UXh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wN38R6Uq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UF4Z3OwX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_dcDs1y6P_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_FdGEYerN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AWMDQGYt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tPrqrT5y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_YEBmUXMw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RI6vQiV3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rpXzzqBy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1iNwBwen_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cydATUz1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7OUJVduB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_7kMWfWaM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ounG9rFD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_wW2q80yi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_kWMtTCwr_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_oKGaHzIs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wvr11JcD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_PW1BYOc8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s5vUus4p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5VSI43RZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AQPdbbmd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yfbckX7o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UmYgm4b1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HsnzdXkq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_NxbATsPu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_qW5Ydl3V_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_rjxu3LRI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ONXD3O6D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_eutq3JpE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VTOq6b8g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_M27APepf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UkO2mkO6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MyZgkvRD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BPIJ0WsW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TYuAynCc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_fl6YyXfg_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_Gp3bpkeA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_lptfG7AB_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_wueYclJX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LedrMRQj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_QERp0jOo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_8oMmgDtk_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_EIOMDYvT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CR98CV1b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_YsnQra7s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AoPi11AT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zmDFC647_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_NDpUDEoO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lsBBBgJU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HyNtaehH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_27q8I9n1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabwrite_1CdhkbDF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_GI6IB7cD_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_y673xJIz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OW5RCTWX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VRHaXSsp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DSBLPJ7w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4rEapjcl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eeCt1ONy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_74JtTSOA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_K3Rsywc4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_fMtw4vxY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_vIO9m9zp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_tNUxlnp9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wBgeAtn1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mHGhff8c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_d971BGMQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sH2mZem0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qu5RC3h6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0vAeAviJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_fBRA5Jy4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_nXnA4ARe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_w6abR7Ip_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NyPGJBxA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_xlBTPoP3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_BvlgPEX5_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_264zEPzE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1eLeBMuS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_n2D0jMXf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Qi3wLctX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OuEmkAxe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TsTanp6v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_z0MGGPBw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Kgx3HWDX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TMraofc3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabwrite_kwTMpqC0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_cO3pOKi7_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_Oei9Y0u7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_46uSoExZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_gNGHsTuK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gk4MLHQQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_aQ5W9K9q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yingzrOj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EBdC9CbN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mooNxPGp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gzeScVHh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gkb6koTn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6fuL3Fcy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lbN9v7sE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wtTDkqaC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_jI78vJ3E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_kd5W01x9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_dMJnaqQb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sngr9xXS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hB6dowKz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XHJrcd84_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_jF4SuAP3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_IA1geQd8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_qhZDDTlo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OkxbTFh5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RfD62aBc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_af14kes0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Z0o35TTd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_DOZY7jkE_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_rxiDJwB6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_3TG2OVle_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_OBVGIYnd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_cxoIMkUk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_OCUasfws_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iEpF9j3o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZLHuqEDY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FM3Gjc47_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5ei5kwrk_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_lfTjFrNf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fVp14ELd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_k2bbKQza_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LRmEDoK4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qrFQvbRC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_aIRJ9hwX_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_DJuuta9e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VK4XK902_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3SzWFamz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_XZlxWwdh_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_idYfJ41q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ELwPynaJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ExuLPzTf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VOhE4acI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4lgq5u2j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ao5EnNgQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DPtjTzgO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_L1khIpqR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0WFgZSvn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fdpksQST_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ypEyvvM6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Op6xm2Wm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_42PlXIXz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zDxUirdj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nnrQG5p6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Wca6pgpz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BogKASbf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WDcD8yM3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3XEaKc1T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mFeT9zef_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0EKHsBCb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_sLOEIuZA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xWKO0KlU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tmJvDRfw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yUdO8mlI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xqua0Sq9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bNcV5l8d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tPRoA4tJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_l7tExUeb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WFnD8xhr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cPBVNXsl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xk10Mt4Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_T6o1zPcD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_i9lZwnJg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RV3Csb6o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wuHx8P0N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fLJSygvJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kJvGT7jl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_y2JWIU7w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XYJEzB1F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_F6i5e6mr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lZF3SBDe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wa2sXbGL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vK9xmCZ5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Q4G9PhlL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OrHotxW9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nHqxC6Kx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JXAtbUJj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jQvANoAX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_R9aIf0F2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EZwMYwAA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3NXZLTIj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZyGOovmH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1tVUZE7P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jQpakoIU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_C7RFKZ8C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s3524mGp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_kFkwI0zs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_CAp0Ao7t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_9jDJmgTH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_8T7T8pqW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_P25SzKYk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MJWWIOUt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pWJ3IK1t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9KBvIZMx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_rjIgxU8k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RUYI5t9S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MFr6DJ3O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_9wia7Lzm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_vbto4MLR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_zcagQBBE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_E90LEi3R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_PxpwnlNn_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  HvTable hTable_DUXj3mZE;
  ControlVar cVar_3cEXG27M;
  ControlVar cVar_RfYGqXNN;
  ControlVar cVar_zRhnZ16D;
  ControlVar cVar_j0cV1UXh;
  ControlBinop cBinop_wN38R6Uq;
  ControlVar cVar_UF4Z3OwX;
  ControlDelay cDelay_FdGEYerN;
  ControlVar cVar_RI6vQiV3;
  ControlBinop cBinop_1iNwBwen;
  ControlBinop cBinop_cydATUz1;
  ControlBinop cBinop_7OUJVduB;
  HvTable hTable_7kMWfWaM;
  ControlVar cVar_ounG9rFD;
  ControlTabread cTabread_wW2q80yi;
  ControlSlice cSlice_oKGaHzIs;
  ControlVar cVar_wvr11JcD;
  ControlBinop cBinop_s5vUus4p;
  ControlBinop cBinop_yfbckX7o;
  ControlBinop cBinop_HsnzdXkq;
  ControlTabread cTabread_NxbATsPu;
  ControlSlice cSlice_rjxu3LRI;
  ControlVar cVar_ONXD3O6D;
  ControlBinop cBinop_VTOq6b8g;
  ControlBinop cBinop_MyZgkvRD;
  ControlBinop cBinop_TYuAynCc;
  ControlSlice cSlice_Gp3bpkeA;
  ControlSlice cSlice_wueYclJX;
  ControlVar cVar_LedrMRQj;
  ControlTabread cTabread_QERp0jOo;
  ControlSlice cSlice_EIOMDYvT;
  ControlVar cVar_CR98CV1b;
  ControlBinop cBinop_AoPi11AT;
  ControlBinop cBinop_lsBBBgJU;
  ControlBinop cBinop_27q8I9n1;
  ControlTabwrite cTabwrite_1CdhkbDF;
  ControlSlice cSlice_y673xJIz;
  ControlVar cVar_OW5RCTWX;
  ControlVar cVar_VRHaXSsp;
  ControlVar cVar_DSBLPJ7w;
  ControlVar cVar_eeCt1ONy;
  ControlVar cVar_74JtTSOA;
  ControlVar cVar_K3Rsywc4;
  ControlIf cIf_tNUxlnp9;
  ControlBinop cBinop_wBgeAtn1;
  ControlVar cVar_mHGhff8c;
  ControlVar cVar_d971BGMQ;
  ControlVar cVar_sH2mZem0;
  ControlVar cVar_0vAeAviJ;
  ControlIf cIf_w6abR7Ip;
  ControlBinop cBinop_NyPGJBxA;
  ControlTabread cTabread_xlBTPoP3;
  ControlSlice cSlice_264zEPzE;
  ControlVar cVar_1eLeBMuS;
  ControlBinop cBinop_Qi3wLctX;
  ControlBinop cBinop_z0MGGPBw;
  ControlBinop cBinop_TMraofc3;
  ControlTabwrite cTabwrite_kwTMpqC0;
  ControlSlice cSlice_Oei9Y0u7;
  ControlVar cVar_46uSoExZ;
  ControlPack cPack_gNGHsTuK;
  ControlVar cVar_gk4MLHQQ;
  ControlBinop cBinop_yingzrOj;
  ControlBinop cBinop_EBdC9CbN;
  ControlVar cVar_gzeScVHh;
  ControlVar cVar_gkb6koTn;
  ControlVar cVar_6fuL3Fcy;
  ControlVar cVar_wtTDkqaC;
  ControlIf cIf_dMJnaqQb;
  ControlBinop cBinop_sngr9xXS;
  ControlVar cVar_hB6dowKz;
  ControlVar cVar_XHJrcd84;
  ControlPack cPack_jF4SuAP3;
  ControlVar cVar_IA1geQd8;
  ControlBinop cBinop_OkxbTFh5;
  ControlBinop cBinop_RfD62aBc;
  ControlVar cVar_Z0o35TTd;
  ControlBinop cBinop_rxiDJwB6;
  ControlRandom cRandom_OBVGIYnd;
  ControlSlice cSlice_cxoIMkUk;
  ControlIf cIf_OCUasfws;
  ControlBinop cBinop_iEpF9j3o;
  ControlVar cVar_FM3Gjc47;
  ControlDelay cDelay_lfTjFrNf;
  ControlVar cVar_LRmEDoK4;
  ControlVar cVar_qrFQvbRC;
  ControlDelay cDelay_DJuuta9e;
  ControlSlice cSlice_idYfJ41q;
  ControlSlice cSlice_ELwPynaJ;
  ControlSlice cSlice_ExuLPzTf;
  ControlBinop cBinop_VOhE4acI;
  ControlBinop cBinop_42PlXIXz;
  ControlBinop cBinop_zDxUirdj;
  ControlBinop cBinop_nnrQG5p6;
  ControlBinop cBinop_Wca6pgpz;
  ControlBinop cBinop_BogKASbf;
  ControlBinop cBinop_WDcD8yM3;
  ControlBinop cBinop_WFnD8xhr;
  ControlBinop cBinop_cPBVNXsl;
  ControlBinop cBinop_xk10Mt4Y;
  ControlBinop cBinop_MJWWIOUt;
  ControlBinop cBinop_pWJ3IK1t;
  ControlBinop cBinop_9KBvIZMx;
};

#endif // _HEAVY_CONTEXT_SEQUENCERPATCH_HPP_
