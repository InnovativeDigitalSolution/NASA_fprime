/*
 * TestCommand1Impl.hpp
 *
 *  Created on: Mar 28, 2014
 *      Author: tcanham
 */

#ifndef TESTCOMMANDSOURCEIMPL_HPP_
#define TESTCOMMANDSOURCEIMPL_HPP_

#include <Autocoders/Python/test/command_tester/CommandTestComponentAc.hpp>

class TestCommandSourceImpl: public Cmd::CommandTesterComponentBase {
    public:
#if FW_OBJECT_NAMES == 1
        TestCommandSourceImpl(const char* compName);
#else
        TestCommandSourceImpl();
#endif
        virtual ~TestCommandSourceImpl();
        void init();
        void test_TEST_CMD_1(I32 arg1, F32 arg2, U8 arg3);
    protected:
        void cmdStatusPort_handler(NATIVE_INT_TYPE portNum, FwOpcodeType opCode, U32 cmdSeq, const Fw::CmdResponse& response);
        void cmdRegPort_handler(NATIVE_INT_TYPE portNum, FwOpcodeType opCode);
    private:
        void printStatus(Fw::CmdResponse response);
};

#endif /* TESTCOMMANDSOURCEIMPL_HPP_ */
