#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>


void TreeToCSV_FakeBkg(){

  //make output file
  std::ofstream outfile;
  outfile.open("../data/FakeBackground.csv");

  TFile* f = new TFile("NonPromptData_MuCBTightMiniIso_ElMVATightRC.root");
  TTree* t = (TTree*) f->Get("tEvts_ssdl");
  //set kinematic info
  float Lep1Pt,Lep2Pt,Jet1Pt,Jet2Pt,HT,DilepMass;
  int nConst,nMu,nTL;
  t->SetBranchAddress("Lep1Pt",&Lep1Pt);
  t->SetBranchAddress("Lep2Pt",&Lep2Pt);
  t->SetBranchAddress("cleanAK4HT",&HT);
  t->SetBranchAddress("cleanAK4Jet1Pt",&Jet1Pt);
  t->SetBranchAddress("cleanAK4Jet2Pt",&Jet2Pt);
  t->SetBranchAddress("DilepMass",&DilepMass);
  t->SetBranchAddress("nConst",&nConst);
  t->SetBranchAddress("Channel",&nMu);
  t->SetBranchAddress("nTL",&nTL);
  //weights
  float cmidWeight, NPWeight, TrigWeight, IDWeight, ISOWeight;
  t->SetBranchAddress("trigSF",&TrigWeight);
  t->SetBranchAddress("NPWeight",&NPWeight);
  t->SetBranchAddress("ChargeMisIDWeight",&cmidWeight);
  t->SetBranchAddress("IDSF",&IDWeight);
  t->SetBranchAddress("IsoSF",&ISOWeight);
  
  int nEntries = t->GetEntries();
  for(int i =0; i< nEntries; i++){
    t->GetEntry(i);
    //preliminary cuts
    if(Lep1Pt<40 || DilepMass <20 || (DilepMass > 71 && DilepMass < 111) || nMu!=0) continue;
    //make total weight
    float weight = TrigWeight*NPWeight*cmidWeight*IDWeight*ISOWeight;
    std::stringstream line;
    line<<Lep1Pt<<","<<Lep2Pt<<","<<Jet1Pt<<","<<Jet2Pt<<","<<HT<<","<<nConst<<","<<DilepMass<<","<<weight<<","<<nTL<<std::endl;
    outfile<<line.str();
    
  }

  outfile.close();

}
