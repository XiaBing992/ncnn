// Tencent is pleased to support the open source community by making ncnn available.
//
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#include "layer/logsoftmax.h"
#include "testutil.h"

static int test_logsoftmax(const ncnn::Mat& a, int axis)
{
    ncnn::ParamDict pd;
    pd.set(0, axis); // axis
    pd.set(1, 1);    // fixbug0

    std::vector<ncnn::Mat> weights(0);

    int ret = test_layer<ncnn::LogSoftmax>("LogSoftmax", pd, weights, a);
    if (ret != 0)
    {
        fprintf(stderr, "test_logsoftmax failed a.dims=%d a=(%d %d %d) axis=%d\n", a.dims, a.w, a.h, a.c, axis);
    }

    return ret;
}

static int test_logsoftmax_0()
{
    ncnn::Mat a = RandomMat(25, 27, 32);
    ncnn::Mat b = RandomMat(27, 29, 28);
    ncnn::Mat c = RandomMat(23, 25, 27);

    return 0
           || test_logsoftmax(a, 0)
           || test_logsoftmax(a, 1)
           || test_logsoftmax(a, 2)
           || test_logsoftmax(a, -1)
           || test_logsoftmax(a, -2)
           || test_logsoftmax(a, -3)

           || test_logsoftmax(b, 0)
           || test_logsoftmax(b, 1)
           || test_logsoftmax(b, 2)
           || test_logsoftmax(b, -1)
           || test_logsoftmax(b, -2)
           || test_logsoftmax(b, -3)

           || test_logsoftmax(c, 0)
           || test_logsoftmax(c, 1)
           || test_logsoftmax(c, 2)
           || test_logsoftmax(c, -1)
           || test_logsoftmax(c, -2)
           || test_logsoftmax(c, -3);
}

static int test_logsoftmax_1()
{
    ncnn::Mat a = RandomMat(25, 32);
    ncnn::Mat b = RandomMat(27, 28);
    ncnn::Mat c = RandomMat(29, 27);

    return 0
           || test_logsoftmax(a, 0)
           || test_logsoftmax(a, 1)
           || test_logsoftmax(a, -1)
           || test_logsoftmax(a, -2)

           || test_logsoftmax(b, 0)
           || test_logsoftmax(b, 1)
           || test_logsoftmax(b, -1)
           || test_logsoftmax(b, -2)

           || test_logsoftmax(c, 0)
           || test_logsoftmax(c, 1)
           || test_logsoftmax(c, -1)
           || test_logsoftmax(c, -2);
}

static int test_logsoftmax_2()
{
    ncnn::Mat a = RandomMat(128);
    ncnn::Mat b = RandomMat(124);
    ncnn::Mat c = RandomMat(127);

    return 0
           || test_logsoftmax(a, 0)
           || test_logsoftmax(a, -1)

           || test_logsoftmax(b, 0)
           || test_logsoftmax(b, -1)

           || test_logsoftmax(c, 0)
           || test_logsoftmax(c, -1);
}

int main()
{
    SRAND(7767517);

    return 0
           || test_logsoftmax_0()
           || test_logsoftmax_1()
           || test_logsoftmax_2();
}
