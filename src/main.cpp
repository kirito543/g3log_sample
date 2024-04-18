#include<iostream>
#include <g3log/g3log.hpp>
#include <g3log/loglevels.hpp>
#include <g3log/logworker.hpp>


using namespace g3;


int main(int argc, char * argv[]){
  // 创建日志工作者
  auto worker = g3::LogWorker::createLogWorker();
  
  // 配置日志器
  auto defaultHandler = worker->addDefaultLogger("custom_log", "./");

  // 添加额外的日志级别
  g3::only_change_at_initialization::addLogLevel(G3LOG_ERROR);

  g3::initializeLogging(worker.get());

  // 记录自定义日志级别
  LOG(INFO) << "This is a custom log message";
  LOG(G3LOG_ERROR) << "This is a Error message";
  LOG(FATAL) << "This is a Fatal message";
  return 0;
}