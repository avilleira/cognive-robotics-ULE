#include "simple_yasmin.hh"


// FOOState Class
FooState::FooState()
: yasmin::State({"outcome1", "outcome2"}), counter {0}
{

}


std::string FooState::execute(yasmin::Blackboard::SharedPtr blackboard)
{
    YASMIN_LOG_INFO("Ececuting state FOO");
    std::this_thread::sleep_for(std::chrono::seconds(3));

    if (this->counter < 3) {
        this->counter++;
        blackboard->set<std::string>("foo_str", "Counter: " + std::to_string(this->counter));
        return "outcome1";
    } else {
        return "outcome2";
    }
}


// BarState CLass
BarState::BarState()
: yasmin::State({"outcome3"})
{

}


std::string BarState::execute(yasmin::Blackboard::SharedPtr blackboard)
{
    YASMIN_LOG_INFO("Executing state BAR");
    std::this_thread::sleep_for(std::chrono::seconds(3));

    YASMIN_LOG_INFO(blackboard->get<std::string>("foo_str").c_str());

    return "outcome3";
}