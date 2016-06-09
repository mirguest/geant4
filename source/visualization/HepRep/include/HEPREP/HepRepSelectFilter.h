//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef HEPREP_HEPREPSELECTFILTER_H
#define HEPREP_HEPREPSELECTFILTER_H 1

// Copyright 2000-2002, FreeHEP.

namespace HEPREP {

class HepRepInstance;

/**
 * HepRepSelectFilter interface used in copying HepReps.
 *
 * @author Mark Donszelmann
 */
class HepRepSelectFilter {

public: 
    /// Destructor.
    virtual ~HepRepSelectFilter() { /* nop */; }

    /**
     * Selects if the given instance will pass.
     *
     * @param instance to be checked.
     * @return true if instance passes.
     */
    virtual bool select(HepRepInstance * instance) = 0;
}; // class
}; // namespace HEPREP
#endif /* ifndef HEPREP_HEPREPSELECTFILTER_H */