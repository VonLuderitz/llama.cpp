#pragma once

#include "ggml.h" // ggml_op

#include <string>

//
// gguf constants (sync with gguf.py)
//

enum llm_arch {
    LLM_ARCH_LLAMA,
    LLM_ARCH_DECI,
    LLM_ARCH_FALCON,
    LLM_ARCH_BAICHUAN,
    LLM_ARCH_GROK,
    LLM_ARCH_GPT2,
    LLM_ARCH_GPTJ,
    LLM_ARCH_GPTNEOX,
    LLM_ARCH_MPT,
    LLM_ARCH_STARCODER,
    LLM_ARCH_REFACT,
    LLM_ARCH_BERT,
    LLM_ARCH_NOMIC_BERT,
    LLM_ARCH_JINA_BERT_V2,
    LLM_ARCH_BLOOM,
    LLM_ARCH_STABLELM,
    LLM_ARCH_QWEN,
    LLM_ARCH_QWEN2,
    LLM_ARCH_QWEN2MOE,
    LLM_ARCH_QWEN2VL,
    LLM_ARCH_PHI2,
    LLM_ARCH_PHI3,
    LLM_ARCH_PHIMOE,
    LLM_ARCH_PLAMO,
    LLM_ARCH_CODESHELL,
    LLM_ARCH_ORION,
    LLM_ARCH_INTERNLM2,
    LLM_ARCH_MINICPM,
    LLM_ARCH_MINICPM3,
    LLM_ARCH_GEMMA,
    LLM_ARCH_GEMMA2,
    LLM_ARCH_STARCODER2,
    LLM_ARCH_MAMBA,
    LLM_ARCH_XVERSE,
    LLM_ARCH_COMMAND_R,
    LLM_ARCH_COHERE2,
    LLM_ARCH_DBRX,
    LLM_ARCH_OLMO,
    LLM_ARCH_OLMO2,
    LLM_ARCH_OLMOE,
    LLM_ARCH_OPENELM,
    LLM_ARCH_ARCTIC,
    LLM_ARCH_DEEPSEEK,
    LLM_ARCH_DEEPSEEK2,
    LLM_ARCH_CHATGLM,
    LLM_ARCH_BITNET,
    LLM_ARCH_T5,
    LLM_ARCH_T5ENCODER,
    LLM_ARCH_JAIS,
    LLM_ARCH_NEMOTRON,
    LLM_ARCH_EXAONE,
    LLM_ARCH_RWKV6,
    LLM_ARCH_RWKV6QWEN2,
    LLM_ARCH_GRANITE,
    LLM_ARCH_GRANITE_MOE,
    LLM_ARCH_CHAMELEON,
    LLM_ARCH_WAVTOKENIZER_DEC,
    LLM_ARCH_UNKNOWN,
};

enum llm_kv {
    LLM_KV_GENERAL_TYPE,
    LLM_KV_GENERAL_ARCHITECTURE,
    LLM_KV_GENERAL_QUANTIZATION_VERSION,
    LLM_KV_GENERAL_ALIGNMENT,
    LLM_KV_GENERAL_NAME,
    LLM_KV_GENERAL_AUTHOR,
    LLM_KV_GENERAL_VERSION,
    LLM_KV_GENERAL_URL,
    LLM_KV_GENERAL_DESCRIPTION,
    LLM_KV_GENERAL_LICENSE,
    LLM_KV_GENERAL_SOURCE_URL,
    LLM_KV_GENERAL_SOURCE_HF_REPO,

