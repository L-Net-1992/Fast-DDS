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
 * @file ReqRepAsReliableHelloWorldReplier.hpp
 *
 */

#ifndef _TEST_BLACKBOX_REQREPASRELIABLEHELLOWORLDREPLIER_HPP_
#define _TEST_BLACKBOX_REQREPASRELIABLEHELLOWORLDREPLIER_HPP_

#include "ReqRepHelloWorldReplier.hpp"
#include <asio.hpp>

class ReqRepAsReliableHelloWorldReplier : public ReqRepHelloWorldReplier
{
public:

    void configDatareader(
            const std::string& suffix) override
    {
        datareader_qos_.reliability().kind = eprosima::fastdds::dds::RELIABLE_RELIABILITY_QOS;

        std::ostringstream t;

        t << "ReqRepAsReliableHelloworld_" << asio::ip::host_name() << "_" << GET_PID() << "_" << suffix;

        datareader_topicname_ = t.str();
    }

    void configDatawriter(
            const std::string& suffix) override
    {
        datawriter_qos_.reliability().kind = eprosima::fastdds::dds::RELIABLE_RELIABILITY_QOS;

        // Increase default max_blocking_time to 1 second, as our CI infrastructure shows some
        // big CPU overhead sometimes
        datawriter_qos_.reliability().max_blocking_time.seconds = 1;
        datawriter_qos_.reliability().max_blocking_time.nanosec = 0;

        std::ostringstream t;

        t << "ReqRepAsReliableHelloworld_" << asio::ip::host_name() << "_" << GET_PID() << "_" << suffix;

        datawriter_topicname_ = t.str();
    }

};

#endif // _TEST_BLACKBOX_REQREPASRELIABLEHELLOWORLDREPLIER_HPP_
