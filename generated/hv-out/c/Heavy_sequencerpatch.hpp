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
  static void hTable_GmqfX3Sf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rgmLjZwC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zihicSa5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WLhoj1fS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hDnRfkW1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vq0Bzx0z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CIvaH6Xt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QH89MGaT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dzYqXtit_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_KMpuIeRA_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_wV0js4yT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oR753RtI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sFJubnyF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GcGfnZQs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EsgLwwcw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bPcdt4ZS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1Fnj0dDW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jfMzfRnw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kkLnmJKT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_S4AfvaKv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nmG5uJFI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_HtPaQIRk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_wLq4jCpN_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_hqzzmWBc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vyKJU34l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_6D9q1YnN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_usHcKYkn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Y3u3rpIn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fmEqhLK5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SFaHwndt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AKVnJyM4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ITeVIP8j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_C3W6ayXd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_qUtK165W_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_OepYDrb0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hd53z7Ag_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_PlLUdTFC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wx0oRVcI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KsE6KarE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CCFsQuXJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SFTv4cPR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1FimGY5K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iWK5tY1m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_xZQAe4IY_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_U3lurAES_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ZGaX6txO_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_xJhPyR51_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bNErEauk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_pD90GbDc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Ss57MTC7_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_6LTY3Te9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HhPead0O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ZngkfZ8K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kFYvmGfp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XxciclGI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bEbHNJmV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_m8AjolRk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_heI9Ak2Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NXLc2xm5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabwrite_ibIt33KH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_q3X3UNXy_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_MyFZJgi1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0YB8RcD3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LI6IQVzv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JCf1kr3y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GmJ6jkkj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EFC1jlke_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XFOJmNhz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Ers4jeqz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_jV90fprf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_sKz9rOl8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_y0zqoypE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yFIFIxLm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MtgxewzT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OHXHY736_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CnizmcPj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WkOvU4ih_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hte3GZa9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_OkSvldZz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_CAXQnD3a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_ckwmpUHC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7MkhxG83_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_5W5xjMI7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_AvgSPszs_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_VfbpkdnP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mcPi5qJ2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_CFGDNhNk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r5K2vv46_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ojktAK6X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_068oI7RJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N1sHZ3yj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1LcUrkg0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wC3WOH5u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabwrite_5ZJdzTDJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_qaVo7i4N_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_zsBDMpQ6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EEZjMwjA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_KdVFCpcx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_F7kwKqQV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_m98fhTUd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CT9kTpB5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OnULMUzo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EFuhLbMi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_X5yEYxyt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fYP0iyjD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FDktYvog_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6AjDyZV6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_unxifVQb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_fLbg0YVS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_BlgLNNOn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_JcGDgsKB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_afK5iFF0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UHbgMKpz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_E7PcBy1t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_Bob4VMdF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gndyYThO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_nDe1Edph_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YNsZwu6V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mLMYT8E8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_quiTYbJr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_llcyckDa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_BiZ6Rqsg_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_A6GdLCFd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Zw74cSWL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_CeTQ9AO2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_sAfxc88v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_sKcRT1yq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nV2L9AUe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iPB76aSz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pu0o1vGK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_UuucGHDj_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_21cfdmLd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WzDkvTuJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xVmjTjE2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4mulQ024_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XXFhSj4A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_YOZYbuuZ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_TORmzKt2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ty1ne8qi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MWnpwQ0m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_XhRHIPUJ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_zsQ3qlmX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Vyh4Of1i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_GUCUQhhV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3LTuSEQi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Fj9nd08b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gk3p16Zd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vV2Kpujk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aS0WSJUj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iazjZHmF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Tb37hAdY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bvaBWuD6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iPBKdGK4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rejwkArX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ak9rzKYD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iQs8bIcH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3if3tsMm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nvpjcPpZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jHvTJ8zW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BdSwn9y0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8xSM2Qua_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ytdSAgCN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Rabaozrk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PQ4O5Hmw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tU8mTOjB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_eidbBrbu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_u0pCdhgB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0gMDMIlc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JtAOGY7b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_d5ZLTvxQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wEkybrL1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1lASdqrD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9YbaMkwK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rXneTsGS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_R2pY5X00_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UfJMkhGo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7FwlbE3i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wXl3g8kJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_S4NWKQe9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_864iPENE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_O5xSHnFM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_U7MzS8EM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3gTnD0ru_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NSNUo91e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dufHnPbj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lg2lv8qH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wxiQm5hO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gQtyTbpH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_G5sQtUiZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GWisDcpy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UBBfjOAA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BzGWqpNj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MggDiASk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_L2l4gppb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qjRocwwA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_O8Ia9rvL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YkAJYm7w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_G2KBE6we_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mUoKhXJK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Weyw58ro_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_TJNhJUY6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_HGAmiwiS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_8Z0hZqWM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_eIvtgoqP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_f2EJ8L4z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vHD40aG7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lQHMVL7G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EfuDaKIB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_mc3l1Jdi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_NJXgpa2E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_3xJ9hNKI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_LNjN222q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_wqYlfae1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_fpKSJS03_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  HvTable hTable_GmqfX3Sf;
  ControlVar cVar_rgmLjZwC;
  ControlVar cVar_zihicSa5;
  ControlVar cVar_WLhoj1fS;
  ControlVar cVar_CIvaH6Xt;
  ControlBinop cBinop_QH89MGaT;
  ControlVar cVar_dzYqXtit;
  ControlDelay cDelay_wV0js4yT;
  ControlVar cVar_EsgLwwcw;
  ControlBinop cBinop_1Fnj0dDW;
  ControlBinop cBinop_jfMzfRnw;
  ControlBinop cBinop_kkLnmJKT;
  HvTable hTable_S4AfvaKv;
  ControlVar cVar_nmG5uJFI;
  ControlTabread cTabread_HtPaQIRk;
  ControlSlice cSlice_hqzzmWBc;
  ControlVar cVar_vyKJU34l;
  ControlBinop cBinop_usHcKYkn;
  ControlBinop cBinop_SFaHwndt;
  ControlBinop cBinop_ITeVIP8j;
  ControlTabread cTabread_C3W6ayXd;
  ControlSlice cSlice_OepYDrb0;
  ControlVar cVar_hd53z7Ag;
  ControlBinop cBinop_wx0oRVcI;
  ControlBinop cBinop_SFTv4cPR;
  ControlBinop cBinop_iWK5tY1m;
  ControlSlice cSlice_U3lurAES;
  ControlSlice cSlice_xJhPyR51;
  ControlVar cVar_bNErEauk;
  ControlTabread cTabread_pD90GbDc;
  ControlSlice cSlice_6LTY3Te9;
  ControlVar cVar_HhPead0O;
  ControlBinop cBinop_kFYvmGfp;
  ControlBinop cBinop_m8AjolRk;
  ControlBinop cBinop_NXLc2xm5;
  ControlTabwrite cTabwrite_ibIt33KH;
  ControlSlice cSlice_MyFZJgi1;
  ControlVar cVar_0YB8RcD3;
  ControlVar cVar_LI6IQVzv;
  ControlVar cVar_JCf1kr3y;
  ControlVar cVar_EFC1jlke;
  ControlVar cVar_XFOJmNhz;
  ControlVar cVar_Ers4jeqz;
  ControlIf cIf_y0zqoypE;
  ControlBinop cBinop_yFIFIxLm;
  ControlVar cVar_MtgxewzT;
  ControlVar cVar_OHXHY736;
  ControlVar cVar_CnizmcPj;
  ControlVar cVar_hte3GZa9;
  ControlIf cIf_ckwmpUHC;
  ControlBinop cBinop_7MkhxG83;
  ControlTabread cTabread_5W5xjMI7;
  ControlSlice cSlice_VfbpkdnP;
  ControlVar cVar_mcPi5qJ2;
  ControlBinop cBinop_r5K2vv46;
  ControlBinop cBinop_N1sHZ3yj;
  ControlBinop cBinop_wC3WOH5u;
  ControlTabwrite cTabwrite_5ZJdzTDJ;
  ControlSlice cSlice_zsBDMpQ6;
  ControlVar cVar_EEZjMwjA;
  ControlPack cPack_KdVFCpcx;
  ControlVar cVar_F7kwKqQV;
  ControlBinop cBinop_CT9kTpB5;
  ControlBinop cBinop_OnULMUzo;
  ControlVar cVar_X5yEYxyt;
  ControlVar cVar_fYP0iyjD;
  ControlVar cVar_FDktYvog;
  ControlVar cVar_unxifVQb;
  ControlIf cIf_JcGDgsKB;
  ControlBinop cBinop_afK5iFF0;
  ControlVar cVar_UHbgMKpz;
  ControlVar cVar_E7PcBy1t;
  ControlPack cPack_Bob4VMdF;
  ControlVar cVar_gndyYThO;
  ControlBinop cBinop_YNsZwu6V;
  ControlBinop cBinop_mLMYT8E8;
  ControlVar cVar_llcyckDa;
  ControlBinop cBinop_A6GdLCFd;
  ControlRandom cRandom_CeTQ9AO2;
  ControlSlice cSlice_sAfxc88v;
  ControlIf cIf_sKcRT1yq;
  ControlBinop cBinop_nV2L9AUe;
  ControlVar cVar_pu0o1vGK;
  ControlDelay cDelay_21cfdmLd;
  ControlVar cVar_4mulQ024;
  ControlVar cVar_XXFhSj4A;
  ControlDelay cDelay_TORmzKt2;
  ControlSlice cSlice_zsQ3qlmX;
  ControlSlice cSlice_Vyh4Of1i;
  ControlSlice cSlice_GUCUQhhV;
  ControlBinop cBinop_3LTuSEQi;
  ControlBinop cBinop_rejwkArX;
  ControlBinop cBinop_Ak9rzKYD;
  ControlBinop cBinop_iQs8bIcH;
  ControlBinop cBinop_3if3tsMm;
  ControlBinop cBinop_nvpjcPpZ;
  ControlBinop cBinop_jHvTJ8zW;
  ControlBinop cBinop_wEkybrL1;
  ControlBinop cBinop_1lASdqrD;
  ControlBinop cBinop_9YbaMkwK;
  ControlBinop cBinop_vHD40aG7;
  ControlBinop cBinop_lQHMVL7G;
  ControlBinop cBinop_EfuDaKIB;
};

#endif // _HEAVY_CONTEXT_SEQUENCERPATCH_HPP_
