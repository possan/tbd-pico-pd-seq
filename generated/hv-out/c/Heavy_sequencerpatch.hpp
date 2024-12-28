/**
 * Copyright (c) 2024 Enzien Audio, Ltd.
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
#include "HvControlTabwrite.h"
#include "HvControlPrint.h"
#include "HvControlSystem.h"
#include "HvControlTabread.h"
#include "HvControlDelay.h"
#include "HvControlUnop.h"
#include "HvControlRandom.h"
#include "HvTable.h"
#include "HvControlVar.h"
#include "HvControlCast.h"
#include "HvControlIf.h"
#include "HvControlPack.h"
#include "HvControlSlice.h"
#include "HvControlBinop.h"

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
        __HV_NOTEOUT = 0xD1D4AC2, // __hv_noteout
        TBD_STEPLED = 0xBD7A3EC7, // tbd_stepled
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void hTable_KAgXbfUZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Y1EAI5L9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_z4E8XBpq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cf13GXeB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1A567NWJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lDdh0GE9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_51DKeBAv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eSm9spUm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_x0o53eWP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5zI4rziq_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_0DnIf5NE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iwlYdBbk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6HYtSiW6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_EUIM7TB0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nAuvmxEB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_O76OLNP4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vbbEi4Om_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_e0kByt6g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wWffeYmm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_p1NfyiQe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2e1wJviR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_nzOGcN2I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_KG3cjk54_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_fc4jptEf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ZoVXMn4m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_daclDU1j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0z3kv3yW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zbsJJW2h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xIkB96OI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yde2oXPP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wLbTaNUD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_77kZI6aS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_lL3RZCns_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_9LadpbHx_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_wAhxrrvV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FQui9nmg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_UeaXAR1L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Qq9dotkM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AojS3moi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jaE1oO9v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BNjJXV7v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_r6igu7Rb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TC1bR67k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_MYckSeDp_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_s9oZgM0N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Pt4ZTfdC_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_axn6Ec17_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FlYfEsMY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_Q29MVnGm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_thl3kLT0_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_9WAywOgi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RCpE21qm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_YQnvaTVb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4BNBX6Jo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_q1wgtlkH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9xJTRLhK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jFFje3jp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2kwWPYyL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BjyUSgAh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabwrite_pq4AEhYP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_HORH3duM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_76Kgx3D8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_tMQQ9NCj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OJr9PpBk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_crbF0t8G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZkC8ydW5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_SgWeKYcl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_e73Zh2j2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LLJIDDYh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_byrqmEAV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_4Y7AXecL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_DoJXr5mR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DswDo8PJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_z31PLJhl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XHYqQouM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gYGbW2Go_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JNT0QhHZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dbhCJN2v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_6NYS3ZuM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_F8MSXxnv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_qFqIZ0YL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2wQAp8Di_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_69zFVHNd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_XxEbqGSD_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_juHKZSSW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Vl3lIQOW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ghG5q3iL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9Nm2WJ1P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BPSd7kph_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gd22b4LO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2H7vvJtm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ynkeK3AJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_X31d94cR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabwrite_zCDf0Qnm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_tqEWSGIH_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_S8JqFPlR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Z2B0qLWD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_IAVWnAo2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_b1im11q1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_0x0xGUge_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JzH7ONAA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OtS02goQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5mI7uc9o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qDxMgu1L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KxplVWAW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_p3k38w8R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_d1yq5Ocn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bTMyXveo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_mjHQ7JKd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_iq7P9mUt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_sdU8jrMs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_snv21ihe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MbX4a2A4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_i6k0WNHT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_qM7wNEV5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_I6hyxGzG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_gsCaTdGD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dzvUnMMN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xvK0V63M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_v9ESTnvO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vtiaG2gV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_JUhfUBGc_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_FzWySGec_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_yZx4TeDJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_AK3up9D4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Ax5gyJiM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_CfkjHFbE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TV4wG2P0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7kSL5ewK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EYbX4a1I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_7ahFdDiE_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_OsrhtCTO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dljlZxfr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_H71yyoGa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JWDqwD6F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_W0FnRGtb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_N6zSqXOE_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_ffN7ZTAf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5MECTuYr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qDLA5ziO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_W3JGdpCO_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_UHyu3CwE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Gik5ke51_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_J7tcr8kL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HoMQwJwi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lhSs3Tq3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aNMr2VYl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zVwz2nFP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3HaB1LwI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QmkDStqq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4DNf1Inw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Q1u9uSlg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_S50OrFNp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EbKF8RXC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HwRtST9Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fLrqUo33_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YiKVkksC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rf6KVXzX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CYzElNH6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_m29cxGkl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SmiitqoM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GVwsyx6m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6AMGxNNX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FriJnX9F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_m5WIUOft_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_54KUQKNA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PStd28TH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Qx8ZHXKn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_isFm8U71_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ji6Oxh4q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KW3nZbzw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RH72URT6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rJBTqopo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ePQvNrtK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JzTd5ORp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8vwXF0Ez_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5CL0ILZJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wlOgQACe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fXeftjpu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_x5Jp07Na_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Olj0Kq9s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_u8okcW6G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RCUikuEp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XKVojtii_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KvIVFd2h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_INr1qfIr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bPgjpJv0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_st7a4re9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CoYbawf2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IpKM17dn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8TcE5Rgm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TbeQ06nD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_48ZeugVM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nNOLBgdm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fsHv7iDu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MyrkVVCW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_20EFYjw9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jLQZnpGV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3ESGQyyA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1Xqbpoq4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_0mQVDziJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_VW99fAuJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_GC4KiI3J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_eA8STs7c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_45DvGVyh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_O8EZKz7X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HYeSHC0r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hiv9a98S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_PxDvQD1D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_OGAOclV6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ZQQRGLmm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_JQ0iHymm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_oztHXV6N_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  HvTable hTable_KAgXbfUZ;
  ControlVar cVar_Y1EAI5L9;
  ControlVar cVar_z4E8XBpq;
  ControlVar cVar_cf13GXeB;
  ControlVar cVar_51DKeBAv;
  ControlBinop cBinop_eSm9spUm;
  ControlVar cVar_x0o53eWP;
  ControlDelay cDelay_0DnIf5NE;
  ControlVar cVar_nAuvmxEB;
  ControlBinop cBinop_vbbEi4Om;
  ControlBinop cBinop_e0kByt6g;
  ControlBinop cBinop_wWffeYmm;
  HvTable hTable_p1NfyiQe;
  ControlVar cVar_2e1wJviR;
  ControlTabread cTabread_nzOGcN2I;
  ControlSlice cSlice_fc4jptEf;
  ControlVar cVar_ZoVXMn4m;
  ControlBinop cBinop_0z3kv3yW;
  ControlBinop cBinop_yde2oXPP;
  ControlBinop cBinop_77kZI6aS;
  ControlTabread cTabread_lL3RZCns;
  ControlSlice cSlice_wAhxrrvV;
  ControlVar cVar_FQui9nmg;
  ControlBinop cBinop_Qq9dotkM;
  ControlBinop cBinop_BNjJXV7v;
  ControlBinop cBinop_TC1bR67k;
  ControlSlice cSlice_s9oZgM0N;
  ControlSlice cSlice_axn6Ec17;
  ControlVar cVar_FlYfEsMY;
  ControlTabread cTabread_Q29MVnGm;
  ControlSlice cSlice_9WAywOgi;
  ControlVar cVar_RCpE21qm;
  ControlBinop cBinop_4BNBX6Jo;
  ControlBinop cBinop_jFFje3jp;
  ControlBinop cBinop_BjyUSgAh;
  ControlTabwrite cTabwrite_pq4AEhYP;
  ControlSlice cSlice_76Kgx3D8;
  ControlVar cVar_tMQQ9NCj;
  ControlVar cVar_OJr9PpBk;
  ControlVar cVar_crbF0t8G;
  ControlVar cVar_SgWeKYcl;
  ControlVar cVar_e73Zh2j2;
  ControlVar cVar_LLJIDDYh;
  ControlIf cIf_DoJXr5mR;
  ControlBinop cBinop_DswDo8PJ;
  ControlVar cVar_z31PLJhl;
  ControlVar cVar_XHYqQouM;
  ControlVar cVar_gYGbW2Go;
  ControlVar cVar_dbhCJN2v;
  ControlIf cIf_qFqIZ0YL;
  ControlBinop cBinop_2wQAp8Di;
  ControlTabread cTabread_69zFVHNd;
  ControlSlice cSlice_juHKZSSW;
  ControlVar cVar_Vl3lIQOW;
  ControlBinop cBinop_9Nm2WJ1P;
  ControlBinop cBinop_2H7vvJtm;
  ControlBinop cBinop_X31d94cR;
  ControlTabwrite cTabwrite_zCDf0Qnm;
  ControlSlice cSlice_S8JqFPlR;
  ControlVar cVar_Z2B0qLWD;
  ControlPack cPack_IAVWnAo2;
  ControlVar cVar_b1im11q1;
  ControlBinop cBinop_JzH7ONAA;
  ControlBinop cBinop_OtS02goQ;
  ControlVar cVar_qDxMgu1L;
  ControlVar cVar_KxplVWAW;
  ControlVar cVar_p3k38w8R;
  ControlVar cVar_bTMyXveo;
  ControlIf cIf_sdU8jrMs;
  ControlBinop cBinop_snv21ihe;
  ControlVar cVar_MbX4a2A4;
  ControlVar cVar_i6k0WNHT;
  ControlPack cPack_qM7wNEV5;
  ControlVar cVar_I6hyxGzG;
  ControlBinop cBinop_dzvUnMMN;
  ControlBinop cBinop_xvK0V63M;
  ControlVar cVar_vtiaG2gV;
  ControlBinop cBinop_FzWySGec;
  ControlRandom cRandom_AK3up9D4;
  ControlSlice cSlice_Ax5gyJiM;
  ControlIf cIf_CfkjHFbE;
  ControlBinop cBinop_TV4wG2P0;
  ControlVar cVar_EYbX4a1I;
  ControlDelay cDelay_OsrhtCTO;
  ControlVar cVar_JWDqwD6F;
  ControlVar cVar_W0FnRGtb;
  ControlDelay cDelay_ffN7ZTAf;
  ControlSlice cSlice_UHyu3CwE;
  ControlSlice cSlice_Gik5ke51;
  ControlSlice cSlice_J7tcr8kL;
  ControlBinop cBinop_HoMQwJwi;
  ControlBinop cBinop_EbKF8RXC;
  ControlBinop cBinop_HwRtST9Q;
  ControlBinop cBinop_fLrqUo33;
  ControlBinop cBinop_YiKVkksC;
  ControlBinop cBinop_rf6KVXzX;
  ControlBinop cBinop_CYzElNH6;
  ControlBinop cBinop_KW3nZbzw;
  ControlBinop cBinop_RH72URT6;
  ControlBinop cBinop_rJBTqopo;
  ControlBinop cBinop_O8EZKz7X;
  ControlBinop cBinop_HYeSHC0r;
  ControlBinop cBinop_hiv9a98S;
};

#endif // _HEAVY_CONTEXT_SEQUENCERPATCH_HPP_
