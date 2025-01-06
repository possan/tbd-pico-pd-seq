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

float hTable_DUXj3mZE_data[32] = {49.0f, 47.979f, 79.0f, 80.0f, 45.0f, 57.0f, 9.98214f, 43.445f, 76.2008f, 58.9658f, 47.0f, 37.1953f, 3.63241f, 11.7963f, 23.5887f, 35.3811f, 56.2445f, 60.78f, 88.9002f, 99.7855f, 109.764f, 44.313f, 35.3811f, 48.9876f, 56.2445f, 70.7581f, 81.6434f, -0.903114f, 14.5177f, 21.7745f, 29.0313f, 41.7308f};
float hTable_7kMWfWaM_data[32] = {101.0f, 86.0f, 70.0f, 56.0f, 39.0f, 5.0f, 0.0f, 1.0f, 0.0f, -1.0f, -2.0f, -1.0f, -1.0f, -1.0f, -2.0f, 6.0f, 17.0f, 27.0f, 35.0f, 47.0f, 59.0f, 73.0f, 90.0f, 96.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f, -4.0f};



/*
 * Class Functions
 */

Heavy_sequencerpatch::Heavy_sequencerpatch(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += hTable_initWithData(&hTable_DUXj3mZE, 32, hTable_DUXj3mZE_data);
  numBytes += cVar_init_f(&cVar_3cEXG27M, 0.0f);
  numBytes += cVar_init_f(&cVar_RfYGqXNN, 0.0f);
  numBytes += cVar_init_f(&cVar_zRhnZ16D, 0.0f);
  numBytes += cVar_init_f(&cVar_j0cV1UXh, 1.0f);
  numBytes += cVar_init_f(&cVar_UF4Z3OwX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FdGEYerN, 0.0f);
  numBytes += cVar_init_f(&cVar_RI6vQiV3, 250.0f);
  numBytes += cBinop_init(&cBinop_7OUJVduB, 0.0f); // __mul
  numBytes += hTable_initWithData(&hTable_7kMWfWaM, 32, hTable_7kMWfWaM_data);
  numBytes += cVar_init_f(&cVar_ounG9rFD, 0.0f);
  numBytes += cTabread_init(&cTabread_wW2q80yi, &hTable_7kMWfWaM); // trigchance
  numBytes += cSlice_init(&cSlice_oKGaHzIs, 1, -1);
  numBytes += cVar_init_s(&cVar_wvr11JcD, "trigchance");
  numBytes += cBinop_init(&cBinop_yfbckX7o, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_NxbATsPu, &hTable_DUXj3mZE); // note
  numBytes += cSlice_init(&cSlice_rjxu3LRI, 1, -1);
  numBytes += cVar_init_s(&cVar_ONXD3O6D, "note");
  numBytes += cBinop_init(&cBinop_MyZgkvRD, 0.0f); // __min
  numBytes += cSlice_init(&cSlice_Gp3bpkeA, 1, -1);
  numBytes += cSlice_init(&cSlice_wueYclJX, 1, -1);
  numBytes += cVar_init_f(&cVar_LedrMRQj, 0.0f);
  numBytes += cTabread_init(&cTabread_QERp0jOo, &hTable_DUXj3mZE); // note
  numBytes += cSlice_init(&cSlice_EIOMDYvT, 1, -1);
  numBytes += cVar_init_s(&cVar_CR98CV1b, "note");
  numBytes += cBinop_init(&cBinop_lsBBBgJU, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_1CdhkbDF, &hTable_DUXj3mZE); // note
  numBytes += cSlice_init(&cSlice_y673xJIz, 1, -1);
  numBytes += cVar_init_f(&cVar_OW5RCTWX, 0.0f);
  numBytes += cVar_init_f(&cVar_VRHaXSsp, 0.0f);
  numBytes += cVar_init_f(&cVar_DSBLPJ7w, 0.0f);
  numBytes += cVar_init_f(&cVar_eeCt1ONy, 0.0f);
  numBytes += cVar_init_f(&cVar_74JtTSOA, 0.0f);
  numBytes += cVar_init_f(&cVar_K3Rsywc4, 0.0f);
  numBytes += cIf_init(&cIf_tNUxlnp9, false);
  numBytes += cVar_init_f(&cVar_mHGhff8c, 0.0f);
  numBytes += cVar_init_f(&cVar_d971BGMQ, 0.0f);
  numBytes += cVar_init_f(&cVar_sH2mZem0, 0.0f);
  numBytes += cVar_init_f(&cVar_0vAeAviJ, 0.0f);
  numBytes += cIf_init(&cIf_w6abR7Ip, false);
  numBytes += cTabread_init(&cTabread_xlBTPoP3, &hTable_7kMWfWaM); // trigchance
  numBytes += cSlice_init(&cSlice_264zEPzE, 1, -1);
  numBytes += cVar_init_s(&cVar_1eLeBMuS, "trigchance");
  numBytes += cBinop_init(&cBinop_z0MGGPBw, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_kwTMpqC0, &hTable_7kMWfWaM); // trigchance
  numBytes += cSlice_init(&cSlice_Oei9Y0u7, 1, -1);
  numBytes += cVar_init_f(&cVar_46uSoExZ, 0.0f);
  numBytes += cPack_init(&cPack_gNGHsTuK, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_gk4MLHQQ, 0.0f);
  numBytes += cVar_init_f(&cVar_gzeScVHh, 0.0f);
  numBytes += cVar_init_f(&cVar_gkb6koTn, 0.0f);
  numBytes += cVar_init_f(&cVar_6fuL3Fcy, 0.0f);
  numBytes += cVar_init_f(&cVar_wtTDkqaC, 0.0f);
  numBytes += cIf_init(&cIf_dMJnaqQb, false);
  numBytes += cVar_init_f(&cVar_hB6dowKz, 0.0f);
  numBytes += cVar_init_f(&cVar_XHJrcd84, 0.0f);
  numBytes += cPack_init(&cPack_jF4SuAP3, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_IA1geQd8, 0.0f);
  numBytes += cVar_init_f(&cVar_Z0o35TTd, 0.0f);
  numBytes += cRandom_init(&cRandom_OBVGIYnd, 1126291262);
  numBytes += cSlice_init(&cSlice_cxoIMkUk, 1, 1);
  numBytes += cIf_init(&cIf_OCUasfws, false);
  numBytes += cBinop_init(&cBinop_iEpF9j3o, 0.0f); // __gte
  numBytes += cVar_init_f(&cVar_FM3Gjc47, 0.0f);
  numBytes += cDelay_init(this, &cDelay_lfTjFrNf, 25.0f);
  numBytes += cVar_init_f(&cVar_LRmEDoK4, 0.0f);
  numBytes += cVar_init_f(&cVar_qrFQvbRC, 0.0f);
  numBytes += cDelay_init(this, &cDelay_DJuuta9e, 10.0f);
  numBytes += cSlice_init(&cSlice_idYfJ41q, 1, -1);
  numBytes += cSlice_init(&cSlice_ELwPynaJ, 1, -1);
  numBytes += cSlice_init(&cSlice_ExuLPzTf, 1, -1);
  numBytes += cBinop_init(&cBinop_42PlXIXz, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_zDxUirdj, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_WFnD8xhr, 0.0f); // __add
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_sequencerpatch::~Heavy_sequencerpatch() {
  hTable_free(&hTable_DUXj3mZE);
  hTable_free(&hTable_7kMWfWaM);
  cPack_free(&cPack_gNGHsTuK);
  cPack_free(&cPack_jF4SuAP3);
}

HvTable *Heavy_sequencerpatch::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x6E3449A8: return &hTable_DUXj3mZE; // note
    case 0x98FB22EB: return &hTable_7kMWfWaM; // trigchance
    default: return nullptr;
  }
}

