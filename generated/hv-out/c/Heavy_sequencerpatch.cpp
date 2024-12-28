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

float hTable_GmqfX3Sf_data[32] = {49.0f, 47.979f, 79.0f, 80.0f, 45.0f, 57.0f, 9.98214f, 43.445f, 76.2008f, 58.9658f, 47.0f, 37.1953f, 3.63241f, 11.7963f, 23.5887f, 35.3811f, 56.2445f, 60.78f, 88.9002f, 99.7855f, 109.764f, 44.313f, 35.3811f, 48.9876f, 56.2445f, 70.7581f, 81.6434f, -0.903114f, 14.5177f, 21.7745f, 29.0313f, 41.7308f};
float hTable_S4AfvaKv_data[32] = {101.0f, 86.0f, 70.0f, 56.0f, 39.0f, 5.0f, 0.0f, 1.0f, 0.0f, -1.0f, -2.0f, -1.0f, -1.0f, -1.0f, -2.0f, 6.0f, 17.0f, 27.0f, 35.0f, 47.0f, 59.0f, 73.0f, 90.0f, 96.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f};



/*
 * Class Functions
 */

Heavy_sequencerpatch::Heavy_sequencerpatch(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += hTable_initWithData(&hTable_GmqfX3Sf, 32, hTable_GmqfX3Sf_data);
  numBytes += cVar_init_f(&cVar_rgmLjZwC, 0.0f);
  numBytes += cVar_init_f(&cVar_zihicSa5, 0.0f);
  numBytes += cVar_init_f(&cVar_WLhoj1fS, 0.0f);
  numBytes += cVar_init_f(&cVar_CIvaH6Xt, 1.0f);
  numBytes += cVar_init_f(&cVar_dzYqXtit, 0.0f);
  numBytes += cDelay_init(this, &cDelay_wV0js4yT, 0.0f);
  numBytes += cVar_init_f(&cVar_EsgLwwcw, 250.0f);
  numBytes += cBinop_init(&cBinop_kkLnmJKT, 0.0f); // __mul
  numBytes += hTable_initWithData(&hTable_S4AfvaKv, 32, hTable_S4AfvaKv_data);
  numBytes += cVar_init_f(&cVar_nmG5uJFI, 0.0f);
  numBytes += cTabread_init(&cTabread_HtPaQIRk, &hTable_S4AfvaKv); // trigchance
  numBytes += cSlice_init(&cSlice_hqzzmWBc, 1, -1);
  numBytes += cVar_init_s(&cVar_vyKJU34l, "trigchance");
  numBytes += cBinop_init(&cBinop_SFaHwndt, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_C3W6ayXd, &hTable_GmqfX3Sf); // note
  numBytes += cSlice_init(&cSlice_OepYDrb0, 1, -1);
  numBytes += cVar_init_s(&cVar_hd53z7Ag, "note");
  numBytes += cBinop_init(&cBinop_SFTv4cPR, 0.0f); // __min
  numBytes += cSlice_init(&cSlice_U3lurAES, 1, -1);
  numBytes += cSlice_init(&cSlice_xJhPyR51, 1, -1);
  numBytes += cVar_init_f(&cVar_bNErEauk, 0.0f);
  numBytes += cTabread_init(&cTabread_pD90GbDc, &hTable_GmqfX3Sf); // note
  numBytes += cSlice_init(&cSlice_6LTY3Te9, 1, -1);
  numBytes += cVar_init_s(&cVar_HhPead0O, "note");
  numBytes += cBinop_init(&cBinop_m8AjolRk, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_ibIt33KH, &hTable_GmqfX3Sf); // note
  numBytes += cSlice_init(&cSlice_MyFZJgi1, 1, -1);
  numBytes += cVar_init_f(&cVar_0YB8RcD3, 0.0f);
  numBytes += cVar_init_f(&cVar_LI6IQVzv, 0.0f);
  numBytes += cVar_init_f(&cVar_JCf1kr3y, 0.0f);
  numBytes += cVar_init_f(&cVar_EFC1jlke, 0.0f);
  numBytes += cVar_init_f(&cVar_XFOJmNhz, 0.0f);
  numBytes += cVar_init_f(&cVar_Ers4jeqz, 0.0f);
  numBytes += cIf_init(&cIf_y0zqoypE, false);
  numBytes += cVar_init_f(&cVar_MtgxewzT, 0.0f);
  numBytes += cVar_init_f(&cVar_OHXHY736, 0.0f);
  numBytes += cVar_init_f(&cVar_CnizmcPj, 0.0f);
  numBytes += cVar_init_f(&cVar_hte3GZa9, 0.0f);
  numBytes += cIf_init(&cIf_ckwmpUHC, false);
  numBytes += cTabread_init(&cTabread_5W5xjMI7, &hTable_S4AfvaKv); // trigchance
  numBytes += cSlice_init(&cSlice_VfbpkdnP, 1, -1);
  numBytes += cVar_init_s(&cVar_mcPi5qJ2, "trigchance");
  numBytes += cBinop_init(&cBinop_N1sHZ3yj, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_5ZJdzTDJ, &hTable_S4AfvaKv); // trigchance
  numBytes += cSlice_init(&cSlice_zsBDMpQ6, 1, -1);
  numBytes += cVar_init_f(&cVar_EEZjMwjA, 0.0f);
  numBytes += cPack_init(&cPack_KdVFCpcx, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_F7kwKqQV, 0.0f);
  numBytes += cVar_init_f(&cVar_X5yEYxyt, 0.0f);
  numBytes += cVar_init_f(&cVar_fYP0iyjD, 0.0f);
  numBytes += cVar_init_f(&cVar_FDktYvog, 0.0f);
  numBytes += cVar_init_f(&cVar_unxifVQb, 0.0f);
  numBytes += cIf_init(&cIf_JcGDgsKB, false);
  numBytes += cVar_init_f(&cVar_UHbgMKpz, 0.0f);
  numBytes += cVar_init_f(&cVar_E7PcBy1t, 0.0f);
  numBytes += cPack_init(&cPack_Bob4VMdF, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_gndyYThO, 0.0f);
  numBytes += cVar_init_f(&cVar_llcyckDa, 0.0f);
  numBytes += cRandom_init(&cRandom_CeTQ9AO2, -1875753640);
  numBytes += cSlice_init(&cSlice_sAfxc88v, 1, 1);
  numBytes += cIf_init(&cIf_sKcRT1yq, false);
  numBytes += cBinop_init(&cBinop_nV2L9AUe, 0.0f); // __gte
  numBytes += cVar_init_f(&cVar_pu0o1vGK, 0.0f);
  numBytes += cDelay_init(this, &cDelay_21cfdmLd, 25.0f);
  numBytes += cVar_init_f(&cVar_4mulQ024, 0.0f);
  numBytes += cVar_init_f(&cVar_XXFhSj4A, 0.0f);
  numBytes += cDelay_init(this, &cDelay_TORmzKt2, 10.0f);
  numBytes += cSlice_init(&cSlice_zsQ3qlmX, 1, -1);
  numBytes += cSlice_init(&cSlice_Vyh4Of1i, 1, -1);
  numBytes += cSlice_init(&cSlice_GUCUQhhV, 1, -1);
  numBytes += cBinop_init(&cBinop_rejwkArX, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Ak9rzKYD, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_wEkybrL1, 0.0f); // __add
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_sequencerpatch::~Heavy_sequencerpatch() {
  hTable_free(&hTable_GmqfX3Sf);
  hTable_free(&hTable_S4AfvaKv);
  cPack_free(&cPack_KdVFCpcx);
  cPack_free(&cPack_Bob4VMdF);
}

HvTable *Heavy_sequencerpatch::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x6E3449A8: return &hTable_GmqfX3Sf; // note
    case 0x98FB22EB: return &hTable_S4AfvaKv; // trigchance
    default: return nullptr;
  }
}

