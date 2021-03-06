#pragma once
#include "Utility/LPGeometry.h"
#include "Overlay/LPImage.h"

class LPImageLinux:
  public LPImage
{
public:
  ~LPImageLinux(void);

private:

public:
  // Base overrides:
  bool SetImage(const std::wstring& filename, const POINT* pHotspot) override;
  bool SetImage(const SIZE& size, const POINT* pHotspot) override;
  bool InitImage(long width, long height, const POINT* pHotspot) override;
};

