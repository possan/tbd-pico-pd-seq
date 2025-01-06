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

#include "Heavy_sequencerpatch.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_sequencerpatch *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_sequencerpatch_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_sequencerpatch));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_sequencerpatch(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_sequencerpatch_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_sequencerpatch));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_sequencerpatch(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_sequencerpatch_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_sequencerpatch();
    // free memory
    hv_free(instance);
  }
} // extern "C"



/*
 * Table Data
 */

float hTable_aU7bpYj5_data[32] = {49.0f, 47.979f, 79.0f, 80.0f, 45.0f, 57.0f, 9.98214f, 43.445f, 76.2008f, 58.9658f, 47.0f, 37.1953f, 3.63241f, 11.7963f, 23.5887f, 35.3811f, 56.2445f, 60.78f, 88.9002f, 99.7855f, 109.764f, 44.313f, 35.3811f, 48.9876f, 56.2445f, 70.7581f, 81.6434f, -0.903114f, 14.5177f, 21.7745f, 29.0313f, 41.7308f};
float hTable_B0WVC5Vx_data[32] = {101.0f, 86.0f, 70.0f, 56.0f, 39.0f, 5.0f, 0.0f, 1.0f, 0.0f, -1.0f, -2.0f, -1.0f, -1.0f, -1.0f, -2.0f, 6.0f, 17.0f, 27.0f, 35.0f, 47.0f, 59.0f, 73.0f, 90.0f, 96.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f};



/*
 * Class Functions
 */

