// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6.9 ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:1217

#ifndef CIAO_FDP_BAR_EXEC_H_
#define CIAO_FDP_BAR_EXEC_H_

#include /**/ "ace/pre.h"

#include "FDP_BarEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "FDP_Bar_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_Bar_Impl
{
  class FDP_BAR_EXEC_Export Bar_Port_exec_i
    : public virtual ::CCM_Bar_Port,
      public virtual ::CORBA::LocalObject
  {
  public:
    Bar_Port_exec_i (void);
    virtual ~Bar_Port_exec_i (void);
    
    // Operations and attributes from ::Bar_Port
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    bar (void);
  };
  
  class FDP_BAR_EXEC_Export Bar_exec_i
    : public virtual Bar_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Bar_exec_i (void);
    virtual ~Bar_exec_i (void);
    
    // Supported operations and attributes.
    
    // Component attributes.
    
    // Port operations.
    
    virtual ::CCM_Bar_Port_ptr
    get_bar (void);
    
    // Operations from Components::SessionComponent.
    
    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
  
  private:
    ::CCM_Bar_Context_var context_;
  };
  
  extern "C" FDP_BAR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Bar_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

