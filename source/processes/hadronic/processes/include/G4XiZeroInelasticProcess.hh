// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4XiZeroInelasticProcess.hh,v 2.0 1998/07/02 16:36:45 gunter Exp $
// GEANT4 tag $Name: geant4-00 $
//
 // G4 Process: XiZero Inelastic Process
 // J.L. Chuma, TRIUMF, 05-Nov-1996
 // Last modified: 03-Apr-1997

#ifndef G4XiZeroInelasticProcess_h
#define G4XiZeroInelasticProcess_h 1
 
//#include "G4HadronicInelasticProcess.hh"
#include "G4HadronInelasticProcess.hh"
 
// class G4XiZeroInelasticProcess : public G4HadronicInelasticProcess
 class G4XiZeroInelasticProcess : public G4HadronInelasticProcess
 {
 public:
    
    G4XiZeroInelasticProcess(
     const G4String& processName = "XiZeroInelastic" ) :
      //      G4HadronicInelasticProcess( processName, G4XiZero::XiZero() )
      G4HadronInelasticProcess( processName, G4XiZero::XiZero() )
    { }
    
    ~G4XiZeroInelasticProcess()
    { }
    
 };
 
#endif