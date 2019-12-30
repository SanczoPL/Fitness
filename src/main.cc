#include "fitnesscalculation.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main() {
    QJsonObject filterConfig
    {
        {"Name", "BGFitness"},
        {"FitnessFunction","Recall_Specificity_FMeasure_Precision"} 
    };

    FitnessCalculation fc{filterConfig};
    fc.configure(filterConfig);
    imageErrors a_imageError;
    a_imageError.tpError = 10;
    a_imageError.fpError = 50;
    a_imageError.fnError = 50;
    a_imageError.tnError = 10;
    a_imageError.nbShadowError = 1;
    a_imageError.time = 0.1;
    fc.process(a_imageError);
    struct fitness fs = fc.getFitness();
    std::cout << "fs.fitness " << fs.fitness << std::endl;
    std::cout << "fs.Accuracy"  << fs.Accuracy << std::endl;
    std::cout << "fs.Recall " << fs.Recall << std::endl;//fs.Recall = (tp / (tp + fn));
    std::cout << "fs.Precision " << fs.Precision << std::endl;
    std::cout << "fs.fitnessTime " << fs.fitnessTime << std::endl;
    std::cout << "fs.fitness " << fs.fitness << std::endl;
    return 0;
}