void Heavy_sequencerpatch::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9wia7Lzm_sendMessage);
      break;
    }
    case 0x88E4D7C8: { // set-tempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zcagQBBE_sendMessage);
      break;
    }
    case 0x559B0855: { // tbd_knob
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PxpwnlNn_sendMessage);
      break;
    }
    case 0xBD433D4B: { // tbd_step
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_E90LEi3R_sendMessage);
      break;
    }
    case 0x26682824: { // tempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vbto4MLR_sendMessage);
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


void Heavy_sequencerpatch::hTable_DUXj3mZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_3cEXG27M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RfYGqXNN, 0, m, &cVar_RfYGqXNN_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_VOhE4acI_sendMessage);
}

void Heavy_sequencerpatch::cVar_RfYGqXNN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 16.0f, 0, m, &cBinop_s3524mGp_sendMessage);
}

void Heavy_sequencerpatch::cVar_zRhnZ16D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sLOEIuZA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3XEaKc1T_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tmJvDRfw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0EKHsBCb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xqua0Sq9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xWKO0KlU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mFeT9zef_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yUdO8mlI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qrFQvbRC, 1, m, &cVar_qrFQvbRC_sendMessage);
}

void Heavy_sequencerpatch::cCast_4dsh7jPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4lgq5u2j_sendMessage(_c, 0, m);
  cMsg_Ao5EnNgQ_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_BExx3yss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3cEXG27M, 0, m, &cVar_3cEXG27M_sendMessage);
}

