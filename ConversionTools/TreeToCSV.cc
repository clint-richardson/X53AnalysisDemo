#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>


void TreeToCSV(){

  //make output file
  std::ofstream outfile;
  outfile.open("RealBackground.csv");

  TFile* f = new TFile("JetInfo-TopJets.root");
  TTree* t = (TTree*) f->Get("demo/JetVariables");
  //load data
  float Lep1Pt,Lep2Pt,Jet1Pt,Jet2Pt,HT;
  //weights
  float cmidWeight, NPWeight, TrigWeight, IDWeight, ISOWeight,
  
  int nEntries = t->GetEntries();
  for(int i =0; i< nEntries; i++){
    t->GetEntry(i);
    std::stringstream line;

    line<<(*jetPt)[0]<<","<<(*Tau1)[0]<<","<<(*Tau2)[0]<<","<<(*Tau3)[0]<<","<<(*SDMass)[0]<<","<<(*PrunedMass)[i]<<std::endl;
    outfile<<line.str();
    delete h;
  }

  outfile.close();

}
