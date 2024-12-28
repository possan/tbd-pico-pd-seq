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

float hTable_KAgXbfUZ_data[32] = {49.0f, 47.979f, 79.0f, 80.0f, 45.0f, 57.0f, 9.98214f, 43.445f, 76.2008f, 58.9658f, 47.0f, 37.1953f, 3.63241f, 11.7963f, 23.5887f, 35.3811f, 56.2445f, 60.78f, 88.9002f, 99.7855f, 109.764f, 44.313f, 35.3811f, 48.9876f, 56.2445f, 70.7581f, 81.6434f, -0.903114f, 14.5177f, 21.7745f, 29.0313f, 41.7308f};
float hTable_p1NfyiQe_data[32] = {101.0f, 86.0f, 70.0f, 56.0f, 39.0f, 5.0f, 0.0f, 1.0f, 0.0f, -1.0f, -2.0f, -1.0f, -1.0f, -1.0f, -2.0f, 6.0f, 17.0f, 27.0f, 35.0f, 47.0f, 59.0f, 73.0f, 90.0f, 96.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f};



/*
 * Class Functions
 */

Heavy_sequencerpatch::Heavy_sequencerpatch(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += hTable_initWithData(&hTable_KAgXbfUZ, 32, hTable_KAgXbfUZ_data);
  numBytes += cVar_init_f(&cVar_Y1EAI5L9, 0.0f);
  numBytes += cVar_init_f(&cVar_z4E8XBpq, 0.0f);
  numBytes += cVar_init_f(&cVar_cf13GXeB, 0.0f);
  numBytes += cVar_init_f(&cVar_51DKeBAv, 1.0f);
  numBytes += cVar_init_f(&cVar_x0o53eWP, 0.0f);
  numBytes += cDelay_init(this, &cDelay_0DnIf5NE, 0.0f);
  numBytes += cVar_init_f(&cVar_nAuvmxEB, 250.0f);
  numBytes += cBinop_init(&cBinop_wWffeYmm, 0.0f); // __mul
  numBytes += hTable_initWithData(&hTable_p1NfyiQe, 32, hTable_p1NfyiQe_data);
  numBytes += cVar_init_f(&cVar_2e1wJviR, 0.0f);
  numBytes += cTabread_init(&cTabread_nzOGcN2I, &hTable_p1NfyiQe); // trigchance
  numBytes += cSlice_init(&cSlice_fc4jptEf, 1, -1);
  numBytes += cVar_init_s(&cVar_ZoVXMn4m, "trigchance");
  numBytes += cBinop_init(&cBinop_yde2oXPP, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_lL3RZCns, &hTable_KAgXbfUZ); // note
  numBytes += cSlice_init(&cSlice_wAhxrrvV, 1, -1);
  numBytes += cVar_init_s(&cVar_FQui9nmg, "note");
  numBytes += cBinop_init(&cBinop_BNjJXV7v, 0.0f); // __min
  numBytes += cSlice_init(&cSlice_s9oZgM0N, 1, -1);
  numBytes += cSlice_init(&cSlice_axn6Ec17, 1, -1);
  numBytes += cVar_init_f(&cVar_FlYfEsMY, 0.0f);
  numBytes += cTabread_init(&cTabread_Q29MVnGm, &hTable_KAgXbfUZ); // note
  numBytes += cSlice_init(&cSlice_9WAywOgi, 1, -1);
  numBytes += cVar_init_s(&cVar_RCpE21qm, "note");
  numBytes += cBinop_init(&cBinop_jFFje3jp, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_pq4AEhYP, &hTable_KAgXbfUZ); // note
  numBytes += cSlice_init(&cSlice_76Kgx3D8, 1, -1);
  numBytes += cVar_init_f(&cVar_tMQQ9NCj, 0.0f);
  numBytes += cVar_init_f(&cVar_OJr9PpBk, 0.0f);
  numBytes += cVar_init_f(&cVar_crbF0t8G, 0.0f);
  numBytes += cVar_init_f(&cVar_SgWeKYcl, 0.0f);
  numBytes += cVar_init_f(&cVar_e73Zh2j2, 0.0f);
  numBytes += cVar_init_f(&cVar_LLJIDDYh, 0.0f);
  numBytes += cIf_init(&cIf_DoJXr5mR, false);
  numBytes += cVar_init_f(&cVar_z31PLJhl, 0.0f);
  numBytes += cVar_init_f(&cVar_XHYqQouM, 0.0f);
  numBytes += cVar_init_f(&cVar_gYGbW2Go, 0.0f);
  numBytes += cVar_init_f(&cVar_dbhCJN2v, 0.0f);
  numBytes += cIf_init(&cIf_qFqIZ0YL, false);
  numBytes += cTabread_init(&cTabread_69zFVHNd, &hTable_p1NfyiQe); // trigchance
  numBytes += cSlice_init(&cSlice_juHKZSSW, 1, -1);
  numBytes += cVar_init_s(&cVar_Vl3lIQOW, "trigchance");
  numBytes += cBinop_init(&cBinop_2H7vvJtm, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_zCDf0Qnm, &hTable_p1NfyiQe); // trigchance
  numBytes += cSlice_init(&cSlice_S8JqFPlR, 1, -1);
  numBytes += cVar_init_f(&cVar_Z2B0qLWD, 0.0f);
  numBytes += cPack_init(&cPack_IAVWnAo2, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_b1im11q1, 0.0f);
  numBytes += cVar_init_f(&cVar_qDxMgu1L, 0.0f);
  numBytes += cVar_init_f(&cVar_KxplVWAW, 0.0f);
  numBytes += cVar_init_f(&cVar_p3k38w8R, 0.0f);
  numBytes += cVar_init_f(&cVar_bTMyXveo, 0.0f);
  numBytes += cIf_init(&cIf_sdU8jrMs, false);
  numBytes += cVar_init_f(&cVar_MbX4a2A4, 0.0f);
  numBytes += cVar_init_f(&cVar_i6k0WNHT, 0.0f);
  numBytes += cPack_init(&cPack_qM7wNEV5, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_I6hyxGzG, 0.0f);
  numBytes += cVar_init_f(&cVar_vtiaG2gV, 0.0f);
  numBytes += cRandom_init(&cRandom_AK3up9D4, 730119775);
  numBytes += cSlice_init(&cSlice_Ax5gyJiM, 1, 1);
  numBytes += cIf_init(&cIf_CfkjHFbE, false);
  numBytes += cBinop_init(&cBinop_TV4wG2P0, 0.0f); // __gte
  numBytes += cVar_init_f(&cVar_EYbX4a1I, 0.0f);
  numBytes += cDelay_init(this, &cDelay_OsrhtCTO, 25.0f);
  numBytes += cVar_init_f(&cVar_JWDqwD6F, 0.0f);
  numBytes += cVar_init_f(&cVar_W0FnRGtb, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ffN7ZTAf, 10.0f);
  numBytes += cSlice_init(&cSlice_UHyu3CwE, 1, -1);
  numBytes += cSlice_init(&cSlice_Gik5ke51, 1, -1);
  numBytes += cSlice_init(&cSlice_J7tcr8kL, 1, -1);
  numBytes += cBinop_init(&cBinop_EbKF8RXC, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_HwRtST9Q, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_KW3nZbzw, 0.0f); // __add
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_sequencerpatch::~Heavy_sequencerpatch() {
  hTable_free(&hTable_KAgXbfUZ);
  hTable_free(&hTable_p1NfyiQe);
  cPack_free(&cPack_IAVWnAo2);
  cPack_free(&cPack_qM7wNEV5);
}

HvTable *Heavy_sequencerpatch::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x6E3449A8: return &hTable_KAgXbfUZ; // note
    case 0x98FB22EB: return &hTable_p1NfyiQe; // trigchance
    default: return nullptr;
  }
}

