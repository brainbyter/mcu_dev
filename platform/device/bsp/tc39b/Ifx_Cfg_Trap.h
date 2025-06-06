// Copyright @2022 Pony AI Inc. All rights reserved.

#ifndef PLATFORM_BSP_TC39B_IFX_CFG_TRAP_H_
#define PLATFORM_BSP_TC39B_IFX_CFG_TRAP_H_

#include <stdio.h>

#define _MACRO_DEFINITION_TO_HEADER_STRING(x) #x
#define MACRO_DEFINITION_TO_HEADER_STRING(x) _MACRO_DEFINITION_TO_HEADER_STRING(x)

#ifdef TC39B_CUSTOM_IFX_CFG_TRAP_HEADER
#include MACRO_DEFINITION_TO_HEADER_STRING(TC39B_CUSTOM_IFX_CFG_TRAP_HEADER)
#endif  // TC39B_CUSTOM_IFX_CFG_TRAP_HEADER

static inline void Tc39bTrapNmiHook(IfxCpu_Trap trap_info) {
  if (trap_info.tClass == IfxCpu_Trap_Class_nonMaskableInterrupt) {
    printf("[NMI TRAP]: tCPU[%d],tId[%d],addr[0x%x].\r\n", trap_info.tCpu, trap_info.tId,
           trap_info.tAddr);
  } else {
    printf("[Not NMI TRAP]: tClass[%d],tCPU[%d],tId[%d],tAddr[0x%x].\r\n", trap_info.tClass,
           trap_info.tCpu, trap_info.tId, trap_info.tAddr);
  }
}

