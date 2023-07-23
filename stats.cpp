#define _USE_MATH_DEFINES // Define this before including <cmath> to enable additional math constants
#include "stats.h"
#include <cmath>

using namespace Statistics;


Stats Statistics::ComputeStatistics(const std::vector<float>& inData)
{
/*   It takes a vector of float numbers as inputs
     returns the tatisticss (min, max, avg) peroformed on the input */ 
   
    Stats result{};

    if (inData.empty()) {
        // Handle the case when the input data is empty.
        result.average = NAN; // NAN represents "Not a Number."
        result.min     = NAN;
        result.max     = NAN;
        return result;
    }

    float sum  = 0.0;
    result.min = inData[0];
    result.max = inData[0];

    for (float value : inData) {
        sum += value;

        if (value < result.min) {
            result.min = value;
        }

        if (value > result.max) {
            result.max = value;
        }
    }

    result.average = sum / static_cast<float>(inData.size());

    return result;
}

// EmailAlert implementation
void EmailAlert::alert() {
    // Implementation to send an email alert
    // For the purpose of this example, we will just set a flag to indicate the alert
    emailSent = true;
}

// LEDAlert implementation
void LEDAlert::alert() {
    // Implementation to activate an LED alert
    // For the purpose of this example, we will just set a flag to indicate the alert
    ledGlows = true;
}

// StatsAlerter constructor
StatsAlerter::StatsAlerter(float maxThreshold, const std::vector<IAlerter*>& alerters)
    : maxThreshold(maxThreshold), alerters(alerters) {}

// Function to check input data and trigger alerts if needed
void StatsAlerter::checkAndAlert(const std::vector<float>& data) {
    if (data.empty())
        return;

    float max = data[0];

    // Find the maximum value in the input data
    for (float value : data) {
        if (value > max) {
            max = value;
        }
    }

    // Check if the maximum value exceeds the threshold
    if (max > maxThreshold) {
        // Trigger alerts by calling the alert() function on each IAlerter object
        for (IAlerter* alerter : alerters) {
            alerter->alert();
        }
    }
}


