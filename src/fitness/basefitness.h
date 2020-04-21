#ifndef BASE_FITNESS_H
#define BASE_FITNESS_H

#include <QObject>

#include <opencv2/imgproc.hpp>

#include "../../../src/structures.h"

class BaseFitness
{
 public:
  BaseFitness();
  virtual ~BaseFitness();

  virtual void process(imageErrors a_imageError) = 0;
  virtual struct fitness getFitness() = 0;
  virtual void addTime(double time) = 0;
};
#endif // BASE_FITNESS_H