Heavy_sequencerpatch::Heavy_sequencerpatch(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += hTable_initWithData(&hTable_aU7bpYj5, 32, hTable_aU7bpYj5_data);
  numBytes += cVar_init_f(&cVar_DxHvhGIH, 0.0f);
  numBytes += cVar_init_f(&cVar_O7TdUt09, 0.0f);
  numBytes += cVar_init_f(&cVar_N0IGDpkg, 0.0f);
  numBytes += cVar_init_f(&cVar_lZ2sUHBf, 1.0f);
  numBytes += cVar_init_f(&cVar_ejk9vpii, 0.0f);
  numBytes += cDelay_init(this, &cDelay_tLUVIYQE, 0.0f);
  numBytes += cVar_init_f(&cVar_taCLOZFO, 250.0f);
  numBytes += cBinop_init(&cBinop_igmxLoWp, 0.0f); // __mul
  numBytes += hTable_initWithData(&hTable_B0WVC5Vx, 32, hTable_B0WVC5Vx_data);
  numBytes += cVar_init_f(&cVar_5Vf8A9ZM, 0.0f);
  numBytes += cTabread_init(&cTabread_xjbkNl3A, &hTable_B0WVC5Vx); // trigchance
  numBytes += cSlice_init(&cSlice_VeZg4GrG, 1, -1);
  numBytes += cVar_init_s(&cVar_wIbctWK9, "trigchance");
  numBytes += cBinop_init(&cBinop_uFE3KRtK, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_bf0irNOP, &hTable_aU7bpYj5); // note
  numBytes += cSlice_init(&cSlice_BTL6gn80, 1, -1);
  numBytes += cVar_init_s(&cVar_VwuGje19, "note");
  numBytes += cBinop_init(&cBinop_tx9F94Jy, 0.0f); // __min
  numBytes += cSlice_init(&cSlice_ETp9c6iu, 1, -1);
  numBytes += cSlice_init(&cSlice_IduNt9kY, 1, -1);
  numBytes += cVar_init_f(&cVar_lN7UVpHY, 0.0f);
  numBytes += cTabread_init(&cTabread_UYGodk10, &hTable_aU7bpYj5); // note
  numBytes += cSlice_init(&cSlice_lAuXMsXH, 1, -1);
  numBytes += cVar_init_s(&cVar_kkTDDoT4, "note");
  numBytes += cBinop_init(&cBinop_MkJ221En, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_2k5ByC7r, &hTable_aU7bpYj5); // note
  numBytes += cSlice_init(&cSlice_94c1tXK9, 1, -1);
  numBytes += cVar_init_f(&cVar_9l41cTYS, 0.0f);
  numBytes += cVar_init_f(&cVar_mwKEUg2U, 0.0f);
  numBytes += cVar_init_f(&cVar_nd9AGDGl, 0.0f);
  numBytes += cVar_init_f(&cVar_5W2ZLuBf, 0.0f);
  numBytes += cVar_init_f(&cVar_Z2ZD9cvG, 0.0f);
  numBytes += cVar_init_f(&cVar_KqKdrQuk, 0.0f);
  numBytes += cIf_init(&cIf_XTxl5moi, false);
  numBytes += cVar_init_f(&cVar_JsLho3iT, 0.0f);
  numBytes += cVar_init_f(&cVar_lVz1tMPm, 0.0f);
  numBytes += cVar_init_f(&cVar_ed9Qv6IC, 0.0f);
  numBytes += cVar_init_f(&cVar_XazeMUyH, 0.0f);
  numBytes += cIf_init(&cIf_NZHgyHMy, false);
  numBytes += cTabread_init(&cTabread_ICozAMIO, &hTable_B0WVC5Vx); // trigchance
  numBytes += cSlice_init(&cSlice_XbiOEW3u, 1, -1);
  numBytes += cVar_init_s(&cVar_VRV3v9Lf, "trigchance");
  numBytes += cBinop_init(&cBinop_d6AenJG8, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_jRYVpswG, &hTable_B0WVC5Vx); // trigchance
  numBytes += cSlice_init(&cSlice_TG2UjY0z, 1, -1);
  numBytes += cVar_init_f(&cVar_0kueEkUH, 0.0f);
  numBytes += cPack_init(&cPack_ooyFBLqM, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_6NsnrJgp, 0.0f);
  numBytes += cVar_init_f(&cVar_1Q3Tokgu, 0.0f);
  numBytes += cVar_init_f(&cVar_jVCEaYKk, 0.0f);
  numBytes += cVar_init_f(&cVar_dxUn5LMw, 0.0f);
  numBytes += cVar_init_f(&cVar_0z5sHZlx, 0.0f);
  numBytes += cIf_init(&cIf_Q4mM85Z5, false);
  numBytes += cVar_init_f(&cVar_NqbtaWmv, 0.0f);
  numBytes += cVar_init_f(&cVar_NwHNu3jE, 0.0f);
  numBytes += cPack_init(&cPack_Xp1iqTAf, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_KLLgErbJ, 0.0f);
  numBytes += cVar_init_f(&cVar_WfKtvQR8, 0.0f);
  numBytes += cRandom_init(&cRandom_e2q2UM0J, -1429138204);
  numBytes += cSlice_init(&cSlice_UMIacYuR, 1, 1);
  numBytes += cIf_init(&cIf_Rx58Wgkr, false);
  numBytes += cBinop_init(&cBinop_m1EYHvHK, 0.0f); // __gte
  numBytes += cVar_init_f(&cVar_a2LBUNVq, 0.0f);
  numBytes += cDelay_init(this, &cDelay_6OcDlbDF, 25.0f);
  numBytes += cVar_init_f(&cVar_2YfEUZZu, 0.0f);
  numBytes += cVar_init_f(&cVar_dlDAo84t, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Kp8PSUUu, 10.0f);
  numBytes += cSlice_init(&cSlice_rVG8edGM, 1, -1);
  numBytes += cSlice_init(&cSlice_jUxHFgYq, 1, -1);
  numBytes += cSlice_init(&cSlice_71e8KdhT, 1, -1);
  numBytes += cBinop_init(&cBinop_CotknhtA, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_1s9XG3gP, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_JiM3NReI, 0.0f); // __add
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_sequencerpatch::~Heavy_sequencerpatch() {
  hTable_free(&hTable_aU7bpYj5);
  hTable_free(&hTable_B0WVC5Vx);
  cPack_free(&cPack_ooyFBLqM);
  cPack_free(&cPack_Xp1iqTAf);
}

HvTable *Heavy_sequencerpatch::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x6E3449A8: return &hTable_aU7bpYj5; // note
    case 0x98FB22EB: return &hTable_B0WVC5Vx; // trigchance
    default: return nullptr;
  }
}

void Heavy_sequencerpatch::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_g8PBp44Z_sendMessage);
      break;
    }
    case 0x88E4D7C8: { // set-tempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Vina7Vm1_sendMessage);
      break;
    }
    case 0x559B0855: { // tbd_knob
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JEt1nX5T_sendMessage);
      break;
    }
    case 0xBD433D4B: { // tbd_step
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HLIH7wrr_sendMessage);
      break;
    }
    case 0x26682824: { // tempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KoXZPZUY_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_sequencerpatch::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_sequencerpatch::hTable_aU7bpYj5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_DxHvhGIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_O7TdUt09, 0, m, &cVar_O7TdUt09_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_OKLfmc7D_sendMessage);
}

void Heavy_sequencerpatch::cVar_O7TdUt09_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 16.0f, 0, m, &cBinop_rvaTXq9W_sendMessage);
}

void Heavy_sequencerpatch::cVar_N0IGDpkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rXZEEH4w_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KGH1BHrD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wi4Lxf6x_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EbCL1Lyn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6C9GngeU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FH51RExO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Gyn2azdK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6uf7qPkK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dlDAo84t, 1, m, &cVar_dlDAo84t_sendMessage);
}