    LLM_KV_VOCAB_SIZE,
    LLM_KV_CONTEXT_LENGTH,
    LLM_KV_EMBEDDING_LENGTH,
    LLM_KV_FEATURES_LENGTH,
    LLM_KV_BLOCK_COUNT,
    LLM_KV_LEADING_DENSE_BLOCK_COUNT,
    LLM_KV_FEED_FORWARD_LENGTH,
    LLM_KV_EXPERT_FEED_FORWARD_LENGTH,
    LLM_KV_EXPERT_SHARED_FEED_FORWARD_LENGTH,
    LLM_KV_USE_PARALLEL_RESIDUAL,
    LLM_KV_TENSOR_DATA_LAYOUT,
    LLM_KV_EXPERT_COUNT,
    LLM_KV_EXPERT_USED_COUNT,
    LLM_KV_EXPERT_SHARED_COUNT,
    LLM_KV_EXPERT_WEIGHTS_SCALE,
    LLM_KV_EXPERT_WEIGHTS_NORM,
    LLM_KV_EXPERT_GATING_FUNC,
    LLM_KV_POOLING_TYPE,
    LLM_KV_LOGIT_SCALE,
    LLM_KV_DECODER_START_TOKEN_ID,
    LLM_KV_ATTN_LOGIT_SOFTCAPPING,
    LLM_KV_FINAL_LOGIT_SOFTCAPPING,
    LLM_KV_SWIN_NORM,
    LLM_KV_RESCALE_EVERY_N_LAYERS,
    LLM_KV_TIME_MIX_EXTRA_DIM,
    LLM_KV_TIME_DECAY_EXTRA_DIM,
    LLM_KV_RESIDUAL_SCALE,
    LLM_KV_EMBEDDING_SCALE,
    LLM_KV_TOKEN_SHIFT_COUNT,

    LLM_KV_ATTENTION_HEAD_COUNT,
    LLM_KV_ATTENTION_HEAD_COUNT_KV,
    LLM_KV_ATTENTION_MAX_ALIBI_BIAS,
    LLM_KV_ATTENTION_CLAMP_KQV,
    LLM_KV_ATTENTION_KEY_LENGTH,
    LLM_KV_ATTENTION_VALUE_LENGTH,
    LLM_KV_ATTENTION_LAYERNORM_EPS,
    LLM_KV_ATTENTION_LAYERNORM_RMS_EPS,
    LLM_KV_ATTENTION_GROUPNORM_EPS,
    LLM_KV_ATTENTION_GROUPNORM_GROUPS,
    LLM_KV_ATTENTION_CAUSAL,
    LLM_KV_ATTENTION_Q_LORA_RANK,
    LLM_KV_ATTENTION_KV_LORA_RANK,
    LLM_KV_ATTENTION_RELATIVE_BUCKETS_COUNT,
    LLM_KV_ATTENTION_SLIDING_WINDOW,
    LLM_KV_ATTENTION_SCALE,

    LLM_KV_ROPE_DIMENSION_COUNT,
    LLM_KV_ROPE_DIMENSION_SECTIONS,
    LLM_KV_ROPE_FREQ_BASE,
    LLM_KV_ROPE_SCALE_LINEAR,
    LLM_KV_ROPE_SCALING_TYPE,
    LLM_KV_ROPE_SCALING_FACTOR,
    LLM_KV_ROPE_SCALING_ATTN_FACTOR,
    LLM_KV_ROPE_SCALING_ORIG_CTX_LEN,
    LLM_KV_ROPE_SCALING_FINETUNED,
    LLM_KV_ROPE_SCALING_YARN_LOG_MUL,

    LLM_KV_SPLIT_NO,
    LLM_KV_SPLIT_COUNT,
    LLM_KV_SPLIT_TENSORS_COUNT,

    LLM_KV_SSM_INNER_SIZE,
    LLM_KV_SSM_CONV_KERNEL,
    LLM_KV_SSM_STATE_SIZE,
    LLM_KV_SSM_TIME_STEP_RANK,
    LLM_KV_SSM_DT_B_C_RMS,

    LLM_KV_WKV_HEAD_SIZE,

