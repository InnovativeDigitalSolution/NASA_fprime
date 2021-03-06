#ifdef FPRIME_CMAKE
#include "Autocoder/GTestBase.hpp"
#else
#include <GTestBase.hpp>
#endif
#include "TesterBase.hpp"
#include <FpConfig.hpp>

// Very minimal to test autocoder. Some day they'll be actual unit test code

class ATester : public Log::LogTesterGTestBase {
    public:
#if FW_OBJECT_NAMES == 1
        ATester() : Log::LogTesterGTestBase("comp",10) {
#else
        ATester() : Log::LogTesterGTestBase(10)  {
#endif
    }

  void from_Time_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Time &time
    )
  {
    this->pushFromPortEntry_Time(time);
  }
};

int main(int argc, char* argv[]) {

    ATester testBase;

}