void Heavy_sequencerpatch::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NJXgpa2E_sendMessage);
      break;
    }
    case 0x88E4D7C8: { // set-tempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LNjN222q_sendMessage);
      break;
    }
    case 0x559B0855: { // tbd_knob
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fpKSJS03_sendMessage);
      break;
    }
    case 0xBD433D4B: { // tbd_step
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wqYlfae1_sendMessage);
      break;
    }
    case 0x26682824: { // tempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3xJ9hNKI_sendMessage);
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


void Heavy_sequencerpatch::hTable_GmqfX3Sf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_rgmLjZwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zihicSa5, 0, m, &cVar_zihicSa5_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_3LTuSEQi_sendMessage);
}

void Heavy_sequencerpatch::cVar_zihicSa5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 16.0f, 0, m, &cBinop_mUoKhXJK_sendMessage);
}

void Heavy_sequencerpatch::cVar_WLhoj1fS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BdSwn9y0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tU8mTOjB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ytdSAgCN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u0pCdhgB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PQ4O5Hmw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8xSM2Qua_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eidbBrbu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Rabaozrk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XXFhSj4A, 1, m, &cVar_XXFhSj4A_sendMessage);
}

void Heavy_sequencerpatch::cCast_hDnRfkW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Fj9nd08b_sendMessage(_c, 0, m);
  cMsg_gk3p16Zd_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_vq0Bzx0z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rgmLjZwC, 0, m, &cVar_rgmLjZwC_sendMessage);
}