    LLM_KV_TOKENIZER_MODEL,
    LLM_KV_TOKENIZER_PRE,
    LLM_KV_TOKENIZER_LIST,
    LLM_KV_TOKENIZER_TOKEN_TYPE,
    LLM_KV_TOKENIZER_TOKEN_TYPE_COUNT,
    LLM_KV_TOKENIZER_SCORES,
    LLM_KV_TOKENIZER_MERGES,
    LLM_KV_TOKENIZER_BOS_ID,
    LLM_KV_TOKENIZER_EOS_ID,
    LLM_KV_TOKENIZER_EOT_ID,
    LLM_KV_TOKENIZER_EOM_ID,
    LLM_KV_TOKENIZER_UNK_ID,
    LLM_KV_TOKENIZER_SEP_ID,
    LLM_KV_TOKENIZER_PAD_ID,
    LLM_KV_TOKENIZER_CLS_ID,
    LLM_KV_TOKENIZER_MASK_ID,
    LLM_KV_TOKENIZER_ADD_BOS,
    LLM_KV_TOKENIZER_ADD_EOS,
    LLM_KV_TOKENIZER_ADD_PREFIX,
    LLM_KV_TOKENIZER_REMOVE_EXTRA_WS,
    LLM_KV_TOKENIZER_PRECOMPILED_CHARSMAP,
    LLM_KV_TOKENIZER_HF_JSON,
    LLM_KV_TOKENIZER_RWKV,
    LLM_KV_TOKENIZER_CHAT_TEMPLATE,
    LLM_KV_TOKENIZER_FIM_PRE_ID,
    LLM_KV_TOKENIZER_FIM_SUF_ID,
    LLM_KV_TOKENIZER_FIM_MID_ID,
    LLM_KV_TOKENIZER_FIM_PAD_ID,
    LLM_KV_TOKENIZER_FIM_REP_ID,
    LLM_KV_TOKENIZER_FIM_SEP_ID,

    LLM_KV_ADAPTER_TYPE,
    LLM_KV_ADAPTER_LORA_ALPHA,

    LLM_KV_POSNET_EMBEDDING_LENGTH,
    LLM_KV_POSNET_BLOCK_COUNT,

    LLM_KV_CONVNEXT_EMBEDDING_LENGTH,
    LLM_KV_CONVNEXT_BLOCK_COUNT,

    // deprecated:
    LLM_KV_TOKENIZER_PREFIX_ID,
    LLM_KV_TOKENIZER_SUFFIX_ID,
    LLM_KV_TOKENIZER_MIDDLE_ID,
};

