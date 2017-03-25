#include "Coset_bit.hpp"

using namespace aff3ct::module;

template <typename B, typename D>
Coset_bit<B,D>::Coset_bit(const int size, const int n_frames, const std::string name)
: Coset<B,D>(size, n_frames, name)
{
}

template <typename B, typename D>
Coset_bit<B,D>::~Coset_bit()
{
}

template <typename B, typename D>
void Coset_bit<B,D>::_apply(const mipp::vector<B>& ref, const mipp::vector<D> &in_data, mipp::vector<D> &out_data)
{
	for (auto i = 0; i < (int)ref.size(); i++)
		out_data[i] = ref[i] ? !in_data[i] : in_data[i];
}

// ==================================================================================== explicit template instantiation
#include "Tools/types.h"
#ifdef MULTI_PREC
template class aff3ct::module::Coset_bit<B_8,  B_8 >;
template class aff3ct::module::Coset_bit<B_16, B_16>;
template class aff3ct::module::Coset_bit<B_32, B_32>;
template class aff3ct::module::Coset_bit<B_64, B_64>;
#else
template class aff3ct::module::Coset_bit<B,B>;
#endif
// ==================================================================================== explicit template instantiation
