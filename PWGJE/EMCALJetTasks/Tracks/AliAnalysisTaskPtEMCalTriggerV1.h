#ifndef ALIANALYSISTASKPTEMCALTRIGGERV1_H
#define ALIANALYSISTASKPTEMCALTRIGGERV1_H
/* Copyright(c) 1998-2014, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

// Author: Markus Fasel
#include "AliAnalysisTaskEmcalJet.h"
#include <TObjArray.h>
#include <TString.h>

class TArrayD;

namespace EMCalTriggerPtAnalysis {

class AliEMCalTriggerAnaTriggerDecisionConfig;
class AliEMCalTriggerBinningComponent;
class AliEMCalTriggerEventData;
class AliEMCalTriggerTaskGroup;

class AliAnalysisTaskPtEMCalTriggerV1: public AliAnalysisTaskEmcalJet {
public:
  AliAnalysisTaskPtEMCalTriggerV1();
  AliAnalysisTaskPtEMCalTriggerV1(const char *name);
  virtual ~AliAnalysisTaskPtEMCalTriggerV1();

  void AddAnalysisGroup(AliEMCalTriggerTaskGroup *taskGroup);
  virtual void UserCreateOutputObjects();
  virtual Bool_t Run();

  void SetMCJetContainerName(const char *name)          { fMCJetContainer = name; }
  void SetDataJetContainerName(const char *name)        { fDataJetContainer = name; }
  void SetBinning(const char *dimname, int nbins, double *binning);
  void SetBinning(const char *dimname, const TArrayD &binning);
  void SetTriggerDebug(Bool_t doDebug = kTRUE) { fDoTriggerDebug = doDebug; }
  void SetTriggerDecisionConfig(AliEMCalTriggerAnaTriggerDecisionConfig *config) { fTriggerDecisionConfig = config; }

protected:
  AliEMCalTriggerEventData *BuildEvent() const;

  TObjArray                           *fTaskGroups;         // grouped analysis components
  AliEMCalTriggerBinningComponent     *fBinning;            // Global binning component
  AliEMCalTriggerAnaTriggerDecisionConfig *fTriggerDecisionConfig;		// Configuration for the trigger decision handling
  TString                              fMCJetContainer;     // Name of the Monte-Carlo jet container
  TString                              fDataJetContainer;   // Data jet container name
  Bool_t                               fSwapTriggerThresholds;    // Swap thresholds of the low and high threshold trigger
  Bool_t                               fDoTriggerDebug;     // Debug trigger decision creator

private:
  AliAnalysisTaskPtEMCalTriggerV1(const AliAnalysisTaskPtEMCalTriggerV1 &);
  AliAnalysisTaskPtEMCalTriggerV1 &operator=(const AliAnalysisTaskPtEMCalTriggerV1 &);

  ClassDef(AliAnalysisTaskPtEMCalTriggerV1, 1);
};

} /* namespace EMCalTriggerPtAnalysis */

#endif /* ALIANALYSISTASKPTEMCALTRIGGERV1_H */