void Heavy_sequencerpatch::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PxDvQD1D_sendMessage);
      break;
    }
    case 0x88E4D7C8: { // set-tempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZQQRGLmm_sendMessage);
      break;
    }
    case 0x559B0855: { // tbd_knob
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_oztHXV6N_sendMessage);
      break;
    }
    case 0xBD433D4B: { // tbd_step
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JQ0iHymm_sendMessage);
      break;
    }
    case 0x26682824: { // tempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OGAOclV6_sendMessage);
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


void Heavy_sequencerpatch::hTable_KAgXbfUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_Y1EAI5L9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_z4E8XBpq, 0, m, &cVar_z4E8XBpq_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_HoMQwJwi_sendMessage);
}

void Heavy_sequencerpatch::cVar_z4E8XBpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 16.0f, 0, m, &cBinop_3ESGQyyA_sendMessage);
}

void Heavy_sequencerpatch::cVar_cf13GXeB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SmiitqoM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GVwsyx6m_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m5WIUOft_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6AMGxNNX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PStd28TH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_54KUQKNA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FriJnX9F_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m29cxGkl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_W0FnRGtb, 1, m, &cVar_W0FnRGtb_sendMessage);
}

void Heavy_sequencerpatch::cCast_1A567NWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lhSs3Tq3_sendMessage(_c, 0, m);
  cMsg_aNMr2VYl_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_lDdh0GE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y1EAI5L9, 0, m, &cVar_Y1EAI5L9_sendMessage);
}

void Heavy_sequencerpatch::cVar_51DKeBAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_eSm9spUm_sendMessage);
  cSwitchcase_5zI4rziq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cBinop_eSm9spUm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_51DKeBAv, 1, m, &cVar_51DKeBAv_sendMessage);
}

