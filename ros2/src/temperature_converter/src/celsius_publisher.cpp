#include <iostream>
#include <limits>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

class CelsiusPublisher : public rclcpp::Node
{
public:
  CelsiusPublisher()
  : Node("celsius_publisher")
  {
    publisher_ =
      this->create_publisher<std_msgs::msg::Float64>("fahrenheit", 10);
  }

  void publish_temperature(double celsius)
  {
    const double fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    std_msgs::msg::Float64 message;
    message.data = fahrenheit;
    publisher_->publish(message);

    RCLCPP_INFO(
      this->get_logger(),
      "Input: %.2f C -> Publishing: %.2f F",
      celsius,
      fahrenheit);
  }

private:
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<CelsiusPublisher>();

  while (rclcpp::ok()) {
    std::cout << "Enter Celsius temperature: ";

    double celsius;
    if (std::cin >> celsius) {
      node->publish_temperature(celsius);
      rclcpp::spin_some(node);
    } else {
      std::cin.clear();
      std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input." << std::endl;
    }
  }

  rclcpp::shutdown();
  return 0;
}
