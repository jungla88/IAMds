/** @brief File FingerprintEdgesDissimilarity.hpp, that contains FingerprintEdgesDissimilarity class.
 *
 * Contains the declaration of the FingerprintEdgesDissimilarity class.
 *
 * @file FingerprintEdgesDissimilarity.hpp
 * @author Filippo Bianchi
 */


#ifndef FINGERPRINTEDGESDISSIMILARITY_HPP_
#define FINGERPRINTEDGESDISSIMILARITY_HPP_

// STD INCLUDES
#include <vector>

// SPARE INCLUDES
#include <spare/SpareTypes.hpp>
#include <spare/Dissimilarity/ModuleDistance.hpp>



/** @brief Dissimilarity for edges labels of an IAM Fingerprint graph type
 */
class FingerprintEdgesDissimilarity
{
public:

	/**
	 * Read/Write access to weight variable for normalize angle field
	 */
	spare::RealType& WeigthA(){
		return nWeightA;
	}

	/**
	 * Read-only access to the weight variable for normalize angle field
	 */
	const spare::RealType& WeigthA() const{
		return nWeighAt;
	}

	/**
	 * Read/Write access to weight variable for normalize orientation field
	 */
	spare::RealType& WeigthO(){
		return nWeightO;
	}

	/**
	 * Read-only access to the weight variable for normalize orientation field
	 */
	const spare::RealType& WeigthO() const{
		return nWeightO;
	}

	/**
	 * Read/Write access to alpha variable
	 */
	spare::RealType& Alpha(){
		return alpha;
	}

	/**
	 * Read-only access to the alpha variable
	 */
	const spare::RealType& Alpha() const{
		return alpha;
	}

    /**
     * Dissimilarity for edges labels of an IAM Fingerprint graph type
     */
    inline spare::RealType Diss(const EdgeLabelType& aV1, const EdgeLabelType& aV2) const
    {
        spare::RealType d1=0, d2=0,D= 0;
        spare::ModuleDistance dist;

        d1=dist.Diss(aV1.angle, aV2.angle)/nWeightA;
        d2=dist.Diss(aV1.orient, aV2.orient)/nWeightO;
        D=alpha*d1 + (1-alpha)*d2;

        return D;
    }

private:

    spare::RealType nWeightA, nWeightO, alpha;

};


#endif /* FINGERPRINTEDGESDISSIMILARITY_HPP_ */
