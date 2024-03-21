#include <chrono>

struct Timer {

private:
    bool running;

    std::chrono::time_point<std::chrono::steady_clock>* startTime;
    std::chrono::time_point<std::chrono::steady_clock> endTime;

    int iDelay;
    std::chrono::duration<int, std::milli> dDelay;

public:
    void start();
    void stop();
    void setDelay(int input);
    int getDelay() const;
    bool hasTimeElapsed() const;
    bool isRunning() const;
    void setRunning(bool input);

    Timer();
    ~Timer();
};