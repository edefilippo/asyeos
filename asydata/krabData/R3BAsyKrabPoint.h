// --------------------------------------------------------------------------
// -----                   R3BAsyKrabPoint header file                 ------
// -----    Created 24/10/23  by E. De Filippo and P. Russotto         ------
// --------------------------------------------------------------------------

/******************************************************************************
 *   Copyright (C) 2022 GSI Helmholtzzentrum f�r Schwerionenforschung GmbH    *
 *   Copyright (C) 2022-2025 Members of R3B Collaboration                     *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU Lesser General Public Licence (LGPL) version 3,        *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

/**  R3BAsyKrabPoint.h
 **/

#ifndef R3BAsyKrabPoint_H
#define R3BAsyKrabPoint_H

#include "FairMCPoint.h"
#include "TObject.h"
#include "TVector3.h"

class R3BAsyKrabPoint : public FairMCPoint {
 public:
  /** Default constructor **/
  R3BAsyKrabPoint();

  /** Constructor with arguments
   *@param trackID  Index of MCTrack
   *@param detID    Detector ID
   *@param detVolID Detector Copy ID
   *@param Z        Atomic number fragment
   *@param A        Mass number fragment
   *@param posIn    Ccoordinates at entrance to active volume [cm]
   *@param posOut   Coordinates at exit of active volume [cm]
   *@param momIn    Momentum of track at entrance [GeV]
   *@param momOut   Momentum of track at exit [GeV]
   *@param tof      Time since event start [ns]
   *@param length   Track length since creation [cm]
   *@param eLoss    Energy deposit [GeV]
   **/
  R3BAsyKrabPoint(Int_t trackID, Int_t detID, Int_t detCopyID, Double_t Z,
                  Double_t A, TVector3 posIn, TVector3 posOut, TVector3 momIn,
                  TVector3 momOut, Double_t tof, Double_t length,
                  Double_t eLoss, Double_t lightYield);

  /** Copy constructor **/
  R3BAsyKrabPoint(const R3BAsyKrabPoint& point) { *this = point; };

  /** Destructor **/
  virtual ~R3BAsyKrabPoint();

  /** Accessors **/
  Int_t GetDetCopyID() const { return fDetCopyID; }
  Double_t GetXIn() const { return fX; }
  Double_t GetYIn() const { return fY; }
  Double_t GetZIn() const { return fZ; }
  Double_t GetXOut() const { return fX_out; }
  Double_t GetYOut() const { return fY_out; }
  Double_t GetZOut() const { return fZ_out; }
  Double_t GetPxOut() const { return fPx_out; }
  Double_t GetPyOut() const { return fPy_out; }
  Double_t GetPzOut() const { return fPz_out; }
  Double_t GetZFF() const { return fZFF; }
  Double_t GetAFF() const { return fAFF; }
  Double_t GetLightYield() const { return fLightYield; }

  void PositionIn(TVector3& pos) { pos.SetXYZ(fX, fY, fZ); }
  void PositionOut(TVector3& pos) { pos.SetXYZ(fX_out, fY_out, fZ_out); }
  void MomentumOut(TVector3& mom) { mom.SetXYZ(fPx_out, fPy_out, fPz_out); }

  /** Point coordinates at given z from linear extrapolation **/
  Double_t GetX(Double_t z) const;
  Double_t GetY(Double_t z) const;

  /** Check for distance between in and out **/
  Bool_t IsUsable() const;

  /** Modifiers **/
  void SetPositionOut(TVector3 pos);
  void SetMomentumOut(TVector3 mom);
  void SetDetCopyID(Int_t id) { fDetCopyID = id; };

  /** Output to screen **/
  // virtual void Print(const Option_t* opt) const;

 private:
  Double32_t fX_out, fY_out, fZ_out;
  Double32_t fPx_out, fPy_out, fPz_out;
  Int_t fDetCopyID;
  Double32_t fZFF, fAFF;
  Double_t fLightYield;

  ClassDef(R3BAsyKrabPoint, 1)
};

inline void R3BAsyKrabPoint::SetPositionOut(TVector3 pos) {
  fX_out = pos.X();
  fY_out = pos.Y();
  fZ_out = pos.Z();
}

inline void R3BAsyKrabPoint::SetMomentumOut(TVector3 mom) {
  fPx_out = mom.Px();
  fPy_out = mom.Py();
  fPz_out = mom.Pz();
}

#endif
