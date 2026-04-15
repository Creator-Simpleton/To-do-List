#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

static constexpr auto infoString{
    "Please enter the serial number for the desired action:\n1) "
    "List pending tasks\n2) Complete a task\n3) Add a task\n4) "
    "Exit\nEnter choice: "};
static constexpr auto errorString{"Unable to open the file!\n"};
static constexpr auto fileName{"data.txt"};

int main() {
  std::ifstream data(fileName);
  std::vector<std::string> tasks;
  std::string task;

  if (data.is_open())
    while (std::getline(data, task))
      tasks.push_back(task);
  else
    std::cerr << errorString;

  static auto running{true};

  while (running) {
    std::cout << infoString;
    std::string userInput;
    std::getline(std::cin, userInput);
    char serialNumber;

    switch (userInput[0]) {
    case '1':
      for (auto i{0}; i < tasks.size(); ++i)
        std::cout << (i + 1) << ") " << tasks[i] << '\n';
      break;
    case '2':
      std::cout << "Write the serial Number of the task you completed: ";
      serialNumber = std::getchar();
      if (((serialNumber - '0') > 0) &&
          ((serialNumber - '0') < (tasks.size() + 1)))
        std::cout << tasks[serialNumber - '0' - 1] << '\n';
      break;
    case '3':
      std::cout << "Type out the task you wish to do: ";
      std::getline(std::cin, task);
      tasks.push_back(task);
      break;
    case '4':
      running = false;
      break;
    default:
      std::cout << "Invalid Arguement!\n";
      break;
    }
  }
  std::ofstream outputData(fileName);
  for (std::string i : tasks)
    outputData << i << '\n';
  return 0;
}
