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
struct imageErrors;
struct fitness;
struct fitnessFunction;

namespace cv
{
  class Mat;
  class TickMeter;
} // namespace cv

class FitnessCalculation
{
 public:
  FitnessCalculation(QJsonObject const &a_config);
  ~FitnessCalculation();

  void configure(QJsonObject const &a_config);
  void process(imageErrors a_imageError);
  struct fitness getFitness();
  double getElapsedTimeSubtractor();

 private:
  BaseFitness* m_baseFitness;
  cv::TickMeter m_timer;
};

#endif // FITNESS_CALCULATION_H