void Heavy_sequencerpatch::cVar_CIvaH6Xt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_QH89MGaT_sendMessage);
  cSwitchcase_KMpuIeRA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cBinop_QH89MGaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CIvaH6Xt, 1, m, &cVar_CIvaH6Xt_sendMessage);
}

void Heavy_sequencerpatch::cVar_dzYqXtit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_llcyckDa, 1, m, &cVar_llcyckDa_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_KMpuIeRA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_bPcdt4ZS_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_bPcdt4ZS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oR753RtI_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cDelay_wV0js4yT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wV0js4yT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wV0js4yT, 0, m, &cDelay_wV0js4yT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vq0Bzx0z_sendMessage);
}

void Heavy_sequencerpatch::cCast_oR753RtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bPcdt4ZS_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wV0js4yT, 0, m, &cDelay_wV0js4yT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vq0Bzx0z_sendMessage);
}

void Heavy_sequencerpatch::cMsg_sFJubnyF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GcGfnZQs_sendMessage);
}

void Heavy_sequencerpatch::cSystem_GcGfnZQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jfMzfRnw_sendMessage);
}

void Heavy_sequencerpatch::cVar_EsgLwwcw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kkLnmJKT, HV_BINOP_MULTIPLY, 0, m, &cBinop_kkLnmJKT_sendMessage);
}

void Heavy_sequencerpatch::cMsg_bPcdt4ZS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wV0js4yT, 0, m, &cDelay_wV0js4yT_sendMessage);
}

void Heavy_sequencerpatch::cBinop_1Fnj0dDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wV0js4yT, 2, m, &cDelay_wV0js4yT_sendMessage);
}

void Heavy_sequencerpatch::cBinop_jfMzfRnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kkLnmJKT, HV_BINOP_MULTIPLY, 1, m, &cBinop_kkLnmJKT_sendMessage);
}

void Heavy_sequencerpatch::cBinop_kkLnmJKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_1Fnj0dDW_sendMessage);
}

void Heavy_sequencerpatch::hTable_S4AfvaKv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_nmG5uJFI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cTabread_HtPaQIRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nmG5uJFI, 0, m, &cVar_nmG5uJFI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_G5sQtUiZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BzGWqpNj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UBBfjOAA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GWisDcpy_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_wLq4jCpN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hqzzmWBc, 0, m, &cSlice_hqzzmWBc_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fmEqhLK5_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Y3u3rpIn_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_hqzzmWBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_HtPaQIRk, 1, m, &cTabread_HtPaQIRk_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_HtPaQIRk, 1, m, &cTabread_HtPaQIRk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_vyKJU34l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AKVnJyM4_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_6D9q1YnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ITeVIP8j_sendMessage);
}

void Heavy_sequencerpatch::cBinop_usHcKYkn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SFaHwndt, HV_BINOP_MIN, 0, m, &cBinop_SFaHwndt_sendMessage);
}

void Heavy_sequencerpatch::cCast_Y3u3rpIn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_usHcKYkn_sendMessage);
}

void Heavy_sequencerpatch::cCast_fmEqhLK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vyKJU34l, 0, m, &cVar_vyKJU34l_sendMessage);
}

void Heavy_sequencerpatch::cBinop_SFaHwndt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_HtPaQIRk, 0, m, &cTabread_HtPaQIRk_sendMessage);
}

void Heavy_sequencerpatch::cMsg_AKVnJyM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6D9q1YnN_sendMessage);
}

void Heavy_sequencerpatch::cBinop_ITeVIP8j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SFaHwndt, HV_BINOP_MIN, 1, m, &cBinop_SFaHwndt_sendMessage);
}

void Heavy_sequencerpatch::cTabread_C3W6ayXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dzYqXtit, 0, m, &cVar_dzYqXtit_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_qUtK165W_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_OepYDrb0, 0, m, &cSlice_OepYDrb0_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CCFsQuXJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KsE6KarE_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_OepYDrb0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_C3W6ayXd, 1, m, &cTabread_C3W6ayXd_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_C3W6ayXd, 1, m, &cTabread_C3W6ayXd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_hd53z7Ag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1FimGY5K_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_PlLUdTFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_iWK5tY1m_sendMessage);
}

void Heavy_sequencerpatch::cBinop_wx0oRVcI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SFTv4cPR, HV_BINOP_MIN, 0, m, &cBinop_SFTv4cPR_sendMessage);
}

void Heavy_sequencerpatch::cCast_KsE6KarE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_wx0oRVcI_sendMessage);
}

void Heavy_sequencerpatch::cCast_CCFsQuXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hd53z7Ag, 0, m, &cVar_hd53z7Ag_sendMessage);
}

void Heavy_sequencerpatch::cBinop_SFTv4cPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_C3W6ayXd, 0, m, &cTabread_C3W6ayXd_sendMessage);
}

