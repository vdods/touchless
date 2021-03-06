#ifndef __TouchPeripheral_h__
#define __TouchPeripheral_h__

#include "Overlay/Overlay.h"
#include "OSInteraction/OSInteraction.h"
#include "GestureInteraction/GestureInteractionManager.h"
#include "Leap.h"

namespace Touchless
{

class TouchPeripheral : public GestureInteractionManager {

public:

  TouchPeripheral(OSInteractionDriver& osInteractionDriver, OverlayDriver& overlayDriver);

protected:

  virtual void processFrameInternal();
  virtual void identifyRelevantPointables(const Leap::PointableList &pointables, std::vector<Leap::Pointable> &relevantPointables) const;

private:

  int m_charmsMode;
  int m_lastNumIcons;

};

}

#endif