void Heavy_sequencerpatch::cVar_x0o53eWP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vtiaG2gV, 1, m, &cVar_vtiaG2gV_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_5zI4rziq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_O76OLNP4_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_O76OLNP4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iwlYdBbk_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cDelay_0DnIf5NE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0DnIf5NE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0DnIf5NE, 0, m, &cDelay_0DnIf5NE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lDdh0GE9_sendMessage);
}

void Heavy_sequencerpatch::cCast_iwlYdBbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O76OLNP4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0DnIf5NE, 0, m, &cDelay_0DnIf5NE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lDdh0GE9_sendMessage);
}

void Heavy_sequencerpatch::cMsg_6HYtSiW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EUIM7TB0_sendMessage);
}

void Heavy_sequencerpatch::cSystem_EUIM7TB0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_e0kByt6g_sendMessage);
}

void Heavy_sequencerpatch::cVar_nAuvmxEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wWffeYmm, HV_BINOP_MULTIPLY, 0, m, &cBinop_wWffeYmm_sendMessage);
}

void Heavy_sequencerpatch::cMsg_O76OLNP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_0DnIf5NE, 0, m, &cDelay_0DnIf5NE_sendMessage);
}

void Heavy_sequencerpatch::cBinop_vbbEi4Om_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0DnIf5NE, 2, m, &cDelay_0DnIf5NE_sendMessage);
}

void Heavy_sequencerpatch::cBinop_e0kByt6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wWffeYmm, HV_BINOP_MULTIPLY, 1, m, &cBinop_wWffeYmm_sendMessage);
}

void Heavy_sequencerpatch::cBinop_wWffeYmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_vbbEi4Om_sendMessage);
}

void Heavy_sequencerpatch::hTable_p1NfyiQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_2e1wJviR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cTabread_nzOGcN2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2e1wJviR, 0, m, &cVar_2e1wJviR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CoYbawf2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IpKM17dn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8TcE5Rgm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TbeQ06nD_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_KG3cjk54_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fc4jptEf, 0, m, &cSlice_fc4jptEf_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zbsJJW2h_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xIkB96OI_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_fc4jptEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_nzOGcN2I, 1, m, &cTabread_nzOGcN2I_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_nzOGcN2I, 1, m, &cTabread_nzOGcN2I_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_ZoVXMn4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wLbTaNUD_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_daclDU1j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_77kZI6aS_sendMessage);
}

void Heavy_sequencerpatch::cBinop_0z3kv3yW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yde2oXPP, HV_BINOP_MIN, 0, m, &cBinop_yde2oXPP_sendMessage);
}

void Heavy_sequencerpatch::cCast_zbsJJW2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZoVXMn4m, 0, m, &cVar_ZoVXMn4m_sendMessage);
}

void Heavy_sequencerpatch::cCast_xIkB96OI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0z3kv3yW_sendMessage);
}

void Heavy_sequencerpatch::cBinop_yde2oXPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_nzOGcN2I, 0, m, &cTabread_nzOGcN2I_sendMessage);
}

void Heavy_sequencerpatch::cMsg_wLbTaNUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_daclDU1j_sendMessage);
}

void Heavy_sequencerpatch::cBinop_77kZI6aS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yde2oXPP, HV_BINOP_MIN, 1, m, &cBinop_yde2oXPP_sendMessage);
}

void Heavy_sequencerpatch::cTabread_lL3RZCns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_x0o53eWP, 0, m, &cVar_x0o53eWP_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_9LadpbHx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_wAhxrrvV, 0, m, &cSlice_wAhxrrvV_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jaE1oO9v_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AojS3moi_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_wAhxrrvV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_lL3RZCns, 1, m, &cTabread_lL3RZCns_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_lL3RZCns, 1, m, &cTabread_lL3RZCns_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_FQui9nmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r6igu7Rb_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_UeaXAR1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TC1bR67k_sendMessage);
}

void Heavy_sequencerpatch::cBinop_Qq9dotkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BNjJXV7v, HV_BINOP_MIN, 0, m, &cBinop_BNjJXV7v_sendMessage);
}

void Heavy_sequencerpatch::cCast_AojS3moi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Qq9dotkM_sendMessage);
}

void Heavy_sequencerpatch::cCast_jaE1oO9v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FQui9nmg, 0, m, &cVar_FQui9nmg_sendMessage);
}

void Heavy_sequencerpatch::cBinop_BNjJXV7v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_lL3RZCns, 0, m, &cTabread_lL3RZCns_sendMessage);
}

void Heavy_sequencerpatch::cMsg_r6igu7Rb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UeaXAR1L_sendMessage);
}

