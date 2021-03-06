// ======================================================================
// \title  RefTopologyAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for Ref topology
//
// \copyright
// Copyright (c) 2021 California Institute of Technology.
// U.S. Government sponsorship acknowledged.
// All rights reserved.
// ======================================================================

#ifndef Ref_RefTopologyAc_HPP
#define Ref_RefTopologyAc_HPP

#include "Drv/BlockDriver/BlockDriver.hpp"
#include "Drv/TcpClient/TcpClient.hpp"
#include "Ref/PingReceiver/PingReceiver.hpp"
#include "Ref/RecvBuffApp/RecvBuff.hpp"
#include "Ref/SendBuffApp/SendBuff.hpp"
#include "Ref/SignalGen/SignalGen.hpp"
#include "Ref/Top/RefTopologyDefs.hpp"
#include "Svc/ActiveLogger/ActiveLogger.hpp"
#include "Svc/ActiveRateGroup/ActiveRateGroup.hpp"
#include "Svc/AssertFatalAdapter/AssertFatalAdapter.hpp"
#include "Svc/BufferManager/BufferManager.hpp"
#include "Svc/CmdDispatcher/CommandDispatcher.hpp"
#include "Svc/CmdSequencer/CmdSequencer.hpp"
#include "Svc/Deframer/Deframer.hpp"
#include "Svc/FatalHandler/FatalHandler.hpp"
#include "Svc/FileDownlink/FileDownlink.hpp"
#include "Svc/FileManager/FileManager.hpp"
#include "Svc/FileUplink/FileUplink.hpp"
#include "Svc/Framer/Framer.hpp"
#include "Svc/Health/Health.hpp"
#include "Svc/LinuxTime/LinuxTime.hpp"
#include "Svc/PassiveConsoleTextLogger/PassiveTextLogger.hpp"
#include "Svc/PrmDb/PrmDb.hpp"
#include "Svc/RateGroupDriver/RateGroupDriver.hpp"
#include "Svc/StaticMemory/StaticMemory.hpp"
#include "Svc/TlmChan/TlmChan.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Constants
  // ----------------------------------------------------------------------

  namespace ConfigConstants {
    namespace cmdSeq {
      enum {
        BUFFER_SIZE = 5*1024
      };
    }
    namespace comm {
      enum {
        PRIORITY = 100,
        STACK_SIZE = Default::stackSize
      };
    }
    namespace fileDownlink {
      enum {
        TIMEOUT = 1000,
        COOLDOWN = 1000,
        CYCLE_TIME = 1000,
        FILE_QUEUE_DEPTH = 10
      };
    }
    namespace fileUplinkBufferManager {
      enum {
        STORE_SIZE = 3000,
        QUEUE_SIZE = 30,
        MGR_ID = 200
      };
    }
    namespace health {
      enum {
        WATCHDOG_CODE = 0x123
      };
    }
  }

  namespace BaseIds {
    enum {
      blockDrv = 0x100,
      rateGroup1Comp = 0x200,
      rateGroup2Comp = 0x300,
      rateGroup3Comp = 0x400,
      cmdDisp = 0x500,
      cmdSeq = 0x600,
      fileDownlink = 0x700,
      fileManager = 0x800,
      fileUplink = 0x900,
      pingRcvr = 0xA00,
      eventLogger = 0xB00,
      chanTlm = 0xC00,
      prmDb = 0xD00,
      health = 0x2000,
      SG1 = 0x2100,
      SG2 = 0x2200,
      SG3 = 0x2300,
      SG4 = 0x2400,
      SG5 = 0x2500,
      sendBuffComp = 0x2600,
      comm = 0x4000,
      downlink = 0x4100,
      fatalAdapter = 0x4200,
      fatalHandler = 0x4300,
      fileUplinkBufferManager = 0x4400,
      linuxTime = 0x4500,
      rateGroupDriverComp = 0x4600,
      recvBuffComp = 0x4700,
      staticMemory = 0x4800,
      textLogger = 0x4900,
      uplink = 0x4A00,
    };
  }

  namespace InstanceIds {
    enum {
      SG1,
      SG2,
      SG3,
      SG4,
      SG5,
      blockDrv,
      chanTlm,
      cmdDisp,
      cmdSeq,
      comm,
      downlink,
      eventLogger,
      fatalAdapter,
      fatalHandler,
      fileDownlink,
      fileManager,
      fileUplink,
      fileUplinkBufferManager,
      health,
      linuxTime,
      pingRcvr,
      prmDb,
      rateGroup1Comp,
      rateGroup2Comp,
      rateGroup3Comp,
      rateGroupDriverComp,
      recvBuffComp,
      sendBuffComp,
      staticMemory,
      textLogger,
      uplink,
    };
  }

  namespace Priorities {
    enum {
      blockDrv = 140,
      chanTlm = 97,
      cmdDisp = 101,
      cmdSeq = 100,
      eventLogger = 98,
      fileDownlink = 100,
      fileManager = 100,
      fileUplink = 100,
      pingRcvr = 100,
      prmDb = 96,
      rateGroup1Comp = 120,
      rateGroup2Comp = 119,
      rateGroup3Comp = 118,
    };
  }

  namespace QueueSizes {
    enum {
      SG1 = 10,
      SG2 = 10,
      SG3 = 10,
      SG4 = 10,
      SG5 = 10,
      blockDrv = 10,
      chanTlm = 10,
      cmdDisp = 20,
      cmdSeq = 10,
      eventLogger = 10,
      fileDownlink = 30,
      fileManager = 30,
      fileUplink = 30,
      health = 25,
      pingRcvr = 10,
      prmDb = 10,
      rateGroup1Comp = 10,
      rateGroup2Comp = 10,
      rateGroup3Comp = 10,
      sendBuffComp = 10,
    };
  }

  namespace StackSizes {
    enum {
      blockDrv = 16384,
      chanTlm = 16384,
      cmdDisp = 16384,
      cmdSeq = 16384,
      eventLogger = 16384,
      fileDownlink = 16384,
      fileManager = 16384,
      fileUplink = 16384,
      pingRcvr = 16384,
      prmDb = 16384,
      rateGroup1Comp = 16384,
      rateGroup2Comp = 16384,
      rateGroup3Comp = 16384,
    };
  }

  namespace TaskIds {
    enum {
      blockDrv,
      chanTlm,
      cmdDisp,
      cmdSeq,
      eventLogger,
      fileDownlink,
      fileManager,
      fileUplink,
      pingRcvr,
      prmDb,
      rateGroup1Comp,
      rateGroup2Comp,
      rateGroup3Comp,
    };
  }

  // ----------------------------------------------------------------------
  // Public interface functions
  // ----------------------------------------------------------------------

  //! Set up the topology
  void setup(
      const TopologyState& state //!< The topology state
  );

  //! Tear down the topology
  void teardown(
      const TopologyState& state //!< The topology state
  );

}

#endif
