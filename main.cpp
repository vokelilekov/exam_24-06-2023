#include "MeticRegister.h"
#include <iostream>

void test() {
  for (int i = 0; i < 10; i++) {
    // Генерация тестовых данных
    int resp_t = i + 1;
    int wait_t = i + 2;

    MetricRegister::instance().add_metr(resp_t, wait_t);

    // Вызов тестируемого метода
    int result = MetricRegister::instance().coutn_cometr(i);

    // Проверка результата
    if (result == resp_t + wait_t) {
      std::cout << "Test passed for key " << i << std::endl;
    } else {
      std::cout << "Test failed for key " << i << ". Expected "
                << (resp_t + wait_t) << ", got " << result << std::endl;
    }
  }
}

int main() {
  // Тесты
  test();

  MetricRegister::instance().add_metr(5, 3);
  MetricRegister::instance().add_metr(7, 2);
  MetricRegister::instance().add_metr(9, 1);

  MetricRegister::instance().show_mert();

  std::cout << "Counted metric for key 1: "
            << MetricRegister::instance().coutn_cometr(1) << std::endl;

  return 0;
}
