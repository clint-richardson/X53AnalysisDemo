#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

void TreeToCSV_RealBkg(){

  //make output file
  std::ofstream outfile;
  outfile.open("../data/RealBackground.csv");
  /* TTZ First */
  TFile* fTTZ = new TFile("TTZ_MuCBTightMiniIso_ElMVATightRC.root");
  TTree* tTTZ = (TTree*) fTTZ->Get("tEvts_ssdl");
  //set kinematic info
  float Lep1Pt,Lep2Pt,Jet1Pt,Jet2Pt,HT,DilepMass;
  int nConst,nMu,nTL;
  tTTZ->SetBranchAddress("Lep1Pt",&Lep1Pt);
  tTTZ->SetBranchAddress("Lep2Pt",&Lep2Pt);
  tTTZ->SetBranchAddress("cleanAK4HT",&HT);
  tTTZ->SetBranchAddress("cleanAK4Jet1Pt",&Jet1Pt);
  tTTZ->SetBranchAddress("cleanAK4Jet2Pt",&Jet2Pt);
  tTTZ->SetBranchAddress("DilepMass",&DilepMass);
  tTTZ->SetBranchAddress("nConst",&nConst);
  tTTZ->SetBranchAddress("Channel",&nMu);
  tTTZ->SetBranchAddress("nTL",&nTL);
  //weights
  float cmidWeight, NPWeight, TrigWeight, IDWeight, ISOWeight;
  tTTZ->SetBranchAddress("trigSF",&TrigWeight);
  tTTZ->SetBranchAddress("NPWeight",&NPWeight);
  tTTZ->SetBranchAddress("ChargeMisIDWeight",&cmidWeight);
  tTTZ->SetBranchAddress("IDSF",&IDWeight);
  tTTZ->SetBranchAddress("IsoSF",&ISOWeight);
  
  int nEntries = tTTZ->GetEntries();
  for(int i =0; i< nEntries; i++){
    tTTZ->GetEntry(i);
    //preliminary cuts
    if(Lep1Pt<40 || DilepMass <20 || (DilepMass > 71 && DilepMass < 111) || nMu!=0) continue;
    //make total weight
    float weight = TrigWeight*NPWeight*cmidWeight*IDWeight*ISOWeight;
    std::stringstream line;
    line<<Lep1Pt<<","<<Lep2Pt<<","<<Jet1Pt<<","<<Jet2Pt<<","<<HT<<","<<nConst<<","<<DilepMass<<","<<weight<<","<<nTL<<std::endl;
    outfile<<line.str();
    
  }

  /* Now do TTW */
  TFile* fTTW = new TFile("TTW_MuCBTightMiniIso_ElMVATightRC.root");
  TTree* tTTW = (TTree*) fTTW->Get("tEvts_ssdl");
  tTTW->SetBranchAddress("Lep1Pt",&Lep1Pt);
  tTTW->SetBranchAddress("Lep2Pt",&Lep2Pt);
  tTTW->SetBranchAddress("cleanAK4HT",&HT);
  tTTW->SetBranchAddress("cleanAK4Jet1Pt",&Jet1Pt);
  tTTW->SetBranchAddress("cleanAK4Jet2Pt",&Jet2Pt);
  tTTW->SetBranchAddress("DilepMass",&DilepMass);
  tTTW->SetBranchAddress("nConst",&nConst);
  tTTW->SetBranchAddress("Channel",&nMu);
  tTTW->SetBranchAddress("nTL",&nTL);
  //weights
  tTTW->SetBranchAddress("trigSF",&TrigWeight);
  tTTW->SetBranchAddress("NPWeight",&NPWeight);
  tTTW->SetBranchAddress("ChargeMisIDWeight",&cmidWeight);
  tTTW->SetBranchAddress("IDSF",&IDWeight);
  tTTW->SetBranchAddress("IsoSF",&ISOWeight);
  
  nEntries = tTTW->GetEntries();
  for(int i =0; i< nEntries; i++){
    tTTW->GetEntry(i);
    //preliminary cuts
    if(Lep1Pt<40 || DilepMass <20 || (DilepMass > 71 && DilepMass < 111) || nMu!=0) continue;
    //make total weight
    float weight = TrigWeight*NPWeight*cmidWeight*IDWeight*ISOWeight;
    std::stringstream line;
    line<<Lep1Pt<<","<<Lep2Pt<<","<<Jet1Pt<<","<<Jet2Pt<<","<<HT<<","<<nConst<<","<<DilepMass<<","<<weight<<","<<nTL<<std::endl;
    outfile<<line.str();
    
  }
  /* Finally add TTH 

  TFile* fTTH = new TFile("TTH_MuCBTightMiniIso_ElMVATightRC.root");
  TTree* tTTH = (TTree*) fTTH->Get("tEvts_ssdl");
  //set kinematic info
  tTTH->SetBranchAddress("Lep1Pt",&Lep1Pt);
  tTTH->SetBranchAddress("Lep2Pt",&Lep2Pt);
  tTTH->SetBranchAddress("cleanAK4HT",&HT);
  tTTH->SetBranchAddress("cleanAK4Jet1Pt",&Jet1Pt);
  tTTH->SetBranchAddress("cleanAK4Jet2Pt",&Jet2Pt);
  tTTH->SetBranchAddress("DilepMass",&DilepMass);
  tTTH->SetBranchAddress("nConst",&nConst);
  tTTH->SetBranchAddress("Channel",&nMu);
  tTTH->SetBranchAddress("nTL",&nTL);
  //weights
  tTTH->SetBranchAddress("trigSF",&TrigWeight);
  tTTH->SetBranchAddress("NPWeight",&NPWeight);
  tTTH->SetBranchAddress("ChargeMisIDWeight",&cmidWeight);
  tTTH->SetBranchAddress("IDSF",&IDWeight);
  tTTH->SetBranchAddress("IsoSF",&ISOWeight);
  
  nEntries = tTTH->GetEntries();
  for(int i =0; i< nEntries; i++){
    tTTH->GetEntry(i);
    //preliminary cuts
    if(Lep1Pt<40 || DilepMass <20 || (DilepMass > 71 && DilepMass < 111) || nMu!=0) continue;
    //make total weight
    float weight = TrigWeight*NPWeight*cmidWeight*IDWeight*ISOWeight;
    std::stringstream line;
    line<<Lep1Pt<<","<<Lep2Pt<<","<<Jet1Pt<<","<<Jet2Pt<<","<<HT<<","<<nConst<<","<<DilepMass<<","<<weight<<","<<nTL<<std::endl;
    outfile<<line.str();
    
  }
  */
  outfile.close();

}