void Heavy_sequencerpatch::cBinop_TC1bR67k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BNjJXV7v, HV_BINOP_MIN, 1, m, &cBinop_BNjJXV7v_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_MYckSeDp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xCCBDDAC9: { // "turn"
      cSlice_onMessage(_c, &Context(_c)->cSlice_s9oZgM0N, 0, m, &cSlice_s9oZgM0N_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_s9oZgM0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPrint_onMessage(_c, m, "got_turn");
      cSwitchcase_W3JGdpCO_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      cPrint_onMessage(_c, m, "got_turn");
      cSwitchcase_W3JGdpCO_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cSwitchcase_Pt4ZTfdC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xCEF0717E: { // "press"
      cSlice_onMessage(_c, &Context(_c)->cSlice_axn6Ec17, 0, m, &cSlice_axn6Ec17_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_axn6Ec17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_FlYfEsMY, 0, m, &cVar_FlYfEsMY_sendMessage);
      cPrint_onMessage(_c, m, "got_step_press");
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_FlYfEsMY, 0, m, &cVar_FlYfEsMY_sendMessage);
      cPrint_onMessage(_c, m, "got_step_press");
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_FlYfEsMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tMQQ9NCj, 1, m, &cVar_tMQQ9NCj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_z31PLJhl, 1, m, &cVar_z31PLJhl_sendMessage);
}

void Heavy_sequencerpatch::cTabread_Q29MVnGm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OJr9PpBk, 0, m, &cVar_OJr9PpBk_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_thl3kLT0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9WAywOgi, 0, m, &cSlice_9WAywOgi_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9xJTRLhK_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_q1wgtlkH_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_9WAywOgi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_Q29MVnGm, 1, m, &cTabread_Q29MVnGm_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_Q29MVnGm, 1, m, &cTabread_Q29MVnGm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_RCpE21qm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2kwWPYyL_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_YQnvaTVb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_BjyUSgAh_sendMessage);
}

void Heavy_sequencerpatch::cBinop_4BNBX6Jo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jFFje3jp, HV_BINOP_MIN, 0, m, &cBinop_jFFje3jp_sendMessage);
}

void Heavy_sequencerpatch::cCast_q1wgtlkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_4BNBX6Jo_sendMessage);
}

void Heavy_sequencerpatch::cCast_9xJTRLhK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RCpE21qm, 0, m, &cVar_RCpE21qm_sendMessage);
}

void Heavy_sequencerpatch::cBinop_jFFje3jp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_Q29MVnGm, 0, m, &cTabread_Q29MVnGm_sendMessage);
}

void Heavy_sequencerpatch::cMsg_2kwWPYyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YQnvaTVb_sendMessage);
}

void Heavy_sequencerpatch::cBinop_BjyUSgAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jFFje3jp, HV_BINOP_MIN, 1, m, &cBinop_jFFje3jp_sendMessage);
}

void Heavy_sequencerpatch::cTabwrite_pq4AEhYP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cSwitchcase_HORH3duM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_76Kgx3D8, 0, m, &cSlice_76Kgx3D8_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pq4AEhYP, 0, m, &cTabwrite_pq4AEhYP_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_76Kgx3D8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pq4AEhYP, 2, m, &cTabwrite_pq4AEhYP_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pq4AEhYP, 2, m, &cTabwrite_pq4AEhYP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_tMQQ9NCj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_thl3kLT0_onMessage(_c, NULL, 0, m, NULL);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pq4AEhYP, 1, m, &cTabwrite_pq4AEhYP_sendMessage);
}

void Heavy_sequencerpatch::cVar_OJr9PpBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EbKF8RXC, HV_BINOP_ADD, 0, m, &cBinop_EbKF8RXC_sendMessage);
}

void Heavy_sequencerpatch::cVar_crbF0t8G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 12.0f, 0, m, &cBinop_CYzElNH6_sendMessage);
}

void Heavy_sequencerpatch::cCast_ZkC8ydW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tMQQ9NCj, 0, m, &cVar_tMQQ9NCj_sendMessage);
}

void Heavy_sequencerpatch::cVar_SgWeKYcl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 30.0f, 0, m, &cBinop_hiv9a98S_sendMessage);
}

void Heavy_sequencerpatch::cVar_e73Zh2j2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 30.0f, 0, m, &cBinop_HYeSHC0r_sendMessage);
}

void Heavy_sequencerpatch::cVar_LLJIDDYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_DswDo8PJ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_DoJXr5mR, 0, m, &cIf_DoJXr5mR_sendMessage);
}

void Heavy_sequencerpatch::cUnop_byrqmEAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HORH3duM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cUnop_4Y7AXecL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HORH3duM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cIf_DoJXr5mR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_4Y7AXecL_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_byrqmEAV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_DswDo8PJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DoJXr5mR, 1, m, &cIf_DoJXr5mR_sendMessage);
}

