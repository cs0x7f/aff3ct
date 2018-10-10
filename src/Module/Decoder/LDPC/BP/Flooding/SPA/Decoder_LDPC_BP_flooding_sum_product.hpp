#ifndef DECODER_LDPC_BP_FLOODING_SUM_PRODUCT_HPP_
#define DECODER_LDPC_BP_FLOODING_SUM_PRODUCT_HPP_

#include "../Decoder_LDPC_BP_flooding.hpp"
#include <mipp.h>

namespace aff3ct
{
namespace module
{
template <typename B = int, typename R = float>
class Decoder_LDPC_BP_flooding_sum_product : public Decoder_LDPC_BP_flooding<B,R>
{
private:
	std::vector<R> values;

public:
	Decoder_LDPC_BP_flooding_sum_product(const int K, const int N, const int n_ite,
	                                     const tools::Sparse_matrix &H,
	                                     const std::vector<unsigned> &info_bits_pos,
	                                     const bool enable_syndrome = true,
	                                     const int  syndrome_depth = 1,
	                                     const int n_frames = 1);
	virtual ~Decoder_LDPC_BP_flooding_sum_product();

protected:
	// BP functions for decoding
	virtual void BP_process(const R *Y_N, std::vector<R> &V_to_C, std::vector<R> &C_to_V);
};

template <typename B = int, typename R = float>
using Decoder_LDPC_BP_flooding_SPA = Decoder_LDPC_BP_flooding_sum_product<B,R>;
}
}

#endif /* DECODER_LDPC_BP_FLOODING_SUM_PRODUCT_HPP_ */
