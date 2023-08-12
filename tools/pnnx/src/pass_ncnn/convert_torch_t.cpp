// Tencent is pleased to support the open source community by making ncnn available.
//
// Copyright (C) 2023 THL A29 Limited, a Tencent company. All rights reserved.
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

#include "convert_torch_t.h"

namespace pnnx{

namespace ncnn{

void convert_torch_t(Graph& graph)
{
    int index = 0;
    for (Operator* op : graph.ops)
    {
        if (op->type != "torch.t")
            continue;
        
        op->type = "Permute";
        op->name = std::string("t_") + std::to_string(index++);
        
        int input_rank = (int)op->inputs[0]->shape.size();
        if (input_rank > 2)
        {
            fprintf(stderr, "Expects input to be 1-D Mat or 2-D Mat, current dimension is %d", input_rank);
            return;
        }

        op->params["0"] = 1;
    }

    return;
}

} // namespace ncnn

} // namespace pnnx