include_directories(
  ${LEAP_INCLUDE_DIR}
  ../Utility
  ../DataStructures
  ..
)

SET(OS_INTERACTION_SRCS
  LPGesture.h
  LPGesture.cpp
  OSInteraction.h
  OSInteraction.cpp
  Touch.h
  TouchManager.cpp
  TouchManager.h
)

if(BUILD_WINDOWS)
  SET(OS_INTERACTION_SRCS
    FocusAppInfo.h
    FocusAppInfo.cpp
    GdiPlusInitializer.h
    GdiPlusInitializer.cpp
    InterfaceCodes.h
    OSInteractionWin.h
    OSInteractionWin.cpp
    TouchManagerWin7Driver.cpp
    TouchManagerWin7Driver.h
    TouchManagerWin7Undocumented.cpp
    TouchManagerWin7Undocumented.h
    TouchManagerWin8.cpp
    TouchManagerWin8.h
    TouchPeripheral.cpp
    TouchPeripheral.h
    Win8TouchStructures.h
    ${OS_INTERACTION_SRCS}
  )
elseif(BUILD_MAC)
  SET(OS_INTERACTION_SRCS
    LPMac.h
    LPMac.mm
    OSInteractionMac.h
    OSInteractionMac.cpp
    ${OS_INTERACTION_SRCS}
  )
  include_directories(${APPKIT_FRAMEWORK}/Headers ${FOUNDATION_FRAMEWORK}/Headers ${QUARTZ_CORE_FRAMEWORK}/Headers ${CARBON_FRAMEWORK}/Frameworks/HIToolbox.framework/Headers)
elseif(BUILD_LINUX)
  SET(OS_INTERACTION_SRCS
    LPLinux.h
    LPLinux.cpp
    OSInteractionLinux.h
    OSInteractionLinux.cpp
    ${OS_INTERACTION_SRCS}
  )
endif()

ADD_MSVC_PRECOMPILED_HEADER("stdafx.h" "stdafx.cpp" OS_INTERACTION_SRCS)

add_library(OSInteraction ${Project_Libary_Mode} ${OS_INTERACTION_SRCS})
set_target_properties(OSInteraction PROPERTIES COMPILE_FLAGS "${ADDITIONAL_COMPILER_FLAGS}")
set_target_properties(OSInteraction PROPERTIES STATIC_LIBRARY_FLAGS "${STATIC_LIB_FLAGS}")

SET(OCU_LIBS ${OCU_DRV_ROOT_DIR}/lib/win32/OcuInterface.lib
             ${OCU_DRV_ROOT_DIR}/lib/win32/hid.lib)

if(BUILD_WINDOWS)
  target_link_libraries(OSInteraction GdiPlus.lib SetupAPI.Lib ShLwApi.Lib Psapi.Lib)
  target_link_libraries(OSInteraction ${OCU_LIBS})
elseif(BUILD_MAC)
  target_link_libraries(OSInteraction ${APPKIT_FRAMEWORK} ${FOUNDATION_FRAMEWORK} ${QUARTZ_CORE_FRAMEWORK} ${OPENGL_FRAMEWORK} ${CARBON_FRAMEWORK})
elseif(BUILD_LINUX)
  target_link_libraries(OSInteraction Utility)
endif()
