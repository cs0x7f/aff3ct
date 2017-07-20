#ifndef FACTORY_DECODER_POLAR_GEN_HPP
#define FACTORY_DECODER_POLAR_GEN_HPP

#include <string>
#include <mipp.h>

#include "Module/Decoder/Decoder.hpp"
#include "Module/CRC/CRC.hpp"

#include "Decoder_polar.hpp"

namespace aff3ct
{
namespace factory
{
struct Decoder_polar_gen : public Decoder_polar
{
	template <typename B = int, typename Q = float>
	static module::Decoder<B,Q>* build(const parameters      &params,
	                                   const mipp::vector<B> &frozen_bits,
	                                         module::CRC<B>  *crc = nullptr);

	template <typename B>
	static void get_frozen_bits(const std::string      implem,
	                            const int              N,
	                                  mipp::vector<B> &frozen_bits);

	static void build_args(arg_map &req_args, arg_map &opt_args);
	static void store_args(const tools::Arguments_reader& ar, parameters &params);
	static void group_args(arg_grp& ar);

	static void header(params_list& head_dec, const parameters& params);

private:
	template <typename B = int, typename Q = float, class API_polar>
	static module::Decoder<B,Q>* _build(const parameters      &params,
	                                    const mipp::vector<B> &frozen_bits,
	                                          module::CRC<B>  *crc = nullptr);
};
}
}

#endif /* FACTORY_DECODER_POLAR_GEN_HPP */
