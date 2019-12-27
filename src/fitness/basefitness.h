#ifndef BASE_FITNESS_H
#define BASE_FITNESS_H

#include <opencv2/imgproc.hpp>

class BaseFitness
{
 public:
  BaseFitness();
  virtual ~BaseFitness();

  virtual void process() = 0;
};
#endif // BASE_FITNESS_H
