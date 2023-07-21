// Copyright � 2016 Adam Augustyn <adam@augustyn.net>, all rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at:
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
//

#include "SaleaeHelper.hpp"
#include "Convert.hpp"

U64 SaleaeHelper::AdvanceClkCycles(AnalyzerChannelData* channel, U64 cycles)
{
	if (channel == nullptr) return 0;
	for (U64 i = 0; i < cycles; i++)
	{
		channel->AdvanceToNextEdge();
		channel->AdvanceToNextEdge();
	}
	return channel->GetSampleNumber();
}


bool SaleaeHelper::CanAdvanceToAbsPosition(AnalyzerChannelData* channel, U64 position)
{
	U64 _current = channel->GetSampleNumber();
	return position >= _current;
}

U32 SaleaeHelper::AdvanceToAbsPositionOrThrow(AnalyzerChannelData* channel, U64 position, const std::string& name)
{
	if (!CanAdvanceToAbsPosition(channel, position))
	{
		std::string msg = std::string("Cannot advance channel '") 
			+ name + std::string("' to absolute position: ") 
			+ Convert::ToDec(position)
			+ std::string(", current position is: ") + Convert::ToDec(channel->GetSampleNumber());
		throw std::runtime_error(msg.c_str());
	}
	return channel->AdvanceToAbsPosition(position);
}