static inline void Tc39bTrapMmeHook(IfxCpu_Trap trap_info) {
  if (trap_info.tClass == IfxCpu_Trap_Class_memoryManagement) {
    switch (trap_info.tId) {
      case IfxCpu_Trap_MemoryManagement_Id_virtualAddressFill:
        printf("[MME TRAP]: Virtual address fill in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_MemoryManagement_Id_virtualAddressProtection:
        printf("[MME TRAP]: Virtual address protection in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      default:
        printf("[MME TRAP]: tCPU[%d],tId[%d],tAddr[0x%x].\r\n", trap_info.tCpu, trap_info.tId,
               trap_info.tAddr);
        break;
    }
  } else {
    printf("[Not MME TRAP]: tClass[%d],tCPU[%d],tId[%d],tAddr[0x%x].\r\n", trap_info.tClass,
           trap_info.tCpu, trap_info.tId, trap_info.tAddr);
  }
}

static inline void Tc39bTrapIpeHook(IfxCpu_Trap trap_info) {
  if (trap_info.tClass == IfxCpu_Trap_Class_internalProtection) {
    switch (trap_info.tId) {
      case IfxCpu_Trap_InternalProtection_Id_privilegeViolation:
        printf("[IPE TRAP]: Privileged instruction in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_InternalProtection_Id_memoryProtectionRead:
        printf("[IPE TRAP]: Memory protection read in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_InternalProtection_Id_memoryProtectionWrite:
        printf("[IPE TRAP]: Memory protection write in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_InternalProtection_Id_memoryProtectionExecute:
        printf("[IPE TRAP]: Memory protection execution in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_InternalProtection_Id_memoryProtectionPeripheralAccess:
        printf("[IPE TRAP]: Memory protection peripheral access in cpu %d at 0x%x.\r\n",
               trap_info.tCpu, trap_info.tAddr);
        break;
      case IfxCpu_Trap_InternalProtection_Id_memoryProtectionNullAddress:
        printf("[IPE TRAP]: Memory protection null address in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_InternalProtection_Id_globalRegisterWriteProtection:
        printf("[IPE TRAP]: Global register write protection in cpu %d at 0x%x.\r\n",
               trap_info.tCpu, trap_info.tAddr);
        break;
      default:
        printf("[IPE TRAP]: tCPU[%d],tId[%d],tAddr[0x%x].\r\n", trap_info.tCpu, trap_info.tId,
               trap_info.tAddr);
        break;
    }
  } else {
    printf("[Not IPE TRAP]: tClass[%d],tCPU[%d],tId[%d],tAddr[0x%x].\r\n", trap_info.tClass,
           trap_info.tCpu, trap_info.tId, trap_info.tAddr);
  }
}

static inline void Tc39bTrapIeHook(IfxCpu_Trap trap_info) {
  if (trap_info.tClass == IfxCpu_Trap_Class_instructionErrors) {
    switch (trap_info.tId) {
      case IfxCpu_Trap_InstructionErrors_Id_illegalOpcode:
        printf("[IE TRAP]: Illegal opcode in cpu %d at 0x%x.\r\n", trap_info.tCpu, trap_info.tAddr);
        break;
      case IfxCpu_Trap_InstructionErrors_Id_unimplementedOpcode:
        printf("[IE TRAP]: Unimplemented opcode in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_InstructionErrors_Id_invalidOperand:
        printf("[IE TRAP]: Invalid operand specification in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_InstructionErrors_Id_dataAddressAlignment:
        printf("[IE TRAP]: Data address alignment in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_InstructionErrors_Id_invalidMemoryAddress:
        printf("[IE TRAP]: Invalid local memory address in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      default:
        printf("[IE TRAP]: tCPU[%d],tId[%d],tAddr[0x%x].\r\n", trap_info.tCpu, trap_info.tId,
               trap_info.tAddr);
        break;
    }
  } else {
    printf("[Not IE TRAP]: tClass[%d],tCPU[%d],tId[%d],tAddr[0x%x].\r\n", trap_info.tClass,
           trap_info.tCpu, trap_info.tId, trap_info.tAddr);
  }
}

static inline void Tc39bTrapCmeHook(IfxCpu_Trap trap_info) {
  if (trap_info.tClass == IfxCpu_Trap_Class_contextManagement) {
    switch (trap_info.tId) {
      case IfxCpu_Trap_ContextManagement_Id_freeContextListDepletion:
        printf("[CME TRAP]: Free Context List Depletion (FCX = LCX) in cpu %d at 0x%x.\r\n",
               trap_info.tCpu, trap_info.tAddr);
        break;
      case IfxCpu_Trap_ContextManagement_Id_callDepthOverflow:
        printf("[CME TRAP]: Call Depth Overflow in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_ContextManagement_Id_callDepthUnderflow:
        printf("[CME TRAP]: Call Depth Underflow in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_ContextManagement_Id_freeContextListUnderflow:
        printf("[CME TRAP]: Free Context List Underflow (FCX = 0) in cpu %d at 0x%x.\r\n",
               trap_info.tCpu, trap_info.tAddr);
        break;
      case IfxCpu_Trap_ContextManagement_Id_callStackUnderflow:
        printf("[CME TRAP]: Call Stack Underflow (PCX = 0) in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_ContextManagement_Id_contextType:
        printf("[CME TRAP]: Context Type (PCXI.UL wrong) in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_ContextManagement_Id_nestingError:
        printf("[CME TRAP]: Nesting Error: RFE with non-zero call depth in cpu %d at 0x%x.\r\n",
               trap_info.tCpu, trap_info.tAddr);
        break;
      default:
        printf("[CME TRAP]: tCPU[%d],tId[%d],tAddr[0x%x].\r\n", trap_info.tCpu, trap_info.tId,
               trap_info.tAddr);
        break;
    }
  } else {
    printf("[Not CME TRAP]: tClass[%d],tCPU[%d],tId[%d],tAddr[0x%x].\r\n", trap_info.tClass,
           trap_info.tCpu, trap_info.tId, trap_info.tAddr);
  }
}

static inline void Tc39bTrapBeHook(IfxCpu_Trap trap_info) {
  if (trap_info.tClass == IfxCpu_Trap_Class_bus) {
    switch (trap_info.tId) {
      case IfxCpu_Trap_Bus_Id_programFetchSynchronousError:
        printf("[BE TRAP]: Program Fetch Synchronous Error in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_Bus_Id_dataAccessSynchronousError:
        printf("[BE TRAP]: Data Access Synchronous Error in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_Bus_Id_dataAccessAsynchronousError:
        printf("[BE TRAP]: Data Access Asynchronous Error in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_Bus_Id_CoprocessorTrapAsynchronousError:
        printf("[BE TRAP]: Coprocessor Trap Asynchronous Error in cpu %d at 0x%x.\r\n",
               trap_info.tCpu, trap_info.tAddr);
        break;
      case IfxCpu_Trap_Bus_Id_programMemoryIntegrityError:
        printf("[BE TRAP]: Program Memory Integrity Error in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_Bus_Id_dataMemoryIntegrityError:
        printf("[BE TRAP]: Data Memory Integrity Error in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_Bus_Id_temporalAsynchronousError:
        printf("[BE TRAP]: Temporal Asynchronous Error in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      default:
        printf("[BE TRAP]: tCPU[%d],tId[%d],tAddr[0x%x].\r\n", trap_info.tCpu, trap_info.tId,
               trap_info.tAddr);
        break;
    }
  } else {
    printf("[Not BE TRAP]: tClass[%d],tCPU[%d],tId[%d],tAddr[0x%x].\r\n", trap_info.tClass,
           trap_info.tCpu, trap_info.tId, trap_info.tAddr);
  }
}

static inline void Tc39bTrapAssertHook(IfxCpu_Trap trap_info) {
  if (trap_info.tClass == IfxCpu_Trap_Class_assertion) {
    switch (trap_info.tId) {
      case IfxCpu_Trap_Assertion_Id_arithmeticOverflow:
        printf("[ASSERT TRAP]: Arithmetic Overflow in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      case IfxCpu_Trap_Assertion_Id_stickyArithmeticOverflow:
        printf("[ASSERT TRAP]: Sticky Arithmetic Overflow in cpu %d at 0x%x.\r\n", trap_info.tCpu,
               trap_info.tAddr);
        break;
      default:
        printf("[ASSERT TRAP]: tCPU[%d],tId[%d],tAddr[0x%x].\r\n", trap_info.tCpu, trap_info.tId,
               trap_info.tAddr);
        break;
    }
  } else {
    printf("[Not ASSERT TRAP]: tClass[%d],tCPU[%d],tId[%d],tAddr[0x%x].\r\n", trap_info.tClass,
           trap_info.tCpu, trap_info.tId, trap_info.tAddr);
  }
}

// Non-Maskable Interrupt
#ifndef IFX_CFG_CPU_TRAP_NMI_HOOK
#define IFX_CFG_CPU_TRAP_NMI_HOOK(trap_info) Tc39bTrapNmiHook(trap_info)
#endif
// Memory Management Error
#ifndef IFX_CFG_CPU_TRAP_MME_HOOK
#define IFX_CFG_CPU_TRAP_MME_HOOK(trap_info) Tc39bTrapMmeHook(trap_info)
#endif
// Internal Protection Error
#ifndef IFX_CFG_CPU_TRAP_IPE_HOOK
#define IFX_CFG_CPU_TRAP_IPE_HOOK(trap_info) Tc39bTrapIpeHook(trap_info)
#endif
// Instruction Error
#ifndef IFX_CFG_CPU_TRAP_IE_HOOK
#define IFX_CFG_CPU_TRAP_IE_HOOK(trap_info)  Tc39bTrapIeHook(trap_info)
#endif
// Context Management Error
#ifndef IFX_CFG_CPU_TRAP_CME_HOOK
#define IFX_CFG_CPU_TRAP_CME_HOOK(trap_info) Tc39bTrapCmeHook(trap_info)
#endif
// Bus Error
#ifndef IFX_CFG_CPU_TRAP_BE_HOOK
#define IFX_CFG_CPU_TRAP_BE_HOOK(trap_info)  Tc39bTrapBeHook(trap_info)
#endif
// Assertion
#ifndef IFX_CFG_CPU_TRAP_ASSERT_HOOK
#define IFX_CFG_CPU_TRAP_ASSERT_HOOK(trap_info)  Tc39bTrapAssertHook(trap_info)
#endif

#endif  // PLATFORM_BSP_TC39B_IFX_CFG_TRAP_H_