void Heavy_sequencerpatch::cMsg_1FimGY5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PlLUdTFC_sendMessage);
}

void Heavy_sequencerpatch::cBinop_iWK5tY1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SFTv4cPR, HV_BINOP_MIN, 1, m, &cBinop_SFTv4cPR_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_xZQAe4IY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xCCBDDAC9: { // "turn"
      cSlice_onMessage(_c, &Context(_c)->cSlice_U3lurAES, 0, m, &cSlice_U3lurAES_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_U3lurAES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPrint_onMessage(_c, m, "got_turn");
      cSwitchcase_XhRHIPUJ_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      cPrint_onMessage(_c, m, "got_turn");
      cSwitchcase_XhRHIPUJ_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cSwitchcase_ZGaX6txO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xCEF0717E: { // "press"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xJhPyR51, 0, m, &cSlice_xJhPyR51_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_xJhPyR51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_bNErEauk, 0, m, &cVar_bNErEauk_sendMessage);
      cPrint_onMessage(_c, m, "got_step_press");
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_bNErEauk, 0, m, &cVar_bNErEauk_sendMessage);
      cPrint_onMessage(_c, m, "got_step_press");
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_bNErEauk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0YB8RcD3, 1, m, &cVar_0YB8RcD3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MtgxewzT, 1, m, &cVar_MtgxewzT_sendMessage);
}

void Heavy_sequencerpatch::cTabread_pD90GbDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LI6IQVzv, 0, m, &cVar_LI6IQVzv_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_Ss57MTC7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6LTY3Te9, 0, m, &cSlice_6LTY3Te9_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bEbHNJmV_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XxciclGI_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_6LTY3Te9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_pD90GbDc, 1, m, &cTabread_pD90GbDc_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_pD90GbDc, 1, m, &cTabread_pD90GbDc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_HhPead0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_heI9Ak2Q_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_ZngkfZ8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_NXLc2xm5_sendMessage);
}

void Heavy_sequencerpatch::cBinop_kFYvmGfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m8AjolRk, HV_BINOP_MIN, 0, m, &cBinop_m8AjolRk_sendMessage);
}

void Heavy_sequencerpatch::cCast_XxciclGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kFYvmGfp_sendMessage);
}

void Heavy_sequencerpatch::cCast_bEbHNJmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HhPead0O, 0, m, &cVar_HhPead0O_sendMessage);
}

void Heavy_sequencerpatch::cBinop_m8AjolRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_pD90GbDc, 0, m, &cTabread_pD90GbDc_sendMessage);
}

void Heavy_sequencerpatch::cMsg_heI9Ak2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZngkfZ8K_sendMessage);
}

void Heavy_sequencerpatch::cBinop_NXLc2xm5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m8AjolRk, HV_BINOP_MIN, 1, m, &cBinop_m8AjolRk_sendMessage);
}

void Heavy_sequencerpatch::cTabwrite_ibIt33KH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cSwitchcase_q3X3UNXy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MyFZJgi1, 0, m, &cSlice_MyFZJgi1_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_ibIt33KH, 0, m, &cTabwrite_ibIt33KH_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_MyFZJgi1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_ibIt33KH, 2, m, &cTabwrite_ibIt33KH_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_ibIt33KH, 2, m, &cTabwrite_ibIt33KH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_0YB8RcD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Ss57MTC7_onMessage(_c, NULL, 0, m, NULL);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_ibIt33KH, 1, m, &cTabwrite_ibIt33KH_sendMessage);
}

void Heavy_sequencerpatch::cVar_LI6IQVzv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rejwkArX, HV_BINOP_ADD, 0, m, &cBinop_rejwkArX_sendMessage);
}

void Heavy_sequencerpatch::cVar_JCf1kr3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 12.0f, 0, m, &cBinop_jHvTJ8zW_sendMessage);
}

void Heavy_sequencerpatch::cCast_GmJ6jkkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0YB8RcD3, 0, m, &cVar_0YB8RcD3_sendMessage);
}

void Heavy_sequencerpatch::cVar_EFC1jlke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 30.0f, 0, m, &cBinop_EfuDaKIB_sendMessage);
}

void Heavy_sequencerpatch::cVar_XFOJmNhz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 30.0f, 0, m, &cBinop_lQHMVL7G_sendMessage);
}

void Heavy_sequencerpatch::cVar_Ers4jeqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_yFIFIxLm_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_y0zqoypE, 0, m, &cIf_y0zqoypE_sendMessage);
}

void Heavy_sequencerpatch::cUnop_jV90fprf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_q3X3UNXy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cUnop_sKz9rOl8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_q3X3UNXy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cIf_y0zqoypE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_sKz9rOl8_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jV90fprf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_yFIFIxLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_y0zqoypE, 1, m, &cIf_y0zqoypE_sendMessage);
}

