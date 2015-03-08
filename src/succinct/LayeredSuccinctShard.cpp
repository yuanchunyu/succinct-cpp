#include "succinct/LayeredSuccinctShard.hpp"

LayeredSuccinctShard::LayeredSuccinctShard(uint32_t id, std::string datafile, bool construct, uint32_t sa_sampling_rate,
            uint32_t isa_sampling_rate, uint32_t sampling_range, bool opportunistic, uint32_t npa_sampling_rate,
            NPA::NPAEncodingScheme npa_encoding_scheme, uint32_t context_len)
            : SuccinctShard(id, datafile, construct, sa_sampling_rate, isa_sampling_rate, npa_sampling_rate,
                    opportunistic ? SamplingScheme::OPPORTUNISTIC_LAYERED_SAMPLE_BY_INDEX : SamplingScheme::LAYERED_SAMPLE_BY_INDEX,
                    opportunistic ? SamplingScheme::OPPORTUNISTIC_LAYERED_SAMPLE_BY_INDEX : SamplingScheme::LAYERED_SAMPLE_BY_INDEX,
                    npa_encoding_scheme, context_len, sampling_range) {
    this->opportunistic = opportunistic;
}

size_t LayeredSuccinctShard::remove_layer(uint32_t layer_id) {
    size_t size = 0;
    if(!opportunistic) {
        size += ((LayeredSampledArray *)SA)->delete_layer(layer_id);
        size += ((LayeredSampledArray *)ISA)->delete_layer(layer_id);
    } else {
        size += ((OpportunisticLayeredSampledArray *)SA)->delete_layer(layer_id);
        size += ((OpportunisticLayeredSampledArray *)ISA)->delete_layer(layer_id);
    }
    return size;
}

size_t LayeredSuccinctShard::reconstruct_layer(uint32_t layer_id) {
    size_t size = 0;
    if(!opportunistic) {
        size += ((LayeredSampledISA *)ISA)->reconstruct_layer(layer_id);
        size += ((LayeredSampledSA *)SA)->reconstruct_layer(layer_id);
    } else {
        size += ((OpportunisticLayeredSampledISA *)ISA)->reconstruct_layer(layer_id);
        size += ((OpportunisticLayeredSampledSA *)SA)->reconstruct_layer(layer_id);
    }
    return size;
}

void LayeredSuccinctShard::get(std::string& result, int64_t key) {

    if(!opportunistic) {
        LayeredSampledISA *ISA_layered = (LayeredSampledISA *)ISA;
        result = "";
        int64_t pos = get_value_offset_pos(key);
        if(pos < 0)
            return;
        int64_t start = value_offsets[pos];
        int64_t end = ((size_t)(pos + 1) < value_offsets.size()) ? value_offsets[pos + 1] : input_size;
        int64_t len = end - start - 1;
        result.resize(len);
        uint64_t idx = lookupISA(start);
        for(int64_t i = 0; i < len; i++) {
            result[i] = alphabet[lookupC(idx)];
            uint64_t next_pos = start + i + 1;
            if(next_pos % ISA->get_sampling_rate() == 0) {
                idx = lookupISA(next_pos);
            } else {
                idx = lookupNPA(idx);
            }
        }
        return;
    }

    OpportunisticLayeredSampledISA *ISA_opp = (OpportunisticLayeredSampledISA *)ISA;
    OpportunisticLayeredSampledSA *SA_opp = (OpportunisticLayeredSampledSA *)SA;

    result = "";
    int64_t pos = get_value_offset_pos(key);
    if(pos < 0)
        return;
    int64_t start = value_offsets[pos];
    int64_t end = ((size_t)(pos + 1) < value_offsets.size()) ? value_offsets[pos + 1] : input_size;
    int64_t len = end - start - 1;
    result.resize(len);
    uint64_t idx = lookupISA(start);
    for(int64_t i = 0; i < len; i++) {
        result[i] = alphabet[lookupC(idx)];
        uint64_t next_pos = start + i + 1;
        if(next_pos % ISA->get_sampling_rate() == 0) {
            idx = lookupISA(next_pos);
        } else {
            idx = lookupNPA(idx);
        }
        ISA_opp->store(next_pos, idx);
    }
}
