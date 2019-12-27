#include "bgfitness.h"
#include <QJsonObject>

Fitness::BGFitness::BGFitness(QJsonObject const &a_config)
{
    m_errorsAccumulation.fnError = 0;
    m_errorsAccumulation.fpError = 0;
    m_errorsAccumulation.tnError = 0;
    m_errorsAccumulation.tpError = 0;
    m_errorsAccumulation.nbShadowError = 0;
}

void Fitness::BGFitness::process(imageErrors a_imageError)
{
    m_errorsAccumulation.fnError += a_imageError.fnError;
    m_errorsAccumulation.fpError += a_imageError.fpError;
    m_errorsAccumulation.tnError += a_imageError.tnError;
    m_errorsAccumulation.tpError += a_imageError.tpError;
    m_errorsAccumulation.nbShadowError += a_imageError.nbShadowError;


}

struct fitness Fitness::BGFitness::getFitness()
{
    
}