void Heavy_sequencerpatch::cVar_j0cV1UXh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_wN38R6Uq_sendMessage);
  cSwitchcase_dcDs1y6P_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cBinop_wN38R6Uq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_j0cV1UXh, 1, m, &cVar_j0cV1UXh_sendMessage);
}

void Heavy_sequencerpatch::cVar_UF4Z3OwX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z0o35TTd, 1, m, &cVar_Z0o35TTd_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_dcDs1y6P_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_rpXzzqBy_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_rpXzzqBy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AWMDQGYt_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cDelay_FdGEYerN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FdGEYerN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FdGEYerN, 0, m, &cDelay_FdGEYerN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BExx3yss_sendMessage);
}

void Heavy_sequencerpatch::cCast_AWMDQGYt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rpXzzqBy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FdGEYerN, 0, m, &cDelay_FdGEYerN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BExx3yss_sendMessage);
}

void Heavy_sequencerpatch::cMsg_tPrqrT5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YEBmUXMw_sendMessage);
}

void Heavy_sequencerpatch::cSystem_YEBmUXMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cydATUz1_sendMessage);
}

void Heavy_sequencerpatch::cVar_RI6vQiV3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7OUJVduB, HV_BINOP_MULTIPLY, 0, m, &cBinop_7OUJVduB_sendMessage);
}

void Heavy_sequencerpatch::cMsg_rpXzzqBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_FdGEYerN, 0, m, &cDelay_FdGEYerN_sendMessage);
}

void Heavy_sequencerpatch::cBinop_1iNwBwen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FdGEYerN, 2, m, &cDelay_FdGEYerN_sendMessage);
}

void Heavy_sequencerpatch::cBinop_cydATUz1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7OUJVduB, HV_BINOP_MULTIPLY, 1, m, &cBinop_7OUJVduB_sendMessage);
}

void Heavy_sequencerpatch::cBinop_7OUJVduB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_1iNwBwen_sendMessage);
}

void Heavy_sequencerpatch::hTable_7kMWfWaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_ounG9rFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cTabread_wW2q80yi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ounG9rFD, 0, m, &cVar_ounG9rFD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jQvANoAX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JXAtbUJj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EZwMYwAA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R9aIf0F2_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_kWMtTCwr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_oKGaHzIs, 0, m, &cSlice_oKGaHzIs_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AQPdbbmd_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5VSI43RZ_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_oKGaHzIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_wW2q80yi, 1, m, &cTabread_wW2q80yi_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_wW2q80yi, 1, m, &cTabread_wW2q80yi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_wvr11JcD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UmYgm4b1_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_PW1BYOc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HsnzdXkq_sendMessage);
}

void Heavy_sequencerpatch::cBinop_s5vUus4p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yfbckX7o, HV_BINOP_MIN, 0, m, &cBinop_yfbckX7o_sendMessage);
}

void Heavy_sequencerpatch::cCast_5VSI43RZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_s5vUus4p_sendMessage);
}

void Heavy_sequencerpatch::cCast_AQPdbbmd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wvr11JcD, 0, m, &cVar_wvr11JcD_sendMessage);
}

void Heavy_sequencerpatch::cBinop_yfbckX7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_wW2q80yi, 0, m, &cTabread_wW2q80yi_sendMessage);
}

void Heavy_sequencerpatch::cMsg_UmYgm4b1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PW1BYOc8_sendMessage);
}

void Heavy_sequencerpatch::cBinop_HsnzdXkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yfbckX7o, HV_BINOP_MIN, 1, m, &cBinop_yfbckX7o_sendMessage);
}

void Heavy_sequencerpatch::cTabread_NxbATsPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UF4Z3OwX, 0, m, &cVar_UF4Z3OwX_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_qW5Ydl3V_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rjxu3LRI, 0, m, &cSlice_rjxu3LRI_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UkO2mkO6_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_M27APepf_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_rjxu3LRI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_NxbATsPu, 1, m, &cTabread_NxbATsPu_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_NxbATsPu, 1, m, &cTabread_NxbATsPu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_ONXD3O6D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BPIJ0WsW_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_eutq3JpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TYuAynCc_sendMessage);
}

void Heavy_sequencerpatch::cBinop_VTOq6b8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MyZgkvRD, HV_BINOP_MIN, 0, m, &cBinop_MyZgkvRD_sendMessage);
}

void Heavy_sequencerpatch::cCast_M27APepf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VTOq6b8g_sendMessage);
}

void Heavy_sequencerpatch::cCast_UkO2mkO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ONXD3O6D, 0, m, &cVar_ONXD3O6D_sendMessage);
}

