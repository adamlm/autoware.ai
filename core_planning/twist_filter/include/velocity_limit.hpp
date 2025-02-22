#pragma once
/*
 * Copyright (C) 2018-2021 LEIDOS.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

#include <ros/ros.h>
#include <geometry_msgs/TwistStamped.h>
#include <autoware_msgs/ControlCommandStamped.h>
#include <hardcoded_params/control_limits/control_limits.h>

namespace twist_filter {

constexpr double MAX_LONGITUDINAL_VELOCITY_HARDCODED_LIMIT_M_S = hardcoded_params::control_limits::MAX_LONGITUDINAL_VELOCITY_MPS;

/**
 * Limit the longitudinal speed found in the input ControlCommandStamped
 * 
 * \param msg The message to be evaluated
 * \param limit The configurable limit to use in addition to the hardcoded limit
 * \return A copy of the message with the longitudinal speed limited 
 * based on params or hardcoded limit
 */
autoware_msgs::ControlCommandStamped
    longitudinalLimitCtrl(const autoware_msgs::ControlCommandStamped& msg, const double limit);

/**
 * Limit the longitudinal speed found in the input TwistStamped
 * 
 * \param msg The message to be evaluated
 * \param limit The configurable limit to use in addition to the hardcoded limit
 * \return A copy of the message with the longitudinal speed limited 
 * based on params or hardcoded limit
 */
geometry_msgs::TwistStamped
    longitudinalLimitTwist(const geometry_msgs::TwistStamped& msg, const double limit);
}