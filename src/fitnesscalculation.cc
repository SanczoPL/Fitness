#include "fitnesscalculation.h"

constexpr auto FILTER_NAME{ "Name" };

FitnessCalculation::FitnessCalculation(QJsonObject const &a_config)
{
  H_Logger->trace("FitnessCalculation::FitnessCalculation()");
  m_baseFitness = new Fitness::None();
}

FitnessCalculation::~FitnessCalculation()
{
  delete m_baseFitness;
}

void FitnessCalculation::configure(QJsonObject const &a_config)
{
  H_Logger->trace("FitnessCalculation::configure()");
  auto const NAME_STRING{ a_config[FILTER_NAME].toString().toStdString() };
  H_Logger->trace("encoder type: {}", NAME_STRING);
  auto const NAME_SID{ SID(NAME_STRING.c_str()) };
  delete m_baseFitness;
  m_timer.reset();
  
  switch (NAME_SID)
  {
    case SID("BGFitness"): m_baseFitness = new Fitness::BGFitness{ a_config }; break;
    case SID("None"): m_baseFitness = new Fitness::None(); break;
    default: H_Logger->error("Unsupported encoder type: {}", NAME_STRING); break;
  }
}

void FitnessCalculation::process(imageErrors a_imageError)
{
  H_Logger->trace("FitnessCalculation::process(a_image)");
  m_timer.start();
  m_baseFitness->process(a_imageError);
  m_timer.stop();
}
double FitnessCalculation::getElapsedTimeSubtractor()
{
  return m_timer.getTimeMilli();
}

struct fitness FitnessCalculation::getFitness()
{
  struct fitness a_fitness = m_baseFitness->getFitness();
  return a_fitness;
}

void FitnessCalculation::addTime(double time)
{
  m_baseFitness->addTime(time);
}