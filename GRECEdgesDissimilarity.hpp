/*
 * GRECEdgesDissimilarity.hpp
 *
 *  Created on: Mar 27, 2012
 *      Author: filippo
 */

#ifndef GRECEDGESDISSIMILARITY_HPP_
#define GRECEDGESDISSIMILARITY_HPP_

// SPARE INCLUDES
#include <spare/SpareTypes.hpp>

class GRECEdgesDissimilarity{
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

	spare::RealType& Beta(){
		return beta;
	}

	const spare::RealType& Beta() const{
		return beta;
	}

	spare::RealType& Gamma(){
		return gamma;
	}

	const spare::RealType& Gamma() const{
		return gamma;
	}

	spare::RealType& Delta(){
		return delta;
	}

	const spare::RealType& Delta() const{
		return delta;
	}

	GRECEdgesDissimilarity(){
		weight = 1;
		alpha = 0.1423;
		beta = 0.125;
		gamma = 0.323;
		delta = 0.1069;
	}

    inline spare::RealType Diss(const EdgeLabelType& gE1, const EdgeLabelType& gE2) const{

    	spare::RealType D = 0;
    	spare::NaturalType f1 = gE1.frequency, f2 = gE2.frequency;

    	if(f1==f2){
    		if(f1==1){
    			if(gE1.type0.compare("line")==0 && gE2.type0.compare("line")==0){
    				D= alpha*(abs(gE1.angle0 - gE2.angle0) + 1.575)/3.15;
    			}else if(gE1.type0.compare("arc")==0 && gE2.type0.compare("arc")==0){
    				D= beta*abs(gE1.angle0 - gE2.angle0)/weight;
    			}else
    				D=gamma;
    		}
    		else
    			if(gE1.type0.compare("line")==0 && gE2.type0.compare("line")==0){
    				D= alpha*(abs(gE1.angle0 - gE2.angle0) + 1.575)/(2*3.15) + beta*abs(gE1.angle1 - gE2.angle1)/(2*weight);
    			}else if(gE1.type0.compare("arc")==0 && gE2.type0.compare("arc")==0){
    				D= alpha*(abs(gE1.angle1 - gE2.angle1) + 1.575)/(2*3.15) + beta*abs(gE1.angle0 - gE2.angle0)/(2*weight);
    			}else
    				D=gamma;
    	}else
    		D=delta;

		return D;
    }

private:

    //normalization of euclidean distance if edges are arcs
    spare::RealType weight;

    //weights
    spare::RealType alpha;
    spare::RealType beta;
    spare::RealType gamma;
    spare::RealType delta;
};

#endif /* GRECEDGESDISSIMILARITY_HPP_ */
