/*
 * GRECVerticesDissimilarity.hpp
 *
 *  Created on: Mar 27, 2012
 *      Author: filippo
 */

#ifndef GRECVERTICESDISSIMILARITY_HPP_
#define GRECVERTICESDISSIMILARITY_HPP_

// STD INCLUDES
#include <vector>

// SPARE INCLUDES
#include <spare/SpareTypes.hpp>
#include <spare/Dissimilarity/Euclidean.hpp>


class GRECVerticesDissimilarity{
public:

	spare::RealType& Weight(){
		return weight;
	}

	const spare::RealType& Weight() const{
		return weight;
	}

	spare::RealType& Alpha(){
		return alpha;
	}

	const spare::RealType& Alpha() const{
		return alpha;
	}

	GRECVerticesDissimilarity(){
		weight = 1;
		alpha = 0.9353;
	}

    inline spare::RealType Diss(const VertexLabelType& gV1, const VertexLabelType& gV2) const{

    	spare::RealType D = 0;
    	if(gV1.type != gV2.type)
    		D+= alpha;

    	std::vector<spare::RealType> v1, v2;
		spare::Euclidean e;

		v1.push_back(gV1.x);
		v1.push_back(gV1.y);
		v2.push_back(gV2.x);
		v2.push_back(gV2.y);


		D+=(1-alpha)*(e.Diss(v1, v2)/weight);

		return D;
    }

private:
    //normalization of euclidean distance
    spare::RealType weight;

    //weight of difference in type (corber vs intersection) over position
    spare::RealType alpha;
};

#endif /* GRECVERTICESDISSIMILARITY_HPP_ */
