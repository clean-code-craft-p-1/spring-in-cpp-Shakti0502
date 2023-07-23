#include <vector>

namespace Statistics 
{
    
    // define the Stats structure here. See the tests to infer its properties
    struct Stats
    {
        float min{};
        float max{};
        float average{};

    };
    
    Stats ComputeStatistics(const std::vector<float>& values );

}

// Forward declaration of the IAlerter interface
class IAlerter {
public:
    virtual void alert() = 0;
};

// EmailAlert class implementing the IAlerter interface
class EmailAlert : public IAlerter {
public:
    void alert() override;

    bool emailSent = false; // Flag to indicate whether the email alert was sent
};

// LEDAlert class implementing the IAlerter interface
class LEDAlert : public IAlerter {
public:
    void alert() override;

    bool ledGlows = false; // Flag to indicate whether the LED alert was triggered
};

// StatsAlerter class
class StatsAlerter {
public:
    StatsAlerter(float maxThreshold, const std::vector<IAlerter*>& alerters);

    // Function to check input data and trigger alerts if needed
    void checkAndAlert(const std::vector<float>& data);

private:
    float maxThreshold; // Maximum threshold to trigger alerts
    std::vector<IAlerter*> alerters; // Vector of IAlerter pointers to trigger alerts
};