void Heavy_sequencerpatch::cVar_MtgxewzT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_AvgSPszs_onMessage(_c, NULL, 0, m, NULL);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_5ZJdzTDJ, 1, m, &cTabwrite_5ZJdzTDJ_sendMessage);
}

void Heavy_sequencerpatch::cVar_OHXHY736_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ak9rzKYD, HV_BINOP_ADD, 0, m, &cBinop_Ak9rzKYD_sendMessage);
}

void Heavy_sequencerpatch::cVar_CnizmcPj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_iQs8bIcH_sendMessage);
}

void Heavy_sequencerpatch::cCast_WkOvU4ih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MtgxewzT, 0, m, &cVar_MtgxewzT_sendMessage);
}

void Heavy_sequencerpatch::cVar_hte3GZa9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_7MkhxG83_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ckwmpUHC, 0, m, &cIf_ckwmpUHC_sendMessage);
}

void Heavy_sequencerpatch::cUnop_OkSvldZz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qaVo7i4N_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cUnop_CAXQnD3a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qaVo7i4N_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cIf_ckwmpUHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_CAXQnD3a_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_OkSvldZz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_7MkhxG83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ckwmpUHC, 1, m, &cIf_ckwmpUHC_sendMessage);
}

void Heavy_sequencerpatch::cTabread_5W5xjMI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OHXHY736, 0, m, &cVar_OHXHY736_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_AvgSPszs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VfbpkdnP, 0, m, &cSlice_VfbpkdnP_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_068oI7RJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ojktAK6X_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_VfbpkdnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_5W5xjMI7, 1, m, &cTabread_5W5xjMI7_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_5W5xjMI7, 1, m, &cTabread_5W5xjMI7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_mcPi5qJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1LcUrkg0_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_CFGDNhNk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_wC3WOH5u_sendMessage);
}

void Heavy_sequencerpatch::cBinop_r5K2vv46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N1sHZ3yj, HV_BINOP_MIN, 0, m, &cBinop_N1sHZ3yj_sendMessage);
}

void Heavy_sequencerpatch::cCast_ojktAK6X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_r5K2vv46_sendMessage);
}

void Heavy_sequencerpatch::cCast_068oI7RJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mcPi5qJ2, 0, m, &cVar_mcPi5qJ2_sendMessage);
}

void Heavy_sequencerpatch::cBinop_N1sHZ3yj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_5W5xjMI7, 0, m, &cTabread_5W5xjMI7_sendMessage);
}

void Heavy_sequencerpatch::cMsg_1LcUrkg0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CFGDNhNk_sendMessage);
}

void Heavy_sequencerpatch::cBinop_wC3WOH5u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N1sHZ3yj, HV_BINOP_MIN, 1, m, &cBinop_N1sHZ3yj_sendMessage);
}

void Heavy_sequencerpatch::cTabwrite_5ZJdzTDJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cSwitchcase_qaVo7i4N_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zsBDMpQ6, 0, m, &cSlice_zsBDMpQ6_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_5ZJdzTDJ, 0, m, &cTabwrite_5ZJdzTDJ_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_zsBDMpQ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_5ZJdzTDJ, 2, m, &cTabwrite_5ZJdzTDJ_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_5ZJdzTDJ, 2, m, &cTabwrite_5ZJdzTDJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_EEZjMwjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KdVFCpcx, 0, m, &cPack_KdVFCpcx_sendMessage);
}

void Heavy_sequencerpatch::cPack_KdVFCpcx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_m98fhTUd_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cVar_F7kwKqQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_CT9kTpB5_sendMessage);
}

void Heavy_sequencerpatch::cSend_m98fhTUd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_noteout", 0xD1D4AC2, m);
}

void Heavy_sequencerpatch::cBinop_CT9kTpB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OnULMUzo_sendMessage);
}

void Heavy_sequencerpatch::cBinop_OnULMUzo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KdVFCpcx, 2, m, &cPack_KdVFCpcx_sendMessage);
}

void Heavy_sequencerpatch::cCast_EFuhLbMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "got_loadbang");
  cSwitchcase_YOZYbuuZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cVar_X5yEYxyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_fYP0iyjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 30.0f, 0, m, &cBinop_vHD40aG7_sendMessage);
}

void Heavy_sequencerpatch::cVar_FDktYvog_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 32.0f, 0, m, &cBinop_1lASdqrD_sendMessage);
}

void Heavy_sequencerpatch::cCast_6AjDyZV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UHbgMKpz, 0, m, &cVar_UHbgMKpz_sendMessage);
}

void Heavy_sequencerpatch::cVar_unxifVQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_afK5iFF0_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_JcGDgsKB, 0, m, &cIf_JcGDgsKB_sendMessage);
}

