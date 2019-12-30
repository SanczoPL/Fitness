#ifndef BASE_FITNESS_H
#define BASE_FITNESS_H

#include <opencv2/imgproc.hpp>
#include <QObject>

struct imageErrors
{
  qint64 tpError;
  qint64 fpError;
  qint64 fnError;
  qint64 tnError;
  qint64 nbShadowError;
  double time;
};

struct fitness
{
  qint64 fn;
  qint64 fp;
  qint64 tn;
  qint64 tp;
  qint64 nb;
  double Accuracy;
  double Recall;
  double Specificity;
  double FPR;
  double FNR;
  double PWC;
  double Precision;
  double NegativePrecision;
  double FMeasure;
  double fitness;
  double rfitness;
  double cfitness;
  double time;
  double fitnessTime;
};


struct fitnessFunction
{
  bool Accuracy;
  bool Recall;
  bool Specificity;
  bool FPR;
  bool FNR;
  bool PWC;
  bool Precision;
  bool NegativePrecision;
  bool FMeasure;
  bool fitnessTime;
};


class BaseFitness
{
 public:
  BaseFitness();
  virtual ~BaseFitness();

  virtual void process(imageErrors a_imageError) = 0;
  virtual struct fitness getFitness() = 0;
};
#endif // BASE_FITNESS_H