enum llm_tensor {
    LLM_TENSOR_TOKEN_EMBD,
    LLM_TENSOR_TOKEN_EMBD_NORM,
    LLM_TENSOR_TOKEN_TYPES,
    LLM_TENSOR_POS_EMBD,
    LLM_TENSOR_OUTPUT,
    LLM_TENSOR_OUTPUT_NORM,
    LLM_TENSOR_ROPE_FREQS,
    LLM_TENSOR_ROPE_FACTORS_LONG,
    LLM_TENSOR_ROPE_FACTORS_SHORT,
    LLM_TENSOR_ATTN_Q,
    LLM_TENSOR_ATTN_K,
    LLM_TENSOR_ATTN_V,
    LLM_TENSOR_ATTN_QKV,
    LLM_TENSOR_ATTN_OUT,
    LLM_TENSOR_ATTN_NORM,
    LLM_TENSOR_ATTN_NORM_2,
    LLM_TENSOR_ATTN_OUT_NORM,
    LLM_TENSOR_ATTN_POST_NORM,
    LLM_TENSOR_ATTN_ROT_EMBD,
    LLM_TENSOR_FFN_GATE_INP,
    LLM_TENSOR_FFN_GATE_INP_SHEXP,
    LLM_TENSOR_FFN_NORM,
    LLM_TENSOR_FFN_POST_NORM,
    LLM_TENSOR_FFN_GATE,
    LLM_TENSOR_FFN_DOWN,
    LLM_TENSOR_FFN_UP,
    LLM_TENSOR_FFN_ACT,
    LLM_TENSOR_FFN_DOWN_EXP,  // split experts for backward compatibility
    LLM_TENSOR_FFN_GATE_EXP,
    LLM_TENSOR_FFN_UP_EXP,
    LLM_TENSOR_FFN_NORM_EXPS,
    LLM_TENSOR_FFN_DOWN_EXPS, // merged experts
    LLM_TENSOR_FFN_GATE_EXPS,
    LLM_TENSOR_FFN_UP_EXPS,
    LLM_TENSOR_FFN_DOWN_SHEXP,
    LLM_TENSOR_FFN_GATE_SHEXP,
    LLM_TENSOR_FFN_UP_SHEXP,
    LLM_TENSOR_FFN_EXP_PROBS_B,
    LLM_TENSOR_ATTN_Q_NORM,
    LLM_TENSOR_ATTN_K_NORM,
    LLM_TENSOR_LAYER_OUT_NORM,
    LLM_TENSOR_SSM_IN,
    LLM_TENSOR_SSM_CONV1D,
    LLM_TENSOR_SSM_X,
    LLM_TENSOR_SSM_DT,
    LLM_TENSOR_SSM_A,
    LLM_TENSOR_SSM_D,
    LLM_TENSOR_SSM_OUT,
    LLM_TENSOR_TIME_MIX_W1,
    LLM_TENSOR_TIME_MIX_W2,
    LLM_TENSOR_TIME_MIX_LERP_X,
    LLM_TENSOR_TIME_MIX_LERP_W,
    LLM_TENSOR_TIME_MIX_LERP_K,
    LLM_TENSOR_TIME_MIX_LERP_V,
    LLM_TENSOR_TIME_MIX_LERP_R,
    LLM_TENSOR_TIME_MIX_LERP_G,
    LLM_TENSOR_TIME_MIX_LERP_FUSED,
    LLM_TENSOR_TIME_MIX_FIRST,
    LLM_TENSOR_TIME_MIX_DECAY,
    LLM_TENSOR_TIME_MIX_DECAY_W1,
    LLM_TENSOR_TIME_MIX_DECAY_W2,
    LLM_TENSOR_TIME_MIX_KEY,
    LLM_TENSOR_TIME_MIX_VALUE,
    LLM_TENSOR_TIME_MIX_RECEPTANCE,
    LLM_TENSOR_TIME_MIX_GATE,
    LLM_TENSOR_TIME_MIX_LN,
    LLM_TENSOR_TIME_MIX_OUTPUT,
    LLM_TENSOR_CHANNEL_MIX_LERP_K,
    LLM_TENSOR_CHANNEL_MIX_LERP_R,
    LLM_TENSOR_CHANNEL_MIX_KEY,
    LLM_TENSOR_CHANNEL_MIX_RECEPTANCE,
    LLM_TENSOR_CHANNEL_MIX_VALUE,
    LLM_TENSOR_ATTN_Q_A,
    LLM_TENSOR_ATTN_Q_B,
    LLM_TENSOR_ATTN_KV_A_MQA,
    LLM_TENSOR_ATTN_KV_B,
    LLM_TENSOR_ATTN_Q_A_NORM,
    LLM_TENSOR_ATTN_KV_A_NORM,
    LLM_TENSOR_ATTN_SUB_NORM,
    LLM_TENSOR_FFN_SUB_NORM,
    LLM_TENSOR_DEC_ATTN_NORM,
    LLM_TENSOR_DEC_ATTN_Q,
    LLM_TENSOR_DEC_ATTN_K,
    LLM_TENSOR_DEC_ATTN_V,
    LLM_TENSOR_DEC_ATTN_OUT,
    LLM_TENSOR_DEC_ATTN_REL_B,
    LLM_TENSOR_DEC_CROSS_ATTN_NORM,
    LLM_TENSOR_DEC_CROSS_ATTN_Q,
    LLM_TENSOR_DEC_CROSS_ATTN_K,
    LLM_TENSOR_DEC_CROSS_ATTN_V,
    LLM_TENSOR_DEC_CROSS_ATTN_OUT,
    LLM_TENSOR_DEC_CROSS_ATTN_REL_B,
    LLM_TENSOR_DEC_FFN_NORM,
    LLM_TENSOR_DEC_FFN_GATE,
    LLM_TENSOR_DEC_FFN_DOWN,
    LLM_TENSOR_DEC_FFN_UP,
    LLM_TENSOR_DEC_OUTPUT_NORM,
    LLM_TENSOR_ENC_ATTN_NORM,
    LLM_TENSOR_ENC_ATTN_Q,
    LLM_TENSOR_ENC_ATTN_K,
    LLM_TENSOR_ENC_ATTN_V,
    LLM_TENSOR_ENC_ATTN_OUT,
    LLM_TENSOR_ENC_ATTN_REL_B,
    LLM_TENSOR_ENC_FFN_NORM,
    LLM_TENSOR_ENC_FFN_GATE,
    LLM_TENSOR_ENC_FFN_DOWN,
    LLM_TENSOR_ENC_FFN_UP,
    LLM_TENSOR_ENC_OUTPUT_NORM,
    LLM_TENSOR_CLS,
    LLM_TENSOR_CLS_OUT,
    LLM_TENSOR_CONV1D,
    LLM_TENSOR_CONVNEXT_DW,
    LLM_TENSOR_CONVNEXT_NORM,
    LLM_TENSOR_CONVNEXT_PW1,
    LLM_TENSOR_CONVNEXT_PW2,
    LLM_TENSOR_CONVNEXT_GAMMA,
    LLM_TENSOR_POS_NET_CONV1,
    LLM_TENSOR_POS_NET_CONV2,
    LLM_TENSOR_POS_NET_NORM,
    LLM_TENSOR_POS_NET_NORM1,
    LLM_TENSOR_POS_NET_NORM2,
    LLM_TENSOR_POS_NET_ATTN_NORM,
    LLM_TENSOR_POS_NET_ATTN_Q,
    LLM_TENSOR_POS_NET_ATTN_K,
    LLM_TENSOR_POS_NET_ATTN_V,
    LLM_TENSOR_POS_NET_ATTN_OUT,
};