void Heavy_sequencerpatch::cCast_FLlKsUNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dbv3vcTz_sendMessage(_c, 0, m);
  cMsg_e2SUpWso_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_6Lw5GgkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DxHvhGIH, 0, m, &cVar_DxHvhGIH_sendMessage);
}

void Heavy_sequencerpatch::cVar_lZ2sUHBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_OKykJxHO_sendMessage);
  cSwitchcase_P0HcQWfI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cBinop_OKykJxHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lZ2sUHBf, 1, m, &cVar_lZ2sUHBf_sendMessage);
}

void Heavy_sequencerpatch::cVar_ejk9vpii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WfKtvQR8, 1, m, &cVar_WfKtvQR8_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_P0HcQWfI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_faAaguyp_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_faAaguyp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Zy8B5ZG7_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cDelay_tLUVIYQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tLUVIYQE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tLUVIYQE, 0, m, &cDelay_tLUVIYQE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6Lw5GgkH_sendMessage);
}

void Heavy_sequencerpatch::cCast_Zy8B5ZG7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_faAaguyp_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tLUVIYQE, 0, m, &cDelay_tLUVIYQE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6Lw5GgkH_sendMessage);
}

void Heavy_sequencerpatch::cMsg_32uIaiWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NQsHUaAW_sendMessage);
}

void Heavy_sequencerpatch::cSystem_NQsHUaAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LtU410AC_sendMessage);
}

void Heavy_sequencerpatch::cVar_taCLOZFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_igmxLoWp, HV_BINOP_MULTIPLY, 0, m, &cBinop_igmxLoWp_sendMessage);
}

void Heavy_sequencerpatch::cMsg_faAaguyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tLUVIYQE, 0, m, &cDelay_tLUVIYQE_sendMessage);
}

void Heavy_sequencerpatch::cBinop_ard2bIT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tLUVIYQE, 2, m, &cDelay_tLUVIYQE_sendMessage);
}

void Heavy_sequencerpatch::cBinop_LtU410AC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_igmxLoWp, HV_BINOP_MULTIPLY, 1, m, &cBinop_igmxLoWp_sendMessage);
}

void Heavy_sequencerpatch::cBinop_igmxLoWp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ard2bIT8_sendMessage);
}

void Heavy_sequencerpatch::hTable_B0WVC5Vx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_5Vf8A9ZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cTabread_xjbkNl3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5Vf8A9ZM, 0, m, &cVar_5Vf8A9ZM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5s1iqmyy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Hck9eFlK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OXRpbNcn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Pa3RUMOx_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_yDX38Ufs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VeZg4GrG, 0, m, &cSlice_VeZg4GrG_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0Sk0h6EE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aYIRDYWp_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_VeZg4GrG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_xjbkNl3A, 1, m, &cTabread_xjbkNl3A_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_xjbkNl3A, 1, m, &cTabread_xjbkNl3A_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_wIbctWK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aI01dG6a_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_LDYJxvm5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ciNEuPgC_sendMessage);
}

void Heavy_sequencerpatch::cBinop_13dqsCEq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uFE3KRtK, HV_BINOP_MIN, 0, m, &cBinop_uFE3KRtK_sendMessage);
}

void Heavy_sequencerpatch::cCast_aYIRDYWp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_13dqsCEq_sendMessage);
}

void Heavy_sequencerpatch::cCast_0Sk0h6EE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wIbctWK9, 0, m, &cVar_wIbctWK9_sendMessage);
}

void Heavy_sequencerpatch::cBinop_uFE3KRtK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_xjbkNl3A, 0, m, &cTabread_xjbkNl3A_sendMessage);
}

void Heavy_sequencerpatch::cMsg_aI01dG6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LDYJxvm5_sendMessage);
}

void Heavy_sequencerpatch::cBinop_ciNEuPgC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uFE3KRtK, HV_BINOP_MIN, 1, m, &cBinop_uFE3KRtK_sendMessage);
}

void Heavy_sequencerpatch::cTabread_bf0irNOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ejk9vpii, 0, m, &cVar_ejk9vpii_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_zmkgv4a6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BTL6gn80, 0, m, &cSlice_BTL6gn80_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dyUJg8r0_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5BJMuWbo_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_BTL6gn80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_bf0irNOP, 1, m, &cTabread_bf0irNOP_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_bf0irNOP, 1, m, &cTabread_bf0irNOP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_VwuGje19_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uG8lWSxO_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_oy7N9KLJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_iSZfRgUU_sendMessage);
}

void Heavy_sequencerpatch::cBinop_z3aoOBtw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tx9F94Jy, HV_BINOP_MIN, 0, m, &cBinop_tx9F94Jy_sendMessage);
}