void Heavy_sequencerpatch::cVar_z31PLJhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XxEbqGSD_onMessage(_c, NULL, 0, m, NULL);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_zCDf0Qnm, 1, m, &cTabwrite_zCDf0Qnm_sendMessage);
}

void Heavy_sequencerpatch::cVar_XHYqQouM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HwRtST9Q, HV_BINOP_ADD, 0, m, &cBinop_HwRtST9Q_sendMessage);
}

void Heavy_sequencerpatch::cVar_gYGbW2Go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_fLrqUo33_sendMessage);
}

void Heavy_sequencerpatch::cCast_JNT0QhHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_z31PLJhl, 0, m, &cVar_z31PLJhl_sendMessage);
}

void Heavy_sequencerpatch::cVar_dbhCJN2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_2wQAp8Di_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_qFqIZ0YL, 0, m, &cIf_qFqIZ0YL_sendMessage);
}

void Heavy_sequencerpatch::cUnop_6NYS3ZuM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_tqEWSGIH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cUnop_F8MSXxnv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_tqEWSGIH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cIf_qFqIZ0YL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_F8MSXxnv_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_6NYS3ZuM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_2wQAp8Di_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qFqIZ0YL, 1, m, &cIf_qFqIZ0YL_sendMessage);
}

void Heavy_sequencerpatch::cTabread_69zFVHNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XHYqQouM, 0, m, &cVar_XHYqQouM_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_XxEbqGSD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_juHKZSSW, 0, m, &cSlice_juHKZSSW_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BPSd7kph_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gd22b4LO_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_juHKZSSW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_69zFVHNd, 1, m, &cTabread_69zFVHNd_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_69zFVHNd, 1, m, &cTabread_69zFVHNd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_Vl3lIQOW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ynkeK3AJ_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_ghG5q3iL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_X31d94cR_sendMessage);
}

void Heavy_sequencerpatch::cBinop_9Nm2WJ1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2H7vvJtm, HV_BINOP_MIN, 0, m, &cBinop_2H7vvJtm_sendMessage);
}

void Heavy_sequencerpatch::cCast_BPSd7kph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Vl3lIQOW, 0, m, &cVar_Vl3lIQOW_sendMessage);
}

void Heavy_sequencerpatch::cCast_gd22b4LO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_9Nm2WJ1P_sendMessage);
}

void Heavy_sequencerpatch::cBinop_2H7vvJtm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_69zFVHNd, 0, m, &cTabread_69zFVHNd_sendMessage);
}

void Heavy_sequencerpatch::cMsg_ynkeK3AJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ghG5q3iL_sendMessage);
}

void Heavy_sequencerpatch::cBinop_X31d94cR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2H7vvJtm, HV_BINOP_MIN, 1, m, &cBinop_2H7vvJtm_sendMessage);
}

void Heavy_sequencerpatch::cTabwrite_zCDf0Qnm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cSwitchcase_tqEWSGIH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_S8JqFPlR, 0, m, &cSlice_S8JqFPlR_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_zCDf0Qnm, 0, m, &cTabwrite_zCDf0Qnm_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_S8JqFPlR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_zCDf0Qnm, 2, m, &cTabwrite_zCDf0Qnm_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_zCDf0Qnm, 2, m, &cTabwrite_zCDf0Qnm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_Z2B0qLWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IAVWnAo2, 0, m, &cPack_IAVWnAo2_sendMessage);
}

void Heavy_sequencerpatch::cPack_IAVWnAo2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0x0xGUge_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cVar_b1im11q1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_JzH7ONAA_sendMessage);
}

void Heavy_sequencerpatch::cSend_0x0xGUge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_noteout", 0xD1D4AC2, m);
}

void Heavy_sequencerpatch::cBinop_JzH7ONAA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OtS02goQ_sendMessage);
}

void Heavy_sequencerpatch::cBinop_OtS02goQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_IAVWnAo2, 2, m, &cPack_IAVWnAo2_sendMessage);
}

void Heavy_sequencerpatch::cCast_5mI7uc9o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "got_loadbang");
  cSwitchcase_N6zSqXOE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cVar_qDxMgu1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_KxplVWAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 30.0f, 0, m, &cBinop_O8EZKz7X_sendMessage);
}

void Heavy_sequencerpatch::cVar_p3k38w8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 32.0f, 0, m, &cBinop_RH72URT6_sendMessage);
}

void Heavy_sequencerpatch::cCast_d1yq5Ocn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MbX4a2A4, 0, m, &cVar_MbX4a2A4_sendMessage);
}

void Heavy_sequencerpatch::cVar_bTMyXveo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_snv21ihe_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_sdU8jrMs, 0, m, &cIf_sdU8jrMs_sendMessage);
}

