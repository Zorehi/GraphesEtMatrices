#pragma once

class CArc
{
private:
	int iARCDestination;

public:
	/**
	 * @brief 
	 * @param iNumeroSommet 
	*/
	CArc(int iNumeroSommet);


	/**
	 * @brief 
	 * @param  
	 * @return 
	*/
	int ARCLireDestination();

	/**
	 * @brief 
	 * @param iNumeroSommet 
	*/
	void ARCModifierDestination(int iNumeroSommet);
};