void Heavy_sequencerpatch::cBinop_MyZgkvRD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_NxbATsPu, 0, m, &cTabread_NxbATsPu_sendMessage);
}

void Heavy_sequencerpatch::cMsg_BPIJ0WsW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eutq3JpE_sendMessage);
}

void Heavy_sequencerpatch::cBinop_TYuAynCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MyZgkvRD, HV_BINOP_MIN, 1, m, &cBinop_MyZgkvRD_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_fl6YyXfg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xCCBDDAC9: { // "turn"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Gp3bpkeA, 0, m, &cSlice_Gp3bpkeA_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_Gp3bpkeA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_XZlxWwdh_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      cSwitchcase_XZlxWwdh_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cSwitchcase_lptfG7AB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0xCEF0717E: { // "press"
      cSlice_onMessage(_c, &Context(_c)->cSlice_wueYclJX, 0, m, &cSlice_wueYclJX_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_wueYclJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_LedrMRQj, 0, m, &cVar_LedrMRQj_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_LedrMRQj, 0, m, &cVar_LedrMRQj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_LedrMRQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OW5RCTWX, 1, m, &cVar_OW5RCTWX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mHGhff8c, 1, m, &cVar_mHGhff8c_sendMessage);
}

void Heavy_sequencerpatch::cTabread_QERp0jOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VRHaXSsp, 0, m, &cVar_VRHaXSsp_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_8oMmgDtk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_EIOMDYvT, 0, m, &cSlice_EIOMDYvT_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zmDFC647_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NDpUDEoO_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_EIOMDYvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_QERp0jOo, 1, m, &cTabread_QERp0jOo_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_QERp0jOo, 1, m, &cTabread_QERp0jOo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_CR98CV1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HyNtaehH_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_YsnQra7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_27q8I9n1_sendMessage);
}

void Heavy_sequencerpatch::cBinop_AoPi11AT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lsBBBgJU, HV_BINOP_MIN, 0, m, &cBinop_lsBBBgJU_sendMessage);
}

void Heavy_sequencerpatch::cCast_zmDFC647_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CR98CV1b, 0, m, &cVar_CR98CV1b_sendMessage);
}

void Heavy_sequencerpatch::cCast_NDpUDEoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_AoPi11AT_sendMessage);
}

void Heavy_sequencerpatch::cBinop_lsBBBgJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_QERp0jOo, 0, m, &cTabread_QERp0jOo_sendMessage);
}

void Heavy_sequencerpatch::cMsg_HyNtaehH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YsnQra7s_sendMessage);
}

void Heavy_sequencerpatch::cBinop_27q8I9n1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lsBBBgJU, HV_BINOP_MIN, 1, m, &cBinop_lsBBBgJU_sendMessage);
}

void Heavy_sequencerpatch::cTabwrite_1CdhkbDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cSwitchcase_GI6IB7cD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_y673xJIz, 0, m, &cSlice_y673xJIz_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_1CdhkbDF, 0, m, &cTabwrite_1CdhkbDF_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_y673xJIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_1CdhkbDF, 2, m, &cTabwrite_1CdhkbDF_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_1CdhkbDF, 2, m, &cTabwrite_1CdhkbDF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_OW5RCTWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8oMmgDtk_onMessage(_c, NULL, 0, m, NULL);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_1CdhkbDF, 1, m, &cTabwrite_1CdhkbDF_sendMessage);
}

void Heavy_sequencerpatch::cVar_VRHaXSsp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_42PlXIXz, HV_BINOP_ADD, 0, m, &cBinop_42PlXIXz_sendMessage);
}

void Heavy_sequencerpatch::cVar_DSBLPJ7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 12.0f, 0, m, &cBinop_WDcD8yM3_sendMessage);
}

void Heavy_sequencerpatch::cCast_4rEapjcl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OW5RCTWX, 0, m, &cVar_OW5RCTWX_sendMessage);
}

void Heavy_sequencerpatch::cVar_eeCt1ONy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 30.0f, 0, m, &cBinop_9KBvIZMx_sendMessage);
}

void Heavy_sequencerpatch::cVar_74JtTSOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 30.0f, 0, m, &cBinop_pWJ3IK1t_sendMessage);
}

void Heavy_sequencerpatch::cVar_K3Rsywc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_wBgeAtn1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_tNUxlnp9, 0, m, &cIf_tNUxlnp9_sendMessage);
}

void Heavy_sequencerpatch::cUnop_fMtw4vxY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GI6IB7cD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cUnop_vIO9m9zp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GI6IB7cD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cIf_tNUxlnp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_vIO9m9zp_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_fMtw4vxY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_wBgeAtn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tNUxlnp9, 1, m, &cIf_tNUxlnp9_sendMessage);
}

