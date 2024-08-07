// Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/**
 * @file SubscriptionMatchedStatus.hpp
 */

#ifndef FASTDDS_DDS_CORE_STATUS__SUBSCRIPTIONMATCHEDSTATUS_HPP
#define FASTDDS_DDS_CORE_STATUS__SUBSCRIPTIONMATCHEDSTATUS_HPP

#include <cstdint>

#include <fastdds/dds/core/status/MatchedStatus.hpp>
#include <fastdds/dds/common/InstanceHandle.hpp>

namespace eprosima {
namespace fastdds {
namespace dds {

//! @brief A structure storing the subscription status
struct SubscriptionMatchedStatus : public MatchedStatus
{
    //! @brief Handle to the last writer that matched the reader causing the status change
    InstanceHandle_t last_publication_handle;
};

} // namespace dds
} // namespace fastdds
} // namespace eprosima

#endif //_SUBCRIPTION_MATCHED_STATUS_HPP_
