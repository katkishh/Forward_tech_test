#include <iostream>
#include"Engine.h"
#include"Tests.h"

bool isCorrect() {
    if (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void heatTest(int env_temp) {
    CombustionEngine* engine = new CombustionEngine(env_temp);
    OverHeatTest* test = new OverHeatTest();

    test->perform(engine, env_temp);

    delete test;
    delete engine;
};

void powerTest(int env_temp) {
    CombustionEngine* engine = new CombustionEngine(env_temp);
    PowerTest* test = new PowerTest();

    test->perform(engine);

    delete test;
    delete engine;
}

int main()
{
    int env_temp;
    std::cin >> env_temp;

    while (!isCorrect()) {
        std::cout << "Please enter correct environment temperature" << std::endl;
        std::cin >> env_temp;
    }

    heatTest(env_temp);
    powerTest(env_temp);


    return 0;
}