void Heavy_sequencerpatch::cVar_mHGhff8c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BvlgPEX5_onMessage(_c, NULL, 0, m, NULL);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_kwTMpqC0, 1, m, &cTabwrite_kwTMpqC0_sendMessage);
}

void Heavy_sequencerpatch::cVar_d971BGMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zDxUirdj, HV_BINOP_ADD, 0, m, &cBinop_zDxUirdj_sendMessage);
}

void Heavy_sequencerpatch::cVar_sH2mZem0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_nnrQG5p6_sendMessage);
}

void Heavy_sequencerpatch::cCast_qu5RC3h6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mHGhff8c, 0, m, &cVar_mHGhff8c_sendMessage);
}

void Heavy_sequencerpatch::cVar_0vAeAviJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_NyPGJBxA_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_w6abR7Ip, 0, m, &cIf_w6abR7Ip_sendMessage);
}

void Heavy_sequencerpatch::cUnop_fBRA5Jy4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cO3pOKi7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cUnop_nXnA4ARe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cO3pOKi7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cIf_w6abR7Ip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_nXnA4ARe_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_fBRA5Jy4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_NyPGJBxA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_w6abR7Ip, 1, m, &cIf_w6abR7Ip_sendMessage);
}

void Heavy_sequencerpatch::cTabread_xlBTPoP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d971BGMQ, 0, m, &cVar_d971BGMQ_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_BvlgPEX5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_264zEPzE, 0, m, &cSlice_264zEPzE_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OuEmkAxe_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TsTanp6v_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_264zEPzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_xlBTPoP3, 1, m, &cTabread_xlBTPoP3_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_xlBTPoP3, 1, m, &cTabread_xlBTPoP3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_1eLeBMuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Kgx3HWDX_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSystem_n2D0jMXf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TMraofc3_sendMessage);
}

void Heavy_sequencerpatch::cBinop_Qi3wLctX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z0MGGPBw, HV_BINOP_MIN, 0, m, &cBinop_z0MGGPBw_sendMessage);
}

void Heavy_sequencerpatch::cCast_OuEmkAxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1eLeBMuS, 0, m, &cVar_1eLeBMuS_sendMessage);
}

void Heavy_sequencerpatch::cCast_TsTanp6v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Qi3wLctX_sendMessage);
}

void Heavy_sequencerpatch::cBinop_z0MGGPBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_xlBTPoP3, 0, m, &cTabread_xlBTPoP3_sendMessage);
}

void Heavy_sequencerpatch::cMsg_Kgx3HWDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_n2D0jMXf_sendMessage);
}

void Heavy_sequencerpatch::cBinop_TMraofc3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z0MGGPBw, HV_BINOP_MIN, 1, m, &cBinop_z0MGGPBw_sendMessage);
}

void Heavy_sequencerpatch::cTabwrite_kwTMpqC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cSwitchcase_cO3pOKi7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Oei9Y0u7, 0, m, &cSlice_Oei9Y0u7_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_kwTMpqC0, 0, m, &cTabwrite_kwTMpqC0_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_Oei9Y0u7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_kwTMpqC0, 2, m, &cTabwrite_kwTMpqC0_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_kwTMpqC0, 2, m, &cTabwrite_kwTMpqC0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cVar_46uSoExZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_gNGHsTuK, 0, m, &cPack_gNGHsTuK_sendMessage);
}

void Heavy_sequencerpatch::cPack_gNGHsTuK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_aQ5W9K9q_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cVar_gk4MLHQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_yingzrOj_sendMessage);
}

void Heavy_sequencerpatch::cSend_aQ5W9K9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_noteout", 0xD1D4AC2, m);
}

void Heavy_sequencerpatch::cBinop_yingzrOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EBdC9CbN_sendMessage);
}

void Heavy_sequencerpatch::cBinop_EBdC9CbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_gNGHsTuK, 2, m, &cPack_gNGHsTuK_sendMessage);
}

void Heavy_sequencerpatch::cCast_mooNxPGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPrint_onMessage(_c, m, "got_loadbang");
  cSwitchcase_aIRJ9hwX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cVar_gzeScVHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_gkb6koTn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 30.0f, 0, m, &cBinop_MJWWIOUt_sendMessage);
}

void Heavy_sequencerpatch::cVar_6fuL3Fcy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 32.0f, 0, m, &cBinop_cPBVNXsl_sendMessage);
}

void Heavy_sequencerpatch::cCast_lbN9v7sE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hB6dowKz, 0, m, &cVar_hB6dowKz_sendMessage);
}

