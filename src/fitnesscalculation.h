#ifndef FITNESS_CALCULATION_H
#define FITNESS_CALCULATION_H

#include "../../../IncludeSpdlog/spdlog.h"
#include "fitness.h"

#include <opencv2/imgproc.hpp>
#include <QVector>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>

class BaseFitness;
class QJsonArray;
namespace cv
{
class Mat;
class TickMeter;
} // namespace cv

class FitnessCalculation
{
 public:
  FitnessCalculation(QJsonObject const &m_filter);
  ~FitnessCalculation();

  void configure(QJsonObject const &m_filter);
  void process(cv::Mat &a_image,cv::Mat &a_gt,cv::Mat &a_pre,cv::Mat &a_post);
  double getElapsedTimeSubtractor();

 private:
  BaseFitness* m_baseFitness;
  cv::TickMeter m_timer;
};

#endif // FITNESS_CALCULATION_H
