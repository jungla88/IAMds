/*
 * AIDSVerticesDissimilarity.hpp
 *
 *  Created on: Mar 28, 2012
 *      Author: filippo
 */

#ifndef AIDSVERTICESDISSIMILARITY_HPP_
#define AIDSVERTICESDISSIMILARITY_HPP_

// STD INCLUDES
#include <vector>

// SPARE INCLUDES
#include <spare/SpareTypes.hpp>
#include <spare/Dissimilarity/Euclidean.hpp>



/** @brief Dissimilarity for vertices labels of an IAM AIDS graph type
 */
class AIDSVerticesDissimilarity
{
public:

	spare::RealType& Weight(){
		return weight;
	}

	const spare::RealType& Weight() const{
		return weight;
	}

	AIDSVerticesDissimilarity(){
		weight = 1;
	}

    /**
     * Dissimilarity for vertices labels of an IAM AIDS graph type
     */
    inline spare::RealType Diss(const VertexLabelType& aV1, const VertexLabelType& aV2) const
    {
        spare::RealType D= 0;
        std::vector<spare::RealType> v1, v2;
        spare::Euclidean e;

        if(aV1.charge!=aV2.charge)
            D+=0.1;

        if(aV1.chem!=aV2.chem)
            D+=0.3;

        v1.push_back(aV1.x);
        v1.push_back(aV1.y);
        v2.push_back(aV2.x);
        v2.push_back(aV2.y);


        D+=(e.Diss(v1, v2)*0.6)/weight;

        return D;
    }

private:
    spare::RealType weight;

};


#endif /* AIDSVERTICESDISSIMILARITY_HPP_ */
