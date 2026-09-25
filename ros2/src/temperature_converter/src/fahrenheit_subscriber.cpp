#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

using std::placeholders::_1;

class FahrenheitSubscriber : public rclcpp::Node
{
public:
  FahrenheitSubscriber()
  : Node("fahrenheit_subscriber")
  {
    subscription_ =
      this->create_subscription<std_msgs::msg::Float64>(
        "fahrenheit",
        10,
        std::bind(
          &FahrenheitSubscriber::temperature_callback,
          this,
          _1));
  }

private:
  void temperature_callback(
    const std_msgs::msg::Float64 & message) const
  {
    RCLCPP_INFO(
      this->get_logger(),
      "Received Fahrenheit: %.2f F",
      message.data);
  }

  rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<FahrenheitSubscriber>());
  rclcpp::shutdown();
  return 0;
}