enum llm_tensor_layer {
    LLM_TENSOR_LAYER_INPUT,
    LLM_TENSOR_LAYER_REPEATING,
    LLM_TENSOR_LAYER_OUTPUT,
};

struct LLM_KV {
    LLM_KV(llm_arch arch);

    llm_arch arch;

    std::string operator()(llm_kv kv) const;
};

// helper to handle gguf constants
// usage:
//
//   const auto tn = LLM_TN(LLM_ARCH_LLAMA);
//
//   std::string name = tn(LLM_TENSOR_OUTPUT);                     -> "output"
//   std::string name = tn(LLM_TENSOR_TOKEN_EMBD, "bias");         -> "token_embd.bias"
//   std::string name = tn(LLM_TENSOR_ATTN_NORM, "weight", 3);     -> "blk.3.attn_norm.weight"
//
struct LLM_TN_IMPL {
    const llm_arch arch;
    const llm_tensor tensor;
    const char * const suffix;
    const int bid;
    const int xid;

    std::string str() const;

    operator std::string() const {
        return str();
    }

    friend bool operator==(const std::string & str, const LLM_TN_IMPL & tn) {
        return str == tn.str();
    }

    friend bool operator!=(const std::string & str, const LLM_TN_IMPL & tn) {
        return str != tn.str();
    }
};

struct LLM_TN {
    LLM_TN(llm_arch arch_) : arch(arch_) {}

    llm_arch arch;

    LLM_TN_IMPL operator()(llm_tensor tensor, const char * suffix, int bid = -1, int xid = -1) const {
        return { arch, tensor, suffix, bid, xid };
    }

    LLM_TN_IMPL operator()(llm_tensor tensor, int bid = -1, int xid = -1) const {
        return { arch, tensor, nullptr, bid, xid };
    }
};


struct llm_tensor_info {
    llm_tensor_layer layer;
    ggml_op op;
};

const char * llm_arch_name(llm_arch arch);

llm_arch llm_arch_from_string(const std::string & name);

const llm_tensor_info & llm_tensor_info_for(llm_tensor tensor);
