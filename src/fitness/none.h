#ifndef FITNESS_NONE_H
#define FITNESS_NONE_H

#include "basefitness.h"

class QJsonObject;

namespace Fitness {
class None : public BaseFitness {
 public:
	None();

	void process(imageErrors a_imageError);
	struct fitness getFitness();
	void addTime(double time);

 private:
};
} // namespace Fitness

#endif // FITNESS_NONE_H
