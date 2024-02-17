#pragma once

#include <set>

#include "selfdrive/frogpilot/ui/frogpilot_ui_functions.h"
#include "selfdrive/ui/qt/offroad/settings.h"
#include "selfdrive/ui/ui.h"

class FrogPilotControlsPanel : public FrogPilotListWidget {
  Q_OBJECT

public:
  explicit FrogPilotControlsPanel(SettingsWindow *parent);

signals:
  void closeParentToggle();
  void openParentToggle();

private:
  void hideEvent(QHideEvent *event);
  void hideSubToggles();
  void parentToggleClicked();
  void updateCarToggles();
  void updateMetric();
  void updateState(const UIState &s);
  void updateToggles();

  ButtonControl *slscPriorityButton;

  FrogPilotButtonIconControl *modelSelectorButton;

  FrogPilotDualParamControl *aggressiveProfile;
  FrogPilotDualParamControl *conditionalSpeedsImperial;
  FrogPilotDualParamControl *conditionalSpeedsMetric;
  FrogPilotDualParamControl *standardProfile;
  FrogPilotDualParamControl *relaxedProfile;

  std::set<QString> conditionalExperimentalKeys = {"CECurves", "CECurvesLead", "CESlowerLead", "CENavigation", "CEStopLights", "CESignal"};
  std::set<QString> fireTheBabysitterKeys = {"NoLogging", "MuteOverheated", "OfflineMode"};
  std::set<QString> laneChangeKeys = {"LaneChangeTime", "LaneDetection", "LaneDetectionWidth", "OneLaneChange"};
  std::set<QString> lateralTuneKeys = {"ForceAutoTune", "NNFF", "SteerRatio", "UseLateralJerk"};
  std::set<QString> longitudinalTuneKeys = {"AccelerationProfile", "AggressiveAcceleration", "SmoothBraking", "StoppingDistance"};
  std::set<QString> mtscKeys = {"DisableMTSCSmoothing", "MTSCAggressiveness", "MTSCCurvatureCheck", "MTSCLimit"};
  std::set<QString> qolKeys = {"DisableOnroadUploads", "HigherBitrate", "NavChill", "PauseLateralOnSignal", "ReverseCruise", "SetSpeedLimit", "SetSpeedOffset"};
  std::set<QString> speedLimitControllerKeys = {"Offset1", "Offset2", "Offset3", "Offset4", "SLCFallback", "SLCOverride", "SLCPriority"};
  std::set<QString> visionTurnControlKeys = {"DisableVTSCSmoothing", "CurveSensitivity", "TurnAggressiveness"};

  std::map<std::string, ParamControl*> toggles;

  Params params;
  Params paramsMemory{"/dev/shm/params"};

  bool isMetric = params.getBool("IsMetric");
  bool started = false;

  float steerRatioStock = params.getFloat("SteerRatioStock");
};