void Heavy_sequencerpatch::cCast_5BJMuWbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_z3aoOBtw_sendMessage);
}

void Heavy_sequencerpatch::cCast_dyUJg8r0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VwuGje19, 0, m, &cVar_VwuGje19_sendMessage);
}

void Heavy_sequencerpatch::cBinop_tx9F94Jy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_bf0irNOP, 0, m, &cTabread_bf0irNOP_sendMessage);
}

void Heavy_sequencerpatch::cMsg_uG8lWSxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oy7N9KLJ_sendMessage);
}

void Heavy_sequencerpatch::cBinop_iSZfRgUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tx9F94Jy, HV_BINOP_MIN, 1, m, &cBinop_tx9F94Jy_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_UXE0hocg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xCCBDDAC9: { // "turn"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ETp9c6iu, 0, m, &cSlice_ETp9c6iu_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_ETp9c6iu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_mFOzOYEm_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      cSwitchcase_mFOzOYEm_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cSwitchcase_JrM3lyDT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xCEF0717E: { // "press"
      cSlice_onMessage(_c, &Context(_c)->cSlice_IduNt9kY, 0, m, &cSlice_IduNt9kY_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_IduNt9kY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_lN7UVpHY, 0, m, &cVar_lN7UVpHY_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_lN7UVpHY, 0, m, &cVar_lN7UVpHY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_lN7UVpHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9l41cTYS, 1, m, &cVar_9l41cTYS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JsLho3iT, 1, m, &cVar_JsLho3iT_sendMessage);
}

void Heavy_sequencerpatch::cTabread_UYGodk10_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mwKEUg2U, 0, m, &cVar_mwKEUg2U_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_JHRqX4pP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lAuXMsXH, 0, m, &cSlice_lAuXMsXH_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_13IpmHpx_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DzLmRk05_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_lAuXMsXH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_UYGodk10, 1, m, &cTabread_UYGodk10_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_UYGodk10, 1, m, &cTabread_UYGodk10_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_kkTDDoT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jfzU9Bk1_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_E5aQMION_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_sGSPXZSF_sendMessage);
}

void Heavy_sequencerpatch::cBinop_aYZbkC6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MkJ221En, HV_BINOP_MIN, 0, m, &cBinop_MkJ221En_sendMessage);
}

void Heavy_sequencerpatch::cCast_13IpmHpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kkTDDoT4, 0, m, &cVar_kkTDDoT4_sendMessage);
}

void Heavy_sequencerpatch::cCast_DzLmRk05_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_aYZbkC6b_sendMessage);
}

void Heavy_sequencerpatch::cBinop_MkJ221En_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_UYGodk10, 0, m, &cTabread_UYGodk10_sendMessage);
}

void Heavy_sequencerpatch::cMsg_jfzU9Bk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_E5aQMION_sendMessage);
}

void Heavy_sequencerpatch::cBinop_sGSPXZSF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MkJ221En, HV_BINOP_MIN, 1, m, &cBinop_MkJ221En_sendMessage);
}

void Heavy_sequencerpatch::cTabwrite_2k5ByC7r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cSwitchcase_ssI5NTCO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_94c1tXK9, 0, m, &cSlice_94c1tXK9_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_2k5ByC7r, 0, m, &cTabwrite_2k5ByC7r_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_94c1tXK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_2k5ByC7r, 2, m, &cTabwrite_2k5ByC7r_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_2k5ByC7r, 2, m, &cTabwrite_2k5ByC7r_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_9l41cTYS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JHRqX4pP_onMessage(_c, NULL, 0, m, NULL);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_2k5ByC7r, 1, m, &cTabwrite_2k5ByC7r_sendMessage);
}

void Heavy_sequencerpatch::cVar_mwKEUg2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CotknhtA, HV_BINOP_ADD, 0, m, &cBinop_CotknhtA_sendMessage);
}

void Heavy_sequencerpatch::cVar_nd9AGDGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 12.0f, 0, m, &cBinop_vXtyMUDa_sendMessage);
}

void Heavy_sequencerpatch::cCast_HabthaiE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9l41cTYS, 0, m, &cVar_9l41cTYS_sendMessage);
}

void Heavy_sequencerpatch::cVar_5W2ZLuBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 30.0f, 0, m, &cBinop_iTwjpAix_sendMessage);
}

void Heavy_sequencerpatch::cVar_Z2ZD9cvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 30.0f, 0, m, &cBinop_MXCgl1uD_sendMessage);
}

void Heavy_sequencerpatch::cVar_KqKdrQuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_tNRU7Bh8_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_XTxl5moi, 0, m, &cIf_XTxl5moi_sendMessage);
}

