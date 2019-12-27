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


    return 0;
}