void Heavy_sequencerpatch::cUnop_mjHQ7JKd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_GC4KiI3J_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cUnop_iq7P9mUt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_GC4KiI3J_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cIf_sdU8jrMs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_iq7P9mUt_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_mjHQ7JKd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_snv21ihe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sdU8jrMs, 1, m, &cIf_sdU8jrMs_sendMessage);
}

void Heavy_sequencerpatch::cVar_MbX4a2A4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KW3nZbzw, HV_BINOP_ADD, 0, m, &cBinop_KW3nZbzw_sendMessage);
}

void Heavy_sequencerpatch::cVar_i6k0WNHT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qM7wNEV5, 0, m, &cPack_qM7wNEV5_sendMessage);
}

void Heavy_sequencerpatch::cPack_qM7wNEV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_gsCaTdGD_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cVar_I6hyxGzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_dzvUnMMN_sendMessage);
}

void Heavy_sequencerpatch::cSend_gsCaTdGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_noteout", 0xD1D4AC2, m);
}

void Heavy_sequencerpatch::cBinop_dzvUnMMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_xvK0V63M_sendMessage);
}

void Heavy_sequencerpatch::cBinop_xvK0V63M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qM7wNEV5, 2, m, &cPack_qM7wNEV5_sendMessage);
}

void Heavy_sequencerpatch::cCast_v9ESTnvO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_st7a4re9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_INr1qfIr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bPgjpJv0_sendMessage);
}

void Heavy_sequencerpatch::cVar_vtiaG2gV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z2B0qLWD, 1, m, &cVar_Z2B0qLWD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_i6k0WNHT, 1, m, &cVar_i6k0WNHT_sendMessage);
  cPrint_onMessage(_c, m, "trigger_note");
}

void Heavy_sequencerpatch::cSwitchcase_JUhfUBGc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ax5gyJiM, 0, m, &cSlice_Ax5gyJiM_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_AK3up9D4, 0, m, &cRandom_AK3up9D4_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cBinop_FzWySGec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_yZx4TeDJ_sendMessage);
}

void Heavy_sequencerpatch::cUnop_yZx4TeDJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TV4wG2P0, HV_BINOP_GREATER_THAN_EQL, 0, m, &cBinop_TV4wG2P0_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_CfkjHFbE, 0, m, &cIf_CfkjHFbE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EYbX4a1I, 0, m, &cVar_EYbX4a1I_sendMessage);
}

void Heavy_sequencerpatch::cRandom_AK3up9D4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_FzWySGec_sendMessage);
}

void Heavy_sequencerpatch::cSlice_Ax5gyJiM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_AK3up9D4, 1, m, &cRandom_AK3up9D4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cIf_CfkjHFbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fsHv7iDu_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nNOLBgdm_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MyrkVVCW_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_48ZeugVM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_TV4wG2P0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CfkjHFbE, 1, m, &cIf_CfkjHFbE_sendMessage);
}

void Heavy_sequencerpatch::cCast_7kSL5ewK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_EYbX4a1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cSwitchcase_7ahFdDiE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_dljlZxfr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_dljlZxfr_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_OsrhtCTO, 1, m, &cDelay_OsrhtCTO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H71yyoGa_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cDelay_OsrhtCTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OsrhtCTO, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fXeftjpu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_x5Jp07Na_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Olj0Kq9s_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wlOgQACe_sendMessage);
}

void Heavy_sequencerpatch::cMsg_dljlZxfr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_OsrhtCTO, 0, m, &cDelay_OsrhtCTO_sendMessage);
}

void Heavy_sequencerpatch::cCast_H71yyoGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OsrhtCTO, 0, m, &cDelay_OsrhtCTO_sendMessage);
}

void Heavy_sequencerpatch::cVar_JWDqwD6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1Xqbpoq4_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cVar_W0FnRGtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1Xqbpoq4_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSwitchcase_N6zSqXOE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_5MECTuYr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_5MECTuYr_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ffN7ZTAf, 1, m, &cDelay_ffN7ZTAf_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qDLA5ziO_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cDelay_ffN7ZTAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ffN7ZTAf, m);
  cMsg_45DvGVyh_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_5MECTuYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ffN7ZTAf, 0, m, &cDelay_ffN7ZTAf_sendMessage);
}

