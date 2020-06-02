/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2016-2019, Regents of the University of California,
 *                          Colorado State University,
 *                          University Pierre & Marie Curie, Sorbonne University.
 *
 * This file is part of ndn-tools (Named Data Networking Essential Tools).
 * See AUTHORS.md for complete list of ndn-tools authors and contributors.
 *
 * ndn-tools is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * ndn-tools is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * ndn-tools, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 *
 * See AUTHORS.md for complete list of ndn-cxx authors and contributors.
 *
 * @author Klaus Schneider
 */

#include "pipeline-interests-bbr.hpp"

#include <cmath>

namespace ndn {
namespace chunks {

constexpr double HIGH_GAIN = 2.885;
constexpr double LOW_GAIN = 0.3466;

PipelineInterestsBBR::PipelineInterestsBBR(Face& face, RttEstimatorWithStats& rttEstimator,
                                               const Options& opts)
  : PipelineInterestsAdaptive(face, rttEstimator, opts)
  , m_lastDecrease(time::steady_clock::now())
{
  //if (m_options.isVerbose) {
   // printOptions();
    //std::cerr << "\tCubic beta = " << m_options.cubicBeta << "\n"
     //         << "\tFast convergence = " << (m_options.enableFastConv ? "yes" : "no") << "\n";
  //}
}

void
PipelineInterestsBBR::Startup()
{ 
//To be Implemented 
//if maxbw remains sasme for 3 consecutive ACKS 
{
m_options.phase=1;
//goto the Drain Phase
}
else
{
m_cwnd=HIGH_GAIN*estiated_BDP;//here estimated BDP has to be replaced with the actual one
m_options.pacing_rate=HIGH_GAIN*maxbw//here maxbw has to be substituted
}  

  emitSignal(afterCwndChange, time::steady_clock::now() - getStartTime(), m_cwnd);
}

void
PipelineInterestsCubic::Drain()
{
if(m_nInFlight>=estimated_BDP)//here estimated BDP is to be replaced
{
m_cwnd=HIGH_GAIN*estimated_BDP//here estimated BDP is to be replaced;
m_options.pacing_rate=DRAIN_GAIN*maxbw//here maxbw has to be substituted
}
else 
m_options.phase=2;
//goto the probe BW phase
  emitSignal(afterCwndChange, time::steady_clock::now() - getStartTime(), m_cwnd);
}

void
PipelineInterestsCubic::ProbeBw(int i)
{
double gain_array={1.25,0.75,1,1,1,1,1,1};
//to be implemented
m_cwnd=2*estimatedBDP//here estimated BDP is to be substituted
m_options.pacing_rate=gain_array[i]*maxbw//here maximum bandwidth has to be substituted
}

void
PipelineInterestsCubic::ProbeRtt()
{
//this phase to be entered every 10 seconds make these changes to the pipeline_interests-adaptive-bbr.hpp file
m_cwnd=4;//get the estimate of min rtt, here
m_cwnd=MIN(m_cwnd,4*segment_size);//here segment_size is to be substituted
m_options.pacing_rate=maxbw//here maxbw to be substituted
/*pacing_gain=cwnd_gain=1
stay in this phase for atleast 200 ms
m_cwnd=MAX(m_cwnd,prev_cwnd)//here previous cwnd to be substituted
*/
if(maxbw remains same)
{
m_options.phase=2;
//goto probebw phase
}
else 
{
m_options.phase=0;
//goto startup phase
}
}
} // namespace chunks
} // namespace ndn