void Heavy_sequencerpatch::cUnop_fLbg0YVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_8Z0hZqWM_sendMessage(_c, 0, m);
  cSend_mc3l1Jdi_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cUnop_BlgLNNOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_8Z0hZqWM_sendMessage(_c, 0, m);
  cSend_mc3l1Jdi_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cIf_JcGDgsKB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_BlgLNNOn_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_fLbg0YVS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_afK5iFF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JcGDgsKB, 1, m, &cIf_JcGDgsKB_sendMessage);
}

void Heavy_sequencerpatch::cVar_UHbgMKpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wEkybrL1, HV_BINOP_ADD, 0, m, &cBinop_wEkybrL1_sendMessage);
}

void Heavy_sequencerpatch::cVar_E7PcBy1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Bob4VMdF, 0, m, &cPack_Bob4VMdF_sendMessage);
}

void Heavy_sequencerpatch::cPack_Bob4VMdF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nDe1Edph_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cVar_gndyYThO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_YNsZwu6V_sendMessage);
}

void Heavy_sequencerpatch::cSend_nDe1Edph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_noteout", 0xD1D4AC2, m);
}

void Heavy_sequencerpatch::cBinop_YNsZwu6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mLMYT8E8_sendMessage);
}

void Heavy_sequencerpatch::cBinop_mLMYT8E8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Bob4VMdF, 2, m, &cPack_Bob4VMdF_sendMessage);
}

void Heavy_sequencerpatch::cCast_quiTYbJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lg2lv8qH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gQtyTbpH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wxiQm5hO_sendMessage);
}

void Heavy_sequencerpatch::cVar_llcyckDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EEZjMwjA, 1, m, &cVar_EEZjMwjA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_E7PcBy1t, 1, m, &cVar_E7PcBy1t_sendMessage);
  cPrint_onMessage(_c, m, "trigger_note");
}

void Heavy_sequencerpatch::cSwitchcase_BiZ6Rqsg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_sAfxc88v, 0, m, &cSlice_sAfxc88v_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_CeTQ9AO2, 0, m, &cRandom_CeTQ9AO2_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cBinop_A6GdLCFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Zw74cSWL_sendMessage);
}

void Heavy_sequencerpatch::cUnop_Zw74cSWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nV2L9AUe, HV_BINOP_GREATER_THAN_EQL, 0, m, &cBinop_nV2L9AUe_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_sKcRT1yq, 0, m, &cIf_sKcRT1yq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pu0o1vGK, 0, m, &cVar_pu0o1vGK_sendMessage);
}

void Heavy_sequencerpatch::cRandom_CeTQ9AO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_A6GdLCFd_sendMessage);
}

void Heavy_sequencerpatch::cSlice_sAfxc88v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_CeTQ9AO2, 1, m, &cRandom_CeTQ9AO2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cIf_sKcRT1yq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_L2l4gppb_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_O8Ia9rvL_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qjRocwwA_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MggDiASk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_nV2L9AUe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sKcRT1yq, 1, m, &cIf_sKcRT1yq_sendMessage);
}

void Heavy_sequencerpatch::cCast_iPB76aSz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_pu0o1vGK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cSwitchcase_UuucGHDj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_WzDkvTuJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_WzDkvTuJ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_21cfdmLd, 1, m, &cDelay_21cfdmLd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xVmjTjE2_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cDelay_21cfdmLd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_21cfdmLd, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_864iPENE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wXl3g8kJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O5xSHnFM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S4NWKQe9_sendMessage);
}

void Heavy_sequencerpatch::cMsg_WzDkvTuJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_21cfdmLd, 0, m, &cDelay_21cfdmLd_sendMessage);
}

void Heavy_sequencerpatch::cCast_xVmjTjE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_21cfdmLd, 0, m, &cDelay_21cfdmLd_sendMessage);
}

void Heavy_sequencerpatch::cVar_4mulQ024_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Weyw58ro_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cVar_XXFhSj4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Weyw58ro_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSwitchcase_YOZYbuuZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Ty1ne8qi_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Ty1ne8qi_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TORmzKt2, 1, m, &cDelay_TORmzKt2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MWnpwQ0m_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cDelay_TORmzKt2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TORmzKt2, m);
  cMsg_f2EJ8L4z_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_Ty1ne8qi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TORmzKt2, 0, m, &cDelay_TORmzKt2_sendMessage);
}