void Heavy_sequencerpatch::cCast_qDLA5ziO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ffN7ZTAf, 0, m, &cDelay_ffN7ZTAf_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_W3JGdpCO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x20AEE293: { // "knob0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UHyu3CwE, 0, m, &cSlice_UHyu3CwE_sendMessage);
      break;
    }
    case 0x3A6EC41A: { // "knob1"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Gik5ke51, 0, m, &cSlice_Gik5ke51_sendMessage);
      break;
    }
    case 0x17356E1C: { // "knob2"
      cSlice_onMessage(_c, &Context(_c)->cSlice_J7tcr8kL, 0, m, &cSlice_J7tcr8kL_sendMessage);
      break;
    }
    default: {
      cPrint_onMessage(_c, m, "got_unhandled_index");
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_UHyu3CwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zVwz2nFP_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3HaB1LwI_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QmkDStqq_sendMessage);
      cPrint_onMessage(_c, m, "got_route_0");
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zVwz2nFP_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3HaB1LwI_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QmkDStqq_sendMessage);
      cPrint_onMessage(_c, m, "got_route_0");
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cSlice_Gik5ke51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Q1u9uSlg_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S50OrFNp_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4DNf1Inw_sendMessage);
      cPrint_onMessage(_c, m, "got_route_1");
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Q1u9uSlg_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S50OrFNp_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4DNf1Inw_sendMessage);
      cPrint_onMessage(_c, m, "got_route_1");
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cSlice_J7tcr8kL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_isFm8U71_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ji6Oxh4q_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qx8ZHXKn_sendMessage);
      cPrint_onMessage(_c, m, "got_route_2");
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_isFm8U71_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ji6Oxh4q_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qx8ZHXKn_sendMessage);
      cPrint_onMessage(_c, m, "got_route_2");
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_HoMQwJwi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y1EAI5L9, 1, m, &cVar_Y1EAI5L9_sendMessage);
}

void Heavy_sequencerpatch::cMsg_lhSs3Tq3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Y1EAI5L9, 0, m, &cVar_Y1EAI5L9_sendMessage);
}

void Heavy_sequencerpatch::cMsg_aNMr2VYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_51DKeBAv, 0, m, &cVar_51DKeBAv_sendMessage);
}

void Heavy_sequencerpatch::cCast_zVwz2nFP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SgWeKYcl, 0, m, &cVar_SgWeKYcl_sendMessage);
}

void Heavy_sequencerpatch::cCast_3HaB1LwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_QmkDStqq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZkC8ydW5_sendMessage);
}

void Heavy_sequencerpatch::cCast_4DNf1Inw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JNT0QhHZ_sendMessage);
}

void Heavy_sequencerpatch::cCast_Q1u9uSlg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_e73Zh2j2, 0, m, &cVar_e73Zh2j2_sendMessage);
}

void Heavy_sequencerpatch::cCast_S50OrFNp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cBinop_EbKF8RXC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_crbF0t8G, 0, m, &cVar_crbF0t8G_sendMessage);
}

void Heavy_sequencerpatch::cBinop_HwRtST9Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gYGbW2Go, 0, m, &cVar_gYGbW2Go_sendMessage);
}

void Heavy_sequencerpatch::cBinop_fLrqUo33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_YiKVkksC_sendMessage);
}

void Heavy_sequencerpatch::cBinop_YiKVkksC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dbhCJN2v, 0, m, &cVar_dbhCJN2v_sendMessage);
}

void Heavy_sequencerpatch::cBinop_rf6KVXzX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LLJIDDYh, 0, m, &cVar_LLJIDDYh_sendMessage);
}

void Heavy_sequencerpatch::cBinop_CYzElNH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 80.0f, 0, m, &cBinop_rf6KVXzX_sendMessage);
}

void Heavy_sequencerpatch::cCast_m29cxGkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_SmiitqoM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KG3cjk54_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_9LadpbHx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cCast_GVwsyx6m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_6AMGxNNX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_FriJnX9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_W0FnRGtb, 0, m, &cVar_W0FnRGtb_sendMessage);
}

void Heavy_sequencerpatch::cCast_m5WIUOft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_54KUQKNA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jLQZnpGV_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_PStd28TH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_20EFYjw9_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_Qx8ZHXKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_d1yq5Ocn_sendMessage);
}

void Heavy_sequencerpatch::cCast_isFm8U71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KxplVWAW, 0, m, &cVar_KxplVWAW_sendMessage);
}

void Heavy_sequencerpatch::cCast_ji6Oxh4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cBinop_KW3nZbzw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p3k38w8R, 0, m, &cVar_p3k38w8R_sendMessage);
}

void Heavy_sequencerpatch::cBinop_RH72URT6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_rJBTqopo_sendMessage);
}

void Heavy_sequencerpatch::cBinop_rJBTqopo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bTMyXveo, 0, m, &cVar_bTMyXveo_sendMessage);
}

void Heavy_sequencerpatch::cCast_ePQvNrtK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z2B0qLWD, 0, m, &cVar_Z2B0qLWD_sendMessage);
}

void Heavy_sequencerpatch::cCast_JzTd5ORp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RCUikuEp_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_8vwXF0Ez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_7ahFdDiE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cCast_5CL0ILZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XKVojtii_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_wlOgQACe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_fXeftjpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KvIVFd2h_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_x5Jp07Na_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u8okcW6G_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_Olj0Kq9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_i6k0WNHT, 0, m, &cVar_i6k0WNHT_sendMessage);
}

