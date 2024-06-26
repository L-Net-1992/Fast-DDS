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

/**
 * @file FileConsumer.hpp
 *
 */

#ifndef FASTDDS_DDS_LOG__FILECONSUMER_HPP
#define FASTDDS_DDS_LOG__FILECONSUMER_HPP

#include <gmock/gmock.h>

#include <fastdds/dds/log/Log.hpp>
#include <fastdds/dds/log/OStreamConsumer.hpp>

namespace eprosima {
namespace fastdds {
namespace dds {

class FileConsumer : public OStreamConsumer
{
public:

    FileConsumer() = default;

    FileConsumer(
            const std::string&,
            bool = false)
    {
    }

    virtual ~FileConsumer() = default;
};

MATCHER(IsFileConsumer, "Argument is a FileConsumer object?")
{
    *result_listener << (typeid(*arg.get()) == typeid(FileConsumer));
    return typeid(*arg.get()) == typeid(FileConsumer);
}

} // namespace dds
} // namespace fastdds
} // namespace eprosima

#endif // FASTDDS_DDS_LOG__FILECONSUMER_HPP
