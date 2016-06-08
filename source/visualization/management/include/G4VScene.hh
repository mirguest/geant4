// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VScene.hh,v 2.4 1998/12/09 23:56:21 allison Exp $
// GEANT4 tag $Name: geant4-00 $
//
// 
// John Allison  19th July 1996.
// Abstract interface class for graphics scenes.
// Inherits from G4VGraphicsScene, in the graphics_reps component, which is
// a minimal abstract interface for the GEANT4 kernel.

// A scene is a set of objects which are sufficient to describe what
// is to be viewed.

#ifndef G4VSCENE_HH
#define G4VSCENE_HH

#include "globals.hh"

#include "G4VGraphicsScene.hh"
#include "G4SceneData.hh"
#include "G4VViewList.hh"
#include "G4ViewParameters.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Tubs.hh"
#include "G4Trd.hh"
#include "G4Trap.hh"
#include "G4Sphere.hh"
#include "G4Para.hh"
#include "G4Torus.hh"
#include "G4Transform3D.hh"
#include "G4VModel.hh"

class G4VGraphicsSystem;
class G4VView;
class G4VSolid;
class G4Polyline;
class G4Text;
class G4Circle;
class G4Square;
class G4Polymarker;
class G4Polyhedron;
class G4NURBS;
class G4VisAttributes;
class G4Colour;
class G4Visible;
class G4VSolid;
class G4ModelingParameters;
class G4LogicalVolume;

class G4VScene: public G4VGraphicsScene {

  friend ostream& operator << (ostream& os, const G4VScene& s);

public:

  enum MarkerSizeType {world, screen};

  G4VScene (G4VGraphicsSystem& system, G4int id, const G4String& name = "");

  virtual ~G4VScene ();

  // For RWTPtrOrderedVector...
  G4bool operator == (const G4VScene& scene) const;

  //////////////////////////////////////////////////////////////
  // Functions for adding raw GEANT4 objects, if the graphics system
  // can can understand them (optional on the part of the graphics
  // system).  If your graphics system is sophisticated enough to
  // handle a particular solid shape as a primitive, in your derived
  // class write a function to override one or more of the following.
  // See the implementation of G4VScene::AddThis (const G4Box& box) for
  // more suggestions.  If not, please implement the base class
  // invocation.
  virtual void AddThis (const G4Box&);
  virtual void AddThis (const G4Cons&);
  virtual void AddThis (const G4Tubs&);
  virtual void AddThis (const G4Trd&);
  virtual void AddThis (const G4Trap&);
  virtual void AddThis (const G4Sphere&);
  virtual void AddThis (const G4Para&);
  virtual void AddThis (const G4Torus&);
  virtual void AddThis (const G4VSolid&);  // For solids not above.

  ///////////////////////////////////////////////////////////////
  // Other inherited functions.

  virtual void EstablishSpecials (G4PhysicalVolumeModel&);
  // Used to establish any special relationships between scene and this
  // particular type of model - non-pure, i.e., no requirement to
  // implement.  See G4PhysicalVolumeModel.hh for details.

  virtual void PreAddThis (const G4Transform3D& objectTransformation,
			   const G4VisAttributes& visAttribs);
  // objectTransformation is the transformation in the world
  // coordinate system of the object about to be added, and visAttribs
  // is its visualization attributes.
  // IMPORTANT: invoke this from your polymorphic versions, e.g.:
  // void MyXXXScene::PreAddThis (const G4Transform3D& objectTransformation,
  //                              const G4VisAttributes& visAttribs) {
  //   G4VScene::PreAddThis (objectTransformation, visAttribs);
  //   ...
  // }

  virtual void PostAddThis ();
  // IMPORTANT: invoke this from your polymorphic versions, e.g.:
  // void MyXXXScene::PostAddThis () {
  //   ...
  //   G4VScene::PostAddThis (objectTransformation, visAttribs);
  // }

  //////////////////////////////////////////////////////////////
  // Functions for adding primitives.

  virtual void BeginModeling ();
  // IMPORTANT: invoke this from your polymorphic versions, e.g.:
  // void MyXXXScene::BeginModeling () {
  //   G4VScene::BeginModeling ();
  //   ...
  // }

  virtual void EndModeling ();
  // IMPORTANT: invoke this from your polymorphic versions, e.g.:
  // void MyXXXScene::EndModeling () {
  //   ...
  //   G4VScene::EndModeling ();
  // }

  virtual void BeginPrimitives (const G4Transform3D& objectTransformation);
  // IMPORTANT: invoke this from your polymorphic versions, e.g.:
  // void MyXXXScene::BeginPrimitives
  // (const G4Transform3D& objectTransformation) {
  //   G4VScene::BeginPrimitives (objectTransformation);
  //   ...
  // }

  virtual void EndPrimitives ();
  // IMPORTANT: invoke this from your polymorphic versions, e.g.:
  // void MyXXXScene::EndPrimitives () {
  //   ...
  //   G4VScene::EndPrimitives ();
  // }