void Heavy_sequencerpatch::cCast_MWnpwQ0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TORmzKt2, 0, m, &cDelay_TORmzKt2_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_XhRHIPUJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zsQ3qlmX, 0, m, &cSlice_zsQ3qlmX_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Vyh4Of1i, 0, m, &cSlice_Vyh4Of1i_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GUCUQhhV, 0, m, &cSlice_GUCUQhhV_sendMessage);
      break;
    }
    default: {
      cPrint_onMessage(_c, m, "got_unhandled_index");
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_zsQ3qlmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iazjZHmF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aS0WSJUj_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vV2Kpujk_sendMessage);
      cPrint_onMessage(_c, m, "got_route_0");
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iazjZHmF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aS0WSJUj_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vV2Kpujk_sendMessage);
      cPrint_onMessage(_c, m, "got_route_0");
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cSlice_Vyh4Of1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Tb37hAdY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iPBKdGK4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bvaBWuD6_sendMessage);
      cPrint_onMessage(_c, m, "got_route_1");
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Tb37hAdY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iPBKdGK4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bvaBWuD6_sendMessage);
      cPrint_onMessage(_c, m, "got_route_1");
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cSlice_GUCUQhhV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d5ZLTvxQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JtAOGY7b_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0gMDMIlc_sendMessage);
      cPrint_onMessage(_c, m, "got_route_2");
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d5ZLTvxQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JtAOGY7b_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0gMDMIlc_sendMessage);
      cPrint_onMessage(_c, m, "got_route_2");
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_3LTuSEQi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rgmLjZwC, 1, m, &cVar_rgmLjZwC_sendMessage);
}

void Heavy_sequencerpatch::cMsg_Fj9nd08b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_rgmLjZwC, 0, m, &cVar_rgmLjZwC_sendMessage);
}

void Heavy_sequencerpatch::cMsg_gk3p16Zd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_CIvaH6Xt, 0, m, &cVar_CIvaH6Xt_sendMessage);
}

void Heavy_sequencerpatch::cCast_vV2Kpujk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GmJ6jkkj_sendMessage);
}

void Heavy_sequencerpatch::cCast_aS0WSJUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_iazjZHmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EFC1jlke, 0, m, &cVar_EFC1jlke_sendMessage);
}

void Heavy_sequencerpatch::cCast_Tb37hAdY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XFOJmNhz, 0, m, &cVar_XFOJmNhz_sendMessage);
}

void Heavy_sequencerpatch::cCast_bvaBWuD6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WkOvU4ih_sendMessage);
}

void Heavy_sequencerpatch::cCast_iPBKdGK4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cBinop_rejwkArX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JCf1kr3y, 0, m, &cVar_JCf1kr3y_sendMessage);
}

void Heavy_sequencerpatch::cBinop_Ak9rzKYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CnizmcPj, 0, m, &cVar_CnizmcPj_sendMessage);
}

void Heavy_sequencerpatch::cBinop_iQs8bIcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_3if3tsMm_sendMessage);
}

void Heavy_sequencerpatch::cBinop_3if3tsMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hte3GZa9, 0, m, &cVar_hte3GZa9_sendMessage);
}

void Heavy_sequencerpatch::cBinop_nvpjcPpZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ers4jeqz, 0, m, &cVar_Ers4jeqz_sendMessage);
}

void Heavy_sequencerpatch::cBinop_jHvTJ8zW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 80.0f, 0, m, &cBinop_nvpjcPpZ_sendMessage);
}

void Heavy_sequencerpatch::cCast_BdSwn9y0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_wLq4jCpN_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_qUtK165W_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cCast_8xSM2Qua_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G2KBE6we_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_ytdSAgCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_Rabaozrk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_PQ4O5Hmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YkAJYm7w_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_tU8mTOjB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_eidbBrbu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XXFhSj4A, 0, m, &cVar_XXFhSj4A_sendMessage);
}

void Heavy_sequencerpatch::cCast_u0pCdhgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_0gMDMIlc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6AjDyZV6_sendMessage);
}

void Heavy_sequencerpatch::cCast_JtAOGY7b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_d5ZLTvxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fYP0iyjD, 0, m, &cVar_fYP0iyjD_sendMessage);
}

void Heavy_sequencerpatch::cBinop_wEkybrL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FDktYvog, 0, m, &cVar_FDktYvog_sendMessage);
}

void Heavy_sequencerpatch::cBinop_1lASdqrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_9YbaMkwK_sendMessage);
}

void Heavy_sequencerpatch::cBinop_9YbaMkwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_unxifVQb, 0, m, &cVar_unxifVQb_sendMessage);
}

void Heavy_sequencerpatch::cCast_rXneTsGS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NSNUo91e_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_R2pY5X00_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EEZjMwjA, 0, m, &cVar_EEZjMwjA_sendMessage);
}

void Heavy_sequencerpatch::cCast_UfJMkhGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3gTnD0ru_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_7FwlbE3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_UuucGHDj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cCast_wXl3g8kJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U7MzS8EM_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_S4NWKQe9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_864iPENE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dufHnPbj_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_O5xSHnFM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_E7PcBy1t, 0, m, &cVar_E7PcBy1t_sendMessage);
}

