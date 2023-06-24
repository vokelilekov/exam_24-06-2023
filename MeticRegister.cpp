#include "MeticRegister.h"
#include <iostream>

MetricRegister &MetricRegister::instance() {
  static MetricRegister instance;
  return instance;
}

bool MetricRegister::add_metr(int resp_t, int wait_t) {
  metrics[nextKey++] = std::make_pair(resp_t, wait_t);
  return true;
}

bool MetricRegister::show_mert() {
  if (metrics.empty())
    return false;

  for (auto &metric : metrics) {
    std::cout << "Key: " << metric.first
              << " Response Time: " << metric.second.first
              << " Waiting Time: " << metric.second.second << std::endl;
  }

  return true;
}

int MetricRegister::coutn_cometr(int key) {
  if (metrics.find(key) == metrics.end())
    return -1;

  return metrics[key].first + metrics[key].second;
}

MetricRegister::MetricRegister() : nextKey(0) {}
