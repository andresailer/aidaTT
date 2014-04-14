#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <vector>

#include "trackParameters.hh"
#include "trajectoryElement.hh"
#include "IPropagation.hh"
#include "IGeometry.hh"
#include "IFittingAlgorithm.hh"

namespace aidaTT
{

    /*** The main class to provide functionality for track parameter estimation.
     *   This includes propagation and extrapolation to any specific point/surface.
     *
     *   Created with the class aidaTT; uses a specific set of
     *        - fitting algorithm
     *        - propagation method
     *        - geometry interface
     *
     *  @version $Rev$
     *  @author Ch. Rosemann, DESY
     ***/

    class IFittingAlgorithm;

    class trajectory
    {
        public:
            /// create an empty trajectory
            trajectory();

            /// copy construct a trajectory
            trajectory(const trajectory&);

            /// trajectory that are to be fitted need full information at initialization
            trajectory(const trackParameters&, const std::vector<trajectoryElement>&,
                       const IFittingAlgorithm*, const IPropagation*, const IGeometry*);

            ~trajectory();

            //~ MarlinTrk:: virtual int addHit(trajectoryElement* hit) = 0 ;
            //~ MarlinTrk:: virtual int addAndFit( trajectoryElement* hit, double& chi2increment, double maxChi2Increment=DBL_MAX ) = 0 ;
            //~ MarlinTrk:: virtual int testChi2Increment( trajectoryElement* hit, double& chi2increment ) = 0 ;

            //~ MarlinTrk:: virtual int getHitsInFit( std::vector<std::pair<trajectoryElement*, double> >& hits ) = 0 ;
            //~ MarlinTrk:: virtual int getOutliers( std::vector<std::pair<trajectoryElement*, double> >& hits ) = 0 ;
            //~ MarlinTrk:: virtual int getNDF( int& ndf ) = 0 ;

            //~ MarlinTrk:: virtual int extrapolate( const gear::Vector3D& point, IMPL::TrackStateImpl& ts, double& chi2, int& ndf ) = 0 ;
            //~ MarlinTrk:: virtual int extrapolate( const gear::Vector3D& point, trajectoryElement* hit, IMPL::TrackStateImpl& ts, double& chi2, int& ndf ) = 0 ;

            //~ MarlinTrk:: virtual int propagate( const gear::Vector3D& point, IMPL::TrackStateImpl& ts, double& chi2, int& ndf ) = 0 ;
            //~ MarlinTrk:: virtual int propagate( const gear::Vector3D& point, trajectoryElement* hit, IMPL::TrackStateImpl& ts, double& chi2, int& ndf ) = 0 ;

            //~ MarlinTrk:: virtual int getTrackState( IMPL::TrackStateImpl& ts, double& chi2, int& ndf ) = 0 ;
            //~ MarlinTrk:: virtual int getTrackState( trajectoryElement* hit, IMPL::TrackStateImpl& ts, double& chi2, int& ndf ) = 0 ;

            /// methods available before fitting
            const std::vector<trajectoryElement>& getTrajectoryElements() const;
            const std::vector<trajectoryElement>& getMeasurements() const;

            const IFittingAlgorithm* const getFittingAlgorithm() const;
            const IPropagation* const getPropagationMethod() const;

            unsigned int fit();

            /// methods after fitting
            std::vector<trajectoryElement> getFittedTrajectoryElements();
            std::vector<trajectoryElement> getFittedMeasurements();
            std::vector<trajectoryElement> getOutliers();

            /// quantify the results
            double getChiSquare();
            unsigned int getNDF();

        private:
            /* disable assignment */
            trajectory operator=(const trajectory&);

            // the  internal parts
            const trackParameters          _referenceParameters;
            std::vector<trajectoryElement> _initialTrajectoryElements;
            std::vector<trajectoryElement> _initialMeasurements;

            const IFittingAlgorithm* _fittingAlgorithm;
            const IPropagation* _propagation;
            const IGeometry* _geometry;



            /*
            // ?
            //~ MarlinTrk::   virtual int initialise( bool fitDirection ) = 0 ;
            //~ MarlinTrk:: virtual int initialise(  const EVENT::TrackState& ts, double bfield_z, bool fitDirection ) = 0 ;

            BREAKS THE CONCEPT

            // kalmanning
            //~ MarlinTrk:: virtual int smooth( trajectoryElement* hit ) = 0 ;

            // no layers available -- can't assume
            //~ MarlinTrk:: virtual int propagateToLayer( int layerID, IMPL::TrackStateImpl& ts, double& chi2, int& ndf, int& detElementID, int mode=modeClosest ) = 0  ;
            //~ MarlinTrk:: virtual int propagateToLayer( int layerID, trajectoryElement* hit, IMPL::TrackStateImpl& ts, double& chi2, int& ndf, int& detElementID, int mode=modeClosest ) = 0  ;
            //~ MarlinTrk:: virtual int intersectionWithLayer( int layerID, gear::Vector3D& point, int& detElementID, int mode=modeClosest ) = 0  ;
            //~ MarlinTrk:: virtual int intersectionWithLayer( int layerID, trajectoryElement* hit, gear::Vector3D& point, int& detElementID, int mode=modeClosest ) = 0  ;
            //~ MarlinTrk:: virtual int extrapolateToLayer( int layerID, IMPL::TrackStateImpl& ts, double& chi2, int& ndf, int& detElementID, int mode=modeClosest ) = 0  ;
            //~ MarlinTrk:: virtual int extrapolateToLayer( int layerID, trajectoryElement* hit, IMPL::TrackStateImpl& ts, double& chi2, int& ndf, int& detElementID, int mode=modeClosest ) = 0  ;



            /// DON'T UNDERSTAND
            * Steve: "not needed"
            //~ MarlinTrk:: virtual int getTrackerHitAtPositiveNDF( trajectoryElement*& trkhit ) = 0 ;

            * what's a detElement?
            //~ MarlinTrk:: virtual int propagateToDetElement( int detElementID, IMPL::TrackStateImpl& ts, double& chi2, int& ndf, int mode=modeClosest ) = 0  ;
            //~ MarlinTrk:: virtual int propagateToDetElement( int detEementID, trajectoryElement* hit, IMPL::TrackStateImpl& ts, double& chi2, int& ndf, int mode=modeClosest ) = 0  ;
            //~ MarlinTrk:: virtual int extrapolateToDetElement( int detEementID, trajectoryElement* hit, IMPL::TrackStateImpl& ts, double& chi2, int& ndf, int mode=modeClosest ) = 0  ;
            //~ MarlinTrk:: virtual int extrapolateToDetElement( int detElementID, IMPL::TrackStateImpl& ts, double& chi2, int& ndf, int mode=modeClosest ) = 0  ;
            //~ MarlinTrk:: virtual int intersectionWithDetElement( int detElementID, gear::Vector3D& point, int mode=modeClosest ) = 0  ;
            //~ MarlinTrk:: virtual int intersectionWithDetElement( int detEementID, trajectoryElement* hit, gear::Vector3D& point, int mode=modeClosest ) = 0  ;
            */
    };
}

#endif // TRAJECTORY_H