void Heavy_sequencerpatch::cVar_wtTDkqaC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_sngr9xXS_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_dMJnaqQb, 0, m, &cIf_dMJnaqQb_sendMessage);
}

void Heavy_sequencerpatch::cUnop_jI78vJ3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9jDJmgTH_sendMessage(_c, 0, m);
  cSend_rjIgxU8k_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cUnop_kd5W01x9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9jDJmgTH_sendMessage(_c, 0, m);
  cSend_rjIgxU8k_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cIf_dMJnaqQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_kd5W01x9_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jI78vJ3E_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_sngr9xXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dMJnaqQb, 1, m, &cIf_dMJnaqQb_sendMessage);
}

void Heavy_sequencerpatch::cVar_hB6dowKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WFnD8xhr, HV_BINOP_ADD, 0, m, &cBinop_WFnD8xhr_sendMessage);
}

void Heavy_sequencerpatch::cVar_XHJrcd84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jF4SuAP3, 0, m, &cPack_jF4SuAP3_sendMessage);
}

void Heavy_sequencerpatch::cPack_jF4SuAP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_qhZDDTlo_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cVar_IA1geQd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_OkxbTFh5_sendMessage);
}

void Heavy_sequencerpatch::cSend_qhZDDTlo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_noteout", 0xD1D4AC2, m);
}

void Heavy_sequencerpatch::cBinop_OkxbTFh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RfD62aBc_sendMessage);
}

void Heavy_sequencerpatch::cBinop_RfD62aBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_jF4SuAP3, 2, m, &cPack_jF4SuAP3_sendMessage);
}

void Heavy_sequencerpatch::cCast_af14kes0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OrHotxW9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q4G9PhlL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nHqxC6Kx_sendMessage);
}

void Heavy_sequencerpatch::cVar_Z0o35TTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_46uSoExZ, 1, m, &cVar_46uSoExZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XHJrcd84, 1, m, &cVar_XHJrcd84_sendMessage);
  cPrint_onMessage(_c, m, "trigger_note");
}

void Heavy_sequencerpatch::cSwitchcase_DOZY7jkE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_cxoIMkUk, 0, m, &cSlice_cxoIMkUk_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OBVGIYnd, 0, m, &cRandom_OBVGIYnd_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cBinop_rxiDJwB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_3TG2OVle_sendMessage);
}

void Heavy_sequencerpatch::cUnop_3TG2OVle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iEpF9j3o, HV_BINOP_GREATER_THAN_EQL, 0, m, &cBinop_iEpF9j3o_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_OCUasfws, 0, m, &cIf_OCUasfws_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FM3Gjc47, 0, m, &cVar_FM3Gjc47_sendMessage);
}

void Heavy_sequencerpatch::cRandom_OBVGIYnd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_rxiDJwB6_sendMessage);
}

void Heavy_sequencerpatch::cSlice_cxoIMkUk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OBVGIYnd, 1, m, &cRandom_OBVGIYnd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cIf_OCUasfws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jQpakoIU_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZyGOovmH_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3NXZLTIj_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1tVUZE7P_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_iEpF9j3o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OCUasfws, 1, m, &cIf_OCUasfws_sendMessage);
}

void Heavy_sequencerpatch::cCast_ZLHuqEDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cVar_FM3Gjc47_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cSwitchcase_5ei5kwrk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_fVp14ELd_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_fVp14ELd_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_lfTjFrNf, 1, m, &cDelay_lfTjFrNf_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k2bbKQza_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cDelay_lfTjFrNf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lfTjFrNf, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XYJEzB1F_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kJvGT7jl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fLJSygvJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_y2JWIU7w_sendMessage);
}

void Heavy_sequencerpatch::cMsg_fVp14ELd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_lfTjFrNf, 0, m, &cDelay_lfTjFrNf_sendMessage);
}

void Heavy_sequencerpatch::cCast_k2bbKQza_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lfTjFrNf, 0, m, &cDelay_lfTjFrNf_sendMessage);
}

void Heavy_sequencerpatch::cVar_LRmEDoK4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RUYI5t9S_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cVar_qrFQvbRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RUYI5t9S_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSwitchcase_aIRJ9hwX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_VK4XK902_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_VK4XK902_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_DJuuta9e, 1, m, &cDelay_DJuuta9e_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3SzWFamz_sendMessage);
      break;
    }
  }
}

void Heavy_sequencerpatch::cDelay_DJuuta9e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DJuuta9e, m);
  cMsg_P25SzKYk_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_VK4XK902_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DJuuta9e, 0, m, &cDelay_DJuuta9e_sendMessage);
}

void Heavy_sequencerpatch::cCast_3SzWFamz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DJuuta9e, 0, m, &cDelay_DJuuta9e_sendMessage);
}