void Heavy_sequencerpatch::cMsg_u8okcW6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_qM7wNEV5, 1, m, &cPack_qM7wNEV5_sendMessage);
}

void Heavy_sequencerpatch::cMsg_RCUikuEp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_IAVWnAo2, 1, m, &cPack_IAVWnAo2_sendMessage);
}

void Heavy_sequencerpatch::cMsg_XKVojtii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_b1im11q1, 0, m, &cVar_b1im11q1_sendMessage);
}

void Heavy_sequencerpatch::cMsg_KvIVFd2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_I6hyxGzG, 0, m, &cVar_I6hyxGzG_sendMessage);
}

void Heavy_sequencerpatch::cCast_INr1qfIr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_bPgjpJv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5CL0ILZJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JzTd5ORp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ePQvNrtK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8vwXF0Ez_sendMessage);
}

void Heavy_sequencerpatch::cCast_st7a4re9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vtiaG2gV, 0, m, &cVar_vtiaG2gV_sendMessage);
}

void Heavy_sequencerpatch::cCast_CoYbawf2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TV4wG2P0, HV_BINOP_GREATER_THAN_EQL, 1, m, &cBinop_TV4wG2P0_sendMessage);
}

void Heavy_sequencerpatch::cCast_IpKM17dn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JUhfUBGc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cCast_8TcE5Rgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7kSL5ewK_sendMessage);
}

void Heavy_sequencerpatch::cCast_TbeQ06nD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_48ZeugVM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v9ESTnvO_sendMessage);
}

void Heavy_sequencerpatch::cCast_nNOLBgdm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_fsHv7iDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_MyrkVVCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cMsg_20EFYjw9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "all-off");
  cSend_0mQVDziJ_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_jLQZnpGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(4);
  msg_init(m, 4, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "all-rgb");
  msg_setFloat(m, 1, 50.0f);
  msg_setFloat(m, 2, 30.0f);
  msg_setFloat(m, 3, 10.0f);
  cSend_0mQVDziJ_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cBinop_3ESGQyyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cf13GXeB, 0, m, &cVar_cf13GXeB_sendMessage);
}

void Heavy_sequencerpatch::cMsg_1Xqbpoq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "rgb");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setFloat(m, 2, 0.0f);
  msg_setFloat(m, 3, 255.0f);
  msg_setFloat(m, 4, 255.0f);
  cSend_0mQVDziJ_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSend_0mQVDziJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "tbd_stepled", 0xBD7A3EC7, m);
}

void Heavy_sequencerpatch::cSend_VW99fAuJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZQQRGLmm_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSend_GC4KiI3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ZQQRGLmm_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSend_eA8STs7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OGAOclV6_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_45DvGVyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  cSend_VW99fAuJ_sendMessage(_c, 0, m);
  cSend_eA8STs7c_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cBinop_O8EZKz7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KW3nZbzw, HV_BINOP_ADD, 1, m, &cBinop_KW3nZbzw_sendMessage);
}

void Heavy_sequencerpatch::cBinop_HYeSHC0r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HwRtST9Q, HV_BINOP_ADD, 1, m, &cBinop_HwRtST9Q_sendMessage);
}

void Heavy_sequencerpatch::cBinop_hiv9a98S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EbKF8RXC, HV_BINOP_ADD, 1, m, &cBinop_EbKF8RXC_sendMessage);
}

void Heavy_sequencerpatch::cReceive_PxDvQD1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6HYtSiW6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nAuvmxEB, 0, m, &cVar_nAuvmxEB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_b1im11q1, 0, m, &cVar_b1im11q1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_I6hyxGzG, 0, m, &cVar_I6hyxGzG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1A567NWJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5mI7uc9o_sendMessage);
}

void Heavy_sequencerpatch::cReceive_OGAOclV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MbX4a2A4, 1, m, &cVar_MbX4a2A4_sendMessage);
}

void Heavy_sequencerpatch::cReceive_ZQQRGLmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nAuvmxEB, 0, m, &cVar_nAuvmxEB_sendMessage);
  cPrint_onMessage(_c, m, "set_tempo");
}

void Heavy_sequencerpatch::cReceive_JQ0iHymm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Pt4ZTfdC_onMessage(_c, NULL, 0, m, NULL);
  cPrint_onMessage(_c, m, "got_tbd-step");
}

void Heavy_sequencerpatch::cReceive_oztHXV6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_MYckSeDp_onMessage(_c, NULL, 0, m, NULL);
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
  
  hv_uint32_t nextBlock = blockStartTimestamp + n;
  while (mq_hasMessageBefore(&mq, nextBlock)) {
    MessageNode *const node = mq_peek(&mq);
    node->sendMessage(this, node->let, node->m);
    mq_pop(&mq);
  }

  blockStartTimestamp = nextBlock;
  return n;

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
