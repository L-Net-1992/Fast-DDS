// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file bitset_structCdrAux.ipp
 * This source file contains some declarations of CDR related functions.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef FAST_DDS_GENERATED__BITSET_STRUCTCDRAUX_IPP
#define FAST_DDS_GENERATED__BITSET_STRUCTCDRAUX_IPP

#include "bitset_structCdrAux.hpp"

#include <fastcdr/Cdr.h>
#include <fastcdr/CdrSizeCalculator.hpp>


#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

namespace eprosima {
namespace fastcdr {

template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const ColorBitset&,
        size_t& current_alignment)
{
    return calculator.calculate_serialized_size(std::bitset<30>{}, current_alignment);
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const ColorBitset& data)
{
    std::bitset<30> bitset;

        bitset <<= 12;
        bitset |= (data.yellow & 0xFFF);

        bitset <<= 10;
        bitset |= (data.blue & 0x3FF);

        bitset <<= 4;

        bitset <<= 1;
        bitset |= (data.green & 0x1);

        bitset <<= 3;
        bitset |= (data.red & 0x7);


    scdr << bitset;
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& dcdr,
        ColorBitset& data)
{
    std::bitset<30> bitset;
    dcdr >> bitset;

        data.red = static_cast<uint8_t>(bitset.to_ullong() & 0x7);
        bitset >>= 3;

        data.green = static_cast<bool>(bitset.to_ullong() & 0x1);
        bitset >>= 1;

        bitset >>= 4;

        data.blue = static_cast<uint16_t>(bitset.to_ullong() & 0x3FF);
        bitset >>= 10;

        data.yellow = static_cast<int16_t>(bitset.to_ullong() & 0xFFF);
        bitset >>= 12;

}

template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const BitsetStruct& data,
        size_t& current_alignment)
{
    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0),
                data.my_bitset(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const BitsetStruct& data)
{
    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0) << data.my_bitset()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        BitsetStruct& data)
{
    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.my_bitset();
                                            break;

                    default:
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}

void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const BitsetStruct& data)
{
    static_cast<void>(scdr);
    static_cast<void>(data);
}



} // namespace fastcdr
} // namespace eprosima

#endif // FAST_DDS_GENERATED__BITSET_STRUCTCDRAUX_IPP
