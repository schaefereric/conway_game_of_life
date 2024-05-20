#include <chrono>

struct Timer {

private:
    bool running;

    std::chrono::time_point<std::chrono::steady_clock>* startTime;
    std::chrono::time_point<std::chrono::steady_clock> endTime;

    int iDelay;                                     // type int
    std::chrono::duration<int, std::milli> dDelay;  // type duration

public:
    void start();
    void stop();

    bool hasTimeElapsed() const;

    void setDelay(int input);
    int getDelay() const;

    bool isRunning() const;
    void setRunning(bool input);

    Timer();
    ~Timer();
};