void Heavy_sequencerpatch::cMsg_U7MzS8EM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_Bob4VMdF, 1, m, &cPack_Bob4VMdF_sendMessage);
}

void Heavy_sequencerpatch::cMsg_3gTnD0ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_KdVFCpcx, 1, m, &cPack_KdVFCpcx_sendMessage);
}

void Heavy_sequencerpatch::cMsg_NSNUo91e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_F7kwKqQV, 0, m, &cVar_F7kwKqQV_sendMessage);
}

void Heavy_sequencerpatch::cMsg_dufHnPbj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_gndyYThO, 0, m, &cVar_gndyYThO_sendMessage);
}

void Heavy_sequencerpatch::cCast_lg2lv8qH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_llcyckDa, 0, m, &cVar_llcyckDa_sendMessage);
}

void Heavy_sequencerpatch::cCast_wxiQm5hO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rXneTsGS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UfJMkhGo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R2pY5X00_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7FwlbE3i_sendMessage);
}

void Heavy_sequencerpatch::cCast_gQtyTbpH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_G5sQtUiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nV2L9AUe, HV_BINOP_GREATER_THAN_EQL, 1, m, &cBinop_nV2L9AUe_sendMessage);
}

void Heavy_sequencerpatch::cCast_GWisDcpy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_UBBfjOAA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iPB76aSz_sendMessage);
}

void Heavy_sequencerpatch::cCast_BzGWqpNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BiZ6Rqsg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cCast_MggDiASk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_quiTYbJr_sendMessage);
}

void Heavy_sequencerpatch::cCast_L2l4gppb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_qjRocwwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_O8Ia9rvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cMsg_YkAJYm7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "all-off");
  cSend_TJNhJUY6_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_G2KBE6we_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(4);
  msg_init(m, 4, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "all-rgb");
  msg_setFloat(m, 1, 50.0f);
  msg_setFloat(m, 2, 30.0f);
  msg_setFloat(m, 3, 10.0f);
  cSend_TJNhJUY6_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cBinop_mUoKhXJK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WLhoj1fS, 0, m, &cVar_WLhoj1fS_sendMessage);
}

void Heavy_sequencerpatch::cMsg_Weyw58ro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "rgb");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setFloat(m, 2, 0.0f);
  msg_setFloat(m, 3, 255.0f);
  msg_setFloat(m, 4, 255.0f);
  cSend_TJNhJUY6_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSend_TJNhJUY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "tbd_stepled", 0xBD7A3EC7, m);
}

void Heavy_sequencerpatch::cSend_HGAmiwiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LNjN222q_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSend_8Z0hZqWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LNjN222q_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSend_eIvtgoqP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3xJ9hNKI_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_f2EJ8L4z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  cSend_HGAmiwiS_sendMessage(_c, 0, m);
  cSend_eIvtgoqP_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cBinop_vHD40aG7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wEkybrL1, HV_BINOP_ADD, 1, m, &cBinop_wEkybrL1_sendMessage);
}

void Heavy_sequencerpatch::cBinop_lQHMVL7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ak9rzKYD, HV_BINOP_ADD, 1, m, &cBinop_Ak9rzKYD_sendMessage);
}

void Heavy_sequencerpatch::cBinop_EfuDaKIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rejwkArX, HV_BINOP_ADD, 1, m, &cBinop_rejwkArX_sendMessage);
}

void Heavy_sequencerpatch::cSend_mc3l1Jdi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3xJ9hNKI_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cReceive_NJXgpa2E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sFJubnyF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EsgLwwcw, 0, m, &cVar_EsgLwwcw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_F7kwKqQV, 0, m, &cVar_F7kwKqQV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gndyYThO, 0, m, &cVar_gndyYThO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hDnRfkW1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EFuhLbMi_sendMessage);
}

void Heavy_sequencerpatch::cReceive_3xJ9hNKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UHbgMKpz, 1, m, &cVar_UHbgMKpz_sendMessage);
}

void Heavy_sequencerpatch::cReceive_LNjN222q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EsgLwwcw, 0, m, &cVar_EsgLwwcw_sendMessage);
  cPrint_onMessage(_c, m, "set_tempo");
}

void Heavy_sequencerpatch::cReceive_wqYlfae1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZGaX6txO_onMessage(_c, NULL, 0, m, NULL);
  cPrint_onMessage(_c, m, "got_tbd-step");
}

void Heavy_sequencerpatch::cReceive_fpKSJS03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xZQAe4IY_onMessage(_c, NULL, 0, m, NULL);
  cPrint_onMessage(_c, m, "got_tbd-knob");
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
