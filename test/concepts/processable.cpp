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
    static_assert(HasProcess<Process>().process(), "a");
    ASSERT_EQ((HasProcess<Process>().process()), true);
    ASSERT_EQ((owle::Processable<Process>), true);
}