void Heavy_sequencerpatch::cUnop_Ku5cBYtq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ssI5NTCO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cUnop_XpimiHfs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ssI5NTCO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cIf_XTxl5moi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_XpimiHfs_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Ku5cBYtq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_tNRU7Bh8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XTxl5moi, 1, m, &cIf_XTxl5moi_sendMessage);
}

void Heavy_sequencerpatch::cVar_JsLho3iT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_O3Wrz6C1_onMessage(_c, NULL, 0, m, NULL);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jRYVpswG, 1, m, &cTabwrite_jRYVpswG_sendMessage);
}

void Heavy_sequencerpatch::cVar_lVz1tMPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1s9XG3gP, HV_BINOP_ADD, 0, m, &cBinop_1s9XG3gP_sendMessage);
}

void Heavy_sequencerpatch::cVar_ed9Qv6IC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_nFM9CAG1_sendMessage);
}

void Heavy_sequencerpatch::cCast_qpkb6KzX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JsLho3iT, 0, m, &cVar_JsLho3iT_sendMessage);
}

void Heavy_sequencerpatch::cVar_XazeMUyH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_AueJdtym_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NZHgyHMy, 0, m, &cIf_NZHgyHMy_sendMessage);
}

void Heavy_sequencerpatch::cUnop_7iJtyTWp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_QJtfSFp3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cUnop_fMEn6B8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_QJtfSFp3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cIf_NZHgyHMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_fMEn6B8x_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7iJtyTWp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_AueJdtym_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NZHgyHMy, 1, m, &cIf_NZHgyHMy_sendMessage);
}

void Heavy_sequencerpatch::cTabread_ICozAMIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lVz1tMPm, 0, m, &cVar_lVz1tMPm_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_O3Wrz6C1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XbiOEW3u, 0, m, &cSlice_XbiOEW3u_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SR58XaOZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qn6KlF9p_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_XbiOEW3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_ICozAMIO, 1, m, &cTabread_ICozAMIO_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_ICozAMIO, 1, m, &cTabread_ICozAMIO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_VRV3v9Lf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eWxC1Q9o_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_Qi51En6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TSMt1tq8_sendMessage);
}

void Heavy_sequencerpatch::cBinop_7lwXIGTz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_d6AenJG8, HV_BINOP_MIN, 0, m, &cBinop_d6AenJG8_sendMessage);
}

void Heavy_sequencerpatch::cCast_SR58XaOZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VRV3v9Lf, 0, m, &cVar_VRV3v9Lf_sendMessage);
}

void Heavy_sequencerpatch::cCast_qn6KlF9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7lwXIGTz_sendMessage);
}

void Heavy_sequencerpatch::cBinop_d6AenJG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_ICozAMIO, 0, m, &cTabread_ICozAMIO_sendMessage);
}

void Heavy_sequencerpatch::cMsg_eWxC1Q9o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Qi51En6h_sendMessage);
}

void Heavy_sequencerpatch::cBinop_TSMt1tq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_d6AenJG8, HV_BINOP_MIN, 1, m, &cBinop_d6AenJG8_sendMessage);
}

void Heavy_sequencerpatch::cTabwrite_jRYVpswG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cSwitchcase_QJtfSFp3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TG2UjY0z, 0, m, &cSlice_TG2UjY0z_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jRYVpswG, 0, m, &cTabwrite_jRYVpswG_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_TG2UjY0z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jRYVpswG, 2, m, &cTabwrite_jRYVpswG_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jRYVpswG, 2, m, &cTabwrite_jRYVpswG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_0kueEkUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ooyFBLqM, 0, m, &cPack_ooyFBLqM_sendMessage);
}

void Heavy_sequencerpatch::cPack_ooyFBLqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XZuNUcRe_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cVar_6NsnrJgp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_jJOSo1PW_sendMessage);
}

void Heavy_sequencerpatch::cSend_XZuNUcRe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_noteout", 0xD1D4AC2, m);
}

void Heavy_sequencerpatch::cBinop_jJOSo1PW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DCmwox3w_sendMessage);
}

void Heavy_sequencerpatch::cBinop_DCmwox3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ooyFBLqM, 2, m, &cPack_ooyFBLqM_sendMessage);
}

void Heavy_sequencerpatch::cCast_1JXk9tfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "got_loadbang");
  cSwitchcase_9GYCWzvI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cVar_1Q3Tokgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_jVCEaYKk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 30.0f, 0, m, &cBinop_D99UlnIn_sendMessage);
}

void Heavy_sequencerpatch::cVar_dxUn5LMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 32.0f, 0, m, &cBinop_ZuEae0TO_sendMessage);
}

void Heavy_sequencerpatch::cCast_VMhVUZ9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NqbtaWmv, 0, m, &cVar_NqbtaWmv_sendMessage);
}