void Heavy_sequencerpatch::cSwitchcase_XZlxWwdh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_idYfJ41q, 0, m, &cSlice_idYfJ41q_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ELwPynaJ, 0, m, &cSlice_ELwPynaJ_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ExuLPzTf, 0, m, &cSlice_ExuLPzTf_sendMessage);
      break;
    }
    default: {
      cPrint_onMessage(_c, m, "got_unhandled_knob_index");
      break;
    }
  }
}

void Heavy_sequencerpatch::cSlice_idYfJ41q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DPtjTzgO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0WFgZSvn_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L1khIpqR_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DPtjTzgO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0WFgZSvn_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L1khIpqR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cSlice_ELwPynaJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ypEyvvM6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fdpksQST_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Op6xm2Wm_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ypEyvvM6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fdpksQST_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Op6xm2Wm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cSlice_ExuLPzTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bNcV5l8d_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l7tExUeb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tPRoA4tJ_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bNcV5l8d_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l7tExUeb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tPRoA4tJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_sequencerpatch::cBinop_VOhE4acI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3cEXG27M, 1, m, &cVar_3cEXG27M_sendMessage);
}

void Heavy_sequencerpatch::cMsg_4lgq5u2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_3cEXG27M, 0, m, &cVar_3cEXG27M_sendMessage);
}

void Heavy_sequencerpatch::cMsg_Ao5EnNgQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_j0cV1UXh, 0, m, &cVar_j0cV1UXh_sendMessage);
}

void Heavy_sequencerpatch::cCast_DPtjTzgO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eeCt1ONy, 0, m, &cVar_eeCt1ONy_sendMessage);
}

void Heavy_sequencerpatch::cCast_L1khIpqR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4rEapjcl_sendMessage);
}

void Heavy_sequencerpatch::cCast_0WFgZSvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_fdpksQST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_ypEyvvM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_74JtTSOA, 0, m, &cVar_74JtTSOA_sendMessage);
}

void Heavy_sequencerpatch::cCast_Op6xm2Wm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qu5RC3h6_sendMessage);
}

void Heavy_sequencerpatch::cBinop_42PlXIXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DSBLPJ7w, 0, m, &cVar_DSBLPJ7w_sendMessage);
}

void Heavy_sequencerpatch::cBinop_zDxUirdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sH2mZem0, 0, m, &cVar_sH2mZem0_sendMessage);
}

void Heavy_sequencerpatch::cBinop_nnrQG5p6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_Wca6pgpz_sendMessage);
}

void Heavy_sequencerpatch::cBinop_Wca6pgpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0vAeAviJ, 0, m, &cVar_0vAeAviJ_sendMessage);
}

void Heavy_sequencerpatch::cBinop_BogKASbf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_K3Rsywc4, 0, m, &cVar_K3Rsywc4_sendMessage);
}

void Heavy_sequencerpatch::cBinop_WDcD8yM3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 80.0f, 0, m, &cBinop_BogKASbf_sendMessage);
}

void Heavy_sequencerpatch::cCast_3XEaKc1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_mFeT9zef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qrFQvbRC, 0, m, &cVar_qrFQvbRC_sendMessage);
}

void Heavy_sequencerpatch::cCast_0EKHsBCb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_sLOEIuZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kWMtTCwr_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_qW5Ydl3V_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cCast_xWKO0KlU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MFr6DJ3O_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_tmJvDRfw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_yUdO8mlI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_xqua0Sq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_C7RFKZ8C_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_bNcV5l8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gkb6koTn, 0, m, &cVar_gkb6koTn_sendMessage);
}

void Heavy_sequencerpatch::cCast_tPRoA4tJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lbN9v7sE_sendMessage);
}

void Heavy_sequencerpatch::cCast_l7tExUeb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cBinop_WFnD8xhr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6fuL3Fcy, 0, m, &cVar_6fuL3Fcy_sendMessage);
}

void Heavy_sequencerpatch::cBinop_cPBVNXsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_xk10Mt4Y_sendMessage);
}

void Heavy_sequencerpatch::cBinop_xk10Mt4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wtTDkqaC, 0, m, &cVar_wtTDkqaC_sendMessage);
}

void Heavy_sequencerpatch::cCast_T6o1zPcD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lZF3SBDe_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_i9lZwnJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5ei5kwrk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cCast_RV3Csb6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wa2sXbGL_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_wuHx8P0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_46uSoExZ, 0, m, &cVar_46uSoExZ_sendMessage);
}

void Heavy_sequencerpatch::cCast_fLJSygvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XHJrcd84, 0, m, &cVar_XHJrcd84_sendMessage);
}