  virtual void AddPrimitive (const G4Polyline&) = 0;
  virtual void AddPrimitive (const G4Text&) = 0;
  virtual void AddPrimitive (const G4Circle&) = 0;
  virtual void AddPrimitive (const G4Square&) = 0;
  virtual void AddPrimitive (const G4Polymarker&);  // Uses the above.
  virtual void AddPrimitive (const G4Polyhedron&) = 0;
  virtual void AddPrimitive (const G4NURBS&) = 0;

  //////////////////////////////////////////////////////////////
  // Access functions.
  const G4String&    GetName           () const;
  void               SetName           (const G4String&);
  G4int              GetSceneId        () const;
  G4int              GetViewCount      () const;
  G4VGraphicsSystem* GetGraphicsSystem () const;
  const G4SceneData& GetSceneData      () const;
  const G4VViewList& GetViewList       () const;
  const G4VModel*    GetModel          () const;
  G4VView*           GetCurrentView    () const;
  void         SetCurrentView (G4VView*);
  void         SetSceneData   (const G4SceneData&);
  G4VViewList& SetViewList    ();  // Non-const if you need to change.
  void         SetModel       (const G4VModel*);

  //////////////////////////////////////////////////////////////
  // Public utility functions.

  const G4Colour& GetColour (const G4Visible&);
  const G4Colour& GetColor  (const G4Visible&);
  // The above return colour of G4Visible object, or default global colour.

  const G4Colour& GetTextColour (const G4Text&);
  const G4Colour& GetTextColor  (const G4Text&);
  // The above return colour of G4Text object, or default text colour.

  G4ViewParameters::DrawingStyle GetDrawingStyle (const G4Visible&);
  // Returns drawing style of G4Visible object, i.e., the global
  // default value unless ovewrridden by forced attributes.  And the
  // attributes themselves can be specified or the global default is
  // used - see next function.  So use this function is you have a
  // G4Visible, or the next if all you have is a G4VisAttributes
  // pointer.

  G4ViewParameters::DrawingStyle GetDrawingStyle (const G4VisAttributes*);
  // Returns global default drawing style unless forced attributes are set.
  // So always use this to get the applicable drawing style.

  G4double GetMarkerSize (const G4VMarker&, MarkerSizeType&);
  // Returns applicable marker size (diameter) and type (in second
  // argument).  Uses global default marker if marker sizes are not
  // set.

  G4double GetMarkerDiameter (const G4VMarker&, MarkerSizeType&);
  // Alias for GetMarkerSize.

  G4double GetMarkerRadius (const G4VMarker&, MarkerSizeType&);
  // GetMarkerSize / 2.

  G4ModelingParameters* CreateModelingParameters ();
  // Only the scene and view know what the Modeling Parameters should
  // be.  For historical reasons, the GEANT4 Visualization Environment
  // maintains its own Scene Data and View Parameters, which must be
  // converted, when needed, to Modeling Parameters.

  //////////////////////////////////////////////////////////////
  // Administration functions.

  G4int IncrementViewCount ();

  virtual void ClearStore ();
  // Clears graphics database (display lists) if any.

  void AddViewToList      (G4VView* pView);  // Add view to view List.
  void RemoveViewFromList (G4VView* pView);  // Remove view from view List.

protected:

  //////////////////////////////////////////////////////////////
  // Default routine used by default AddThis ().

  virtual void RequestPrimitives (const G4VSolid& solid);

  //////////////////////////////////////////////////////////////
  // Data members

  G4VGraphicsSystem&     fSystem;      // Abstract system for this scene.
  const G4int            fSceneId;     // Id of this instance.
  G4String               fName;
  G4int                  fViewCount;   // To determine view ids for this scene.
  G4VViewList            fViewList;    // Views.
  G4VView*               fpView;       // Current view.
  G4SceneData            fSD;          // Scene data for this scene.

  //////////////////////////////////////////////////////////////
  // Workspace...

  G4bool fReadyForTransients;  // I.e., not processing scene.
  const G4VModel*          fpModel;      // Current model.
  const G4Transform3D*     fpObjectTransformation;  // Accum'd obj. transfn.
  const G4VisAttributes*   fpVisAttribs; // Working vis attributes.
  G4int              fCurrentDepth; // Current depth of geom. hierarchy.
  G4VPhysicalVolume* fpCurrentPV;   // Current physical volume.
  G4LogicalVolume*   fpCurrentLV;   // Current logical volume.

private:

  //////////////////////////////////////////////////////////////
  // Friend function accessed only by views of this scene.

  friend void G4VView::ProcessView ();

  //////////////////////////////////////////////////////////////
  // Private functions, etc..

  void   ProcessScene     (G4VView& view);
  // Accessed by G4VView::ProcessView ().

};

#include "G4VScene.icc"

#endif