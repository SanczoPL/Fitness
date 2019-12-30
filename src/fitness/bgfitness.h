#ifndef FITNESS_BGFITNESS_H
#define FITNESS_BGFITNESS_H

#include "basefitness.h"
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "../../../../IncludeSpdlog/spdlog.h"
#include <QtCore>

class QJsonObject;
struct fitnessFunction;

namespace Fitness {
class BGFitness : public BaseFitness {
 public:
  BGFitness(QJsonObject const &a_config);

  void process(imageErrors a_imageError);
  struct fitness getFitness();
  void addTime(double time);

 private:
    imageErrors m_errors;
    fitnessFunction m_activeFitnessFunction;
};
} // namespace Fitness

#endif // FITNESS_BGFITNESS_H
