#include <chrono>
#include <iostream>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "yasmin/logs.hpp"
#include "yasmin/state.hpp"
#include "yasmin/state_machine.hpp"
#include "yasmin_ros/ros_logs.hpp"
#include "yasmin_viewer/yasmin_viewer_pub.hpp"


/**
 * @brief Represents the "Foo" state in the state machine.
 *
 * This state increments a counter each time it is executed and
 * communicates the current count via the blackboard.
 */
class FooState : public yasmin::State
{
public:
    int counter;

    /**
    * @brief Constructs a FooState object, initializing the counter.
    */
    FooState();

    /**
    * @brief Executes the Foo state logic.
    *
    * This method logs the execution, waits for 3 seconds,
    * increments the counter, and sets a string in the blackboard.
    * The state will transition to either "outcome1" or "outcome2"
    * based on the current value of the counter.
    *
    * @param blackboard Shared pointer to the blackboard for state communication.
    * @return std::string The outcome of the execution: "outcome1" or "outcome2".
    */
    std::string execute(yasmin::Blackboard::SharedPtr blackboard) override;
};


/**
* @brief Represents the "Bar" state in the state machine.
*
* This state logs the value from the blackboard and provides
* a single outcome to transition.
*/
class BarState : public yasmin::State
{
    /**
    * @brief Constructs a BarState object.
    */
    BarState();

    /**
    * @brief Executes the Bar state logic.
    *
    * This method logs the execution, waits for 3 seconds,
    * retrieves a string from the blackboard, and logs it.
    *
    * @param blackboard Shared pointer to the blackboard for state communication.
    * @return std::string The outcome of the execution: "outcome3".
    */
    std::string execute(yasmin::Blackboard::SharedPtr blackboard) override;
};