void Heavy_sequencerpatch::cVar_0z5sHZlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_VfKtRn9w_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Q4mM85Z5, 0, m, &cIf_Q4mM85Z5_sendMessage);
}

void Heavy_sequencerpatch::cUnop_5lVGji2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_AT1Vwgid_sendMessage(_c, 0, m);
  cSend_T5WQjpIr_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cUnop_k0KHkan1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_AT1Vwgid_sendMessage(_c, 0, m);
  cSend_T5WQjpIr_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cIf_Q4mM85Z5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_k0KHkan1_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_5lVGji2w_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_VfKtRn9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Q4mM85Z5, 1, m, &cIf_Q4mM85Z5_sendMessage);
}

void Heavy_sequencerpatch::cVar_NqbtaWmv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JiM3NReI, HV_BINOP_ADD, 0, m, &cBinop_JiM3NReI_sendMessage);
}

void Heavy_sequencerpatch::cVar_NwHNu3jE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Xp1iqTAf, 0, m, &cPack_Xp1iqTAf_sendMessage);
}

void Heavy_sequencerpatch::cPack_Xp1iqTAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2qoVRIuY_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cVar_KLLgErbJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_F8Z62DDb_sendMessage);
}

void Heavy_sequencerpatch::cSend_2qoVRIuY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_noteout", 0xD1D4AC2, m);
}

void Heavy_sequencerpatch::cBinop_F8Z62DDb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_91qqY32I_sendMessage);
}

void Heavy_sequencerpatch::cBinop_91qqY32I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Xp1iqTAf, 2, m, &cPack_Xp1iqTAf_sendMessage);
}

void Heavy_sequencerpatch::cCast_SeBwtL85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JD8KBoMB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EShg3avm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_y3t9XHHS_sendMessage);
}

void Heavy_sequencerpatch::cVar_WfKtvQR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0kueEkUH, 1, m, &cVar_0kueEkUH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NwHNu3jE, 1, m, &cVar_NwHNu3jE_sendMessage);
  cPrint_onMessage(_c, m, "trigger_note");
}

void Heavy_sequencerpatch::cSwitchcase_jrt8kfzw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UMIacYuR, 0, m, &cSlice_UMIacYuR_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_e2q2UM0J, 0, m, &cRandom_e2q2UM0J_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cBinop_oXgGWBnh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_6cWcOxvQ_sendMessage);
}

void Heavy_sequencerpatch::cUnop_6cWcOxvQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m1EYHvHK, HV_BINOP_GREATER_THAN_EQL, 0, m, &cBinop_m1EYHvHK_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Rx58Wgkr, 0, m, &cIf_Rx58Wgkr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_a2LBUNVq, 0, m, &cVar_a2LBUNVq_sendMessage);
}

void Heavy_sequencerpatch::cRandom_e2q2UM0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_oXgGWBnh_sendMessage);
}

void Heavy_sequencerpatch::cSlice_UMIacYuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_e2q2UM0J, 1, m, &cRandom_e2q2UM0J_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cIf_Rx58Wgkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_508jYoA3_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3pQb5ooC_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7QsNNM85_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_X7XwlAwM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_m1EYHvHK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Rx58Wgkr, 1, m, &cIf_Rx58Wgkr_sendMessage);
}

void Heavy_sequencerpatch::cCast_HM9ftm2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_a2LBUNVq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cSwitchcase_RywFdWTk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ggyZhbAa_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ggyZhbAa_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_6OcDlbDF, 1, m, &cDelay_6OcDlbDF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UerklJen_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cDelay_6OcDlbDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6OcDlbDF, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z4C1sJ8M_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_r4qIRTKH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bdHRFJKy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LTCzfUaq_sendMessage);
}

void Heavy_sequencerpatch::cMsg_ggyZhbAa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_6OcDlbDF, 0, m, &cDelay_6OcDlbDF_sendMessage);
}

void Heavy_sequencerpatch::cCast_UerklJen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6OcDlbDF, 0, m, &cDelay_6OcDlbDF_sendMessage);
}

void Heavy_sequencerpatch::cVar_2YfEUZZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_569nSxZ8_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cVar_dlDAo84t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_569nSxZ8_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSwitchcase_9GYCWzvI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_uqWZPzQk_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_uqWZPzQk_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Kp8PSUUu, 1, m, &cDelay_Kp8PSUUu_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9Ndstogj_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cDelay_Kp8PSUUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Kp8PSUUu, m);
  cMsg_cJP01Y26_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_uqWZPzQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kp8PSUUu, 0, m, &cDelay_Kp8PSUUu_sendMessage);
}

