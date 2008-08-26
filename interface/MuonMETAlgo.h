#ifndef Type1MET_MuonMETAlgo_h
#define Type1MET_MuonMETAlgo_h

/** \class MuonMETAlgo
 *
 * Correct MET for muons in the events.
 *
 * \version   1st Version August 30, 2007
 ************************************************************/

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Math/interface/Point3D.h"
#include "DataFormats/Math/interface/LorentzVector.h"

#include "DataFormats/Common/interface/View.h"
#include "DataFormats/METReco/interface/METCollection.h"
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/METReco/interface/CaloMETCollection.h"
#include "DataFormats/METReco/interface/CorrMETData.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "TrackingTools/TrackAssociator/interface/TrackDetectorAssociator.h"
#include "TrackingTools/TrackAssociator/interface/TrackAssociatorParameters.h"

#include "JetMETCorrections/Type1MET/interface/MuonMETInfo.h"

class MuonMETAlgo 
{
 public:
  MuonMETAlgo();
  virtual ~MuonMETAlgo();
   
  reco::CaloMET makeMET(const reco::CaloMET& fMet, double fSumEt,
			const std::vector<CorrMETData>& fCorrections, 
			const reco::MET::LorentzVector&);
  reco::MET     makeMET(const reco::MET&, double fSumEt,
			const std::vector<CorrMETData>& fCorrections, 
			const MET::LorentzVector& fP4);
  
  virtual void run(const edm::Event& iEvent,
		   const edm::EventSetup& iSetup, 
		   const reco::METCollection& uncorMET,
		   const edm::View<reco::Muon>& Muons,
		   TrackDetectorAssociator& trackAssociator,
		   TrackAssociatorParameters& trackAssociatorParameters,
		   reco::METCollection* corMET,
		   bool useTrackAssociatorPositions);
  virtual void run(const edm::Event& iEvent,
		   const edm::EventSetup& iSetup, 
		   const reco::CaloMETCollection& uncorMET, 
                   const edm::View<reco::Muon>& Muons,
		   TrackDetectorAssociator& trackAssociator,
		   TrackAssociatorParameters& trackAssociatorParameters,
		   reco::CaloMETCollection* corMET,
		   bool useTrackAssociatorPositions);
		   
  template <class T> void MuonMETAlgo_run(const edm::Event& iEvent,
					  const edm::EventSetup& iSetup,
					  const std::vector<T>& v_uncorMET,
	                                  const edm::View<reco::Muon>& inputMuons,
					  TrackDetectorAssociator& trackAssociator,
					  TrackAssociatorParameters& trackAssociatorParameters,
					  std::vector<T>* v_corMET,
					  bool useTrackAssociatorPositions);
					  
  static void  correctMETforMuon(double& metx, double& mety,
				 double bfield, int muonCharge,
				 const math::XYZTLorentzVector muonP4,
				 const math::XYZPoint muonVertex,
				 MuonMETInfo&);
    
};

#endif // Type1MET_MuonMETAlgo_h

/*  LocalWords:  MuonMETAlgo
 */
