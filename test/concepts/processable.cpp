//
// Created by Himatya on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/concepts/processable.hpp>

struct Process {
    bool process() const { return true; }
};

template <class ProcessableType> requires owle::Processable<ProcessableType>
struct HasProcess : ProcessableType {};

TEST(ProcessableTest, HasProcessable) {
    ASSERT_EQ(HasProcess<Process>().process(), true);
}
