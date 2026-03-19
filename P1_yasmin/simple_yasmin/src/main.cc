#include "simple_yasmin.hh"


auto main(int argc, char *argv[]) -> int {
    // Initialize ROS 2
    rclcpp::init(argc, argv);

    // Set ROS 2 logs
    yasmin_ros::set_ros_loggers();
    YASMIN_LOG_INFO("yasmin_demo");

    // Create a state machine
    auto sm = yasmin::StateMachine::make_shared(std::initializer_list<std::string>{"outcome4"}, true);

    // Add states to the state machine
    sm->add_state("FOO", std::make_shared<FooState>(),
                  {
                        {"outcome1", "BAR"},
                        {"outcome2", "outcome4"},
                  });
    sm->add_state("BAR", std::make_shared<BarState>(),
                  {
                        {"outcome3", "FOO"},
                  });

    // Publish state machine updates
    yasmin_viewer::YasminViewerPub yasmin_pub(sm, "YASMIN_DEMO");

    // Execute the state machine
    try {
        std::string outcome = (*sm.get())();
        YASMIN_LOG_INFO(outcome.c_str());
    } catch (const std::exception &e) {
        YASMIN_LOG_WARN(e.what());
    }

    rclcpp::shutdown();

    return EXIT_SUCCESS;
}