void Heavy_sequencerpatch::cCast_9Ndstogj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Kp8PSUUu, 0, m, &cDelay_Kp8PSUUu_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_mFOzOYEm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rVG8edGM, 0, m, &cSlice_rVG8edGM_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jUxHFgYq, 0, m, &cSlice_jUxHFgYq_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_71e8KdhT, 0, m, &cSlice_71e8KdhT_sendMessage);
      break;
    }
    default: {
      cPrint_onMessage(_c, m, "got_unhandled_knob_index");
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_rVG8edGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TN3amiBI_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DMu9DUTF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HhyxrnpG_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TN3amiBI_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DMu9DUTF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HhyxrnpG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cSlice_jUxHFgYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5SckXBbv_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oW0GzJIC_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EzvIh5w7_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5SckXBbv_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oW0GzJIC_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EzvIh5w7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cSlice_71e8KdhT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_t4DZMO7L_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qlz1IfLM_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lHA9ehFu_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_t4DZMO7L_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qlz1IfLM_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lHA9ehFu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_OKLfmc7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DxHvhGIH, 1, m, &cVar_DxHvhGIH_sendMessage);
}

void Heavy_sequencerpatch::cMsg_Dbv3vcTz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_DxHvhGIH, 0, m, &cVar_DxHvhGIH_sendMessage);
}

void Heavy_sequencerpatch::cMsg_e2SUpWso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_lZ2sUHBf, 0, m, &cVar_lZ2sUHBf_sendMessage);
}

void Heavy_sequencerpatch::cCast_TN3amiBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5W2ZLuBf, 0, m, &cVar_5W2ZLuBf_sendMessage);
}

void Heavy_sequencerpatch::cCast_HhyxrnpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HabthaiE_sendMessage);
}

void Heavy_sequencerpatch::cCast_DMu9DUTF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_oW0GzJIC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_5SckXBbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z2ZD9cvG, 0, m, &cVar_Z2ZD9cvG_sendMessage);
}

void Heavy_sequencerpatch::cCast_EzvIh5w7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qpkb6KzX_sendMessage);
}

void Heavy_sequencerpatch::cBinop_CotknhtA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nd9AGDGl, 0, m, &cVar_nd9AGDGl_sendMessage);
}

void Heavy_sequencerpatch::cBinop_1s9XG3gP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ed9Qv6IC, 0, m, &cVar_ed9Qv6IC_sendMessage);
}

void Heavy_sequencerpatch::cBinop_nFM9CAG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_57BdG3Zv_sendMessage);
}

void Heavy_sequencerpatch::cBinop_57BdG3Zv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XazeMUyH, 0, m, &cVar_XazeMUyH_sendMessage);
}

void Heavy_sequencerpatch::cBinop_mbvUBcwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KqKdrQuk, 0, m, &cVar_KqKdrQuk_sendMessage);
}

void Heavy_sequencerpatch::cBinop_vXtyMUDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 80.0f, 0, m, &cBinop_mbvUBcwn_sendMessage);
}

void Heavy_sequencerpatch::cCast_KGH1BHrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_Gyn2azdK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dlDAo84t, 0, m, &cVar_dlDAo84t_sendMessage);
}

void Heavy_sequencerpatch::cCast_EbCL1Lyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_rXZEEH4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_yDX38Ufs_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_zmkgv4a6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cCast_FH51RExO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_trxNycyA_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_Wi4Lxf6x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_6uf7qPkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_6C9GngeU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lqG4cVa5_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_t4DZMO7L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jVCEaYKk, 0, m, &cVar_jVCEaYKk_sendMessage);
}

void Heavy_sequencerpatch::cCast_lHA9ehFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VMhVUZ9u_sendMessage);
}

void Heavy_sequencerpatch::cCast_qlz1IfLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cBinop_JiM3NReI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dxUn5LMw, 0, m, &cVar_dxUn5LMw_sendMessage);
}

void Heavy_sequencerpatch::cBinop_ZuEae0TO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_Y5m3CzU5_sendMessage);
}

void Heavy_sequencerpatch::cBinop_Y5m3CzU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0z5sHZlx, 0, m, &cVar_0z5sHZlx_sendMessage);
}

void Heavy_sequencerpatch::cCast_DfSBJUZI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uZmcSASI_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_dGwZO9o6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RywFdWTk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cCast_OOyVeKvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1oKS66dN_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_KwR8996p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0kueEkUH, 0, m, &cVar_0kueEkUH_sendMessage);
}

void Heavy_sequencerpatch::cCast_bdHRFJKy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NwHNu3jE, 0, m, &cVar_NwHNu3jE_sendMessage);
}

void Heavy_sequencerpatch::cCast_r4qIRTKH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J4bF9XHy_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_LTCzfUaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_Z4C1sJ8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5cbW2F3C_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_J4bF9XHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_Xp1iqTAf, 1, m, &cPack_Xp1iqTAf_sendMessage);
}

