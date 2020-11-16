//
// Created by Himatya on 2020/11/07.
//

#pragma once

namespace owle {
    template <class ProcessableType>
    concept Processable = requires (ProcessableType& processable) {
        processable.process();
    };
}
