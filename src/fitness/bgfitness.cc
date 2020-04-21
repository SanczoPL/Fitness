#include "bgfitness.h"
#include <QJsonObject>

Fitness::BGFitness::BGFitness(QJsonObject const &a_config)
{
  QString activeFitnessString = a_config["FitnessFunction"].toString();
  QStringList activeFitnessList = activeFitnessString.split("_");
  m_activeFitnessFunction.Accuracy = false;
  m_activeFitnessFunction.Recall = false;
  m_activeFitnessFunction.Specificity = false;
  m_activeFitnessFunction.FPR = false;
  m_activeFitnessFunction.FNR = false;
  m_activeFitnessFunction.PWC = false;
  m_activeFitnessFunction.Precision = false;
  m_activeFitnessFunction.NegativePrecision = false;
  m_activeFitnessFunction.FMeasure = false;
  m_activeFitnessFunction.fitnessTime = false;

  for (qint32 i = 0; i < activeFitnessList.size(); i++)
  {
    H_Logger->trace("activeFitnessList[{}]:{}", i, activeFitnessList[i].toStdString().c_str());
    if (activeFitnessList[i] == QString::fromStdString("Accuracy"))
    {
      m_activeFitnessFunction.Accuracy = true;
    }
    if (activeFitnessList[i] == QString::fromStdString("Recall"))
    {
      m_activeFitnessFunction.Recall = true;
    }
    if (activeFitnessList[i] == QString::fromStdString("Specificity"))
    {
      m_activeFitnessFunction.Specificity = true;
    }
    if (activeFitnessList[i] == QString::fromStdString("Precision"))
    {
      m_activeFitnessFunction.Precision = true;
    }
    if (activeFitnessList[i] == QString::fromStdString("NegativePrecision"))
    {
      m_activeFitnessFunction.NegativePrecision = true;
    }
    if (activeFitnessList[i] == QString::fromStdString("FMeasure"))
    {
      m_activeFitnessFunction.FMeasure = true;
    }
    if (activeFitnessList[i] == QString::fromStdString("fitnessTime"))
    {
      m_activeFitnessFunction.fitnessTime = true;
    }
  }

  m_errors.fnError = 0;
  m_errors.fpError = 0;
  m_errors.tnError = 0;
  m_errors.tpError = 0;
  m_errors.nbShadowError = 0;
}

void Fitness::BGFitness::process(imageErrors a_imageError)
{
  m_errors.fnError += a_imageError.fnError;
  m_errors.fpError += a_imageError.fpError;
  m_errors.tnError += a_imageError.tnError;
  m_errors.tpError += a_imageError.tpError;
  m_errors.nbShadowError += a_imageError.nbShadowError;
}

void Fitness::BGFitness::addTime(double time)
{
  m_errors.time = time;
}

struct fitness Fitness::BGFitness::getFitness()
{
  double fn = m_errors.fnError ? m_errors.fnError : 1;
  double fp = m_errors.fpError ? m_errors.fpError : 1;
  double tn = m_errors.tnError ? m_errors.tnError : 1;
  double tp = m_errors.tpError ? m_errors.tpError : 1;
  double nb = m_errors.nbShadowError ? m_errors.nbShadowError : 1;
  double time = m_errors.time ? m_errors.time : 1;

  H_Logger->trace("time:{}", time);

  struct fitness fs;
  fs.fn = fn;
  fs.fp = fp;
  fs.tn = tn;
  fs.tp = tp;
  fs.nb = nb;
  fs.time = time;
  fs.fitness = 0;
  fs.fitnessTime = static_cast<double>((1 / fs.time) * 200);
  H_Logger->trace("fitnessTime:{}", fs.fitnessTime);
  fs.Accuracy = static_cast<double>((tp + tn) / (tp + tn + fp + fn));
  fs.Recall = (tp / (tp + fn));
  fs.Specificity = (tn / (tn + fp));
  fs.FPR = (fp / (fp + tn));
  fs.FNR = (fn / (tp + fn));
  fs.PWC = (100 * (fn + fp) / (tp + fn + fp + tn));
  fs.Precision = (tp / (tp + fp));
  fs.FMeasure = (2 * fs.Precision * fs.Recall) / (fs.Precision + fs.Recall);
  fs.NegativePrecision = (tn / (tn + fn));
  // fs.fitness = fs.Recall + fs.Specificity + fs.FMeasure + fs.Precision;

  // .name.split("_");
  if (m_activeFitnessFunction.Accuracy == true)
  {
    fs.fitness = fs.fitness + fs.Accuracy;
  }
  if (m_activeFitnessFunction.Specificity == true)
  {
    fs.fitness = fs.fitness + fs.Specificity;
  }
  if (m_activeFitnessFunction.Recall == true)
  {
    fs.fitness = fs.fitness + fs.Recall;
  }
  if (m_activeFitnessFunction.Precision == true)
  {
    fs.fitness = fs.fitness + fs.Precision;
  }
  if (m_activeFitnessFunction.NegativePrecision == true)
  {
    fs.fitness = fs.fitness + fs.NegativePrecision;
  }
  if (m_activeFitnessFunction.FMeasure == true)
  {
    fs.fitness = fs.fitness + fs.FMeasure;
  }
  if (m_activeFitnessFunction.fitnessTime == true)
  {
    fs.fitness = fs.fitness + fs.fitnessTime;
  }
  return fs;
}
