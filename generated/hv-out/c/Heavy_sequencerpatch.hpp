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
#include "HvControlVar.h"
#include "HvControlCast.h"
#include "HvControlBinop.h"
#include "HvControlRandom.h"
#include "HvControlTabread.h"
#include "HvControlIf.h"
#include "HvControlSlice.h"
#include "HvControlUnop.h"
#include "HvControlTabwrite.h"
#include "HvControlPack.h"
#include "HvControlSystem.h"
#include "HvControlPrint.h"
#include "HvTable.h"
#include "HvControlDelay.h"

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
  static void hTable_aU7bpYj5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DxHvhGIH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_O7TdUt09_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_N0IGDpkg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FLlKsUNi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6Lw5GgkH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lZ2sUHBf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OKykJxHO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ejk9vpii_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_P0HcQWfI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_tLUVIYQE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Zy8B5ZG7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_32uIaiWG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_NQsHUaAW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_taCLOZFO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_faAaguyp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ard2bIT8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LtU410AC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_igmxLoWp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_B0WVC5Vx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5Vf8A9ZM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_xjbkNl3A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_yDX38Ufs_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_VeZg4GrG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wIbctWK9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_LDYJxvm5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_13dqsCEq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aYIRDYWp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0Sk0h6EE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uFE3KRtK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aI01dG6a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ciNEuPgC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_bf0irNOP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_zmkgv4a6_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_BTL6gn80_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VwuGje19_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_oy7N9KLJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_z3aoOBtw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5BJMuWbo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dyUJg8r0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tx9F94Jy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uG8lWSxO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iSZfRgUU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_UXE0hocg_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_ETp9c6iu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_JrM3lyDT_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_IduNt9kY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lN7UVpHY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_UYGodk10_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_JHRqX4pP_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_lAuXMsXH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kkTDDoT4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_E5aQMION_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aYZbkC6b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_13IpmHpx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DzLmRk05_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MkJ221En_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jfzU9Bk1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sGSPXZSF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabwrite_2k5ByC7r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ssI5NTCO_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_94c1tXK9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9l41cTYS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mwKEUg2U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nd9AGDGl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HabthaiE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5W2ZLuBf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Z2ZD9cvG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KqKdrQuk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Ku5cBYtq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_XpimiHfs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_XTxl5moi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tNRU7Bh8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JsLho3iT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lVz1tMPm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ed9Qv6IC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qpkb6KzX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XazeMUyH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_7iJtyTWp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_fMEn6B8x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_NZHgyHMy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AueJdtym_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_ICozAMIO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_O3Wrz6C1_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_XbiOEW3u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VRV3v9Lf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Qi51En6h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7lwXIGTz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SR58XaOZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qn6KlF9p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_d6AenJG8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_eWxC1Q9o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TSMt1tq8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabwrite_jRYVpswG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_QJtfSFp3_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_TG2UjY0z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0kueEkUH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_ooyFBLqM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6NsnrJgp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_XZuNUcRe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jJOSo1PW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DCmwox3w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1JXk9tfP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1Q3Tokgu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jVCEaYKk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dxUn5LMw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_VMhVUZ9u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0z5sHZlx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_5lVGji2w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_k0KHkan1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_Q4mM85Z5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VfKtRn9w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NqbtaWmv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NwHNu3jE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_Xp1iqTAf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KLLgErbJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_2qoVRIuY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_F8Z62DDb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_91qqY32I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SeBwtL85_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WfKtvQR8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_jrt8kfzw_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_oXgGWBnh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_6cWcOxvQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_e2q2UM0J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_UMIacYuR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_Rx58Wgkr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_m1EYHvHK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HM9ftm2x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_a2LBUNVq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_RywFdWTk_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_6OcDlbDF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ggyZhbAa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UerklJen_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2YfEUZZu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dlDAo84t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_9GYCWzvI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_Kp8PSUUu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uqWZPzQk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9Ndstogj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_mFOzOYEm_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_rVG8edGM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_jUxHFgYq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_71e8KdhT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OKLfmc7D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Dbv3vcTz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_e2SUpWso_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TN3amiBI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HhyxrnpG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DMu9DUTF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oW0GzJIC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5SckXBbv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EzvIh5w7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CotknhtA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1s9XG3gP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nFM9CAG1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_57BdG3Zv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mbvUBcwn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vXtyMUDa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KGH1BHrD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Gyn2azdK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EbCL1Lyn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rXZEEH4w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FH51RExO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Wi4Lxf6x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6uf7qPkK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6C9GngeU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_t4DZMO7L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lHA9ehFu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qlz1IfLM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JiM3NReI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZuEae0TO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Y5m3CzU5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DfSBJUZI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dGwZO9o6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OOyVeKvu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KwR8996p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bdHRFJKy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_r4qIRTKH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LTCzfUaq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Z4C1sJ8M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_J4bF9XHy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uZmcSASI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1oKS66dN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5cbW2F3C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EShg3avm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JD8KBoMB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_y3t9XHHS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Hck9eFlK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5s1iqmyy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Pa3RUMOx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OXRpbNcn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7QsNNM85_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3pQb5ooC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_X7XwlAwM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_508jYoA3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lqG4cVa5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rvaTXq9W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_VnekL1Rd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_PSYmqHrq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_AT1Vwgid_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Y3xvR11l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cJP01Y26_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_D99UlnIn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MXCgl1uD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iTwjpAix_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_T5WQjpIr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_569nSxZ8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_trxNycyA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_g8PBp44Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_KoXZPZUY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Vina7Vm1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_HLIH7wrr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_JEt1nX5T_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  HvTable hTable_aU7bpYj5;
  ControlVar cVar_DxHvhGIH;
  ControlVar cVar_O7TdUt09;
  ControlVar cVar_N0IGDpkg;
  ControlVar cVar_lZ2sUHBf;
  ControlBinop cBinop_OKykJxHO;
  ControlVar cVar_ejk9vpii;
  ControlDelay cDelay_tLUVIYQE;
  ControlVar cVar_taCLOZFO;
  ControlBinop cBinop_ard2bIT8;
  ControlBinop cBinop_LtU410AC;
  ControlBinop cBinop_igmxLoWp;
  HvTable hTable_B0WVC5Vx;
  ControlVar cVar_5Vf8A9ZM;
  ControlTabread cTabread_xjbkNl3A;
  ControlSlice cSlice_VeZg4GrG;
  ControlVar cVar_wIbctWK9;
  ControlBinop cBinop_13dqsCEq;
  ControlBinop cBinop_uFE3KRtK;
  ControlBinop cBinop_ciNEuPgC;
  ControlTabread cTabread_bf0irNOP;
  ControlSlice cSlice_BTL6gn80;
  ControlVar cVar_VwuGje19;
  ControlBinop cBinop_z3aoOBtw;
  ControlBinop cBinop_tx9F94Jy;
  ControlBinop cBinop_iSZfRgUU;
  ControlSlice cSlice_ETp9c6iu;
  ControlSlice cSlice_IduNt9kY;
  ControlVar cVar_lN7UVpHY;
  ControlTabread cTabread_UYGodk10;
  ControlSlice cSlice_lAuXMsXH;
  ControlVar cVar_kkTDDoT4;
  ControlBinop cBinop_aYZbkC6b;
  ControlBinop cBinop_MkJ221En;
  ControlBinop cBinop_sGSPXZSF;
  ControlTabwrite cTabwrite_2k5ByC7r;
  ControlSlice cSlice_94c1tXK9;
  ControlVar cVar_9l41cTYS;
  ControlVar cVar_mwKEUg2U;
  ControlVar cVar_nd9AGDGl;
  ControlVar cVar_5W2ZLuBf;
  ControlVar cVar_Z2ZD9cvG;
  ControlVar cVar_KqKdrQuk;
  ControlIf cIf_XTxl5moi;
  ControlBinop cBinop_tNRU7Bh8;
  ControlVar cVar_JsLho3iT;
  ControlVar cVar_lVz1tMPm;
  ControlVar cVar_ed9Qv6IC;
  ControlVar cVar_XazeMUyH;
  ControlIf cIf_NZHgyHMy;
  ControlBinop cBinop_AueJdtym;
  ControlTabread cTabread_ICozAMIO;
  ControlSlice cSlice_XbiOEW3u;
  ControlVar cVar_VRV3v9Lf;
  ControlBinop cBinop_7lwXIGTz;
  ControlBinop cBinop_d6AenJG8;
  ControlBinop cBinop_TSMt1tq8;
  ControlTabwrite cTabwrite_jRYVpswG;
  ControlSlice cSlice_TG2UjY0z;
  ControlVar cVar_0kueEkUH;
  ControlPack cPack_ooyFBLqM;
  ControlVar cVar_6NsnrJgp;
  ControlBinop cBinop_jJOSo1PW;
  ControlBinop cBinop_DCmwox3w;
  ControlVar cVar_1Q3Tokgu;
  ControlVar cVar_jVCEaYKk;
  ControlVar cVar_dxUn5LMw;
  ControlVar cVar_0z5sHZlx;
  ControlIf cIf_Q4mM85Z5;
  ControlBinop cBinop_VfKtRn9w;
  ControlVar cVar_NqbtaWmv;
  ControlVar cVar_NwHNu3jE;
  ControlPack cPack_Xp1iqTAf;
  ControlVar cVar_KLLgErbJ;
  ControlBinop cBinop_F8Z62DDb;
  ControlBinop cBinop_91qqY32I;
  ControlVar cVar_WfKtvQR8;
  ControlBinop cBinop_oXgGWBnh;
  ControlRandom cRandom_e2q2UM0J;
  ControlSlice cSlice_UMIacYuR;
  ControlIf cIf_Rx58Wgkr;
  ControlBinop cBinop_m1EYHvHK;
  ControlVar cVar_a2LBUNVq;
  ControlDelay cDelay_6OcDlbDF;
  ControlVar cVar_2YfEUZZu;
  ControlVar cVar_dlDAo84t;
  ControlDelay cDelay_Kp8PSUUu;
  ControlSlice cSlice_rVG8edGM;
  ControlSlice cSlice_jUxHFgYq;
  ControlSlice cSlice_71e8KdhT;
  ControlBinop cBinop_OKLfmc7D;
  ControlBinop cBinop_CotknhtA;
  ControlBinop cBinop_1s9XG3gP;
  ControlBinop cBinop_nFM9CAG1;
  ControlBinop cBinop_57BdG3Zv;
  ControlBinop cBinop_mbvUBcwn;
  ControlBinop cBinop_vXtyMUDa;
  ControlBinop cBinop_JiM3NReI;
  ControlBinop cBinop_ZuEae0TO;
  ControlBinop cBinop_Y5m3CzU5;
  ControlBinop cBinop_D99UlnIn;
  ControlBinop cBinop_MXCgl1uD;
  ControlBinop cBinop_iTwjpAix;
};

#endif // _HEAVY_CONTEXT_SEQUENCERPATCH_HPP_