void Heavy_sequencerpatch::cCast_kJvGT7jl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F6i5e6mr_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cCast_y2JWIU7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_XYJEzB1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vK9xmCZ5_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_F6i5e6mr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_jF4SuAP3, 1, m, &cPack_jF4SuAP3_sendMessage);
}

void Heavy_sequencerpatch::cMsg_lZF3SBDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_gNGHsTuK, 1, m, &cPack_gNGHsTuK_sendMessage);
}

void Heavy_sequencerpatch::cMsg_wa2sXbGL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_gk4MLHQQ, 0, m, &cVar_gk4MLHQQ_sendMessage);
}

void Heavy_sequencerpatch::cMsg_vK9xmCZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_IA1geQd8, 0, m, &cVar_IA1geQd8_sendMessage);
}

void Heavy_sequencerpatch::cCast_Q4G9PhlL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_OrHotxW9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z0o35TTd, 0, m, &cVar_Z0o35TTd_sendMessage);
}

void Heavy_sequencerpatch::cCast_nHqxC6Kx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RV3Csb6o_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T6o1zPcD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wuHx8P0N_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i9lZwnJg_sendMessage);
}

void Heavy_sequencerpatch::cCast_JXAtbUJj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DOZY7jkE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cCast_jQvANoAX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iEpF9j3o, HV_BINOP_GREATER_THAN_EQL, 1, m, &cBinop_iEpF9j3o_sendMessage);
}

void Heavy_sequencerpatch::cCast_R9aIf0F2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_EZwMYwAA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZLHuqEDY_sendMessage);
}

void Heavy_sequencerpatch::cCast_3NXZLTIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_ZyGOovmH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cCast_1tVUZE7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_af14kes0_sendMessage);
}

void Heavy_sequencerpatch::cCast_jQpakoIU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_sequencerpatch::cMsg_C7RFKZ8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "all-off");
  cSend_kFkwI0zs_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cBinop_s3524mGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zRhnZ16D, 0, m, &cVar_zRhnZ16D_sendMessage);
}

void Heavy_sequencerpatch::cSend_kFkwI0zs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "tbd_stepled", 0xBD7A3EC7, m);
}

void Heavy_sequencerpatch::cSend_CAp0Ao7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zcagQBBE_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSend_9jDJmgTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zcagQBBE_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cSend_8T7T8pqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vbto4MLR_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_P25SzKYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 500.0f);
  cSend_CAp0Ao7t_sendMessage(_c, 0, m);
  cSend_8T7T8pqW_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cBinop_MJWWIOUt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WFnD8xhr, HV_BINOP_ADD, 1, m, &cBinop_WFnD8xhr_sendMessage);
}

void Heavy_sequencerpatch::cBinop_pWJ3IK1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zDxUirdj, HV_BINOP_ADD, 1, m, &cBinop_zDxUirdj_sendMessage);
}

void Heavy_sequencerpatch::cBinop_9KBvIZMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_42PlXIXz, HV_BINOP_ADD, 1, m, &cBinop_42PlXIXz_sendMessage);
}

void Heavy_sequencerpatch::cSend_rjIgxU8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vbto4MLR_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_RUYI5t9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "rgb");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setFloat(m, 2, 255.0f);
  msg_setFloat(m, 3, 255.0f);
  msg_setFloat(m, 4, 255.0f);
  cSend_kFkwI0zs_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cMsg_MFr6DJ3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(4);
  msg_init(m, 4, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "all-rgb");
  msg_setFloat(m, 1, 0.0f);
  msg_setFloat(m, 2, 0.0f);
  msg_setFloat(m, 3, 10.0f);
  cSend_kFkwI0zs_sendMessage(_c, 0, m);
}

void Heavy_sequencerpatch::cReceive_9wia7Lzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tPrqrT5y_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RI6vQiV3, 0, m, &cVar_RI6vQiV3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gk4MLHQQ, 0, m, &cVar_gk4MLHQQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IA1geQd8, 0, m, &cVar_IA1geQd8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4dsh7jPl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mooNxPGp_sendMessage);
}

void Heavy_sequencerpatch::cReceive_vbto4MLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hB6dowKz, 1, m, &cVar_hB6dowKz_sendMessage);
}

void Heavy_sequencerpatch::cReceive_zcagQBBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RI6vQiV3, 0, m, &cVar_RI6vQiV3_sendMessage);
  cPrint_onMessage(_c, m, "set_tempo");
}

void Heavy_sequencerpatch::cReceive_E90LEi3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lptfG7AB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_sequencerpatch::cReceive_PxpwnlNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fl6YyXfg_onMessage(_c, NULL, 0, m, NULL);
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
