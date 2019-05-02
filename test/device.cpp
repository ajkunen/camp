/*
Copyright (c) 2016-18, Lawrence Livermore National Security, LLC.
Produced at the Lawrence Livermore National Laboratory
Maintained by Tom Scogland <scogland1@llnl.gov>
CODE-756261, All rights reserved.
This file is part of camp.
For details about use and distribution, please read LICENSE and NOTICE from
http://github.com/llnl/camp
*/

#include "camp/camp.hpp"
#include "gtest/gtest.h"

#if defined(__NVCC__)
TEST(CampDevices, DefaultDevice)
{
  camp::CudaDevice device;

  SUCCEED();
}
#endif