void Heavy_sequencerpatch::cMsg_uZmcSASI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_ooyFBLqM, 1, m, &cPack_ooyFBLqM_sendMessage);
}

void Heavy_sequencerpatch::cMsg_1oKS66dN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_6NsnrJgp, 0, m, &cVar_6NsnrJgp_sendMessage);
}

void Heavy_sequencerpatch::cMsg_5cbW2F3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_KLLgErbJ, 0, m, &cVar_KLLgErbJ_sendMessage);
}

void Heavy_sequencerpatch::cCast_EShg3avm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_JD8KBoMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WfKtvQR8, 0, m, &cVar_WfKtvQR8_sendMessage);
}

void Heavy_sequencerpatch::cCast_y3t9XHHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OOyVeKvu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DfSBJUZI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KwR8996p_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dGwZO9o6_sendMessage);
}

void Heavy_sequencerpatch::cCast_Hck9eFlK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jrt8kfzw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cCast_5s1iqmyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m1EYHvHK, HV_BINOP_GREATER_THAN_EQL, 1, m, &cBinop_m1EYHvHK_sendMessage);
}

void Heavy_sequencerpatch::cCast_Pa3RUMOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_OXRpbNcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HM9ftm2x_sendMessage);
}

void Heavy_sequencerpatch::cCast_7QsNNM85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_3pQb5ooC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_X7XwlAwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SeBwtL85_sendMessage);
}

void Heavy_sequencerpatch::cCast_508jYoA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cMsg_lqG4cVa5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "all-off");
  cSend_VnekL1Rd_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cBinop_rvaTXq9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_N0IGDpkg, 0, m, &cVar_N0IGDpkg_sendMessage);
}

void Heavy_sequencerpatch::cSend_VnekL1Rd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "tbd_stepled", 0xBD7A3EC7, m);
}

void Heavy_sequencerpatch::cSend_PSYmqHrq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Vina7Vm1_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSend_AT1Vwgid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Vina7Vm1_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSend_Y3xvR11l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KoXZPZUY_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_cJP01Y26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  cSend_PSYmqHrq_sendMessage(_c, 0, m);
  cSend_Y3xvR11l_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cBinop_D99UlnIn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JiM3NReI, HV_BINOP_ADD, 1, m, &cBinop_JiM3NReI_sendMessage);
}

void Heavy_sequencerpatch::cBinop_MXCgl1uD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1s9XG3gP, HV_BINOP_ADD, 1, m, &cBinop_1s9XG3gP_sendMessage);
}

void Heavy_sequencerpatch::cBinop_iTwjpAix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CotknhtA, HV_BINOP_ADD, 1, m, &cBinop_CotknhtA_sendMessage);
}

void Heavy_sequencerpatch::cSend_T5WQjpIr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_KoXZPZUY_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_569nSxZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "rgb");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setFloat(m, 2, 255.0f);
  msg_setFloat(m, 3, 255.0f);
  msg_setFloat(m, 4, 255.0f);
  cSend_VnekL1Rd_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_trxNycyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(4);
  msg_init(m, 4, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "all-rgb");
  msg_setFloat(m, 1, 0.0f);
  msg_setFloat(m, 2, 0.0f);
  msg_setFloat(m, 3, 10.0f);
  cSend_VnekL1Rd_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cReceive_g8PBp44Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_32uIaiWG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_taCLOZFO, 0, m, &cVar_taCLOZFO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6NsnrJgp, 0, m, &cVar_6NsnrJgp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KLLgErbJ, 0, m, &cVar_KLLgErbJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FLlKsUNi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1JXk9tfP_sendMessage);
}

void Heavy_sequencerpatch::cReceive_KoXZPZUY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NqbtaWmv, 1, m, &cVar_NqbtaWmv_sendMessage);
}

void Heavy_sequencerpatch::cReceive_Vina7Vm1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_taCLOZFO, 0, m, &cVar_taCLOZFO_sendMessage);
  cPrint_onMessage(_c, m, "set_tempo");
}

void Heavy_sequencerpatch::cReceive_HLIH7wrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JrM3lyDT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cReceive_JEt1nX5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_UXE0hocg_onMessage(_c, NULL, 0, m, NULL);
}




/*
 * Context Process Implementation
 */

int Heavy_sequencerpatch::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }

  sendBangToReceiver(0xDD21C0EB); // send to __hv_bang~ on next cycle
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars

  // input and output vars

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    

    // process all signal functions

    // save output vars to output buffer
    // no output channels
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_sequencerpatch::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 0 channel(s)
  float **const bOut = NULL;

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_sequencerpatch::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 0 channel(s)
  float *const bOut = NULL;

  int n = processInline(bIn, bOut, n4);

  

  return n;
}
